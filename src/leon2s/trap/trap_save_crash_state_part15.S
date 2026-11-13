! trap_save_crash_state_part15  (FUN_a0060800)
!
! Save %g0..%g3 in locals before calling the crash hook.
! Note: Ghidra piece 15 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060800 @ 0xa0060800  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060800
	.type FUN_a0060800, #function
FUN_a0060800:
! Part 15 of trap_save_crash_state (0xA0060720..0xA0060853). This piece lies in the slot of trap type
! 0x80 (0xA0060800): in this program the software-trap slots hold this code.
	mov  %g0, %l3                     ! keep %g0 in %l3
	mov  %g1, %l4                     ! keep %g1 in %l4
	mov  %g2, %l5                     ! keep %g2 in %l5
	mov  %g3, %l6                     ! keep %g3 in %l6
	.size FUN_a0060800, .-FUN_a0060800
