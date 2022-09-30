// Single Input and Single Output
#include "Arduino.h"


void *sisoCreate(void);
void *sisoDestroy(void*);
void sisoControl(void*, uint32_t, uint32_t, uint32_t);
int  sisoStart(void*);
void sisoStop(void*);
void sisoPause(void*);
void sisoResume(void*);
void sisoRegIn(void *obj, uint32_t arg1, uint32_t arg2);
void sisoRegOut(void *obj, uint32_t arg1, uint32_t arg2);


