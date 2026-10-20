! leon2m FUN_a0156a74 @ 0xa0156a74  MATCH (sparc-elf-as -Av8, asm)
! Hand-written assembly in the original: uses instructions C cannot express
! (processor state / trap registers). Reproduced from the disassembly; not yet commented.
	.section ".text"
	.align 4
	.global FUN_a0156a74
	.type FUN_a0156a74, #function
FUN_a0156a74:
	orcc  %o1, %o0, %g0
	bge .La0156a98
	xor  %o1, %o0, %g3
	tst  %o1
	bge .La0156a94
	tst  %o0
	bge .La0156a98
	neg  %o1
.La0156a94:
	neg  %o0
.La0156a98:
	orcc  %o1, %g0, %o5
	bne .La0156ab0
	mov  %o0, %o3
	ta  2
	retl
	mov  %g0, %o0
.La0156ab0:
	cmp  %o3, %o5
	bcs .La0156d08
	mov  %g0, %o2
	sethi  %hi(0x8000000), %g1
	cmp  %o3, %g1
	bcs .La0156b64
	mov  %g0, %o4
.La0156acc:
	cmp  %o5, %g1
	bcc .La0156b04
	mov  1, %g2
	sll  %o5, 4, %o5
	b .La0156acc
	inc  %o4
.La0156ae4:
	addcc  %o5, %o5, %o5
	bcc .La0156b04
	inc  %g2
	sll  %g1, 4, %g1
	srl  %o5, 1, %o5
	add  %o5, %g1, %o5
	b .La0156b18
	dec  %g2
.La0156b04:
	cmp  %o5, %o3
	bcs .La0156ae4
	nop
	be .La0156b18
	nop
.La0156b18:
	deccc  %g2
	bl .La0156cf4
	nop
	sub  %o3, %o5, %o3
	mov  1, %o2
	b .La0156b54
	nop
.La0156b34:
	sll  %o2, 1, %o2
	bl .La0156b4c
	srl  %o5, 1, %o5
	sub  %o3, %o5, %o3
	b .La0156b54
	inc  %o2
.La0156b4c:
	add  %o3, %o5, %o3
	dec  %o2
.La0156b54:
	deccc  %g2
	bge .La0156b34
	tst  %o3
	b,a .La0156cf4
.La0156b64:
	sll  %o5, 4, %o5
	cmp  %o5, %o3
	bleu .La0156b64
	inccc  %o4
	be .La0156d08
	dec  %o4
	tst  %o3
.La0156b80:
	sll  %o2, 4, %o2
	bl .La0156c40
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156bec
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156bc8
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156bbc
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 0xf, %o2
.La0156bbc:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 0xd, %o2
.La0156bc8:
	addcc  %o3, %o5, %o3
	bl .La0156be0
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 0xb, %o2
.La0156be0:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 9, %o2
.La0156bec:
	addcc  %o3, %o5, %o3
	bl .La0156c1c
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156c10
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 7, %o2
.La0156c10:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 5, %o2
.La0156c1c:
	addcc  %o3, %o5, %o3
	bl .La0156c34
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, 3, %o2
.La0156c34:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	inc  %o2
.La0156c40:
	addcc  %o3, %o5, %o3
	bl .La0156ca0
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156c7c
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156c70
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -1, %o2
.La0156c70:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -3, %o2
.La0156c7c:
	addcc  %o3, %o5, %o3
	bl .La0156c94
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -5, %o2
.La0156c94:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -7, %o2
.La0156ca0:
	addcc  %o3, %o5, %o3
	bl .La0156cd0
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	bl .La0156cc4
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -9, %o2
.La0156cc4:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -11, %o2
.La0156cd0:
	addcc  %o3, %o5, %o3
	bl .La0156ce8
	srl  %o5, 1, %o5
	subcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -13, %o2
.La0156ce8:
	addcc  %o3, %o5, %o3
	b .La0156cf4
	add  %o2, -15, %o2
.La0156cf4:
	deccc  %o4
	bge .La0156b80
	tst  %o3
	bl,a .La0156d08
	dec  %o2
.La0156d08:
	tst  %g3
	bl,a .La0156d14
	neg  %o2
.La0156d14:
	retl
	mov  %o2, %o0
	.size FUN_a0156a74, .-FUN_a0156a74
