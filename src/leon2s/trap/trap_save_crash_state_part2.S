! trap_save_crash_state_part2  (FUN_a0060730)
!
! Clear the %g0 slot and store %g1/%g2 in the crash area.
! Note: Ghidra piece 2 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060730 @ 0xa0060730  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060730
	.type FUN_a0060730, #function
FUN_a0060730:
! Part 2 of trap_save_crash_state (0xA0060720..0xA0060853).
	or  %l7, 0x360, %l7               ! %l7 = save area 0xA807FF60
	clr  [%l7 + 0]                    ! word 0 = 0 (the place of %g0)
	st  %g1, [ %l7 + 4 ]              ! +0x04 = %g1
	st  %g2, [ %l7 + 8 ]              ! +0x08 = %g2
	.size FUN_a0060730, .-FUN_a0060730
