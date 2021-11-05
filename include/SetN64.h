#ifndef SETN64_H
#define SETN64_H

// Indexed set
typedef struct {
    /* 0x00 */ int m_BlockCount;
    /* 0x04 */ int m_Offset;
} CISet; /* sizeof = 0x8 */

// Unindexed Set
typedef struct {
    /* 0x00 */ int m_BlockSize;
    /* 0x04 */ int m_BlockCount;
    /* 0x08 */ int m_Data;
} CUSet; /* sizeof = 0xC */

#endif

