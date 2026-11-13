! irq_entry_part11  (FUN_a0060430)
!
! Save %g6, %g7, %g1 and the Y register.
! Note: Ghidra piece 11 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060430 @ 0xa0060430  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060430
	.type FUN_a0060430, #function
FUN_a0060430:
! Part 11 of irq_entry (0xA00603AC..0xA006048B).
	std  %g6, [ %l4 + 0x10 ]          ! words 4, 5 = %g6, %g7
	st  %g1, [ %l4 + 0x18 ]           ! word 6 = %g1
	rd  %y, %l3                       ! %l3 = Y register
	st  %l3, [ %l4 + 0x1c ]           ! word 7 = Y
	.size FUN_a0060430, .-FUN_a0060430
