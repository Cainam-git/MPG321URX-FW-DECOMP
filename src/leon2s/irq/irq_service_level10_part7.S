! irq_service_level10_part7  (FUN_a0060f30)
!
! Skip idle sources and choose the acknowledge order.
! Note: Ghidra piece 7 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f30 @ 0xa0060f30  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f30
	.type FUN_a0060f30, #function
FUN_a0060f30:
! Piece 7 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	be ext_a0060f7c                   ! no: on to the next source (0xA0060F7C)
	sethi  %hi(0xa8079000), %g1       ! delay slot: %g1 = upper half of the handler table address
	btst  %l3, %l0                    ! does its handler run before the acknowledge?
	be ext_a0060f64                   ! no: acknowledge first, then run it (0xA0060F64)
	.size FUN_a0060f30, .-FUN_a0060f30
