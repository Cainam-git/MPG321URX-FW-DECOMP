! irq_service_level4_part9  (FUN_a0060b30)
!
! Call the source handler (acknowledge-after-call order).
! Note: Ghidra piece 9 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b30 @ 0xa0060b30  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b30
	.type FUN_a0060b30, #function
FUN_a0060b30:
! Piece 9 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	be ext_a0060b54                   ! no: acknowledge first, then run it (0xA0060B54)
	sethi  %hi(0x9f120000), %g1       ! delay slot: %g1 = 0x9F120000 (second-level interrupt registers)
	call  %o5                         ! run the handler of the source
	nop                               ! delay slot: nothing
	.size FUN_a0060b30, .-FUN_a0060b30
