LOCAL_PATH := $(call my-dir)
include $(LOCAL_PATH)/../../Android.mk.def

#
# libVIPuser
#
include $(CLEAR_VARS)


LOCAL_C_INCLUDES := \
           $(LOCAL_PATH) \
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
           gc_vip_user.c \
           linux/gc_vip_user_os.c \
           gc_vip_user_heap.c

LOCAL_CFLAGS := \
        $(CFLAGS) \



LOCAL_LDFLAGS := -Wl,--version-script=$(LOCAL_PATH)/libVIPuser.map

LOCAL_LDLIBS := -llog 

LOCAL_MODULE:= libVIPuser
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
ifeq ($(PLATFORM_VENDOR),1)
LOCAL_VENDOR_MODULE  := true
endif
include $(BUILD_SHARED_LIBRARY)
