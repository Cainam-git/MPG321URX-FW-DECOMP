! irq_service_level9_part3  (FUN_a0060e90)
!
! Set bit 0x200 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA0060E78..0xA0060ED3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 8 = 0xA0060E78; bit 0x200 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e90 @ 0xa0060e90  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e90
	.type FUN_a0060e90, #function
FUN_a0060e90:
! Piece 3 of the level-9 service routine (0xA0060E78..0xA0060ED3); see irq_service_level9_part1.S.
	or  %o5, 0x28, %o4                ! %o4 = the active-level register 0x9F120028
	ld  [ %o4 ], %g1                  ! read the active-level register
	or  %g1, 0x200, %g1               ! set bit 0x200: level 9 is being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	.size FUN_a0060e90, .-FUN_a0060e90
