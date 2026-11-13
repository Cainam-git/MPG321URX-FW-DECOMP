! irq_service_level9_part7  (FUN_a0060ed0)
!
! Last word (a nop) of the level-9 interrupt service routine.
! Note: Ghidra piece 7 of the routine 0xA0060E78..0xA0060ED3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 8 = 0xA0060E78; bit 0x200 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060ed0 @ 0xa0060ed0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ed0
	.type FUN_a0060ed0, #function
FUN_a0060ed0:
! Last word of the service routine of interrupt level 9 (0XA0060E78..0XA0060ED3).
	nop                               ! delay slot of the 'retl' above: nothing
	.size FUN_a0060ed0, .-FUN_a0060ed0
