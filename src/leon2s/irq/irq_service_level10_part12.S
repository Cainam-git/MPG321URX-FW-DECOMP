! irq_service_level10_part12  (FUN_a0060f80)
!
! Loop over both sources, then start the end-of-service clear.
! Note: Ghidra piece 12 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f80 @ 0xa0060f80  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f80
	.type FUN_a0060f80, #function
FUN_a0060f80:
! Piece 12 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	cmp  %l2, 1                       ! more sources? (loop while the number is at most 1)
	bleu ext_a0060f24                 ! yes: back to the start of the loop (0xA0060F24)
	mov  1, %g1                       ! delay slot: %g1 = 1, shifted below into the bit of the source
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060f80, .-FUN_a0060f80
