! sys_main_part2  (FUN_a0060870)
!
! Run the next start-up steps, including the HDMI receiver PHY set-up.
! Note: Ghidra piece 2 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Labels used below:
!   FUN_a006d31c = input_init_receivers
!   FUN_a0072958 = ipc_init_mailbox
!
! Matching notes
! --------------
! leon2s FUN_a0060870 @ 0xa0060870  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060870
	.type FUN_a0060870, #function
FUN_a0060870:
! Piece 2 of sys_main (0xA0060864..0xA00608EF): start-up steps.
	call FUN_a0072958                 ! ipc_init_mailbox: word 0x9F130000 = 0, below mailbox portal 1
	nop                               ! delay slot: nothing
	call FUN_a006d31c                 ! input_init_receivers: HDMI and DP receivers and their PHYs
	nop                               ! delay slot: nothing
	.size FUN_a0060870, .-FUN_a0060870
