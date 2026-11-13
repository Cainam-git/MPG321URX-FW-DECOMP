! sys_main_part6  (FUN_a00608b0)
!
! Main loop: run the link standby / colour-space task and the debug console reader.
! Note: Ghidra piece 6 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Labels used below:
!   FUN_a006fa28 = input_run_link_tasks
!   FUN_a00b28d0 = dbg_handle_input_line
!
! Matching notes
! --------------
! leon2s FUN_a00608b0 @ 0xa00608b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00608b0
	.type FUN_a00608b0, #function
FUN_a00608b0:
! Piece 6 of sys_main (0xA0060864..0xA00608EF): main loop.
	call FUN_a006fa28                 ! input_run_link_tasks: link state machines of all HDMI and DP ports
	nop                               ! delay slot: nothing
	call FUN_a00b28d0                 ! dbg_handle_input_line: a line typed on the debug serial port
	nop                               ! delay slot: nothing
	.size FUN_a00608b0, .-FUN_a00608b0
