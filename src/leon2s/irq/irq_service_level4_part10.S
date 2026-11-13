! irq_service_level4_part10  (FUN_a0060b40)
!
! Acknowledge the source in the status register after its handler returned.
! Note: Ghidra piece 10 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b40 @ 0xa0060b40  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b40
	.type FUN_a0060b40, #function
FUN_a0060b40:
! Piece 10 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	sethi  %hi(0x9f120000), %g1       ! %g1 = 0x9F120000 (second-level interrupt registers)
	or  %g1, 0x7c, %g1                ! %g1 = the source status register of level 4 (0x9F12007C)
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-4 status register
	b ext_a0060b68                    ! on to the loop test (0xA0060B68)
	.size FUN_a0060b40, .-FUN_a0060b40
