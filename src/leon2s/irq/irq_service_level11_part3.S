! irq_service_level11_part3  (FUN_a0060ff0)
!
! Mark interrupt 11 in service, clear it at both levels, then unmask it and return.
! Note: Ghidra piece 3 of the routine 0xA0060FD0..0xA006102B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 10 = 0xA0060FD0; masks bit 0x800 of 0x9F100090, clears it
!   in 0x9F120034 / 0x9F10009C and unmasks it
!
! Matching notes
! --------------
! leon2s FUN_a0060ff0 @ 0xa0060ff0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ff0
	.type FUN_a0060ff0, #function
FUN_a0060ff0:
! Piece 3 of the level-11 service routine (0xA0060FD0..0xA006102B); see irq_service_level11_part1.S.
	or  %g1, 0x800, %g1               ! set bit 0x800: level 11 is being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	mov  0x800, %g1                   ! %g1 = 0x800, the bit of interrupt level 11
	or  %o5, 0x34, %o5                ! %o5 = register 0x9F120034, written at the end of every service
	st  %g1, [ %o5 ]                  ! write bit 0x800 to register 0x9F120034 (end of the service)
	or  %o3, 0x9c, %o3                ! %o3 = the LEON2 interrupt clear register
	st  %g1, [ %o3 ]                  ! write 0x800: clear level 11 in the LEON2 interrupt clear register
	ld  [ %o4 ], %g1                  ! read the active-level register
	and  %g1, -2049, %g1              ! clear bit 0x800: level 11 no longer being served
	st  %g1, [ %o4 ]                  ! write the active-level register back
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	or  %g1, 0x800, %g1               ! set bit 0x800: level 11 allowed again
	st  %g1, [ %o2 ]                  ! write the interrupt mask back
	retl                              ! return to irq_entry (leaf routine: no register window)
	nop                               ! delay slot: nothing
	.size FUN_a0060ff0, .-FUN_a0060ff0
