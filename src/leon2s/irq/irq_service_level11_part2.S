! irq_service_level11_part2  (FUN_a0060fe0)
!
! Finish the mask and start setting bit 0x800 in the active-level register.
! Note: Ghidra piece 2 of the routine 0xA0060FD0..0xA006102B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 10 = 0xA0060FD0; masks bit 0x800 of 0x9F100090, clears it
!   in 0x9F120034 / 0x9F10009C and unmasks it
!
! Matching notes
! --------------
! leon2s FUN_a0060fe0 @ 0xa0060fe0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060fe0
	.type FUN_a0060fe0, #function
FUN_a0060fe0:
! Piece 2 of the level-11 service routine (0xA0060FD0..0xA006102B); see irq_service_level11_part1.S.
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	or  %o5, 0x28, %o4                ! %o4 = the active-level register 0x9F120028
	ld  [ %o4 ], %g1                  ! read the active-level register
	.size FUN_a0060fe0, .-FUN_a0060fe0
