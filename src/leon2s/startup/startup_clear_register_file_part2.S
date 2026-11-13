! startup_clear_register_file_part2  (FUN_a0060660)
!
! Clear the global registers %g4..%g7.
! Note: Ghidra piece 2 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a0060660 @ 0xa0060660  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060660
	.type FUN_a0060660, #function
FUN_a0060660:
! Part 2 of startup_clear_register_file (0xA0060658..0xA00606EF).
	mov  %g0, %g4                     ! %g4 = 0
	mov  %g0, %g5                     ! %g5 = 0
	mov  %g0, %g6                     ! %g6 = 0
	mov  %g0, %g7                     ! %g7 = 0
	.size FUN_a0060660, .-FUN_a0060660
