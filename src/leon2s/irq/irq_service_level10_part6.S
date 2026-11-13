! irq_service_level10_part6  (FUN_a0060f20)
!
! Test the next pending source bit.
! Note: Ghidra piece 6 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f20 @ 0xa0060f20  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f20
	.type FUN_a0060f20, #function
FUN_a0060f20:
! Piece 6 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	mov  1, %g1                       ! %g1 = 1, shifted below into the bit of the source
	sll  %g1, %l2, %l0                ! %l0 = bit of the source numbered %l2
	btst  %l1, %l0                    ! is this source signalling (and not masked)?
	sll  %l2, 2, %o5                  ! %o5 = source number x 4 (offset in the handler table)
	.size FUN_a0060f20, .-FUN_a0060f20
