! irq_service_level10_part9  (FUN_a0060f50)
!
! Acknowledge the source in the status register after its handler returned.
! Note: Ghidra piece 9 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f50 @ 0xa0060f50  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f50
	.type FUN_a0060f50, #function
FUN_a0060f50:
! Piece 9 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	sethi  %hi(0x9f120000), %g1       ! %g1 = 0x9F120000 (second-level interrupt registers)
	or  %g1, 0x94, %g1                ! %g1 = the source status register of level 10 (0x9F120094)
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-10 status register
	b ext_a0060f80                    ! on to the loop test (0xA0060F80)
	.size FUN_a0060f50, .-FUN_a0060f50
