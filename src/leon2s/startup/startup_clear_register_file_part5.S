! startup_clear_register_file_part5  (FUN_a0060690)
!
! Clear %l3..%l6 of the current window.
! Note: Ghidra piece 5 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a0060690 @ 0xa0060690  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060690
	.type FUN_a0060690, #function
FUN_a0060690:
! Part 5 of startup_clear_register_file (0xA0060658..0xA00606EF).
	mov  %g0, %l3                     ! %l3 = 0
	mov  %g0, %l4                     ! %l4 = 0
	mov  %g0, %l5                     ! %l5 = 0
	mov  %g0, %l6                     ! %l6 = 0
	.size FUN_a0060690, .-FUN_a0060690
