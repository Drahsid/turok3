#ifndef TENGINE_H
#define TENGINE_H

#include "inttypes.h"
#include "playerai.h"
#include "camera.h"
#include "scene.h"
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

typedef struct {
    /* 0x00000 */ uint8_t unk_0x00[0x3AC]; // framedata and pointer to current frame data
    /* 0x003AC */ void* m_pStaticSegment;
    /* 0x003B0 */ CScene m_Scene;
    /* 0x1D7E0 */ uint8_t unk_0x1D7E0[0x96D0];
    /* 0x26EB0 */ CPlayerPool m_PlayerPool;
    /* 0x26EF8 */ CCameraPool m_CameraPool;
    /* 0x280E8 */ uint8_t unk_0x280E8[0x704];
    /* 0x287EC */ uint8_t unk_0x287EC;
    /* 0x287ED */ uint8_t unk_0x287ED[3];
    /* 0x287F0 */ uint8_t unk_0x287F0[0x2C];
    /* 0x2881C */ uint32_t m_Mode;
    /* 0x28820 */ uint8_t unk_0x28820[0x10];
    /* 0x28830 */ int32_t unk_0x28830;
    /* 0x28834 */ uint8_t unk_0x28834[0x20];
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

