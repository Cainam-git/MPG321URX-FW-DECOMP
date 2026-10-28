# fn_40008c38: 0x40008c38-0x40008c56 (firmware file offset 0x38c38-0x38c56), 12 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008c38, @function
fn_40008c38:
	entry	a1, 48                  # 40008c38
	s32i.n	a2, a1, 0               # 40008c3b
	read_impwire	a2              # 40008c3d
	movi.n	a3, 1                   # 40008c40
	l32i.n	a4, a1, 0               # 40008c42
	ssl	a4                      # 40008c44
	sll	a3, a3                  # 40008c47
	and	a2, a2, a3              # 40008c4a
	l32i.n	a3, a1, 0               # 40008c4d
	ssr	a3                      # 40008c4f
	srl	a2, a2                  # 40008c52
	retw.n                          # 40008c55
	.size	fn_40008c38, . - fn_40008c38
