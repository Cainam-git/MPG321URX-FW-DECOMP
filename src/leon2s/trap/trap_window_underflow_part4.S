! trap_window_underflow_part4  (FUN_a00605c0)
!
! Reload the remaining locals and the first in registers from the stack frame.
! Note: Ghidra piece 4 of the routine 0xA0060590..0xA00605E7, not callable on its own.
! Name basis: proven - trap-table slot 6 jumps to 0x590; trap-name table: 'RESTORE into invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a00605c0 @ 0xa00605c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605c0
	.type FUN_a00605c0, #function
FUN_a00605c0:
! Part 4 of the window-underflow handler (0xA0060590..0xA00605E7).
	ldd  [ %sp + 0x10 ], %l4          ! %l4, %l5
	ldd  [ %sp + 0x18 ], %l6          ! %l6, %l7
	ldd  [ %sp + 0x20 ], %i0          ! %i0, %i1
	ldd  [ %sp + 0x28 ], %i2          ! %i2, %i3
	.size FUN_a00605c0, .-FUN_a00605c0
