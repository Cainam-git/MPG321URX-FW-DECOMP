! irq_entry_part4  (FUN_a00603d0)
!
! Store TBR, PC and nPC in the interrupt save area.
! Note: Ghidra piece 4 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603d0 @ 0xa00603d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603d0
	.type FUN_a00603d0, #function
FUN_a00603d0:
! Part 4 of irq_entry (0xA00603AC..0xA006048B).
	sethi  %hi(0xa807fc00), %l4       ! upper bits of the save area
	or  %l4, 0x360, %l4               ! %l4 = save area 0xA807FF60
	st  %l3, [%l4 + 0]                ! word 0 = TBR (holds the trap type)
	st  %l5, [ %l4 + 4 ]              ! word 1 = interrupted PC
	.size FUN_a00603d0, .-FUN_a00603d0
