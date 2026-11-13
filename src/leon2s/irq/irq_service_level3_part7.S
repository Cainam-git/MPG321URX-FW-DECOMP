! irq_service_level3_part7  (FUN_a0060ab0)
!
! Last word (a nop) of the level-3 interrupt service routine.
! Note: Ghidra piece 7 of the routine 0xA0060A58..0xA0060AB3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 2 = 0xA0060A58; bit 0x8 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060ab0 @ 0xa0060ab0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060ab0
	.type FUN_a0060ab0, #function
FUN_a0060ab0:
! Last word of the service routine of interrupt level 3 (0XA0060A58..0XA0060AB3).
	nop                               ! delay slot of the 'retl' above: nothing
	.size FUN_a0060ab0, .-FUN_a0060ab0
