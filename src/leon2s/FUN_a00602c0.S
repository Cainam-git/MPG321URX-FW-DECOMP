! leon2s FUN_a00602c0 @ 0xa00602c0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00602c0
	.type FUN_a00602c0, #function
FUN_a00602c0:
	flush  %g0 + 0
	wr  %g0, 0xcf, %psr
	mov  %g0, %wim
	mov  %g0, %y
	.size FUN_a00602c0, .-FUN_a00602c0
