! irq_entry_part13  (FUN_a0060450)
!
! Restore %g2..%g7 and %g1 after the service routine.
! Note: Ghidra piece 13 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060450 @ 0xa0060450  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060450
	.type FUN_a0060450, #function
FUN_a0060450:
! Part 13 of irq_entry (0xA00603AC..0xA006048B).
	ldd  [%l4 + 0], %g2               ! %g2, %g3 back
	ldd  [ %l4 + 8 ], %g4             ! %g4, %g5 back
	ldd  [ %l4 + 0x10 ], %g6          ! %g6, %g7 back
	ld  [ %l4 + 0x18 ], %g1           ! %g1 back
	.size FUN_a0060450, .-FUN_a0060450
