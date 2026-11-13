! irq_entry_nosave_part3  (FUN_a00604a0)
!
! Index the vector table by trap type - 0x11 and call the level's service routine.
! Note: Ghidra piece 3 of the routine 0xA006048C..0xA00604BF, not callable on its own.
! Name basis: descriptive - same vector-table lookup as irq_trap_entry; no trap-table slot, call or stored
!   word reaches 0xA006048C
!
! Matching notes
! --------------
! leon2s FUN_a00604a0 @ 0xa00604a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604a0
	.type FUN_a00604a0, #function
FUN_a00604a0:
! Part 3 of irq_entry_nosave (0xA006048C..0xA00604BF).
	sub  %l3, 0x11, %l3               ! minus 0x11: entry number 0..14 (level 1..15)
	sll  %l3, 2, %l3                  ! times 4: byte offset in the vector table
	ld  [ %l4 + %l3 ], %l3            ! %l3 = the service routine of this level
	call  %l3                         ! call it
	.size FUN_a00604a0, .-FUN_a00604a0
