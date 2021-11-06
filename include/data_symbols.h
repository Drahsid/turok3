#ifndef DATA_SYMBOLS_H
#define DATA_SYMBOLS_H

#include "common.h"
#include "tengine.h"

extern struct_D_800F20CC D_800F20CC[];
extern OSPri gThreadPriorityIdle;
extern OSPri gThreadPriorityIdleInit;
extern OSPri gThreadPriorityMain;
extern OSPri gThreadPriorityLoader;
extern OSPri gThreadPriorityScheduler;
extern char gEngineTimestamp[256];
extern char gEngineTimestampFormat[];
extern char gEngineTimestampDate[];
extern char gEngineTimestampTime[];
extern uint32_t D_8011D7E0;
extern OSMesgQueue D_801282F0; // REMOVEME: D_801282F0 is &gSysRCLoader->Queue
extern char gBootSignature[];
extern void* gCFB[];
extern uint32_t gPoolBuffers; // TODO: declare CPool struct
extern float gRefreshRateNTSC;
extern float gRefreshRatePAL;
extern int32_t gScreenHeight;
extern int32_t gScreenWidth;
extern uint32_t gTotalFramebuffers;
extern uint8_t gValidControllerBits;
extern Gfx* gDList;
extern UNK_TYPE D_80166190;
extern uint32_t gFirstBoot;
extern UNK_TYPE D_801659B0;
extern float D_800FB0BC;
extern struct_D_80124ECD D_80124ECD;

#endif

