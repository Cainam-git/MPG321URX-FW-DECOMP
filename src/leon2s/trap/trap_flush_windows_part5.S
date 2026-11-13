! trap_flush_windows_part5  (FUN_a0060620)
!
! Walk back to the starting window (RESTORE x4).
! Note: Ghidra piece 5 of the routine 0xA00605E8..0xA0060647, not callable on its own.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a0060620 @ 0xa0060620  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060620
	.type FUN_a0060620, #function
FUN_a0060620:
! Part 5 of trap_flush_windows (0xA00605E8..0xA0060647).
	restore                           ! RESTORE number 2
	restore                           ! RESTORE number 3
	restore                           ! RESTORE number 4
	restore                           ! RESTORE number 5
	.size FUN_a0060620, .-FUN_a0060620
