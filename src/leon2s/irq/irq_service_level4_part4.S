! irq_service_level4_part4  (FUN_a0060ae0)
!
! Read the interrupt-4 source status and its source mask.
! Note: Ghidra piece 4 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060ae0 @ 0xa0060ae0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ae0
	.type FUN_a0060ae0, #function
FUN_a0060ae0:
! Piece 4 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	or  %o4, 0x7c, %g1                ! %g1 = the source status register of level 4 (0x9F12007C)
	ld  [ %g1 ], %l1                  ! %l1 = the sources of level 4 that are signalling
	or  %o4, 0x44, %o4                ! %o4 = the source mask register of level 4 (0x9F120044)
	ld  [ %o4 ], %g1                  ! %g1 = source mask (a set bit in the low half masks a source)
	.size FUN_a0060ae0, .-FUN_a0060ae0
