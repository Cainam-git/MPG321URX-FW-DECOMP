! irq_entry_part10  (FUN_a0060420)
!
! Load the level's service routine and save %g2..%g5.
! Note: Ghidra piece 10 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060420 @ 0xa0060420  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060420
	.type FUN_a0060420, #function
FUN_a0060420:
! Part 10 of irq_entry (0xA00603AC..0xA006048B). The global registers and Y now go to the save area;
! the TBR, PC and nPC words there are no longer needed.
	or  %l1, 0x40, %l1                ! %l1 = vector table 0xA8076040 (service routines of levels 1..15)
	ld  [ %l1 + %l3 ], %l7            ! %l7 = the service routine of this level
	std  %g2, [%l4 + 0]               ! words 0, 1 = %g2, %g3
	std  %g4, [ %l4 + 8 ]             ! words 2, 3 = %g4, %g5
	.size FUN_a0060420, .-FUN_a0060420
