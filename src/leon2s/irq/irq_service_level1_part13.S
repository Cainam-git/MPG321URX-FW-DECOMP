! irq_service_level1_part13  (FUN_a00609b0)
!
! Loop over the six sources, then address the second-level clear register.
! Note: Ghidra piece 13 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00609b0 @ 0xa00609b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609b0
	.type FUN_a00609b0, #function
FUN_a00609b0:
! Piece 13 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	bleu ext_a0060948                 ! yes: back to the start of the loop (0xA0060948)
	mov  1, %g1                       ! delay slot: %g1 = 1, shifted below into the bit of the source
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	or  %o5, 0x34, %g1                ! %g1 = register 0x9F120034, written at the end of every service
	.size FUN_a00609b0, .-FUN_a00609b0
