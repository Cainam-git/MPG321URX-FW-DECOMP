! trap_flush_windows_part6  (FUN_a0060630)
!
! Restore the original PSR.
! Note: Ghidra piece 6 of the routine 0xA00605E8..0xA0060647, not callable on its own.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a0060630 @ 0xa0060630  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060630
	.type FUN_a0060630, #function
FUN_a0060630:
! Part 6 of trap_flush_windows (0xA00605E8..0xA0060647).
	mov  %g1, %psr                    ! PSR as at the trap: traps off, old level, the trap window again
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	nop
	.size FUN_a0060630, .-FUN_a0060630
