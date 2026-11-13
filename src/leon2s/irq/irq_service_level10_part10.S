! irq_service_level10_part10  (FUN_a0060f60)
!
! Advance to the next source and acknowledge it in the status register (early path).
! Note: Ghidra piece 10 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f60 @ 0xa0060f60  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f60
	.type FUN_a0060f60, #function
FUN_a0060f60:
! Piece 10 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	inc  %l2                          ! delay slot: next source number
	sethi  %hi(0x9f120000), %g1       ! %g1 = 0x9F120000 (second-level interrupt registers)
	or  %g1, 0x94, %g1                ! %g1 = the source status register of level 10 (0x9F120094)
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-10 status register
	.size FUN_a0060f60, .-FUN_a0060f60
