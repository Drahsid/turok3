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

extern OSThread gThreadIdle; // "idleThread"
extern OSThread gThreadMain; // "mainThread"

// stacks
#define STACKSIZE_IDLE          (0x0080)
#define STACKSIZE_BASE          (0x1000)
#define STACKSIZE_MAIN          (0x8000)
#define STACKSIZE_AUDIO         (0x4000)
#define STACKSIZE_CACHE         (0x0800)
#define STACKSIZE_DECOMPRESSOR  (0x1000)

#define ABS(X)      (((X) < 0) ? (-(X)) : (X))
#define MAX(A, B)   ((A) > (B) ? (A) : (B))
#define MIN(A, B)   ((A) < (B) ? (A) : (B))

extern uint8_t gSchedulerStack[]; // "schedule_stack"
extern uint8_t gThreadStackIdle[]; // "idle_thread_stack"
extern uint8_t gThreadStackMain[]; // "main_thread_stack"
extern uint8_t gThreadStackBoot[]; // "boot_stack"
extern uint8_t gThreadStackAudio[]; // "audio_stack"

#endif

