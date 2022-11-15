#include "StreamIO.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "mimo_drv.h"
#include "miso_drv.h"
#include "simo_drv.h"
#include "siso_drv.h"

#ifdef __cplusplus
}
#endif

void inputErrorFunction(mm_context_t* ctx) {
    (void)ctx;
    printf("ERROR: Wrong input function used for StreamIO object! \r\n");
}

void outputErrorFunction(mm_context_t* ctx) {
    (void)ctx;
    printf("ERROR: Wrong output function used for StreamIO object! \r\n");
}

StreamIO::StreamIO(uint8_t numInput, uint8_t numOutput) {
    if (numInput > 3) {
        printf("StreamIO too many inputs. Max 3 inputs.\r\n");
        return;
    }
    if (numOutput > 2) {
        printf("StreamIO too many outputs. Max 2 outputs.\r\n");
        return;
    }
    if (numInput > 1) {
        if (numOutput > 1) {
            // MIMO (Multi Input Multi Output)
            this->create = &mimoCreate;
            this->destroy = &mimoDestroy;
            this->registerInput = &inputErrorFunction;
            this->registerInput1 = &mimoRegIn1;
            this->registerInput2 = &mimoRegIn2;
            this->registerInput3 = &mimoRegIn3;
            this->registerOutput = &outputErrorFunction;
            this->registerOutput1 = &mimoRegOut1;
            this->registerOutput2 = &mimoRegOut2;
            this->start = &mimoStart;
            this->stop = &mimoStop;
            this->pause = &mimoPause;
            this->resume = &mimoResume;

            getInput(numInput);
            printf("NumIn = %d ", numInput);
        } else {
            // MISO (Multi Input Single Output)
            this->create = &misoCreate;
            this->destroy = &misoDestroy;
            this->registerInput = &inputErrorFunction;
            this->registerInput1 = &misoRegIn1;
            this->registerInput2 = &misoRegIn2;
            this->registerInput3 = &inputErrorFunction;
            this->registerOutput = &misoRegOut;
            this->registerOutput1 = &outputErrorFunction;
            this->registerOutput2 = &outputErrorFunction;
            this->start = &misoStart;
            this->stop = &misoStop;
            this->pause = &misoPause;
            this->resume = &misoResume;
        }
    } else {
        if (numOutput > 1) {
            // SIMO (Single Input Multi Output)
            this->create = &simoCreate;
            this->destroy = &simoDestroy;
            this->registerInput = &simoRegIn;
            this->registerInput1 = &inputErrorFunction;
            this->registerInput2 = &inputErrorFunction;
            this->registerInput3 = &inputErrorFunction;
            this->registerOutput = &outputErrorFunction;
            this->registerOutput1 = &simoRegOut1;
            this->registerOutput2 = &simoRegOut2;
            this->start = &simoStart;
            this->stop = &simoStop;
            this->pause = &simoPause;
            this->resume = &simoResume;
        } else {
            // SISO (Single Input Single Output)
            this->create = &sisoCreate;
            this->destroy = &sisoDestroy;
            this->registerInput = &sisoRegIn;
            this->registerInput1 = &inputErrorFunction;
            this->registerInput2 = &inputErrorFunction;
            this->registerInput3 = &inputErrorFunction;
            this->registerOutput = &sisoRegOut;
            this->registerOutput1 = &outputErrorFunction;
            this->registerOutput2 = &outputErrorFunction;
            this->start = &sisoStart;
            this->stop = &sisoStop;
            this->pause = &sisoPause;
            this->resume = &sisoResume;
            this->setStackSize = &sisoSetStackSize;
            this->setTaskPriority = &sisoSetTaskPriority;
        }
    }
}