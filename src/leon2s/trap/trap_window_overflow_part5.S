! trap_window_overflow_part5  (FUN_a0060570)
!
! Spill the window's in registers to its stack frame.
! Note: Ghidra piece 5 of the routine 0xA0060538..0xA006058F, not callable on its own.
! Name basis: proven - trap-table slot 5 jumps to 0x538 (inside piece 0xA0060530); trap-name table: 'SAVE into
!   invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a0060570 @ 0xa0060570  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060570
	.type FUN_a0060570, #function
FUN_a0060570:
! Part 5 of the window-overflow handler (0xA0060538..0xA006058F): the in registers go to the next 32 bytes.
	std  %i0, [ %sp + 0x20 ]          ! %i0, %i1
	std  %i2, [ %sp + 0x28 ]          ! %i2, %i3
	std  %i4, [ %sp + 0x30 ]          ! %i4, %i5
	std  %fp, [ %sp + 0x38 ]          ! %i6 (frame pointer), %i7 (return address)
	.size FUN_a0060570, .-FUN_a0060570
