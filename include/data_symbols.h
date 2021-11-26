#ifndef DATA_SYMBOLS_H
#define DATA_SYMBOLS_H

#include "common.h"
#include "tengine.h"

extern struct_D_800F20CC D_800F20CC[];
extern OSPri gThreadPriorityIdle; // "PRIORITY_IDLE"
extern OSPri gThreadPriorityIdleInit; // "PRIORITY_IDLEINIT"
extern OSPri gThreadPriorityMain; // "PRIORITY_MAIN"
extern OSPri gThreadPriorityLoader; // "PRIORITY_LOADER"
extern OSPri gThreadPriorityScheduler; // "PRIORITY_SCHEDULER"
extern OSPri gThreadPriorityCache; // "PRIORITY_CACHE"
extern OSPri gThreadPriorityDecompressorLow; // "PRIORITY_DECOMPRESSOR_LOW"
extern char gEngineTimestamp[256];
extern char gEngineTimestampFormat[];
extern char gEngineTimestampDate[];
extern char gEngineTimestampTime[];
extern uint32_t D_8011D7E0;
extern OSMesgQueue D_801282F0; // REMOVEME: D_801282F0 is &gSysRCLoader->Queue
extern uint32_t gFirstBoot; // "b_first_boot"
extern char gBootSignature[]; // "signature"
extern void* gCFB[]; // "cfb_16"
extern uint32_t gPoolBuffers; // "pool_buffers" TODO: declare CPool struct
extern const float gRefreshRateNTSC;
extern const float gRefreshRatePAL;
extern int32_t gScreenWidth; // "screen_width"
extern int32_t gScreenHeight; // "screen_height"
extern uint32_t gTotalFramebuffers; // "total_frame_buffers"
extern Gfx* gDisplayList0; // "display_list_a"
extern Gfx* gDisplayList1; // "display_list_b"
extern Gfx* gLineList0; // "line_list_a"
extern Gfx* gLineList1; // "line_list_b"
extern uint8_t gValidControllerBits; // "ValidControllers"
extern Gfx* gDList; // "pDList"
extern UNK_TYPE D_80166190;
extern UNK_TYPE D_801659B0;
extern float D_800FB0BC;
extern struct_D_80124ECD D_80124ECD;
extern float D_800F8D60;

#endif

