# fn_40004190: 0x40004190-0x400041a4 (firmware file offset 0x34190-0x341a4), 8 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_40003fa0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004190, @function
fn_40004190:
	entry	a1, 48                  # 40004190
	s32i.n	a2, a1, 0               # 40004193
	extui	a2, a3, 0, 8            # 40004195
	s8i	a2, a1, 4               # 40004198
	l32i.n	a10, a1, 0              # 4000419b
	l8ui	a11, a1, 4              # 4000419d
	call8	fn_40003fa0             # 400041a0
	retw.n                          # 400041a3
	.size	fn_40004190, . - fn_40004190
