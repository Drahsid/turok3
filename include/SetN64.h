#ifndef SETN64_H
#define SETN64_H

// Indexed set
typedef struct {
    /* 0x00 */ int32_t m_BlockCount;
    /* 0x04 */ int32_t m_Offset;
} CISet; /* sizeof = 0x8 */

// Unindexed Set
typedef struct {
    /* 0x00 */ int32_t m_BlockSize;
    /* 0x04 */ int32_t m_BlockCount;
    /* 0x08 */ int32_t m_Data;
} CUSet; /* sizeof = 0xC */

#endif

