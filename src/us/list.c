#include "include_asm.h"
#include "list.h"

void CList__Construct(CList* thisx, uint32_t lastOffset, uint32_t nextOffset) {
    thisx->lastOffset = lastOffset;
    thisx->nextOffset = nextOffset;
    thisx->head = thisx->tail = NULL;
    thisx->size = 0;
}

void CList__AddHead(CList* thisx, void* entry) {
    if (thisx->head != 0) {
        CList__GetNext(thisx, entry) = thisx->head;
        CList__GetLast(thisx, thisx->head) = entry;
    }
    else {
        CList__GetNext(thisx, entry) = NULLPTR;
        thisx->tail = entry;
    }

    CList__GetLast(thisx, entry) = NULLPTR;
    thisx->head = entry;
    thisx->size++;
}

void CList__AddTail(CList* thisx, void* entry) {
    if (thisx->tail != 0) {
        CList__GetLast(thisx, entry) = thisx->tail;
        CList__GetNext(thisx, thisx->tail) = entry;
    }
    else {
        CList__GetLast(thisx, entry) = NULLPTR;
        thisx->head = entry;
    }

    CList__GetNext(thisx, entry) = NULLPTR;
    thisx->tail = entry;
    thisx->size += 1;
}


INCLUDE_ASM("asm/nonmatchings/list", func_242F10);

INCLUDE_ASM("asm/nonmatchings/list", func_242FC4);

void CList__Remove(CList* thisx, void* entry) {
    if (CList__GetLast(thisx, entry)) {
        CList__GetNext(thisx, CList__GetLast(thisx, entry)) = CList__GetNext(thisx, entry);
    }

    if (CList__GetNext(thisx, entry)) {
        CList__GetLast(thisx, CList__GetNext(thisx, entry)) = CList__GetLast(thisx, entry);
    }

    if (thisx->head == entry) {
        thisx->head = CList__GetNext(thisx, entry);
    }

    if (thisx->tail == entry) {
        thisx->tail = CList__GetLast(thisx, entry);
    }

    thisx->size--;
}

INCLUDE_ASM("asm/nonmatchings/list", func_243110);

INCLUDE_ASM("asm/nonmatchings/list", func_243134);

INCLUDE_ASM("asm/nonmatchings/list", func_243158);

INCLUDE_ASM("asm/nonmatchings/list", func_243244);

INCLUDE_ASM("asm/nonmatchings/list", func_243330);

INCLUDE_ASM("asm/nonmatchings/list", func_2433B4);

INCLUDE_ASM("asm/nonmatchings/list", func_2433DC);
