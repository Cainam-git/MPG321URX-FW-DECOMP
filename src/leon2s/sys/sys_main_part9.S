! sys_main_part9  (FUN_a00608e0)
!
! Main loop: copy register 0xCF03C820 to 0xCF03C830 and repeat the loop.
! Note: Ghidra piece 9 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Matching notes
! --------------
! leon2s FUN_a00608e0 @ 0xa00608e0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00608e0
	.type FUN_a00608e0, #function
FUN_a00608e0:
! Piece 9 of sys_main (0xA0060864..0xA00608EF): the end of the main loop.
	ld  [ %o5 ], %o5                  ! read register 0xCF03C820
	or  %g1, 0x30, %g1                ! %g1 = register 0xCF03C830
	st  %o5, [ %g1 ]                  ! copy the value to 0xCF03C830
	b,a ext_a00608a0                  ! back to the main loop start 0xA00608A0 (',a': skip the delay slot)
	.size FUN_a00608e0, .-FUN_a00608e0
