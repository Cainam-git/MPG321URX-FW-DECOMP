! trap_window_underflow_part6  (FUN_a00605e0)
!
! Retry the RESTORE that trapped.
! Note: Ghidra piece 6 of the routine 0xA0060590..0xA00605E7, not callable on its own.
! Name basis: proven - trap-table slot 6 jumps to 0x590; trap-name table: 'RESTORE into invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a00605e0 @ 0xa00605e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605e0
	.type FUN_a00605e0, #function
FUN_a00605e0:
! Part 6 of the window-underflow handler (0xA0060590..0xA00605E7).
	jmp  %l1                          ! jump back to the RESTORE that trapped
	rett  %l2                         ! delay slot: return from the trap; the RESTORE runs again
	.size FUN_a00605e0, .-FUN_a00605e0
