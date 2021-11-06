#ifndef SYSRC_H
#define SYSRC_H

#include "heap.h"
#include "loader.h"
#include "decompressor.h"

extern CHeap gHeap; // "sysrc_heap"
extern CLoader gLoader; // "sysrc_loader"
extern CDecompressor gDecompressor; // "sysrc_decompressor"

#define GetHeap() (&gHeap)
#define GetLoader() (&gLoader)
#define GetDecompressor() (&gDecompressor)

extern void InitializeSystemResources(void);

#endif

