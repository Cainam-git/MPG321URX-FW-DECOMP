! startup_clear_register_file_part1  (FUN_a0060658)
!
! Start the loop counter in %g1 and keep the return address in %g2.
! Note: Ghidra piece 1 of the routine 0xA0060658..0xA00606EF, not callable on its own; unreached: no call or
!   stored word points at it.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a0060658 @ 0xa0060658  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060658
	.type FUN_a0060658, #function
FUN_a0060658:
! Unreached: no call or stored word points at 0xA0060658. Clears %g1 and %g4..%g7 and then the local
! and out registers of eight register windows, one SAVE further each time; WIM is 0 meanwhile, so the
! SAVEs do not trap. At the end WIM is put back (it stays in %g7) and the routine returns through the
! address kept in %g2, in the window eight SAVEs further on.
	mov  %g0, %g1                     ! %g1 = 0, the window counter
	mov  %o7, %g2                     ! keep the return address in %g2
	.size FUN_a0060658, .-FUN_a0060658
