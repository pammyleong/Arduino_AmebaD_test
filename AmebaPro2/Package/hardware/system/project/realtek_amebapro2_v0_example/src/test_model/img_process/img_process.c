/******************************************************************************
*
* Copyright(c) 2007 - 2021 Realtek Corporation. All rights reserved.
*
******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "img_process.h"

/*-------------------------------------------------------------------*/

#define QP	8

#define I2Q(v, q) (int)((v)*(1<<(q)))
#define Q2I(v, q) (int)((v)/(1<<(q)))

#define F2Q(v, q) (int)floor((v)*(1<<(q)))
#define Q2F(v, q) (float)( (float)(v)/(float)(1<<(q)))

#define MULQ(a, b, q)       ((a)*(b))/(1<<(q))
#define DIVQ(a, b, q)       ((a)*(1<<(q)))/(b)

#define IM(im,w,y,x) im[y*w+x]

/*-------------------------------------------------------------------*/

int img_resize_planar(img_t *im_in, rect_t *roi, img_t *im_out)
{
	int roi_w = roi->xmax - roi->xmin;
	int roi_h = roi->ymax - roi->ymin;

	int offx = roi->xmin;
	int offy = roi->ymin;

	if (im_out->width == 0) {
		im_out->width = roi_w;
	}
	if (im_out->height == 0) {
		im_out->height = roi_h;
	}

	// int scale_w = F2Q((float)im_out->width / (float)roi_w, QP);
	// int scale_h = F2Q((float)im_out->height / (float)roi_h, QP);
	int inv_scale_w = F2Q((float)roi_w / (float)im_out->width, QP);
	int inv_scale_h = F2Q((float)roi_h / (float)im_out->height, QP);

	if (im_out->data == NULL) {
		return -1;
	}

	uint8_t *in[3];
	uint8_t *out[3];

	in[0] = im_in->data;
	in[1] = im_in->data + im_in->width * im_in->height;
	in[2] = im_in->data + im_in->width * im_in->height * 2;

	out[0] = im_out->data;
	out[1] = im_out->data + im_out->width * im_out->height;
	out[2] = im_out->data + im_out->width * im_out->height * 2;

	for (int y = 0; y < im_out->height; y++) {
		for (int x = 0; x < im_out->width; x++) {
			// int in_x = DIVQ(I2Q(x, QP), scale_w, QP) + I2Q(offx, QP);
			// int in_y = DIVQ(I2Q(y, QP), scale_h, QP) + I2Q(offy, QP);
			int in_x = MULQ(I2Q(x, QP), inv_scale_w, QP) + I2Q(offx, QP);
			int in_y = MULQ(I2Q(y, QP), inv_scale_h, QP) + I2Q(offy, QP);

			int top = Q2I(in_y, QP);
			int left = Q2I(in_x, QP);

			for (int p = 0; p < 3; p++) {
				IM(out[p], im_out->width, y, x) = IM(in[p], im_in->width, top, left);
			}
		}
	}

	return 0;
}

/*-------------------------------------------------------------------*/

// only hp, vp is fixed point
static int bilinearly_interpolate_fix(int top, int bottom, int left, int right, int hp, int vp, uint8_t *input, int pitch)
{
	int top_left = I2Q(IM(input, pitch, top, left), QP);         //input[top][left];
	int top_right = I2Q(IM(input, pitch, top, right), QP);       //input[top][right];
	int bottom_left = I2Q(IM(input, pitch, bottom, left), QP);   //input[bottom][left];
	int bottom_right = I2Q(IM(input, pitch, bottom, right), QP);  //input[bottom][right];

	int horizontal_progress = hp - I2Q(left, QP);
	int vertical_progress = vp - I2Q(top, QP);

	int top_block = top_left + MULQ(horizontal_progress, (top_right - top_left), QP);
	int bottom_block = bottom_left + MULQ(horizontal_progress, (bottom_right - bottom_left), QP);

	return Q2I(top_block + MULQ(vertical_progress, (bottom_block - top_block), QP), QP);
}

static int rotate_tick = 0;
static int rotate_cnt = 0;

int img_rotation_fix(img_t *im_in, rect_t *roi, rotate_t *rotate_cfg, img_t *im_out, float (*aligned_c)[2])
{

	int cx = rotate_cfg->cx;    // horizontal
	int cy = rotate_cfg->cy;    // vertical
	float angle = rotate_cfg->angle;

	int roi_w = roi->xmax - roi->xmin;
	int roi_h = roi->ymax - roi->ymin;

	//int start_tick = (int)xTaskGetTickCount();
	rotate_cnt++;

	if (im_out->width == 0) {
		im_out->width = roi_w;
	}
	if (im_out->height == 0) {
		im_out->height = roi_h;
	}

	int scale_w = F2Q((float)im_out->width / (float)roi_w, QP);
	int scale_h = F2Q((float)im_out->height / (float)roi_h, QP);
	int scale = scale_w < scale_h ? scale_w : scale_h;

	int inv_scale_w = F2Q((float)roi_w / (float)im_out->width, QP);
	int inv_scale_h = F2Q((float)roi_h / (float)im_out->height, QP);
	int inv_scale = inv_scale_w > inv_scale_h ? inv_scale_w : inv_scale_h;

	int offx, offy;
	if (aligned_c != NULL) {
		offx = cx - aligned_c[0][0] / Q2F(scale, QP);
		offy = cy - aligned_c[0][1] / Q2F(scale, QP);
	} else {
		offx = roi->xmin;
		offy = roi->ymin;
	}

	int sin_val = F2Q((float)sin(angle), QP);
	int cos_val = F2Q((float)cos(angle), QP);

	if (im_out->data == NULL) {
		im_out->data = (uint8_t *)malloc((im_out->width + 8) * (im_out->height + 8) * 3);
		if (!im_out->data) {
			return -1;
		}
	}

	uint8_t *in[3];
	uint8_t *out[3];

	in[0] = im_in->data;
	in[1] = im_in->data + im_in->width * im_in->height;
	in[2] = im_in->data + im_in->width * im_in->height * 2;

	out[0] = im_out->data;
	out[1] = im_out->data + im_out->width * im_out->height;
	out[2] = im_out->data + im_out->width * im_out->height * 2;

	for (int y = 0; y < im_out->height; y++) {
		for (int x = 0; x < im_out->width; x++) {
			// int in_x = DIVQ(I2Q(x, QP), scale, QP) + I2Q(offx, QP);
			// int in_y = DIVQ(I2Q(y, QP), scale, QP) + I2Q(offy, QP);
			int in_x = MULQ(I2Q(x, QP), inv_scale, QP) + I2Q(offx, QP);
			int in_y = MULQ(I2Q(y, QP), inv_scale, QP) + I2Q(offy, QP);

			int vp = MULQ(cos_val, in_y - I2Q(cy, QP), QP) + MULQ(sin_val, in_x - I2Q(cx, QP), QP) + I2Q(cy, QP);
			int hp = MULQ(-sin_val, in_y - I2Q(cy, QP), QP) + MULQ(cos_val, in_x - I2Q(cx, QP), QP) + I2Q(cx, QP);

			int top = Q2I(vp, QP);
			int left = Q2I(hp, QP);

			int bottom = top + 1;
			int right = left + 1;

			if (top >= 0 && bottom < im_in->height && left >= 0 && right < im_in->width) {
				for (int p = 0; p < 3; p++) {
					IM(out[p], im_out->width, y, x) = (uint8_t)bilinearly_interpolate_fix(top, bottom, left, right, hp, vp, in[p], im_in->width);
				}
			}
		}
	}

	rotate_tick += ((int)xTaskGetTickCount() - start_tick);
	if ((rotate_cnt & 0x3F) == 0) {
		printf(">>>>>>>>>>>>>>>>>>>>>>>>> rotate tick %f\n\r", (float)rotate_tick / rotate_cnt);
	}

	return 0;
}

/*-------------------------------------------------------------------*/

#include "dma_api.h"
#define DMA_BLOCK_LENGTH    4000    // 4095 at most
#define DMA_BLOCK_NUM       16      // 16 at most
#define DMA_CHUNK_SIZE      DMA_BLOCK_LENGTH * DMA_BLOCK_NUM

static void img_dma_done_handler(void *id)
{
	SemaphoreHandle_t sem = *((SemaphoreHandle_t *)id);
	xSemaphoreGiveFromISR(sem, NULL);
}

void *img_dma_copy(uint8_t *dst, uint8_t *src, uint32_t size)
{
	gdma_t gdma;
	hal_gdma_block_t block_info[DMA_BLOCK_NUM];
	SemaphoreHandle_t dma_done_sem = xSemaphoreCreateBinary();

	dma_memcpy_init(&gdma, img_dma_done_handler, (uint32_t)&gdma);
	gdma.hal_gdma_adaptor.block_num = DMA_BLOCK_NUM;
	gdma.hal_gdma_adaptor.gdma_cb_para = &dma_done_sem;

	uint32_t sizechunk = 0;
	uint32_t block_num = 0;
	uint32_t last_blk_size = 0;

	for (int k = 0; k < size; k = k + sizechunk) {
		if (size - k < DMA_CHUNK_SIZE) {
			sizechunk = size - k;
			block_num = sizechunk / DMA_BLOCK_LENGTH;
			last_blk_size = sizechunk % DMA_BLOCK_LENGTH;
			block_num = last_blk_size == 0 ? block_num : block_num + 1;
		} else {
			sizechunk = DMA_CHUNK_SIZE;
			block_num = DMA_BLOCK_NUM;
		}

		for (int i = 0; i < block_num; i++) {
			block_info[i].src_offset = 0;
			block_info[i].dst_offset = 0;
			block_info[i].src_addr = (uint32_t)(src + k + i * DMA_BLOCK_LENGTH);
			block_info[i].dst_addr = (uint32_t)(dst + k + i * DMA_BLOCK_LENGTH);
			block_info[i].block_length = (last_blk_size != 0 && i == (block_num - 1)) ? last_blk_size : DMA_BLOCK_LENGTH;
		}

		dma_multiblk_memcpy(&gdma, (phal_gdma_block_t) &block_info, block_num);
		if (xSemaphoreTake(dma_done_sem, 5000) != pdTRUE) {
			printf("[WARN] wait dma_done_sem timeout.\r\n");
			goto img_dma_cleanup;
		}
	}

img_dma_cleanup:

	dma_memcpy_deinit(&gdma);
	vSemaphoreDelete(dma_done_sem);

	return (void *)dst;
}

/*-------------------------------------------------------------------*/
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

void img_stb_resize_planar(img_t *img_in, img_t *img_out)
{
	uint8_t *in[3];
	uint8_t *out[3];

	in[0] = img_in->data;
	in[1] = img_in->data + img_in->width * img_in->height;
	in[2] = img_in->data + img_in->width * img_in->height * 2;

	out[0] = img_out->data;
	out[1] = img_out->data + img_out->width * img_out->height;
	out[2] = img_out->data + img_out->width * img_out->height * 2;

	for (int i = 0; i < 3; i++) {
		stbir_resize_uint8(in[i], img_in->width, img_in->height, 0,
						   out[i], img_out->width, img_out->height, 0, 1);
	}
}

/*-------------------------------------------------------------------*/

img_t img_create_image(int w, int h, uint8_t *pbuf)
{
	img_t new_img;
	new_img.width = w;
	new_img.height = h;
	if (pbuf != NULL) {
		new_img.data = pbuf;
	} else {
		new_img.data = malloc(w * h * 3);
		if (new_img.data == NULL) {
			printf("[%s] fail to allocate memory\r\n", __func__);
			assert(0);
		}
	}
	return new_img;
}

void img_free_image(img_t im)
{
	if (im.data) {
		free(im.data);
	}
}

/*-------------------------------------------------------------------*/

void img_fill_image(img_t im, uint8_t val)
{
	for (int i = 0; i < im.width * im.height * 3; i++) {
		im.data[i] = val;
	}
}

static void set_pixel(img_t im, int x, int y, int c, uint8_t val)
{
	if (x < 0 || y < 0 || c < 0 || x >= im.width || y >= im.height || c >= 3) {
		return;
	}
	assert(x < im.width && y < im.height && c < 3);
	im.data[im.width * im.height * c + y * im.width + x] = val;
}

static uint8_t get_pixel(img_t im, int x, int y, int c)
{
	assert(x < im.width && y < im.height && c < 3);
	return im.data[c * im.height * im.width + y * im.width + x];
}

static void img_embed_image(img_t im_src, img_t im_dst, int dx, int dy)
{
	for (int k = 0; k < 3; k++) {
		for (int y = 0; y < im_src.height; y++) {
			for (int x = 0; x < im_src.width; x++) {
				float val = get_pixel(im_src, x, y, k);
				set_pixel(im_dst, dx + x, dy + y, k, val);
			}
		}
	}
}

void img_scaled_into_letterbox(img_t *p_im_in, img_t *p_im_out)
{
	img_t im_in = *p_im_in;
	img_t im_out = *p_im_out;

	int dst_w = im_out.width;
	int dst_h = im_out.height;
	int new_w, new_h;
	if (((float)dst_w / im_in.width) < ((float)dst_h / im_in.height)) {
		new_w = dst_w;
		new_h = (im_in.height * dst_w) / im_in.width;
	} else {
		new_h = dst_h;
		new_w = (im_in.width * dst_h) / im_in.height;
	}

	img_t resized_im = img_create_image(new_w, new_h, NULL);
	img_stb_resize_planar(&im_in, &resized_im);

	img_fill_image(im_out, 0);
	img_embed_image(resized_im, im_out, (dst_w - new_w) / 2, (dst_h - new_h) / 2);

	img_free_image(resized_im);
}
