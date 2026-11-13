! irq_service_level10_part4  (FUN_a0060f00)
!
! Read the interrupt-10 source status and its source mask.
! Note: Ghidra piece 4 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f00 @ 0xa0060f00  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f00
	.type FUN_a0060f00, #function
FUN_a0060f00:
! Piece 4 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	or  %o4, 0x94, %g1                ! %g1 = the source status register of level 10 (0x9F120094)
	ld  [ %g1 ], %l1                  ! %l1 = the sources of level 10 that are signalling
	or  %o4, 0x5c, %o4                ! %o4 = the source mask register of level 10 (0x9F12005C)
	ld  [ %o4 ], %g1                  ! %g1 = source mask (a set bit in the low half masks a source)
	.size FUN_a0060f00, .-FUN_a0060f00
