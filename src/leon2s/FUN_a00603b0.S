! leon2s FUN_a00603b0 @ 0xa00603b0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00603b0
	.type FUN_a00603b0, #function
FUN_a00603b0:
	mov  %l2, %l6
	rd  %psr, %l0
	or  %l0, 0xf00, %l0
	mov  %l0, %psr
	.size FUN_a00603b0, .-FUN_a00603b0
