! trap_flush_windows_part2  (FUN_a00605f0)
!
! Step to the trapped window and enable traps with interrupts masked.
! Note: Ghidra piece 2 of the routine 0xA00605E8..0xA0060647, not callable on its own.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a00605f0 @ 0xa00605f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605f0
	.type FUN_a00605f0, #function
FUN_a00605f0:
! Part 2 of trap_flush_windows (0xA00605E8..0xA0060647).
	restore                           ! step to the trapped window (the PSR write sets the window back)
	wr  %g2, 0x20, %psr               ! write PSR: %g2 with ET flipped on: traps on, interrupts masked
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	.size FUN_a00605f0, .-FUN_a00605f0
