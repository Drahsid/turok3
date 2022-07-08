#ifndef T3_RAXPLAYER_H
#define T3_RAXPLAYER_H

#include "common.h"
#include "audioworld.h"

enum {
    /* 0 */ RAX_IDLE = 0,
    /* 1 */ RAX_STARTING,
    /* 2 */ RAX_STOPPING,
    /* 3 */ RAX_PLAYING
};

typedef struct {
    /* 0x00 */ CAudioWorld* audioWorld; // "AudioWorld"
    /* 0x04 */ s32 lastRaxStarted;      // "LastRaxStarted"
    /* 0x08 */ u32 raxEffectState;      // "RaxEffectState"
    /* 0x0C */ s32 raxNewEffectType;    // "RaxNewEffectType"
    /* 0x10 */ s32 raxNewEffectIndex;   // "RaxNewEffectIndex;"
    /* 0x14 */ s32 raxNewEffectVol;     // "RaxNewEffectVol;"
    /* 0x18 */ s32 raxNewEffectPan;     // "RaxNewEffectPan;"
    /* 0x1C */ s32 unk_0x1C;
    /* 0x20 */ s32 raxSoundID;          // "RAXSoundID";
    /* 0x24 */ f32 currentVol;          // "VolSpecifiedForCurrent"
    /* 0x28 */ f32 currentReverb;       // "ReverbSpecifiedForCurrent"
    /* 0x2C */ s32 unk_0x2C;
} CRAXPlayer; /* sizeof = 0x30 */

extern void CRAXPlayer__Initialize(CRAXPlayer* thisx, CAudioWorld* aw);
extern u32 CRAXPlayer__StartRaxSample(CRAXPlayer* thisx, s32 sampleType, f32 volume, s8 pan, s32 arg4);
extern void CRAXPlayer__Update(CRAXPlayer* thisx);
extern void CRAXPlayer__KillRAX(CRAXPlayer* thisx);

#endif

