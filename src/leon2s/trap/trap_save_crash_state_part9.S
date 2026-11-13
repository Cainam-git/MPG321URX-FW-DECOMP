! trap_save_crash_state_part9  (FUN_a00607a0)
!
! Step to the trapped window and store its %i0..%i2.
! Note: Ghidra piece 9 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a00607a0 @ 0xa00607a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00607a0
	.type FUN_a00607a0, #function
FUN_a00607a0:
! Part 9 of trap_save_crash_state (0xA0060720..0xA0060853): the trapped window's registers.
	restore                           ! step back to the trapped window
	st  %i0, [ %g3 + 0x60 ]           ! +0x60 = its %i0
	st  %i1, [ %g3 + 0x64 ]           ! +0x64 = %i1
	st  %i2, [ %g3 + 0x68 ]           ! +0x68 = %i2
	.size FUN_a00607a0, .-FUN_a00607a0
