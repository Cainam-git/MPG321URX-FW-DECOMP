! irq_service_level6_part8  (FUN_a0060d20)
!
! Load the source handler and skip sources without one.
! Note: Ghidra piece 8 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d20 @ 0xa0060d20  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d20
	.type FUN_a0060d20, #function
FUN_a0060d20:
! Piece 8 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	or  %g1, 0x388, %g1               ! %g1 = the handler table of level 6 (0xA8079388)
	ld  [ %g1 + %o5 ], %o5            ! %o5 = the handler of this source
	cmp  %o5, 0                       ! is there a handler for it?
	be,a ext_a0060d70                 ! no handler: on to the next source (0xA0060D70)
	.size FUN_a0060d20, .-FUN_a0060d20
