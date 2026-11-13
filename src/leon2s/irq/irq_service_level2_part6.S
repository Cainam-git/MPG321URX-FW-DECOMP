! irq_service_level2_part6  (FUN_a0060a40)
!
! Drop bit 0x4 from 0x9F120028 and unmask interrupt 2 in the LEON2 interrupt mask.
! Note: Ghidra piece 6 of the routine 0xA00609FC..0xA0060A57, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a40 @ 0xa0060a40  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a40
	.type FUN_a0060a40, #function
FUN_a0060a40:
! Piece 6 of the level-2 service routine (0xA00609FC..0xA0060A57); see irq_service_level2_part1.S.
	st  %g1, [ %o4 ]                  ! write the active-level register back
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	or  %g1, 4, %g1                   ! set bit 0x4: level 2 allowed again
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	.size FUN_a0060a40, .-FUN_a0060a40
