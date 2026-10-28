# fn_40001344: 0x40001344-0x4000139c (firmware file offset 0x31344-0x3139c), 34 instructions
# Address stored in the words at: 0x4000d29c
# Calls: fn_40000fb4, fn_40006374, fn_4000660c, fn_4000670c, fn_40000de8, fn_400008c0
# Other literal values: 0x3ffe2bf0, 0x3ffe4450, 0x00000d70, 0x00001400

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001344, @function
fn_40001344:
	entry	a1, 48                  # 40001344
	s32i.n	a2, a1, 0               # 40001347
	s32i.n	a3, a1, 4               # 40001349
	l32i.n	a5, a1, 4               # 4000134b
	bnei	a5, 1, .L4000139b       # 4000134d
	call8	fn_40000fb4             # 40001350
	l32r	a10, lit_3ffe1a80       # 40001353  = 0x3ffe2bf0
	l32i.n	a10, a10, 0             # 40001356
	l32r	a11, lit_3ffe1a80       # 40001358  = 0x3ffe2bf0
	l32i.n	a11, a11, 4             # 4000135b
	call8	fn_40006374             # 4000135d
	l32r	a10, lit_3ffe1a84       # 40001360  = 0x3ffe4450
	l32i.n	a10, a10, 0             # 40001363
	l32r	a11, lit_3ffe1a84       # 40001365  = 0x3ffe4450
	l32i.n	a11, a11, 4             # 40001368
	call8	fn_4000660c             # 4000136a
	l32r	a12, lit_3ffe1b18       # 4000136d  = 0x00000d70
	l32r	a11, lit_3ffe1a80       # 40001370  = 0x3ffe2bf0
	l32i.n	a11, a11, 0             # 40001373
	beq	a11, a12, .L40001383    # 40001375
	l32r	a13, lit_3ffe1b1c       # 40001378  = 0x00001400
	l32r	a12, lit_3ffe1a80       # 4000137b  = 0x3ffe2bf0
	l32i.n	a12, a12, 0             # 4000137e
	bne	a12, a13, .L4000138b    # 40001380
.L40001383:
	movi.n	a10, 16                 # 40001383
	call8	fn_4000670c             # 40001385
	j	.L40001390              # 40001388
.L4000138b:
	movi.n	a10, 32                 # 4000138b
	call8	fn_4000670c             # 4000138d
.L40001390:
	l32r	a10, lit_3ffe1a80       # 40001390  = 0x3ffe2bf0
	l32i.n	a10, a10, 24            # 40001393
	call8	fn_40000de8             # 40001395
	call8	fn_400008c0             # 40001398
.L4000139b:
	retw.n                          # 4000139b
	.size	fn_40001344, . - fn_40001344
