! trap_call_halt_handler_part8  (FUN_a0060380)
!
! Restore %g2/%g3 and disable traps again.
! Note: Ghidra piece 8 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060380 @ 0xa0060380  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060380
	.type FUN_a0060380, #function
FUN_a0060380:
! Part 8 of trap_call_halt_handler (0xA0060314..0xA00603AB): not reached, see part 1.
	mov  %l3, %g2                     ! %g2 back
	mov  %l4, %g3                     ! %g3 back
	nop                               ! no operation
	wr  %l0, 0x20, %psr               ! %l0 has traps on: writing it with ET flipped turns traps off
	.size FUN_a0060380, .-FUN_a0060380
