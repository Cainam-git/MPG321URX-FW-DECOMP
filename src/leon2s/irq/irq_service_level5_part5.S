! irq_service_level5_part5  (FUN_a0060bf0)
!
! Drop masked sources and take the acknowledge-after-call flags from the mask's upper half.
! Note: Ghidra piece 5 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060bf0 @ 0xa0060bf0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060bf0
	.type FUN_a0060bf0, #function
FUN_a0060bf0:
! Piece 5 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	ld  [ %o4 ], %g1                  ! %g1 = source mask (a set bit in the low half masks a source)
	ld  [ %o4 ], %o5                  ! read it again, for its upper half
	andn  %l1, %g1, %l1               ! drop the masked sources
	srl  %o5, 0x10, %l3               ! %l3 = upper half: sources to run before the acknowledge
	.size FUN_a0060bf0, .-FUN_a0060bf0
