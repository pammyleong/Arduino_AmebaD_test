#ifndef __ARRAY_H__
#define __ARRAY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "array_drv.h"
#include "avcodec.h"

#ifdef __cplusplus
}
#endif

#include "VideoStream.h"

class Array:public MMFModule {
    public:
        Array(void);
        ~Array(void);

        void configArray(void);
        void begin(void);
        void end(void);

        void printInfo(void);

    private:
        
};

#endif