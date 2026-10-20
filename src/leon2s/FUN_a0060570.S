! leon2s FUN_a0060570 @ 0xa0060570  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060570
	.type FUN_a0060570, #function
FUN_a0060570:
	std  %i0, [ %sp + 0x20 ]
	std  %i2, [ %sp + 0x28 ]
	std  %i4, [ %sp + 0x30 ]
	std  %fp, [ %sp + 0x38 ]
	.size FUN_a0060570, .-FUN_a0060570
