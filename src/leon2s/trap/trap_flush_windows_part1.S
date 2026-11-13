! trap_flush_windows_part1  (FUN_a00605e8)
!
! Read PSR and build a copy with the interrupt level raised to 15.
! Note: Ghidra piece 1 of the routine 0xA00605E8..0xA0060647, not callable on its own; unreached: no trap-
!   table slot, call or stored word points at it.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a00605e8 @ 0xa00605e8  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605e8
	.type FUN_a00605e8, #function
FUN_a00605e8:
! Unreached: no trap-table slot, call or stored word points at 0xA00605E8. The same instructions as
! the 'ta 3' handler of the main processor (trap_handle_faults at 0xA0029328): with interrupts masked
! and traps on, six SAVEs step forward through the register windows (a SAVE into the window marked
! invalid raises a window-overflow trap, which writes the oldest window to its stack) and five RESTOREs
! step back. It uses %g1 and %g2 without keeping them.
	rd  %psr, %g1                     ! %g1 = PSR as at the trap (traps off, the trap window)
	or  %g1, 0xf00, %g2               ! %g2 = the same with interrupt level 15
	.size FUN_a00605e8, .-FUN_a00605e8
