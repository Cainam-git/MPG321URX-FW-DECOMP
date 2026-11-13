! trap_window_overflow_part3  (FUN_a0060550)
!
! Write the new WIM and wait the three required cycles.
! Note: Ghidra piece 3 of the routine 0xA0060538..0xA006058F, not callable on its own.
! Name basis: proven - trap-table slot 5 jumps to 0x538 (inside piece 0xA0060530); trap-name table: 'SAVE into
!   invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a0060550 @ 0xa0060550  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060550
	.type FUN_a0060550, #function
FUN_a0060550:
! Part 3 of the window-overflow handler (0xA0060538..0xA006058F).
	mov  %g1, %wim                    ! WIM = new value: this window is now the invalid one
	nop                               ! wait: a WIM write takes effect after three instructions
	nop
	nop
	.size FUN_a0060550, .-FUN_a0060550
