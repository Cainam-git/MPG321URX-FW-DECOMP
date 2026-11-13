! trap_window_overflow_part4  (FUN_a0060560)
!
! Spill the window's local registers to its stack frame.
! Note: Ghidra piece 4 of the routine 0xA0060538..0xA006058F, not callable on its own.
! Name basis: proven - trap-table slot 5 jumps to 0x538 (inside piece 0xA0060530); trap-name table: 'SAVE into
!   invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a0060560 @ 0xa0060560  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060560
	.type FUN_a0060560, #function
FUN_a0060560:
! Part 4 of the window-overflow handler (0xA0060538..0xA006058F): the window's local registers go to
! the first 32 bytes of its stack frame, two registers per store.
	std  %l0, [%sp + 0]               ! %l0, %l1
	std  %l2, [ %sp + 8 ]             ! %l2, %l3
	std  %l4, [ %sp + 0x10 ]          ! %l4, %l5
	std  %l6, [ %sp + 0x18 ]          ! %l6, %l7
	.size FUN_a0060560, .-FUN_a0060560
