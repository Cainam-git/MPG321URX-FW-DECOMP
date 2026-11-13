! trap_software_trap_25_unhandled  (FUN_a0028990)
!
! Trap table slot 0x99 (software trap 25): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028990 @ 0xa0028990  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028990
	.type FUN_a0028990, #function
FUN_a0028990:
! Unused slot of trap type 0x99, software trap 25 (raised by the instruction 'ta 25').
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0028990, .-FUN_a0028990
