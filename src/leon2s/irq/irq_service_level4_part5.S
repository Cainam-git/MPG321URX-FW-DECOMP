! irq_service_level4_part5  (FUN_a0060af0)
!
! Drop masked sources, take the acknowledge-after-call flags and start the loop.
! Note: Ghidra piece 5 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060af0 @ 0xa0060af0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060af0
	.type FUN_a0060af0, #function
FUN_a0060af0:
! Piece 5 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	ld  [ %o4 ], %o5                  ! read it again, for its upper half
	andn  %l1, %g1, %l1               ! drop the masked sources
	srl  %o5, 0x10, %l3               ! %l3 = upper half: sources to run before the acknowledge
	or %g0, 0, %l2                    ! %l2 = 0: number of the first source
	.size FUN_a0060af0, .-FUN_a0060af0
