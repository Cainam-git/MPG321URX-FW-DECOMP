! irq_service_level5_part3  (FUN_a0060bd0)
!
! Set bit 0x20 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060bd0 @ 0xa0060bd0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060bd0
	.type FUN_a0060bd0, #function
FUN_a0060bd0:
! Piece 3 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	sethi  %hi(0x9f120000), %o4       ! %o4 = 0x9F120000 (second-level interrupt registers)
	or  %o4, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	or  %g1, 0x20, %g1                ! set bit 0x20: level 5 is being served
	.size FUN_a0060bd0, .-FUN_a0060bd0
