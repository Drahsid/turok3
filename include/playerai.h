#ifndef PLAYERAI_H
#define PLAYERAI_H

#include "inttypes.h"
#include "list.h"

typedef struct {
    /* 0x00 */ uint32_t unk_0x00;
    /* 0x04 */ struct CPlayer* players[4]; // "m_Players" TODO: declare CPlayer struct
    /* 0x14 */ int32_t playerCount; // "m_nPlayers"
    /* 0x18 */ CList freeList; // "m_FreeList"
    /* 0x2C */ CList activeList; // "m_ActiveList"
    /* 0x40 */ uint32_t activeCount;
} CPlayerPool; /* sizeof = 0x44 */

#endif

