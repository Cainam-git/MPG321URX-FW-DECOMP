! trap_flush_windows_part3  (FUN_a0060600)
!
! Start walking forward through the register windows (SAVE x3).
! Note: Ghidra piece 3 of the routine 0xA00605E8..0xA0060647, not callable on its own.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a0060600 @ 0xa0060600  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060600
	.type FUN_a0060600, #function
FUN_a0060600:
! Part 3 of trap_flush_windows (0xA00605E8..0xA0060647).
	nop                               ! third wait instruction
	save                              ! one window forward (overflow trap at the invalid window)
	save
	save
	.size FUN_a0060600, .-FUN_a0060600
