! irq_service_level1_part8  (FUN_a0060960)
!
! Skip sources without a registered handler.
! Note: Ghidra piece 8 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060960 @ 0xa0060960  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060960
	.type FUN_a0060960, #function
FUN_a0060960:
! Piece 8 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	ld  [ %g1 + %o5 ], %o5            ! %o5 = the handler of this source
	cmp  %o5, 0                       ! is there a handler for it?
	be,a ext_a00609ac                 ! no handler: on to the next source (0xA00609AC)
	inc  %l2                          ! delay slot, runs only when the branch is taken: next source number
	.size FUN_a0060960, .-FUN_a0060960
