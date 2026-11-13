! irq_service_level9_part6  (FUN_a0060ec0)
!
! Unmask interrupt 9 in the LEON2 interrupt mask and return.
! Note: Ghidra piece 6 of the routine 0xA0060E78..0xA0060ED3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 8 = 0xA0060E78; bit 0x200 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060ec0 @ 0xa0060ec0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ec0
	.type FUN_a0060ec0, #function
FUN_a0060ec0:
! Piece 6 of the level-9 service routine (0xA0060E78..0xA0060ED3); see irq_service_level9_part1.S.
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	or  %g1, 0x200, %g1               ! set bit 0x200: level 9 allowed again
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	retl                              ! return to irq_entry (leaf routine: no register window)
	.size FUN_a0060ec0, .-FUN_a0060ec0
