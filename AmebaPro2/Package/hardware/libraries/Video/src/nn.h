#ifndef __NN_H__
#define __NN_H__

#ifdef __cplusplus
extern "C" {
#endif

// #include "nn_drv.h"  // includes nn, md, osd source code 

#ifdef __cplusplus
}
#endif

class NNClass {
    public:
        NNClass(void);
        ~NNClass();

        static int check_in_list(int class_indx);
        static void nn_set_object(void *p, void *img_param);
        static void md_process(void *md_result);


    private:

};

class MDClass {
    public:
        MDClass(void);
        ~MDClass();
};

class OSDClass {
    public:
        OSDClass(void);
        ~OSDClass();
};

#endif
