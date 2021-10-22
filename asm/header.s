.section .data

.word 0x80371240       /* PI BSB Domain 1 register */
.word 0x0000000F       /* Clockrate setting */
.word 0x80000400       /* Entrypoint address */
.word 0x00001444       /* Revision */
.word 0x89A579F1       /* Checksum 1 */
.word 0x667E97EF       /* Checksum 2 */
.word 0x00000000       /* Unknown 1 */
.word 0x00000000       /* Unknown 2 */
.ascii "Turok 3: Shadow of O" /* Internal name */
.word 0x00000000       /* Unknown 3 */
.word 0x0000004E       /* Cartridge */
.ascii "TK"            /* Cartridge ID */
.ascii "E"             /* Country code */
.byte 0x00             /* Version */
