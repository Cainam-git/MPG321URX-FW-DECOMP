! trap_flush_windows_part7  (FUN_a0060640)
!
! Return from the trap past the trapping instruction.
! Note: Ghidra piece 7 of the routine 0xA00605E8..0xA0060647, not callable on its own.
! Name basis: descriptive - 6 SAVEs then 6 RESTOREs with interrupts masked, ends 'jmp %l2; rett %l2+4'; no
!   reference to 0xA00605E8
!
! Matching notes
! --------------
! leon2s FUN_a0060640 @ 0xa0060640  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060640
	.type FUN_a0060640, #function
FUN_a0060640:
! Part 7 of trap_flush_windows (0xA00605E8..0xA0060647).
	jmp  %l2                          ! jump to the instruction after the trapping one (its nPC)
	rett  %l2 + 4                     ! delay slot: return from the trap; the next one comes from nPC + 4
	.size FUN_a0060640, .-FUN_a0060640
