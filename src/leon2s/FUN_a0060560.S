! leon2s FUN_a0060560 @ 0xa0060560  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060560
	.type FUN_a0060560, #function
FUN_a0060560:
	std  %l0, [%sp + 0]
	std  %l2, [ %sp + 8 ]
	std  %l4, [ %sp + 0x10 ]
	std  %l6, [ %sp + 0x18 ]
	.size FUN_a0060560, .-FUN_a0060560
