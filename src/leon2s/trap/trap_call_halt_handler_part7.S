! trap_call_halt_handler_part7  (FUN_a0060370)
!
! Return to the trap window and restore %g0/%g1.
! Note: Ghidra piece 7 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060370 @ 0xa0060370  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060370
	.type FUN_a0060370, #function
FUN_a0060370:
! Part 7 of trap_call_halt_handler (0xA0060314..0xA00603AB): not reached, see part 1.
	restore                           ! step to the trapped window ...
	save                              ! ... and back, with traps on
	mov  %l1, %g0                     ! no effect: %g0 is always 0
	mov  %l2, %g1                     ! %g1 back
	.size FUN_a0060370, .-FUN_a0060370
