#include <Arduino.h>
#include "nn.h"

#ifdef __cplusplus
extern "C" {
#endif

// #include "camera_drv.h"

#ifdef __cplusplus
}
#endif

#define DEBUG 0

#if DEBUG
#define CAMDBG(fmt, args...) \
    do {printf("\r\nFunc-[%s]@Line-%d: \r\n" fmt "\r\n", __func__, __LINE__, ## args); } while (0);
#else
#define CAMDBG(fmt, args...)
#endif

NNClass::NNClass(){
    // nn_data = NULL;
};

NNClass::~NNClass(){};

MDClass::MDClass(){
    // nn_data = NULL;
};

MDClass::~MDClass(){};

OSDClass::OSDClass(){
    // nn_data = NULL;
};

OSDClass::~OSDClass(){};
