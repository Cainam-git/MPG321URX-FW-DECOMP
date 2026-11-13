! trap_software_trap_13_unhandled  (FUN_a00288d0)
!
! Trap table slot 0x8d (software trap 13): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a00288d0 @ 0xa00288d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00288d0
	.type FUN_a00288d0, #function
FUN_a00288d0:
! Unused slot of trap type 0x8D, software trap 13 (raised by the instruction 'ta 13').
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a00288d0, .-FUN_a00288d0
