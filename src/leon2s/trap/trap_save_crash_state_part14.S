! trap_save_crash_state_part14  (FUN_a00607f0)
!
! Reload %g3 and load the crash hook pointer.
! Note: Ghidra piece 14 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a00607f0 @ 0xa00607f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00607f0
	.type FUN_a00607f0, #function
FUN_a00607f0:
! Part 14 of trap_save_crash_state (0xA0060720..0xA0060853).
	ld  [ %l7 + 0xc ], %g3            ! %g3 back to its value at the trap (word +0x0C)
	sethi  %hi(0xa8076000), %l3       ! upper bits of the crash hook word
	or  %l3, 0x88, %l3                ! %l3 = 0xA8076088, the crash hook word
	ld  [ %l3 ], %l7                  ! %l7 = the crash hook (start value trap_dump_crash_and_halt)
	.size FUN_a00607f0, .-FUN_a00607f0
