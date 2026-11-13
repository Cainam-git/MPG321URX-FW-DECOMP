! trap_save_crash_state_part19  (FUN_a0060840)
!
! Wait out the PSR write and start the return to the trapped instruction.
! Note: Ghidra piece 19 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060840 @ 0xa0060840  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060840
	.type FUN_a0060840, #function
FUN_a0060840:
! Part 19 of trap_save_crash_state (0xA0060720..0xA0060853): not reached, see part 16.
	nop                               ! wait: a PSR write takes effect after three instructions
	nop
	nop
	jmp  %l1                          ! jump back to the trapped instruction
	.size FUN_a0060840, .-FUN_a0060840
