! irq_service_level7_part3  (FUN_a0060de0)
!
! Finish 0x9F120028 and start clearing interrupt 7 in the second-level clear register.
! Note: Ghidra piece 3 of the routine 0xA0060DC0..0xA0060E1B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 6 = 0xA0060DC0; bit 0x80 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060de0 @ 0xa0060de0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060de0
	.type FUN_a0060de0, #function
FUN_a0060de0:
! Piece 3 of the level-7 service routine (0xA0060DC0..0xA0060E1B); see irq_service_level7_part1.S.
	or  %g1, 0x80, %g1                ! set bit 0x80: level 7 is being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	mov  0x80, %g1                    ! %g1 = 0x80, the bit of interrupt level 7
	or  %o5, 0x34, %o5                ! %o5 = register 0x9F120034, written at the end of every service
	.size FUN_a0060de0, .-FUN_a0060de0
