#ifndef _IMG_PROCESS_H_
#define _IMG_PROCESS_H_

#include "mmf2_module.h"
#include "module_vipnn.h"

typedef struct img_s {
	unsigned int width;
	unsigned int height;
	unsigned char *data;
} img_t;

/*
typedef struct rect_s {
	int xmin;
	int ymin;
	int xmax;
	int ymax;
} rect_t;
*/

typedef struct rotate_s {
	int cx, cy;
	float angle;
} rotate_t;

/*
 * brief: resize the planar image
 *
 * [in] im_in : original image
 * [in] roi : roi of original image
 * [out] im_out : output resized image
 */
int img_resize_planar(img_t *im_in, rect_t *roi, img_t *im_out);

/*
 * brief: rotate and scale the image
 *
 * [in] im_in : original image
 * [in] roi : roi of original image
 * [in] rotate_cfg : angle to rotate
 * [out] im_out : output rotated/scaled image
 * [in] aligned_c: aligned center (set it to NULL if not used)
 */
int img_rotation_fix(img_t *im_in, rect_t *roi, rotate_t *rotate_cfg, img_t *im_out, float (*aligned_c)[2]);


/*
 * brief: copy img data by DMA
 *
 * [out] dst : pointer to the destination
 * [in] src : pointer to the source of data
 * [in] size : number of bytes to copy.
 */
void *img_dma_copy(uint8_t *dst, uint8_t *src, uint32_t size);

#endif /* _IMG_PROCESS_H_ */