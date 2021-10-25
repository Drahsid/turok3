#include "include_asm.h"
#include "function_symbols.h"
#include "data_symbols.h"
#include "tengine.h"
#include "common.h"
#include "PR/os.h"

INCLUDE_ASM(s32, "tengine", func_283E80);

INCLUDE_ASM(s32, "tengine", func_284004);

INCLUDE_ASM(s32, "tengine", func_284208);

INCLUDE_ASM(s32, "tengine", CEngineApp__Main);

INCLUDE_ASM(s32, "tengine", func_2849BC);

INCLUDE_ASM(s32, "tengine", func_284B80);

INCLUDE_ASM(s32, "tengine", func_284D7C);

INCLUDE_ASM(s32, "tengine", func_285024);

INCLUDE_ASM(s32, "tengine", func_285424);

INCLUDE_ASM(s32, "tengine", func_28577C);

void boot(void) {
    CEngineApp__Boot(GetApp());
}

// Codegen is different, but this matches
/*#ifdef BAD_CODEGEN
void CEngineApp__Boot(CEngineApp* thisx) {
    memset(gThreadStackIdle, THREAD_IDLE, STACKSIZE_IDLE);
    osCreateThread(&gThreadIdle, THREAD_IDLE, idle, 0, gThreadStackIdle + STACKSIZE_IDLE, gThreadPriorityIdleInit);
    osStartThread(&gThreadIdle);
}
#else*/
INCLUDE_ASM(s32, "tengine", CEngineApp__Boot);
//#endif

// Codegen is different, but this matches
/*#ifdef BAD_CODEGEN
void CEngineApp__Idle(CEngineApp* thisx, void* arg) {
    memset(gThreadStackMain, THREAD_MAIN, STACKSIZE_MAIN);

    osCreateThread(&gThreadMain, THREAD_MAIN, mainproc, arg, gThreadStackMain + STACKSIZE_MAIN, gThreadPriorityMain);
    osStartThread(&gThreadMain);

    osSetThreadPri(NULL, gThreadPriorityIdle);

    while (1) {}
}
#else*/
INCLUDE_ASM(s32, "tengine", CEngineApp__Idle);
//#endif

INCLUDE_ASM(s32, "tengine", func_285CD8);

INCLUDE_ASM(s32, "tengine", func_285DA8);

INCLUDE_ASM(s32, "tengine", func_285DC4);

INCLUDE_ASM(s32, "tengine", func_285E00);

INCLUDE_ASM(s32, "tengine", func_285E50);

INCLUDE_ASM(s32, "tengine", func_285EFC);

void idle(void* arg) {
    CEngineApp__Idle(GetApp(), arg);
}

void mainproc(void* arg) {
    uint32_t fpstat;

    //sprintf(gEngineTimestamp, "%s %s", __DATE__, __TIME__);
    sprintf(gEngineTimestamp, gEngineTimestampFormat, gEngineTimestampDate, gEngineTimestampTime);

    // enable divide-by-zero exception for floating-point
    fpstat = __osGetFpcCsr();
    fpstat |= 0x400;
    __osSetFpcCsr(fpstat);

    CEngineApp__Main(GetApp());
}

INCLUDE_ASM(s32, "tengine", func_285F94);

INCLUDE_ASM(s32, "tengine", func_285FC4);

INCLUDE_ASM(s32, "tengine", func_286058);

INCLUDE_ASM(s32, "tengine", func_28607C);

INCLUDE_ASM(s32, "tengine", func_28620C);

INCLUDE_ASM(s32, "tengine", func_2862C8);

INCLUDE_ASM(s32, "tengine", func_28635C);

INCLUDE_ASM(s32, "tengine", func_286438);

INCLUDE_ASM(s32, "tengine", func_286520);

INCLUDE_ASM(s32, "tengine", func_28653C);

INCLUDE_ASM(s32, "tengine", func_286574);

INCLUDE_ASM(s32, "tengine", func_2865C4);

INCLUDE_ASM(s32, "tengine", func_286610);

void func_286798(void) {
}

INCLUDE_ASM(s32, "tengine", func_2867A0);

INCLUDE_ASM(s32, "tengine", func_286808);

void func_2868BC(void) {
}

INCLUDE_ASM(s32, "tengine", func_2868C4);

INCLUDE_ASM(s32, "tengine", func_2868FC);

INCLUDE_ASM(s32, "tengine", func_286930);

INCLUDE_ASM(s32, "tengine", func_286B90);

INCLUDE_ASM(s32, "tengine", func_287068);

INCLUDE_ASM(s32, "tengine", func_28714C);

INCLUDE_ASM(s32, "tengine", func_287218);

INCLUDE_ASM(s32, "tengine", func_287234);

INCLUDE_ASM(s32, "tengine", func_287258);

INCLUDE_ASM(s32, "tengine", func_287318);

INCLUDE_ASM(s32, "tengine", func_2873D8);

INCLUDE_ASM(s32, "tengine", func_287458);

INCLUDE_ASM(s32, "tengine", func_2874FC);

INCLUDE_ASM(s32, "tengine", func_287518);

INCLUDE_ASM(s32, "tengine", func_287564);

INCLUDE_ASM(s32, "tengine", func_2875B0);

INCLUDE_ASM(s32, "tengine", func_2875FC);

INCLUDE_ASM(s32, "tengine", func_2876A0);

INCLUDE_ASM(s32, "tengine", func_287720);

INCLUDE_ASM(s32, "tengine", func_287730);

INCLUDE_ASM(s32, "tengine", func_287740);

INCLUDE_ASM(s32, "tengine", func_287758);

INCLUDE_ASM(s32, "tengine", func_287770);
