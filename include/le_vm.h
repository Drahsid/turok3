#ifndef T3_LE_VM_H
#define T3_LE_VM_H

#include "common.h"

typedef struct s_VM_Page {
    struct s_VM_Page* prev; // "pPrev"
    struct s_VM_Page* next; // "pNext"
    u16 logicalPage; // "LogicalPage"
    u8 physicalPage; // "PhysicalPage"
    u8 tlbEntry; // "TLBEntry"
    u32 age; // "Age"
} t_VM_Page;

#define VM_MEGABYTE(X) (X * 0x100000)

#define VM_PHYS_PAGE_COUNT (24)
#define VM_OS_BASE (VM_MEGABYTE(2))

extern void VM_Initialize(char*, char*);
extern s32 VM_AcquireNextTLB(void);
extern void VM_MapTLBEntry(s16 faultpage, t_VM_Page* pPage, u8 faultthread, u8* pLogicalTrans);
extern void VM_Age(void);
extern void osMapTLBRdb(void);
extern void* VM_Alloc(u32 size, u32 flags, u32 romBase);

extern void VM_MapTLB(u32 tlb, u32 size, void* logical, u32 even, u32 odd, u32 dvg);

#endif

