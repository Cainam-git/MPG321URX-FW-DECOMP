# fn_400091f4: 0x400091f4-0x40009214 (firmware file offset 0x391f4-0x39214), 14 instructions
# Called from: fn_40005de8
# Calls: fn_40009ee8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400091f4, @function
fn_400091f4:
	entry	a1, 48                  # 400091f4
	call8	fn_40009ee8             # 400091f7
	s32i.n	a10, a1, 0              # 400091fa
	movi.n	a3, 0                   # 400091fc
	l32i.n	a2, a1, 0               # 400091fe
	blt	a2, a3, .L4000920a      # 40009200
	l32i.n	a4, a1, 0               # 40009203
	s32i.n	a4, a1, 4               # 40009205
	j	.L40009211              # 40009207
.L4000920a:
	movi.n	a5, -1                  # 4000920a
	s32i.n	a5, a1, 4               # 4000920c
	j	.L40009211              # 4000920e
.L40009211:
	l32i.n	a2, a1, 4               # 40009211
	retw.n                          # 40009213
	.size	fn_400091f4, . - fn_400091f4
