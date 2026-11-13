! irq_entry_part8  (FUN_a0060400)
!
! Read PSR and extract the trap type from TBR.
! Note: Ghidra piece 8 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060400 @ 0xa0060400  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060400
	.type FUN_a0060400, #function
FUN_a0060400:
! Part 8 of irq_entry (0xA00603AC..0xA006048B).
	rd  %psr, %l0                     ! %l0 = PSR as it is now (traps on, level 15)
	nop                               ! no operation
	nop
	srl  %l3, 4, %l3                  ! TBR >> 4 ...
	.size FUN_a0060400, .-FUN_a0060400
