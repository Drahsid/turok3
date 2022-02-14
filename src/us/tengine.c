#include "tengine.h"
#include "options.h"
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/tengine", func_283E80);

INCLUDE_ASM("asm/nonmatchings/tengine", func_284004);

// Behaviorally matching, AS pseudo-op issue, D_80124ECD struct
#ifdef NON_MATCHING
void CEngineApp__Construct(CEngineApp* thisx) {
    uint32_t index;
    CFrameData* frame_data;

    osCreateMesgQueue(&gGfxFrameMessageQueue, gGfxFrameMessageBuffer, 0x1000);
    memset(gSchedulerStack, THREAD_SCHED, OS_SC_STACKSIZE);
    osCreateScheduler(&gScheduler, (SIZE_TYPE)gSchedulerStack + OS_SC_STACKSIZE, gThreadPriorityScheduler, 0, 1);
    osScAddClient(&gScheduler, &gGfxClient, &gGfxFrameMessageQueue);

    thisx->lastMode = 0;

    CEngineApp__InitFade(thisx);

    gDList = NULLPTR;

    func_2E4A60(&D_80166190);
    if (gFirstBoot != 0) {
        func_2526B0(); // context implies CCrash__Construct, but the function is empty
        COptions__SetDefaults(GetOptions());
    }

    Cinema__Initialize();
    CEngineApp__SetupShadowVtxs();
    CSun__Construct(&thisx->sun);
    thisx->unk_0x28840 = -1;
    thisx->unk_0x28830 = 0;
    thisx->unk_0x28804 = 1;
    thisx->unk_0x28808 = 0;
    thisx->unk_0x2880C = 0;
    thisx->unk_0x28810 = 0;
    thisx->unk_0x28834 = 0;
    thisx->unk_0x28844 = 0;
    thisx->unk_0x28848 = 0;
    thisx->unk_0x2884C = 0;
    thisx->unk_0x2883C = 0;
    thisx->unk_0x28850 = 0;
    thisx->unk_0x2882C = D_800FB0BC;

    // these are part of some struct but get shorthanded at D_80124ECD
    // this current method results in nonmatching code
    D_80124ECD = 0;
    D_80125224 = (uint32_t)0;

    for (index = 0; index < gTotalFramebuffers; index++) {
        int32_t next = (index + 1 + gTotalFramebuffers) % gTotalFramebuffers;
        int32_t prev = (index - 1 + gTotalFramebuffers) % gTotalFramebuffers;

        frame_data = &thisx->frameData[index];
        frame_data->message.gen.type = OS_SC_DONE_MSG;
        frame_data->frameBuffer = gCFB[index];
        frame_data->prev = &thisx->frameData[prev];
        frame_data->next = &thisx->frameData[next];

        CSunFrameData__Construct(&frame_data->sunFrameData);
    }

    CEngineApp__AdvanceFrameData(thisx);
    Sound__Initialize();
}
#else
INCLUDE_ASM("asm/nonmatchings/tengine", CEngineApp__Construct);
#endif

// OK besides the pseudo-op issue and `if (options->unk_0x10 == 0)` case
#ifdef NON_MATCHING
void CEngineApp__Main(CEngineApp* thisx) {
    COptions* options;
    int32_t index;

    InitializeSystemResources();
    osCreateViManager(OS_PRIORITY_VIMGR);
    osViBlack(1);

    // if not NTSC or PAL, enter infinite loop
    if ((osTvType - 1) >= OS_TV_MPAL) {
        while(1);
    }

    CPool__Construct(&gPoolBuffers);
    CPool__AllocateStandardBuffers(&gPoolBuffers);
    osViSwapBuffer(gCFB[0]);
    osViBlack(0);

    if (osTvType == OS_TV_PAL) {
        gRefreshRate = gRefreshRatePAL;
    }
    else {
        gRefreshRate = gRefreshRateNTSC;
    }

    gGfxMsg = NULL;
    gDisplayListCount = MAX_DISPLAY_LISTS;
    gCurrentTick = 0;
    gNumTicks0 = 0;
    gNumTicks1 = 0;
    gNumTicks2 = 0;
    gNumTicks3 = 0;
    gNumTicksPending = 0;
    gCurrentTickWaiting = 0;
    gNumTicksWaiting = 0;
    gCurrentTickFinished = 0;
    gCurrentFB = 0;
    gPendingFB = 0;

    CEngineApp__Construct(thisx);
    SCSI_SetMessageFunc(func_287068);
    // TODO: D_801282F0 is &gSysRCLoader->Queue
    osSendMesg(&D_801282F0, (void*)0xBEEFDEAD, 0);

    for (index = 0; index < gTotalFramebuffers; index++) {
        memset(gCFB[index], 0, gScreenWidth * gScreenHeight * 2);
    }

    CCameraPool__Construct(&thisx->cameraPool);
    CPlayerPool__Construct(&thisx->playerPool);
    CCollisionInfo__Reset();

    thisx->staticSegment = (void*)(CCache_GetFromLookupTable(0x18) & ~0xC0000000);

    CCameraPool__NewGame(&thisx->cameraPool, 0);
    CPlayerPool__NewGame(&thisx->playerPool, 0);

    CScene__Construct(GetScene(), thisx->staticSegment);
    func_26AEE0(&thisx->unk_0x28854);

    if (gValidControllerBits == 0) {
        InitControllers();
    }

    COnScreen__Construct(thisx->unk_0x1D7E0);

    PAK_InitSystem();
    func_41FBF8();
    func_2523A4();
    func_285FC4(thisx, 2);

    // &gEngineApp.options gets loaded into S1 here?
    options = GetOptions();

    while (1) {
        osRecvMesg(&gGfxFrameMessageQueue, (OSMesg*)&gGfxMsg, OS_MESG_BLOCK);

        switch (gGfxMsg->gen.type) {
            case (OS_SC_RETRACE_MSG): {
                CEngineApp__Retrace(thisx);
                break;
            }
            case (OS_SC_DONE_MSG): {
                if (gGfxMsg == &thisx->frameData[0].message) {
                    gFrameData = &thisx->frameData[0];
                }
                else if (gGfxMsg == &thisx->frameData[1].message) {
                    gFrameData = &thisx->frameData[1];
                }
                else if (gGfxMsg == &thisx->frameData[2].message) {
                    gFrameData = &thisx->frameData[2];
                }
                else {
                    ((void)0);
                }

                // no idea, D_80136EE4 loaded from offsets of gFrameData address
                if (options->unk_0x10 == 0) {
                    // not right, not sure what D_80136EE4 is actually being loaded into
                    // so this is technically the closest fakematch I could find (it is still nonmatching)
                    options = D_80136EE4; // huh?
                }

                if (thisx->currentMode == 3) {
                    gDisplayListCount++;
                }
                else {
                    CEngineApp__Update(thisx);
                }
                break;
            }
            case (OS_SC_PRE_NMI_MSG): {
                gBootSignature[0] = '\0';

                // Stop rumbles ?
                func_252414(gGfxMsg);
                func_25245C(0);

                thisx->unk_0x28824 = 1; // m_FadeFast ?
                func_286058(thisx, 3); // CEngineApp__SetupFadeTo ?
                thisx->unk_0x28830 = 1; // m_bReset ?
                break;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/tengine", CEngineApp__Main);
#endif

INCLUDE_ASM("asm/nonmatchings/tengine", func_284868);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2849BC);

INCLUDE_ASM("asm/nonmatchings/tengine", func_284B80);

INCLUDE_ASM("asm/nonmatchings/tengine", func_284D7C);

INCLUDE_ASM("asm/nonmatchings/tengine", func_285024);

INCLUDE_ASM("asm/nonmatchings/tengine", CEngineApp__Draw);

// Close, needs work, most differents possibly from pseudo-ops (gotta investigate the cop1 stuff)
#ifdef NON_MATCHING
void CEngineApp__Update(CEngineApp* thisx) {
    // need to dedupe these (they are not real)
    float phi_f0;
    float phi_f0_2;
    float phi_f0_3;

    OSTime now = osGetTime();
    OSTime delta = now - gLastEngineUpdate;
    float microseconds = OS_CYCLES_TO_USEC(delta);
    float seconds = microseconds / 1000000.0f;
    float good_frame_increment;

    gLastEngineUpdate = now;
    good_frame_increment = seconds * FRAME_FPS;

    if (func_285EFC() == 0) {
        D_80124ECD = 0;
    }

    gNextTicks = CALC_FRAMERATE(2); // 30 fps
    if (Cinema_PathPlaying()) {
        gNextTicks = CALC_FRAMERATE(4); // 15 fps
    }

    gFrameIncrement = (gNextTicks * FRAME_FPS) / gRefreshRate;
    if (Cinema_PathPlaying()) {
        gFrameIncrement = good_frame_increment;
    }

    CCache__Advance();

    // TODO: expansion of CEngineApp__IncreaseGameTime
    gFrameData = gEngineApp.currentFrameData;
    if (thisx->unk_0x2880C > 0.0f) {
        thisx->unk_0x2880C = thisx->unk_0x2880C - gFrameIncrement;
        phi_f0 = thisx->unk_0x2880C - gFrameIncrement;
        if (!(thisx->unk_0x2880C - gFrameIncrement >= 0.0f)) {
            phi_f0 = 0.0f;
        }
        thisx->unk_0x2880C = phi_f0;
    }

    if (thisx->unk_0x28808 > 0.0f) {
        thisx->unk_0x28808 = thisx->unk_0x28808 - gFrameIncrement;
        phi_f0_2 = thisx->unk_0x28808 - gFrameIncrement;
        if (!(thisx->unk_0x28808 - gFrameIncrement >= 0.0f)) {
            phi_f0_2 = 0.0f;
        }
        thisx->unk_0x28808 = phi_f0_2;
    }

    if (thisx->unk_0x28810 > 0.0f) {
        thisx->unk_0x28810 = thisx->unk_0x28810 - gFrameIncrement;
        phi_f0_3 = thisx->unk_0x28810 - gFrameIncrement;
        if (!(thisx->unk_0x28810 - gFrameIncrement >= 0.0f)) {
            phi_f0_3 = 0.0f;
        }
        thisx->unk_0x28810 = phi_f0_3;
    }

    CEngineApp__Draw(thisx);
    thisx->modeTime += gFrameIncrement;
}
#else
INCLUDE_ASM("asm/nonmatchings/tengine", CEngineApp__Update);
#endif

void boot(void) {
    CEngineApp__Boot(GetApp());
}

void CEngineApp__Boot(CEngineApp* thisx) {
    memset(gThreadStackIdle, THREAD_IDLE, STACKSIZE_IDLE);
    osCreateThread(&gThreadIdle, THREAD_IDLE, idle, 0, gThreadStackIdle + STACKSIZE_IDLE, gThreadPriorityIdleInit);
    osStartThread(&gThreadIdle);
}

void CEngineApp__Idle(CEngineApp* thisx, void* arg) {
    memset(gThreadStackMain, THREAD_MAIN, STACKSIZE_MAIN);

    osCreateThread(&gThreadMain, THREAD_MAIN, mainproc, arg, gThreadStackMain + STACKSIZE_MAIN, gThreadPriorityMain);
    osStartThread(&gThreadMain);

    osSetThreadPri(NULL, gThreadPriorityIdle);

    while (1) {}
}

void CEngineApp__AdvanceFrameData(CEngineApp* thisx) {
    gFrameCount++;
    gFrameCountGameplay++;
    gEvenOdd ^= 1;

    thisx->currentFrameData = &thisx->frameData[gFrameCount % gTotalFramebuffers];
    thisx->currentFrameData->displayListHead = gEvenOdd ? gDisplayList0 : gDisplayList1;
    thisx->currentFrameData->lineListHead = gEvenOdd ? gLineList0 : gLineList1;
}

INCLUDE_ASM("asm/nonmatchings/tengine", func_285DA8);

INCLUDE_ASM("asm/nonmatchings/tengine", func_285DC4);

INCLUDE_ASM("asm/nonmatchings/tengine", func_285E00);

INCLUDE_ASM("asm/nonmatchings/tengine", func_285E50);

INCLUDE_ASM("asm/nonmatchings/tengine", func_285EFC);

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

void CEngineApp__InitFade(CEngineApp* thisx) {
    thisx->unk_0x28825 = 1;
    thisx->fadeAlpha = 0;
    thisx->unk_0x28824 = 0;
}

INCLUDE_ASM("asm/nonmatchings/tengine", func_285FC4);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286058);

INCLUDE_ASM("asm/nonmatchings/tengine", func_28607C);

void CEngineApp__Retrace(CEngineApp* thisx) {
    if (gFirstFrame) {
        gFirstFrame = 0;
    }

    func_2526E0();

    if (gEngineModeTable[thisx->currentMode].retraceFunction != NULLPTR) {
        gEngineModeTable[thisx->currentMode].retraceFunction(thisx);
    }

    if (thisx->currentMode != 3) {
        if (gDisplayListCount) {
            gDisplayListCount--;
            CEngineApp__Update(thisx);
        }
    }

    gRetraceCount++;
}

INCLUDE_ASM("asm/nonmatchings/tengine", func_2862C8);

INCLUDE_ASM("asm/nonmatchings/tengine", func_28635C);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286438);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286520);

INCLUDE_ASM("asm/nonmatchings/tengine", func_28653C);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286574);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2865C4);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286610);

void func_286798(void) {
}

INCLUDE_ASM("asm/nonmatchings/tengine", func_2867A0);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286808);

void func_2868BC(void) {
}

INCLUDE_ASM("asm/nonmatchings/tengine", func_2868C4);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2868FC);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286930);

INCLUDE_ASM("asm/nonmatchings/tengine", func_286B90);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287068);

INCLUDE_ASM("asm/nonmatchings/tengine", func_28714C);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287218);

INCLUDE_ASM("asm/nonmatchings/tengine", CTexModSet__IsActive); // this is in texmod.c, file split above here somewhere

INCLUDE_ASM("asm/nonmatchings/tengine", func_287258);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287318);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2873D8);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287458);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2874FC);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287518);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287564);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2875B0);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2875FC);

INCLUDE_ASM("asm/nonmatchings/tengine", func_2876A0);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287720);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287730);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287740);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287758);

INCLUDE_ASM("asm/nonmatchings/tengine", func_287770);
