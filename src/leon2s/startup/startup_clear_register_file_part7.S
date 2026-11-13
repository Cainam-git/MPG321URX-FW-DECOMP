! startup_clear_register_file_part7  (FUN_a00606b0)
!
! Clear %o3..%o5 and the stack pointer of the current window.
! Note: Ghidra piece 7 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a00606b0 @ 0xa00606b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606b0
	.type FUN_a00606b0, #function
FUN_a00606b0:
! Part 7 of startup_clear_register_file (0xA0060658..0xA00606EF).
	mov  %g0, %o3                     ! %o3 = 0
	mov  %g0, %o4                     ! %o4 = 0
	mov  %g0, %o5                     ! %o5 = 0
	mov  %g0, %sp                     ! %o6 (stack pointer) = 0
	.size FUN_a00606b0, .-FUN_a00606b0
