! irq_service_level6_part5  (FUN_a0060cf0)
!
! Read the its source mask and drop masked sources.
! Note: Ghidra piece 5 of the routine 0xA0060CBC..0xA0060DBF, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 5 = 0xA0060CBC; masks bit 0x40 of LEON2 mask 0x9F100090
!   and calls table 0xA8079388
!
! Matching notes
! --------------
! leon2s FUN_a0060cf0 @ 0xa0060cf0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060cf0
	.type FUN_a0060cf0, #function
FUN_a0060cf0:
! Piece 5 of the level-6 service routine (0xA0060CBC..0xA0060DBF); see irq_service_level6_part1.S.
	or  %o4, 0x4c, %o4                ! %o4 = the source mask register of level 6 (0x9F12004C)
	ld  [ %o4 ], %g1                  ! %g1 = source mask (a set bit in the low half masks a source)
	ld  [ %o4 ], %o5                  ! read it again, for its upper half
	andn  %l1, %g1, %l1               ! drop the masked sources
	.size FUN_a0060cf0, .-FUN_a0060cf0
