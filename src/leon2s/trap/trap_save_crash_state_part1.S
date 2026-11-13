! trap_save_crash_state_part1  (FUN_a0060720)
!
! Capture WIM, the stack pointer and Y, and start addressing the crash save area.
! Note: Ghidra piece 1 of the routine 0xA0060720..0xA0060853, not callable on its own; cED_ALL reads PC at
!   0xA807FF84, TBR at 0xA807FF8C, stack pointer at 0xA807FF94 and ends in a halt loop, so parts 17..20 run
!   only if the hook returns.
! Name basis: proven - trap slots 2,3,7,9,0x2A jump to 0x720; hook 0xA8076088 = CED_ALL, which prints 'System
!   Crash. PC=' from this save area
!
! Matching notes
! --------------
! leon2s FUN_a0060720 @ 0xa0060720  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060720
	.type FUN_a0060720, #function
FUN_a0060720:
! Fatal-trap path of the input processor, entered from the slots of trap types 0x02 (illegal_instruction),
! 0x03 (privileged_instruction), 0x07 (mem_address_not_aligned), 0x09 (data_access_exception) and 0x2A
! (division_by_zero), with traps off. It stores the registers in the save area at 0xA807FF60: word 0 =
! 0 and %g1..%g7 (+0x00), the trap window's %l0..%l7 = PSR, PC, nPC, TBR, WIM, stack pointer, Y, frame
! pointer (+0x20), its %i0..%i7 (+0x40), then the trapped window's %i0..%i7 (+0x60) and %l0..%l7
! (+0x80). Then it calls the crash hook, the word at 0xA8076088, whose start value is 0xA0072CB8,
! trap_dump_crash_and_halt: it prints the crash report and never returns. Traps stay off during the call.
	rd  %wim, %l4                     ! %l4 = WIM
	mov  %sp, %l5                     ! %l5 = stack pointer
	rd  %y, %l6                       ! %l6 = Y register
	sethi  %hi(0xa807fc00), %l7       ! upper bits of the save area
	.size FUN_a0060720, .-FUN_a0060720
