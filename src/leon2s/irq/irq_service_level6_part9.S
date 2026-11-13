! irq_service_level6_part9  (FUN_a0060d30)
!
! Choose the acknowledge order for the source.
! Note: Ghidra piece 9 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d30 @ 0xa0060d30  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d30
	.type FUN_a0060d30, #function
FUN_a0060d30:
! Piece 9 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	inc  %l2                          ! delay slot, runs only when the branch is taken: next source number
	btst  %l3, %l0                    ! does its handler run before the acknowledge?
	be ext_a0060d5c                   ! no: acknowledge first, then run it (0xA0060D5C)
	sethi  %hi(0x9f120000), %g1       ! delay slot: %g1 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060d30, .-FUN_a0060d30
