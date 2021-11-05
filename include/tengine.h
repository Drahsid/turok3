#ifndef TENGINE_H
#define TENGINE_H

#include "inttypes.h"
#include "playerai.h"
#include "camera.h"
#include "scene.h"
#include "sun.h"
#include <PR/sched.h>

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
    /* 0x000 */ CSunFrameData m_SunFrame;
    /* 0x020 */ OSScTask m_Task;
    /* 0x088 */ OSScTask m_LineTask;
    /* 0x0F0 */ GFXMsg m_Message;
    /* 0x110 */ void* m_pFrameBuffer;
    /* 0x114 */ Gfx* m_pDisplayList;
    /* 0x118 */ Gfx* m_pLineList;
    /* 0x11C */ uint32_t m_DisplayListSize;
    /* 0x120 */ uint32_t m_LineListSize;
    /* 0x124 */ uint32_t m_nPredictTicks;
    /* 0x128 */ struct CFrameData* m_pPrev;
    /* 0x12C */ struct CFrameData* m_pNext;
    /* 0x130 */ uint8_t _pad[8];
} CFrameData; /* sizeof = 0x138 */

typedef struct {
    /* 0x00000 */ CFrameData m_FrameData[3];
    /* 0x003A8 */ CFrameData* m_pCurrentFrameData;
    /* 0x003AC */ void* m_pStaticSegment;
    /* 0x003B0 */ CScene m_Scene;
    /* 0x1D7E0 */ uint8_t unk_0x1D7E0[0x96D0];
    /* 0x26EB0 */ CPlayerPool m_PlayerPool;
    /* 0x26EF4 */ uint32_t unk_0x26EF8;
    /* 0x26EF8 */ uint32_t unk_0x26EFC;
    /* 0x26EFC */ CCameraPool m_CameraPool;
    /* 0x280E8 */ uint8_t unk_0x280E8[0x704];
    /* 0x287EC */ uint8_t unk_0x287EC;
    /* 0x287ED */ uint8_t unk_0x287ED[3];
    /* 0x287F0 */ uint32_t unk_0x287F0;
    /* 0x287F4 */ uint32_t unk_0x287F4;
    /* 0x287F8 */ uint32_t unk_0x287F8;
    /* 0x287FC */ uint32_t unk_0x287FC;
    /* 0x28800 */ uint32_t unk_0x28800;
    /* 0x28804 */ uint32_t unk_0x28804;
    /* 0x28808 */ uint32_t unk_0x28808;
    /* 0x2880C */ uint32_t unk_0x2880C;
    /* 0x28810 */ uint32_t unk_0x28810;
    /* 0x28814 */ uint32_t unk_0x28814;
    /* 0x28818 */ uint32_t m_LastMode;
    /* 0x2881C */ uint32_t m_Mode;
    /* 0x28820 */ uint32_t unk_0x28820;
    /* 0x28824 */ uint32_t unk_0x28824;
    /* 0x28828 */ uint32_t unk_0x28828;
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

extern CEngineApp gEngineApp;

#define GetApp() (&gEngineApp)
#define MAX_DISPLAY_LISTS (2)

extern void CEngineApp__Main(CEngineApp* thisx);
extern void boot(void);
extern void CEngineApp__Boot(CEngineApp* thisx);
extern void CEngineApp__Idle(CEngineApp* thisx, void* arg);
extern void idle(void* arg);
extern void mainproc(void* arg);

extern void CEngineApp__Construct(CEngineApp* thisx);
extern void CEngineApp__Retrace(CEngineApp* thisx);
extern void CEngineApp__Update(CEngineApp* thisx);

#endif

