! irq_service_level10_part14  (FUN_a0060fa0)
!
! Clear interrupt 10 in the LEON2 interrupt clear register.
! Note: Ghidra piece 14 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060fa0 @ 0xa0060fa0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060fa0
	.type FUN_a0060fa0, #function
FUN_a0060fa0:
! Piece 14 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	or  %o4, 0x9c, %g1                ! %g1 = the LEON2 interrupt clear register
	st  %o3, [ %g1 ]                  ! write 0x400: clear level 10 in the LEON2 interrupt clear register
	or  %o5, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	.size FUN_a0060fa0, .-FUN_a0060fa0
