# fn_40006e94: 0x40006e94-0x40006eff (firmware file offset 0x36e94-0x36eff), 40 instructions
# Called from: fn_40006f00, fn_40008010
# Calls: fn_40003f38
# Other literal values: 0xc0192038, 0x00002000, 0xc0192138, 0xc0192238, 0xc0192338

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006e94, @function
fn_40006e94:
	entry	a1, 48                  # 40006e94
	s32i.n	a2, a1, 0               # 40006e97
	s32i.n	a3, a1, 4               # 40006e99
	l32i.n	a5, a1, 0               # 40006e9b
	extui	a5, a5, 0, 1            # 40006e9d
	beqz.n	a5, .L40006eb6          # 40006ea0
	l32r	a10, lit_3ffe1fa4       # 40006ea2  = 0xc0192038
	l32i.n	a11, a1, 4              # 40006ea5
	extui	a11, a11, 0, 1          # 40006ea7
	slli	a11, a11, 13            # 40006eaa
	l32r	a12, lit_3ffe1fa8       # 40006ead  = 0x00002000
	call8	fn_40003f38             # 40006eb0
	j	.L40006efe              # 40006eb3
.L40006eb6:
	l32i.n	a12, a1, 0              # 40006eb6
	bbci	a12, 1, .L40006ecf      # 40006eb8
	l32r	a10, lit_3ffe1fac       # 40006ebb  = 0xc0192138
	l32i.n	a11, a1, 4              # 40006ebe
	extui	a11, a11, 0, 1          # 40006ec0
	slli	a11, a11, 13            # 40006ec3
	l32r	a12, lit_3ffe1fa8       # 40006ec6  = 0x00002000
	call8	fn_40003f38             # 40006ec9
	j	.L40006efe              # 40006ecc
.L40006ecf:
	l32i.n	a12, a1, 0              # 40006ecf
	bbci	a12, 2, .L40006ee8      # 40006ed1
	l32r	a10, lit_3ffe1fb0       # 40006ed4  = 0xc0192238
	l32i.n	a11, a1, 4              # 40006ed7
	extui	a11, a11, 0, 1          # 40006ed9
	slli	a11, a11, 13            # 40006edc
	l32r	a12, lit_3ffe1fa8       # 40006edf  = 0x00002000
	call8	fn_40003f38             # 40006ee2
	j	.L40006efe              # 40006ee5
.L40006ee8:
	l32i.n	a12, a1, 0              # 40006ee8
	bbci	a12, 3, .L40006efe      # 40006eea
	l32r	a10, lit_3ffe1fb4       # 40006eed  = 0xc0192338
	l32i.n	a11, a1, 4              # 40006ef0
	extui	a11, a11, 0, 1          # 40006ef2
	slli	a11, a11, 13            # 40006ef5
	l32r	a12, lit_3ffe1fa8       # 40006ef8  = 0x00002000
	call8	fn_40003f38             # 40006efb
.L40006efe:
	retw.n                          # 40006efe
	.size	fn_40006e94, . - fn_40006e94
