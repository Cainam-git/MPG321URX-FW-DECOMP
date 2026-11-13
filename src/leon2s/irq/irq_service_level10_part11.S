! irq_service_level10_part11  (FUN_a0060f70)
!
! Call the source handler after the early acknowledge and advance to the next source.
! Note: Ghidra piece 11 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f70 @ 0xa0060f70  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f70
	.type FUN_a0060f70, #function
FUN_a0060f70:
! Piece 11 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	ld  [ %o3 + %o5 ], %g1            ! %g1 = the handler of this source
	call  %g1                         ! run the handler of the source
	nop                               ! delay slot: nothing
	inc  %l2                          ! next source number
	.size FUN_a0060f70, .-FUN_a0060f70
