! trap_return_retry  (FUN_a00604c0)
!
! Return from a trap and re-execute the trapped instruction.
! Note: Unreached: no trap-table slot, call or stored word points at it.
! Name basis: descriptive - jmp %l1; rett %l2; no reference to 0xA00604C0
!
! Matching notes
! --------------
! leon2s FUN_a00604c0 @ 0xa00604c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604c0
	.type FUN_a00604c0, #function
FUN_a00604c0:
! Unreached: no trap-table slot, call or stored word points at 0xA00604C0. The return that runs the
! trapped instruction again: jump to its PC (%l1), and RETT continues with its nPC (%l2).
	jmp  %l1                          ! jump to the trapped instruction
	rett  %l2                         ! delay slot: return from the trap (traps on again), next at the nPC
	nop                               ! padding; never reached
	nop
	.size FUN_a00604c0, .-FUN_a00604c0
