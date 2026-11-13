! irq_service_level10_part8  (FUN_a0060f40)
!
! Load the source handler from the handler table and call it.
! Note: Ghidra piece 8 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f40 @ 0xa0060f40  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f40
	.type FUN_a0060f40, #function
FUN_a0060f40:
! Piece 8 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	or  %g1, 0x380, %o3               ! delay slot: %o3 = the handler table of level 10 (0xA8079380)
	ld  [ %o3 + %o5 ], %g1            ! %g1 = the handler of this source
	call  %g1                         ! run the handler of the source
	nop                               ! delay slot: nothing
	.size FUN_a0060f40, .-FUN_a0060f40
