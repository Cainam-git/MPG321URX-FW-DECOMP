! leon2s FUN_a00603e0 @ 0xa00603e0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00603e0
	.type FUN_a00603e0, #function
FUN_a00603e0:
	st  %l6, [ %l4 + 8 ]
	restore
	.size FUN_a00603e0, .-FUN_a00603e0
