! trap_window_underflow_part2  (FUN_a00605a0)
!
! Write the new WIM and wait the three required cycles.
! Note: Ghidra piece 2 of the routine 0xA0060590..0xA00605E7, not callable on its own.
! Name basis: proven - trap-table slot 6 jumps to 0x590; trap-name table: 'RESTORE into invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a00605a0 @ 0xa00605a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00605a0
	.type FUN_a00605a0, #function
FUN_a00605a0:
! Part 2 of the window-underflow handler (0xA0060590..0xA00605E7).
	mov  %l5, %wim                    ! WIM = new value
	nop                               ! wait: a WIM write takes effect after three instructions
	nop
	nop
	.size FUN_a00605a0, .-FUN_a00605a0
