#include "siso_drv.h"
#include "mmf2_link.h"
#include "mmf2_siso.h"

mm_siso_t *siso_arduino = NULL;


/**
  * @brief  allocate memory for a siso object
  * @param  none
  * @retval  pointer to the siso object
  */
void* sisoCreate(void) {
    //create SISO queue and task
    siso_arduino = siso_create();
    return (void*)siso_arduino;
}

void* sisoDestroy(void *obj) {
    //TO-DO
    return NULL;

}


/**
  * @brief  command-based api to control input output source and parameters
  * @param  obj: siso object
  * @param  cmd: command to control siso behaviours, value can be anything starting with "MMIC_CMD" defined in "mmf2_link.h"
  * @param  arg1: this argument can be input and output source, or other config values
  * @param  arg2: second input source, only used when input queue larger than 1
  * @retval  none
  */
void sisoControl(void *obj, uint32_t cmd, uint32_t arg1, uint32_t arg2) {
    switch (cmd) {
        case MMIC_CMD_ADD_INPUT:
            siso_ctrl((mm_siso_t *)obj, MMIC_CMD_ADD_INPUT, arg1, arg2);
            break;
        case MMIC_CMD_ADD_OUTPUT:
            siso_ctrl((mm_siso_t *)obj, MMIC_CMD_ADD_OUTPUT, arg1, 0);
            break;
        default:
            siso_ctrl((mm_siso_t *)obj, cmd, arg1, 0);
    }
}


/**
  * @brief  api to register input source to SISO
  * @param  obj: siso object
  * @param  arg1: this argument is an input source
  * @param  arg2: secondary input source
  * @retval  none
  */
void sisoRegIn(void *obj, uint32_t arg1, uint32_t arg2) {
    siso_ctrl((mm_siso_t *)obj, MMIC_CMD_ADD_INPUT, arg1, arg2);
}


/**
  * @brief  api to register output source to SISO
  * @param  obj: siso object
  * @param  arg1: this argument is output source
  * @param  arg2: secondary output source
  * @retval  none
  */
void sisoRegOut(void *obj, uint32_t arg1, uint32_t arg2) {
    siso_ctrl((mm_siso_t *)obj, MMIC_CMD_ADD_OUTPUT, arg1, arg2);
}


/**
  * @brief  create a pumper task that send and receive data between input and output
  * @param  obj: pointer to siso object
  * @retval :0 for success, -1 for fail
  */
int sisoStart(void *obj) {
    return siso_start((mm_siso_t *)obj);
}


void sisoStop(void *obj) {
    //TO-DO

}

void sisoPause(void *obj) {
    //TO-DO

}

void sisoResume(void *obj) {
    //TO-DO

}


