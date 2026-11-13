! trap_window_overflow_part1  (FUN_a0060530)
!
! Begin the window-overflow handler: read the window mask and keep %g1.
! Note: Its first two words (nop; ta 0) are the end of trap_write_buffer_error. Sits in the trap table slot of
!   type 0x53.
! Name basis: proven - rd %wim, %l3; mov %g1, %l7 in front of trap_window_overflow_part2
!
! Matching notes
! --------------
! leon2s FUN_a0060530 @ 0xa0060530  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060530
	.type FUN_a0060530, #function
FUN_a0060530:
! This slot (trap type 0x53) holds the end of trap_write_buffer_error and the first two instructions of
! the window-overflow handler, not a handler for trap type 0x53.
	nop                               ! never reached (after the 'ta 0' at 0xA0060528)
	ta  0                             ! no path leads to this 'ta 0' (it would stop the processor)
! Window-overflow handler, entered here at 0xA0060538 from slot trap_window_overflow_entry (trap type
! 0x05). A SAVE wanted to enter the window that WIM marks invalid, and the trap put the processor in
! exactly that window. The handler moves the invalid mark one window on, writes the window there (the
! oldest one in use) to its stack and runs the SAVE again. The processor has 16 register windows.
	rd  %wim, %l3                     ! %l3 = WIM
	mov  %g1, %l7                     ! keep the trapped code's %g1 in %l7 (the handler needs %g1)
	.size FUN_a0060530, .-FUN_a0060530
