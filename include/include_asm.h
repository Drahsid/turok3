#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME, ...) \
__asm__( \
    ".set fp=64\n"\
    ".section .text\n" \
    "\t.align\t2\n" \
    "\t.globl\t"#NAME"\n" \
    "\t.ent\t"#NAME"\n" \
    #NAME ":\n" \
    "\t.include \""FOLDER#NAME".s\"\n" \
    "\t.set reorder\n" \
    "\t.set at\n" \
    "\t.end\t"#NAME \
);
#endif
#ifndef ORIGINAL_AS_TESTS
__asm__(".include \"include/macro.inc\"\n");
#endif
// don't include this if we want to use modern as pseudo-ops
#if !defined(ALLOW_SHIFTY_PSEUDOOPS)
__asm__(".include \"include/pseudoops.inc\"\n");
#endif
#else
#define INCLUDE_ASM(FOLDER, NAME, ...)
#endif

#endif
