! startup_clear_register_file_part10  (FUN_a00606e0)
!
! Return to the caller through the address kept in %g2.
! Note: Ghidra piece 10 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a00606e0 @ 0xa00606e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606e0
	.type FUN_a00606e0, #function
FUN_a00606e0:
! Part 10 of startup_clear_register_file (0xA0060658..0xA00606EF).
	nop                               ! third wait instruction
	mov  %g2, %o7                     ! return address back into %o7 of this window
	retl                              ! return to the caller
	nop                               ! delay slot: nothing
	.size FUN_a00606e0, .-FUN_a00606e0
