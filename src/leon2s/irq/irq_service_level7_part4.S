! irq_service_level7_part4  (FUN_a0060df0)
!
! Clear interrupt 7 in the second-level clear register and the LEON2 interrupt clear register.
! Note: Ghidra piece 4 of the routine 0xA0060DC0..0xA0060E1B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 6 = 0xA0060DC0; bit 0x80 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060df0 @ 0xa0060df0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060df0
	.type FUN_a0060df0, #function
FUN_a0060df0:
! Piece 4 of the level-7 service routine (0xA0060DC0..0xA0060E1B); see irq_service_level7_part1.S.
	st  %g1, [ %o5 ]                  ! write bit 0x80 to register 0x9F120034 (end of the service)
	or  %o3, 0x9c, %o3                ! %o3 = the LEON2 interrupt clear register
	st  %g1, [ %o3 ]                  ! write 0x80: clear level 7 in the LEON2 interrupt clear register
	ld  [ %o4 ], %g1                  ! read the active-level register
	.size FUN_a0060df0, .-FUN_a0060df0
