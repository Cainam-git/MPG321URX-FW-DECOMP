! irq_service_level1_part12  (FUN_a00609a0)
!
! Call the handler, advance to the next source and test the loop bound.
! Note: Ghidra piece 12 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00609a0 @ 0xa00609a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609a0
	.type FUN_a00609a0, #function
FUN_a00609a0:
! Piece 12 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	call  %o5                         ! run the handler of the source
	nop                               ! delay slot: nothing
	inc  %l2                          ! next source number
	cmp  %l2, 5                       ! more sources? (loop while the number is at most 5)
	.size FUN_a00609a0, .-FUN_a00609a0
