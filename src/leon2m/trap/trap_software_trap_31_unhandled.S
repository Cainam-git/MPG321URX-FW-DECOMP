! trap_software_trap_31_unhandled  (FUN_a00289f0)
!
! Trap table slot 0x9f (software trap 31): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a00289f0 @ 0xa00289f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00289f0
	.type FUN_a00289f0, #function
FUN_a00289f0:
! Unused slot of trap type 0x9F, software trap 31 (raised by the instruction 'ta 31').
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a00289f0, .-FUN_a00289f0
