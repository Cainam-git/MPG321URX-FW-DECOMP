! irq_entry_part3  (FUN_a00603c0)
!
! Enable traps with all interrupts still masked.
! Note: Ghidra piece 3 of the routine 0xA00603AC..0xA006048B, not callable on its own. The same four
!   instructions as trap_call_halt_handler_part3.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603c0 @ 0xa00603c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603c0
	.type FUN_a00603c0, #function
FUN_a00603c0:
! Part 3 of irq_entry (0xA00603AC..0xA006048B); the same four instructions as trap_call_halt_handler_part3.
	wr  %l0, 0x20, %psr               ! write PSR with ET flipped on: traps on, interrupts still masked
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	nop
	.size FUN_a00603c0, .-FUN_a00603c0
