! startup_clear_register_file_part3  (FUN_a0060670)
!
! Save WIM in %g7 and clear it so every window can be entered.
! Note: Ghidra piece 3 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a0060670 @ 0xa0060670  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060670
	.type FUN_a0060670, #function
FUN_a0060670:
! Part 3 of startup_clear_register_file (0xA0060658..0xA00606EF).
	rd  %wim, %g7                     ! keep WIM in %g7
	mov  %g0, %wim                    ! WIM = 0: no window invalid, SAVE never traps
	nop                               ! wait: a WIM write takes effect after three instructions
	nop
	.size FUN_a0060670, .-FUN_a0060670
