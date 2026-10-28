# fn_40001428: 0x40001428-0x400014bc (firmware file offset 0x31428-0x314bc), 56 instructions
# Address stored in the words at: 0x4000d294
# Calls: fn_40006904, fn_4000679c, fn_4000087c, fn_400011e4
# Addresses loaded: data_3ffe23e0, data_3ffe2390, data_3ffe2410
# Other literal values: 0x3ffe2bf0, 0x3ffe3eb0, 0x3ffe3ef0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001428, @function
fn_40001428:
	entry	a1, 48                  # 40001428
	s32i.n	a2, a1, 0               # 4000142b
	s32i.n	a3, a1, 4               # 4000142d
	l32r	a7, lit_3ffe1a80        # 4000142f  = 0x3ffe2bf0
	l32i.n	a6, a1, 4               # 40001432
	s32i	a6, a7, 0x144           # 40001434
	l32r	a5, lit_3ffe1a80        # 40001437  = 0x3ffe2bf0
	l32i	a5, a5, 0x144           # 4000143a
	bnei	a5, 3, .L40001452       # 4000143d
	l32r	a10, lit_3ffe1b20       # 40001440  = data_3ffe23e0
	movi.n	a11, 5                  # 40001443
	call8	fn_40006904             # 40001445
	l32r	a8, lit_3ffe1a98        # 40001448  = data_3ffe2390
	movi.n	a7, 4                   # 4000144b
	s32i.n	a7, a8, 4               # 4000144d
	j	.L4000148e              # 4000144f
.L40001452:
	l32r	a9, lit_3ffe1a80        # 40001452  = 0x3ffe2bf0
	l32i	a9, a9, 0x144           # 40001455
	beqi	a9, 1, .L40001464       # 40001458
	l32r	a10, lit_3ffe1a80       # 4000145b  = 0x3ffe2bf0
	l32i	a10, a10, 0x144         # 4000145e
	bnei	a10, 2, .L40001476      # 40001461
.L40001464:
	l32r	a10, lit_3ffe1b24       # 40001464  = data_3ffe2410
	movi.n	a11, 2                  # 40001467
	call8	fn_40006904             # 40001469
	l32r	a12, lit_3ffe1a98       # 4000146c  = data_3ffe2390
	movi.n	a11, 0                  # 4000146f
	s32i.n	a11, a12, 4             # 40001471
	j	.L4000148e              # 40001473
.L40001476:
	l32r	a13, lit_3ffe1a80       # 40001476  = 0x3ffe2bf0
	l32i	a13, a13, 0x144         # 40001479
	bnei	a13, 4, .L4000148e      # 4000147c
	l32r	a10, lit_3ffe1b20       # 4000147f  = data_3ffe23e0
	movi.n	a11, 5                  # 40001482
	call8	fn_40006904             # 40001484
	l32r	a15, lit_3ffe1a98       # 40001487  = data_3ffe2390
	movi.n	a14, 0                  # 4000148a
	s32i.n	a14, a15, 4             # 4000148c
.L4000148e:
	l32r	a10, lit_3ffe1a98       # 4000148e  = data_3ffe2390
	l32i.n	a10, a10, 4             # 40001491
	call8	fn_4000679c             # 40001493
	l32r	a10, lit_3ffe1a98       # 40001496  = data_3ffe2390
	l32i.n	a10, a10, 16            # 40001499
	l32r	a11, lit_3ffe1ac0       # 4000149b  = 0x3ffe3eb0
	l32r	a12, lit_3ffe1a98       # 4000149e  = data_3ffe2390
	l32i.n	a12, a12, 0             # 400014a1
	call8	fn_4000087c             # 400014a3
	l32r	a10, lit_3ffe1a98       # 400014a6  = data_3ffe2390
	l32i.n	a10, a10, 20            # 400014a9
	l32r	a11, lit_3ffe1ac4       # 400014ab  = 0x3ffe3ef0
	l32r	a12, lit_3ffe1a98       # 400014ae  = data_3ffe2390
	l32i.n	a12, a12, 0             # 400014b1
	call8	fn_4000087c             # 400014b3
	movi.n	a10, 1                  # 400014b6
	call8	fn_400011e4             # 400014b8
	retw.n                          # 400014bb
	.size	fn_40001428, . - fn_40001428
