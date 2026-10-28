# fn_40002660: 0x40002660-0x40002686 (firmware file offset 0x32660-0x32686), 16 instructions
# Called from: fn_40002894, fn_40002a00, fn_40002bf0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002660, @function
fn_40002660:
	entry	a1, 48                  # 40002660
	s32i.n	a2, a1, 0               # 40002663
	s32i.n	a3, a1, 4               # 40002665
	s32i.n	a4, a1, 8               # 40002667
	l32i.n	a5, a1, 8               # 40002669
	movi	a4, 0x400               # 4000266b
	sub	a4, a4, a5              # 4000266e
	l32i.n	a3, a1, 4               # 40002671
	mull	a3, a3, a4              # 40002673
	l32i.n	a4, a1, 8               # 40002676
	l32i.n	a2, a1, 0               # 40002678
	mull	a2, a2, a4              # 4000267a
	add.n	a2, a2, a3              # 4000267d
	addmi	a2, a2, 0x200           # 4000267f
	srli	a2, a2, 10              # 40002682
	retw.n                          # 40002685
	.size	fn_40002660, . - fn_40002660
