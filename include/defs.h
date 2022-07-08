#ifndef T3_DEFS_H
#define T3_DEFS_H

#include "common.h"

#define OFFSETOF(STRUCT, MEMBER) ((s32)&(((STRUCT*)0)->MEMBER))
#define RANDOM(RANGE) (RandomSwapWord() % (RANGE))

extern SIZE_TYPE GetMemSize(void);
extern s32 strcmp(const char* str0, const char* str1);
extern char* strcpy(char* dest, const char* src);

#endif
