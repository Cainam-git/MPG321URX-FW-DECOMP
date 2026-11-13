! trap_call_halt_handler_part3  (FUN_a0060330)
!
! Enable traps with all interrupts still masked.
! Note: Ghidra piece 3 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060330 @ 0xa0060330  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060330
	.type FUN_a0060330, #function
FUN_a0060330:
! Part 3 of trap_call_halt_handler (0xA0060314..0xA00603AB).
	wr  %l0, 0x20, %psr               ! write PSR with ET flipped on: traps on, interrupts still masked
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	nop
	.size FUN_a0060330, .-FUN_a0060330
