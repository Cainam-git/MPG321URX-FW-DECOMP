! irq_service_level6_part4  (FUN_a0060ce0)
!
! Finish 0x9F120028 and read the interrupt-6 source status.
! Note: Ghidra piece 4 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060ce0 @ 0xa0060ce0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ce0
	.type FUN_a0060ce0, #function
FUN_a0060ce0:
! Piece 4 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	or  %g1, 0x40, %g1                ! set bit 0x40: level 6 is being served
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x84, %g1                ! %g1 = the source status register of level 6 (0x9F120084)
	ld  [ %g1 ], %l1                  ! %l1 = the sources of level 6 that are signalling
	.size FUN_a0060ce0, .-FUN_a0060ce0
