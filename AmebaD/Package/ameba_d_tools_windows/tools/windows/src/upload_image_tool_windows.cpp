/*

Compile:

windows:
mingw32-g++.exe -o upload_image_tool_windows.exe upload_image_tool_windows.cpp -static
i686-w64-mingw32-g++.exe -o upload_image_tool_windows.exe upload_image_tool_windows.cpp -static
*/
#include <time.h>
#include <errno.h>

#if defined(__WIN32__) // MINGW64
#include <windows.h>
#define FD HANDLE

#elif defined(__linux__) || defined(__APPLE__)// ubuntu 32 bits  and OS X 64bits
#include <sys/ioctl.h>
#include <fcntl.h>
#define FD int

#else

#error Unknown platform!
#endif


#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>

//#include <windows.h>

#include <thread>
//#include <mutex>

using namespace std;

//mutex mu;
int check_image_upload = 0;
uint8_t recv_buff[100];
int check_auto_upload = 0;

#if defined(__WIN32__)
void sleep_time(int ms) {
    Sleep(ms);
}
#elif defined(__linux__) || defined(__APPLE__)
void sleep_time(int ms) {
    msleep(ms);
}
#endif

void image_tool_thread(char* t1_com) {
	stringstream t1_cmdss;
	string t1_cmd;
	t1_cmdss.clear();
	t1_cmdss << ".\\tools\\windows\\image_tool\\amebad_image_tool.exe " << t1_com;
	getline(t1_cmdss, t1_cmd);
	system(t1_cmd.c_str());
//	mu.lock();
	check_image_upload = 100;
//	mu.unlock();
}

void image_tool_progress() {
	cout << "Uploading." << flush;
	while (1) {
		sleep_time(500);
//		mu.lock();
		if (check_image_upload != 0) {
			break;
		} else {
			cout << "." << flush;
		}
//		mu.unlock();
	}
	cout << "    Upload Image done. " << endl;
}

#if defined(__WIN32__)
DWORD read_UART(FD fd, uint8_t * buffer, int buffersize)
{
    DWORD dwBytesRead = 0;
    buffersize = 1;
    if(!ReadFile(fd, buffer, buffersize, &dwBytesRead, NULL)){
        printf("Read UART error.\n");
    }
//    if(verbose >5 && dwBytesRead)
    if (*buffer == 0x15)
        check_auto_upload++;
    return dwBytesRead;
}
#elif defined(__linux__) || defined(__APPLE__)
int read_UART(FD fd, uint8_t * buffer, int len)
{
    if (read(fd, buffer, 1) == 1) {
//        if(verbose >5)printf("%02X ",*buffer);
        if (*buffer == 0x15)
            check_auto_upload++;
        return 1;
    }
    return 0;
}

#endif

void Auto_upload_progress(int mode, char * com) {
    char buf[256];
    FD fd;

#if defined(__WIN32__)
    strcpy(buf,"\\\\.\\");
    strcat(buf,com);

    fd = CreateFileA(buf,                           //port name
                    GENERIC_READ | GENERIC_WRITE,   //Read/Write
                    0,                              // No Sharing
                    NULL,                           // No Security
                    OPEN_EXISTING,                  // Open existing port only
                    0,                              // Non Overlapped I/O
                    NULL);                          // Null for Comm Devices

    if (fd == INVALID_HANDLE_VALUE) {
        printf("Error in opening serial port");
        return;
    }
#elif defined(__linux__) || defined(__APPLE__)
    //fd = open( com , O_RDWR | O_NOCTTY | O_NDELAY);
    char *comName = com;
    fd = open( comName , O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd < 0) {
        printf("Error in opening serial port %s.\n",comName);
        return;
    }
#endif

//        EscapeCommFunction(fd, CLRRTS);
//        EscapeCommFunction(fd, SETRTS);
//        EscapeCommFunction(fd, CLRDTR);
//        EscapeCommFunction(fd, SETDTR);

//          DTR         RTS         CHIP_EN (reset)     PA7_log_TXD (download)
//  *1      1           1           1                   1
//  *2      0           0           1                   1
//  *3      1           0           0                   1
//  *4      0           1           1                   0

    //  com open auto set DTR, RTS low
    //  CLRDTR, CLRRTS high 3.3V
    //  SETDTR, SETRTS low  0.5 - 0.6V

// mode : 0  reset
// mode : 1  download mode
#if defined(__WIN32__)

    if (mode == 1) {
        // enter uart flash download mode.

//        EscapeCommFunction(fd, CLRDTR);
//        EscapeCommFunction(fd, CLRRTS);
//        sleep_time(500);

        EscapeCommFunction(fd, CLRDTR);
        EscapeCommFunction(fd, SETRTS);
        sleep_time(500);

        EscapeCommFunction(fd, SETDTR);
        EscapeCommFunction(fd, CLRRTS);
        sleep_time(500);

        EscapeCommFunction(fd, CLRDTR);
        EscapeCommFunction(fd, CLRRTS);
        sleep_time(500);

        for (int i =0; i<50;i++) {
            read_UART(fd, recv_buff, 1);
        }

    } else {
        // reset system.

        EscapeCommFunction(fd, CLRDTR);
        EscapeCommFunction(fd, CLRRTS);
        sleep_time(500);
//        EscapeCommFunction(fd, CLRDTR);
        EscapeCommFunction(fd, SETRTS);
        sleep_time(500);
//        EscapeCommFunction(fd, CLRDTR);
        EscapeCommFunction(fd, CLRRTS);
        sleep_time(500);
    }

    CloseHandle(fd); //Closing the Serial Port
//    sleep_time(500);

#elif defined(__linux__) || defined(__APPLE__)

    int status = 0;

    if (mode == 1) {
        // enter uart flash download mode

        status = TIOCM_DTR;
        //ioctl(fd, TIOCMBIS, &status);
        ioctl(fd, TIOCMBIC, &status);
        status = TIOCM_RTS;
        ioctl(fd, TIOCMBIS, &status);
        //ioctl(fd, TIOCMBIC, &status);
        sleep_time(500);

        status = TIOCM_DTR;
        ioctl(fd, TIOCMBIS, &status);
        //ioctl(fd, TIOCMBIC, &status);
        status = TIOCM_RTS;
        //ioctl(fd, TIOCMBIS, &status);
        ioctl(fd, TIOCMBIC, &status);
        sleep_time(500);

        //printf("   flash download  END  \r\n");
        for (int i =0; i<50;i++) {
            read_UART(fd, recv_buff, 1);
        }
    } else {
        // reset system.

        status = TIOCM_DTR;
        //ioctl(fd, TIOCMBIS, &status);
        ioctl(fd, TIOCMBIC, &status);
        status = TIOCM_RTS;
        //ioctl(fd, TIOCMBIS, &status);
        ioctl(fd, TIOCMBIC, &status);
        sleep_time(500);

        //status = TIOCM_DTR;
        //ioctl(fd, TIOCMBIS, &status);
        //ioctl(fd, TIOCMBIC, &status);
        status = TIOCM_RTS;
        ioctl(fd, TIOCMBIS, &status);
        //ioctl(fd, TIOCMBIC, &status);
        sleep_time(500);

        //status = TIOCM_DTR;
        //ioctl(fd, TIOCMBIS, &status);
        //ioctl(fd, TIOCMBIC, &status);
        status = TIOCM_RTS;
        //ioctl(fd, TIOCMBIS, &status);
        ioctl(fd, TIOCMBIC, &status);
        sleep_time(500);

        printf("   reset system  END  \r\n");
    }
    close(fd);

#endif
}

bool Auto_upload_mode(char * com) {

	cout << "Enter Auto upload mode" << endl;
	Auto_upload_progress(0, com);
	Auto_upload_progress(1, com);

	if (check_auto_upload >=15) {
		return true;
	}
	cout << "Device not supports Auto upload mode" << endl;
	return false;
}

// up to argv[4];
int main(int argc, char *argv[]) {
	string cmd;
	string auto_board, auto_user_selection;
	chdir(argv[1]);

// auto upload process
	// ameba_rtl8721d
	// ameba_rtl8722dm_mini
	// ameba_rtl8720dn_bw16
	auto_board = argv[3];
	auto_user_selection = argv[4];
	if ((auto_board == "ameba_rtl8720dn_bw16") && (auto_user_selection == "Enable")) {
		if (!Auto_upload_mode(argv[2])) {
			cmd = "Please enter the upload mode manually(wait 5s)";
			cout << cmd << endl;
			for (int i = 5; i > 0; i--) {
				sleep_time(1000);
				cmd = to_string(i);
				cout << "    0" << cmd << endl;
			}
		}
	} else {
		cmd = "Please enter the upload mode manually(wait 5s)";
		cout << cmd << endl;
		for (int i = 5; i > 0; i--) {
			sleep_time(1000);
			cmd = to_string(i);
			cout << "    0" << cmd << endl;
		}
	}

// download process
	thread t2(image_tool_progress);
	thread t1(image_tool_thread, argv[2]);
	// t2.detach();
	// t1.detach();
	t2.join();
	t1.join();

	return 0;
}
