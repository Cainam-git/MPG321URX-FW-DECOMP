! irq_service_level10_part13  (FUN_a0060f90)
!
! Clear interrupt 10 in the second-level clear register and prepare the LEON2 block.
! Note: Ghidra piece 13 of the routine 0xA0060ED4..0xA0060FCF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 9 = 0xA0060ED4; masks bit 0x400 of LEON2 mask 0x9F100090
!   and calls table 0xA8079380
!
! Matching notes
! --------------
! leon2s FUN_a0060f90 @ 0xa0060f90  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060f90
	.type FUN_a0060f90, #function
FUN_a0060f90:
! Piece 13 of the level-10 service routine (0xA0060ED4..0xA0060FCF); see irq_service_level10_part1.S.
	or  %o5, 0x34, %g1                ! %g1 = register 0x9F120034, written at the end of every service
	mov  0x400, %o3                   ! %o3 = 0x400, the bit of interrupt level 10
	st  %o3, [ %g1 ]                  ! write bit 0x400 to register 0x9F120034 (end of the service)
	sethi  %hi(0x9f100000), %o4       ! %o4 = 0x9F100000 (LEON2 interrupt registers)
	.size FUN_a0060f90, .-FUN_a0060f90
