# fn_40002bf0: 0x40002bf0-0x40002c9c (firmware file offset 0x32bf0-0x32c9c), 66 instructions
# Called from: fn_40003174
# Calls: fn_40002660, fn_400069f0
# Addresses loaded: data_3ffe2580, data_3ffe2390
# Other literal values: 0x00000d00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002bf0, @function
fn_40002bf0:
	entry	a1, 64                  # 40002bf0
	s32i.n	a2, a1, 16              # 40002bf3
	s32i.n	a3, a1, 20              # 40002bf5
	l32i.n	a5, a1, 20              # 40002bf7
	bnei	a5, 1, .L40002c57       # 40002bf9
	l32r	a7, lit_3ffe1bd0        # 40002bfc  = data_3ffe2580
	l32i.n	a7, a7, 0               # 40002bff
	l32i.n	a6, a1, 16              # 40002c01
	bgeu	a6, a7, .L40002c20      # 40002c03
	l32i.n	a10, a1, 16             # 40002c06
	slli	a10, a10, 8             # 40002c08
	l32r	a11, lit_3ffe1bd0       # 40002c0b  = data_3ffe2580
	l32i.n	a11, a11, 0             # 40002c0e
	l32r	a12, lit_3ffe1a98       # 40002c10  = data_3ffe2390
	l32i.n	a12, a12, 52            # 40002c13
	call8	fn_40002660             # 40002c15
	l32r	a11, lit_3ffe1bd0       # 40002c18  = data_3ffe2580
	s32i.n	a10, a11, 0             # 40002c1b
	j	.L40002c41              # 40002c1d
.L40002c20:
	l32i.n	a13, a1, 16             # 40002c20
	l32r	a12, lit_3ffe1bd0       # 40002c22  = data_3ffe2580
	l32i.n	a12, a12, 0             # 40002c25
	bgeu	a12, a13, .L40002c41    # 40002c27
	l32i.n	a10, a1, 16             # 40002c2a
	slli	a10, a10, 8             # 40002c2c
	l32r	a11, lit_3ffe1bd0       # 40002c2f  = data_3ffe2580
	l32i.n	a11, a11, 0             # 40002c32
	l32r	a12, lit_3ffe1a98       # 40002c34  = data_3ffe2390
	l32i.n	a12, a12, 56            # 40002c37
	call8	fn_40002660             # 40002c39
	l32r	a11, lit_3ffe1bd0       # 40002c3c  = data_3ffe2580
	s32i.n	a10, a11, 0             # 40002c3f
.L40002c41:
	l32r	a13, lit_3ffe1a98       # 40002c41  = data_3ffe2390
	movi	a14, 128                # 40002c44
	l32r	a12, lit_3ffe1bd0       # 40002c47  = data_3ffe2580
	l32i.n	a12, a12, 0             # 40002c4a
	add.n	a12, a12, a14           # 40002c4c
	srli	a12, a12, 8             # 40002c4e
	s32i	a12, a13, 72            # 40002c51
	j	.L40002c69              # 40002c54
.L40002c57:
	l32r	a15, lit_3ffe1bd0       # 40002c57  = data_3ffe2580
	l32i.n	a14, a1, 16             # 40002c5a
	slli	a14, a14, 8             # 40002c5c
	s32i.n	a14, a15, 0             # 40002c5f
	l32r	a14, lit_3ffe1a98       # 40002c61  = data_3ffe2390
	l32i.n	a13, a1, 16             # 40002c64
	s32i	a13, a14, 72            # 40002c66
.L40002c69:
	l32r	a2, lit_3ffe1a98        # 40002c69  = data_3ffe2390
	l32i	a2, a2, 72              # 40002c6c
	l32r	a15, lit_3ffe1bd4       # 40002c6f  = 0x00000d00
	bltu	a15, a2, .L40002c85     # 40002c72
	movi.n	a4, 16                  # 40002c75
	l32r	a3, lit_3ffe1a98        # 40002c77  = data_3ffe2390
	l32i	a3, a3, 72              # 40002c7a
	maxu	a3, a3, a4              # 40002c7d
	s32i.n	a3, a1, 0               # 40002c80
	j	.L40002c8a              # 40002c82
.L40002c85:
	l32r	a4, lit_3ffe1bd4        # 40002c85  = 0x00000d00
	s32i.n	a4, a1, 0               # 40002c88
.L40002c8a:
	l32r	a12, lit_3ffe1a98       # 40002c8a  = data_3ffe2390
	l32i.n	a11, a1, 0              # 40002c8d
	s32i	a11, a12, 72            # 40002c8f
	l32r	a10, lit_3ffe1a98       # 40002c92  = data_3ffe2390
	l32i	a10, a10, 72            # 40002c95
	call8	fn_400069f0             # 40002c98
	retw.n                          # 40002c9b
	.size	fn_40002bf0, . - fn_40002bf0
