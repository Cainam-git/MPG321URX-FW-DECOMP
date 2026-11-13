! trap_save_crash_state_part16  (FUN_a0060810)
!
! Call the crash hook, which does not return.
! Note: Ghidra piece 16 of the routine 0xA0060720..0xA0060853, not callable on its own. The same four
!   instructions as irq_entry_part12; sits in the trap table slot of type 0x81.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060810 @ 0xa0060810  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060810
	.type FUN_a0060810, #function
FUN_a0060810:
! Part 16 of trap_save_crash_state (0xA0060720..0xA0060853), in the slot of trap type 0x81; the same four
! instructions as irq_entry_part12, but here the call goes to the crash hook. That routine
! (trap_dump_crash_and_halt) never returns, so the rest of trap_save_crash_state is not reached.
	call  %l7                         ! call the crash hook, traps still off
	nop                               ! delay slot: nothing
	restore                           ! step to the trapped window ...
	save                              ! ... and back
	.size FUN_a0060810, .-FUN_a0060810
