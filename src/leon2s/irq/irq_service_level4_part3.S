! irq_service_level4_part3  (FUN_a0060ad0)
!
! Set bit 0x10 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060ad0 @ 0xa0060ad0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ad0
	.type FUN_a0060ad0, #function
FUN_a0060ad0:
! Piece 3 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	or  %o4, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	or  %g1, 0x10, %g1                ! set bit 0x10: level 4 is being served
	st  %g1, [ %o5 ]                  ! write the active-level register back
	.size FUN_a0060ad0, .-FUN_a0060ad0
