! trap_save_crash_state_part17  (FUN_a0060820)
!
! Restore %g0..%g3 after the crash hook.
! Note: Ghidra piece 17 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060820 @ 0xa0060820  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060820
	.type FUN_a0060820, #function
FUN_a0060820:
! Part 17 of trap_save_crash_state (0xA0060720..0xA0060853): not reached, see part 16.
	mov  %l3, %g0                     ! no effect: %g0 is always 0
	mov  %l4, %g1                     ! %g1 back
	mov  %l5, %g2                     ! %g2 back
	mov  %l6, %g3                     ! %g3 back
	.size FUN_a0060820, .-FUN_a0060820
