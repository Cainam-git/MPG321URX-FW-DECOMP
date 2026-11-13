! trap_type_71_unhandled  (FUN_a0028710)
!
! Trap table slot 0x71 (type 71): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028710 @ 0xa0028710  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028710
	.type FUN_a0028710, #function
FUN_a0028710:
! Unused slot of trap type 0x71, a trap type SPARC V8 leaves to the processor maker.
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0028710, .-FUN_a0028710
