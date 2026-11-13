! irq_service_level5_part17  (FUN_a0060cb0)
!
! Finish the unmask and return.
! Note: Ghidra piece 17 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060cb0 @ 0xa0060cb0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060cb0
	.type FUN_a0060cb0, #function
FUN_a0060cb0:
! Piece 17 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	st  %g1, [ %o4 ]                  ! write the interrupt mask back
	ret                               ! return to irq_entry
	restore                           ! delay slot: close the register window
	.size FUN_a0060cb0, .-FUN_a0060cb0
