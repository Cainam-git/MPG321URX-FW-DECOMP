# fn_4000574c: 0x4000574c-0x400058d9 (firmware file offset 0x3574c-0x358d9), 160 instructions
# Called from: fn_400058dc
# Calls: fn_40005460, fn_40005518
# Other literal values: 0x3ffe4240, 0x0000ffff, 0x00001000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000574c, @function
fn_4000574c:
	entry	a1, 64                  # 4000574c
	s32i.n	a2, a1, 16              # 4000574f
	movi.n	a11, 1                  # 40005751
	s32i.n	a11, a1, 0              # 40005753
	l32i.n	a10, a1, 16             # 40005755
	addi.n	a10, a10, 3             # 40005757
	movi.n	a11, 4                  # 40005759
	call8	fn_40005460             # 4000575b
	s32i.n	a10, a1, 4              # 4000575e
	movi.n	a13, 42                 # 40005760
	l32i.n	a12, a1, 16             # 40005762
	l8ui	a12, a12, 0             # 40005764
	bne	a12, a13, .L4000578b    # 40005767
	movi	a14, 113                # 4000576a
	l32i.n	a13, a1, 16             # 4000576d
	l8ui	a13, a13, 1             # 4000576f
	bne	a13, a14, .L4000578b    # 40005772
	movi	a15, 116                # 40005775
	l32i.n	a14, a1, 16             # 40005778
	l8ui	a14, a14, 2             # 4000577a
	bne	a14, a15, .L4000578b    # 4000577d
	l32r	a2, lit_3ffe1d70        # 40005780  = 0x3ffe4240
	l32r	a15, lit_3ffe1b70       # 40005783  = 0x0000ffff
	s32i.n	a15, a2, 4              # 40005786
	j	.L400058d6              # 40005788
.L4000578b:
	movi.n	a4, 42                  # 4000578b
	l32i.n	a3, a1, 16              # 4000578d
	l8ui	a3, a3, 0               # 4000578f
	bne	a3, a4, .L400057d3      # 40005792
	movi.n	a5, 82                  # 40005795
	l32i.n	a4, a1, 16              # 40005797
	l8ui	a4, a4, 1               # 40005799
	bne	a4, a5, .L400057d3      # 4000579c
	movi.n	a6, 68                  # 4000579f
	l32i.n	a5, a1, 16              # 400057a1
	l8ui	a5, a5, 2               # 400057a3
	bne	a5, a6, .L400057d3      # 400057a6
	l32i.n	a10, a1, 4              # 400057a9
	movi.n	a11, 0                  # 400057ab
	call8	fn_40005518             # 400057ad
	l32i.n	a6, a1, 16              # 400057b0
	l8ui	a6, a6, 7               # 400057b2
	beq	a6, a10, .L400057c2     # 400057b5
	l32r	a8, lit_3ffe1d70        # 400057b8  = 0x3ffe4240
	movi.n	a7, 0                   # 400057bb
	s32i.n	a7, a8, 4               # 400057bd
	j	.L400057d0              # 400057bf
.L400057c2:
	l32r	a12, lit_3ffe1d70       # 400057c2  = 0x3ffe4240
	l32i.n	a11, a1, 4              # 400057c5
	s32i.n	a11, a12, 8             # 400057c7
	l32r	a10, lit_3ffe1d70       # 400057c9  = 0x3ffe4240
	movi.n	a9, 1                   # 400057cc
	s32i.n	a9, a10, 4              # 400057ce
.L400057d0:
	j	.L400058d6              # 400057d0
.L400057d3:
	movi.n	a14, 42                 # 400057d3
	l32i.n	a13, a1, 16             # 400057d5
	l8ui	a13, a13, 0             # 400057d7
	bne	a13, a14, .L4000581f    # 400057da
	movi.n	a15, 87                 # 400057dd
	l32i.n	a14, a1, 16             # 400057df
	l8ui	a14, a14, 1             # 400057e1
	bne	a14, a15, .L4000581f    # 400057e4
	movi.n	a2, 68                  # 400057e7
	l32i.n	a15, a1, 16             # 400057e9
	l8ui	a15, a15, 2             # 400057eb
	bne	a15, a2, .L4000581f     # 400057ee
	l32i.n	a10, a1, 16             # 400057f1
	addi.n	a10, a10, 7             # 400057f3
	movi.n	a11, 8                  # 400057f5
	call8	fn_40005460             # 400057f7
	s32i.n	a10, a1, 8              # 400057fa
	l32r	a3, lit_3ffe1d70        # 400057fc  = 0x3ffe4240
	l32i.n	a2, a1, 4               # 400057ff
	s32i.n	a2, a3, 8               # 40005801
	l32r	a15, lit_3ffe1d70       # 40005803  = 0x3ffe4240
	l32i.n	a14, a1, 8              # 40005806
	s32i.n	a14, a15, 12            # 40005808
	l32r	a14, lit_3ffe1d70       # 4000580a  = 0x3ffe4240
	l32i.n	a13, a1, 16             # 4000580d
	l8ui	a13, a13, 15            # 4000580f
	s8i	a13, a14, 16            # 40005812
	l32r	a12, lit_3ffe1d70       # 40005815  = 0x3ffe4240
	movi.n	a11, 2                  # 40005818
	s32i.n	a11, a12, 4             # 4000581a
	j	.L400058d6              # 4000581c
.L4000581f:
	movi.n	a5, 42                  # 4000581f
	l32i.n	a4, a1, 16              # 40005821
	l8ui	a4, a4, 0               # 40005823
	bne	a4, a5, .L40005847      # 40005826
	movi.n	a6, 82                  # 40005829
	l32i.n	a5, a1, 16              # 4000582b
	l8ui	a5, a5, 1               # 4000582d
	bne	a5, a6, .L40005847      # 40005830
	movi.n	a7, 66                  # 40005833
	l32i.n	a6, a1, 16              # 40005835
	l8ui	a6, a6, 2               # 40005837
	bne	a6, a7, .L40005847      # 4000583a
	l32r	a8, lit_3ffe1d70        # 4000583d  = 0x3ffe4240
	movi.n	a7, 3                   # 40005840
	s32i.n	a7, a8, 4               # 40005842
	j	.L400058d6              # 40005844
.L40005847:
	movi.n	a10, 42                 # 40005847
	l32i.n	a9, a1, 16              # 40005849
	l8ui	a9, a9, 0               # 4000584b
	bne	a9, a10, .L4000586f     # 4000584e
	movi.n	a11, 87                 # 40005851
	l32i.n	a10, a1, 16             # 40005853
	l8ui	a10, a10, 1             # 40005855
	bne	a10, a11, .L4000586f    # 40005858
	movi.n	a12, 66                 # 4000585b
	l32i.n	a11, a1, 16             # 4000585d
	l8ui	a11, a11, 2             # 4000585f
	bne	a11, a12, .L4000586f    # 40005862
	l32r	a13, lit_3ffe1d70       # 40005865  = 0x3ffe4240
	movi.n	a12, 4                  # 40005868
	s32i.n	a12, a13, 4             # 4000586a
	j	.L400058d6              # 4000586c
.L4000586f:
	movi.n	a15, 42                 # 4000586f
	l32i.n	a14, a1, 16             # 40005871
	l8ui	a14, a14, 0             # 40005873
	bne	a14, a15, .L400058d2    # 40005876
	movi.n	a2, 67                  # 40005879
	l32i.n	a15, a1, 16             # 4000587b
	l8ui	a15, a15, 1             # 4000587d
	bne	a15, a2, .L400058d2     # 40005880
	movi.n	a3, 66                  # 40005883
	l32i.n	a2, a1, 16              # 40005885
	l8ui	a2, a2, 2               # 40005887
	bne	a2, a3, .L400058d2      # 4000588a
	l32i.n	a10, a1, 4              # 4000588d
	movi.n	a11, 0                  # 4000588f
	call8	fn_40005518             # 40005891
	l32i.n	a3, a1, 16              # 40005894
	l8ui	a3, a3, 7               # 40005896
	beq	a3, a10, .L400058a6     # 40005899
	l32r	a5, lit_3ffe1d70        # 4000589c  = 0x3ffe4240
	movi.n	a4, 0                   # 4000589f
	s32i.n	a4, a5, 4               # 400058a1
	j	.L400058cf              # 400058a3
.L400058a6:
	l32r	a11, lit_3ffe1d70       # 400058a6  = 0x3ffe4240
	l32i.n	a10, a1, 4              # 400058a9
	s32i.n	a10, a11, 8             # 400058ab
	l32r	a9, lit_3ffe1d70        # 400058ad  = 0x3ffe4240
	movi.n	a8, 5                   # 400058b0
	s32i.n	a8, a9, 4               # 400058b2
	l32r	a7, lit_3ffe1df0        # 400058b4  = 0x00001000
	l32i.n	a6, a1, 4               # 400058b7
	bne	a6, a7, .L400058c7      # 400058b9
	l32r	a13, lit_3ffe1d70       # 400058bc  = 0x3ffe4240
	movi.n	a12, 1                  # 400058bf
	s8i	a12, a13, 24            # 400058c1
	j	.L400058cf              # 400058c4
.L400058c7:
	l32r	a15, lit_3ffe1d70       # 400058c7  = 0x3ffe4240
	movi.n	a14, 0                  # 400058ca
	s8i	a14, a15, 24            # 400058cc
.L400058cf:
	j	.L400058d6              # 400058cf
.L400058d2:
	movi.n	a2, 0                   # 400058d2
	s32i.n	a2, a1, 0               # 400058d4
.L400058d6:
	l32i.n	a2, a1, 0               # 400058d6
	retw.n                          # 400058d8
	.size	fn_4000574c, . - fn_4000574c
