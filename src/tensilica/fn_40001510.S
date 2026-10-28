# fn_40001510: 0x40001510-0x40001539 (firmware file offset 0x31510-0x31539), 16 instructions
# Address stored in the words at: 0x4000d2d4
# Addresses loaded: data_3ffe2390
# Other literal values: 0x3ffe2bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001510, @function
fn_40001510:
	entry	a1, 48                  # 40001510
	s32i.n	a2, a1, 0               # 40001513
	s32i.n	a3, a1, 4               # 40001515
	l32r	a8, lit_3ffe1a80        # 40001517  = 0x3ffe2bf0
	l32i.n	a7, a1, 4               # 4000151a
	s32i	a7, a8, 0x14c           # 4000151c
	l32r	a6, lit_3ffe1a80        # 4000151f  = 0x3ffe2bf0
	l32i	a6, a6, 0x14c           # 40001522
	l32r	a5, lit_3ffe1a98        # 40001525  = data_3ffe2390
	l32i.n	a5, a5, 16              # 40001528
	bgeu	a5, a6, .L40001538      # 4000152a
	l32r	a9, lit_3ffe1a80        # 4000152d  = 0x3ffe2bf0
	l32r	a8, lit_3ffe1a98        # 40001530  = data_3ffe2390
	l32i.n	a8, a8, 16              # 40001533
	s32i	a8, a9, 0x14c           # 40001535
.L40001538:
	retw.n                          # 40001538
	.size	fn_40001510, . - fn_40001510
