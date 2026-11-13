! irq_service_level6_part16  (FUN_a0060da0)
!
! Drop bit 0x40 from 0x9F120028 and address the LEON2 interrupt mask.
! Note: Ghidra piece 16 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060da0 @ 0xa0060da0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060da0
	.type FUN_a0060da0, #function
FUN_a0060da0:
! Piece 16 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	and  %g1, -65, %g1                ! clear bit 0x40: level 6 no longer being served
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x90, %o4                ! %o4 = the LEON2 interrupt mask register
	ld  [ %o4 ], %g1                  ! read the interrupt mask
	.size FUN_a0060da0, .-FUN_a0060da0
