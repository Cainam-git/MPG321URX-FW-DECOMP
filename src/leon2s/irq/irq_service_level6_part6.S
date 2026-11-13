! irq_service_level6_part6  (FUN_a0060d00)
!
! Take the acknowledge-after-call flags and start the source loop.
! Note: Ghidra piece 6 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060d00 @ 0xa0060d00  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060d00
	.type FUN_a0060d00, #function
FUN_a0060d00:
! Piece 6 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	srl  %o5, 0x10, %l3               ! %l3 = upper half: sources to run before the acknowledge
	or %g0, 0, %l2                    ! %l2 = 0: number of the first source
	mov  1, %g1                       ! %g1 = 1, shifted below into the bit of the source
	sll  %g1, %l2, %l0                ! %l0 = bit of the source numbered %l2
	.size FUN_a0060d00, .-FUN_a0060d00
