! irq_service_level7_part5  (FUN_a0060e00)
!
! Drop bit 0x80 from 0x9F120028 and start unmasking interrupt 7.
! Note: Ghidra piece 5 of the routine 0xA0060DC0..0xA0060E1B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 6 = 0xA0060DC0; bit 0x80 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e00 @ 0xa0060e00  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e00
	.type FUN_a0060e00, #function
FUN_a0060e00:
! Piece 5 of the level-7 service routine (0xA0060DC0..0xA0060E1B); see irq_service_level7_part1.S.
	and  %g1, -129, %g1               ! clear bit 0x80: level 7 no longer being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	or  %g1, 0x80, %g1                ! set bit 0x80: level 7 allowed again
	.size FUN_a0060e00, .-FUN_a0060e00
