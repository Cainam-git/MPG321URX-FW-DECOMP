! irq_service_level6_part14  (FUN_a0060d80)
!
! Clear interrupt 6 in the second-level clear register.
! Note: Ghidra piece 14 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d80 @ 0xa0060d80  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d80
	.type FUN_a0060d80, #function
FUN_a0060d80:
! Piece 14 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	or  %o5, 0x34, %g1                ! %g1 = register 0x9F120034, written at the end of every service
	mov  0x40, %o3                    ! %o3 = 0x40, the bit of interrupt level 6
	st  %o3, [ %g1 ]                  ! write bit 0x40 to register 0x9F120034 (end of the service)
	sethi  %hi(0x9f100000), %o4       ! %o4 = 0x9F100000 (LEON2 interrupt registers)
	.size FUN_a0060d80, .-FUN_a0060d80
