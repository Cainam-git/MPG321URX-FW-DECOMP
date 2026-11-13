! irq_service_level5_part2  (FUN_a0060bc0)
!
! Mask interrupt 5 (bit 0x20) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060bc0 @ 0xa0060bc0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060bc0
	.type FUN_a0060bc0, #function
FUN_a0060bc0:
! Piece 2 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	or  %o5, 0x90, %o5                ! %o5 = the LEON2 interrupt mask register
	ld  [ %o5 ], %g1                  ! read the interrupt mask
	and  %g1, -33, %g1                ! clear bit 0x20: level 5 masked while it is served
	st  %g1, [ %o5 ]                  ! write the interrupt mask back
	.size FUN_a0060bc0, .-FUN_a0060bc0
