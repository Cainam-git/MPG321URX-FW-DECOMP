! trap_save_crash_state_part7  (FUN_a0060780)
!
! Store the trap window's %i0..%i3.
! Note: Ghidra piece 7 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060780 @ 0xa0060780  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060780
	.type FUN_a0060780, #function
FUN_a0060780:
! Part 7 of trap_save_crash_state (0xA0060720..0xA0060853): the trap window's in registers.
	st  %i0, [ %g3 + 0x40 ]           ! +0x40 = %i0
	st  %i1, [ %g3 + 0x44 ]           ! +0x44 = %i1
	st  %i2, [ %g3 + 0x48 ]           ! +0x48 = %i2
	st  %i3, [ %g3 + 0x4c ]           ! +0x4C = %i3
	.size FUN_a0060780, .-FUN_a0060780
