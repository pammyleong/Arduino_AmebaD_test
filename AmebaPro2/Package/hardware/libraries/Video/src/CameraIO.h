//#include "IO_SISO.h"
//#include "IO_MISO.h"
//#include "IO_SIMO.h"
//#include "IO_MIMO.h"
#include "Arduino.h"

class CameraIOClass
{
public:
    uint8_t numInput;
    uint8_t numOutput;

    CameraIOClass(uint8_t numInput, uint8_t numOutput);

    // function pointers
    void *(*create)();
    void *(*destroy)(void*);
    void (*control)(void*, uint32_t, uint32_t, uint32_t);
    void (*registerInput)(void*, uint32_t, uint32_t);
    void (*registerOutput)(void*, uint32_t, uint32_t);
    int  (*start)(void*);
    void (*stop)(void*);
    void (*pause)(void*);
    void (*resume)(void*);
};

