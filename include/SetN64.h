#ifndef SETN64_H
#define SETN64_H

// Indexed set
typedef struct {
    /* 0x00 */ int32_t blockCount; // "m_BlockCount"
    /* 0x04 */ int32_t offsets[1]; // "m_Offsets", there are blockCount number of these
} CISet; /* sizeof = 0x08 */

// Unindexed Set
typedef struct {
    /* 0x00 */ int32_t blockSize; // "m_BlockSize"
    /* 0x04 */ int32_t blockCount; // "m_BlockCount"
    /* 0x08 */ int32_t data[1]; // "m_Array"
} CUSet; /* sizeof = 0x0C */

extern void* CISet__GetROMAddress(CISet* thisx, void* romAddressBase, int32_t blockIndex);
extern void* CISet__GetROMAddressAndSize(CISet* thisx, void* romAddressBase, int32_t blockIndex, int32_t* length);

#endif

