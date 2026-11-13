! irq_service_level2_part4  (FUN_a0060a20)
!
! Finish 0x9F120028 and clear interrupt 2 in the second-level clear register.
! Note: Ghidra piece 4 of the routine 0xA00609FC..0xA0060A57, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a20 @ 0xa0060a20  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a20
	.type FUN_a0060a20, #function
FUN_a0060a20:
! Piece 4 of the level-2 service routine (0xA00609FC..0xA0060A57); see irq_service_level2_part1.S.
	st  %g1, [ %o4 ]                  ! write the active-level register back
	mov  4, %g1                       ! %g1 = 0x4, the bit of interrupt level 2
	or  %o5, 0x34, %o5                ! %o5 = register 0x9F120034, written at the end of every service
	st  %g1, [ %o5 ]                  ! write bit 0x4 to register 0x9F120034 (end of the service)
	.size FUN_a0060a20, .-FUN_a0060a20
