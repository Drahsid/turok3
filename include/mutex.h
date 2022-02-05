#ifndef MUTEX_H
#define MUTEX_H

#include "inttypes.h"
#include <PR/os_internal.h>
#include <ultra64.h>

typedef struct {
    /* 0x00 */ OSMesgQueue queue; // "Queue"
    /* 0x18 */ OSMesg msg;  // "Msg"
    /* 0x1C */ int32_t count; // "Count"
} CMutex; /* sizeof = 0x20 */

typedef struct {
    /* 0x00 */ OSMesgQueue queue;
    /* 0x18 */ OSMesg msg;
} CBlocker; /* sizeof = 0x1C */


extern void CMutex__Construct(CMutex* thisx);


// inline functions
static inline void CMutex__Begin(CMutex* thisx) {
    OSIntMask mask = __osDisableInt();

    if (++thisx->count != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&thisx->queue, NULLPTR, OS_MESG_BLOCK);
    }
    else {
        __osRestoreInt(mask);
    }
}

static inline void CMutex__End(CMutex* thisx) {
    OSIntMask mask = __osDisableInt();

    if (--thisx->count) {
        __osRestoreInt(mask);
        osSendMesg(&thisx->queue, NULL, OS_MESG_BLOCK);
    }
    else {
        __osRestoreInt(mask);
    }
}

#ifdef NO_DEFINE_FUNCS
static inline void CBlocker__Construct(CBlocker* thisx) {
    osCreateMesgQueue(&thisx->queue, &thisx->msg, 1);
}
#else
#define CBlocker__Construct(THISX) (osCreateMesgQueue(&(THISX)->queue, &(THISX)->msg, 1))
#endif

#endif

