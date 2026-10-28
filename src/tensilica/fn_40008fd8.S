# fn_40008fd8: 0x40008fd8-0x4000902b (firmware file offset 0x38fd8-0x3902b), 33 instructions
# Address stored in the words at: 0x4000cf5c
# Calls: fn_4000ac08, fn_4000a548, fn_4000abe4, fn_4000abdc
# Indirect calls (callx): 1
# Other literal values: 0x3ffe5598

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008fd8, @function
fn_40008fd8:
	entry	a1, 48                  # 40008fd8
.L40008fdb:
	movi.n	a10, 1                  # 40008fdb
	call8	fn_4000ac08             # 40008fdd
	s32i.n	a10, a1, 0              # 40008fe0
	movi.n	a3, 0                   # 40008fe2
	l32r	a2, lit_3ffe2258        # 40008fe4  = 0x3ffe5598
	l8ui	a2, a2, 12              # 40008fe7
	beq	a2, a3, .L40008ff6      # 40008fea
	movi	a10, 0x400              # 40008fed
	call8	fn_4000a548             # 40008ff0
	j	.L40009004              # 40008ff3
.L40008ff6:
	movi.n	a10, 1                  # 40008ff6
	l32i.n	a12, a1, 0              # 40008ff8
	l32r	a11, lit_3ffe2258       # 40008ffa  = 0x3ffe5598
	l32i.n	a11, a11, 16            # 40008ffd
	add.n	a11, a11, a12           # 40008fff
	call8	fn_4000abe4             # 40009001
.L40009004:
	movi.n	a13, 0                  # 40009004
	l32r	a12, lit_3ffe2258       # 40009006  = 0x3ffe5598
	l32i.n	a12, a12, 20            # 40009009
	beq	a12, a13, .L40009016    # 4000900b
	l32r	a8, lit_3ffe2258        # 4000900e  = 0x3ffe5598
	l32i.n	a8, a8, 20              # 40009011
	callx8	a8                      # 40009013
.L40009016:
	call8	fn_4000abdc             # 40009016
	l32i.n	a11, a1, 0              # 40009019
	sub	a10, a10, a11           # 4000901b
	s32i.n	a10, a1, 4              # 4000901e
	l32i.n	a10, a1, 4              # 40009020
	l32r	a9, lit_3ffe2258        # 40009022  = 0x3ffe5598
	l32i.n	a9, a9, 16              # 40009025
	bltu	a9, a10, .L40008fdb     # 40009027
	retw.n                          # 4000902a
	.size	fn_40008fd8, . - fn_40008fd8
