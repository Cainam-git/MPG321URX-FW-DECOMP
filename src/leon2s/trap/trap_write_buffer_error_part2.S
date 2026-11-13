! trap_write_buffer_error_part2  (FUN_a0060510)
!
! Count the stored counter down; return to the interrupted code, or raise 'ta 0' when it drops below 0.
! Note: Second half of trap_write_buffer_error; sits in the trap table slots of types 0x51 and 0x52.
! Name basis: proven - continues trap_write_buffer_error_part1: deccc, store, 'jmp %l1; rett %l2', and 'ta 0'
!   on the negative branch
!
! Matching notes
! --------------
! leon2s FUN_a0060510 @ 0xa0060510  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060510
	.type FUN_a0060510, #function
FUN_a0060510:
! This slot (trap type 0x51) holds the rest of trap_write_buffer_error, not a handler for trap type 0x51.
	deccc  %l5                        ! one error less (subtract 1 and set the condition codes)
	st  %l5, [ %l4 ]                  ! store the new count
	bl .La0060528                     ! below 0: stop the processor (0xA0060528)
	nop                               ! delay slot: nothing
	jmp  %l1                          ! else jump back to the trapped instruction
	rett  %l2                         ! delay slot: return from the trap and run it again
.La0060528:
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! never reached
	.size FUN_a0060510, .-FUN_a0060510
