! sys_main_part7  (FUN_a00608c0)
!
! Main loop: publish the input-port status words and run the next task.
! Note: Ghidra piece 7 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Labels used below:
!   FUN_a006cfe8 = osd_run_pending_unzip
!   FUN_a00700cc = ipc_publish_port_status
!
! Matching notes
! --------------
! leon2s FUN_a00608c0 @ 0xa00608c0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00608c0
	.type FUN_a00608c0, #function
FUN_a00608c0:
! Piece 7 of sys_main (0xA0060864..0xA00608EF): main loop.
	call FUN_a00700cc                 ! ipc_publish_port_status: changed port records and HPD to Leon2M
	nop                               ! delay slot: nothing
	call FUN_a006cfe8                 ! osd_run_pending_unzip: a queued OSD unpack request
	nop                               ! delay slot: nothing
	.size FUN_a00608c0, .-FUN_a00608c0
