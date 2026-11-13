! irq_service_level1_part15  (FUN_a00609d0)
!
! Clear interrupt 1 in the LEON2 interrupt clear register and drop bit 0x2 from 0x9F120028.
! Note: Ghidra piece 15 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00609d0 @ 0xa00609d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609d0
	.type FUN_a00609d0, #function
FUN_a00609d0:
! Piece 15 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	st  %o3, [ %g1 ]                  ! write 0x2: clear level 1 in the LEON2 interrupt clear register
	or  %o5, 0x28, %o5                ! %o5 = the active-level register 0x9F120028
	ld  [ %o5 ], %g1                  ! read the active-level register
	and  %g1, -3, %g1                 ! clear bit 0x2: level 1 no longer being served
	.size FUN_a00609d0, .-FUN_a00609d0
