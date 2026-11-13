! irq_service_level1_part7  (FUN_a0060950)
!
! Skip idle sources and look up the source handler in the handler table.
! Note: Ghidra piece 7 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060950 @ 0xa0060950  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060950
	.type FUN_a0060950, #function
FUN_a0060950:
! Piece 7 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	be ext_a00609a8                   ! no: on to the next source (0xA00609A8)
	sll  %l2, 2, %o5                  ! delay slot: %o5 = source number x 4 (offset in the handler table)
	sethi  %hi(0xa8078400), %g1       ! %g1 = upper half of the handler table address
	or  %g1, 0x3c4, %g1               ! %g1 = the handler table of level 1 (0xA80787C4)
	.size FUN_a0060950, .-FUN_a0060950
