! trap_window_underflow_part3  (FUN_a00605b0)
!
! Step back two windows and start reloading the local registers from the stack.
! Note: Ghidra piece 3 of the routine 0xA0060590..0xA00605E7, not callable on its own.
! Name basis: proven - trap-table slot 6 jumps to 0x590; trap-name table: 'RESTORE into invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a00605b0 @ 0xa00605b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605b0
	.type FUN_a00605b0, #function
FUN_a00605b0:
! Part 3 of the window-underflow handler (0xA0060590..0xA00605E7).
	restore                           ! step back to the window of the trapped RESTORE ...
	restore                           ! ... and one more, into the window to load
	ldd  [%sp + 0], %l0               ! reload %l0, %l1 from its stack frame
	ldd  [ %sp + 8 ], %l2             ! %l2, %l3
	.size FUN_a00605b0, .-FUN_a00605b0
