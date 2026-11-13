! irq_service_level1_part4  (FUN_a0060920)
!
! Read the interrupt-1 source status and address its source mask.
! Note: Ghidra piece 4 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060920 @ 0xa0060920  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060920
	.type FUN_a0060920, #function
FUN_a0060920:
! Piece 4 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x70, %g1                ! %g1 = the source status register of level 1 (0x9F120070)
	ld  [ %g1 ], %l1                  ! %l1 = the sources of level 1 that are signalling
	or  %o4, 0x38, %o4                ! %o4 = the source mask register of level 1 (0x9F120038)
	.size FUN_a0060920, .-FUN_a0060920
