! trap_call_halt_handler_part2  (FUN_a0060320)
!
! Open a new window and raise the interrupt level to 15.
! Note: Ghidra piece 2 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060320 @ 0xa0060320  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060320
	.type FUN_a0060320, #function
FUN_a0060320:
! Part 2 of trap_call_halt_handler (0xA0060314..0xA00603AB).
	save  %sp, -64, %sp               ! back into the trap window, frame 64 bytes below the trapped one
	rd  %psr, %l0                     ! %l0 = PSR
	or  %l0, 0xf00, %l0               ! interrupt level 15: mask all maskable interrupts
	mov  %l0, %psr                    ! write PSR (traps still off)
	.size FUN_a0060320, .-FUN_a0060320
