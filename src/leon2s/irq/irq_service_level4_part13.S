! irq_service_level4_part13  (FUN_a0060b70)
!
! Start clearing interrupt 4 in the second-level clear register.
! Note: Ghidra piece 13 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b70 @ 0xa0060b70  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b70
	.type FUN_a0060b70, #function
FUN_a0060b70:
! Piece 13 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	mov  1, %g1                       ! delay slot: %g1 = 1, shifted below into the bit of the source
	sethi  %hi(0x9f120000), %o5       ! %o5 = 0x9F120000 (second-level interrupt registers)
	or  %o5, 0x34, %g1                ! %g1 = register 0x9F120034, written at the end of every service
	mov  0x10, %o3                    ! %o3 = 0x10, the bit of interrupt level 4
	.size FUN_a0060b70, .-FUN_a0060b70
