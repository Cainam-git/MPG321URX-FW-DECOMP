! irq_service_level5_part8  (FUN_a0060c20)
!
! Load the source handler and skip sources without one.
! Note: Ghidra piece 8 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c20 @ 0xa0060c20  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c20
	.type FUN_a0060c20, #function
FUN_a0060c20:
! Piece 8 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	ld  [ %g1 + %o5 ], %o5            ! %o5 = the handler of this source
	cmp  %o5, 0                       ! is there a handler for it?
	be,a ext_a0060c6c                 ! no handler: on to the next source (0xA0060C6C)
	inc  %l2                          ! delay slot, runs only when the branch is taken: next source number
	.size FUN_a0060c20, .-FUN_a0060c20
