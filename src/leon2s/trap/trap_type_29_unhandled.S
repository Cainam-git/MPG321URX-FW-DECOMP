! trap_type_29_unhandled  (FUN_a0060290)
!
! Trap table slot 0x29 (type 29): not handled, raises a software trap.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a0060290 @ 0xa0060290  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060290
	.type FUN_a0060290, #function
FUN_a0060290:
! Unused slot of trap type 0x29, data_access_error: an error on a data load or store.
! Taking a trap turns traps off (ET = 0). The 'ta 0' below is then a trap while traps are off,
! and SPARC V8 puts the processor into error mode for that: it stops until it is reset.
	ta  0                             ! software trap 0 with traps off: error mode, the processor stops
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	nop
	.size FUN_a0060290, .-FUN_a0060290
