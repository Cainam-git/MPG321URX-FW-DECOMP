! irq_service_level3_part3  (FUN_a0060a70)
!
! Set bit 0x8 in the second-level register 0x9F120028.
! Note: Ghidra piece 3 of the routine 0xA0060A58..0xA0060AB3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 2 = 0xA0060A58; bit 0x8 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a70 @ 0xa0060a70  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a70
	.type FUN_a0060a70, #function
FUN_a0060a70:
! Piece 3 of the level-3 service routine (0xA0060A58..0xA0060AB3); see irq_service_level3_part1.S.
	or  %o5, 0x28, %o4                ! %o4 = the active-level register 0x9F120028
	ld  [ %o4 ], %g1                  ! read the active-level register
	or  %g1, 8, %g1                   ! set bit 0x8: level 3 is being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	.size FUN_a0060a70, .-FUN_a0060a70
