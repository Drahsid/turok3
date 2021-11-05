#ifndef COMMON_H
#define COMMON_H

#include "include_asm.h"
#include "inttypes.h"
#include "common_structs.h"
#include "unknown_structs.h"
#include "function_symbols.h"
#include "data_symbols.h"
#include <ultra64.h>

//  threads

enum {
    THREAD_IDLE,
    THREAD_MAIN,
    THREAD_FAULT,
    THREAD_DECOMPRESSOR,
    THREAD_LOADER,
    THREAD_CACHE,
    THREAD_DEFRAGGER,
    THREAD_SCHED,
    THREAD_AUDIO
};

extern OSThread gThreadIdle;
extern OSThread gThreadMain;

// stacks
#define	STACKSIZE_IDLE  (0x0080)
#define	STACKSIZE_BASE  (0x1000)
#define	STACKSIZE_MAIN  (0x8000)
#define	STACKSIZE_AUDIO (0x4000)

extern uint8_t gThreadStackSched[];
extern uint8_t gThreadStackIdle[];
extern uint8_t gThreadStackMain[];
extern uint8_t gThreadStackBoot[];
extern uint8_t gThreadStackAudio[];

#endif

