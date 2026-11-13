! trap_flush_windows_part4  (FUN_a0060610)
!
! Finish the forward walk, forcing overflow spills, and start walking back.
! Note: Ghidra piece 4 of the routine 0xA00605E8..0xA0060647, not callable on its own.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a0060610 @ 0xa0060610  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060610
	.type FUN_a0060610, #function
FUN_a0060610:
! Part 4 of trap_flush_windows (0xA00605E8..0xA0060647).
	save                              ! SAVE number 4
	save                              ! SAVE number 5
	save                              ! SAVE number 6
	restore                           ! one window back: RESTORE number 1
	.size FUN_a0060610, .-FUN_a0060610
