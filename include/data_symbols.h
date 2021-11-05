#ifndef DATA_SYMBOLS_H
#define DATA_SYMBOLS_H

#include "common.h"
#include "tengine.h"

extern struct_D_800F20CC D_800F20CC[];
extern int32_t gThreadPriorityIdle;
extern int32_t gThreadPriorityIdleInit;
extern int32_t gThreadPriorityMain;
extern char gEngineTimestamp[256];
extern char gEngineTimestampFormat[];
extern char gEngineTimestampDate[];
extern char gEngineTimestampTime[];
extern uint32_t D_8011D7E0;
extern OSMesgQueue D_801282F0; // REMOVEME: D_801282F0 is &gSysRCLoader->Queue
extern char gBootSignature[];
extern void* gCFB[];
extern int32_t gCurrentFB;
extern int32_t gCurrentTick;
extern int32_t gCurrentTickFinished;
extern int32_t gCurrentTickWaiting;
extern int32_t gDisplayListCount;
extern struct CFrameData* gFrameData; // TODO: declare CFrameData struct
extern OSMesgQueue gGfxFrameMessageQueue;
extern GFXMsg* gGfxMsg;
extern int32_t gNumTicks0;
extern int32_t gNumTicks1;
extern int32_t gNumTicks2;
extern int32_t gNumTicks3;
extern int32_t gNumTicksPending;
extern int32_t gNumTicksWaiting;
extern int32_t gPendingFB;
extern uint32_t gPoolBuffers; // TODO: declare CPool struct
extern float gRefreshRate;
extern float gRefreshRateNTSC;
extern float gRefreshRatePAL;
extern int32_t gScreenHeight;
extern int32_t gScreenWidth;
extern uint32_t gTotalFramebuffers;
extern uint8_t gValidControllerBits;

#endif

