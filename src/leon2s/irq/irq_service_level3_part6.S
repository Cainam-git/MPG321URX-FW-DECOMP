! irq_service_level3_part6  (FUN_a0060aa0)
!
! Unmask interrupt 3 in the LEON2 interrupt mask and return.
! Note: Ghidra piece 6 of the routine 0xA0060A58..0xA0060AB3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 2 = 0xA0060A58; bit 0x8 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060aa0 @ 0xa0060aa0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060aa0
	.type FUN_a0060aa0, #function
FUN_a0060aa0:
! Piece 6 of the level-3 service routine (0xA0060A58..0xA0060AB3); see irq_service_level3_part1.S.
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	or  %g1, 8, %g1                   ! set bit 0x8: level 3 allowed again
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	retl                              ! return to irq_entry (leaf routine: no register window)
	.size FUN_a0060aa0, .-FUN_a0060aa0
