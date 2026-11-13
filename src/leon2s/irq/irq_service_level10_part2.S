! irq_service_level10_part2  (FUN_a0060ee0)
!
! Mask interrupt 10 (bit 0x400) in the LEON2 interrupt mask and start setting 0x9F120028.
! Note: Ghidra piece 2 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060ee0 @ 0xa0060ee0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ee0
	.type FUN_a0060ee0, #function
FUN_a0060ee0:
! Piece 2 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	ld  [ %o5 ], %g1                  ! read the interrupt mask
	and  %g1, -1025, %g1              ! clear bit 0x400: level 10 masked while it is served
	st  %g1, [ %o5 ]                  ! write the interrupt mask back
	sethi  %hi(0x9f120000), %o4       ! %o4 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060ee0, .-FUN_a0060ee0
