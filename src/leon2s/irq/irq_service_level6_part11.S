! irq_service_level6_part11  (FUN_a0060d50)
!
! Finish the late acknowledge; on the early path start acknowledging first.
! Note: Ghidra piece 11 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d50 @ 0xa0060d50  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d50
	.type FUN_a0060d50, #function
FUN_a0060d50:
! Piece 11 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-6 status register
	b ext_a0060d70                    ! on to the loop test (0xA0060D70)
	inc  %l2                          ! delay slot: next source number
	or  %g1, 0x84, %g1                ! %g1 = the source status register of level 6 (0x9F120084)
	.size FUN_a0060d50, .-FUN_a0060d50
