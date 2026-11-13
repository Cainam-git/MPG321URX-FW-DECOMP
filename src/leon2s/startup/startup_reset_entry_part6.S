! startup_reset_entry_part6  (FUN_a0060310)
!
! Fill the delay slot of the reset entry's closing 'ta 1' loop.
! Note: Ghidra piece 6 of the routine 0xA00602C0..0xA0060313, not callable on its own.
! Name basis: proven - trap-table slot 0 (reset) jumps to 0x2C0; trap-name table says 'Power-on reset'; part 5
!   calls main 0xA0060864
!
! Matching notes
! --------------
! leon2s FUN_a0060310 @ 0xa0060310  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060310
	.type FUN_a0060310, #function
FUN_a0060310:
! Last word of the reset start-up (0xA00602C0..0xA0060313).
	nop                               ! delay slot of the 'b' at 0xA006030C: nothing
	.size FUN_a0060310, .-FUN_a0060310
