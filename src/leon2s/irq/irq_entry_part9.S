! irq_entry_part9  (FUN_a0060410)
!
! Turn the trap type into an index (type - 0x11) into the vector the handler table.
! Note: Ghidra piece 9 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060410 @ 0xa0060410  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060410
	.type FUN_a0060410, #function
FUN_a0060410:
! Part 9 of irq_entry (0xA00603AC..0xA006048B).
	and  %l3, 0xff, %l3               ! ... & 0xFF: the trap type, 0x11..0x1F
	sub  %l3, 0x11, %l3               ! minus 0x11: entry number 0..14 (level 1..15)
	sll  %l3, 2, %l3                  ! times 4: byte offset in the vector table
	sethi  %hi(0xa8076000), %l1       ! upper bits of the vector table
	.size FUN_a0060410, .-FUN_a0060410
