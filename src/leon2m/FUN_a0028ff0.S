! leon2m FUN_a0028ff0 @ 0xa0028ff0  last trap-table slot + the reset code at 0xA0029000 - byte-exact (sparc-elf-as
! -Av8, asm). Hand-written assembly.
! 0xA0028FF0: trap slot 0xFF = "ta 0" (software trap) padding. 0xA0029000 (reset entry, from slot 0): flush, %psr =
! 0xCF (supervisor, traps off, interrupt level 15), %wim = 0, %y = 0, %wim = 1 (window 0 invalid), %psr = 0x10E0
! (FPU enabled, supervisor, traps on), frame pointer 0xA803FF50 and stack pointer 0xA803FEF0 (internal RAM), trap
! base %tbr = 0xA0028000, then calls the C start FUN_a00295a4; if that ever returns: "ta 1" in an endless loop.
	.section ".text"
	.align 4
	.global FUN_a0028ff0
	.type FUN_a0028ff0, #function
FUN_a0028ff0:
	ta  0
	nop
	nop
	nop
	flush  %g0 + 0
	wr  %g0, 0xcf, %psr
	mov  %g0, %wim
	mov  %g0, %y
	mov  1, %g1
	mov  %g1, %wim
	sethi  %hi(0x1000), %g1
	or  %g1, 0xe0, %g1
	mov  %g1, %psr
	sethi  %hi(0xa803fc00), %g3
	or  %g3, 0x350, %g3
	mov  %g3, %fp
	sub  %g3, 0x60, %sp
	sethi  %hi(0xa0028000), %g1
	mov  %g1, %tbr
	nop
	call FUN_a00295a4
	nop
.La0029048:
	ta  1
	b .La0029048
	nop
	.size FUN_a0028ff0, .-FUN_a0028ff0
