! irq_service_level10_part3  (FUN_a0060ef0)
!
! Set bit 0x400 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060ef0 @ 0xa0060ef0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ef0
	.type FUN_a0060ef0, #function
FUN_a0060ef0:
! Piece 3 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	or  %o4, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	or  %g1, 0x400, %g1               ! set bit 0x400: level 10 is being served
	st  %g1, [ %o5 ]                  ! write the active-level register back
	.size FUN_a0060ef0, .-FUN_a0060ef0
