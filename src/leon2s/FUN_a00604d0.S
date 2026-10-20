! leon2s FUN_a00604d0 @ 0xa00604d0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00604d0
	.type FUN_a00604d0, #function
FUN_a00604d0:
	jmp  %l2
	.size FUN_a00604d0, .-FUN_a00604d0
