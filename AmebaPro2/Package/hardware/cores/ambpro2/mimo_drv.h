// Multiple Input and Single Output
#include "Arduino.h"
#include "mmf2_module.h"


void mimoCreate(void);
void mimoDestroy(void);
int  mimoStart(void);
void mimoStop(void);
void mimoPause(void);
void mimoResume(void);
void mimoRegIn0(mm_context_t*);
void mimoRegIn1(mm_context_t*);
void mimoRegOut0(mm_context_t*);
void mimoRegOut1(mm_context_t*);

