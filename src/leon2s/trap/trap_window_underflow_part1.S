! trap_window_underflow_part1  (FUN_a0060590)
!
! Compute the new invalid-window mask (WIM rotated left by one).
! Note: Ghidra piece 1 of the routine 0xA0060590..0xA00605E7, not callable on its own.
! Name basis: proven - trap-table slot 6 jumps to 0x590; trap-name table: 'RESTORE into invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a0060590 @ 0xa0060590  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060590
	.type FUN_a0060590, #function
FUN_a0060590:
! Window-underflow handler (trap type 0x06, from slot trap_window_underflow_entry). A RESTORE wanted to
! return to a window that WIM marks invalid: that window had been written to its stack. The handler moves
! the invalid mark one window back, loads the window from its stack and runs the RESTORE again.
	rd  %wim, %l3                     ! %l3 = WIM
	sll  %l3, 1, %l4                  ! WIM << 1 ...
	srl  %l3, 0xf, %l5                ! ... and WIM >> 15 ...
	or  %l5, %l4, %l5                 ! ... combined: WIM turned left by one place (16 windows)
	.size FUN_a0060590, .-FUN_a0060590
