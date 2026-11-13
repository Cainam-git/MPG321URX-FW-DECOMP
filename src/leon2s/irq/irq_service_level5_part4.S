! irq_service_level5_part4  (FUN_a0060be0)
!
! Finish 0x9F120028 and read the interrupt-5 source status.
! Note: Ghidra piece 4 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060be0 @ 0xa0060be0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060be0
	.type FUN_a0060be0, #function
FUN_a0060be0:
! Piece 4 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	st  %g1, [ %o5 ]                  ! write the active-level register back
	or  %o4, 0x80, %g1                ! %g1 = the source status register of level 5 (0x9F120080)
	ld  [ %g1 ], %l1                  ! %l1 = the sources of level 5 that are signalling
	or  %o4, 0x48, %o4                ! %o4 = the source mask register of level 5 (0x9F120048)
	.size FUN_a0060be0, .-FUN_a0060be0
