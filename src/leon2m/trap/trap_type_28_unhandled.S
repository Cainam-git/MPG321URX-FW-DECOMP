! trap_type_28_unhandled  (FUN_a0028280)
!
! Trap table slot 0x28 (type 28): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028280 @ 0xa0028280  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028280
	.type FUN_a0028280, #function
FUN_a0028280:
! Unused slot of trap type 0x28, cp_exception: a coprocessor exception.
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0028280, .-FUN_a0028280
