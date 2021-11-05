#ifndef DEFS_H
#define DEFS_H

#include "inttypes.h"

#define OFFSETOF(STRUCT, MEMBER) ((int32_t)&(((STRUCT*)0)->MEMBER))

extern int32_t strcmp(const char* str0, const char* str1);
extern char* strcpy(char* dest, const char* src);

#endif
