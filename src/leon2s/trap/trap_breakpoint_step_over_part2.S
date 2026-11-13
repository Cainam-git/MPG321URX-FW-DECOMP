! trap_breakpoint_step_over_part2  (FUN_a00604f0)
!
! Run the copied instruction from RAM and continue at the trapped nPC (passed in %g1).
! Note: Ghidra piece 2 of the routine 0xA00604E0..0xA00604FB, not callable on its own; clobbers %g1.
! Name basis: proven - jmp %l6 to the RAM copy at 0xA807608C, followed there by 'jmp %g1' (word 0xA8076090)
!
! Matching notes
! --------------
! leon2s FUN_a00604f0 @ 0xa00604f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604f0
	.type FUN_a00604f0, #function
FUN_a00604f0:
! Part 2 of trap_breakpoint_step_over (0xA00604E0..0xA00604FB).
	mov  %l2, %g1                     ! %g1 = the old nPC, for the 'jmp %g1' that follows the copy in RAM
	jmp  %l6                          ! jump to the copy in RAM
	rett  %l6 + 4                     ! delay slot: return from the trap; the next one is 0xA8076090
	.size FUN_a00604f0, .-FUN_a00604f0
