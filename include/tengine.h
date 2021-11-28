#ifndef TENGINE_H
#define TENGINE_H

#include "inttypes.h"
#include "playerai.h"
#include "camera.h"
#include "scene.h"
#include "sun.h"
#include "options.h"
#include <PR/sched.h>

#define GetApp() (&gEngineApp)
#define MAX_DISPLAY_LISTS (2)
#define CALC_FRAMERATE(MIN_TICKS) MAX(MIN_TICKS, ((gNumTicks0 + gNumTicks1 + gNumTicks2 + gNumTicks3 + 2) - MAX(gNumTicks0, MAX(gNumTicks1, MAX(gNumTicks2, gNumTicks3)))) / 3)
#define FRAME_FPS (15)

typedef union {
    struct {
        int16_t type;
    } gen;
    struct {
        int16_t type;
    } done;
    OSScMsg app;
} GFXMsg;

typedef struct CFrameData {
    /* 0x000 */ CSunFrameData sunFrameData; // "m_SunFrame"
    /* 0x020 */ OSScTask gfxTask;           // "m_Task"
    /* 0x088 */ OSScTask lineTask;          // "m_LineTask"
    /* 0x0F0 */ GFXMsg message;             // "m_Msg"
    /* 0x110 */ void* frameBuffer;          // "m_pFrameBuffer"
    /* 0x114 */ Gfx* displayListHead;       // "m_pDisplayList"
    /* 0x118 */ Gfx* lineListHead;          // "m_pLineList"
    /* 0x11C */ uint32_t displayListSize;   // "m_DisplayListSize"
    /* 0x120 */ uint32_t lineListSize;      // "m_LineListSize"
    /* 0x124 */ uint32_t predictionTicks;   // "m_nPredictTicks"
    /* 0x128 */ struct CFrameData* prev;    // "m_pPrev"
    /* 0x12C */ struct CFrameData* next;    // "m_pNext"
    /* 0x130 */ uint8_t _pad[8];
} CFrameData; /* sizeof = 0x138 */

typedef struct {
    /* 0x00000 */ CFrameData frameData[3];      // "m_FrameData"
    /* 0x003A8 */ CFrameData* currentFrameData; // "m_pCurrentFrameData"
    /* 0x003AC */ void* staticSegment;          // "m_pStaticSegment"
    /* 0x003B0 */ CScene scene;                 // "m_Scene"
    /* 0x1D7E0 */ uint8_t unk_0x1D7E0[0x96D0];
    /* 0x26EB0 */ CPlayerPool playerPool;       // "m_PlayerPool"
    /* 0x26EF4 */ uint32_t unk_0x26EF4;
    /* 0x26EF8 */ uint32_t unk_0x26EF8;
    /* 0x26EFC */ uint32_t unk_0x26EFC;
    /* 0x26F00 */ CCameraPool cameraPool;       // "m_CameraPool"
    /* 0x280E8 */ uint8_t unk_0x280E8[0x4];
    /* 0x280F0 */ COptions options;             // "m_Options"
    /* 0x287E0 */ CSun sun;                     // "m_Sun"
    /* 0x28804 */ uint32_t unk_0x28804;
    /* 0x28808 */ float unk_0x28808;
    /* 0x2880C */ float unk_0x2880C;
    /* 0x28810 */ float unk_0x28810;
    /* 0x28814 */ float modeTime;               // "m_ModeTime"
    /* 0x28818 */ uint32_t lastMode;            // "m_LastMode"
    /* 0x2881C */ uint32_t currentMode;         // "m_Mode"
    /* 0x28820 */ uint32_t unk_0x28820;
    /* 0x28824 */ uint8_t unk_0x28824;
    /* 0x28825 */ uint8_t unk_0x28825;
    /* 0x28826 */ uint8_t unk_0x28826;
    /* 0x28827 */ uint8_t unk_0x28827;
    /* 0x28828 */ float fadeAlpha;              // "m_FadeAlpha"
    /* 0x2882C */ float unk_0x2882C;
    /* 0x28830 */ int32_t unk_0x28830;
    /* 0x28834 */ uint32_t unk_0x28834;
    /* 0x28838 */ uint32_t unk_0x28838;
    /* 0x2883C */ uint32_t unk_0x2883C;
    /* 0x28840 */ uint32_t unk_0x28840;
    /* 0x28844 */ uint32_t unk_0x28844;
    /* 0x28848 */ uint32_t unk_0x28848;
    /* 0x2884C */ uint32_t unk_0x2884C;
    /* 0x28850 */ uint32_t unk_0x28850;
    /* 0x28854 */ uint32_t unk_0x28854;
} CEngineApp; /* sizeof = unk */

typedef void(*CEngineFunction)(CEngineApp* thisx);

typedef struct {
    /* 0x00 */ CEngineFunction retraceFunction; // "m_pfRetraceFunction"
    /* 0x04 */ CEngineFunction unk_0x4;
    /* 0x08 */ CEngineFunction unk_0x8;
} CEngineModeInfo; /* sizeof = 0x0C */


extern CEngineApp gEngineApp;               // "engine_app"
extern GFXMsg* gGfxMsg;                     // "pMsg"
extern CFrameData* gFrameData;              // "pFrameData"
extern int32_t gDisplayListCount;           // "nDisplayLists"
extern int32_t gNextTicks;                  // "nNextFields"
extern OSSched gScheduler;                  // "sc"
extern OSScClient gGfxClient;               // "gfxClient"
extern int32_t gFirstFrame;                 // "firstFrame"
extern OSMesgQueue gGfxFrameMessageQueue;   // "gfxFrameMsgQ"
extern OSMesg gGfxFrameMessageBuffer[];     // "gfxFrameMsgBuf"
extern int32_t gCurrentTick;                // "c_field"
extern int32_t gNumTicks0;                  // "n_fields"
extern int32_t gNumTicks1;                  // "n_l_fields"
extern int32_t gNumTicks2;                  // "n_ll_fields"
extern int32_t gNumTicks3;                  // "n_lll_fields"
extern int32_t gNumTicksPending;            // "n_pending"
extern int32_t gCurrentTickWaiting;         // "c_waiting"
extern int32_t gNumTicksWaiting;            // "n_waiting"
extern int32_t gCurrentTickFinished;        // "c_finished"
extern int32_t gCurrentFB;                  // "p_current_fb"
extern int32_t gPendingFB;                  // "p_pending_fb"
extern float gFrameIncrement;               // "frame_increment"
extern uint32_t gFrameCount;                // "frame_number"
extern uint32_t gEvenOdd;                   // "even_odd"
extern uint32_t gFrameCountGameplay;        // "game_frame_number"
extern uint32_t gRetraceCount;              // "retrace_count"
extern OSTime gLastEngineUpdate;            // "LastEngineUpdate"
extern float gRefreshRate;                  // "refresh_rate"
extern Vtx gShadowVertexes[];               // "shadow_vtxs"
extern CEngineModeInfo gEngineModeTable[];  // "EngineModeTable"


extern void CEngineApp__Construct(CEngineApp* thisx);
extern void CEngineApp__Main(CEngineApp* thisx);
extern void CEngineApp__Draw(CEngineApp* thisx);
extern void CEngineApp__Update(CEngineApp* thisx);
extern void boot(void);
extern void CEngineApp__Boot(CEngineApp* thisx);
extern void CEngineApp__Idle(CEngineApp* thisx, void* arg);
extern void CEngineApp__AdvanceFrameData(CEngineApp* thisx);
extern void idle(void* arg);
extern void mainproc(void* arg);
extern void CEngineApp__InitFade(CEngineApp* thisx);
extern void CEngineApp__Retrace(CEngineApp* thisx);

extern void CEngineApp__SetupShadowVtxs(void);

#endif

