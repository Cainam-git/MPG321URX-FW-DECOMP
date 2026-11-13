! irq_entry_part12  (FUN_a0060440)
!
! Call the level's service routine and return to the trap window.
! Note: Ghidra piece 12 of the routine 0xA00603AC..0xA006048B, not callable on its own.
! Name basis: proven - trap-table slots 0x11..0x1F all jump to 0x3AC; indexes vector table 0xA8076040 by trap
!   type - 0x11
!
! Matching notes
! --------------
! leon2s FUN_a0060440 @ 0xa0060440  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060440
	.type FUN_a0060440, #function
FUN_a0060440:
! Part 12 of irq_entry (0xA00603AC..0xA006048B). RESTORE + SAVE with traps on after the call: if the
! interrupted window was written to its stack while the service routine ran, the RESTORE raises a
! window-underflow trap that loads it back, so the RETT at the end returns into a loaded window.
	call  %l7                         ! call the service routine of the level
	nop                               ! delay slot: nothing
	restore                           ! step to the interrupted window ...
	save                              ! ... and back
	.size FUN_a0060440, .-FUN_a0060440
