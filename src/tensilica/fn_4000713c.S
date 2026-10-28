# fn_4000713c: 0x4000713c-0x40007346 (firmware file offset 0x3713c-0x37346), 212 instructions
# Called from: fn_400079b8, fn_40007ab8
# Calls: fn_4000aa64, fn_40006be8, fn_4000912c
# Addresses loaded: ro_3ffe0ba0
# Other literal values: 0x3ffe5548, 0x00372000, 0x3ffe554c, 0x3ffe5550, 0x3ffe5554, 0x3ffe5558, 0x3ffe555c,
#                       0x3ffe5560, 0x3ffe5564, 0x3ffe5568, 0x3ffe556c, 0x3ffe5570, 0x3ffe5574, 0x3ffe5578,
#                       0x3ffe557c, 0x3ffe5580, 0x3ffe5584

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000713c, @function
fn_4000713c:
	entry	a1, 96                  # 4000713c
	s32i.n	a2, a1, 48              # 4000713f
	s32i.n	a3, a1, 52              # 40007141
	s32i.n	a4, a1, 56              # 40007143
	mov.n	a10, a1                 # 40007145
	l32r	a11, lit_3ffe2058       # 40007147  = ro_3ffe0ba0
	movi.n	a12, 36                 # 4000714a
	call8	fn_4000aa64             # 4000714c
	l32r	a4, lit_3ffe205c        # 4000714f  = 0x3ffe5548
	l32i.n	a4, a4, 0               # 40007152
	mov.n	a2, a1                  # 40007154
	l32r	a3, lit_3ffe2060        # 40007156  = 0x00372000
	l32i.n	a5, a1, 52              # 40007159
	addx4	a4, a4, a5              # 4000715b
	l32i.n	a4, a4, 0               # 4000715e
	extui	a4, a4, 0, 8            # 40007160
	slli	a4, a4, 24              # 40007163
	l32i.n	a15, a1, 48             # 40007166
	add.n	a15, a15, a4            # 40007168
	add.n	a15, a15, a3            # 4000716a
	s32i.n	a15, a2, 0              # 4000716c
	l32r	a14, lit_3ffe205c       # 4000716e  = 0x3ffe5548
	l32i.n	a14, a14, 0             # 40007171
	l32r	a3, lit_3ffe2064        # 40007173  = 0x3ffe554c
	l32i.n	a3, a3, 0               # 40007176
	l32r	a2, lit_3ffe2068        # 40007178  = 0x3ffe5550
	l32i.n	a2, a2, 0               # 4000717b
	addi.n	a15, a1, 4              # 4000717d
	l32i.n	a4, a1, 52              # 4000717f
	addx4	a2, a2, a4              # 40007181
	l32i.n	a2, a2, 0               # 40007184
	extui	a2, a2, 0, 8            # 40007186
	slli	a2, a2, 24              # 40007189
	l32i.n	a4, a1, 52              # 4000718c
	addx4	a3, a3, a4              # 4000718e
	l32i.n	a3, a3, 0               # 40007191
	slli	a3, a3, 8               # 40007193
	l32i.n	a4, a1, 52              # 40007196
	addx4	a14, a14, a4            # 40007198
	l32i.n	a14, a14, 0             # 4000719b
	srli	a14, a14, 8             # 4000719d
	extui	a14, a14, 0, 8          # 400071a0
	add.n	a14, a14, a3            # 400071a3
	add.n	a14, a14, a2            # 400071a5
	s32i.n	a14, a15, 0             # 400071a7
	l32r	a13, lit_3ffe2068       # 400071a9  = 0x3ffe5550
	l32i.n	a13, a13, 0             # 400071ac
	l32r	a2, lit_3ffe206c        # 400071ae  = 0x3ffe5554
	l32i.n	a2, a2, 0               # 400071b1
	l32r	a15, lit_3ffe2070       # 400071b3  = 0x3ffe5558
	l32i.n	a15, a15, 0             # 400071b6
	addi.n	a14, a1, 8              # 400071b8
	l32i.n	a3, a1, 52              # 400071ba
	addx4	a15, a15, a3            # 400071bc
	l32i.n	a15, a15, 0             # 400071bf
	extui	a15, a15, 0, 8          # 400071c1
	slli	a15, a15, 24            # 400071c4
	l32i.n	a3, a1, 52              # 400071c7
	addx4	a2, a2, a3              # 400071c9
	l32i.n	a2, a2, 0               # 400071cc
	slli	a2, a2, 8               # 400071ce
	l32i.n	a3, a1, 52              # 400071d1
	addx4	a13, a13, a3            # 400071d3
	l32i.n	a13, a13, 0             # 400071d6
	srli	a13, a13, 8             # 400071d8
	extui	a13, a13, 0, 8          # 400071db
	add.n	a13, a13, a2            # 400071de
	add.n	a13, a13, a15           # 400071e0
	s32i.n	a13, a14, 0             # 400071e2
	l32r	a12, lit_3ffe2070       # 400071e4  = 0x3ffe5558
	l32i.n	a12, a12, 0             # 400071e7
	l32r	a15, lit_3ffe2074       # 400071e9  = 0x3ffe555c
	l32i.n	a15, a15, 0             # 400071ec
	l32r	a14, lit_3ffe2078       # 400071ee  = 0x3ffe5560
	l32i.n	a14, a14, 0             # 400071f1
	addi.n	a13, a1, 12             # 400071f3
	l32i.n	a2, a1, 52              # 400071f5
	addx4	a14, a14, a2            # 400071f7
	l32i.n	a14, a14, 0             # 400071fa
	extui	a14, a14, 0, 8          # 400071fc
	slli	a14, a14, 24            # 400071ff
	l32i.n	a2, a1, 52              # 40007202
	addx4	a15, a15, a2            # 40007204
	l32i.n	a15, a15, 0             # 40007207
	slli	a15, a15, 8             # 40007209
	l32i.n	a2, a1, 52              # 4000720c
	addx4	a12, a12, a2            # 4000720e
	l32i.n	a12, a12, 0             # 40007211
	srli	a12, a12, 8             # 40007213
	extui	a12, a12, 0, 8          # 40007216
	add.n	a12, a12, a15           # 40007219
	add.n	a12, a12, a14           # 4000721b
	s32i.n	a12, a13, 0             # 4000721d
	l32r	a11, lit_3ffe2078       # 4000721f  = 0x3ffe5560
	l32i.n	a11, a11, 0             # 40007222
	l32r	a14, lit_3ffe207c       # 40007224  = 0x3ffe5564
	l32i.n	a14, a14, 0             # 40007227
	l32r	a13, lit_3ffe2080       # 40007229  = 0x3ffe5568
	l32i.n	a13, a13, 0             # 4000722c
	addi	a12, a1, 16             # 4000722e
	l32i.n	a15, a1, 52             # 40007231
	addx4	a13, a13, a15           # 40007233
	l32i.n	a13, a13, 0             # 40007236
	extui	a13, a13, 0, 8          # 40007238
	slli	a13, a13, 24            # 4000723b
	l32i.n	a15, a1, 52             # 4000723e
	addx4	a14, a14, a15           # 40007240
	l32i.n	a14, a14, 0             # 40007243
	slli	a14, a14, 8             # 40007245
	l32i.n	a15, a1, 52             # 40007248
	addx4	a11, a11, a15           # 4000724a
	l32i.n	a11, a11, 0             # 4000724d
	srli	a11, a11, 8             # 4000724f
	extui	a11, a11, 0, 8          # 40007252
	add.n	a11, a11, a14           # 40007255
	add.n	a11, a11, a13           # 40007257
	s32i.n	a11, a12, 0             # 40007259
	l32r	a10, lit_3ffe2080       # 4000725b  = 0x3ffe5568
	l32i.n	a10, a10, 0             # 4000725e
	l32r	a13, lit_3ffe2084       # 40007260  = 0x3ffe556c
	l32i.n	a13, a13, 0             # 40007263
	l32r	a12, lit_3ffe2088       # 40007265  = 0x3ffe5570
	l32i.n	a12, a12, 0             # 40007268
	addi	a11, a1, 20             # 4000726a
	l32i.n	a14, a1, 52             # 4000726d
	addx4	a12, a12, a14           # 4000726f
	l32i.n	a12, a12, 0             # 40007272
	extui	a12, a12, 0, 8          # 40007274
	slli	a12, a12, 24            # 40007277
	l32i.n	a14, a1, 52             # 4000727a
	addx4	a13, a13, a14           # 4000727c
	l32i.n	a13, a13, 0             # 4000727f
	slli	a13, a13, 8             # 40007281
	l32i.n	a14, a1, 52             # 40007284
	addx4	a10, a10, a14           # 40007286
	l32i.n	a10, a10, 0             # 40007289
	srli	a10, a10, 8             # 4000728b
	extui	a10, a10, 0, 8          # 4000728e
	add.n	a10, a10, a13           # 40007291
	add.n	a10, a10, a12           # 40007293
	s32i.n	a10, a11, 0             # 40007295
	l32r	a9, lit_3ffe2088        # 40007297  = 0x3ffe5570
	l32i.n	a9, a9, 0               # 4000729a
	l32r	a12, lit_3ffe208c       # 4000729c  = 0x3ffe5574
	l32i.n	a12, a12, 0             # 4000729f
	l32r	a11, lit_3ffe2090       # 400072a1  = 0x3ffe5578
	l32i.n	a11, a11, 0             # 400072a4
	addi	a10, a1, 24             # 400072a6
	l32i.n	a13, a1, 52             # 400072a9
	addx4	a11, a11, a13           # 400072ab
	l32i.n	a11, a11, 0             # 400072ae
	extui	a11, a11, 0, 8          # 400072b0
	slli	a11, a11, 24            # 400072b3
	l32i.n	a13, a1, 52             # 400072b6
	addx4	a12, a12, a13           # 400072b8
	l32i.n	a12, a12, 0             # 400072bb
	slli	a12, a12, 8             # 400072bd
	l32i.n	a13, a1, 52             # 400072c0
	addx4	a9, a9, a13             # 400072c2
	l32i.n	a9, a9, 0               # 400072c5
	srli	a9, a9, 8               # 400072c7
	extui	a9, a9, 0, 8            # 400072ca
	add.n	a9, a9, a12             # 400072cd
	add.n	a9, a9, a11             # 400072cf
	s32i.n	a9, a10, 0              # 400072d1
	l32r	a8, lit_3ffe2090        # 400072d3  = 0x3ffe5578
	l32i.n	a8, a8, 0               # 400072d6
	l32r	a11, lit_3ffe2094       # 400072d8  = 0x3ffe557c
	l32i.n	a11, a11, 0             # 400072db
	l32r	a10, lit_3ffe2098       # 400072dd  = 0x3ffe5580
	l32i.n	a10, a10, 0             # 400072e0
	addi	a9, a1, 28              # 400072e2
	l32i.n	a12, a1, 52             # 400072e5
	addx4	a10, a10, a12           # 400072e7
	l32i.n	a10, a10, 0             # 400072ea
	extui	a10, a10, 0, 8          # 400072ec
	slli	a10, a10, 24            # 400072ef
	l32i.n	a12, a1, 52             # 400072f2
	addx4	a11, a11, a12           # 400072f4
	l32i.n	a11, a11, 0             # 400072f7
	slli	a11, a11, 8             # 400072f9
	l32i.n	a12, a1, 52             # 400072fc
	addx4	a8, a8, a12             # 400072fe
	l32i.n	a8, a8, 0               # 40007301
	srli	a8, a8, 8               # 40007303
	extui	a8, a8, 0, 8            # 40007306
	add.n	a8, a8, a11             # 40007309
	add.n	a8, a8, a10             # 4000730b
	s32i.n	a8, a9, 0               # 4000730d
	l32r	a7, lit_3ffe2098        # 4000730f  = 0x3ffe5580
	l32i.n	a7, a7, 0               # 40007312
	l32r	a9, lit_3ffe209c        # 40007314  = 0x3ffe5584
	l32i.n	a9, a9, 0               # 40007317
	addi	a8, a1, 32              # 40007319
	l32i.n	a10, a1, 52             # 4000731c
	addx4	a9, a9, a10             # 4000731e
	l32i.n	a9, a9, 0               # 40007321
	slli	a9, a9, 8               # 40007323
	l32i.n	a10, a1, 52             # 40007326
	addx4	a7, a7, a10             # 40007328
	l32i.n	a7, a7, 0               # 4000732b
	srli	a7, a7, 8               # 4000732d
	extui	a7, a7, 0, 8            # 40007330
	add.n	a7, a7, a9              # 40007333
	s32i.n	a7, a8, 0               # 40007335
	movi.n	a10, 9                  # 40007337
	mov.n	a11, a1                 # 40007339
	movi.n	a12, 1                  # 4000733b
	call8	fn_40006be8             # 4000733d
	movi.n	a10, 2                  # 40007340
	call8	fn_4000912c             # 40007342
	retw.n                          # 40007345
	.size	fn_4000713c, . - fn_4000713c
