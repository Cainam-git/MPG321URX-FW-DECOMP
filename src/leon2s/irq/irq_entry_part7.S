! irq_entry_part7  (FUN_a00603f0)
!
! Reload TBR, PC and nPC from the save area into the trap window.
! Note: Ghidra piece 7 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603f0 @ 0xa00603f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603f0
	.type FUN_a00603f0, #function
FUN_a00603f0:
! Part 7 of irq_entry (0xA00603AC..0xA006048B).
	or  %l4, 0x360, %l4               ! %l4 = save area 0xA807FF60
	ld  [%l4 + 0], %l3                ! %l3 = TBR
	ld  [ %l4 + 4 ], %l5              ! %l5 = interrupted PC
	ld  [ %l4 + 8 ], %l6              ! %l6 = interrupted nPC
	.size FUN_a00603f0, .-FUN_a00603f0
