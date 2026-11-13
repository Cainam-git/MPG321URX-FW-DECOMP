! trap_save_crash_state_part12  (FUN_a00607d0)
!
! Store the trapped window's %l3..%l6.
! Note: Ghidra piece 12 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a00607d0 @ 0xa00607d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00607d0
	.type FUN_a00607d0, #function
FUN_a00607d0:
! Part 12 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %l3, [ %g3 + 0x8c ]           ! +0x8C = %l3
	st  %l4, [ %g3 + 0x90 ]           ! +0x90 = %l4
	st  %l5, [ %g3 + 0x94 ]           ! +0x94 = %l5
	st  %l6, [ %g3 + 0x98 ]           ! +0x98 = %l6
	.size FUN_a00607d0, .-FUN_a00607d0
