! irq_service_level3_part2  (FUN_a0060a60)
!
! Mask interrupt 3 (bit 0x8) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA0060A58..0xA0060AB3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 2 = 0xA0060A58; bit 0x8 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a60 @ 0xa0060a60  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a60
	.type FUN_a0060a60, #function
FUN_a0060a60:
! Piece 2 of the level-3 service routine (0xA0060A58..0xA0060AB3); see irq_service_level3_part1.S.
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	and  %g1, -9, %g1                 ! clear bit 0x8: level 3 masked while it is served
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	.size FUN_a0060a60, .-FUN_a0060a60
