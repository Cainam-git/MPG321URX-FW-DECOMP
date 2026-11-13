! irq_service_level6_part13  (FUN_a0060d70)
!
! Loop over the five sources, then start clearing interrupt 6.
! Note: Ghidra piece 13 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d70 @ 0xa0060d70  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d70
	.type FUN_a0060d70, #function
FUN_a0060d70:
! Piece 13 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	cmp  %l2, 4                       ! more sources? (loop while the number is at most 4)
	bleu ext_a0060d0c                 ! yes: back to the start of the loop (0xA0060D0C)
	mov  1, %g1                       ! delay slot: %g1 = 1, shifted below into the bit of the source
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060d70, .-FUN_a0060d70
