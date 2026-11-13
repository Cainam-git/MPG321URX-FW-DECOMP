! irq_service_level5_part16  (FUN_a0060ca0)
!
! Finish 0x9F120028 and start unmasking interrupt 5 in the LEON2 interrupt mask.
! Note: Ghidra piece 16 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060ca0 @ 0xa0060ca0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ca0
	.type FUN_a0060ca0, #function
FUN_a0060ca0:
! Piece 16 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x90, %o4                ! %o4 = the LEON2 interrupt mask register
	ld  [ %o4 ], %g1                  ! read the interrupt mask
	or  %g1, 0x20, %g1                ! set bit 0x20: level 5 allowed again
	.size FUN_a0060ca0, .-FUN_a0060ca0
