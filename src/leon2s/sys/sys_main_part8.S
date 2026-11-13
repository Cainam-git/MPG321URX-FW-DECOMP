! sys_main_part8  (FUN_a00608d0)
!
! Main loop: run hdr_task and address register 0xCF03C820.
! Note: Ghidra piece 8 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Matching notes
! --------------
! leon2s FUN_a00608d0 @ 0xa00608d0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00608d0
	.type FUN_a00608d0, #function
FUN_a00608d0:
! Piece 8 of sys_main (0xA0060864..0xA00608EF): main loop.
! 0x9F1C3C40 is hdr_task in the third program part (named 0xF10000 higher, at 0xA00D3C40).
	call FUN_9f1c3c40                 ! hdr_task: read the source's HDR metadata, update the tone curve
	nop                               ! delay slot: nothing
	sethi  %hi(0xcf03c800), %g1       ! %g1 = 0xCF03C800 (shared registers)
	or  %g1, 0x20, %o5                ! %o5 = register 0xCF03C820
	.size FUN_a00608d0, .-FUN_a00608d0
