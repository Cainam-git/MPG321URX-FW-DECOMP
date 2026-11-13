! irq_entry_part14  (FUN_a0060460)
!
! Restore Y and disable traps before the return.
! Note: Ghidra piece 14 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060460 @ 0xa0060460  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060460
	.type FUN_a0060460, #function
FUN_a0060460:
! Part 14 of irq_entry (0xA00603AC..0xA006048B).
	ld  [ %l4 + 0x1c ], %l3           ! %l3 = the saved Y
	mov  %l3, %y                      ! Y back
	nop                               ! no operation
	wr  %l0, 0x20, %psr               ! %l0 has traps on: writing it with ET flipped turns traps off
	.size FUN_a0060460, .-FUN_a0060460
