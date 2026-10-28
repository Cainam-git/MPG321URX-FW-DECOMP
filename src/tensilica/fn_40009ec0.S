# fn_40009ec0: 0x40009ec0-0x40009ee7 (firmware file offset 0x39ec0-0x39ee7), 16 instructions
# Called from: fn_40003cd0
# Other literal values: 0xe00a0014, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009ec0, @function
fn_40009ec0:
	entry	a1, 48                  # 40009ec0
	l32r	a2, lit_3ffe2318        # 40009ec3  = 0xe00a0014
	memw                            # 40009ec6
	l32i.n	a2, a2, 0               # 40009ec9
	extui	a2, a2, 0, 1            # 40009ecb
	beqz.n	a2, .L40009edd          # 40009ece
	l32r	a3, lit_3ffe2300        # 40009ed0  = 0xe00a0000
	memw                            # 40009ed3
	l32i.n	a3, a3, 0               # 40009ed6
	s32i.n	a3, a1, 0               # 40009ed8
	j	.L40009ee4              # 40009eda
.L40009edd:
	movi.n	a4, -1                  # 40009edd
	s32i.n	a4, a1, 0               # 40009edf
	j	.L40009ee4              # 40009ee1
.L40009ee4:
	l32i.n	a2, a1, 0               # 40009ee4
	retw.n                          # 40009ee6
	.size	fn_40009ec0, . - fn_40009ec0
