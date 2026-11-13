! irq_service_level6_part10  (FUN_a0060d40)
!
! Call the handler, then start acknowledging the source in the status register.
! Note: Ghidra piece 10 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d40 @ 0xa0060d40  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d40
	.type FUN_a0060d40, #function
FUN_a0060d40:
! Piece 10 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	call  %o5                         ! run the handler of the source
	nop                               ! delay slot: nothing
	sethi  %hi(0x9f120000), %g1       ! %g1 = 0x9F120000 (second-level interrupt registers)
	or  %g1, 0x84, %g1                ! %g1 = the source status register of level 6 (0x9F120084)
	.size FUN_a0060d40, .-FUN_a0060d40
