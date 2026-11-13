! irq_service_level9_part2  (FUN_a0060e80)
!
! Mask interrupt 9 (bit 0x200) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA0060E78..0xA0060ED3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 8 = 0xA0060E78; bit 0x200 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e80 @ 0xa0060e80  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e80
	.type FUN_a0060e80, #function
FUN_a0060e80:
! Piece 2 of the level-9 service routine (0xA0060E78..0xA0060ED3); see irq_service_level9_part1.S.
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	and  %g1, -513, %g1               ! clear bit 0x200: level 9 masked while it is served
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	.size FUN_a0060e80, .-FUN_a0060e80
