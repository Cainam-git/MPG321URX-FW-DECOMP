# fn_40001880: 0x40001880-0x40001890 (firmware file offset 0x31880-0x31890), 7 instructions
# Address stored in the words at: 0x4000d30c
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001880, @function
fn_40001880:
	entry	a1, 48                  # 40001880
	s32i.n	a2, a1, 0               # 40001883
	s32i.n	a3, a1, 4               # 40001885
	l32r	a6, lit_3ffe1a98        # 40001887  = data_3ffe2390
	l32i.n	a5, a1, 4               # 4000188a
	s32i	a5, a6, 68              # 4000188c
	retw.n                          # 4000188f
	.size	fn_40001880, . - fn_40001880
