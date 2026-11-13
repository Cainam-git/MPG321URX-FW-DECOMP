! irq_service_level1_part11  (FUN_a0060990)
!
! Acknowledge the source in the status register before calling its handler.
! Note: Ghidra piece 11 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060990 @ 0xa0060990  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060990
	.type FUN_a0060990, #function
FUN_a0060990:
! Piece 11 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	b ext_a00609ac                    ! on to the loop test (0xA00609AC)
	inc  %l2                          ! delay slot: next source number
	or  %g1, 0x70, %g1                ! %g1 = the source status register of level 1 (0x9F120070)
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-1 status register
	.size FUN_a0060990, .-FUN_a0060990
