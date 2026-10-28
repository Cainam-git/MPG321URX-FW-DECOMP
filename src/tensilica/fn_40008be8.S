# fn_40008be8: 0x40008be8-0x40008c0d (firmware file offset 0x38be8-0x38c0d), 16 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008be8, @function
fn_40008be8:
	entry	a1, 64                  # 40008be8
	s32i.n	a2, a1, 16              # 40008beb
	movi.n	a8, 1                   # 40008bed
	l32i.n	a9, a1, 16              # 40008bef
	ssl	a9                      # 40008bf1
	sll	a8, a8                  # 40008bf4
	s32i.n	a8, a1, 0               # 40008bf7
	movi.n	a6, 1                   # 40008bf9
	l32i.n	a7, a1, 16              # 40008bfb
	ssl	a7                      # 40008bfd
	sll	a6, a6                  # 40008c00
	s32i.n	a6, a1, 4               # 40008c03
	l32i.n	a4, a1, 0               # 40008c05
	l32i.n	a5, a1, 4               # 40008c07
	wrmsk_expstate	a4, a5          # 40008c09
	retw.n                          # 40008c0c
	.size	fn_40008be8, . - fn_40008be8
