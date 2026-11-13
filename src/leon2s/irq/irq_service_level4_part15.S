! irq_service_level4_part15  (FUN_a0060b90)
!
! Drop bit 0x10 from 0x9F120028.
! Note: Ghidra piece 15 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b90 @ 0xa0060b90  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b90
	.type FUN_a0060b90, #function
FUN_a0060b90:
! Piece 15 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	or  %o5, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	and  %g1, -17, %g1                ! clear bit 0x10: level 4 no longer being served
	st  %g1, [ %o5 ]                  ! write the active-level register back
	.size FUN_a0060b90, .-FUN_a0060b90
