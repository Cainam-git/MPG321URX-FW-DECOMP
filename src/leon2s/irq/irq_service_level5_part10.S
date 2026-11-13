! irq_service_level5_part10  (FUN_a0060c40)
!
! Acknowledge the source in the status register after its handler returned.
! Note: Ghidra piece 10 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c40 @ 0xa0060c40  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c40
	.type FUN_a0060c40, #function
FUN_a0060c40:
! Piece 10 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	nop                               ! delay slot: nothing
	sethi  %hi(0x9f120000), %g1       ! %g1 = 0x9F120000 (second-level interrupt registers)
	or  %g1, 0x80, %g1                ! %g1 = the source status register of level 5 (0x9F120080)
	st  %l0, [ %g1 ]                  ! acknowledge: write the source bit to the level-5 status register
	.size FUN_a0060c40, .-FUN_a0060c40
