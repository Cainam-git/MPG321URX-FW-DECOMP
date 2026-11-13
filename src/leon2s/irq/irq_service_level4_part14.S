! irq_service_level4_part14  (FUN_a0060b80)
!
! Clear interrupt 4 in the second-level clear register and the LEON2 interrupt clear register.
! Note: Ghidra piece 14 of the routine 0xA0060AB4..0xA0060BB7, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 3 = 0xA0060AB4; masks bit 0x10 of LEON2 mask 0x9F100090
!   and calls table 0xA80787A8
!
! Matching notes
! --------------
! leon2s FUN_a0060b80 @ 0xa0060b80  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060b80
	.type FUN_a0060b80, #function
FUN_a0060b80:
! Piece 14 of the level-4 service routine (0xA0060AB4..0xA0060BB7); see irq_service_level4_part1.S.
	st  %o3, [ %g1 ]                  ! write bit 0x10 to register 0x9F120034 (end of the service)
	sethi  %hi(0x9f100000), %o4       ! %o4 = 0x9F100000 (LEON2 interrupt registers)
	or  %o4, 0x9c, %g1                ! %g1 = the LEON2 interrupt clear register
	st  %o3, [ %g1 ]                  ! write 0x10: clear level 4 in the LEON2 interrupt clear register
	.size FUN_a0060b80, .-FUN_a0060b80
