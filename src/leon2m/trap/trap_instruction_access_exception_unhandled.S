! trap_instruction_access_exception_unhandled  (FUN_a0028010)
!
! Trap table slot 0x01 (instruction access exception): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028010 @ 0xa0028010  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028010
	.type FUN_a0028010, #function
FUN_a0028010:
! Unused slot of trap type 0x01, instruction_access_exception: an instruction fetch failed.
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0028010, .-FUN_a0028010
