! irq_service_level5_part15  (FUN_a0060c90)
!
! Clear interrupt 5 in the LEON2 interrupt clear register and start dropping bit 0x20 from 0x9F120028.
! Note: Ghidra piece 15 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c90 @ 0xa0060c90  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c90
	.type FUN_a0060c90, #function
FUN_a0060c90:
! Piece 15 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	st  %o3, [ %g1 ]                  ! write 0x20: clear level 5 in the LEON2 interrupt clear register
	or  %o5, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	and  %g1, -33, %g1                ! clear bit 0x20: level 5 no longer being served
	.size FUN_a0060c90, .-FUN_a0060c90
