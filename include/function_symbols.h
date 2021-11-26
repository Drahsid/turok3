#ifndef FUNCTION_SYMBOLS_H
#define FUNCTION_SYMBOLS_H

#include "common.h"
#include "tengine.h"

extern uint32_t func_20A9E0(int32_t arg0);
extern void* memset(void* ptr, int32_t value, uint32_t bytes);
extern void boot();
extern int32_t CCache_GetFromLookupTable(int32_t offset);
extern void CCameraPool__Construct(CCameraPool* thisx);
extern void CCameraPool__NewGame(CCameraPool* thisx, int32_t maxCameraCount);
extern void CCollisionInfo__Reset(void);
extern void COnScreen__Construct(struct COnScreen* thisx); // TODO: declare COnScreen struct
extern void CPlayerPool__Construct(CPlayerPool* thisx);
extern void CPlayerPool__NewGame(CPlayerPool* thisx, int32_t maxPlayerCount);
extern void CPool__AllocateStandardBuffers(struct CPool* thisx); // TODO: declare CPool struct
extern void CPool__Construct(struct CPool* thisx); // TODO: declare CPool struct
extern void CScene__Construct(CScene* thisx, void* romData);
extern void InitControllers(void);
extern void InitializeSystemResources(void);
extern void PAK_InitSystem(void);
extern void func_2523A4(void);
extern void func_252414(void*);
extern void func_25245C(int32_t);
extern void func_26AEE0(uint32_t*);
extern void func_285FC4(CEngineApp* thisx, int32_t);
extern void func_286058(CEngineApp* thisx, int32_t);
extern void func_41FBF8(void);
extern uint32_t func_287068(uint32_t);
extern void VM_Initialize(char*, char*);
extern void CCache__Construct(OSId threadId);
extern void func_232A68(void);
extern void func_232B00(void);
extern void func_241BD8(void);

#endif

