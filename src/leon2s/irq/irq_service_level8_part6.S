! irq_service_level8_part6  (FUN_a0060e60)
!
! Drop bit 0x100 from 0x9F120028 and unmask interrupt 8 in the LEON2 interrupt mask.
! Note: Ghidra piece 6 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e60 @ 0xa0060e60  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e60
	.type FUN_a0060e60, #function
FUN_a0060e60:
! Piece 6 of the level-8 service routine (0xA0060E1C..0xA0060E77); see irq_service_level8_part1.S.
	st  %g1, [ %o4 ]                  ! write the active-level register back
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	or  %g1, 0x100, %g1               ! set bit 0x100: level 8 allowed again
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	.size FUN_a0060e60, .-FUN_a0060e60
