! irq_service_level7_part2  (FUN_a0060dd0)
!
! Finish the mask and start setting bit 0x80 in the active-level register.
! Note: Ghidra piece 2 of the routine 0xA0060DC0..0xA0060E1B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 6 = 0xA0060DC0; bit 0x80 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060dd0 @ 0xa0060dd0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060dd0
	.type FUN_a0060dd0, #function
FUN_a0060dd0:
! Piece 2 of the level-7 service routine (0xA0060DC0..0xA0060E1B); see irq_service_level7_part1.S.
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	or  %o5, 0x28, %o4                ! %o4 = the active-level register 0x9F120028
	ld  [ %o4 ], %g1                  ! read the active-level register
	.size FUN_a0060dd0, .-FUN_a0060dd0
