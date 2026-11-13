! irq_service_level7_part6  (FUN_a0060e10)
!
! Unmask interrupt 7 in the LEON2 interrupt mask and return.
! Note: Ghidra piece 6 of the routine 0xA0060DC0..0xA0060E1B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 6 = 0xA0060DC0; bit 0x80 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e10 @ 0xa0060e10  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e10
	.type FUN_a0060e10, #function
FUN_a0060e10:
! Piece 6 of the level-7 service routine (0xA0060DC0..0xA0060E1B); see irq_service_level7_part1.S.
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	retl                              ! return to irq_entry (leaf routine: no register window)
	nop                               ! delay slot: nothing
	.size FUN_a0060e10, .-FUN_a0060e10
