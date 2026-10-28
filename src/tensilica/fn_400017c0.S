# fn_400017c0: 0x400017c0-0x4000182e (firmware file offset 0x317c0-0x3182e), 43 instructions
# Address stored in the words at: 0x4000d2ec
# Calls: fn_40001188, fn_4000087c, fn_400011e4
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe2bf0, 0x3ffe3ef0, 0xe0091028

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400017c0, @function
fn_400017c0:
	entry	a1, 48                  # 400017c0
	s32i.n	a2, a1, 0               # 400017c3
	s32i.n	a3, a1, 4               # 400017c5
	l32r	a12, lit_3ffe1a98       # 400017c7  = data_3ffe2390
	l32i.n	a11, a1, 4              # 400017ca
	extui	a11, a11, 0, 10         # 400017cc
	s32i.n	a11, a12, 28            # 400017cf
	l32r	a10, lit_3ffe1a98       # 400017d1  = data_3ffe2390
	l32i.n	a10, a10, 12            # 400017d4
	l32r	a11, lit_3ffe1a98       # 400017d6  = data_3ffe2390
	l32i.n	a11, a11, 8             # 400017d9
	l32r	a12, lit_3ffe1a98       # 400017db  = data_3ffe2390
	l32i.n	a12, a12, 24            # 400017de
	l32r	a13, lit_3ffe1a98       # 400017e0  = data_3ffe2390
	l32i.n	a13, a13, 28            # 400017e3
	call8	fn_40001188             # 400017e5
	l32r	a13, lit_3ffe1a98       # 400017e8  = data_3ffe2390
	s32i.n	a10, a13, 20            # 400017eb
	movi.n	a13, 0                  # 400017ed
	l32r	a12, lit_3ffe1a80       # 400017ef  = 0x3ffe2bf0
	l32i	a12, a12, 0x144         # 400017f2
	beq	a12, a13, .L40001801    # 400017f5
	l32r	a14, lit_3ffe1a80       # 400017f8  = 0x3ffe2bf0
	l32i	a14, a14, 0x144         # 400017fb
	bnei	a14, 3, .L40001816      # 400017fe
.L40001801:
	l32r	a10, lit_3ffe1a98       # 40001801  = data_3ffe2390
	l32i.n	a10, a10, 20            # 40001804
	l32r	a11, lit_3ffe1ac4       # 40001806  = 0x3ffe3ef0
	l32r	a12, lit_3ffe1a98       # 40001809  = data_3ffe2390
	l32i.n	a12, a12, 0             # 4000180c
	call8	fn_4000087c             # 4000180e
	movi.n	a10, 1                  # 40001811
	call8	fn_400011e4             # 40001813
.L40001816:
	l32r	a12, lit_3ffe1b28       # 40001816  = 0xe0091028
	l32r	a13, lit_3ffe1a98       # 40001819  = data_3ffe2390
	l32i.n	a13, a13, 20            # 4000181c
	slli	a13, a13, 16            # 4000181e
	l32r	a11, lit_3ffe1a98       # 40001821  = data_3ffe2390
	l32i.n	a11, a11, 16            # 40001824
	add.n	a11, a11, a13           # 40001826
	memw                            # 40001828
	s32i.n	a11, a12, 0             # 4000182b
	retw.n                          # 4000182d
	.size	fn_400017c0, . - fn_400017c0
