! irq_service_level10_part15  (FUN_a0060fb0)
!
! Drop the in-service bit of interrupt 10 and read the LEON2 interrupt mask.
! Note: Ghidra piece 15 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060fb0 @ 0xa0060fb0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060fb0
	.type FUN_a0060fb0, #function
FUN_a0060fb0:
! Piece 15 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	and  %g1, -1025, %g1              ! clear bit 0x400: level 10 no longer being served
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x90, %o4                ! %o4 = the LEON2 interrupt mask register
	ld  [ %o4 ], %g1                  ! read the interrupt mask
	.size FUN_a0060fb0, .-FUN_a0060fb0
