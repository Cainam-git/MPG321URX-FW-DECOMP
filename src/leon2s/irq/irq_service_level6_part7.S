! irq_service_level6_part7  (FUN_a0060d10)
!
! Test the next pending source bit and address the handler table.
! Note: Ghidra piece 7 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d10 @ 0xa0060d10  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d10
	.type FUN_a0060d10, #function
FUN_a0060d10:
! Piece 7 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	btst  %l1, %l0                    ! is this source signalling (and not masked)?
	be ext_a0060d6c                   ! no: on to the next source (0xA0060D6C)
	sll  %l2, 2, %o5                  ! delay slot: %o5 = source number x 4 (offset in the handler table)
	sethi  %hi(0xa8079000), %g1       ! %g1 = upper half of the handler table address
	.size FUN_a0060d10, .-FUN_a0060d10
