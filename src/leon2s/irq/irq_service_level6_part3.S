! irq_service_level6_part3  (FUN_a0060cd0)
!
! Finish the mask and start setting bit 0x40 in the active-level register.
! Note: Ghidra piece 3 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060cd0 @ 0xa0060cd0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060cd0
	.type FUN_a0060cd0, #function
FUN_a0060cd0:
! Piece 3 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	st  %g1, [ %o5 ]                  ! write the interrupt mask back
	sethi  %hi(0x9f120000), %o4       ! %o4 = 0x9F120000 (second-level interrupt registers)
	or  %o4, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	.size FUN_a0060cd0, .-FUN_a0060cd0
