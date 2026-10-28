# fn_400068c0: 0x400068c0-0x40006902 (firmware file offset 0x368c0-0x36902), 26 instructions
# Called from: fn_4000a3cc
# Calls: fn_40006180, fn_40006144, fn_40006750, fn_400063dc, fn_40006374, fn_4000660c, fn_4000670c,
#        fn_40006724, fn_4000679c, fn_40006854, fn_40005fac
# Other literal values: 0x08802000, 0x00000f00, 0x00000870

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400068c0, @function
fn_400068c0:
	entry	a1, 32                  # 400068c0
	call8	fn_40006180             # 400068c3
	call8	fn_40006144             # 400068c6
	l32r	a10, lit_3ffe1f10       # 400068c9  = 0x08802000
	call8	fn_40006750             # 400068cc
	movi.n	a10, 5                  # 400068cf
	movi.n	a11, 6                  # 400068d1
	call8	fn_400063dc             # 400068d3
	l32r	a10, lit_3ffe1acc       # 400068d6  = 0x00000f00
	l32r	a11, lit_3ffe1ac8       # 400068d9  = 0x00000870
	call8	fn_40006374             # 400068dc
	movi.n	a10, 32                 # 400068df
	movi.n	a11, 16                 # 400068e1
	call8	fn_4000660c             # 400068e3
	movi.n	a10, 32                 # 400068e6
	call8	fn_4000670c             # 400068e8
	movi.n	a10, 56                 # 400068eb
	movi.n	a11, 20                 # 400068ed
	call8	fn_40006724             # 400068ef
	movi.n	a10, 4                  # 400068f2
	call8	fn_4000679c             # 400068f4
	movi.n	a10, 3                  # 400068f7
	call8	fn_40006854             # 400068f9
	movi.n	a10, 0                  # 400068fc
	call8	fn_40005fac             # 400068fe
	retw.n                          # 40006901
	.size	fn_400068c0, . - fn_400068c0
