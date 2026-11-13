! irq_service_level4_part7  (FUN_a0060b10)
!
! Look up the source handler in the handler table.
! Note: Ghidra piece 7 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b10 @ 0xa0060b10  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b10
	.type FUN_a0060b10, #function
FUN_a0060b10:
! Piece 7 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	sll  %l2, 2, %o5                  ! delay slot: %o5 = source number x 4 (offset in the handler table)
	sethi  %hi(0xa8078400), %g1       ! %g1 = upper half of the handler table address
	or  %g1, 0x3a8, %g1               ! %g1 = the handler table of level 4 (0xA80787A8)
	ld  [ %g1 + %o5 ], %o5            ! %o5 = the handler of this source
	.size FUN_a0060b10, .-FUN_a0060b10
