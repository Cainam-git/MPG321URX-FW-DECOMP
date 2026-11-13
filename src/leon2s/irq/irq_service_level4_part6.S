! irq_service_level4_part6  (FUN_a0060b00)
!
! Test the next pending source bit.
! Note: Ghidra piece 6 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b00 @ 0xa0060b00  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b00
	.type FUN_a0060b00, #function
FUN_a0060b00:
! Piece 6 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	mov  1, %g1                       ! %g1 = 1, shifted below into the bit of the source
	sll  %g1, %l2, %l0                ! %l0 = bit of the source numbered %l2
	btst  %l1, %l0                    ! is this source signalling (and not masked)?
	be ext_a0060b64                   ! no: on to the next source (0xA0060B64)
	.size FUN_a0060b00, .-FUN_a0060b00
