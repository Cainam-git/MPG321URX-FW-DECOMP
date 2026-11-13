! irq_service_level1_part2  (FUN_a0060900)
!
! Mask interrupt 1 (bit 0x2) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060900 @ 0xa0060900  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060900
	.type FUN_a0060900, #function
FUN_a0060900:
! Piece 2 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	or  %o5, 0x90, %o5                ! %o5 = the LEON2 interrupt mask register
	ld  [ %o5 ], %g1                  ! read the interrupt mask
	and  %g1, -3, %g1                 ! clear bit 0x2: level 1 masked while it is served
	st  %g1, [ %o5 ]                  ! write the interrupt mask back
	.size FUN_a0060900, .-FUN_a0060900
