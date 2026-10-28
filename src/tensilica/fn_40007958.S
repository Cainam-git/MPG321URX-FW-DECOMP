# fn_40007958: 0x40007958-0x40007997 (firmware file offset 0x37958-0x37997), 24 instructions
# Called from: fn_40001994
# Calls: fn_40007914, fn_40007878, fn_400078e8
# Other literal values: 0x3ffe2d30

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007958, @function
fn_40007958:
	entry	a1, 48                  # 40007958
	s32i.n	a2, a1, 0               # 4000795b
	l32i.n	a4, a1, 0               # 4000795d
	bnei	a4, 1, .L40007975       # 4000795f
	movi.n	a10, 1                  # 40007962
	call8	fn_40007914             # 40007964
	movi.n	a10, 6                  # 40007967
	call8	fn_40007878             # 40007969
	movi	a10, 96                 # 4000796c
	call8	fn_400078e8             # 4000796f
	j	.L40007996              # 40007972
.L40007975:
	movi.n	a10, 0                  # 40007975
	call8	fn_40007914             # 40007977
	l32r	a5, lit_3ffe20e0        # 4000797a  = 0x3ffe2d30
	l32i.n	a5, a5, 0               # 4000797d
	bgeui	a5, 4, .L4000798b       # 4000797f
	movi	a10, 128                # 40007982
	call8	fn_40007878             # 40007985
	j	.L40007991              # 40007988
.L4000798b:
	movi	a10, 132                # 4000798b
	call8	fn_40007878             # 4000798e
.L40007991:
	movi.n	a10, 0                  # 40007991
	call8	fn_400078e8             # 40007993
.L40007996:
	retw.n                          # 40007996
	.size	fn_40007958, . - fn_40007958
