/*

Compile:

windows:
mingw32-g++ -o ameba_d_arduino_image_tool_windows.exe tools\windows\src\ameba_d_arduino_image_tool_windows.cpp -static

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

int retrieve_system_call_result (string cmd, vector<string> *lines) {

    int ret = 0;

    FILE *fin;
    stringstream ss;
    string line;
    const int bufsize = 256;
    char buf[bufsize];

    bool buffer_result = true;

    if (lines == NULL) {
        buffer_result = false;
    } else {
        lines->clear();
    }

    do {
        fin = popen(cmd.c_str(), "r");
        if (fin == NULL || errno != 0) {
            ret = -1;
            break;
        }

        while(fgets(buf, bufsize, fin) != NULL) {
            if (buffer_result) {
                ss << buf;
            }
        }

        // now ss contain the results. Dump into string vector
        if (buffer_result) {
            lines->clear();
            while(getline(ss, line)) {
                lines->push_back(line);
            }
        }
        pclose(fin);
    } while (0);

    return ret;
}

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




    cout << "zzw test" << endl;
// ./ameba_d_arduino_image_tool_windows.exe km0_km4_image2.bin 
// ./ameba_d_arduino_image_tool_windows.exe C:\\Users\\zhangzhenwu\\Desktop\\Github_masters\\Arduino_AmebaD_test\\Ameba_test\\AmebaD_test\\ameba_d_tools_windows\\tools\\windows\\test_imagetool\\km0_km4_image2.bin s d 
    while(1);
    return 0;
}
