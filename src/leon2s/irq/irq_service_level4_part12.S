! irq_service_level4_part12  (FUN_a0060b60)
!
! Advance to the next source and loop over the seven sources.
! Note: Ghidra piece 12 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b60 @ 0xa0060b60  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b60
	.type FUN_a0060b60, #function
FUN_a0060b60:
! Piece 12 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	nop                               ! delay slot: nothing
	inc  %l2                          ! next source number
	cmp  %l2, 6                       ! more sources? (loop while the number is at most 6)
	bleu ext_a0060b04                 ! yes: back to the start of the loop (0xA0060B04)
	.size FUN_a0060b60, .-FUN_a0060b60
