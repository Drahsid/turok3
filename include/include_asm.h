#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
//__asm__(".include \"include/macro.inc\"\n");
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
#else
#define INCLUDE_ASM(FOLDER, NAME, ...)
#endif

#endif
