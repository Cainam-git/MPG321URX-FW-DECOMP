! irq_service_level1_part6  (FUN_a0060940)
!
! Start the source loop and test the next pending source bit.
! Note: Ghidra piece 6 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060940 @ 0xa0060940  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060940
	.type FUN_a0060940, #function
FUN_a0060940:
! Piece 6 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	or %g0, 0, %l2                    ! %l2 = 0: number of the first source
	mov  1, %g1                       ! %g1 = 1, shifted below into the bit of the source
	sll  %g1, %l2, %l0                ! %l0 = bit of the source numbered %l2
	btst  %l1, %l0                    ! is this source signalling (and not masked)?
	.size FUN_a0060940, .-FUN_a0060940
