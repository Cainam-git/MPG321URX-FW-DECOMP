# fn_4000802c: 0x4000802c-0x400082ca (firmware file offset 0x3802c-0x382ca), 250 instructions
# Address stored in the words at: 0x4000c79c
# Calls: fn_40006be8
# Other literal values: 0x3ffe5594, 0x3ffe2bf0, 0x3ffe2c24, 0x3ffe2d30, 0x3ffe3eb0, 0x3ffe2c28, 0x3ffe2c2c,
#                       0x3ffe2c30, 0x3ffe2c34, 0x3ffe2c38, 0x3ffe2c3c, 0x3ffe2c40, 0x3ffe3ef0, 0x3ffe3eb8,
#                       0x3ffe3eb4, 0x3ffe3eb6, 0x3ffe3eb2, 0x3ffe3ec0, 0x3ffe3ec2, 0x3ffe3ebc, 0x3ffe3ebe,
#                       0x3ffe3ef6, 0x3ffe3ef8, 0x3ffe3eba, 0x3ffe3f02, 0x3ffe3ef4, 0x3ffe3ef2, 0x3ffe3efa,
#                       0x3ffe3efc, 0x3ffe3f00, 0x3ffe3efe

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000802c, @function
fn_4000802c:
	entry	a1, 80                  # 4000802c
	l32r	a2, lit_3ffe2158        # 4000802f  = 0x3ffe5594
	l32i.n	a2, a2, 0               # 40008032
	bnei	a2, 1, .L4000803a       # 40008034
	j	.L400082c9              # 40008037
.L4000803a:
	l32r	a3, lit_3ffe1a80        # 4000803a  = 0x3ffe2bf0
	l32i.n	a3, a3, 32              # 4000803d
	beqi	a3, 1, .L40008045       # 4000803f
	j	.L400081b1              # 40008042
.L40008045:
	l32r	a13, lit_3ffe1b08       # 40008045  = 0x3ffe2c24
	l32i.n	a13, a13, 0             # 40008048
	mov.n	a14, a1                 # 4000804a
	movi	a15, 170                # 4000804c
	l32r	a2, lit_3ffe20e0        # 4000804f  = 0x3ffe2d30
	l32i.n	a2, a2, 0               # 40008052
	slli	a2, a2, 8               # 40008054
	l32r	a3, lit_3ffe1ac0        # 40008057  = 0x3ffe3eb0
	addx2	a13, a13, a3            # 4000805a
	l16ui	a13, a13, 0             # 4000805d
	slli	a13, a13, 16            # 40008060
	add.n	a13, a13, a2            # 40008063
	add.n	a13, a13, a15           # 40008065
	s32i.n	a13, a14, 0             # 40008067
	l32r	a12, lit_3ffe215c       # 40008069  = 0x3ffe2c28
	l32i.n	a12, a12, 0             # 4000806c
	l32r	a14, lit_3ffe2160       # 4000806e  = 0x3ffe2c2c
	l32i.n	a14, a14, 0             # 40008071
	addi.n	a13, a1, 4              # 40008073
	l32r	a15, lit_3ffe1ac0       # 40008075  = 0x3ffe3eb0
	addx2	a14, a14, a15           # 40008078
	l16ui	a14, a14, 0             # 4000807b
	slli	a14, a14, 16            # 4000807e
	l32r	a15, lit_3ffe1ac0       # 40008081  = 0x3ffe3eb0
	addx2	a12, a12, a15           # 40008084
	l16ui	a12, a12, 0             # 40008087
	add.n	a12, a12, a14           # 4000808a
	s32i.n	a12, a13, 0             # 4000808c
	l32r	a11, lit_3ffe2164       # 4000808e  = 0x3ffe2c30
	l32i.n	a11, a11, 0             # 40008091
	l32r	a13, lit_3ffe2168       # 40008093  = 0x3ffe2c34
	l32i.n	a13, a13, 0             # 40008096
	addi.n	a12, a1, 8              # 40008098
	l32r	a14, lit_3ffe1ac0       # 4000809a  = 0x3ffe3eb0
	addx2	a13, a13, a14           # 4000809d
	l16ui	a13, a13, 0             # 400080a0
	slli	a13, a13, 16            # 400080a3
	l32r	a14, lit_3ffe1ac0       # 400080a6  = 0x3ffe3eb0
	addx2	a11, a11, a14           # 400080a9
	l16ui	a11, a11, 0             # 400080ac
	add.n	a11, a11, a13           # 400080af
	s32i.n	a11, a12, 0             # 400080b1
	l32r	a10, lit_3ffe216c       # 400080b3  = 0x3ffe2c38
	l32i.n	a10, a10, 0             # 400080b6
	l32r	a12, lit_3ffe2170       # 400080b8  = 0x3ffe2c3c
	l32i.n	a12, a12, 0             # 400080bb
	addi.n	a11, a1, 12             # 400080bd
	l32r	a13, lit_3ffe1ac0       # 400080bf  = 0x3ffe3eb0
	addx2	a12, a12, a13           # 400080c2
	l16ui	a12, a12, 0             # 400080c5
	slli	a12, a12, 16            # 400080c8
	l32r	a13, lit_3ffe1ac0       # 400080cb  = 0x3ffe3eb0
	addx2	a10, a10, a13           # 400080ce
	l16ui	a10, a10, 0             # 400080d1
	add.n	a10, a10, a12           # 400080d4
	s32i.n	a10, a11, 0             # 400080d6
	l32r	a9, lit_3ffe2174        # 400080d8  = 0x3ffe2c40
	l32i.n	a9, a9, 0               # 400080db
	addi	a10, a1, 16             # 400080dd
	l32r	a11, lit_3ffe1ac0       # 400080e0  = 0x3ffe3eb0
	addx2	a9, a9, a11             # 400080e3
	l16ui	a9, a9, 0               # 400080e6
	s32i.n	a9, a10, 0              # 400080e9
	l32r	a8, lit_3ffe1b08        # 400080eb  = 0x3ffe2c24
	l32i.n	a8, a8, 0               # 400080ee
	l32r	a10, lit_3ffe215c       # 400080f0  = 0x3ffe2c28
	l32i.n	a10, a10, 0             # 400080f3
	addi	a9, a1, 20              # 400080f5
	l32r	a11, lit_3ffe1ac4       # 400080f8  = 0x3ffe3ef0
	addx2	a10, a10, a11           # 400080fb
	l16ui	a10, a10, 0             # 400080fe
	srli	a10, a10, 2             # 40008101
	slli	a10, a10, 24            # 40008104
	l32r	a11, lit_3ffe1ac4       # 40008107  = 0x3ffe3ef0
	addx2	a8, a8, a11             # 4000810a
	l16ui	a8, a8, 0               # 4000810d
	srli	a8, a8, 2               # 40008110
	slli	a8, a8, 16              # 40008113
	add.n	a8, a8, a10             # 40008116
	s32i.n	a8, a9, 0               # 40008118
	l32r	a7, lit_3ffe2164        # 4000811a  = 0x3ffe2c30
	l32i.n	a7, a7, 0               # 4000811d
	l32r	a11, lit_3ffe2160       # 4000811f  = 0x3ffe2c2c
	l32i.n	a11, a11, 0             # 40008122
	l32r	a10, lit_3ffe2168       # 40008124  = 0x3ffe2c34
	l32i.n	a10, a10, 0             # 40008127
	l32r	a9, lit_3ffe216c        # 40008129  = 0x3ffe2c38
	l32i.n	a9, a9, 0               # 4000812c
	addi	a8, a1, 24              # 4000812e
	l32r	a12, lit_3ffe1ac4       # 40008131  = 0x3ffe3ef0
	addx2	a9, a9, a12             # 40008134
	l16ui	a9, a9, 0               # 40008137
	srli	a9, a9, 2               # 4000813a
	slli	a9, a9, 24              # 4000813d
	l32r	a12, lit_3ffe1ac4       # 40008140  = 0x3ffe3ef0
	addx2	a10, a10, a12           # 40008143
	l16ui	a10, a10, 0             # 40008146
	srli	a10, a10, 2             # 40008149
	slli	a10, a10, 16            # 4000814c
	l32r	a12, lit_3ffe1ac4       # 4000814f  = 0x3ffe3ef0
	addx2	a11, a11, a12           # 40008152
	l16ui	a11, a11, 0             # 40008155
	srli	a11, a11, 2             # 40008158
	l32r	a12, lit_3ffe1ac4       # 4000815b  = 0x3ffe3ef0
	addx2	a7, a7, a12             # 4000815e
	l16ui	a7, a7, 0               # 40008161
	srli	a7, a7, 2               # 40008164
	slli	a7, a7, 8               # 40008167
	add.n	a7, a7, a11             # 4000816a
	add.n	a7, a7, a10             # 4000816c
	add.n	a7, a7, a9              # 4000816e
	s32i.n	a7, a8, 0               # 40008170
	l32r	a6, lit_3ffe2174        # 40008172  = 0x3ffe2c40
	l32i.n	a6, a6, 0               # 40008175
	l32r	a8, lit_3ffe2170        # 40008177  = 0x3ffe2c3c
	l32i.n	a8, a8, 0               # 4000817a
	addi	a7, a1, 28              # 4000817c
	l32r	a9, lit_3ffe1ac4        # 4000817f  = 0x3ffe3ef0
	addx2	a8, a8, a9              # 40008182
	l16ui	a8, a8, 0               # 40008185
	srli	a8, a8, 2               # 40008188
	l32r	a9, lit_3ffe1ac4        # 4000818b  = 0x3ffe3ef0
	addx2	a6, a6, a9              # 4000818e
	l16ui	a6, a6, 0               # 40008191
	srli	a6, a6, 2               # 40008194
	slli	a6, a6, 8               # 40008197
	add.n	a6, a6, a8              # 4000819a
	s32i.n	a6, a7, 0               # 4000819c
	addi	a5, a1, 32              # 4000819e
	movi.n	a4, 85                  # 400081a1
	s32i.n	a4, a5, 0               # 400081a3
	movi.n	a10, 9                  # 400081a5
	mov.n	a11, a1                 # 400081a7
	movi.n	a12, 1                  # 400081a9
	call8	fn_40006be8             # 400081ab
	j	.L400082c9              # 400081ae
.L400081b1:
	mov.n	a10, a1                 # 400081b1
	movi	a11, 170                # 400081b3
	l32r	a12, lit_3ffe20e0       # 400081b6  = 0x3ffe2d30
	l32i.n	a12, a12, 0             # 400081b9
	slli	a12, a12, 8             # 400081bb
	l32r	a9, lit_3ffe2178        # 400081be  = 0x3ffe3eb8
	l16ui	a9, a9, 0               # 400081c1
	slli	a9, a9, 16              # 400081c4
	add.n	a9, a9, a12             # 400081c7
	add.n	a9, a9, a11             # 400081c9
	s32i.n	a9, a10, 0              # 400081cb
	addi.n	a7, a1, 4               # 400081cd
	l32r	a8, lit_3ffe217c        # 400081cf  = 0x3ffe3eb4
	l16ui	a8, a8, 0               # 400081d2
	slli	a8, a8, 16              # 400081d5
	l32r	a6, lit_3ffe2180        # 400081d8  = 0x3ffe3eb6
	l16ui	a6, a6, 0               # 400081db
	add.n	a6, a6, a8              # 400081de
	s32i.n	a6, a7, 0               # 400081e0
	addi.n	a4, a1, 8               # 400081e2
	l32r	a5, lit_3ffe1ac0        # 400081e4  = 0x3ffe3eb0
	l16ui	a5, a5, 0               # 400081e7
	slli	a5, a5, 16              # 400081ea
	l32r	a3, lit_3ffe2184        # 400081ed  = 0x3ffe3eb2
	l16ui	a3, a3, 0               # 400081f0
	add.n	a3, a3, a5              # 400081f3
	s32i.n	a3, a4, 0               # 400081f5
	addi.n	a15, a1, 12             # 400081f7
	l32r	a2, lit_3ffe2188        # 400081f9  = 0x3ffe3ec0
	l16ui	a2, a2, 0               # 400081fc
	slli	a2, a2, 16              # 400081ff
	l32r	a14, lit_3ffe218c       # 40008202  = 0x3ffe3ec2
	l16ui	a14, a14, 0             # 40008205
	add.n	a14, a14, a2            # 40008208
	s32i.n	a14, a15, 0             # 4000820a
	addi	a12, a1, 16             # 4000820c
	l32r	a13, lit_3ffe2190       # 4000820f  = 0x3ffe3ebc
	l16ui	a13, a13, 0             # 40008212
	slli	a13, a13, 16            # 40008215
	l32r	a11, lit_3ffe2194       # 40008218  = 0x3ffe3ebe
	l16ui	a11, a11, 0             # 4000821b
	add.n	a11, a11, a13           # 4000821e
	s32i.n	a11, a12, 0             # 40008220
	addi	a9, a1, 20              # 40008222
	l32r	a10, lit_3ffe2198       # 40008225  = 0x3ffe3ef6
	l16ui	a10, a10, 0             # 40008228
	srli	a10, a10, 2             # 4000822b
	slli	a10, a10, 24            # 4000822e
	l32r	a11, lit_3ffe219c       # 40008231  = 0x3ffe3ef8
	l16ui	a11, a11, 0             # 40008234
	srli	a11, a11, 2             # 40008237
	slli	a11, a11, 16            # 4000823a
	l32r	a8, lit_3ffe21a0        # 4000823d  = 0x3ffe3eba
	l16ui	a8, a8, 0               # 40008240
	add.n	a8, a8, a11             # 40008243
	add.n	a8, a8, a10             # 40008245
	s32i.n	a8, a9, 0               # 40008247
	addi	a6, a1, 24              # 40008249
	l32r	a7, lit_3ffe21a4        # 4000824c  = 0x3ffe3f02
	l16ui	a7, a7, 0               # 4000824f
	srli	a7, a7, 2               # 40008252
	slli	a7, a7, 24              # 40008255
	l32r	a8, lit_3ffe1ac4        # 40008258  = 0x3ffe3ef0
	l16ui	a8, a8, 0               # 4000825b
	srli	a8, a8, 2               # 4000825e
	slli	a8, a8, 16              # 40008261
	l32r	a9, lit_3ffe21a8        # 40008264  = 0x3ffe3ef4
	l16ui	a9, a9, 0               # 40008267
	srli	a9, a9, 2               # 4000826a
	l32r	a5, lit_3ffe21ac        # 4000826d  = 0x3ffe3ef2
	l16ui	a5, a5, 0               # 40008270
	srli	a5, a5, 2               # 40008273
	slli	a5, a5, 8               # 40008276
	add.n	a5, a5, a9              # 40008279
	add.n	a5, a5, a8              # 4000827b
	add.n	a5, a5, a7              # 4000827d
	s32i.n	a5, a6, 0               # 4000827f
	addi	a3, a1, 28              # 40008281
	l32r	a4, lit_3ffe21b0        # 40008284  = 0x3ffe3efa
	l16ui	a4, a4, 0               # 40008287
	srli	a4, a4, 2               # 4000828a
	slli	a4, a4, 24              # 4000828d
	l32r	a5, lit_3ffe21b4        # 40008290  = 0x3ffe3efc
	l16ui	a5, a5, 0               # 40008293
	srli	a5, a5, 2               # 40008296
	slli	a5, a5, 16              # 40008299
	l32r	a6, lit_3ffe21b8        # 4000829c  = 0x3ffe3f00
	l16ui	a6, a6, 0               # 4000829f
	srli	a6, a6, 2               # 400082a2
	l32r	a2, lit_3ffe21bc        # 400082a5  = 0x3ffe3efe
	l16ui	a2, a2, 0               # 400082a8
	srli	a2, a2, 2               # 400082ab
	slli	a2, a2, 8               # 400082ae
	add.n	a2, a2, a6              # 400082b1
	add.n	a2, a2, a5              # 400082b3
	add.n	a2, a2, a4              # 400082b5
	s32i.n	a2, a3, 0               # 400082b7
	addi	a15, a1, 32             # 400082b9
	movi.n	a14, 85                 # 400082bc
	s32i.n	a14, a15, 0             # 400082be
	movi.n	a10, 9                  # 400082c0
	mov.n	a11, a1                 # 400082c2
	movi.n	a12, 1                  # 400082c4
	call8	fn_40006be8             # 400082c6
.L400082c9:
	retw.n                          # 400082c9
	.size	fn_4000802c, . - fn_4000802c
