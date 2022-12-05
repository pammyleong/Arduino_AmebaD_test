#We have not tested this Android.mk in all Android version. Maybe you need to make sone modifications.

LOCAL_PATH := $(call my-dir)
include $(LOCAL_PATH)/../../Android.mk.def

#just for you reference

#
# vipcore.ko
#
include $(CLEAR_VARS)

VIPCORE_OUT := $(TARGET_OUT_INTERMEDIATES)/VIPCORE_OBJ

VIPCORE := \
	$(VIPLITE_ROOT)/vipcore.ko

KERNELENVSH := $(VIPCORE_OUT)/kernelenv.sh

$(KERNELENVSH):
	rm -rf $(KERNELENVSH)
	echo 'export KERNEL_DIR=$(KERNEL_DIR)' > $(KERNELENVSH)
	echo 'export CROSS_COMPILE=$(CROSS_COMPILE)' >> $(KERNELENVSH)
	echo 'export ARCH_TYPE=$(ARCH_TYPE)' >> $(KERNELENVSH)

VIPCORE_LOCAL_PATH := $(LOCAL_PATH)

$(VIPCORE): $(KERNELENVSH)
	@cd $(VIPLITE_ROOT)
	source $(KERNELENVSH); $(MAKE) -f Kbuild -C $(VIPLITE_ROOT) \
		VIPLITE_ROOT=$(abspath $(VIPLITE_ROOT)) \
		ARCH_TYPE=$(ARCH_TYPE) \
		DEBUG=$(DEBUG) \

LOCAL_PREBUILT_MODULE_FILE := \
	$(VIPCORE)


LOCAL_GENERATED_SOURCES += \
	$(VIPCORE)

ifeq ($(shell expr $(PLATFORM_SDK_VERSION) ">=" 21),1)
  LOCAL_MODULE_RELATIVE_PATH := modules
else
  LOCAL_MODULE_PATH          := $(TARGET_OUT_SHARED_LIBRARIES)/modules
endif

LOCAL_MODULE        := vipcore
LOCAL_MODULE_SUFFIX := .ko
LOCAL_MODULE_TAGS   := optional
LOCAL_MODULE_CLASS  := SHARED_LIBRARIES
LOCAL_STRIP_MODULE  := false
include $(BUILD_PREBUILT)


