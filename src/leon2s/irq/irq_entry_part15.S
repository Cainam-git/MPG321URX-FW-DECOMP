! irq_entry_part15  (FUN_a0060470)
!
! Clear the interrupt level in PSR, traps still off.
! Note: Ghidra piece 15 of the routine 0xA00603AC..0xA006048B, not callable on its own. The same four
!   instructions as trap_call_halt_handler_part9.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060470 @ 0xa0060470  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060470
	.type FUN_a0060470, #function
FUN_a0060470:
! Part 15 of irq_entry (0xA00603AC..0xA006048B); the same four instructions as trap_call_halt_handler_part9.
	andn  %l0, 0xf00, %l4             ! the same PSR with interrupt level 0
	wr  %l4, 0x20, %psr               ! write it with ET flipped: traps stay off, interrupt level 0
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	.size FUN_a0060470, .-FUN_a0060470
