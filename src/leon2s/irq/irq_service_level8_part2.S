! irq_service_level8_part2  (FUN_a0060e20)
!
! Mask interrupt 8 (bit 0x100) in the LEON2 interrupt mask.
! Note: Ghidra piece 2 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e20 @ 0xa0060e20  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e20
	.type FUN_a0060e20, #function
FUN_a0060e20:
! Piece 2 of the level-8 service routine (0xA0060E1C..0xA0060E77); see irq_service_level8_part1.S.
	or  %o3, 0x90, %o2                ! %o2 = the LEON2 interrupt mask register
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	and  %g1, -257, %g1               ! clear bit 0x100: level 8 masked while it is served
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	.size FUN_a0060e20, .-FUN_a0060e20
