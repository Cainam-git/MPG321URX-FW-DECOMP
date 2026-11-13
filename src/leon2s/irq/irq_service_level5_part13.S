! irq_service_level5_part13  (FUN_a0060c70)
!
! Loop over the fourteen sources, then start clearing interrupt 5.
! Note: Ghidra piece 13 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c70 @ 0xa0060c70  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c70
	.type FUN_a0060c70, #function
FUN_a0060c70:
! Piece 13 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	bleu ext_a0060c08                 ! yes: back to the start of the loop (0xA0060C08)
	mov  1, %g1                       ! delay slot: %g1 = 1, shifted below into the bit of the source
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	or  %o5, 0x34, %g1                ! %g1 = register 0x9F120034, written at the end of every service
	.size FUN_a0060c70, .-FUN_a0060c70
