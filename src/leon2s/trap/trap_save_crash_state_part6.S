! trap_save_crash_state_part6  (FUN_a0060770)
!
! Store %l4..%l7 (WIM, stack pointer, Y, frame pointer).
! Note: Ghidra piece 6 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060770 @ 0xa0060770  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060770
	.type FUN_a0060770, #function
FUN_a0060770:
! Part 6 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %l4, [ %g3 + 0x30 ]           ! +0x30 = WIM
	st  %l5, [ %g3 + 0x34 ]           ! +0x34 = stack pointer
	st  %l6, [ %g3 + 0x38 ]           ! +0x38 = Y
	st  %l7, [ %g3 + 0x3c ]           ! +0x3C = frame pointer
	.size FUN_a0060770, .-FUN_a0060770
