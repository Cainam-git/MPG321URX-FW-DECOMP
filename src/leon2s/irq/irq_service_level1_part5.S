! irq_service_level1_part5  (FUN_a0060930)
!
! Drop masked sources and take the acknowledge-after-call flags from the mask's upper half.
! Note: Ghidra piece 5 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060930 @ 0xa0060930  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060930
	.type FUN_a0060930, #function
FUN_a0060930:
! Piece 5 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	ld  [ %o4 ], %g1                  ! %g1 = source mask (a set bit in the low half masks a source)
	ld  [ %o4 ], %o5                  ! read it again, for its upper half
	andn  %l1, %g1, %l1               ! drop the masked sources
	srl  %o5, 0x10, %l3               ! %l3 = upper half: sources to run before the acknowledge
	.size FUN_a0060930, .-FUN_a0060930
