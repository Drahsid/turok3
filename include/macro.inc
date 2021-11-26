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

# sltu is aparently a pseudo-op for sltiu, original as expanded it as slti; can't fix it without it being a recursive macro

# for (sign-extended) sb, sh, sw we either need to use original as,
# or non-recursively preprocess their pseudo-ops to take account for sign extension
# in the same way that original as does; may be able to do it with regex
