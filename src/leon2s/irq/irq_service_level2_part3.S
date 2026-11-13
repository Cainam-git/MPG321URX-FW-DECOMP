! irq_service_level2_part3  (FUN_a0060a10)
!
! Finish the mask and set bit 0x4 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA00609FC..0xA0060A57, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a10 @ 0xa0060a10  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a10
	.type FUN_a0060a10, #function
FUN_a0060a10:
! Piece 3 of the level-2 service routine (0xA00609FC..0xA0060A57); see irq_service_level2_part1.S.
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	or  %o5, 0x28, %o4                ! %o4 = the active-level register 0x9F120028
	ld  [ %o4 ], %g1                  ! read the active-level register
	or  %g1, 4, %g1                   ! set bit 0x4: level 2 is being served
	.size FUN_a0060a10, .-FUN_a0060a10
