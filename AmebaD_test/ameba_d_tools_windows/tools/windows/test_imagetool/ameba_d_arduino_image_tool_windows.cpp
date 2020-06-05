/*

Compile:

windows:
mingw32-g++ -o ameba_d_arduino_image_tool_windows.exe ameba_d_arduino_image_tool_windows.cpp -static

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <sys/stat.h>

#include <windows.h>

using namespace std;

bool isFileExist(string path) {
    bool ret = false;
    struct stat info;

    do {
        if (stat(path.c_str(), &info) != 0) {
            break;
        }

        ret = true;
    } while (0);

    return ret;
}

void zzw_delay_S(int t) {
    string cmd;
    for (int i = t; i > 0; i--)
    {
        Sleep(1000);
        cmd = to_string(i);
        cout << cmd << endl;
    }
}

unsigned int ameba_baudrate = 1500000;

int main(int argc, char *argv[]) {

    string image2_filepath;
    string flashloader_bin_name = "imgtool_flashloader_amebad.bin";
    string image2_bin_name = "km0_km4_image2.bin";
    uint32_t flashloader_addr = 0x00082000;
    uint32_t image2_addr = 0x08006000;

//0 set image2 path
    if (argc >= 2) {
        // the path of image2 is feed from arg
        image2_filepath.assign(argv[1]);
    } else {
        // assume image2 is in current path
        image2_filepath.assign(image2_bin_name);
    }

//1 check flashloader and image2 files
    if (!isFileExist(flashloader_bin_name)) {
        cout << "ERR: Upload tool corrupt!" << endl;
        return 0;
    }

    if (!isFileExist(image2_filepath)) {
        cout << "ERR: Upload image not found!" << endl;
        return 0;
    }

//2 open serial
    //serialport_open(argv[2], 115200);
    if (serialport_open(argv[2], ameba_baudrate) == 0) {
        cout << "ERR: Serial Port not open!" << endl;
        return 0;
    }



    cout << "zzw test" << endl;
// ./ameba_d_arduino_image_tool_windows.exe km0_km4_image2.bin 
// ./ameba_d_arduino_image_tool_windows.exe C:\\Users\\zhangzhenwu\\Desktop\\Github_masters\\Arduino_AmebaD_test\\Ameba_test\\AmebaD_test\\ameba_d_tools_windows\\tools\\windows\\test_imagetool\\km0_km4_image2.bin s d 
    while(1);
    return 0;
}
