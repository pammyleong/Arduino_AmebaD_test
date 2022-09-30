#include "CameraIO.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "siso_drv.h"

#ifdef __cplusplus
}
#endif


#define SIMO 0
#define MISO 0
#define MIMO 0


CameraIOClass::CameraIOClass (uint8_t numInput, uint8_t numOutput ) {

    if (numInput > 1){
        
        if (numOutput > 1){
            //MIMO
            #if MIMO
            this->create = &(MIMO::create);
            this->destroy = &(MIMO::destroy);
            this->control = &(MIMO::control);
            this->start = &(MIMO::start);
            this->stop = &(MIMO::stop);
            this->pause = &(MIMO::pause);
            this->resume = &(MIMO::resume);
            #endif
        }
        else {
            // MISO
            #if MISO
            this->create = &(MISO::create);
            this->destroy = &(MISO::destroy);
            this->control = &(MISO::control);
            this->start = &(MISO::start);
            this->stop = &(MISO::stop);
            this->pause = &(MISO::pause);
            this->resume = &(MISO::resume);
            #endif
        }
    } else {
        if (numOutput > 1){
            //SIMO
            #if SIMO
            this->create = &(SIMO::create);
            this->destroy = &(SIMO::destroy);
            this->control = &(SIMO::control);
            this->start = &(SIMO::start);
            this->stop = &(SIMO::stop);
            this->pause = &(SIMO::pause);
            this->resume = &(SIMO::resume);
            #endif
        }
        else {
            // SISO
            #if 0
            this->createIO = &(SISO::createIO);
            this->destroyIO = &(SISO::destroyIO);
            this->control = &(SISO::controlIO);
            this->registerInput = &(SISO::regIn);
            this->registerOutput = &(SISO::regOut);
            this->start = &(SISO::startIO);
            this->stop = &(SISO::stopIO);
            this->pause = &(SISO::pauseIO);
            this->resume = &(SISO::resumeIO);
            #else
            
            this->create = &sisoCreate;
            this->destroy = &sisoDestroy;
            this->control = &sisoControl;
            this->registerInput = &sisoRegIn;
            this->registerOutput = &sisoRegOut;
            this->start = &sisoStart;
            this->stop = &sisoStop;
            this->pause = &sisoPause;
            this->resume = &sisoResume;
            
            #endif
        }
    }
}

