#ifndef TENGINE_H
#define TENGINE_H

#include "inttypes.h"

typedef struct {
    /* 0x00000 */ uint8_t unk_0x00[0x3C4]; // framedata and pointer to current frame data
    /* 0x003C4 */ void* m_pStaticSegment;
    /* 0x003C8 */ uint8_t unk_0x38C[0x23CC4]; // the rest (starting with CScene)
} CEngineApp; /* sizeof = 0x24050 */

extern CEngineApp gEngineApp;

#define GetApp() (&gEngineApp)

extern void CEngineApp__Main(CEngineApp* thisx);
extern void boot(void);
extern void CEngineApp__Boot(CEngineApp* thisx);
extern void CEngineApp__Idle(CEngineApp* thisx, void* arg);
extern void idle(void* arg);
extern void mainproc(void* arg);

#endif

