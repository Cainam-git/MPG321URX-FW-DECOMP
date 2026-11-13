! trap_save_crash_state_part13  (FUN_a00607e0)
!
! Store %l7, return to the trap window and address the crash area again.
! Note: Ghidra piece 13 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a00607e0 @ 0xa00607e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00607e0
	.type FUN_a00607e0, #function
FUN_a00607e0:
! Part 13 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %l7, [ %g3 + 0x9c ]           ! +0x9C = %l7
	save                              ! back into the trap window
	sethi  %hi(0xa807fc00), %l7       ! upper bits of the save area
	or  %l7, 0x360, %l7               ! %l7 = save area 0xA807FF60
	.size FUN_a00607e0, .-FUN_a00607e0
