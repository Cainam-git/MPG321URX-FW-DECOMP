! trap_save_crash_state_part18  (FUN_a0060830)
!
! Rewrite PSR from the trap-time PSR with ET toggled and the interrupt level cleared.
! Note: Ghidra piece 18 of the routine 0xA0060720..0xA0060853, not callable on its own.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060830 @ 0xa0060830  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060830
	.type FUN_a0060830, #function
FUN_a0060830:
! Part 18 of trap_save_crash_state (0xA0060720..0xA0060853): not reached, see part 16. %l0 is the PSR
! read at the trap, with traps off, so both writes flip ET on: traps on, then interrupt level 0. A RETT
! with traps on is an illegal_instruction trap under SPARC V8.
	nop                               ! no operation
	wr  %l0, 0x20, %psr               ! write PSR with ET flipped: traps on
	andn  %l0, 0xf00, %l4             ! the same PSR with interrupt level 0
	wr  %l4, 0x20, %psr               ! write it with ET flipped: traps on, interrupt level 0
	.size FUN_a0060830, .-FUN_a0060830
