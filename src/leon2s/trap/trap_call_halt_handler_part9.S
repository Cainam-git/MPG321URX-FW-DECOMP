! trap_call_halt_handler_part9  (FUN_a0060390)
!
! Clear the interrupt level in PSR, traps still off.
! Note: Ghidra piece 9 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060390 @ 0xa0060390  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060390
	.type FUN_a0060390, #function
FUN_a0060390:
! Part 9 of trap_call_halt_handler (0xA0060314..0xA00603AB): not reached, see part 1.
	andn  %l0, 0xf00, %l4             ! the same PSR with interrupt level 0
	wr  %l4, 0x20, %psr               ! write it with ET flipped: traps stay off, interrupt level 0
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	.size FUN_a0060390, .-FUN_a0060390
