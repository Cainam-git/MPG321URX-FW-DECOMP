! leon2s FUN_a00609f0 @ 0xa00609f0  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a00609f0
	.type FUN_a00609f0, #function
FUN_a00609f0:
	st  %g1, [ %o4 ]
	ret
	restore
	.size FUN_a00609f0, .-FUN_a00609f0
