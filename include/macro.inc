.macro glabel label
    .global \label
    \label:
.endm

.macro move a, b
    addu \a, \b, $zero
.endm

.macro remu a, b, c
.set noreorder
    divu $zero, \b, \c
    bnez \c, 1f
    nop
    break 7
1:
    mfhi \a
.set reorder
.endm

