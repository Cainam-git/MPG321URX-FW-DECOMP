# reset_40000400: 0x40000400-0x400007ff (firmware file offset 0x30400-0x307ff), 82 instructions
# Jumps over its own literal words (lit_40000404-lit_40000434). Writes INTENABLE, VECBASE
# (lit_40000408), ATOMCTL and PS (rsil 1); writes the instruction and data TLB entries (witlb,
# wdtlb) from the nibbles of lit_4000040c; calls (callx0) the address in lit_40000418 when it is
# not 0; copies the regions listed in section_table to RAM; sets WINDOWSTART, WINDOWBASE and
# EXCSAVE2-EXCSAVE5 (the EXCSAVE4 and EXCSAVE5 values are also stored at data_3ffe2a70 and
# data_3ffe2be0); then calls (call0) fn_40000800.
# The bytes after the call up to 0x40000800 are zero.

reset_40000400:
	j	.L40000440              # 40000400
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x40000404
lit_40000404:
	.word	0x00000000              # 40000404
lit_40000408:
	.word	vec_base                # 40000408
lit_4000040c:
	.word	0x2222111f              # 4000040c
lit_40000410:
	.word	0xe0000000              # 40000410
lit_40000414:
	.word	.L40000494              # 40000414
lit_40000418:
	.word	0x00000000              # 40000418
lit_4000041c:
	.word	section_table           # 4000041c
lit_40000420:
	.word	0x00000000              # 40000420
lit_40000424:
	.word	fn_4000a680             # 40000424
lit_40000428:
	.word	0x00000000              # 40000428
lit_4000042c:
	.word	data_3ffe2a70           # 4000042c
lit_40000430:
	.word	fn_4000a74c             # 40000430
lit_40000434:
	.word	data_3ffe2be0           # 40000434
	.space	8, 0                    # 8 zero bytes, 0x40000438-0x4000043f
.L40000440:
	movi.n	a0, 0                   # 40000440
	wsr.intenable	a0              # 40000442
	l32r	a2, lit_40000404        # 40000445  = 0x00000000
	rsr.prid	a3              # 40000448
	extui	a3, a3, 0, 8            # 4000044b
	beqz.n	a2, .L40000454          # 4000044e
	bnez.n	a3, .L40000454          # 40000450
	s32i.n	a0, a2, 0               # 40000452
.L40000454:
	l32r	a2, lit_40000408        # 40000454  = vec_base
	wsr.vecbase	a2              # 40000457
	movi.n	a3, 21                  # 4000045a
	wsr.atomctl	a3              # 4000045c
	rsil	a2, 1                   # 4000045f
	l32r	a2, lit_4000040c        # 40000462  = 0x2222111f
	l32r	a5, lit_40000410        # 40000465  = 0xe0000000
	l32r	a6, lit_40000414        # 40000468  = .L40000494
	movi.n	a3, 0                   # 4000046b
	mov.n	a7, a2                  # 4000046d
	and	a6, a6, a5              # 4000046f
	j	.L40000494              # 40000472
	.space	11, 0                   # 11 zero bytes, 0x40000475-0x4000047f
.L40000480:
	witlb	a4, a3                  # 40000480
	isync                           # 40000483
	nop.n                           # 40000486
	nop                             # 40000488
	sub	a3, a3, a5              # 4000048b
	bltui	a3, 16, .L400004a6      # 4000048e
.L40000491:
	srli	a7, a7, 4               # 40000491
.L40000494:
	extui	a4, a7, 0, 4            # 40000494
	beq	a3, a6, .L40000480      # 40000497
	witlb	a4, a3                  # 4000049a
	sub	a3, a3, a5              # 4000049d
	bgeui	a3, 16, .L40000491      # 400004a0
	isync                           # 400004a3
.L400004a6:
	l32r	a5, lit_40000410        # 400004a6  = 0xe0000000
	movi.n	a3, 0                   # 400004a9
	mov.n	a7, a2                  # 400004ab
.L400004ad:
	extui	a4, a7, 0, 4            # 400004ad
	wdtlb	a4, a3                  # 400004b0
	sub	a3, a3, a5              # 400004b3
	srli	a7, a7, 4               # 400004b6
	bgeui	a3, 16, .L400004ad      # 400004b9
	dsync                           # 400004bc
	l32r	a2, lit_40000418        # 400004bf  = 0x00000000
	beqz	a2, .L400004cc          # 400004c2
	callx0	a2                      # 400004c5
	movi.n	a0, 0                   # 400004c8
	bnez.n	a2, .L400004f2          # 400004ca
.L400004cc:
	l32r	a2, lit_4000041c        # 400004cc  = section_table
	beqz.n	a2, .L400004f2          # 400004cf
.L400004d1:
	l32i.n	a3, a2, 0               # 400004d1
	l32i.n	a4, a2, 4               # 400004d3
	l32i.n	a5, a2, 8               # 400004d5
	addi.n	a2, a2, 12              # 400004d7
	bgeu	a3, a4, .L400004ec      # 400004d9
.L400004dc:
	l32i.n	a6, a5, 0               # 400004dc
	addi.n	a5, a5, 4               # 400004de
	s32i.n	a6, a3, 0               # 400004e0
	addi.n	a3, a3, 4               # 400004e2
	bltu	a3, a4, .L400004dc      # 400004e4
	j	.L400004d1              # 400004e7
	.balign	4, 0                    # 2 zero bytes up to the 4-byte boundary 0x400004ec
.L400004ec:
	bnez	a3, .L400004d1          # 400004ec
	bnez	a5, .L400004d1          # 400004ef
.L400004f2:
	isync                           # 400004f2
	movi.n	a1, 1                   # 400004f5
	wsr.windowstart	a1              # 400004f7
	wsr.windowbase	a0              # 400004fa
	rsync                           # 400004fd
	movi.n	a0, 0                   # 40000500
	l32r	a4, lit_40000420        # 40000502  = 0x00000000
	wsr.excsave2	a4              # 40000505
	l32r	a4, lit_40000424        # 40000508  = fn_4000a680
	wsr.excsave3	a4              # 4000050b
	l32r	a4, lit_40000428        # 4000050e  = 0x00000000
	wsr.excsave4	a4              # 40000511
	l32r	a5, lit_4000042c        # 40000514  = data_3ffe2a70
	s32i	a4, a5, 0               # 40000517
	l32r	a4, lit_40000430        # 4000051a  = fn_4000a74c
	wsr.excsave5	a4              # 4000051d
	l32r	a5, lit_40000434        # 40000520  = data_3ffe2be0
	s32i	a4, a5, 0               # 40000523
	call0	fn_40000800             # 40000526
	.org	0x800, 0
