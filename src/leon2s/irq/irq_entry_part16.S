! irq_entry_part16  (FUN_a0060480)
!
! Return from the trap to the saved PC/nPC.
! Note: Ghidra piece 16 of the routine 0xA00603AC..0xA006048B, not callable on its own. The same three
!   instructions as trap_call_halt_handler_part10.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060480 @ 0xa0060480  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060480
	.type FUN_a0060480, #function
FUN_a0060480:
! Part 16 of irq_entry (0xA00603AC..0xA006048B); the same three instructions as trap_call_halt_handler_part10.
	nop                               ! third wait instruction
	jmp  %l5                          ! jump back to the interrupted instruction
	rett  %l6                         ! delay slot: return from the trap (traps on again), next at the nPC
	.size FUN_a0060480, .-FUN_a0060480
