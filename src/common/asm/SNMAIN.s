.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

# This contains the entrypoint "boot_main", and is titled "SNMAIN" in the source code

glabel boot_main
/* 1000 80000400 3C1D803F */  la         $sp, 0x80400000 - 0x40 # Initialize stack pointer
/* 1004 80000404 37BDFFC0 */
/* 1008 80000408 2404001E */  addiu      $a0, $zero, 0x1e
.Lclrlp:
/* 100C 8000040C 40085000 */  mfc0       $t0, $10       # Preserve EntryHi
/* 1010 80000410 40840000 */  mtc0       $a0, $0        # Set Index
/* 1014 80000414 3C098000 */  lui        $t1, 0x8000    # Set new EntryHi (invalid)
/* 1018 80000418 40895000 */  mtc0       $t1, $10
/* 101C 8000041C 40801000 */  mtc0       $zero, $2  # Clear EntryLo0 and EntryLo1
/* 1020 80000420 40801800 */  mtc0       $zero, $3
/* 1024 80000424 00000000 */  nop
/* 1028 80000428 42000002 */  tlbwi     # Write it
/* 102C 8000042C 00000000 */  nop
/* 1030 80000430 00000000 */  nop
/* 1034 80000434 00000000 */  nop
/* 1038 80000438 00000000 */  nop
/* 103C 8000043C 40885000 */  mtc0       $t0, $10   # Restore EntryHi
/* 1040 80000440 00000000 */  nop
/* 1044 80000444 1480FFF1 */  bnez       $a0, .Lclrlp
/* 1048 80000448 2084FFFF */   addi      $a0, $a0, -1
/* 104C 8000044C 2404001F */  addiu      $a0, $zero, 0x1f
/* 1050 80000450 3C05001F */  li         $a1, 0x001FE000    # Page size 0x001FE000
/* 1054 80000454 34A5E000 */
/* 1058 80000458 3C060020 */  li         $a2, 0x00200000    # Virtual address 0x00200000
/* 105C 8000045C 24070000 */  li         $a3, 0             # Maps to physical address 0x00000000
/* 1060 80000460 3C090010 */  li         $t1, 0x00100000    # And physical address 0x00100000
/* 1064 80000464 AFA90010 */  sw         $t1, 0x10($sp)
/* 1068 80000468 24080007 */  li         $t0, 7             # MAP_VALID | MAP_GLOBAL | MAP_DIRTY
/* 106C 8000046C 0C000122 */  jal        STVM_MapTLB
/* 1070 80000470 AFA80014 */   sw        $t0, 0x14($sp)
/* 1074 80000474 3C040021 */  la         $a0, main
/* 1078 80000478 2484AA50 */
/* 107C 8000047C 0080F809 */  jalr       $a0    # jal to main
/* 1080 80000480 00000000 */   nop
/* 1084 80000484 0001008D */  break      1, 2   # if the program ever exits, break

glabel STVM_MapTLB
/* 1088 80000488 8FB80010 */  lw         $t8, 0x10($sp)
/* 108C 8000048C 20080007 */  addi       $t0, $zero, 7
/* 1090 80000490 8FB90014 */  lw         $t9, 0x14($sp)
/* 1094 80000494 200FFFFF */  addi       $t7, $zero, -1
/* 1098 80000498 0328C824 */  and        $t9, $t9, $t0
/* 109C 8000049C 37390018 */  ori        $t9, $t9, 0x18
/* 10A0 800004A0 40085000 */  mfc0       $t0, $10
/* 10A4 800004A4 40840000 */  mtc0       $a0, $0
/* 10A8 800004A8 40852800 */  mtc0       $a1, $5
/* 10AC 800004AC 40865000 */  mtc0       $a2, $10
/* 10B0 800004B0 10EF0005 */  beq        $a3, $t7, .L800004C8
/* 10B4 800004B4 200E0001 */   addi      $t6, $zero, 1
/* 10B8 800004B8 00076982 */  srl        $t5, $a3, 6
/* 10BC 800004BC 01B96825 */  or         $t5, $t5, $t9
/* 10C0 800004C0 10000002 */  b          .L800004CC
/* 10C4 800004C4 408D1000 */   mtc0      $t5, $2
.L800004C8:
/* 10C8 800004C8 408E1000 */  mtc0       $t6, $2
.L800004CC:
/* 10CC 800004CC 130F0004 */  beq        $t8, $t7, .L800004E0
/* 10D0 800004D0 408E1800 */   mtc0      $t6, $3
/* 10D4 800004D4 00186982 */  srl        $t5, $t8, 6
/* 10D8 800004D8 01B96825 */  or         $t5, $t5, $t9
/* 10DC 800004DC 408D1800 */  mtc0       $t5, $3
.L800004E0:
/* 10E0 800004E0 42000002 */  tlbwi
/* 10E4 800004E4 00000000 */  nop
/* 10E8 800004E8 00000000 */  nop
/* 10EC 800004EC 00000000 */  nop
/* 10F0 800004F0 00000000 */  nop
/* 10F4 800004F4 40885000 */  mtc0       $t0, $10
/* 10F8 800004F8 03E00008 */  jr         $ra
/* 10FC 800004FC 00000000 */   nop
