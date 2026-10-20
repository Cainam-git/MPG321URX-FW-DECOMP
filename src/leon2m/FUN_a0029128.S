! leon2m FUN_a0029128 @ 0xa0029128  interrupt dispatcher - byte-exact (sparc-elf-as -Av8, asm).
! Hand-written assembly. Saves %g1..%g7 and %y into the save area at 0xA803FF60, takes the trap type from the saved
! word (bits 4..11) minus 0x11 (first external interrupt) as an index into the handler table at RAM 0xA8027B50, calls
! that handler, restores the globals and %y, and re-enables traps (%psr writes; the interrupt level field is cleared
! on the way out).
	.section ".text"
	.align 4
	.global FUN_a0029128
	.type FUN_a0029128, #function
FUN_a0029128:
	save  %sp, -64, %sp
	sethi  %hi(0xa803fc00), %l4
	or  %l4, 0x360, %l4
	ld  [ %l4 + 0 ], %l3
	ld  [ %l4 + 4 ], %l5
	ld  [ %l4 + 8 ], %l6
	rd  %psr, %l0
	nop
	nop
	srl  %l3, 4, %l3
	and  %l3, 0xff, %l3
	sub  %l3, 0x11, %l3
	sll  %l3, 2, %l3
	sethi  %hi(0xa8027800), %l1
	or  %l1, 0x350, %l1
	ld  [ %l1 + %l3 ], %l7
	std  %g2, [ %l4 + 0 ]
	std  %g4, [ %l4 + 8 ]
	std  %g6, [ %l4 + 0x10 ]
	st  %g1, [ %l4 + 0x18 ]
	rd  %y, %l3
	st  %l3, [ %l4 + 0x1c ]
	call  %l7
	nop
	restore
	save
	ldd  [ %l4 + 0 ], %g2
	ldd  [ %l4 + 8 ], %g4
	ldd  [ %l4 + 0x10 ], %g6
	ld  [ %l4 + 0x18 ], %g1
	ld  [ %l4 + 0x1c ], %l3
	mov  %l3, %y
	nop
	wr  %l0, 0x20, %psr
	andn  %l0, 0xf00, %l4
	wr  %l4, 0x20, %psr
	nop
	nop
	nop
	.size FUN_a0029128, .-FUN_a0029128
