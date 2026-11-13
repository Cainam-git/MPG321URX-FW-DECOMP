! irq_service_level1_part14  (FUN_a00609c0)
!
! Write the clear to the second-level clear register and address the LEON2 interrupt clear register.
! Note: Ghidra piece 14 of the routine 0xA00608F8..0xA00609FB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 0 = 0xA00608F8; masks bit 0x2 of LEON2 mask 0x9F100090 and
!   calls table 0xA80787C4
!
! Matching notes
! --------------
! leon2s FUN_a00609c0 @ 0xa00609c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609c0
	.type FUN_a00609c0, #function
FUN_a00609c0:
! Piece 14 of the level-1 service routine (0xA00608F8..0xA00609FB); see irq_service_level1_part1.S.
	mov  2, %o3                       ! %o3 = 0x2, the bit of interrupt level 1
	st  %o3, [ %g1 ]                  ! write bit 0x2 to register 0x9F120034 (end of the service)
	sethi  %hi(0x9f100000), %o4       ! %o4 = 0x9F100000 (LEON2 interrupt registers)
	or  %o4, 0x9c, %g1                ! %g1 = the LEON2 interrupt clear register
	.size FUN_a00609c0, .-FUN_a00609c0
