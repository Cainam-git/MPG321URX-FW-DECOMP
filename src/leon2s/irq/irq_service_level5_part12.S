! irq_service_level5_part12  (FUN_a0060c60)
!
! Call the handler, advance to the next source and test the loop bound.
! Note: Ghidra piece 12 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c60 @ 0xa0060c60  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c60
	.type FUN_a0060c60, #function
FUN_a0060c60:
! Piece 12 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	call  %o5                         ! run the handler of the source
	nop                               ! delay slot: nothing
	inc  %l2                          ! next source number
	cmp  %l2, 0xd                     ! more sources? (loop while the number is at most 13)
	.size FUN_a0060c60, .-FUN_a0060c60
