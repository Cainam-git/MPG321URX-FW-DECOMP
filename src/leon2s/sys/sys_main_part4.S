! sys_main_part4  (FUN_a0060890)
!
! Call hdr_init(1) and ipc_post_ready_flag, the last two start-up steps.
! Note: Ghidra piece 4 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Labels used below:
!   FUN_a006fb00 = ipc_post_ready_flag
!
! Matching notes
! --------------
! leon2s FUN_a0060890 @ 0xa0060890  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060890
	.type FUN_a0060890, #function
FUN_a0060890:
! Piece 4 of sys_main (0xA0060864..0xA00608EF): the last start-up steps.
! 0x9F1C27FC is hdr_init in the third program part (named 0xF10000 higher, at 0xA00D27FC).
	call FUN_9f1c27fc                 ! hdr_init: prepare the HDR handling
	mov  1, %o0                       ! delay slot: argument %o0 = 1
	call FUN_a006fb00                 ! ipc_post_ready_flag: ready bit in mailbox slot 0 for the main chip
	nop                               ! delay slot: nothing
	.size FUN_a0060890, .-FUN_a0060890
