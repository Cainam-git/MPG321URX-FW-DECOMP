! irq_service_level1_part16  (FUN_a00609e0)
!
! Finish 0x9F120028 and unmask interrupt 1 in the LEON2 interrupt mask.
! Note: Ghidra piece 16 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00609e0 @ 0xa00609e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609e0
	.type FUN_a00609e0, #function
FUN_a00609e0:
! Piece 16 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x90, %o4                ! %o4 = the LEON2 interrupt mask register
	ld  [ %o4 ], %g1                  ! read the interrupt mask
	or  %g1, 2, %g1                   ! set bit 0x2: level 1 allowed again
	.size FUN_a00609e0, .-FUN_a00609e0
