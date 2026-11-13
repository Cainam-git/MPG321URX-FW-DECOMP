! irq_entry_nosave_part2  (FUN_a0060490)
!
! Address the vector the handler table and extract the trap type from TBR.
! Note: Ghidra piece 2 of the routine 0xA006048C..0xA00604BF, not callable on its own.
! Name basis: descriptive - same vector-table lookup as irq_trap_entry; no trap-table slot, call or stored
!   word reaches 0xA006048C
!
! Matching notes
! --------------
! leon2s FUN_a0060490 @ 0xa0060490  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060490
	.type FUN_a0060490, #function
FUN_a0060490:
! Part 2 of irq_entry_nosave (0xA006048C..0xA00604BF).
	sethi  %hi(0xa8076000), %l4       ! upper bits of the vector table
	or  %l4, 0x40, %l4                ! %l4 = vector table 0xA8076040
	srl  %l3, 4, %l3                  ! TBR >> 4 ...
	and  %l3, 0xff, %l3               ! ... & 0xFF: the trap type, 0x11..0x1F
	.size FUN_a0060490, .-FUN_a0060490
