! trap_call_halt_handler_part6  (FUN_a0060360)
!
! Save %g2/%g3 in locals and call the handler (an endless halt loop).
! Note: Ghidra piece 6 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060360 @ 0xa0060360  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060360
	.type FUN_a0060360, #function
FUN_a0060360:
! Part 6 of trap_call_halt_handler (0xA0060314..0xA00603AB).
	mov  %g2, %l3                     ! keep %g2 in %l3
	mov  %g3, %l4                     ! keep %g3 in %l4
	call  %l7                         ! call trap_halt_forever: an endless loop, it never returns
	nop                               ! delay slot: nothing
	.size FUN_a0060360, .-FUN_a0060360
