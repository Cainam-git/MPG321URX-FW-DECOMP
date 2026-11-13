! irq_service_level8_part3  (FUN_a0060e30)
!
! Finish the mask and set bit 0x100 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e30 @ 0xa0060e30  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e30
	.type FUN_a0060e30, #function
FUN_a0060e30:
! Piece 3 of the level-8 service routine (0xA0060E1C..0xA0060E77); see irq_service_level8_part1.S.
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	or  %o5, 0x28, %o4                ! %o4 = the active-level register 0x9F120028
	ld  [ %o4 ], %g1                  ! read the active-level register
	or  %g1, 0x100, %g1               ! set bit 0x100: level 8 is being served
	.size FUN_a0060e30, .-FUN_a0060e30
