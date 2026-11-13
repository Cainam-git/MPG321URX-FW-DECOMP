! trap_window_overflow_part2  (FUN_a0060540)
!
! Compute the new invalid-window mask (WIM rotated right by one) and enter the next window.
! Note: Ghidra piece 2 of the routine 0xA0060538..0xA006058F, not callable on its own.
! Name basis: proven - trap-table slot 5 jumps to 0x538 (inside piece 0xA0060530); trap-name table: 'SAVE into
!   invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a0060540 @ 0xa0060540  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060540
	.type FUN_a0060540, #function
FUN_a0060540:
! Part 2 of the window-overflow handler (0xA0060538..0xA006058F).
	srl  %l3, 1, %g1                  ! WIM >> 1 ...
	sll  %l3, 0xf, %l4                ! ... | WIM << 15: WIM turned right by one place (16 windows)
	or  %l4, %g1, %g1                 ! %g1 = the new WIM
	save                              ! step into the oldest window (old WIM still in force: no trap)
	.size FUN_a0060540, .-FUN_a0060540
