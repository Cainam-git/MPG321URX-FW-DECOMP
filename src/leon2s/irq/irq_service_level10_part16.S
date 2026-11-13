! irq_service_level10_part16  (FUN_a0060fc0)
!
! Unmask interrupt 10 again and return from the service routine.
! Note: Ghidra piece 16 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060fc0 @ 0xa0060fc0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060fc0
	.type FUN_a0060fc0, #function
FUN_a0060fc0:
! Piece 16 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	or  %g1, 0x400, %g1               ! set bit 0x400: level 10 allowed again
	st  %g1, [ %o4 ]                  ! write the interrupt mask back
	ret                               ! return to irq_entry
	restore                           ! delay slot: close the register window
	.size FUN_a0060fc0, .-FUN_a0060fc0
