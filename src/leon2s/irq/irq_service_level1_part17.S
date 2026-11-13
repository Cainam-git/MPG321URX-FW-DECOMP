! irq_service_level1_part17  (FUN_a00609f0)
!
! Finish the unmask and return.
! Note: Ghidra piece 17 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00609f0 @ 0xa00609f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609f0
	.type FUN_a00609f0, #function
FUN_a00609f0:
! Piece 17 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	st  %g1, [ %o4 ]                  ! write the interrupt mask back
	ret                               ! return to irq_entry
	restore                           ! delay slot: close the register window
	.size FUN_a00609f0, .-FUN_a00609f0
