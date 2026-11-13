! trap_save_crash_state_part20  (FUN_a0060850)
!
! Finish the return from the trap (retry the trapped instruction).
! Note: Ghidra piece 20 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060850 @ 0xa0060850  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060850
	.type FUN_a0060850, #function
FUN_a0060850:
! Last word of trap_save_crash_state (0xA0060720..0xA0060853): not reached, see part 16.
	rett  %l2                         ! delay slot: return from the trap, next at the nPC
	.size FUN_a0060850, .-FUN_a0060850
