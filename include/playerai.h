#ifndef PLAYERAI_H
#define PLAYERAI_H

#include "inttypes.h"
#include "list.h"

typedef struct {
    /* 0x00 */ uint32_t unk_0x00;
    /* 0x04 */ void* m_pPlayers[4];
    /* 0x14 */ int32_t m_nPlayers;
    /* 0x18 */ CList m_FreeList;
    /* 0x2C */ CList m_ActiveList;
    /* 0x40 */ uint32_t m_nNumActive;
} CPlayerPool; /* sizeof = 0x44 */

#endif

