LOCAL_PATH := $(call my-dir)
include $(LOCAL_PATH)/../Android.mk.def

#
# libVIPlite
#
include $(CLEAR_VARS)


LOCAL_C_INCLUDES := \
           $(LOCAL_PATH) \
           $(LOCAL_PATH)/inc \
           $(VIPLITE_ROOT)/hal/inc \
           $(VIPLITE_ROOT)/hal/user \
           $(VIPLITE_ROOT)/hal/kernel \
           $(VIPLITE_ROOT)/hal/kernel/linux \
           $(VIPLITE_ROOT)/hal/user/linux \
           $(VIPLITE_ROOT)/driver/inc \
           $(VIPLITE_ROOT)/sdk/inc \
           $(VIPLITE_ROOT)/hal/kernel/linux/vivante

# Core
LOCAL_SRC_FILES := \
           gc_vip_cpu.c \
           gc_vip_user_cpu.c \
           gc_vip_lite.c \
           gc_vip_lite_debug.c \
           gc_vip_lite_network.c

LOCAL_CFLAGS := \
        $(CFLAGS) \



LOCAL_SHARED_LIBRARIES := libVIPuser
LOCAL_LDFLAGS := -Wl,--version-script=$(LOCAL_PATH)/libVIPlite.map

#LOCAL_LDLIBS := -llog 

LOCAL_MODULE:= libVIPlite
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
ifeq ($(PLATFORM_VENDOR),1)
LOCAL_VENDOR_MODULE  := true
endif
include $(BUILD_SHARED_LIBRARY)
