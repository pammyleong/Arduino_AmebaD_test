
/********************************************************************************
 * Copyright (c) 2014, Realtek Semiconductor Corp.
 * All rights reserved.
 *
 * This module is a confidential and proprietary property of RealTek and
 * possession or use of this module requires written permission of RealTek.
 *******************************************************************************
 */
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#if defined (_WIN32)
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/time.h>
#endif

#include "xmodem.h"
#include "serialport.h"
#include "infohelper.h"
#include "delay.h"

int bufsz = 0, crc = 0;
uint8_t packetno = 1;
int c = 0, len = 0;
int retry = 0;

uint8_t xbuff[(1030 + 4)];//for RT-xmodem
uint32_t cal_sum = 0;
extern int txstatus;
extern double per_sec;
extern int filenum;
extern char* allfilename[];
extern uint32_t ameba_address[6];
extern const char*ameba_port;

void xmodem_reset(void) {
    bufsz = 0;
    crc = 0;
    packetno = 1;
    //i = 0;
    c = 0;
    len = 0;
    retry =0;
}

bool xmodem_handshake(void) {
    unsigned char read_byte;

#ifdef _WIN32
    DWORD tstart = GetTickCount();
    DWORD tend = 0;
#else
    struct timeval tv0, tv1;
    gettimeofday(&tv0, NULL);
    unsigned int time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        //recv NAK
        if (read_byte == NAK) {
            break;
        }

#ifdef _WIN32
        tend=GetTickCount();
        if (tend-tstart > 2000) {
            return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 2000) {
            return false;
        }
#endif
    }

    LOGDEBUG("receive NAK in handshake");
    com_delay_ms(20);

    unsigned char write_byte;
    write_byte = BAUDCHK;//BAUDCHK
    serialport_write(&write_byte, 1);
    com_delay_ms(20);

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        //recv ACK
        if (read_byte == ACK) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if (tend-tstart > 5000) {
        return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return false;
        }
#endif
    }

    LOGDEBUG("receive ACK in handshake");
    return true;
}

uint8_t* mymemset(uint8_t* xbuff, int index, int num) {
    for(int i = 0; i < num; i++) {
        xbuff[i+index] =0xFF;
    }
    return xbuff;
}

uint8_t* mymemcpy(uint8_t* dest, int d_i, uint8_t* src, int d_s, int num) {
    for(int i = 0; i < num; i++) {
        dest[(i + d_i)] = src[(i + d_s)];
    }
    return dest;
}

int startTrans(uint8_t* src, int srcsz, bool use1k, uint32_t addr) {
    uint8_t read_byte;
    uint8_t addr_array[4];
    addr_array[0] = (uint8_t)(0x000000FF & addr);
    addr_array[1] = (uint8_t)((0x0000FF00 & addr) >> 8);
    addr_array[2] = (uint8_t)((0x00FF0000 & addr) >> 16);
    addr_array[3] = (uint8_t)((0xFF000000 & addr) >> 24);

    len = 0;

    while (true) {
        bufsz = use1k ? 1024 : 128;

        xbuff[0] = use1k ? STX : SOH;
        xbuff[1] = packetno;
        xbuff[2] = (uint8_t)(~packetno);

        c = srcsz - len;//len=data already sent
        if (c > bufsz) {
            c = bufsz;
        }
        if (c > 0) {
            int i = 0;
            for(i = 0; i < (bufsz + 4); i++) {
                xbuff[(i + 3)] = 0xFF;
            }
            for (i = 0; i < 4; i++) {
                xbuff[(i + 3)] = addr_array[i];
            }
            for (i = 0; i < c; i++) {
                xbuff[(i + 7)] = src[(i + len)];
            }

            //add checksum
            uint8_t ccks=0;
            for (i = 3; i < (4 + bufsz + 3); i++) {
                ccks += xbuff[i];
            }
            xbuff[(4 + bufsz + 3)] = ccks;

            retry=0;
            bool success = false;

            while ((retry < MAXRETRANS) && (!success)) {
                retry++;
                serialport_write(xbuff, (bufsz + 4 + 4));
                com_delay_ms(20);

                serialport_read(&read_byte, 1);
                if (read_byte == ACK) {
                    ++packetno;
                    len += bufsz;
                    success = true;
                    LOGDEBUG("receive ACK after data packet");
                }
                if (read_byte == CAN) {
                    uint8_t write_byte = ACK;
                    serialport_write(&write_byte, 1);
                    com_delay_ms(20);
                    serialport_drain();//might be a problem
                    return -1;
                }
            }

            if (!success) {
                uint8_t write_byte = CAN;
                serialport_write(&write_byte, 1);
                serialport_write(&write_byte, 1);
                serialport_write(&write_byte, 1);
                serialport_drain();//might be a problem
                return -4;
            }

            if (success) {
                return 1;
            }
        } else {
            return len;
        }
    }
}

int endtrans(void) {
    unsigned char write_byte;
    unsigned char read_byte;
    for (retry = 0; retry < 10; retry++) {
        write_byte = EOT;
        serialport_write(&write_byte, 1);
        com_delay_ms(50);
        serialport_read(&read_byte, 1);
        if (read_byte == ACK) {
            break;
        }
    }
    return (read_byte == ACK) ? 1 : (-5);
}

bool TX_Data(const char* name, uint32_t dst_addr,bool flashloaderflag) {
    uint8_t txbuf[1024];
    int txnum = 0;
    size_t txNum;
    unsigned long txsum = 0;

    struct stat st;
    if (stat(name, &st) != 0) {
        LOGERR("stat %s failed: %s", name, strerror(errno));
        return false;
    }

    FILE* f = fopen(name, "rb");
    if (!f) {
        LOGERR("failed to open file for reading");
        return false;
    }

    if (!flashloaderflag) {
        INFO("image %s is sending...\n", name);
    }

    txsum = 0;
    txNum = fread(txbuf, 1, 1024, f);
    txnum = txNum;
    while (txnum>0) {
        if (txstatus >= 0) {
            txstatus=startTrans(txbuf, txnum, true, dst_addr);
        } else {
            break;
        }

        txsum += txnum;
        dst_addr += (uint32_t)txnum;
        txNum = fread(txbuf, 1, 1024, f);
        txnum = txNum;
        LOGDEBUG("TXNUM=%d",txnum);
    }

    fclose(f);
    return true;
}

bool WriteStatusRegister(uint8_t cmd, uint8_t len, uint8_t* val) {
    unsigned char read_byte;
    unsigned char write_byte;

#ifdef _WIN32
	DWORD tstart=GetTickCount();
	DWORD tend=0;
#else
	struct timeval tv0, tv1;
	gettimeofday(&tv0, NULL);
	unsigned int time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == NAK) {
            break;
        }

#ifdef _WIN32
        tend=GetTickCount();
        if (tend-tstart > 5000) {
            return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return false;
        }
#endif
    }

    serialport_drain();//might be a problem
    write_byte = WRITESTATUS;
    serialport_write(&write_byte, 1);
    write_byte = cmd;
    serialport_write(&write_byte, 1);
    write_byte = len;
    serialport_write(&write_byte, 1);
    write_byte = val[0];
    serialport_write(&write_byte, 1);
    com_delay_ms(20);

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == ACK) {
            break;
        }

#ifdef _WIN32
        tend=GetTickCount();
        if (tend-tstart > 5000) {
            return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return false;
        }
#endif
    }
    LOGDEBUG("RECV ACK in write status register");
    return true;
}

bool WriteRegFromXmodem(void) {
    uint32_t retry = 0, value = 0;
    uint32_t reg_addr = 0x040000210;

    bool result=true;
    while (retry <3) {
        result = ReadReg(reg_addr, &value);
        LOGDEBUG("REGVALUE=%d",value);
        if (result) {
            if (((value & (1 << 25)) != 0) || ((value & (1 << 24)) == 0)) {
                value = (uint32_t)(value & 0xFCFFFFFF);
                value = (uint32_t)(value | 0x01000000);
                result= WriteReg(reg_addr, &value);
            } else {
                break;
            }
        }
        retry++;
    }
    if (retry == 3) {
        return false;
    }

    return true;
}

bool ReadReg(uint32_t address, uint32_t *value) {
    unsigned char read_byte;
    unsigned char txdata[5];
    unsigned char rxdata[4];
    int wait_times = 1, index = 0;

    txdata[0] = RXREG;
    txdata[1] = (unsigned char)(address & 0xFF);
    txdata[2] = (unsigned char)((address & 0xFFFF) >> 8);
    txdata[3] = (unsigned char)((address & 0xFFFFFF) >> 16);
    txdata[4] = (unsigned char)(address >> 24);

#ifdef _WIN32
    DWORD tstart = GetTickCount();
    DWORD tend = 0;
#else
    struct timeval tv0, tv1;
    gettimeofday(&tv0, NULL);
    unsigned int time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == NAK) {
            break;
        }
#ifdef _WIN32
        tend=GetTickCount();
        if (tend-tstart > 5000) {
            return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return false;
        }
#endif
    }

    serialport_drain();//might be a problem
    serialport_write(txdata, 5);

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == RXREG) {
            break;
        }

#ifdef _WIN32
        tend=GetTickCount();
        if ((tend - tstart) > 5000) {
            return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return false;
        }
#endif
    }

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif

    while (wait_times != 0) {
        serialport_read(&rxdata[index], 1);
        index++;
        if (index == 4) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if ((tend - tstart) > 5000) {
            wait_times--;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            wait_times--;
        }
#endif
    }

    if (wait_times == 0) {
        return false;
    } else {
        *value = (uint32_t)((rxdata[0] & 0x000000FF) + ((rxdata[1] << 8) & 0x0000FF00) + ((rxdata[2] << 16) & 0x00FF0000) + ((rxdata[3] << 24) & 0xFF000000));
        return true;
    }
}

bool WriteReg(uint32_t address, uint32_t *value) {
    unsigned char read_byte;
    unsigned char txdata[9];
    int wait_times = 1;

    txdata[0] = TXREG;
    txdata[1] = (unsigned char)(address & 0xFF);
    txdata[2] = (unsigned char)((address & 0xFFFF >> 8);
    txdata[3] = (unsigned char)((address & 0xFFFFFF) >> 16);
    txdata[4] = (unsigned char)(address >> 24);
    txdata[5] = (unsigned char)((*value) & 0xFF);
    txdata[6] = (unsigned char)(((*value) & 0xFFFF) >> 8);
    txdata[7] = (unsigned char)(((*value) & 0xFFFFFF) >> 16);
    txdata[8] = (unsigned char)((*value) >> 24);

#ifdef _WIN32
    DWORD tstart = GetTickCount();
    DWORD tend = 0;
#else
    struct timeval tv0, tv1;
    gettimeofday(&tv0, NULL);
    unsigned int time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == NAK) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if (tend-tstart > 5000) {
            return false;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return false;
        }
#endif
    }

    serialport_drain();//might be a problem
    serialport_write(txdata, 9);

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif

    while (wait_times !=0) {
        serialport_read(&read_byte,1);
        if (read_byte == ACK) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if ((tend - tstart) > 5000) {
            wait_times--;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            wait_times--;
        }
#endif
    }

    if (wait_times == 0) {
        return false;
    } else {
        return true;
    }
}

bool ErashFlashFromXmodem() {
    bool result = false;
    uint8_t retry = 0;
    uint32_t filesz = 0;
    uint32_t end_addr = 0;

    struct stat st;
    for (int i = 0; i < filenum; i++) {
        if (stat(allfilename[i], &st) != 0) {
            LOGERR("stat %s failed: %s", allfilename[i], strerror(errno));
            return false;
        }
        filesz = st.st_size;
        end_addr = (uint32_t)((((ameba_address[i] + filesz - 1) >> 12) + 1) << 12);
        retry = 0;
        result = false;
        while((!result) && (retry < 3)) {
            result = EraseFlash(ameba_address[i], ((end_addr - ameba_address[i]) >> 12));
            retry++;
        }
        if (!result) {
            LOGERR("Erase flash fail!");
            return false;
        }
    }
    return true;
}

bool EraseFlash(uint32_t address,uint32_t len_4k) {
    unsigned char txdata[6];
    uint32_t wait_times = ((len_4k / 10) == 0) ? 1 : (len_4k / 10);
    unsigned char read_byte;

    txdata[0] = XMERASE;
    txdata[1] = (unsigned char)(address & 0xFF);
    txdata[2] = (unsigned char)((address & 0xFFFF) >> 8);
    txdata[3] = (unsigned char)((address & 0xFFFFFF) >> 16);
    txdata[4] = (unsigned char)(len_4k & 0xFF);
    txdata[5] = (unsigned char)((len_4k & 0xFFFF) >> 8);

    serialport_drain();
    serialport_write(txdata, 6);

#ifdef _WIN32
    DWORD tstart = GetTickCount();
    DWORD tend = 0;
#else
    struct timeval tv0, tv1;
    gettimeofday(&tv0, NULL);
    unsigned int time_spent = 0;
#endif

    while (wait_times != 0) {
        serialport_read(&read_byte, 1);
        if (read_byte == ACK) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if (tend-tstart > 5000) {
            wait_times--;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            wait_times--;
        }
#endif
    }

    if (wait_times == 0) {
        return false;
    } else {
        if (read_byte == ACK) {
            return true;
        } else {
            return false;
        }
    }
}

uint32_t calculateChecksum(char *name) {
    uint32_t checksum = 0;
    uint32_t data_32 = 0;
    uint8_t data_byte[1];
    uint32_t filesize = 0;
    uint32_t offset_to_align = 0;
    uint32_t read_times = 0;
    uint8_t databuf[4];
    struct stat st;

    if (stat(name, &st) != 0) {
        LOGERR("stat %s failed: %s", name, strerror(errno));
    }

    FILE* f = fopen(name, "rb");
    if (!f) {
        LOGERR("failed to open file for reading");
    }

    filesize = (uint32_t)(st.st_size);
    offset_to_align = filesize & 0x03;
    read_times = (filesize - offset_to_align) / 4;
    int tmp = 0;

    while (read_times-- != 0) {
        if (fread(databuf, 1, 4, f)) {
            data_32 = (uint32_t)(databuf[0]) + (uint32_t)(databuf[1] << 8) + (uint32_t)(databuf[2] << 16) + (uint32_t)(databuf[3] << 24);
            checksum += data_32;
        } else {
            LOGERR("can not read data from file");
        }
    }
    while (tmp < offset_to_align) {
        if (fread(data_byte, 1, 1, f)) {
            checksum += (uint32_t)(data_byte[0] << (tmp * 8));
            tmp++;
        }
    }

    fclose(f);
    LOGDEBUG("cal_sum each=%x", checksum);
    return checksum;
}

uint32_t getChecksumFromXmodem() {
    LOGDEBUG("ENTER getchecksumfromxomdem");
    uint32_t checksum = 0;
    LOGDEBUG("FILNUM=%d\n", filenum);
    for (int i = 0; i < filenum; i++) {
        checksum += xmodem_checksum(allfilename[i], ameba_address[i]);
    }

    LOGDEBUG("CHECKSUM=%d", checksum);
    return checksum;
}

uint32_t xmodem_checksum(char *name, uint32_t address) {
    LOGDEBUG("ENTER xmodem_checksum");
    uint8_t txdata[7];
    uint8_t rxdata[4];
    unsigned char read_byte;
    int wait_times = 5, index = 0;
    uint32_t checksum = 0;
    uint32_t filelen = 0;
    struct stat st;

    if(stat(name, &st) != 0) {
      LOGERR("stat %s failed: %s", name, strerror(errno));
    }

    LOGDEBUG("FILENAME=%s", name);
    filelen = (uint32_t)(st.st_size);

    txdata[0] = CHECKSUM;
    txdata[1] = (uint8_t)(address & 0xFF);
    txdata[2] = (uint8_t)((address & 0xFFFF) >> 8);
    txdata[3] = (uint8_t)((address & 0xFFFFFF) >> 16);
    txdata[4] = (uint8_t)(filelen & 0xFF);
    txdata[5] = (uint8_t)((filelen & 0xFFFF) >> 8);
    txdata[6] = (uint8_t)((filelen & 0xFFFFFF) >> 16);

#ifdef _WIN32
    DWORD tstart = GetTickCount();
    DWORD tend = 0;
#else
    struct timeval tv0, tv1;
    gettimeofday(&tv0, NULL);
    unsigned int time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == NAK) {
            break;
        }

#ifdef _WIN32
        tend=GetTickCount();
        if (tend-tstart > 5000) {
            return 0xFFFFFFFF;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return 0xFFFFFFFF;
        }
#endif
    }

#ifdef _WIN32
    serialport_flush();
#else
    serialport_drain();
#endif

    serialport_write(txdata, 7);
    com_delay_ms(20);

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == CHECKSUM) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if (tend-tstart > 5000) {
            return 0xFFFFFFFF;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            return 0xFFFFFFFF;
        }
#endif
    }

#ifdef _WIN32
    tstart = GetTickCount();
    tend = 0;
#else
    gettimeofday(&tv0, NULL);
    time_spent = 0;
#endif
    while (wait_times != 0) {
        serialport_read(&rxdata[index], 1);
        index++;
        if (index == 4) {
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        if (tend-tstart > 5000) {
            wait_times--;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 5000) {
            wait_times--;
        }
#endif
    }

    if (wait_times == 0) {
        return 0xFFFFFFFF;
    } else {
        checksum = (uint32_t)((rxdata[0] & 0x000000FF) + ((rxdata[1] << 8) & 0x0000FF00) + ((rxdata[2] << 16) & 0x00FF0000) + ((rxdata[3] << 24) & 0xFF000000));
        LOGDEBUG("checksum each=%x\n", checksum);
        return checksum;
    }
}

void redownload(void) {
    unsigned char read_byte;
    while (true) {
        serialport_read(&read_byte, 1);
        if (read_byte == NAK) {
            break;
        }
    }

    serialport_drain();
    unsigned char write_byte = XM_REDOWNLOAD;
    serialport_write(&write_byte, 1);
    com_delay_ms(20);
}

bool download_images(bool flashloaderflag) {
    xmodem_reset();
    serialport_drain();//discard buffer

    if (xmodem_handshake() == false) {
        LOGERR("Handshake fail!\n");
        return false;
    }
    serialport_drain();//discard buffer

    if (flashloaderflag) {
        uint32_t dst_addr = 0x10002000;
        if (TX_Data("imgtool_flashloader_amebaz.bin", dst_addr, true) == false) {
            return false;
        }
    } else {
        cal_sum = 0;
        for (int i = 0; i < filenum; i++) {
            if (TX_Data(allfilename[i], ameba_address[i], false) == false) {
                return false;
            }
            cal_sum += calculateChecksum(allfilename[i]);
        }
    }

    if (txstatus >= 0) {
        if (endtrans() > 0) {
            if (!flashloaderflag) {
                INFO("All images are sent successfully!\n");
            }
        } else {
            if (flashloaderflag) {
                LOGERR("Flashloader download fail!");
                return false;
            } else {
                LOGERR("Images download fail!");
                return false;
            }
        }
    } else {
        LOGERR("Download fail\n");
        return false;
    }
    return true;
}

void EnterUartDownloadMode() {
    com_delay_ms(100);
    unsigned char  read_byte;
    int NAK_cnt = 0;

#ifdef _WIN32
	DWORD tstart=GetTickCount();
	DWORD tend=0;
#else
	struct timeval tv0, tv1;
	gettimeofday(&tv0, NULL);
	unsigned int time_spent = 0;
#endif

    while (true) {
        serialport_read(&read_byte, 1);
        //receive NAK
        if (read_byte == 0x15) {
            NAK_cnt = 1;
            break;
        }

#ifdef _WIN32
        tend = GetTickCount();
        LOGDEBUG("TIME SPENT=%d\n", (tend - tstart));
        if (tend-tstart > 2000) {
            break;
        }
#else
        gettimeofday(&tv1, NULL);
        time_spent = (tv1.tv_sec - tv0.tv_sec) * 1000 + (tv1.tv_usec / 1000) - (tv0.tv_usec / 1000);
        if (time_spent > 2000) {
            break;
        }
#endif
    }

    if (NAK_cnt == 0) {
        serialport_close();
        //change baudate to 115200 for sending reboot uartburn
        serialport_open(ameba_port, 115200);
        unsigned char by = 0x1B;
        serialport_write(&by, 1);
        unsigned char by2[2] = {0x0D, 0x0A};
        serialport_write(by2, 2);
        com_delay_ms(20);
        unsigned char by3[17] = {0x72, 0x65, 0x62, 0x6F, 0x6F, 0x74, 0x20, 0x75, 0x61, 0x72, 0x74, 0x62, 0x75, 0x72, 0x6E, 0x0D, 0x0A};
        serialport_write(by3, 17);//send reboot uartburn\r\n
        com_delay_ms(20);
    }
}
