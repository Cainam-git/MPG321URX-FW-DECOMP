! trap_call_halt_handler_part5  (FUN_a0060350)
!
! Finish the handler address and save %g0/%g1 in locals.
! Note: Ghidra piece 5 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060350 @ 0xa0060350  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060350
	.type FUN_a0060350, #function
FUN_a0060350:
! Part 5 of trap_call_halt_handler (0xA0060314..0xA00603AB).
	or  %l4, 0x224, %l4               ! %l4 = 0xA0061224, trap_halt_forever
	mov  %l4, %l7                     ! %l7 = the routine to call
	mov  %g0, %l1                     ! keep %g0 in %l1
	mov  %g1, %l2                     ! keep %g1 in %l2
	.size FUN_a0060350, .-FUN_a0060350
