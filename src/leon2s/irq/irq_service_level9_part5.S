! irq_service_level9_part5  (FUN_a0060eb0)
!
! Clear interrupt 9 in the LEON2 interrupt clear register and drop bit 0x200 from 0x9F120028.
! Note: Ghidra piece 5 of the routine 0xA0060E78..0xA0060ED3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 8 = 0xA0060E78; bit 0x200 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060eb0 @ 0xa0060eb0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060eb0
	.type FUN_a0060eb0, #function
FUN_a0060eb0:
! Piece 5 of the level-9 service routine (0xA0060E78..0xA0060ED3); see irq_service_level9_part1.S.
	st  %g1, [ %o3 ]                  ! write 0x200: clear level 9 in the LEON2 interrupt clear register
	ld  [ %o4 ], %g1                  ! read the active-level register
	and  %g1, -513, %g1               ! clear bit 0x200: level 9 no longer being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	.size FUN_a0060eb0, .-FUN_a0060eb0
