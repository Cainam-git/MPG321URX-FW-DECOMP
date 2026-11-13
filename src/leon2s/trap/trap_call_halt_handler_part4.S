! trap_call_halt_handler_part4  (FUN_a0060340)
!
! Read PSR and start loading the halt-loop address.
! Note: Ghidra piece 4 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060340 @ 0xa0060340  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060340
	.type FUN_a0060340, #function
FUN_a0060340:
! Part 4 of trap_call_halt_handler (0xA0060314..0xA00603AB).
	rd  %psr, %l0                     ! %l0 = PSR as it is now (traps on, level 15)
	nop                               ! no operation
	nop
	sethi  %hi(0xa0061000), %l4       ! upper bits of the address of trap_halt_forever
	.size FUN_a0060340, .-FUN_a0060340
