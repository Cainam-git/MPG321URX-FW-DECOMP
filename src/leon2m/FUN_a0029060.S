! leon2m FUN_a0029060 @ 0xa0029060  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0029060
	.type FUN_a0029060, #function
FUN_a0029060:
	save  %sp, -64, %sp
	rd  %psr, %l0
	or  %l0, 0xf00, %l0
	mov  %l0, %psr
	wr  %l0, 0x20, %psr
	nop
	nop
	nop
	rd  %psr, %l0
	nop
	nop
	sethi  %hi(0xa002a800), %l4
	or  %l4, 0x78, %l4
	mov  %l4, %l7
	mov  %g0, %l1
	mov  %g1, %l2
	mov  %g2, %l3
	mov  %g3, %l4
	call  %l7
	nop
	restore
	save
	mov  %l1, %g0
	mov  %l2, %g1
	mov  %l3, %g2
	mov  %l4, %g3
	nop
	wr  %l0, 0x20, %psr
	andn  %l0, 0xf00, %l4
	wr  %l4, 0x20, %psr
	nop
	nop
	nop
	.size FUN_a0029060, .-FUN_a0029060
