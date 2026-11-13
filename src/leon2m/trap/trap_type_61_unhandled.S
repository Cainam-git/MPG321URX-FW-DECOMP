! trap_type_61_unhandled  (FUN_a0028610)
!
! Trap table slot 0x61 (type 61): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028610 @ 0xa0028610  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028610
	.type FUN_a0028610, #function
FUN_a0028610:
! Unused slot of trap type 0x61, a trap type SPARC V8 leaves to the processor maker.
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0028610, .-FUN_a0028610
