! irq_service_level6_part17  (FUN_a0060db0)
!
! Unmask interrupt 6 in the LEON2 interrupt mask and return.
! Note: Ghidra piece 17 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060db0 @ 0xa0060db0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060db0
	.type FUN_a0060db0, #function
FUN_a0060db0:
! Piece 17 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	or  %g1, 0x40, %g1                ! set bit 0x40: level 6 allowed again
	st  %g1, [ %o4 ]                  ! write the interrupt mask back
	ret                               ! return to irq_entry
	restore                           ! delay slot: close the register window
	.size FUN_a0060db0, .-FUN_a0060db0
