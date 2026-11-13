! trap_call_halt_handler_part10  (FUN_a00603a0)
!
! Return from the trap to the saved PC/nPC.
! Note: Ghidra piece 10 of the routine 0xA0060314..0xA00603AB, not callable on its own.
! Name basis: descriptive - calls 0xA0061224 ('for (;;);'); no trap-table slot, call or stored address reaches
!   0xA0060314
!
! Matching notes
! --------------
! leon2s FUN_a00603a0 @ 0xa00603a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00603a0
	.type FUN_a00603a0, #function
FUN_a00603a0:
! Part 10 of trap_call_halt_handler (0xA0060314..0xA00603AB): not reached, see part 1.
	nop                               ! third wait instruction
	jmp  %l5                          ! jump back to the trapped instruction
	rett  %l6                         ! delay slot: return from the trap (traps on again), next at the nPC
	.size FUN_a00603a0, .-FUN_a00603a0
