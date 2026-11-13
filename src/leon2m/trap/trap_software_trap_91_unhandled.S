! trap_software_trap_91_unhandled  (FUN_a0028db0)
!
! Trap table slot 0xdb (software trap 91): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028db0 @ 0xa0028db0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028db0
	.type FUN_a0028db0, #function
FUN_a0028db0:
! Unused slot of trap type 0xDB, software trap 91 (raised by the instruction 'ta 91').
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0028db0, .-FUN_a0028db0
