! irq_service_level4_part2  (FUN_a0060ac0)
!
! Mask interrupt 4 (bit 0x10) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060ac0 @ 0xa0060ac0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ac0
	.type FUN_a0060ac0, #function
FUN_a0060ac0:
! Piece 2 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	ld  [ %o5 ], %g1                  ! read the interrupt mask
	and  %g1, -17, %g1                ! clear bit 0x10: level 4 masked while it is served
	st  %g1, [ %o5 ]                  ! write the interrupt mask back
	sethi  %hi(0x9f120000), %o4       ! %o4 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060ac0, .-FUN_a0060ac0
