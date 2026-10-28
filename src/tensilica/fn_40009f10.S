# fn_40009f10: 0x40009f10-0x40009f6f (firmware file offset 0x39f10-0x39f6f), 37 instructions
# Address stored in the words at: 0x4000d00c
# Other literal values: 0xe00a0014, 0xe00a0000, 0x3ffe5cd0, 0x3ffe5cd4, 0xe00a1070

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009f10, @function
fn_40009f10:
	entry	a1, 48                  # 40009f10
	l32r	a2, lit_3ffe2318        # 40009f13  = 0xe00a0014
	memw                            # 40009f16
	l32i.n	a2, a2, 0               # 40009f19
	extui	a2, a2, 0, 1            # 40009f1b
	beqz	a2, .L40009f64          # 40009f1e
	l32r	a6, lit_3ffe2300        # 40009f21  = 0xe00a0000
	memw                            # 40009f24
	l32i.n	a6, a6, 0               # 40009f27
	s32i.n	a6, a1, 0               # 40009f29
	l32r	a5, lit_3ffe230c        # 40009f2b  = 0x3ffe5cd0
	l32i	a5, a5, 0x204           # 40009f2e
	addi.n	a5, a5, 1               # 40009f31
	s32i.n	a5, a1, 4               # 40009f33
	l32i.n	a4, a1, 4               # 40009f35
	movi	a3, 127                 # 40009f37
	bgeu	a3, a4, .L40009f41      # 40009f3a
	movi.n	a7, 0                   # 40009f3d
	s32i.n	a7, a1, 4               # 40009f3f
.L40009f41:
	l32i.n	a9, a1, 4               # 40009f41
	l32r	a8, lit_3ffe230c        # 40009f43  = 0x3ffe5cd0
	l32i	a8, a8, 0x208           # 40009f46
	beq	a8, a9, .L40009f64      # 40009f49
	l32r	a12, lit_3ffe230c       # 40009f4c  = 0x3ffe5cd0
	l32i	a12, a12, 0x204         # 40009f4f
	l32r	a13, lit_3ffe231c       # 40009f52  = 0x3ffe5cd4
	addx4	a12, a12, a13           # 40009f55
	l32i.n	a11, a1, 0              # 40009f58
	s32i.n	a11, a12, 0             # 40009f5a
	l32r	a10, lit_3ffe230c       # 40009f5c  = 0x3ffe5cd0
	l32i.n	a9, a1, 4               # 40009f5f
	s32i	a9, a10, 0x204          # 40009f61
.L40009f64:
	l32r	a14, lit_3ffe2220       # 40009f64  = 0xe00a1070
	movi.n	a13, 4                  # 40009f67
	memw                            # 40009f69
	s32i.n	a13, a14, 0             # 40009f6c
	retw.n                          # 40009f6e
	.size	fn_40009f10, . - fn_40009f10
