! irq_entry_nosave_part1  (FUN_a006048c)
!
! Set the stack pointer from the trap window's frame pointer.
! Note: Ghidra piece 1 of the routine 0xA006048C..0xA00604BF, not callable on its own; unreached: does not
!   save the global registers or Y, unlike irq_entry.
! Name basis: descriptive - same vector-table lookup as irq_trap_entry; no trap-table slot, call or stored
!   word reaches 0xA006048C
!
! Matching notes
! --------------
! leon2s FUN_a006048c @ 0xa006048c  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a006048c
	.type FUN_a006048c, #function
FUN_a006048c:
! Unreached: no trap-table slot, call or stored word points at 0xA006048C. A shorter interrupt entry:
! it calls the level's service routine from the vector table at 0xA8076040 with traps still off and
! without saving the global registers or Y, then returns to the interrupted instruction.
	mov  %fp, %sp                     ! stack pointer = the interrupted code's stack pointer (%fp here)
	.size FUN_a006048c, .-FUN_a006048c
