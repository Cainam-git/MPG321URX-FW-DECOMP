! irq_service_level2_part2  (FUN_a0060a00)
!
! Mask interrupt 2 (bit 0x4) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA00609FC..0xA0060A57, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a00 @ 0xa0060a00  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a00
	.type FUN_a0060a00, #function
FUN_a0060a00:
! Piece 2 of the level-2 service routine (0xA00609FC..0xA0060A57); see irq_service_level2_part1.S.
	or  %o3, 0x90, %o2                ! %o2 = the LEON2 interrupt mask register
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	and  %g1, -5, %g1                 ! clear bit 0x4: level 2 masked while it is served
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060a00, .-FUN_a0060a00
