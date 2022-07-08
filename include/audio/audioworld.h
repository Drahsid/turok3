#ifndef T3_AUDIOWORLD_H
#define T3_AUDIOWORLD_H

#include "common.h"
#include "SetN64.h"
#include "mutex.h"
#include <PR/libaudio.h>

typedef struct {
    /* 0x0000 */ u8 unk_0x00[0x110];
    /* 0x0110 */ CMutex mutex; // "Mutex"
    /* 0x0130 */ u8 unk_0x130[0x2A20];
    /* 0x2B50 */ CISet* indexedSetMusic; // "pisMusic"
    /* 0x2B54 */ u32 unk_0x2B54;
    /* 0x2B58 */ u32 unk_0x2B58;
    /* 0x2B5C */ u32 unk_0x2B5C;
    /* 0x2B60 */ u32* musicTypes; // "pMusicTypes"
    /* 0x2B64 */ s32 binaryCount; // "NumberOfBinaries"
} CAudioWorld; /* sizeof = unk */

extern ALSndPlayer* CAudioWorld__GetSndPlayer(CAudioWorld* thisx);
extern void CAudioWorld__Lock(CAudioWorld* thisx);
extern void CAudioWorld__Unlock(CAudioWorld* thisx);

#endif

