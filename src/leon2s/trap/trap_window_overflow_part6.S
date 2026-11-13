! trap_window_overflow_part6  (FUN_a0060580)
!
! Return to the trap window, restore %g1 and retry the SAVE.
! Note: Ghidra piece 6 of the routine 0xA0060538..0xA006058F, not callable on its own.
! Name basis: proven - trap-table slot 5 jumps to 0x538 (inside piece 0xA0060530); trap-name table: 'SAVE into
!   invalid window'
!
! Matching notes
! --------------
! leon2s FUN_a0060580 @ 0xa0060580  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060580
	.type FUN_a0060580, #function
FUN_a0060580:
! Part 6 of the window-overflow handler (0xA0060538..0xA006058F).
	restore                           ! back to the trap window
	mov  %l7, %g1                     ! give the trapped code its %g1 back
	jmp  %l1                          ! jump back to the SAVE that trapped
	rett  %l2                         ! delay slot: return from the trap; the SAVE runs again
	.size FUN_a0060580, .-FUN_a0060580
