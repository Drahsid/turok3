#ifndef SETN64_H
#define SETN64_H

// Indexed set
typedef struct {
    /* 0x00 */ int32_t blockCount; // "m_BlockCount"
    /* 0x04 */ int32_t offset; // "m_Offsets"
} CISet; /* sizeof = 0x08 */

// Unindexed Set
typedef struct {
    /* 0x00 */ int32_t blockSize; // "m_BlockSize"
    /* 0x04 */ int32_t blockCount; // "m_BlockCount"
    /* 0x08 */ int32_t data; // "m_Array[1]"
} CUSet; /* sizeof = 0x0C */

#endif

