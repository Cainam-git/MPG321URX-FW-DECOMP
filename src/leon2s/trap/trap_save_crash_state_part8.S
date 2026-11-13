! trap_save_crash_state_part8  (FUN_a0060790)
!
! Store the trap window's %i4..%i7.
! Note: Ghidra piece 8 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060790 @ 0xa0060790  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060790
	.type FUN_a0060790, #function
FUN_a0060790:
! Part 8 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %i4, [ %g3 + 0x50 ]           ! +0x50 = %i4
	st  %i5, [ %g3 + 0x54 ]           ! +0x54 = %i5
	st  %fp, [ %g3 + 0x58 ]           ! +0x58 = %i6 (frame pointer)
	st  %i7, [ %g3 + 0x5c ]           ! +0x5C = %i7
	.size FUN_a0060790, .-FUN_a0060790
