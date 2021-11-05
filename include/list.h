#ifndef LIST_H
#define LIST_H

#include "inttypes.h"

typedef struct {
    void* m_pHead;
    void* m_pTail;
    uint32_t m_LastOffset;
    uint32_t m_NextOffset;
    uint32_t m_Size;
} CList;

#endif

