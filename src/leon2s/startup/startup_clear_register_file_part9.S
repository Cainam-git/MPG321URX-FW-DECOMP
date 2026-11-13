! startup_clear_register_file_part9  (FUN_a00606d0)
!
! Count the window and, after the loop, restore the saved WIM.
! Note: Ghidra piece 9 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a00606d0 @ 0xa00606d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606d0
	.type FUN_a00606d0, #function
FUN_a00606d0:
! Part 9 of startup_clear_register_file (0xA0060658..0xA00606EF).
	inc  %g1                          ! delay slot, runs on every pass: count the window
	mov  %g7, %wim                    ! WIM back to the kept value
	nop                               ! wait: a WIM write takes effect after three instructions
	nop
	.size FUN_a00606d0, .-FUN_a00606d0
