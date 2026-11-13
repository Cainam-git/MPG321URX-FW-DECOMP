! startup_clear_register_file_part4  (FUN_a0060680)
!
! Clear %l0..%l2 of the current window (loop start).
! Note: Ghidra piece 4 of the routine 0xA0060658..0xA00606EF, not callable on its own.
! Name basis: descriptive - zeroes globals and locals/outs of 8 windows, returns by retl; no call or stored
!   word reaches 0xA0060658
!
! Matching notes
! --------------
! leon2s FUN_a0060680 @ 0xa0060680  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060680
	.type FUN_a0060680, #function
FUN_a0060680:
! Part 4 of startup_clear_register_file (0xA0060658..0xA00606EF). The loop starts at 0xA0060684.
	nop                               ! third wait instruction
	mov  %g0, %l0                     ! loop: %l0 = 0
	mov  %g0, %l1                     ! %l1 = 0
	mov  %g0, %l2                     ! %l2 = 0
	.size FUN_a0060680, .-FUN_a0060680
