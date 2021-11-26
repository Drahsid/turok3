#ifndef HASH_H
#define HASH_H

#include "inttypes.h"

typedef struct HashEntry {
    /* 0x00 */ uint32_t key; // "Key"
    /* 0x04 */ uint32_t value; // "Value"
    /* 0x08 */ uint32_t index; // "Index"
    /* 0x0C */ struct HashEntry* next; // "Next"
} HashEntry; /* sizeof = 0x10 */

extern uint32_t gHashSize;
extern uint32_t gHashTableSize;
extern uint32_t gHashMask;
extern uint32_t gHashTableMask;
extern HashEntry* gHashTable;

extern void CHashTable__Construct(uint32_t num_entries);

#endif

