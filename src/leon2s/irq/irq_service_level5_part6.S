! irq_service_level5_part6  (FUN_a0060c00)
!
! Start the source loop and test the next pending source bit.
! Note: Ghidra piece 6 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c00 @ 0xa0060c00  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c00
	.type FUN_a0060c00, #function
FUN_a0060c00:
! Piece 6 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	or %g0, 0, %l2                    ! %l2 = 0: number of the first source
	mov  1, %g1                       ! %g1 = 1, shifted below into the bit of the source
	sll  %g1, %l2, %l0                ! %l0 = bit of the source numbered %l2
	btst  %l1, %l0                    ! is this source signalling (and not masked)?
	.size FUN_a0060c00, .-FUN_a0060c00
