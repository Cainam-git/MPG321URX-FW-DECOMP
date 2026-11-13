! sys_main_part1  (FUN_a0060864)
!
! Open the main frame and run the system set-up that prints the Leon2S banner.
! Note: Ghidra piece 1 of the routine 0xA0060864..0xA00608EF, not callable on its own.
! Name basis: proven - called only by startup_reset_entry; never returns; callees print the 'Leon2S system'
!   banner, init the HDMI Rx PHY, run deferred calls, link tasks and the debug console
!
! Labels used below:
!   FUN_a00b18d0 = startup_init_system
!
! Matching notes
! --------------
! leon2s FUN_a0060864 @ 0xa0060864  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060864
	.type FUN_a0060864, #function
FUN_a0060864:
! The main routine of the input processor (Leon2S), called once by the reset start-up (0xA0060300).
! Pieces 1 to 4 run the start-up steps in order; pieces 5 to 9 are the main loop, which calls the
! service routines one after the other for ever. The routine never returns.
	save  %sp, -104, %sp              ! open a stack frame of 104 bytes (a new register window)
	call FUN_a00b18d0                 ! startup_init_system: basic services, prints the version banner
	nop                               ! delay slot: nothing
	.size FUN_a0060864, .-FUN_a0060864
