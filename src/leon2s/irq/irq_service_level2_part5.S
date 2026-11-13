! irq_service_level2_part5  (FUN_a0060a30)
!
! Clear interrupt 2 in the LEON2 interrupt clear register and start dropping bit 0x4.
! Note: Ghidra piece 5 of the routine 0xA00609FC..0xA0060A57, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a30 @ 0xa0060a30  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a30
	.type FUN_a0060a30, #function
FUN_a0060a30:
! Piece 5 of the level-2 service routine (0xA00609FC..0xA0060A57); see irq_service_level2_part1.S.
	or  %o3, 0x9c, %o3                ! %o3 = the LEON2 interrupt clear register
	st  %g1, [ %o3 ]                  ! write 0x4: clear level 2 in the LEON2 interrupt clear register
	ld  [ %o4 ], %g1                  ! read the active-level register
	and  %g1, -5, %g1                 ! clear bit 0x4: level 2 no longer being served
	.size FUN_a0060a30, .-FUN_a0060a30
