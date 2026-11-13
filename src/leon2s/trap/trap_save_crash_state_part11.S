! trap_save_crash_state_part11  (FUN_a00607c0)
!
! Store the trapped window's %i7 and %l0..%l2.
! Note: Ghidra piece 11 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a00607c0 @ 0xa00607c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00607c0
	.type FUN_a00607c0, #function
FUN_a00607c0:
! Part 11 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %i7, [ %g3 + 0x7c ]           ! +0x7C = %i7
	st  %l0, [ %g3 + 0x80 ]           ! +0x80 = its %l0
	st  %l1, [ %g3 + 0x84 ]           ! +0x84 = %l1
	st  %l2, [ %g3 + 0x88 ]           ! +0x88 = %l2
	.size FUN_a00607c0, .-FUN_a00607c0
