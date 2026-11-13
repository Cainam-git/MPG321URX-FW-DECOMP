! irq_service_level4_part16  (FUN_a0060ba0)
!
! Unmask interrupt 4 in the LEON2 interrupt mask.
! Note: Ghidra piece 16 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060ba0 @ 0xa0060ba0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ba0
	.type FUN_a0060ba0, #function
FUN_a0060ba0:
! Piece 16 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	or  %o4, 0x90, %o4                ! %o4 = the LEON2 interrupt mask register
	ld  [ %o4 ], %g1                  ! read the interrupt mask
	or  %g1, 0x10, %g1                ! set bit 0x10: level 4 allowed again
	st  %g1, [ %o4 ]                  ! write the interrupt mask back
	.size FUN_a0060ba0, .-FUN_a0060ba0
