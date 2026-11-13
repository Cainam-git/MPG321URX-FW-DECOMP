! irq_service_level6_part2  (FUN_a0060cc0)
!
! Mask interrupt 6 (bit 0x40) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060cc0 @ 0xa0060cc0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060cc0
	.type FUN_a0060cc0, #function
FUN_a0060cc0:
! Piece 2 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	sethi  %hi(0x9f100000), %o5       ! %o5 = 0x9F100000 (LEON2 interrupt registers)
	or  %o5, 0x90, %o5                ! %o5 = the LEON2 interrupt mask register
	ld  [ %o5 ], %g1                  ! read the interrupt mask
	and  %g1, -65, %g1                ! clear bit 0x40: level 6 masked while it is served
	.size FUN_a0060cc0, .-FUN_a0060cc0
