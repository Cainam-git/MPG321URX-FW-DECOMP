# fn_40003ff8: 0x40003ff8-0x40004149 (firmware file offset 0x33ff8-0x34149), 146 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003ff8, @function
fn_40003ff8:
	entry	a1, 96                  # 40003ff8
	s32i.n	a2, a1, 48              # 40003ffb
	s32i.n	a3, a1, 52              # 40003ffd
	s32i.n	a4, a1, 56              # 40003fff
	s32i.n	a5, a1, 60              # 40004001
	l32i.n	a9, a1, 56              # 40004003
	movi.n	a8, 32                  # 40004005
	bgeu	a8, a9, .L4000400d      # 40004007
	j	.L40004148              # 4000400a
.L4000400d:
	l32i.n	a2, a1, 60              # 4000400d
	s32i.n	a2, a1, 0               # 4000400f
	l32i.n	a15, a1, 48             # 40004011
	s32i.n	a15, a1, 4              # 40004013
	l32i.n	a14, a1, 4              # 40004015
	extui	a14, a14, 0, 2          # 40004017
	s32i.n	a14, a1, 8              # 4000401a
	l32i.n	a13, a1, 8              # 4000401c
	slli	a13, a13, 3             # 4000401e
	l32i.n	a12, a1, 52             # 40004021
	add.n	a12, a12, a13           # 40004023
	l32i.n	a11, a1, 56             # 40004025
	add.n	a11, a11, a12           # 40004027
	movi.n	a10, 32                 # 40004029
	bltu	a10, a11, .L40004031    # 4000402b
	j	.L400040d3              # 4000402e
.L40004031:
	l32i.n	a2, a1, 8               # 40004031
	slli	a2, a2, 3               # 40004033
	l32i.n	a15, a1, 52             # 40004036
	add.n	a15, a15, a2            # 40004038
	l32i.n	a14, a1, 56             # 4000403a
	add.n	a14, a14, a15           # 4000403c
	addi	a14, a14, -32           # 4000403e
	s32i.n	a14, a1, 12             # 40004041
	l32i.n	a14, a1, 12             # 40004043
	l32i.n	a13, a1, 56             # 40004045
	sub	a13, a13, a14           # 40004047
	s32i.n	a13, a1, 16             # 4000404a
	l32i.n	a12, a1, 8              # 4000404c
	l32i.n	a11, a1, 4              # 4000404e
	sub	a11, a11, a12           # 40004050
	s32i.n	a11, a1, 4              # 40004053
	l32i.n	a10, a1, 4              # 40004055
	addi.n	a10, a10, 4             # 40004057
	s32i.n	a10, a1, 20             # 40004059
	l32i.n	a9, a1, 4               # 4000405b
	memw                            # 4000405d
	l32i.n	a9, a9, 0               # 40004060
	s32i.n	a9, a1, 24              # 40004062
	l32i.n	a8, a1, 20              # 40004064
	memw                            # 40004066
	l32i.n	a8, a8, 0               # 40004069
	s32i.n	a8, a1, 28              # 4000406b
	movi.n	a6, -1                  # 4000406d
	l32i.n	a7, a1, 16              # 4000406f
	ssr	a7                      # 40004071
	srl	a6, a6                  # 40004074
	l32i.n	a5, a1, 24              # 40004077
	and	a5, a5, a6              # 40004079
	s32i.n	a5, a1, 24              # 4000407c
	movi.n	a3, -1                  # 4000407e
	l32i.n	a4, a1, 12              # 40004080
	ssl	a4                      # 40004082
	sll	a3, a3                  # 40004085
	l32i.n	a2, a1, 28              # 40004088
	and	a2, a2, a3              # 4000408a
	s32i.n	a2, a1, 28              # 4000408d
	l32i.n	a14, a1, 0              # 4000408f
	l32i.n	a15, a1, 16             # 40004091
	ssr	a15                     # 40004093
	srl	a14, a14                # 40004096
	s32i.n	a14, a1, 32             # 40004099
	l32i.n	a11, a1, 0              # 4000409b
	l32i.n	a13, a1, 16             # 4000409d
	movi.n	a12, 32                 # 4000409f
	sub	a12, a12, a13           # 400040a1
	ssl	a12                     # 400040a4
	sll	a11, a11                # 400040a7
	s32i.n	a11, a1, 0              # 400040aa
	l32i.n	a10, a1, 24             # 400040ac
	l32i.n	a9, a1, 0               # 400040ae
	or	a9, a9, a10             # 400040b0
	s32i.n	a9, a1, 24              # 400040b3
	l32i.n	a8, a1, 28              # 400040b5
	l32i.n	a7, a1, 32              # 400040b7
	or	a7, a7, a8              # 400040b9
	s32i.n	a7, a1, 28              # 400040bc
	l32i.n	a6, a1, 4               # 400040be
	l32i.n	a5, a1, 24              # 400040c0
	memw                            # 400040c2
	s32i.n	a5, a6, 0               # 400040c5
	l32i.n	a4, a1, 20              # 400040c7
	l32i.n	a3, a1, 28              # 400040c9
	memw                            # 400040cb
	s32i.n	a3, a4, 0               # 400040ce
	j	.L40004148              # 400040d0
.L400040d3:
	l32i.n	a5, a1, 8               # 400040d3
	l32i.n	a4, a1, 4               # 400040d5
	sub	a4, a4, a5              # 400040d7
	s32i.n	a4, a1, 4               # 400040da
	l32i.n	a3, a1, 56              # 400040dc
	s32i.n	a3, a1, 16              # 400040de
	l32i.n	a2, a1, 4               # 400040e0
	memw                            # 400040e2
	l32i.n	a2, a2, 0               # 400040e5
	s32i.n	a2, a1, 24              # 400040e7
	movi.n	a12, -1                 # 400040e9
	movi.n	a13, -1                 # 400040eb
	l32i.n	a15, a1, 8              # 400040ed
	slli	a15, a15, 3             # 400040ef
	l32i.n	a14, a1, 52             # 400040f2
	add.n	a14, a14, a15           # 400040f4
	ssl	a14                     # 400040f6
	sll	a13, a13                # 400040f9
	movi.n	a11, -1                 # 400040fc
	l32i.n	a3, a1, 8               # 400040fe
	slli	a3, a3, 3               # 40004100
	l32i.n	a2, a1, 52              # 40004103
	add.n	a2, a2, a3              # 40004105
	l32i.n	a15, a1, 56             # 40004107
	add.n	a15, a15, a2            # 40004109
	movi.n	a14, 32                 # 4000410b
	sub	a14, a14, a15           # 4000410d
	ssr	a14                     # 40004110
	srl	a11, a11                # 40004113
	and	a11, a11, a13           # 40004116
	xor	a11, a11, a12           # 40004119
	l32i.n	a10, a1, 24             # 4000411c
	and	a10, a10, a11           # 4000411e
	s32i.n	a10, a1, 24             # 40004121
	l32i.n	a7, a1, 0               # 40004123
	l32i.n	a9, a1, 8               # 40004125
	slli	a9, a9, 3               # 40004127
	l32i.n	a8, a1, 52              # 4000412a
	add.n	a8, a8, a9              # 4000412c
	ssl	a8                      # 4000412e
	sll	a7, a7                  # 40004131
	s32i.n	a7, a1, 0               # 40004134
	l32i.n	a6, a1, 24              # 40004136
	l32i.n	a5, a1, 0               # 40004138
	or	a5, a5, a6              # 4000413a
	s32i.n	a5, a1, 24              # 4000413d
	l32i.n	a4, a1, 4               # 4000413f
	l32i.n	a3, a1, 24              # 40004141
	memw                            # 40004143
	s32i.n	a3, a4, 0               # 40004146
.L40004148:
	retw.n                          # 40004148
	.size	fn_40003ff8, . - fn_40003ff8
