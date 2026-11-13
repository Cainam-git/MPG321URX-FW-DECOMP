! irq_service_level6_part12  (FUN_a0060d60)
!
! Acknowledge the source, call its handler and advance to the next source.
! Note: Ghidra piece 12 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d60 @ 0xa0060d60  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d60
	.type FUN_a0060d60, #function
FUN_a0060d60:
! Piece 12 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-6 status register
	call  %o5                         ! run the handler of the source
	nop                               ! delay slot: nothing
	inc  %l2                          ! next source number
	.size FUN_a0060d60, .-FUN_a0060d60
