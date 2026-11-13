! trap_save_crash_state_part3  (FUN_a0060740)
!
! Store %g3..%g6 in the crash area.
! Note: Ghidra piece 3 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060740 @ 0xa0060740  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060740
	.type FUN_a0060740, #function
FUN_a0060740:
! Part 3 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %g3, [ %l7 + 0xc ]            ! +0x0C = %g3
	st  %g4, [ %l7 + 0x10 ]           ! +0x10 = %g4
	st  %g5, [ %l7 + 0x14 ]           ! +0x14 = %g5
	st  %g6, [ %l7 + 0x18 ]           ! +0x18 = %g6
	.size FUN_a0060740, .-FUN_a0060740
