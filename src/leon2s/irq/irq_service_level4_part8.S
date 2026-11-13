! irq_service_level4_part8  (FUN_a0060b20)
!
! Skip sources without a handler and choose the acknowledge order.
! Note: Ghidra piece 8 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b20 @ 0xa0060b20  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b20
	.type FUN_a0060b20, #function
FUN_a0060b20:
! Piece 8 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	cmp  %o5, 0                       ! is there a handler for it?
	be,a ext_a0060b68                 ! no handler: on to the next source (0xA0060B68)
	inc  %l2                          ! delay slot, runs only when the branch is taken: next source number
	btst  %l3, %l0                    ! does its handler run before the acknowledge?
	.size FUN_a0060b20, .-FUN_a0060b20
