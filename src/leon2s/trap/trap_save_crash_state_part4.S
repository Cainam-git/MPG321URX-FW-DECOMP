! trap_save_crash_state_part4  (FUN_a0060750)
!
! Store %g7, keep the crash area address in %g3 and copy %fp to %l7.
! Note: Ghidra piece 4 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060750 @ 0xa0060750  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060750
	.type FUN_a0060750, #function
FUN_a0060750:
! Part 4 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %g7, [ %l7 + 0x1c ]           ! +0x1C = %g7
	sethi  %hi(0xa807fc00), %g3       ! %g3 = the save area as well (its old value is stored)
	or  %g3, 0x360, %g3
	mov  %fp, %l7                     ! %l7 = frame pointer (the last of the eight trap-window values)
	.size FUN_a0060750, .-FUN_a0060750
