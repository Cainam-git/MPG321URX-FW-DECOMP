! irq_service_level5_part9  (FUN_a0060c30)
!
! Choose the acknowledge order for the source and call its handler.
! Note: Ghidra piece 9 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c30 @ 0xa0060c30  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c30
	.type FUN_a0060c30, #function
FUN_a0060c30:
! Piece 9 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	btst  %l3, %l0                    ! does its handler run before the acknowledge?
	be ext_a0060c58                   ! no: acknowledge first, then run it (0xA0060C58)
	sethi  %hi(0x9f120000), %g1       ! delay slot: %g1 = 0x9F120000 (second-level interrupt registers)
	call  %o5                         ! run the handler of the source
	.size FUN_a0060c30, .-FUN_a0060c30
