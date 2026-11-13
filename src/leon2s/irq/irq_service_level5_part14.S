! irq_service_level5_part14  (FUN_a0060c80)
!
! Clear interrupt 5 in the second-level clear register and address the LEON2 interrupt clear register.
! Note: Ghidra piece 14 of the routine 0xA0060BB8..0xA0060CBB, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 4 = 0xA0060BB8; masks bit 0x20 of LEON2 mask 0x9F100090
!   and calls table 0xA8078770
!
! Matching notes
! --------------
! leon2s FUN_a0060c80 @ 0xa0060c80  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060c80
	.type FUN_a0060c80, #function
FUN_a0060c80:
! Piece 14 of the level-5 service routine (0xA0060BB8..0xA0060CBB); see irq_service_level5_part1.S.
	mov  0x20, %o3                    ! %o3 = 0x20, the bit of interrupt level 5
	st  %o3, [ %g1 ]                  ! write bit 0x20 to register 0x9F120034 (end of the service)
	sethi  %hi(0x9f100000), %o4       ! %o4 = 0x9F100000 (LEON2 interrupt registers)
	or  %o4, 0x9c, %g1                ! %g1 = the LEON2 interrupt clear register
	.size FUN_a0060c80, .-FUN_a0060c80
