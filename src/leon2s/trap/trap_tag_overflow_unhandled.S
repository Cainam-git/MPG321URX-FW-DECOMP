! trap_tag_overflow_unhandled  (FUN_a00600a0)
!
! Trap table slot 0x0a (tag overflow): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a00600a0 @ 0xa00600a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00600a0
	.type FUN_a00600a0, #function
FUN_a00600a0:
! Unused slot of trap type 0x0A, tag_overflow: a tagged add or subtract instruction overflowed.
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a00600a0, .-FUN_a00600a0
