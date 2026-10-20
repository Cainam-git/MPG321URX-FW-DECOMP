/* leon2m FUN_a00290e4 @ 0xa00290e4..0xa0029128 (17 words)  BYTE-EXACT hand-written assembly:
 * sparc-elf-as -Av8, .text compared word by word with parts/leon2m.bin 0xa00290e4..0xa0029128: 0 mismatches / 17.
 * 0xa00290e4..0xa00290e8 is the return (jmp %l5; rett %l6) of FUN_a0029060, whose function list range ends there.
 * 0xa00290ec is the entry of every external interrupt: trap slots tt11..tt1F (src/leon2m/FUN_a0028110.S ..
 * FUN_a00281f0.S) read %psr into %l0 and %tbr into %l3 and jump here. Code: %l5/%l6 = the interrupted PC/nPC;
 * %psr |= 0xF00 (interrupt level 15) with traps still off, then 'wr %l0, 0x20, %psr' turns traps ON at level 15
 * (so faults inside an interrupt handler trap normally, maskable interrupts stay blocked); stores %tbr, PC, nPC
 * at RAM 0xA803FF60/64/68; 'restore' and falls through into FUN_a0029128 (whose first instruction is 'save'),
 * which calls the dispatcher 0xA8027B50[(tbr >> 4 & 0xff) - 0x11] (initial data: 0xA0029994, 0xA0029AAC, ...).
 * Note: interrupts only run while the core runs; after the fatal path (FUN_a00291c4.S) traps stay
 * disabled forever, so none of these handlers runs again.
 */
	.section ".text"
	.align 4
	.global FUN_a00290e4
	.type FUN_a00290e4, #function
FUN_a00290e4:
! return of FUN_a0029060.
	jmp  %l5                                   ! a00290e4
	rett  %l6                                  ! a00290e8
! interrupt entry (tt11..tt1F): save PC/nPC, interrupt level 15, traps on, store TBR/PC/nPC at 0xA803FF60.
	mov  %l1, %l5                              ! a00290ec
	mov  %l2, %l6                              ! a00290f0
	rd  %psr, %l0                              ! a00290f4
	or  %l0, 0xf00, %l0                        ! a00290f8
	mov  %l0, %psr                             ! a00290fc
	wr  %l0, 0x20, %psr                        ! a0029100
	nop                                        ! a0029104
	nop                                        ! a0029108
	nop                                        ! a002910c
	sethi  %hi(0xa803fc00), %l4                ! a0029110
	or  %l4, 0x360, %l4                        ! a0029114
	st  %l3, [ %l4 + 0 ]                       ! a0029118
	st  %l5, [ %l4 + 4 ]                       ! a002911c
	st  %l6, [ %l4 + 8 ]                       ! a0029120
! restore; falls into FUN_a0029128 ('save' first), the dispatcher.
	restore                                    ! a0029124
	.size FUN_a00290e4, .-FUN_a00290e4
