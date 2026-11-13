! irq_service_level3_part4  (FUN_a0060a80)
!
! Clear interrupt 3 in the second-level clear register and address the LEON2 interrupt clear register.
! Note: Ghidra piece 4 of the routine 0xA0060A58..0xA0060AB3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 2 = 0xA0060A58; bit 0x8 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060a80 @ 0xa0060a80  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060a80
	.type FUN_a0060a80, #function
FUN_a0060a80:
! Piece 4 of the level-3 service routine (0xA0060A58..0xA0060AB3); see irq_service_level3_part1.S.
	mov  8, %g1                       ! %g1 = 0x8, the bit of interrupt level 3
	or  %o5, 0x34, %o5                ! %o5 = register 0x9F120034, written at the end of every service
	st  %g1, [ %o5 ]                  ! write bit 0x8 to register 0x9F120034 (end of the service)
	or  %o3, 0x9c, %o3                ! %o3 = the LEON2 interrupt clear register
	.size FUN_a0060a80, .-FUN_a0060a80
