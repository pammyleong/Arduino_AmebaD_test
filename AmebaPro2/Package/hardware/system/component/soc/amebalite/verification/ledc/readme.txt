
Description:
	LEDC Verification
	@author chris_liang@realsil.com.cn
	@purpose
		To Test LEDC IP output to RGB LED
	@fcuntion
		1. DMA or CPU mode
		2. configurable Timing setting with 50MHz.
		3. configurable output RGB mode
		4. up to 1024 LED with refresh of 30fps
		5. LED reset under control

Test Flow:
	1. Init LEDC_StructInit
	2. Init LEDC_Init
	3. Select LEDC mode
	4. Config LED number and LED data length
	5. Enable LEDC
	6. Prepare Data to FIFO


Verification Command Flow:
