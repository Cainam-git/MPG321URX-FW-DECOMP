# fn_40009e88: 0x40009e88-0x40009ebd (firmware file offset 0x39e88-0x39ebd), 20 instructions
# Called from: fn_400038e8
# Other literal values: 0xe00a0014, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009e88, @function
fn_40009e88:
	entry	a1, 48                  # 40009e88
	extui	a2, a2, 0, 8            # 40009e8b
	s8i	a2, a1, 0               # 40009e8e
	l32r	a4, lit_3ffe2318        # 40009e91  = 0xe00a0014
	memw                            # 40009e94
	l32i.n	a4, a4, 0               # 40009e97
	bbsi	a4, 5, .L40009eae       # 40009e99
.L40009e9c:
	movi.n	a6, 0                   # 40009e9c
	movi.n	a7, 32                  # 40009e9e
	l32r	a5, lit_3ffe2318        # 40009ea0  = 0xe00a0014
	memw                            # 40009ea3
	l32i.n	a5, a5, 0               # 40009ea6
	and	a5, a5, a7              # 40009ea8
	beq	a5, a6, .L40009e9c      # 40009eab
.L40009eae:
	l32r	a4, lit_3ffe2300        # 40009eae  = 0xe00a0000
	l8ui	a3, a1, 0               # 40009eb1
	memw                            # 40009eb4
	s32i.n	a3, a4, 0               # 40009eb7
	l8ui	a2, a1, 0               # 40009eb9
	retw.n                          # 40009ebc
	.size	fn_40009e88, . - fn_40009e88
