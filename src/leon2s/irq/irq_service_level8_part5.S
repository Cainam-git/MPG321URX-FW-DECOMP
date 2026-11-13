! irq_service_level8_part5  (FUN_a0060e50)
!
! Clear interrupt 8 in the LEON2 interrupt clear register and start dropping bit 0x100.
! Note: Ghidra piece 5 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e50 @ 0xa0060e50  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e50
	.type FUN_a0060e50, #function
FUN_a0060e50:
! Piece 5 of the level-8 service routine (0xA0060E1C..0xA0060E77); see irq_service_level8_part1.S.
	or  %o3, 0x9c, %o3                ! %o3 = the LEON2 interrupt clear register
	st  %g1, [ %o3 ]                  ! write 0x100: clear level 8 in the LEON2 interrupt clear register
	ld  [ %o4 ], %g1                  ! read the active-level register
	and  %g1, -257, %g1               ! clear bit 0x100: level 8 no longer being served
	.size FUN_a0060e50, .-FUN_a0060e50
