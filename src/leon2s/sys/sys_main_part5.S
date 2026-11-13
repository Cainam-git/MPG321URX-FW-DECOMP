! sys_main_part5  (FUN_a00608a0)
!
! Main loop: run the queued deferred calls and the next service task.
! Note: Ghidra piece 5 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Labels used below:
!   FUN_a006d050 = input_poll_port_services
!   FUN_a00b229c = sys_task_run_pending
!
! Matching notes
! --------------
! leon2s FUN_a00608a0 @ 0xa00608a0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00608a0
	.type FUN_a00608a0, #function
FUN_a00608a0:
! Piece 5 of sys_main (0xA0060864..0xA00608EF): the main loop starts here (0xA00608A0).
	call FUN_a00b229c                 ! sys_task_run_pending: run every task whose time has come
	nop                               ! delay slot: nothing
	call FUN_a006d050                 ! input_poll_port_services: receiver, DP output and cable services
	nop                               ! delay slot: nothing
	.size FUN_a00608a0, .-FUN_a00608a0
