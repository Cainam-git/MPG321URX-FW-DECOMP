# fn_40003140: 0x40003140-0x40003172 (firmware file offset 0x33140-0x33172), 20 instructions
# Called from: fn_400035d0
# Calls: fn_400021d0, fn_40002d7c, fn_40002d0c, fn_40002894, fn_4000082c
# Other literal values: 0x3ffe3eb0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003140, @function
fn_40003140:
	entry	a1, 0x130               # 40003140
	s32i	a2, a1, 0x100           # 40003143
	l32i	a10, a1, 0x100          # 40003146
	mov.n	a11, a1                 # 40003149
	call8	fn_400021d0             # 4000314b
	mov.n	a10, a1                 # 4000314e
	call8	fn_40002d7c             # 40003150
	mov.n	a10, a1                 # 40003153
	call8	fn_40002d0c             # 40003155
	mov.n	a10, a1                 # 40003158
	addi	a11, a1, 127            # 4000315a
	addi.n	a11, a11, 1             # 4000315d
	movi.n	a12, 0                  # 4000315f
	call8	fn_40002894             # 40003161
	addi	a10, a1, 127            # 40003164
	addi.n	a10, a10, 1             # 40003167
	l32r	a11, lit_3ffe1ac0       # 40003169  = 0x3ffe3eb0
	movi.n	a12, 32                 # 4000316c
	call8	fn_4000082c             # 4000316e
	retw.n                          # 40003171
	.size	fn_40003140, . - fn_40003140
