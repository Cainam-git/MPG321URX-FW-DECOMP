! irq_service_level6_part15  (FUN_a0060d90)
!
! Clear interrupt 6 in the LEON2 interrupt clear register.
! Note: Ghidra piece 15 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d90 @ 0xa0060d90  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d90
	.type FUN_a0060d90, #function
FUN_a0060d90:
! Piece 15 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	or  %o4, 0x9c, %g1                ! %g1 = the LEON2 interrupt clear register
	st  %o3, [ %g1 ]                  ! write 0x40: clear level 6 in the LEON2 interrupt clear register
	or  %o5, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	.size FUN_a0060d90, .-FUN_a0060d90
