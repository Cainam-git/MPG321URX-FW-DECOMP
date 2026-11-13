! irq_service_level1_part3  (FUN_a0060910)
!
! Set bit 0x2 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060910 @ 0xa0060910  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060910
	.type FUN_a0060910, #function
FUN_a0060910:
! Piece 3 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	sethi  %hi(0x9f120000), %o4       ! %o4 = 0x9F120000 (second-level interrupt registers)
	or  %o4, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	or  %g1, 2, %g1                   ! set bit 0x2: level 1 is being served
	.size FUN_a0060910, .-FUN_a0060910
