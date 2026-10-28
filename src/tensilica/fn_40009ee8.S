# fn_40009ee8: 0x40009ee8-0x40009f0f (firmware file offset 0x39ee8-0x39f0f), 15 instructions
# Called from: fn_400091f4
# Other literal values: 0xe00a0014, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009ee8, @function
fn_40009ee8:
	entry	a1, 32                  # 40009ee8
	l32r	a2, lit_3ffe2318        # 40009eeb  = 0xe00a0014
	memw                            # 40009eee
	l32i.n	a2, a2, 0               # 40009ef1
	bbsi	a2, 0, .L40009f06       # 40009ef3
.L40009ef6:
	movi.n	a4, 0                   # 40009ef6
	l32r	a3, lit_3ffe2318        # 40009ef8  = 0xe00a0014
	memw                            # 40009efb
	l32i.n	a3, a3, 0               # 40009efe
	extui	a3, a3, 0, 1            # 40009f00
	beq	a3, a4, .L40009ef6      # 40009f03
.L40009f06:
	l32r	a2, lit_3ffe2300        # 40009f06  = 0xe00a0000
	memw                            # 40009f09
	l32i.n	a2, a2, 0               # 40009f0c
	retw.n                          # 40009f0e
	.size	fn_40009ee8, . - fn_40009ee8
