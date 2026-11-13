! sys_main_part3  (FUN_a0060880)
!
! Run two more start-up steps, the second setting up the debug console.
! Note: Ghidra piece 3 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns (b,a back to 0xA00608A0); callees
!   print the 'Leon2S system' banner and run console/link/status tasks
!
! Labels used below:
!   FUN_a006d3c8 = input_set_ports_power_on_wrapper
!   FUN_a00b34a8 = dbg_command_line_init
!
! Matching notes
! --------------
! leon2s FUN_a0060880 @ 0xa0060880  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060880
	.type FUN_a0060880, #function
FUN_a0060880:
! Piece 3 of sys_main (0xA0060864..0xA00608EF): start-up steps.
	call FUN_a006d3c8                 ! input_set_ports_power_on_wrapper: ports 0..6 to power-on state
	nop                               ! delay slot: nothing
	call FUN_a00b34a8                 ! dbg_command_line_init: debug command line, welcome banner
	nop                               ! delay slot: nothing
	.size FUN_a0060880, .-FUN_a0060880
