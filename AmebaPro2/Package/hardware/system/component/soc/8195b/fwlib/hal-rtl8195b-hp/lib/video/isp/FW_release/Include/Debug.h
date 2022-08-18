#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef FUNC_IN_OUT_MSG_ENABLE
//FUNC IN/OUT Message,  the parameter should be the function's name
//#define FUNC_IN_MSG(x)   printf("\n====> %s\tLine:%4d",__FILE__,__LINE__); printf("\tFunc:    "); printf x;
//printf("\n") //printf("\t%s\tLine:%4d\n\n",__FILE__,__LINE__);
//#define FUNC_OUT_MSG(x)  printf("\n<==== %s\tLine:%4d",__FILE__,__LINE__); printf("\tFunc:    "); printf x;
//printf("\n") //printf("\t%s\tLine:%4d\n\n",__FILE__,__LINE__);
#define FUNC_IN_MSG(x) \
	do{	\
		printf("\n==> %s \t Line:%d",__FILE__,__LINE__);\
		printf("\tFunc:    ");\
		printf (x);\
	} while(0)

#define FUNC_OUT_MSG(x) \
	do{	\
		printf("\n<== %s\ t Line:%d",__FILE__,__LINE__);\
		printf("\tFunc:    ");\
		printf (x);\
	} while(0)

#else
#define FUNC_IN_MSG(x)
#define FUNC_OUT_MSG(x)
#endif

#ifdef LINE_RUN_MSG
#define LINE_EXEC_MSG(x) \
	do{	\
		printf("\n==>%s\t Line:%d\t  -%bd-",__FILE__,__LINE__,(x));\
	} while(0)
#else
#define LINE_EXEC_MSG(x)
#endif


#ifdef MSG_ENABLE
#define MSG(x)  printf x
#else
#define MSG(x)
#endif

#ifdef DBG_MSG_ENABLE
#define DBG(x)      printf x
#else
#define DBG(x)
#endif

#ifdef MIPI_MSG_ENABLE
#define MIPI_MSG(x) printf x
#else
#define MIPI_MSG(x)
#endif

#ifdef DBG_sCache_MSG_ENABLE
#define DBG_sCache(x)      printf x
#else
#define DBG_sCache(x)
#endif

#ifdef CFG_MSG_ENABLE
#define DBG_CFG(x)      printf x
#else
#define DBG_CFG(x)
#endif

#ifdef DBG_BOOT_ENABLE
#define DBG_BOOT(x)      printf x
#else
#define DBG_BOOT(x)
#endif

#ifdef DBG_MCU_SPDUP_ENABLE
#define DBG_SPDUP(x)      printf x
#else
#define DBG_SPDUP(x)
#endif

#ifdef DBG2_MSG_ENABLE
#define DBG2(x)      printf x
#else
#define DBG2(x)
#endif

#ifdef DBG_SENSOR_MSG_ENABLE
#define DBG_SENSOR(x)      printf x
#else
#define DBG_SENSOR(x)
#endif

#ifdef DBG_OV7670_MSG_ENABLE
#define DBG_OV7670(x)      printf x
#else
#define DBG_OV7670(x)
#endif

#ifdef DBG_OV7690_MSG_ENABLE
#define DBG_OV7690(x)      printf x
#else
#define DBG_OV7690(x)
#endif

#ifdef FCALL_DBG_MSG_ENABLE
#define FCALL_DBG(x)      printf x
#else
#define FCALL_DBG(x)
#endif

#ifdef DBG_VD_MSG_ENABLE
#define DBG_VD(x)      printf x
#else
#define DBG_VD(x)
#endif

#ifdef GLOBALVAR_INIT_MSG_ENABLE
#define VARINTITSTMSG(x)      printf x
#else
#define VARINTITSTMSG(x)
#endif

#ifdef WARN_MSG_ENABLE
#define WARN(x)  printf x
#else
#define WARN(x)
#endif

#ifdef ERR_MSG_ENABLE
#define ERR(x)  printf x
#else
#define ERR(x)
#endif

#ifdef ISP_MSG_ENABLE
#define ISP_MSG(x) printf x
#else
#define ISP_MSG(x)
#endif

#ifdef IDEAEYE_MSG_ENALBE
#define IDEAEYE_MSG(x) printf x
#else
#define IDEAEYE_MSG(x)
#endif

#ifdef USB_DBG_ENABLE
#define USB_MSG(x) printf x
#else
#define USB_MSG(x)
#endif

#ifdef MTD_MSG_ENABLE
#define MTD_MSG(x) printf x
#else
#define MTD_MSG(x)
#endif

#ifdef BURNIN_MSG_ENABLE
#define BURNIN_MSG(x) printf x
#else
#define BURNIN_MSG(x)
#endif

#ifdef EPE_MSG_ENABLE
#define EPE_MSG(x) printf x
#else
#define EPE_MSG(x)
#endif

#ifdef BULK_MSG_ENABLE
#define BULK_MSG(x) printf x
#else
#define BULK_MSG(x)
#endif

#ifdef USB3_MSG_ENABLE
#define USB3_MSG(x) printf x
#else
#define USB3_MSG(x)
#endif

#ifdef USB3_DGB_EP0_ENABLE
#define USB3_EP0_DBG(x) printf x
#else
#define USB3_EP0_DBG(x)
#endif

#ifdef _ASSERT_ENABLE_
#define ASSERT(expr) \
  if (expr) { ; } \
  else  {\
    ERR(("Assert failed: " #expr " (file %s line %d)\n", __FILE__, (int) __LINE__ ));\
    while (1);\
  }
#else
#define ASSERT(expr)
#endif

#ifdef ISO_MSG_ENABLE
#define ISO_MSG(x) printf x
#else
#define ISO_MSG(x)
#endif

#ifdef SNR_ENABLE
#define SNR(x)  printf x
#else
#define SNR(x)
#endif

#ifdef MJPG_TUNE_ENABLE
#define MJPG_TUNE_MSG(x)  printf x
#else
#define MJPG_TUNE_MSG(x)
#endif

#ifdef DBG_CPU_CMD
#define CPU_CMD_MSG(x)  printf x
#else
#define CPU_CMD_MSG(x)
#endif

#ifdef IMX225_MSG_ENABLE
#define IMX225_MSG(x) printf x
#else
#define IMX225_MSG(x)
#endif

#ifdef LDC_MSG_ENABLE
#define LDC_MSG(x) printf x
#else
#define LDC_MSG(x)
#endif

#ifdef OSD_MSG_ENABLE
#define OSD_MSG(x) printf x
#else
#define OSD_MSG(x)
#endif

#endif // _DEBUG_H_
