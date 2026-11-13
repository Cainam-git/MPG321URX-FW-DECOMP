! startup_clear_register_file_part8  (FUN_a00606c0)
!
! Clear %o7, move to the next window and loop for eight windows.
! Note: Ghidra piece 8 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a00606c0 @ 0xa00606c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606c0
	.type FUN_a00606c0, #function
FUN_a00606c0:
! Part 8 of startup_clear_register_file (0xA0060658..0xA00606EF).
	mov  %g0, %o7                     ! %o7 = 0
	save                              ! on to the next window
	cmp  %g1, 7                       ! was this window number 7?
	bne ext_a0060684                  ! no: clear the next one (back to 0xA0060684)
	.size FUN_a00606c0, .-FUN_a00606c0
