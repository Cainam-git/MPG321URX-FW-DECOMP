! trap_save_crash_state_part10  (FUN_a00607b0)
!
! Store the trapped window's %i3..%i6.
! Note: Ghidra piece 10 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a00607b0 @ 0xa00607b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00607b0
	.type FUN_a00607b0, #function
FUN_a00607b0:
! Part 10 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %i3, [ %g3 + 0x6c ]           ! +0x6C = %i3
	st  %i4, [ %g3 + 0x70 ]           ! +0x70 = %i4
	st  %i5, [ %g3 + 0x74 ]           ! +0x74 = %i5
	st  %fp, [ %g3 + 0x78 ]           ! +0x78 = %i6 (frame pointer)
	.size FUN_a00607b0, .-FUN_a00607b0
