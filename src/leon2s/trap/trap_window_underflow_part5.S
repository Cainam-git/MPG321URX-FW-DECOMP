! trap_window_underflow_part5  (FUN_a00605d0)
!
! Reload the last in registers and step forward to the trap window.
! Note: Ghidra piece 5 of the routine 0xA0060590..0xA00605E7, not callable on its own.
! Name basis: proven - trap-table slot 6 jumps to 0x590; trap-name table: 'RESTORE into invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a00605d0 @ 0xa00605d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605d0
	.type FUN_a00605d0, #function
FUN_a00605d0:
! Part 5 of the window-underflow handler (0xA0060590..0xA00605E7).
	ldd  [ %sp + 0x30 ], %i4          ! %i4, %i5
	ldd  [ %sp + 0x38 ], %fp          ! %i6 (frame pointer), %i7 (return address)
	save                              ! forward again ...
	save                              ! ... to the trap window
	.size FUN_a00605d0, .-FUN_a00605d0
