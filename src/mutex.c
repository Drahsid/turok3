#include "mutex.h"
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/mutex/", func_243910);

void CMutex__Construct(CMutex* thisx) {
    thisx->count = 0;
    osCreateMesgQueue(&thisx->queue, &thisx->msg, 1);
}


