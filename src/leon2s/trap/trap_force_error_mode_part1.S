! trap_force_error_mode_part1  (FUN_a0060648)
!
! Load from the misaligned address 1 while traps are disabled.
! Note: Ghidra piece 1 of the routine 0xA0060648..0xA0060657, not callable on its own; unreached: no trap-
!   table slot, call or stored word points at it.
! Name basis: descriptive - ld [1] inside a trap handler (ET=0) puts a SPARC V8 core in error mode; no
!   reference to 0xA0060648
!
! Matching notes
! --------------
! leon2s FUN_a0060648 @ 0xa0060648  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060648
	.type FUN_a0060648, #function
FUN_a0060648:
! Unreached: no trap-table slot, call or stored word points at 0xA0060648. The same instructions as the
! 'ta 0' handler of the main processor (trap_handle_faults at 0xA0029388).
	ld  [ 1 ], %g0                    ! word load from the odd address 1 with traps off: error mode, stop
	jmp  %l2                          ! never reached: jump past the trapped instruction
	.size FUN_a0060648, .-FUN_a0060648
