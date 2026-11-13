! irq_service_level3_part5  (FUN_a0060a90)
!
! Clear interrupt 3 in the LEON2 interrupt clear register and drop bit 0x8 from 0x9F120028.
! Note: Ghidra piece 5 of the routine 0xA0060A58..0xA0060AB3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 2 = 0xA0060A58; bit 0x8 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a90 @ 0xa0060a90  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a90
	.type FUN_a0060a90, #function
FUN_a0060a90:
! Piece 5 of the level-3 service routine (0xA0060A58..0xA0060AB3); see irq_service_level3_part1.S.
	st  %g1, [ %o3 ]                  ! write 0x8: clear level 3 in the LEON2 interrupt clear register
	ld  [ %o4 ], %g1                  ! read the active-level register
	and  %g1, -9, %g1                 ! clear bit 0x8: level 3 no longer being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	.size FUN_a0060a90, .-FUN_a0060a90
