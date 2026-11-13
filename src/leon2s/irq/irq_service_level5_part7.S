! irq_service_level5_part7  (FUN_a0060c10)
!
! Skip idle sources and look up the source handler in the handler table.
! Note: Ghidra piece 7 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c10 @ 0xa0060c10  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c10
	.type FUN_a0060c10, #function
FUN_a0060c10:
! Piece 7 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	be ext_a0060c68                   ! no: on to the next source (0xA0060C68)
	sll  %l2, 2, %o5                  ! delay slot: %o5 = source number x 4 (offset in the handler table)
	sethi  %hi(0xa8078400), %g1       ! %g1 = upper half of the handler table address
	or  %g1, 0x370, %g1               ! %g1 = the handler table of level 5 (0xA8078770)
	.size FUN_a0060c10, .-FUN_a0060c10
