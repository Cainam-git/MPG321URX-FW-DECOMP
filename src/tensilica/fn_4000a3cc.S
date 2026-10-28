# fn_4000a3cc: 0x4000a3cc-0x4000a457 (firmware file offset 0x3a3cc-0x3a457), 51 instructions
# Called from: fn_40000800
# Calls: fn_40003c94, fn_40005ba8, fn_40008e9c, fn_40009104, fn_40005dd8, fn_40006f00, fn_400068c0,
#        fn_40000e20, fn_40008f58, fn_400037d8, fn_400099bc, fn_40003764, fn_40003814, fn_400058dc
# Text loaded: "\nGot power down command..\n", "Enter to Idle loop", "SW_IRQ!!\n"
# Addresses loaded: fn_4000a3c4
# Other literal values: 0x11223344, 0xe0091000, 0x3ffe5edc
# 1 instruction after an unconditional jump or return: no branch, jump, call or stored address leads to it.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a3cc, @function
fn_4000a3cc:
	entry	a1, 48                  # 4000a3cc
	call8	fn_40003c94             # 4000a3cf
	call8	fn_40005ba8             # 4000a3d2
	call8	fn_40008e9c             # 4000a3d5
	movi.n	a2, 0                   # 4000a3d8
	s32i.n	a2, a1, 0               # 4000a3da
	l32r	a10, lit_3ffe232c       # 4000a3dc  = fn_4000a3c4
	call8	fn_40009104             # 4000a3df
	call8	fn_40005dd8             # 4000a3e2
	call8	fn_40006f00             # 4000a3e5
	call8	fn_400068c0             # 4000a3e8
	call8	fn_40000e20             # 4000a3eb
	call8	fn_40008f58             # 4000a3ee
	call8	fn_400037d8             # 4000a3f1
.L4000a3f4:
	l32r	a4, lit_3ffe2330        # 4000a3f4  = 0x11223344
	l32r	a3, lit_3ffe2334        # 4000a3f7  = 0xe0091000
	memw                            # 4000a3fa
	l32i.n	a3, a3, 0               # 4000a3fd
	bne	a3, a4, .L4000a426      # 4000a3ff
	l32r	a5, lit_3ffe2334        # 4000a402  = 0xe0091000
	movi.n	a6, -1                  # 4000a405
	l32r	a4, lit_3ffe2334        # 4000a407  = 0xe0091000
	memw                            # 4000a40a
	l32i.n	a4, a4, 0               # 4000a40d
	xor	a4, a4, a6              # 4000a40f
	memw                            # 4000a412
	s32i.n	a4, a5, 0               # 4000a415
	l32r	a10, lit_3ffe2338       # 4000a417  = ro_3ffe19c0 "\nGot power down command..\n"
	call8	fn_400099bc             # 4000a41a
	l32r	a10, lit_3ffe233c       # 4000a41d  = ro_3ffe19dc "Enter to Idle loop"
	call8	fn_400099bc             # 4000a420
.L4000a423:
	j	.L4000a423              # 4000a423
.L4000a426:
	l32r	a5, lit_3ffe2234        # 4000a426  = 0x3ffe5edc
	l32i.n	a5, a5, 0               # 4000a429
	bnei	a5, 1, .L4000a43b       # 4000a42b
	l32r	a10, lit_3ffe2340       # 4000a42e  = ro_3ffe19f0 "SW_IRQ!!\n"
	call8	fn_400099bc             # 4000a431
	l32r	a7, lit_3ffe2234        # 4000a434  = 0x3ffe5edc
	movi.n	a6, 0                   # 4000a437
	s32i.n	a6, a7, 0               # 4000a439
.L4000a43b:
	l32r	a8, lit_3ffe2234        # 4000a43b  = 0x3ffe5edc
	l32i.n	a8, a8, 4               # 4000a43e
	bnei	a8, 1, .L4000a44d       # 4000a440
	call8	fn_40003764             # 4000a443
	l32r	a10, lit_3ffe2234       # 4000a446  = 0x3ffe5edc
	movi.n	a9, 0                   # 4000a449
	s32i.n	a9, a10, 4              # 4000a44b
.L4000a44d:
	call8	fn_40003814             # 4000a44d
	call8	fn_400058dc             # 4000a450
	j	.L4000a3f4              # 4000a453
	retw.n                          # 4000a456
	.size	fn_4000a3cc, . - fn_4000a3cc
