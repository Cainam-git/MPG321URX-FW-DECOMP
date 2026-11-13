! irq_entry_part6  (FUN_a00603e8)
!
! Reopen the trap window and start addressing the save area.
! Note: Ghidra piece 6 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a00603e8 @ 0xa00603e8  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603e8
	.type FUN_a00603e8, #function
FUN_a00603e8:
! Part 6 of irq_entry (0xA00603AC..0xA006048B). This SAVE runs with traps on. If the trap window is the
! window WIM marks invalid, it raises a window-overflow trap first, which writes the oldest window to its
! stack. That trap also overwrites the local registers of the trap window, so TBR, PC and nPC are read
! back from the save area below.
	save  %sp, -64, %sp               ! back into the trap window, frame 64 bytes lower
	sethi  %hi(0xa807fc00), %l4       ! upper bits of the save area
	.size FUN_a00603e8, .-FUN_a00603e8
