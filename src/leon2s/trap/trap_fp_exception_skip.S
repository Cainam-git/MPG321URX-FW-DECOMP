! trap_fp_exception_skip  (FUN_a00604d0)
!
! Skip the instruction that raised an FPU exception and resume.
! Note: Entered from trap-table slot 8; the faulting instruction is not retried.
! Name basis: proven - trap-table slot 8 jumps to 0x4D0; trap-name table: 'FPU exception'; jmp %l2; rett %l2+4
!
! Matching notes
! --------------
! leon2s FUN_a00604d0 @ 0xa00604d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00604d0
	.type FUN_a00604d0, #function
FUN_a00604d0:
! Handler of trap type 0x08, fp_exception (slot trap_fp_exception_entry; the trap-name table calls it
! 'FPU exception'). It does not run the floating-point instruction again: it goes on after it.
	jmp  %l2                          ! jump to the instruction after the trapped one (its nPC)
	rett  %l2 + 4                     ! delay slot: return from the trap; the next one comes from nPC + 4
	nop                               ! padding; never reached
	nop
	.size FUN_a00604d0, .-FUN_a00604d0
