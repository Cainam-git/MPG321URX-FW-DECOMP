! trap_call_halt_handler_part1  (FUN_a0060314)
!
! Copy the trap PC/nPC to %l5/%l6 and step back to the trapped window.
! Note: Ghidra piece 1 of the routine 0xA0060314..0xA00603AB, not callable on its own; unreached: no trap-
!   table slot, call or stored word points at it.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a0060314 @ 0xa0060314  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060314
	.type FUN_a0060314, #function
FUN_a0060314:
! Unreached: no trap-table slot, call or stored word points at 0xA0060314. Written as a trap handler
! (the same steps as the Leon2M routines trap_save_return_pc + trap_enter_halt_loop): it masks all
! interrupts, turns traps on and calls trap_halt_forever (0xA0061224), an endless loop. The code after
! the call would put %g0..%g3 back and return from the trap with traps off and interrupt level 0.
	mov  %l1, %l5                     ! keep the trapped PC in %l5
	mov  %l2, %l6                     ! keep the trapped nPC in %l6
	restore                           ! step back to the trapped window
	.size FUN_a0060314, .-FUN_a0060314
