#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME, ...) \
__asm__( \
    "\r\n" \
    "# versions/"GAME_VERSION"/"FOLDER"/"#NAME".s\r\n" \
    ".section .text\r\n" \
    "\t.set noat\r\n" \
    "\t.set noreorder\r\n" \
    "\t.global\t"#NAME"\r\n" \
    "\t.ent\t"#NAME"\r\n" \
    "\t.include \"versions/"GAME_VERSION"/"FOLDER"/"#NAME".s\"\r\n" \
    "\t.set reorder\r\n" \
    "\t.set at\r\n" \
);
#endif // INCLUDE_ASM
#else
#define INCLUDE_ASM(FOLDER, NAME, ...)
#endif // !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)

#endif // __INCLUDE_ASM_H__
