// Single Input and Single Output
#include "Arduino.h"


void *sisoCreate(void);
void sisoDestroy(void*);
int  sisoStart(void*);
void sisoStop(void*);
void sisoPause(void*);
void sisoResume(void*);
void sisoRegIn(void*, uint32_t, uint32_t);
void sisoRegOut(void*, uint32_t, uint32_t);

