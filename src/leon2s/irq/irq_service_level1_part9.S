! irq_service_level1_part9  (FUN_a0060970)
!
! Choose the acknowledge order for the source and call its handler.
! Note: Ghidra piece 9 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a0060970 @ 0xa0060970  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060970
	.type FUN_a0060970, #function
FUN_a0060970:
! Piece 9 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	btst  %l3, %l0                    ! does its handler run before the acknowledge?
	be ext_a0060998                   ! no: acknowledge first, then run it (0xA0060998)
	sethi  %hi(0x9f120000), %g1       ! delay slot: %g1 = 0x9F120000 (second-level interrupt registers)
	call  %o5                         ! run the handler of the source
	.size FUN_a0060970, .-FUN_a0060970
