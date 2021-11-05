#ifndef SYSRC_H
#define SYSRC_H

#include "heap.h"
#include "loader.h"
#include "decompressor.h"

extern CHeap gHeap;
extern CLoader gLoader;
extern CDecompressor gDecompressor;

#define GetHeap() (&gHeap)
#define GetLoader() (&gLoader)
#define GetDecompressor() (&gDecompressor)

extern void InitializeSystemResources(void);

#endif

