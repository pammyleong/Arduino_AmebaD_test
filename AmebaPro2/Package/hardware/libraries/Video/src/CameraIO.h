#include "Arduino.h"

class CameraIOClass
{
public:
    CameraIOClass(uint8_t numInput, uint8_t numOutput);

    uint8_t numInput;
    uint8_t numOutput;

    // function pointers
    void *(*create)(void);
    void (*destroy)(void*);
    void (*registerInput)(void*, uint32_t, uint32_t);
    void (*registerOutput)(void*, uint32_t, uint32_t);
    int  (*start)(void*);
    void (*stop)(void*);
    void (*pause)(void*);
    void (*resume)(void*);
};

