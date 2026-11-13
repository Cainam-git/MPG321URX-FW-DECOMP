! trap_force_error_mode_part2  (FUN_a0060650)
!
! Return from the trap past the trapping instruction (reached only if the load does not trap).
! Note: Ghidra piece 2 of the routine 0xA0060648..0xA0060657, not callable on its own.
! Name basis: descriptive - ld [1] inside a trap handler (ET=0) puts a SPARC V8 core in error mode; no
!   reference to 0xA0060648
!
! Matching notes
! --------------
! leon2s FUN_a0060650 @ 0xa0060650  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060650
	.type FUN_a0060650, #function
FUN_a0060650:
! Part 2 of trap_force_error_mode (0xA0060648..0xA0060657).
	rett  %l2 + 4                     ! delay slot, never reached: return from the trap
	nop                               ! padding; never reached
	.size FUN_a0060650, .-FUN_a0060650
