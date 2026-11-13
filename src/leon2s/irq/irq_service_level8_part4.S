! irq_service_level8_part4  (FUN_a0060e40)
!
! Finish 0x9F120028 and clear interrupt 8 in the second-level clear register.
! Note: Ghidra piece 4 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e40 @ 0xa0060e40  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e40
	.type FUN_a0060e40, #function
FUN_a0060e40:
! Piece 4 of the level-8 service routine (0xA0060E1C..0xA0060E77); see irq_service_level8_part1.S.
	st  %g1, [ %o4 ]                  ! write the active-level register back
	mov  0x100, %g1                   ! %g1 = 0x100, the bit of interrupt level 8
	or  %o5, 0x34, %o5                ! %o5 = register 0x9F120034, written at the end of every service
	st  %g1, [ %o5 ]                  ! write bit 0x100 to register 0x9F120034 (end of the service)
	.size FUN_a0060e40, .-FUN_a0060e40
