! irq_entry_part5  (FUN_a00603e0)
!
! Store nPC and step back to the interrupted window.
! Note: Ghidra piece 5 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603e0 @ 0xa00603e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603e0
	.type FUN_a00603e0, #function
FUN_a00603e0:
! Part 5 of irq_entry (0xA00603AC..0xA006048B).
	st  %l6, [ %l4 + 8 ]              ! word 2 = interrupted nPC
	restore                           ! step back to the interrupted window
	.size FUN_a00603e0, .-FUN_a00603e0
