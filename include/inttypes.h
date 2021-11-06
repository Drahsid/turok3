#ifndef INTTYPES_H
#define INTTYPES_H

typedef signed char int8_t;
typedef signed short int16_t;
typedef int int32_t;
typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
typedef uint32_t SIZE_TYPE;
typedef uint32_t UNK_TYPE;

#define NULL 0
#define NULLPTR 0

// TODO: Remove (should be in libultra)
#define	OS_K0_TO_PHYSICAL(x) (u32)(((char *)(x)-0x80000000))
#define	OS_K1_TO_PHYSICAL(x) (u32)(((char *)(x)-0xa0000000))

#define	OS_PHYSICAL_TO_K0(x) (void *)(((u32)(x)+0x80000000))
#define	OS_PHYSICAL_TO_K1(x) (void *)(((u32)(x)+0xa0000000))

#endif

