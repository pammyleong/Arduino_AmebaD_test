This is the test for testing all of the usual use media (RTSP, RTP, NN, SD, Video, Audio)

************************ Description *************************************
(1) the video stream 1, H264, is for mp4 
(2) the video stream 2, H264, is for RTSP
(3) the video stream 4, RGB, is for NN
(4) the NN predtion result will be drawn on the video stream 2
(5) the audio stream will be decoded by AAC for mp4 or RTSP
(6) a rtp stream will send AAC streaming and be decoded by AAC decoder and then be play by Pro2

************************ How to use **************************************
(1) open the file project\realtek_amebapro2_v0_example\src\mmfv2_video_example\video_example_media_framework.c and
    uncomment "mmf2_video_example_joint_test_vipnn_rtsp_mp4_init"

(2) open the file project\realtek_amebapro2_v0_example\inc\sensor.h and 
    select the usage sensor (#define USE_SENSOR)

(3) open the compiling terminal and go to the folder project\realtek_amebapro2_v0_example\GCC-RELEASE and 
    create a build folder

(4) enter the build folder and run "cmake .. -G"Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake -DVIDEO_EXAMPLE=on"

(5) then, run "cmake --build . --target flash_nn" or use "cmake --build . --target flash_nn -j4" to speed up the compiling time

(6) after download and test the example here are two command can be used 
    A. UC=TD  : Use for deinit all of the flow 
    B. UC=TSR : Reset the whole AmebaPro2, it can be used after doing command UC=TD. 