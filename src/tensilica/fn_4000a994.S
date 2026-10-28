# fn_4000a994: 0x4000a994-0x4000a9b3 (firmware file offset 0x3a994-0x3a9b3), 12 instructions
# Called from: fn_4000a890
# Other literal values: 0xe0000000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000a994, @function
fn_4000a994:
	entry	a1, 16                  # 4000a994
	l32r	a5, lit_3ffe2384        # 4000a997  = 0xe0000000
	movi.n	a2, 0                   # 4000a99a
	movi.n	a3, 0                   # 4000a99c
.L4000a99e:
	add.n	a3, a3, a5              # 4000a99e
	rdtlb1	a4, a3                  # 4000a9a0
	dsync                           # 4000a9a3
	slli	a2, a2, 4               # 4000a9a6
	extui	a4, a4, 0, 4            # 4000a9a9
	or	a2, a2, a4              # 4000a9ac
	bgeui	a3, 16, .L4000a99e      # 4000a9af
	retw.n                          # 4000a9b2
	.size	fn_4000a994, . - fn_4000a994
