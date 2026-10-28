# fn_40005fac: 0x40005fac-0x40006140 (firmware file offset 0x35fac-0x36140), 151 instructions
# Called from: fn_40000e20, fn_40003558, fn_400068c0
# Other literal values: 0xe0080310, 0xe0080400, 0xe008000c, 0xe0080514, 0xfffefffe, 0x00010001

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005fac, @function
fn_40005fac:
	entry	a1, 48                  # 40005fac
	s32i.n	a2, a1, 0               # 40005faf
	l32i.n	a4, a1, 0               # 40005fb1
	bnei	a4, 1, .L4000600f       # 40005fb3
	l32r	a9, lit_3ffe1e6c        # 40005fb6  = 0xe0080310
	movi.n	a10, -2                 # 40005fb9
	l32r	a8, lit_3ffe1e6c        # 40005fbb  = 0xe0080310
	memw                            # 40005fbe
	l32i.n	a8, a8, 0               # 40005fc1
	and	a8, a8, a10             # 40005fc3
	memw                            # 40005fc6
	s32i.n	a8, a9, 0               # 40005fc9
	l32r	a8, lit_3ffe1e70        # 40005fcb  = 0xe0080400
	movi.n	a9, 1                   # 40005fce
	l32r	a7, lit_3ffe1e70        # 40005fd0  = 0xe0080400
	memw                            # 40005fd3
	l32i.n	a7, a7, 0               # 40005fd6
	or	a7, a7, a9              # 40005fd8
	memw                            # 40005fdb
	s32i.n	a7, a8, 0               # 40005fde
	l32r	a7, lit_3ffe1e74        # 40005fe0  = 0xe008000c
	movi	a8, -129                # 40005fe3
	l32r	a6, lit_3ffe1e74        # 40005fe6  = 0xe008000c
	memw                            # 40005fe9
	l32i.n	a6, a6, 0               # 40005fec
	and	a6, a6, a8              # 40005fee
	memw                            # 40005ff1
	s32i.n	a6, a7, 0               # 40005ff4
	l32r	a6, lit_3ffe1e78        # 40005ff6  = 0xe0080514
	l32r	a7, lit_3ffe1e7c        # 40005ff9  = 0xfffefffe
	l32r	a5, lit_3ffe1e78        # 40005ffc  = 0xe0080514
	memw                            # 40005fff
	l32i.n	a5, a5, 0               # 40006002
	and	a5, a5, a7              # 40006004
	memw                            # 40006007
	s32i.n	a5, a6, 0               # 4000600a
	j	.L4000613f              # 4000600c
.L4000600f:
	l32i.n	a9, a1, 0               # 4000600f
	bnei	a9, 2, .L40006042       # 40006011
	l32r	a12, lit_3ffe1e70       # 40006014  = 0xe0080400
	movi.n	a13, 1                  # 40006017
	l32r	a11, lit_3ffe1e70       # 40006019  = 0xe0080400
	memw                            # 4000601c
	l32i.n	a11, a11, 0             # 4000601f
	or	a11, a11, a13           # 40006021
	memw                            # 40006024
	s32i.n	a11, a12, 0             # 40006027
	l32r	a11, lit_3ffe1e78       # 40006029  = 0xe0080514
	l32r	a12, lit_3ffe1e80       # 4000602c  = 0x00010001
	l32r	a10, lit_3ffe1e78       # 4000602f  = 0xe0080514
	memw                            # 40006032
	l32i.n	a10, a10, 0             # 40006035
	or	a10, a10, a12           # 40006037
	memw                            # 4000603a
	s32i.n	a10, a11, 0             # 4000603d
	j	.L4000613f              # 4000603f
.L40006042:
	l32i.n	a12, a1, 0              # 40006042
	bnei	a12, 4, .L400060a0      # 40006044
	l32r	a3, lit_3ffe1e6c        # 40006047  = 0xe0080310
	movi.n	a4, -2                  # 4000604a
	l32r	a2, lit_3ffe1e6c        # 4000604c  = 0xe0080310
	memw                            # 4000604f
	l32i.n	a2, a2, 0               # 40006052
	and	a2, a2, a4              # 40006054
	memw                            # 40006057
	s32i.n	a2, a3, 0               # 4000605a
	l32r	a2, lit_3ffe1e70        # 4000605c  = 0xe0080400
	movi.n	a3, 1                   # 4000605f
	l32r	a15, lit_3ffe1e70       # 40006061  = 0xe0080400
	memw                            # 40006064
	l32i.n	a15, a15, 0             # 40006067
	or	a15, a15, a3            # 40006069
	memw                            # 4000606c
	s32i.n	a15, a2, 0              # 4000606f
	l32r	a15, lit_3ffe1e74       # 40006071  = 0xe008000c
	movi	a2, -129                # 40006074
	l32r	a14, lit_3ffe1e74       # 40006077  = 0xe008000c
	memw                            # 4000607a
	l32i.n	a14, a14, 0             # 4000607d
	and	a14, a14, a2            # 4000607f
	memw                            # 40006082
	s32i.n	a14, a15, 0             # 40006085
	l32r	a14, lit_3ffe1e78       # 40006087  = 0xe0080514
	l32r	a15, lit_3ffe1e7c       # 4000608a  = 0xfffefffe
	l32r	a13, lit_3ffe1e78       # 4000608d  = 0xe0080514
	memw                            # 40006090
	l32i.n	a13, a13, 0             # 40006093
	and	a13, a13, a15           # 40006095
	memw                            # 40006098
	s32i.n	a13, a14, 0             # 4000609b
	j	.L4000613f              # 4000609d
.L400060a0:
	l32i.n	a3, a1, 0               # 400060a0
	bnei	a3, 3, .L400060fe       # 400060a2
	l32r	a8, lit_3ffe1e6c        # 400060a5  = 0xe0080310
	movi.n	a9, -2                  # 400060a8
	l32r	a7, lit_3ffe1e6c        # 400060aa  = 0xe0080310
	memw                            # 400060ad
	l32i.n	a7, a7, 0               # 400060b0
	and	a7, a7, a9              # 400060b2
	memw                            # 400060b5
	s32i.n	a7, a8, 0               # 400060b8
	l32r	a7, lit_3ffe1e70        # 400060ba  = 0xe0080400
	movi.n	a8, 1                   # 400060bd
	l32r	a6, lit_3ffe1e70        # 400060bf  = 0xe0080400
	memw                            # 400060c2
	l32i.n	a6, a6, 0               # 400060c5
	or	a6, a6, a8              # 400060c7
	memw                            # 400060ca
	s32i.n	a6, a7, 0               # 400060cd
	l32r	a6, lit_3ffe1e74        # 400060cf  = 0xe008000c
	movi	a7, -129                # 400060d2
	l32r	a5, lit_3ffe1e74        # 400060d5  = 0xe008000c
	memw                            # 400060d8
	l32i.n	a5, a5, 0               # 400060db
	and	a5, a5, a7              # 400060dd
	memw                            # 400060e0
	s32i.n	a5, a6, 0               # 400060e3
	l32r	a5, lit_3ffe1e78        # 400060e5  = 0xe0080514
	l32r	a6, lit_3ffe1e7c        # 400060e8  = 0xfffefffe
	l32r	a4, lit_3ffe1e78        # 400060eb  = 0xe0080514
	memw                            # 400060ee
	l32i.n	a4, a4, 0               # 400060f1
	and	a4, a4, a6              # 400060f3
	memw                            # 400060f6
	s32i.n	a4, a5, 0               # 400060f9
	j	.L4000613f              # 400060fb
.L400060fe:
	l32r	a11, lit_3ffe1e78       # 400060fe  = 0xe0080514
	l32r	a12, lit_3ffe1e80       # 40006101  = 0x00010001
	l32r	a10, lit_3ffe1e78       # 40006104  = 0xe0080514
	memw                            # 40006107
	l32i.n	a10, a10, 0             # 4000610a
	or	a10, a10, a12           # 4000610c
	memw                            # 4000610f
	s32i.n	a10, a11, 0             # 40006112
	l32r	a10, lit_3ffe1e70       # 40006114  = 0xe0080400
	movi.n	a11, 1                  # 40006117
	l32r	a9, lit_3ffe1e70        # 40006119  = 0xe0080400
	memw                            # 4000611c
	l32i.n	a9, a9, 0               # 4000611f
	or	a9, a9, a11             # 40006121
	memw                            # 40006124
	s32i.n	a9, a10, 0              # 40006127
	l32r	a9, lit_3ffe1e74        # 40006129  = 0xe008000c
	movi	a10, -129               # 4000612c
	l32r	a8, lit_3ffe1e74        # 4000612f  = 0xe008000c
	memw                            # 40006132
	l32i.n	a8, a8, 0               # 40006135
	and	a8, a8, a10             # 40006137
	memw                            # 4000613a
	s32i.n	a8, a9, 0               # 4000613d
.L4000613f:
	retw.n                          # 4000613f
	.size	fn_40005fac, . - fn_40005fac
