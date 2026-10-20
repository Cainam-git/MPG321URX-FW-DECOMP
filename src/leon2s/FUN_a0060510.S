! leon2s FUN_a0060510 @ 0xa0060510  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0060510
	.type FUN_a0060510, #function
FUN_a0060510:
	deccc  %l5
	st  %l5, [ %l4 ]
	bl .La0060528
	nop
	jmp  %l1
	rett  %l2
.La0060528:
	ta  0
	nop
	.size FUN_a0060510, .-FUN_a0060510
