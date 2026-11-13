! trap_save_crash_state_part5  (FUN_a0060760)
!
! Store the trap window's %l0..%l3 (PSR, PC, nPC, TBR).
! Note: Ghidra piece 5 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060760 @ 0xa0060760  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060760
	.type FUN_a0060760, #function
FUN_a0060760:
! Part 5 of trap_save_crash_state (0xA0060720..0xA0060853).
	st  %l0, [ %g3 + 0x20 ]           ! +0x20 = PSR at the trap
	st  %l1, [ %g3 + 0x24 ]           ! +0x24 = trapped PC
	st  %l2, [ %g3 + 0x28 ]           ! +0x28 = trapped nPC
	st  %l3, [ %g3 + 0x2c ]           ! +0x2C = TBR (holds the trap type)
	.size FUN_a0060760, .-FUN_a0060760
