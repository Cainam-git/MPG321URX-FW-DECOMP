! irq_entry_nosave_part4  (FUN_a00604b0)
!
! Return from the interrupt trap to the saved PC/nPC.
! Note: Ghidra piece 4 of the routine 0xA006048C..0xA00604BF, not callable on its own.
! Name basis: descriptive - same vector-table lookup as irq_trap_entry; no trap-table slot, call or stored
!   word reaches 0xA006048C
!
! Matching notes
! --------------
! leon2s FUN_a00604b0 @ 0xa00604b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604b0
	.type FUN_a00604b0, #function
FUN_a00604b0:
! Part 4 of irq_entry_nosave (0xA006048C..0xA00604BF).
	nop                               ! delay slot: nothing
	jmp  %l1                          ! jump back to the interrupted instruction
	rett  %l2                         ! delay slot: return from the trap (traps on again), next at the nPC
	nop                               ! padding; never reached
	.size FUN_a00604b0, .-FUN_a00604b0
