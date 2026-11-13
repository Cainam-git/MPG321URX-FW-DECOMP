! startup_clear_register_file_part6  (FUN_a00606a0)
!
! Clear %l7 and %o0..%o2 of the current window.
! Note: Ghidra piece 6 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a00606a0 @ 0xa00606a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606a0
	.type FUN_a00606a0, #function
FUN_a00606a0:
! Part 6 of startup_clear_register_file (0xA0060658..0xA00606EF).
	mov  %g0, %l7                     ! %l7 = 0
	mov  %g0, %o0                     ! %o0 = 0
	mov  %g0, %o1                     ! %o1 = 0
	mov  %g0, %o2                     ! %o2 = 0
	.size FUN_a00606a0, .-FUN_a00606a0
