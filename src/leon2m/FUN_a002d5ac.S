/* leon2m FUN_a002d5ac @ 0xa002d5ac..0xa002e238 (803 words)  BYTE-EXACT hand-transcribed assembly:
 * sparc-elf-as -Av8 (toolchains/sparc-elf-4.4.2), .text compared word by word with parts/leon2m.bin
 * 0xa002d5ac..0xa002e238: 0 mismatches / 803. Compiled C in the RAM
 * piece (CPU address = this address, flash 0xD55AC), transcribed instruction by instruction; branch targets are local
 * labels, the 62 calls go to Reg_Read32 FUN_a002c250 / Reg_Write32 FUN_a002c25c (written as .Lf - offset).
 * ROLE: the Big chip's FATAL TRAP HOOK. The fatal trap path 0xa0029460 (src/leon2m/FUN_a00291c4.S: tt02 illegal
 * instruction, tt03, tt07 unaligned, tt09 data access, tt2A divide by zero, tt82) saves the registers at
 * 0xA803FF60.. and calls the word at 0xA8027B98 (initial value 0xA002D5AC) with traps still disabled (ET = 0).
 * What it does (code facts):
 *  - Every character goes out on UART 0xC00B0000: poll the status word 0xC00B0014 (Reg_Read32) until bit 5 is set or
 *    0xFFFFE polls have passed (the bound is also stored at 0x00199270), then Reg_Write32(0xC00B0000, ch); a '\n' is
 *    followed by the same wait + '\r'. No wait is unbounded; the dump always finishes.
 *  - "\n\nSystem Crash.\nPC= " (0x001991F0) + the 8 hex digits (table "0123456789ABCDEF" at 0x00198FA0) of the
 *    trap PC (save word 0xA803FF84 = trap-window %l1); ", Exception= " (0x00199208) + the name from the 17-entry
 *    table {tt, text} at RAM 0xA8025C78 (initial data: 0 "Power-on reset", 1 "Error during instruction fetch",
 *    2 "UNIMP or other un-implemented instruction", 7 "Memory access to un-aligned address", 9 "Access error during
 *    load or store", 0x2A "Divide by zero", ...) matched against tt = bits 11..4 of the saved TBR (0xA803FF8C); no
 *    match (index 17) -> hex digits instead.
 *  - "\nCPU registers:\n" (0x00199218) + the 40 saved words 0xA803FF60..0xA803FFFC in hex, " " (0x00198BB0) between,
 *    "\n" (0x000FEF90) after every 8th (i & 7 == 7).
 *  - "\nStack contents:\n" (0x00199230) + 16 words from the saved %sp (0xA803FF94); "\nCode contents:\n" (0x00199248)
 *    + 32 words starting 16 bytes before the trap PC (loop bounds cmp 0xF / 0x1F; layout as above).
 *  - "\nSystem Halt." (0x00199260), then 0xa002dd08 'b 0xa002dd08' = an endless loop. There is no ret/retl/jmp in the
 *    function: it NEVER returns.
 * Can it fail or wait? It always ends in the endless loop with ET = 0 (no interrupts: no timer, no mailbox service,
 * no main loop, no watchdog kick from this core). Only an external reset (8051 STOP/RUN or power cycle) restarts the
 * Big chip. A fetch of a non-instruction word (tt02) or a misaligned / failing access (tt07 / tt09) ends here: crash text on the Big chip's UART, then a halt
 * before the logo (FUN_a0087020) and before the tool command task (FUN_a00ce348). A tt01 instruction fetch error
 * does NOT come here ('ta 0' in its trap slot with ET = 0 = error mode, FUN_a00291c4.S header).
 * Note: the UART 0xC00B0000 is the Big chip's debug UART (the "GPLL_..." prints use FUN_a00df170 on the same base,
 * FUN_a00dedc8 sets its divisor); whether it is wired to anything a user can see is not in the code.
 */
	.section ".text"
	.align 4
	.global FUN_a002d5ac
	.type FUN_a002d5ac, #function
FUN_a002d5ac:
.Lf:
! "\n\nSystem Crash.\nPC= " character by character (0x001991F0); each char: poll 0xC00B0014 bit 5 <= 0xFFFFE times, write 0xC00B0000.
	save  %sp, -120, %sp                       ! a002d5ac 9de3bf88
	sethi  %hi(0x199000), %o5                  ! a002d5b0 1b000664
	ldsb  [ %o5 + 0x1f0 ], %g1                 ! a002d5b4 c24b61f0
	cmp  %g1, 0                                ! a002d5b8 80a06000
	be  .La002d630                             ! a002d5bc 0280001d
	or  %o5, 0x1f0, %l3                        ! a002d5c0 a61361f0
	sethi  %hi(0xffc00), %o0                   ! a002d5c4 110003ff
	or  %o0, 0x3fe, %l6                        ! a002d5c8 ac1223fe
	sethi  %hi(0xc00b0000), %l4                ! a002d5cc 293002c0
	mov  %l6, %l5                              ! a002d5d0 aa100016
	mov  0, %l0                                ! a002d5d4 a0102000
.La002d5d8:
	call  .Lf - 0x135c                ! a002d5d8 7ffffb1e
	or  %l4, 0x14, %o0                         ! a002d5dc 90152014
	btst  0x20, %o0                            ! a002d5e0 808a2020
	bne  .La002d5f8                            ! a002d5e4 12800005
	inc  %l0                                   ! a002d5e8 a0042001
	cmp  %l0, %l5                              ! a002d5ec 80a40015
	bleu  .La002d5d8                           ! a002d5f0 08bffffa
	nop                                        ! a002d5f4 01000000
.La002d5f8:
	ldsb  [ %l3 ], %o1                         ! a002d5f8 d24cc000
	call  .Lf - 0x1350                ! a002d5fc 7ffffb18
	sethi  %hi(0xc00b0000), %o0                ! a002d600 113002c0
	ldsb  [ %l3 ], %o1                         ! a002d604 d24cc000
	cmp  %o1, 0xa                              ! a002d608 80a2600a
	mov  0, %l0                                ! a002d60c a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002d610 233002c0
	be  .La002dd1c                             ! a002d614 028001c2
	mov  %l6, %l2                              ! a002d618 a4100016
	inc  %l3                                   ! a002d61c a604e001
.La002d620:
	ldsb  [ %l3 ], %o2                         ! a002d620 d44cc000
	cmp  %o2, 0                                ! a002d624 80a2a000
	bne,a  .La002d5d8                          ! a002d628 32bfffec
	mov  0, %l0                                ! a002d62c a0102000
.La002d630:
! 8 hex digits of the trap PC (word 0xA803FF84), digit table 0x00198FA0.
	sethi  %hi(0xa803fc00), %l0                ! a002d630 212a00ff
	or  %l0, 0x384, %o7                        ! a002d634 9e142384
	sethi  %hi(0x198c00), %o4                  ! a002d638 19000663
	sethi  %hi(0xffc00), %o3                   ! a002d63c 170003ff
	ld  [ %o7 ], %i2                           ! a002d640 f403c000
	or  %o4, 0x3a0, %l6                        ! a002d644 ac1323a0
	or  %o3, 0x3fe, %l4                        ! a002d648 a812e3fe
	mov  0, %l1                                ! a002d64c a2102000
	sethi  %hi(0xc00b0000), %l3                ! a002d650 273002c0
	mov  0x1c, %l5                             ! a002d654 aa10201c
.La002d658:
	srl  %i2, %l5, %l2                         ! a002d658 a5368015
	and  %l2, 0xf, %l7                         ! a002d65c ae0ca00f
	ldub  [ %l6 + %l7 ], %l2                   ! a002d660 e40d8017
	mov  0, %l0                                ! a002d664 a0102000
.La002d668:
	call  .Lf - 0x135c                ! a002d668 7ffffafa
	or  %l3, 0x14, %o0                         ! a002d66c 9014e014
	btst  0x20, %o0                            ! a002d670 808a2020
	bne  .La002d688                            ! a002d674 12800005
	inc  %l0                                   ! a002d678 a0042001
	cmp  %l0, %l4                              ! a002d67c 80a40014
	bleu  .La002d668                           ! a002d680 08bffffa
	nop                                        ! a002d684 01000000
.La002d688:
	sll  %l2, 0x18, %i0                        ! a002d688 b12ca018
	sra  %i0, 0x18, %o1                        ! a002d68c 933e2018
	call  .Lf - 0x1350                ! a002d690 7ffffaf3
	sethi  %hi(0xc00b0000), %o0                ! a002d694 113002c0
	inc  %l1                                   ! a002d698 a2046001
	cmp  %l1, 7                                ! a002d69c 80a46007
	ble  .La002d658                            ! a002d6a0 04bfffee
	add  %l5, -4, %l5                          ! a002d6a4 aa057ffc
! ", Exception= " (0x00199208).
	sethi  %hi(0x199000), %l1                  ! a002d6a8 23000664
	ldsb  [ %l1 + 0x208 ], %l3                 ! a002d6ac e64c6208
	cmp  %l3, 0                                ! a002d6b0 80a4e000
	be  .La002d728                             ! a002d6b4 0280001d
	or  %l1, 0x208, %l3                        ! a002d6b8 a6146208
	sethi  %hi(0xffc00), %l4                   ! a002d6bc 290003ff
	or  %l4, 0x3fe, %l6                        ! a002d6c0 ac1523fe
	sethi  %hi(0xc00b0000), %l4                ! a002d6c4 293002c0
	mov  %l6, %l5                              ! a002d6c8 aa100016
	mov  0, %l0                                ! a002d6cc a0102000
.La002d6d0:
	call  .Lf - 0x135c                ! a002d6d0 7ffffae0
	or  %l4, 0x14, %o0                         ! a002d6d4 90152014
	btst  0x20, %o0                            ! a002d6d8 808a2020
	bne  .La002d6f0                            ! a002d6dc 12800005
	inc  %l0                                   ! a002d6e0 a0042001
	cmp  %l0, %l5                              ! a002d6e4 80a40015
	bleu  .La002d6d0                           ! a002d6e8 08bffffa
	nop                                        ! a002d6ec 01000000
.La002d6f0:
	sethi  %hi(0xc00b0000), %o0                ! a002d6f0 113002c0
	call  .Lf - 0x1350                ! a002d6f4 7ffffada
	ldsb  [ %l3 ], %o1                         ! a002d6f8 d24cc000
	ldsb  [ %l3 ], %i1                         ! a002d6fc f24cc000
	cmp  %i1, 0xa                              ! a002d700 80a6600a
	mov  0, %l0                                ! a002d704 a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002d708 233002c0
	be  .La002dd50                             ! a002d70c 02800191
	mov  %l6, %l2                              ! a002d710 a4100016
	inc  %l3                                   ! a002d714 a604e001
.La002d718:
	ldsb  [ %l3 ], %i3                         ! a002d718 f64cc000
	cmp  %i3, 0                                ! a002d71c 80a6e000
	bne,a  .La002d6d0                          ! a002d720 32bfffec
	mov  0, %l0                                ! a002d724 a0102000
.La002d728:
! tt = (saved TBR 0xA803FF8C >> 4) & 0xFF: search the 17-entry {tt, name} table at RAM 0xA8025C78, print the name (else hex).
	sethi  %hi(0xa803fc00), %g1                ! a002d728 032a00ff
	or  %g1, 0x38c, %o5                        ! a002d72c 9a10638c
	sethi  %hi(0xffc00), %l5                   ! a002d730 2b0003ff
	ld  [ %o5 ], %i5                           ! a002d734 fa034000
	or  %l5, 0x3fe, %o2                        ! a002d738 941563fe
	and  %i5, 0xff0, %i4                       ! a002d73c b80f6ff0
	sethi  %hi(0xa8025c00), %l6                ! a002d740 2d2a0097
	srl  %i4, 4, %l5                           ! a002d744 ab372004
	or  %l6, 0x78, %o4                         ! a002d748 9815a078
	mov  0, %l2                                ! a002d74c a4102000
	mov  %o2, %o3                              ! a002d750 9610000a
	sll  %l2, 3, %o5                           ! a002d754 9b2ca003
.La002d758:
	ld  [ %o4 + %o5 ], %o0                     ! a002d758 d003000d
	cmp  %o0, %l5                              ! a002d75c 80a20015
	be  .La002e184                             ! a002d760 02800289
	add  %o5, %o4, %o7                         ! a002d764 9e03400c
	inc  %l2                                   ! a002d768 a404a001
	cmp  %l2, 0x10                             ! a002d76c 80a4a010
	ble,a  .La002d758                          ! a002d770 24bffffa
	sll  %l2, 3, %o5                           ! a002d774 9b2ca003
.La002d778:
	cmp  %l2, 0x11                             ! a002d778 80a4a011
.La002d77c:
	be  .La002e10c                             ! a002d77c 02800264
	mov  %l5, %l7                              ! a002d780 ae100015
! "\nCPU registers:\n" (0x00199218).
	sethi  %hi(0x199000), %l7                  ! a002d784 2f000664
.La002d788:
	ldsb  [ %l7 + 0x218 ], %l1                 ! a002d788 e24de218
	cmp  %l1, 0                                ! a002d78c 80a46000
	be  .La002d804                             ! a002d790 0280001d
	or  %l7, 0x218, %l3                        ! a002d794 a615e218
	sethi  %hi(0xffc00), %l4                   ! a002d798 290003ff
	or  %l4, 0x3fe, %l6                        ! a002d79c ac1523fe
	sethi  %hi(0xc00b0000), %l4                ! a002d7a0 293002c0
	mov  %l6, %l5                              ! a002d7a4 aa100016
	mov  0, %l0                                ! a002d7a8 a0102000
.La002d7ac:
	call  .Lf - 0x135c                ! a002d7ac 7ffffaa9
	or  %l4, 0x14, %o0                         ! a002d7b0 90152014
	btst  0x20, %o0                            ! a002d7b4 808a2020
	bne  .La002d7cc                            ! a002d7b8 12800005
	inc  %l0                                   ! a002d7bc a0042001
	cmp  %l0, %l5                              ! a002d7c0 80a40015
	bleu  .La002d7ac                           ! a002d7c4 08bffffa
	nop                                        ! a002d7c8 01000000
.La002d7cc:
	sethi  %hi(0xc00b0000), %o0                ! a002d7cc 113002c0
	call  .Lf - 0x1350                ! a002d7d0 7ffffaa3
	ldsb  [ %l3 ], %o1                         ! a002d7d4 d24cc000
	ldsb  [ %l3 ], %i3                         ! a002d7d8 f64cc000
	cmp  %i3, 0xa                              ! a002d7dc 80a6e00a
	mov  0, %l0                                ! a002d7e0 a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002d7e4 233002c0
	be  .La002ddb8                             ! a002d7e8 02800174
	mov  %l6, %l2                              ! a002d7ec a4100016
	inc  %l3                                   ! a002d7f0 a604e001
.La002d7f4:
	ldsb  [ %l3 ], %i4                         ! a002d7f4 f84cc000
	cmp  %i4, 0                                ! a002d7f8 80a72000
	bne  .La002d7ac                            ! a002d7fc 12bfffec
	mov  0, %l0                                ! a002d800 a0102000
.La002d804:
	sethi  %hi(0x198c00), %l6                  ! a002d804 2d000663
! the 40 saved words 0xA803FF60.. in hex, " " (0x00198BB0) between, "\n" (0x000FEF90) after every 8th.
	sethi  %hi(0xa803fc00), %l5                ! a002d808 2b2a00ff
	or  %l6, 0x3a0, %i4                        ! a002d80c b815a3a0
	sethi  %hi(0x199000), %l3                  ! a002d810 27000664
	or  %l5, 0x360, %i1                        ! a002d814 b2156360
	mov  0, %i3                                ! a002d818 b6102000
	sethi  %hi(0x198800), %i0                  ! a002d81c 31000662
	sethi  %hi(0xc00b0000), %l6                ! a002d820 2d3002c0
	ld  [ %l3 + 0x270 ], %l7                   ! a002d824 ee04e270
	sll  %i3, 2, %i5                           ! a002d828 bb2ee002
.La002d82c:
	ld  [ %i5 + %i1 ], %l4                     ! a002d82c e8074019
	mov  0, %l3                                ! a002d830 a6102000
	mov  0x1c, %l2                             ! a002d834 a410201c
.La002d838:
	srl  %l4, %l2, %g1                         ! a002d838 83350012
	and  %g1, 0xf, %o5                         ! a002d83c 9a08600f
	ldub  [ %i4 + %o5 ], %l1                   ! a002d840 e20f000d
	mov  0, %l0                                ! a002d844 a0102000
.La002d848:
	call  .Lf - 0x135c                ! a002d848 7ffffa82
	or  %l6, 0x14, %o0                         ! a002d84c 9015a014
	btst  0x20, %o0                            ! a002d850 808a2020
	bne  .La002d868                            ! a002d854 12800005
	inc  %l0                                   ! a002d858 a0042001
	cmp  %l0, %l7                              ! a002d85c 80a40017
	bleu  .La002d848                           ! a002d860 08bffffa
	nop                                        ! a002d864 01000000
.La002d868:
	sll  %l1, 0x18, %o0                        ! a002d868 912c6018
	sra  %o0, 0x18, %o1                        ! a002d86c 933a2018
	call  .Lf - 0x1350                ! a002d870 7ffffa7b
	sethi  %hi(0xc00b0000), %o0                ! a002d874 113002c0
	inc  %l3                                   ! a002d878 a604e001
	cmp  %l3, 7                                ! a002d87c 80a4e007
	ble  .La002d838                            ! a002d880 04bfffee
	add  %l2, -4, %l2                          ! a002d884 a404bffc
	ldsb  [ %i0 + 0x3b0 ], %o1                 ! a002d888 d24e23b0
	cmp  %o1, 0                                ! a002d88c 80a26000
	be  .La002d904                             ! a002d890 0280001d
	or  %i0, 0x3b0, %l3                        ! a002d894 a61623b0
	sethi  %hi(0x199000), %o7                  ! a002d898 1f000664
	sethi  %hi(0xc00b0000), %l4                ! a002d89c 293002c0
	ld  [ %o7 + 0x270 ], %l5                   ! a002d8a0 ea03e270
	mov  %l5, %i5                              ! a002d8a4 ba100015
	mov  0, %l0                                ! a002d8a8 a0102000
.La002d8ac:
	call  .Lf - 0x135c                ! a002d8ac 7ffffa69
	or  %l4, 0x14, %o0                         ! a002d8b0 90152014
	btst  0x20, %o0                            ! a002d8b4 808a2020
	bne  .La002d8cc                            ! a002d8b8 12800005
	inc  %l0                                   ! a002d8bc a0042001
	cmp  %l0, %l5                              ! a002d8c0 80a40015
	bleu  .La002d8ac                           ! a002d8c4 08bffffa
	nop                                        ! a002d8c8 01000000
.La002d8cc:
	sethi  %hi(0xc00b0000), %o0                ! a002d8cc 113002c0
	call  .Lf - 0x1350                ! a002d8d0 7ffffa63
	ldsb  [ %l3 ], %o1                         ! a002d8d4 d24cc000
	ldsb  [ %l3 ], %o2                         ! a002d8d8 d44cc000
	cmp  %o2, 0xa                              ! a002d8dc 80a2a00a
	mov  0, %l0                                ! a002d8e0 a0102000
	sethi  %hi(0xc00b0000), %l2                ! a002d8e4 253002c0
	be  .La002dd84                             ! a002d8e8 02800127
	mov  %i5, %l1                              ! a002d8ec a210001d
	inc  %l3                                   ! a002d8f0 a604e001
.La002d8f4:
	ldsb  [ %l3 ], %o3                         ! a002d8f4 d64cc000
	cmp  %o3, 0                                ! a002d8f8 80a2e000
	bne,a  .La002d8ac                          ! a002d8fc 32bfffec
	mov  0, %l0                                ! a002d900 a0102000
.La002d904:
	and  %i3, 7, %o4                           ! a002d904 980ee007
	cmp  %o4, 7                                ! a002d908 80a32007
	be,a  .La002dee4                           ! a002d90c 22800176
	sethi  %hi(0xfec00), %l0                   ! a002d910 210003fb
.La002d914:
	inc  %i3                                   ! a002d914 b606e001
.La002d918:
	cmp  %i3, 0x27                             ! a002d918 80a6e027
	ble,a  .La002d82c                          ! a002d91c 24bfffc4
	sll  %i3, 2, %i5                           ! a002d920 bb2ee002
! "\nStack contents:\n" (0x00199230), then 16 words from the saved %sp (word 0xA803FF94).
	sethi  %hi(0x199000), %i1                  ! a002d924 33000664
	ldsb  [ %i1 + 0x230 ], %l7                 ! a002d928 ee4e6230
	cmp  %l7, 0                                ! a002d92c 80a5e000
	be  .La002d9a4                             ! a002d930 0280001d
	or  %i1, 0x230, %l3                        ! a002d934 a6166230
	sethi  %hi(0xffc00), %l4                   ! a002d938 290003ff
	or  %l4, 0x3fe, %l6                        ! a002d93c ac1523fe
	sethi  %hi(0xc00b0000), %l4                ! a002d940 293002c0
	mov  %l6, %l5                              ! a002d944 aa100016
	mov  0, %l0                                ! a002d948 a0102000
.La002d94c:
	call  .Lf - 0x135c                ! a002d94c 7ffffa41
	or  %l4, 0x14, %o0                         ! a002d950 90152014
	btst  0x20, %o0                            ! a002d954 808a2020
	bne  .La002d96c                            ! a002d958 12800005
	inc  %l0                                   ! a002d95c a0042001
	cmp  %l0, %l5                              ! a002d960 80a40015
	bleu  .La002d94c                           ! a002d964 08bffffa
	nop                                        ! a002d968 01000000
.La002d96c:
	sethi  %hi(0xc00b0000), %o0                ! a002d96c 113002c0
	call  .Lf - 0x1350                ! a002d970 7ffffa3b
	ldsb  [ %l3 ], %o1                         ! a002d974 d24cc000
	ldsb  [ %l3 ], %i3                         ! a002d978 f64cc000
	cmp  %i3, 0xa                              ! a002d97c 80a6e00a
	mov  0, %l0                                ! a002d980 a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002d984 233002c0
	be  .La002de20                             ! a002d988 02800126
	mov  %l6, %l2                              ! a002d98c a4100016
	inc  %l3                                   ! a002d990 a604e001
.La002d994:
	ldsb  [ %l3 ], %i4                         ! a002d994 f84cc000
	cmp  %i4, 0                                ! a002d998 80a72000
	bne  .La002d94c                            ! a002d99c 12bfffec
	mov  0, %l0                                ! a002d9a0 a0102000
.La002d9a4:
	sethi  %hi(0xa803fc00), %i5                ! a002d9a4 3b2a00ff
	or  %i5, 0x394, %l5                        ! a002d9a8 aa176394
	ld  [ %l5 ], %l6                           ! a002d9ac ec054000
	sethi  %hi(0xffc00), %o0                   ! a002d9b0 110003ff
	or  %o0, 0x3fe, %i3                        ! a002d9b4 b61223fe
	st  %l6, [ %fp + -16 ]                     ! a002d9b8 ec27bff0
	sethi  %hi(0x198c00), %l3                  ! a002d9bc 27000663
	mov  %i3, %i1                              ! a002d9c0 b210001b
	or  %l3, 0x3a0, %i4                        ! a002d9c4 b814e3a0
	clr  [ %fp + -12 ]                         ! a002d9c8 c027bff4
	sethi  %hi(0xc00b0000), %l6                ! a002d9cc 2d3002c0
	mov  %i3, %l7                              ! a002d9d0 ae10001b
.La002d9d4:
	ld  [ %fp + -12 ], %o2                     ! a002d9d4 d407bff4
	sll  %o2, 2, %o7                           ! a002d9d8 9f2aa002
	ld  [ %fp + -16 ], %o1                     ! a002d9dc d207bff0
	ld  [ %o7 + %o1 ], %l4                     ! a002d9e0 e803c009
	mov  0, %l2                                ! a002d9e4 a4102000
	mov  0x1c, %l3                             ! a002d9e8 a610201c
.La002d9ec:
	srl  %l4, %l3, %o4                         ! a002d9ec 99350013
	and  %o4, 0xf, %o3                         ! a002d9f0 960b200f
	ldub  [ %i4 + %o3 ], %l1                   ! a002d9f4 e20f000b
	mov  0, %l0                                ! a002d9f8 a0102000
.La002d9fc:
	call  .Lf - 0x135c                ! a002d9fc 7ffffa15
	or  %l6, 0x14, %o0                         ! a002da00 9015a014
	btst  0x20, %o0                            ! a002da04 808a2020
	bne  .La002da1c                            ! a002da08 12800005
	inc  %l0                                   ! a002da0c a0042001
	cmp  %l0, %l7                              ! a002da10 80a40017
	bleu  .La002d9fc                           ! a002da14 08bffffa
	nop                                        ! a002da18 01000000
.La002da1c:
	sll  %l1, 0x18, %l0                        ! a002da1c a12c6018
	sra  %l0, 0x18, %o1                        ! a002da20 933c2018
	call  .Lf - 0x1350                ! a002da24 7ffffa0e
	sethi  %hi(0xc00b0000), %o0                ! a002da28 113002c0
	inc  %l2                                   ! a002da2c a404a001
	cmp  %l2, 7                                ! a002da30 80a4a007
	ble  .La002d9ec                            ! a002da34 04bfffee
	add  %l3, -4, %l3                          ! a002da38 a604fffc
	ldsb  [ %i0 + 0x3b0 ], %l2                 ! a002da3c e44e23b0
	cmp  %l2, 0                                ! a002da40 80a4a000
	be  .La002dab8                             ! a002da44 0280001d
	or  %i0, 0x3b0, %l3                        ! a002da48 a61623b0
	sethi  %hi(0xc00b0000), %l4                ! a002da4c 293002c0
	mov  %i3, %l5                              ! a002da50 aa10001b
	sethi  %hi(0x199000), %l1                  ! a002da54 23000664
	ld  [ %l1 + 0x270 ], %i5                   ! a002da58 fa046270
	mov  0, %l0                                ! a002da5c a0102000
.La002da60:
	call  .Lf - 0x135c                ! a002da60 7ffff9fc
	or  %l4, 0x14, %o0                         ! a002da64 90152014
	btst  0x20, %o0                            ! a002da68 808a2020
	bne  .La002da80                            ! a002da6c 12800005
	inc  %l0                                   ! a002da70 a0042001
	cmp  %l0, %l5                              ! a002da74 80a40015
	bleu  .La002da60                           ! a002da78 08bffffa
	nop                                        ! a002da7c 01000000
.La002da80:
	sethi  %hi(0xc00b0000), %o0                ! a002da80 113002c0
	call  .Lf - 0x1350                ! a002da84 7ffff9f6
	ldsb  [ %l3 ], %o1                         ! a002da88 d24cc000
	ldsb  [ %l3 ], %o5                         ! a002da8c da4cc000
	cmp  %o5, 0xa                              ! a002da90 80a3600a
	mov  0, %l0                                ! a002da94 a0102000
	sethi  %hi(0xc00b0000), %l2                ! a002da98 253002c0
	be  .La002ddec                             ! a002da9c 028000d4
	mov  %i5, %l1                              ! a002daa0 a210001d
	inc  %l3                                   ! a002daa4 a604e001
.La002daa8:
	ldsb  [ %l3 ], %g1                         ! a002daa8 c24cc000
	cmp  %g1, 0                                ! a002daac 80a06000
	bne,a  .La002da60                          ! a002dab0 32bfffec
	mov  0, %l0                                ! a002dab4 a0102000
.La002dab8:
	ld  [ %fp + -12 ], %l3                     ! a002dab8 e607bff4
	and  %l3, 7, %l4                           ! a002dabc a80ce007
	cmp  %l4, 7                                ! a002dac0 80a52007
	be,a  .La002e054                           ! a002dac4 22800164
	sethi  %hi(0xfec00), %l5                   ! a002dac8 2b0003fb
.La002dacc:
	ld  [ %fp + -12 ], %o3                     ! a002dacc d607bff4
.La002dad0:
	add  %o3, 1, %o2                           ! a002dad0 9402e001
	cmp  %o2, 0xf                              ! a002dad4 80a2a00f
	ble  .La002d9d4                            ! a002dad8 04bfffbf
	st  %o2, [ %fp + -12 ]                     ! a002dadc d427bff4
! "\nCode contents:\n" (0x00199248), then 32 words from trap PC - 16.
	sethi  %hi(0x199000), %i1                  ! a002dae0 33000664
	ldsb  [ %i1 + 0x248 ], %l7                 ! a002dae4 ee4e6248
	cmp  %l7, 0                                ! a002dae8 80a5e000
	be  .La002db60                             ! a002daec 0280001d
	or  %i1, 0x248, %l3                        ! a002daf0 a6166248
	sethi  %hi(0xffc00), %i3                   ! a002daf4 370003ff
	or  %i3, 0x3fe, %l6                        ! a002daf8 ac16e3fe
	sethi  %hi(0xc00b0000), %l4                ! a002dafc 293002c0
	mov  %l6, %l5                              ! a002db00 aa100016
	mov  0, %l0                                ! a002db04 a0102000
.La002db08:
	call  .Lf - 0x135c                ! a002db08 7ffff9d2
	or  %l4, 0x14, %o0                         ! a002db0c 90152014
	btst  0x20, %o0                            ! a002db10 808a2020
	bne  .La002db28                            ! a002db14 12800005
	inc  %l0                                   ! a002db18 a0042001
	cmp  %l0, %l5                              ! a002db1c 80a40015
	bleu  .La002db08                           ! a002db20 08bffffa
	nop                                        ! a002db24 01000000
.La002db28:
	sethi  %hi(0xc00b0000), %o0                ! a002db28 113002c0
	call  .Lf - 0x1350                ! a002db2c 7ffff9cc
	ldsb  [ %l3 ], %o1                         ! a002db30 d24cc000
	ldsb  [ %l3 ], %i4                         ! a002db34 f84cc000
	cmp  %i4, 0xa                              ! a002db38 80a7200a
	mov  0, %l0                                ! a002db3c a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002db40 233002c0
	be  .La002de88                             ! a002db44 028000d1
	mov  %l6, %l2                              ! a002db48 a4100016
	inc  %l3                                   ! a002db4c a604e001
.La002db50:
	ldsb  [ %l3 ], %o4                         ! a002db50 d84cc000
	cmp  %o4, 0                                ! a002db54 80a32000
	bne,a  .La002db08                          ! a002db58 32bfffec
	mov  0, %l0                                ! a002db5c a0102000
.La002db60:
	add  %i2, -16, %l6                         ! a002db60 ac06bff0
	sethi  %hi(0x198c00), %i2                  ! a002db64 35000663
	sethi  %hi(0xffc00), %l2                   ! a002db68 250003ff
	or  %l2, 0x3fe, %i1                        ! a002db6c b214a3fe
	st  %l6, [ %fp + -20 ]                     ! a002db70 ec27bfec
	or  %i2, 0x3a0, %i4                        ! a002db74 b816a3a0
	sethi  %hi(0x199000), %l0                  ! a002db78 21000664
	mov  0, %i3                                ! a002db7c b6102000
	sethi  %hi(0xc00b0000), %l6                ! a002db80 2d3002c0
	mov  %i1, %l7                              ! a002db84 ae100019
	ld  [ %l0 + 0x270 ], %i2                   ! a002db88 f4042270
	sll  %i3, 2, %o5                           ! a002db8c 9b2ee002
.La002db90:
	ld  [ %fp + -20 ], %l1                     ! a002db90 e207bfec
	ld  [ %o5 + %l1 ], %l4                     ! a002db94 e8034011
	mov  0, %l3                                ! a002db98 a6102000
	mov  0x1c, %l2                             ! a002db9c a410201c
.La002dba0:
	srl  %l4, %l2, %l5                         ! a002dba0 ab350012
	and  %l5, 0xf, %g1                         ! a002dba4 820d600f
	ldub  [ %i4 + %g1 ], %l1                   ! a002dba8 e20f0001
	mov  0, %l0                                ! a002dbac a0102000
.La002dbb0:
	call  .Lf - 0x135c                ! a002dbb0 7ffff9a8
	or  %l6, 0x14, %o0                         ! a002dbb4 9015a014
	btst  0x20, %o0                            ! a002dbb8 808a2020
	bne  .La002dbd0                            ! a002dbbc 12800005
	inc  %l0                                   ! a002dbc0 a0042001
	cmp  %l0, %l7                              ! a002dbc4 80a40017
	bleu  .La002dbb0                           ! a002dbc8 08bffffa
	nop                                        ! a002dbcc 01000000
.La002dbd0:
	sll  %l1, 0x18, %i5                        ! a002dbd0 bb2c6018
	sra  %i5, 0x18, %o1                        ! a002dbd4 933f6018
	call  .Lf - 0x1350                ! a002dbd8 7ffff9a1
	sethi  %hi(0xc00b0000), %o0                ! a002dbdc 113002c0
	inc  %l3                                   ! a002dbe0 a604e001
	cmp  %l3, 7                                ! a002dbe4 80a4e007
	ble  .La002dba0                            ! a002dbe8 04bfffee
	add  %l2, -4, %l2                          ! a002dbec a404bffc
	ldsb  [ %i0 + 0x3b0 ], %l4                 ! a002dbf0 e84e23b0
	cmp  %l4, 0                                ! a002dbf4 80a52000
	be  .La002dc68                             ! a002dbf8 0280001c
	or  %i0, 0x3b0, %l3                        ! a002dbfc a61623b0
	sethi  %hi(0xc00b0000), %l4                ! a002dc00 293002c0
	mov  %i1, %l5                              ! a002dc04 aa100019
	mov  %i2, %i5                              ! a002dc08 ba10001a
	mov  0, %l0                                ! a002dc0c a0102000
.La002dc10:
	call  .Lf - 0x135c                ! a002dc10 7ffff990
	or  %l4, 0x14, %o0                         ! a002dc14 90152014
	btst  0x20, %o0                            ! a002dc18 808a2020
	bne  .La002dc30                            ! a002dc1c 12800005
	inc  %l0                                   ! a002dc20 a0042001
	cmp  %l0, %l5                              ! a002dc24 80a40015
	bleu  .La002dc10                           ! a002dc28 08bffffa
	nop                                        ! a002dc2c 01000000
.La002dc30:
	sethi  %hi(0xc00b0000), %o0                ! a002dc30 113002c0
	call  .Lf - 0x1350                ! a002dc34 7ffff98a
	ldsb  [ %l3 ], %o1                         ! a002dc38 d24cc000
	ldsb  [ %l3 ], %o0                         ! a002dc3c d04cc000
	cmp  %o0, 0xa                              ! a002dc40 80a2200a
	mov  0, %l0                                ! a002dc44 a0102000
	sethi  %hi(0xc00b0000), %l2                ! a002dc48 253002c0
	be  .La002de54                             ! a002dc4c 02800082
	mov  %i5, %l1                              ! a002dc50 a210001d
	inc  %l3                                   ! a002dc54 a604e001
.La002dc58:
	ldsb  [ %l3 ], %o1                         ! a002dc58 d24cc000
	cmp  %o1, 0                                ! a002dc5c 80a26000
	bne,a  .La002dc10                          ! a002dc60 32bfffec
	mov  0, %l0                                ! a002dc64 a0102000
.La002dc68:
	and  %i3, 7, %l3                           ! a002dc68 a60ee007
	cmp  %l3, 7                                ! a002dc6c 80a4e007
	be,a  .La002df9c                           ! a002dc70 228000cb
	sethi  %hi(0xfec00), %o7                   ! a002dc74 1f0003fb
.La002dc78:
	inc  %i3                                   ! a002dc78 b606e001
.La002dc7c:
	cmp  %i3, 0x1f                             ! a002dc7c 80a6e01f
	ble,a  .La002db90                          ! a002dc80 24bfffc4
	sll  %i3, 2, %o5                           ! a002dc84 9b2ee002
! "\nSystem Halt." (0x00199260), then the endless loop at 0xa002dd08.
	sethi  %hi(0x199000), %i0                  ! a002dc88 31000664
	ldsb  [ %i0 + 0x260 ], %i1                 ! a002dc8c f24e2260
	cmp  %i1, 0                                ! a002dc90 80a66000
	be  .La002dd08                             ! a002dc94 0280001d
	or  %i0, 0x260, %l3                        ! a002dc98 a6162260
	sethi  %hi(0xffc00), %l7                   ! a002dc9c 2f0003ff
	or  %l7, 0x3fe, %l6                        ! a002dca0 ac15e3fe
	sethi  %hi(0xc00b0000), %l4                ! a002dca4 293002c0
	mov  %l6, %l5                              ! a002dca8 aa100016
	mov  0, %l0                                ! a002dcac a0102000
.La002dcb0:
	call  .Lf - 0x135c                ! a002dcb0 7ffff968
	or  %l4, 0x14, %o0                         ! a002dcb4 90152014
	btst  0x20, %o0                            ! a002dcb8 808a2020
	bne  .La002dcd0                            ! a002dcbc 12800005
	inc  %l0                                   ! a002dcc0 a0042001
	cmp  %l0, %l5                              ! a002dcc4 80a40015
	bleu  .La002dcb0                           ! a002dcc8 08bffffa
	nop                                        ! a002dccc 01000000
.La002dcd0:
	sethi  %hi(0xc00b0000), %o0                ! a002dcd0 113002c0
	call  .Lf - 0x1350                ! a002dcd4 7ffff962
	ldsb  [ %l3 ], %o1                         ! a002dcd8 d24cc000
	ldsb  [ %l3 ], %i3                         ! a002dcdc f64cc000
	cmp  %i3, 0xa                              ! a002dce0 80a6e00a
	mov  0, %l0                                ! a002dce4 a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002dce8 233002c0
	be  .La002debc                             ! a002dcec 02800074
	mov  %l6, %l2                              ! a002dcf0 a4100016
	inc  %l3                                   ! a002dcf4 a604e001
.La002dcf8:
	ldsb  [ %l3 ], %i4                         ! a002dcf8 f84cc000
	cmp  %i4, 0                                ! a002dcfc 80a72000
	bne,a  .La002dcb0                          ! a002dd00 32bfffec
	mov  0, %l0                                ! a002dd04 a0102000
.La002dd08:
! ENDLESS LOOP: the function never returns (traps are still disabled).
	b  .La002dd08                              ! a002dd08 10800000
	nop                                        ! a002dd0c 01000000
.La002dd10:
! shared tails of the printing loops (per-character UART waits, "\r" after "\n"), reached by branches only.
	cmp  %l0, %l2                              ! a002dd10 80a40012
	bgu  .La002dd34                            ! a002dd14 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002dd18 113002c0
.La002dd1c:
	call  .Lf - 0x135c                ! a002dd1c 7ffff94d
	or  %l1, 0x14, %o0                         ! a002dd20 90146014
	btst  0x20, %o0                            ! a002dd24 808a2020
	be  .La002dd10                             ! a002dd28 02bffffa
	inc  %l0                                   ! a002dd2c a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002dd30 113002c0
.La002dd34:
	call  .Lf - 0x1350                ! a002dd34 7ffff94a
	mov  0xd, %o1                              ! a002dd38 9210200d
	b  .La002d620                              ! a002dd3c 10bffe39
	inc  %l3                                   ! a002dd40 a604e001
.La002dd44:
	cmp  %l0, %l2                              ! a002dd44 80a40012
	bgu  .La002dd68                            ! a002dd48 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002dd4c 113002c0
.La002dd50:
	call  .Lf - 0x135c                ! a002dd50 7ffff940
	or  %l1, 0x14, %o0                         ! a002dd54 90146014
	btst  0x20, %o0                            ! a002dd58 808a2020
	be  .La002dd44                             ! a002dd5c 02bffffa
	inc  %l0                                   ! a002dd60 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002dd64 113002c0
.La002dd68:
	call  .Lf - 0x1350                ! a002dd68 7ffff93d
	mov  0xd, %o1                              ! a002dd6c 9210200d
	b  .La002d718                              ! a002dd70 10bffe6a
	inc  %l3                                   ! a002dd74 a604e001
.La002dd78:
	cmp  %l0, %l1                              ! a002dd78 80a40011
	bgu  .La002dd9c                            ! a002dd7c 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002dd80 113002c0
.La002dd84:
	call  .Lf - 0x135c                ! a002dd84 7ffff933
	or  %l2, 0x14, %o0                         ! a002dd88 9014a014
	btst  0x20, %o0                            ! a002dd8c 808a2020
	be  .La002dd78                             ! a002dd90 02bffffa
	inc  %l0                                   ! a002dd94 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002dd98 113002c0
.La002dd9c:
	call  .Lf - 0x1350                ! a002dd9c 7ffff930
	mov  0xd, %o1                              ! a002dda0 9210200d
	b  .La002d8f4                              ! a002dda4 10bffed4
	inc  %l3                                   ! a002dda8 a604e001
.La002ddac:
	cmp  %l0, %l2                              ! a002ddac 80a40012
	bgu  .La002ddd0                            ! a002ddb0 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002ddb4 113002c0
.La002ddb8:
	call  .Lf - 0x135c                ! a002ddb8 7ffff926
	or  %l1, 0x14, %o0                         ! a002ddbc 90146014
	btst  0x20, %o0                            ! a002ddc0 808a2020
	be  .La002ddac                             ! a002ddc4 02bffffa
	inc  %l0                                   ! a002ddc8 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002ddcc 113002c0
.La002ddd0:
	call  .Lf - 0x1350                ! a002ddd0 7ffff923
	mov  0xd, %o1                              ! a002ddd4 9210200d
	b  .La002d7f4                              ! a002ddd8 10bffe87
	inc  %l3                                   ! a002dddc a604e001
.La002dde0:
	cmp  %l0, %l1                              ! a002dde0 80a40011
	bgu  .La002de04                            ! a002dde4 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002dde8 113002c0
.La002ddec:
	call  .Lf - 0x135c                ! a002ddec 7ffff919
	or  %l2, 0x14, %o0                         ! a002ddf0 9014a014
	btst  0x20, %o0                            ! a002ddf4 808a2020
	be  .La002dde0                             ! a002ddf8 02bffffa
	inc  %l0                                   ! a002ddfc a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002de00 113002c0
.La002de04:
	call  .Lf - 0x1350                ! a002de04 7ffff916
	mov  0xd, %o1                              ! a002de08 9210200d
	b  .La002daa8                              ! a002de0c 10bfff27
	inc  %l3                                   ! a002de10 a604e001
.La002de14:
	cmp  %l0, %l2                              ! a002de14 80a40012
	bgu  .La002de38                            ! a002de18 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002de1c 113002c0
.La002de20:
	call  .Lf - 0x135c                ! a002de20 7ffff90c
	or  %l1, 0x14, %o0                         ! a002de24 90146014
	btst  0x20, %o0                            ! a002de28 808a2020
	be  .La002de14                             ! a002de2c 02bffffa
	inc  %l0                                   ! a002de30 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002de34 113002c0
.La002de38:
	call  .Lf - 0x1350                ! a002de38 7ffff909
	mov  0xd, %o1                              ! a002de3c 9210200d
	b  .La002d994                              ! a002de40 10bffed5
	inc  %l3                                   ! a002de44 a604e001
.La002de48:
	cmp  %l0, %l1                              ! a002de48 80a40011
	bgu  .La002de6c                            ! a002de4c 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002de50 113002c0
.La002de54:
	call  .Lf - 0x135c                ! a002de54 7ffff8ff
	or  %l2, 0x14, %o0                         ! a002de58 9014a014
	btst  0x20, %o0                            ! a002de5c 808a2020
	be  .La002de48                             ! a002de60 02bffffa
	inc  %l0                                   ! a002de64 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002de68 113002c0
.La002de6c:
	call  .Lf - 0x1350                ! a002de6c 7ffff8fc
	mov  0xd, %o1                              ! a002de70 9210200d
	b  .La002dc58                              ! a002de74 10bfff79
	inc  %l3                                   ! a002de78 a604e001
.La002de7c:
	cmp  %l0, %l2                              ! a002de7c 80a40012
	bgu  .La002dea0                            ! a002de80 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002de84 113002c0
.La002de88:
	call  .Lf - 0x135c                ! a002de88 7ffff8f2
	or  %l1, 0x14, %o0                         ! a002de8c 90146014
	btst  0x20, %o0                            ! a002de90 808a2020
	be  .La002de7c                             ! a002de94 02bffffa
	inc  %l0                                   ! a002de98 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002de9c 113002c0
.La002dea0:
	call  .Lf - 0x1350                ! a002dea0 7ffff8ef
	mov  0xd, %o1                              ! a002dea4 9210200d
	b  .La002db50                              ! a002dea8 10bfff2a
	inc  %l3                                   ! a002deac a604e001
.La002deb0:
	cmp  %l0, %l2                              ! a002deb0 80a40012
	bgu  .La002ded4                            ! a002deb4 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002deb8 113002c0
.La002debc:
	call  .Lf - 0x135c                ! a002debc 7ffff8e5
	or  %l1, 0x14, %o0                         ! a002dec0 90146014
	btst  0x20, %o0                            ! a002dec4 808a2020
	be  .La002deb0                             ! a002dec8 02bffffa
	inc  %l0                                   ! a002decc a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002ded0 113002c0
.La002ded4:
	call  .Lf - 0x1350                ! a002ded4 7ffff8e2
	mov  0xd, %o1                              ! a002ded8 9210200d
	b  .La002dcf8                              ! a002dedc 10bfff87
	inc  %l3                                   ! a002dee0 a604e001
.La002dee4:
	ldsb  [ %l0 + 0x390 ], %l2                 ! a002dee4 e44c2390
	cmp  %l2, 0                                ! a002dee8 80a4a000
	be  .La002d914                             ! a002deec 02bffe8a
	or  %l0, 0x390, %l3                        ! a002def0 a6142390
	sethi  %hi(0x199000), %l1                  ! a002def4 23000664
	sethi  %hi(0xc00b0000), %l4                ! a002def8 293002c0
	ld  [ %l1 + 0x270 ], %l5                   ! a002defc ea046270
	mov  %l5, %i5                              ! a002df00 ba100015
	mov  0, %l0                                ! a002df04 a0102000
.La002df08:
	call  .Lf - 0x135c                ! a002df08 7ffff8d2
	or  %l4, 0x14, %o0                         ! a002df0c 90152014
	btst  0x20, %o0                            ! a002df10 808a2020
	bne  .La002df28                            ! a002df14 12800005
	inc  %l0                                   ! a002df18 a0042001
	cmp  %l0, %l5                              ! a002df1c 80a40015
	bleu  .La002df08                           ! a002df20 08bffffa
	nop                                        ! a002df24 01000000
.La002df28:
	sethi  %hi(0xc00b0000), %o0                ! a002df28 113002c0
	call  .Lf - 0x1350                ! a002df2c 7ffff8cc
	ldsb  [ %l3 ], %o1                         ! a002df30 d24cc000
	ldsb  [ %l3 ], %o5                         ! a002df34 da4cc000
	cmp  %o5, 0xa                              ! a002df38 80a3600a
	mov  0, %l0                                ! a002df3c a0102000
	sethi  %hi(0xc00b0000), %l2                ! a002df40 253002c0
	be  .La002df74                             ! a002df44 0280000c
	mov  %i5, %l1                              ! a002df48 a210001d
	inc  %l3                                   ! a002df4c a604e001
.La002df50:
	ldsb  [ %l3 ], %g1                         ! a002df50 c24cc000
	cmp  %g1, 0                                ! a002df54 80a06000
	bne,a  .La002df08                          ! a002df58 32bfffec
	mov  0, %l0                                ! a002df5c a0102000
	b  .La002d918                              ! a002df60 10bffe6e
	inc  %i3                                   ! a002df64 b606e001
.La002df68:
	cmp  %l0, %l1                              ! a002df68 80a40011
	bgu  .La002df8c                            ! a002df6c 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002df70 113002c0
.La002df74:
	call  .Lf - 0x135c                ! a002df74 7ffff8b7
	or  %l2, 0x14, %o0                         ! a002df78 9014a014
	btst  0x20, %o0                            ! a002df7c 808a2020
	be  .La002df68                             ! a002df80 02bffffa
	inc  %l0                                   ! a002df84 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002df88 113002c0
.La002df8c:
	call  .Lf - 0x1350                ! a002df8c 7ffff8b4
	mov  0xd, %o1                              ! a002df90 9210200d
	b  .La002df50                              ! a002df94 10bfffef
	inc  %l3                                   ! a002df98 a604e001
.La002df9c:
	ldsb  [ %o7 + 0x390 ], %o2                 ! a002df9c d44be390
	cmp  %o2, 0                                ! a002dfa0 80a2a000
	be  .La002dc78                             ! a002dfa4 02bfff35
	or  %o7, 0x390, %l3                        ! a002dfa8 a613e390
	sethi  %hi(0x199000), %o3                  ! a002dfac 17000664
	sethi  %hi(0xc00b0000), %l4                ! a002dfb0 293002c0
	ld  [ %o3 + 0x270 ], %l5                   ! a002dfb4 ea02e270
	mov  %l5, %i5                              ! a002dfb8 ba100015
	mov  0, %l0                                ! a002dfbc a0102000
.La002dfc0:
	call  .Lf - 0x135c                ! a002dfc0 7ffff8a4
	or  %l4, 0x14, %o0                         ! a002dfc4 90152014
	btst  0x20, %o0                            ! a002dfc8 808a2020
	bne  .La002dfe0                            ! a002dfcc 12800005
	inc  %l0                                   ! a002dfd0 a0042001
	cmp  %l0, %l5                              ! a002dfd4 80a40015
	bleu  .La002dfc0                           ! a002dfd8 08bffffa
	nop                                        ! a002dfdc 01000000
.La002dfe0:
	sethi  %hi(0xc00b0000), %o0                ! a002dfe0 113002c0
	call  .Lf - 0x1350                ! a002dfe4 7ffff89e
	ldsb  [ %l3 ], %o1                         ! a002dfe8 d24cc000
	ldsb  [ %l3 ], %o4                         ! a002dfec d84cc000
	cmp  %o4, 0xa                              ! a002dff0 80a3200a
	mov  0, %l0                                ! a002dff4 a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002dff8 233002c0
	be  .La002e02c                             ! a002dffc 0280000c
	mov  %i5, %l2                              ! a002e000 a410001d
	inc  %l3                                   ! a002e004 a604e001
.La002e008:
	ldsb  [ %l3 ], %l0                         ! a002e008 e04cc000
	cmp  %l0, 0                                ! a002e00c 80a42000
	bne,a  .La002dfc0                          ! a002e010 32bfffec
	mov  0, %l0                                ! a002e014 a0102000
	b  .La002dc7c                              ! a002e018 10bfff19
	inc  %i3                                   ! a002e01c b606e001
.La002e020:
	cmp  %l0, %l2                              ! a002e020 80a40012
	bgu  .La002e044                            ! a002e024 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002e028 113002c0
.La002e02c:
	call  .Lf - 0x135c                ! a002e02c 7ffff889
	or  %l1, 0x14, %o0                         ! a002e030 90146014
	btst  0x20, %o0                            ! a002e034 808a2020
	be  .La002e020                             ! a002e038 02bffffa
	inc  %l0                                   ! a002e03c a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002e040 113002c0
.La002e044:
	call  .Lf - 0x1350                ! a002e044 7ffff886
	mov  0xd, %o1                              ! a002e048 9210200d
	b  .La002e008                              ! a002e04c 10bfffef
	inc  %l3                                   ! a002e050 a604e001
.La002e054:
	ldsb  [ %l5 + 0x390 ], %i5                 ! a002e054 fa4d6390
	cmp  %i5, 0                                ! a002e058 80a76000
	be  .La002dacc                             ! a002e05c 02bffe9c
	or  %l5, 0x390, %l3                        ! a002e060 a6156390
	sethi  %hi(0xc00b0000), %l4                ! a002e064 293002c0
	mov  %i1, %l5                              ! a002e068 aa100019
	sethi  %hi(0x199000), %o0                  ! a002e06c 11000664
	ld  [ %o0 + 0x270 ], %i5                   ! a002e070 fa022270
	mov  0, %l0                                ! a002e074 a0102000
.La002e078:
	call  .Lf - 0x135c                ! a002e078 7ffff876
	or  %l4, 0x14, %o0                         ! a002e07c 90152014
	btst  0x20, %o0                            ! a002e080 808a2020
	bne  .La002e098                            ! a002e084 12800005
	inc  %l0                                   ! a002e088 a0042001
	cmp  %l0, %l5                              ! a002e08c 80a40015
	bleu  .La002e078                           ! a002e090 08bffffa
	nop                                        ! a002e094 01000000
.La002e098:
	ldsb  [ %l3 ], %o1                         ! a002e098 d24cc000
	call  .Lf - 0x1350                ! a002e09c 7ffff870
	sethi  %hi(0xc00b0000), %o0                ! a002e0a0 113002c0
	ldsb  [ %l3 ], %o1                         ! a002e0a4 d24cc000
	cmp  %o1, 0xa                              ! a002e0a8 80a2600a
	mov  0, %l0                                ! a002e0ac a0102000
	sethi  %hi(0xc00b0000), %l1                ! a002e0b0 233002c0
	be  .La002e0e4                             ! a002e0b4 0280000c
	mov  %i5, %l2                              ! a002e0b8 a410001d
	inc  %l3                                   ! a002e0bc a604e001
.La002e0c0:
	ldsb  [ %l3 ], %o7                         ! a002e0c0 de4cc000
	cmp  %o7, 0                                ! a002e0c4 80a3e000
	bne,a  .La002e078                          ! a002e0c8 32bfffec
	mov  0, %l0                                ! a002e0cc a0102000
	b  .La002dad0                              ! a002e0d0 10bffe80
	ld  [ %fp + -12 ], %o3                     ! a002e0d4 d607bff4
.La002e0d8:
	cmp  %l0, %l2                              ! a002e0d8 80a40012
	bgu  .La002e0fc                            ! a002e0dc 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002e0e0 113002c0
.La002e0e4:
	call  .Lf - 0x135c                ! a002e0e4 7ffff85b
	or  %l1, 0x14, %o0                         ! a002e0e8 90146014
	btst  0x20, %o0                            ! a002e0ec 808a2020
	be  .La002e0d8                             ! a002e0f0 02bffffa
	inc  %l0                                   ! a002e0f4 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002e0f8 113002c0
.La002e0fc:
	call  .Lf - 0x1350                ! a002e0fc 7ffff858
	mov  0xd, %o1                              ! a002e100 9210200d
	b  .La002e0c0                              ! a002e104 10bfffef
	inc  %l3                                   ! a002e108 a604e001
.La002e10c:
	sethi  %hi(0x198c00), %l0                  ! a002e10c 21000663
	sethi  %hi(0xffc00), %o4                   ! a002e110 190003ff
	or  %l0, 0x3a0, %l4                        ! a002e114 a81423a0
	or  %o4, 0x3fe, %l6                        ! a002e118 ac1323fe
	mov  0, %l1                                ! a002e11c a2102000
	sethi  %hi(0xc00b0000), %l5                ! a002e120 2b3002c0
	mov  4, %l3                                ! a002e124 a6102004
.La002e128:
	sra  %l7, %l3, %l2                         ! a002e128 a53dc013
	and  %l2, 0xf, %i0                         ! a002e12c b00ca00f
	ldub  [ %l4 + %i0 ], %l2                   ! a002e130 e40d0018
	b  .La002e148                              ! a002e134 10800005
	mov  0, %l0                                ! a002e138 a0102000
.La002e13c:
	cmp  %l0, %l6                              ! a002e13c 80a40016
	bgu  .La002e160                            ! a002e140 18800008
	sll  %l2, 0x18, %i1                        ! a002e144 b32ca018
.La002e148:
	call  .Lf - 0x135c                ! a002e148 7ffff842
	or  %l5, 0x14, %o0                         ! a002e14c 90156014
	btst  0x20, %o0                            ! a002e150 808a2020
	be  .La002e13c                             ! a002e154 02bffffa
	inc  %l0                                   ! a002e158 a0042001
	sll  %l2, 0x18, %i1                        ! a002e15c b32ca018
.La002e160:
	sra  %i1, 0x18, %o1                        ! a002e160 933e6018
	call  .Lf - 0x1350                ! a002e164 7ffff83e
	sethi  %hi(0xc00b0000), %o0                ! a002e168 113002c0
	inc  %l1                                   ! a002e16c a2046001
	cmp  %l1, 1                                ! a002e170 80a46001
	ble  .La002e128                            ! a002e174 04bfffed
	add  %l3, -4, %l3                          ! a002e178 a604fffc
	b  .La002d788                              ! a002e17c 10bffd83
	sethi  %hi(0x199000), %l7                  ! a002e180 2f000664
.La002e184:
	ld  [ %o7 + 4 ], %l1                       ! a002e184 e203e004
	ldsb  [ %l1 ], %o1                         ! a002e188 d24c4000
	cmp  %o1, 0                                ! a002e18c 80a26000
	be  .La002d778                             ! a002e190 02bffd7a
	mov  %o3, %l7                              ! a002e194 ae10000b
	sethi  %hi(0xc00b0000), %l6                ! a002e198 2d3002c0
	mov  %o2, %i5                              ! a002e19c ba10000a
	mov  0, %l0                                ! a002e1a0 a0102000
.La002e1a4:
	call  .Lf - 0x135c                ! a002e1a4 7ffff82b
	or  %l6, 0x14, %o0                         ! a002e1a8 9015a014
	btst  0x20, %o0                            ! a002e1ac 808a2020
	bne  .La002e1c4                            ! a002e1b0 12800005
	inc  %l0                                   ! a002e1b4 a0042001
	cmp  %l0, %l7                              ! a002e1b8 80a40017
	bleu  .La002e1a4                           ! a002e1bc 08bffffa
	nop                                        ! a002e1c0 01000000
.La002e1c4:
	sethi  %hi(0xc00b0000), %o0                ! a002e1c4 113002c0
	call  .Lf - 0x1350                ! a002e1c8 7ffff825
	ldsb  [ %l1 ], %o1                         ! a002e1cc d24c4000
	ldsb  [ %l1 ], %o2                         ! a002e1d0 d44c4000
	cmp  %o2, 0xa                              ! a002e1d4 80a2a00a
	mov  0, %l0                                ! a002e1d8 a0102000
	sethi  %hi(0xc00b0000), %l3                ! a002e1dc 273002c0
	be  .La002e210                             ! a002e1e0 0280000c
	mov  %i5, %l4                              ! a002e1e4 a810001d
	inc  %l1                                   ! a002e1e8 a2046001
.La002e1ec:
	ldsb  [ %l1 ], %o3                         ! a002e1ec d64c4000
	cmp  %o3, 0                                ! a002e1f0 80a2e000
	bne,a  .La002e1a4                          ! a002e1f4 32bfffec
	mov  0, %l0                                ! a002e1f8 a0102000
	b  .La002d77c                              ! a002e1fc 10bffd60
	cmp  %l2, 0x11                             ! a002e200 80a4a011
.La002e204:
	cmp  %l0, %l4                              ! a002e204 80a40014
	bgu  .La002e228                            ! a002e208 18800008
	sethi  %hi(0xc00b0000), %o0                ! a002e20c 113002c0
.La002e210:
	call  .Lf - 0x135c                ! a002e210 7ffff810
	or  %l3, 0x14, %o0                         ! a002e214 9014e014
	btst  0x20, %o0                            ! a002e218 808a2020
	be  .La002e204                             ! a002e21c 02bffffa
	inc  %l0                                   ! a002e220 a0042001
	sethi  %hi(0xc00b0000), %o0                ! a002e224 113002c0
.La002e228:
	call  .Lf - 0x1350                ! a002e228 7ffff80d
	mov  0xd, %o1                              ! a002e22c 9210200d
	b  .La002e1ec                              ! a002e230 10bfffef
	inc  %l1                                   ! a002e234 a2046001
	.size FUN_a002d5ac, .-FUN_a002d5ac
