# fn_40002894: 0x40002894-0x400029ff (firmware file offset 0x32894-0x329ff), 149 instructions
# Called from: fn_40003140
# Calls: fn_40002660
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe3eb0, 0x3ffe3e30, 0x00000fff

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002894, @function
fn_40002894:
	entry	a1, 64                  # 40002894
	s32i.n	a2, a1, 16              # 40002897
	s32i.n	a3, a1, 20              # 40002899
	s32i.n	a4, a1, 24              # 4000289b
	movi.n	a8, 0                   # 4000289d
	s32i.n	a8, a1, 0               # 4000289f
	l32i.n	a7, a1, 24              # 400028a1
	beqi	a7, 1, .L400028a9       # 400028a3
	j	.L400029b6              # 400028a6
.L400028a9:
	movi.n	a11, 0                  # 400028a9
	s32i.n	a11, a1, 0              # 400028ab
	l32r	a10, lit_3ffe1a98       # 400028ad  = data_3ffe2390
	l32i.n	a10, a10, 0             # 400028b0
	l32i.n	a9, a1, 0               # 400028b2
	bltu	a9, a10, .L400028ba     # 400028b4
	j	.L400029b3              # 400028b7
.L400028ba:
	l32i.n	a13, a1, 0              # 400028ba
	l32r	a14, lit_3ffe1ac0       # 400028bc  = 0x3ffe3eb0
	addx2	a13, a13, a14           # 400028bf
	l16ui	a13, a13, 0             # 400028c2
	l32i.n	a12, a1, 0              # 400028c5
	l32i.n	a14, a1, 16             # 400028c7
	addx4	a12, a12, a14           # 400028c9
	l32i.n	a12, a12, 0             # 400028cc
	bgeu	a12, a13, .L40002917    # 400028ce
	l32i.n	a10, a1, 0              # 400028d1
	l32i.n	a11, a1, 16             # 400028d3
	addx4	a10, a10, a11           # 400028d5
	l32i.n	a10, a10, 0             # 400028d8
	slli	a10, a10, 8             # 400028da
	l32i.n	a11, a1, 0              # 400028dd
	l32r	a12, lit_3ffe1ab4       # 400028df  = 0x3ffe3e30
	addx4	a11, a11, a12           # 400028e2
	l32i.n	a11, a11, 0             # 400028e5
	l32r	a12, lit_3ffe1a98       # 400028e7  = data_3ffe2390
	l32i.n	a12, a12, 40            # 400028ea
	call8	fn_40002660             # 400028ec
	l32i.n	a15, a1, 0              # 400028ef
	l32r	a2, lit_3ffe1ab4        # 400028f1  = 0x3ffe3e30
	addx4	a15, a15, a2            # 400028f4
	s32i.n	a10, a15, 0             # 400028f7
	l32i.n	a13, a1, 0              # 400028f9
	l32i.n	a14, a1, 20             # 400028fb
	addx4	a13, a13, a14           # 400028fd
	movi	a14, 128                # 40002900
	l32i.n	a12, a1, 0              # 40002903
	l32r	a15, lit_3ffe1ab4       # 40002905  = 0x3ffe3e30
	addx4	a12, a12, a15           # 40002908
	l32i.n	a12, a12, 0             # 4000290b
	add.n	a12, a12, a14           # 4000290d
	srli	a12, a12, 8             # 4000290f
	s32i.n	a12, a13, 0             # 40002912
	j	.L40002988              # 40002914
.L40002917:
	l32i.n	a4, a1, 0               # 40002917
	l32i.n	a5, a1, 16              # 40002919
	addx4	a4, a4, a5              # 4000291b
	l32i.n	a4, a4, 0               # 4000291e
	l32i.n	a3, a1, 0               # 40002920
	l32r	a5, lit_3ffe1ac0        # 40002922  = 0x3ffe3eb0
	addx2	a3, a3, a5              # 40002925
	l16ui	a3, a3, 0               # 40002928
	bgeu	a3, a4, .L40002974      # 4000292b
	l32i.n	a10, a1, 0              # 4000292e
	l32i.n	a11, a1, 16             # 40002930
	addx4	a10, a10, a11           # 40002932
	l32i.n	a10, a10, 0             # 40002935
	slli	a10, a10, 8             # 40002937
	l32i.n	a11, a1, 0              # 4000293a
	l32r	a12, lit_3ffe1ab4       # 4000293c  = 0x3ffe3e30
	addx4	a11, a11, a12           # 4000293f
	l32i.n	a11, a11, 0             # 40002942
	l32r	a12, lit_3ffe1a98       # 40002944  = data_3ffe2390
	l32i.n	a12, a12, 36            # 40002947
	call8	fn_40002660             # 40002949
	l32i.n	a15, a1, 0              # 4000294c
	l32r	a2, lit_3ffe1ab4        # 4000294e  = 0x3ffe3e30
	addx4	a15, a15, a2            # 40002951
	s32i.n	a10, a15, 0             # 40002954
	l32i.n	a13, a1, 0              # 40002956
	l32i.n	a14, a1, 20             # 40002958
	addx4	a13, a13, a14           # 4000295a
	movi	a14, 128                # 4000295d
	l32i.n	a12, a1, 0              # 40002960
	l32r	a15, lit_3ffe1ab4       # 40002962  = 0x3ffe3e30
	addx4	a12, a12, a15           # 40002965
	l32i.n	a12, a12, 0             # 40002968
	add.n	a12, a12, a14           # 4000296a
	srli	a12, a12, 8             # 4000296c
	s32i.n	a12, a13, 0             # 4000296f
	j	.L40002988              # 40002971
.L40002974:
	l32i.n	a4, a1, 0               # 40002974
	l32i.n	a5, a1, 20              # 40002976
	addx4	a4, a4, a5              # 40002978
	l32i.n	a3, a1, 0               # 4000297b
	l32r	a5, lit_3ffe1ac0        # 4000297d  = 0x3ffe3eb0
	addx2	a3, a3, a5              # 40002980
	l16ui	a3, a3, 0               # 40002983
	s32i.n	a3, a4, 0               # 40002986
.L40002988:
	l32i.n	a10, a1, 0              # 40002988
	l32i.n	a11, a1, 20             # 4000298a
	addx4	a10, a10, a11           # 4000298c
	l32r	a11, lit_3ffe1abc       # 4000298f  = 0x00000fff
	l32i.n	a9, a1, 0               # 40002992
	l32i.n	a12, a1, 20             # 40002994
	addx4	a9, a9, a12             # 40002996
	l32i.n	a9, a9, 0               # 40002999
	minu	a9, a9, a11             # 4000299b
	s32i.n	a9, a10, 0              # 4000299e
	l32i.n	a8, a1, 0               # 400029a0
	addi.n	a8, a8, 1               # 400029a2
	s32i.n	a8, a1, 0               # 400029a4
	l32r	a7, lit_3ffe1a98        # 400029a6  = data_3ffe2390
	l32i.n	a7, a7, 0               # 400029a9
	l32i.n	a6, a1, 0               # 400029ab
	bgeu	a6, a7, .L400029b3      # 400029ad
	j	.L400028ba              # 400029b0
.L400029b3:
	j	.L400029fe              # 400029b3
.L400029b6:
	movi.n	a14, 0                  # 400029b6
	s32i.n	a14, a1, 0              # 400029b8
	l32r	a13, lit_3ffe1a98       # 400029ba  = data_3ffe2390
	l32i.n	a13, a13, 0             # 400029bd
	l32i.n	a12, a1, 0              # 400029bf
	bgeu	a12, a13, .L400029fe    # 400029c1
.L400029c4:
	l32i.n	a8, a1, 0               # 400029c4
	l32i.n	a9, a1, 20              # 400029c6
	addx4	a8, a8, a9              # 400029c8
	l32i.n	a7, a1, 0               # 400029cb
	l32i.n	a9, a1, 16              # 400029cd
	addx4	a7, a7, a9              # 400029cf
	l32i.n	a7, a7, 0               # 400029d2
	s32i.n	a7, a8, 0               # 400029d4
	l32i.n	a5, a1, 0               # 400029d6
	l32i.n	a6, a1, 20              # 400029d8
	addx4	a5, a5, a6              # 400029da
	l32r	a6, lit_3ffe1abc        # 400029dd  = 0x00000fff
	l32i.n	a4, a1, 0               # 400029e0
	l32i.n	a7, a1, 20              # 400029e2
	addx4	a4, a4, a7              # 400029e4
	l32i.n	a4, a4, 0               # 400029e7
	minu	a4, a4, a6              # 400029e9
	s32i.n	a4, a5, 0               # 400029ec
	l32i.n	a3, a1, 0               # 400029ee
	addi.n	a3, a3, 1               # 400029f0
	s32i.n	a3, a1, 0               # 400029f2
	l32r	a2, lit_3ffe1a98        # 400029f4  = data_3ffe2390
	l32i.n	a2, a2, 0               # 400029f7
	l32i.n	a15, a1, 0              # 400029f9
	bltu	a15, a2, .L400029c4     # 400029fb
.L400029fe:
	retw.n                          # 400029fe
	.size	fn_40002894, . - fn_40002894
