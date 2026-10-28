# fn_400074b4: 0x400074b4-0x400074e9 (firmware file offset 0x374b4-0x374e9), 20 instructions
# Called from: fn_400019c4, fn_4000770c, fn_400077d4, fn_40007820, fn_4000784c, fn_40007878, fn_400078a0,
#              fn_400078e8, fn_40007914, fn_40007998, fn_400079b8
# Calls: fn_40006be8, fn_4000912c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400074b4, @function
fn_400074b4:
	entry	a1, 64                  # 400074b4
	extui	a4, a2, 0, 8            # 400074b7
	s8i	a4, a1, 16              # 400074ba
	extui	a2, a3, 0, 8            # 400074bd
	s8i	a2, a1, 20              # 400074c0
	movi	a7, 192                 # 400074c3
	l8ui	a8, a1, 20              # 400074c6
	slli	a8, a8, 16              # 400074c9
	l8ui	a6, a1, 16              # 400074cc
	slli	a6, a6, 8               # 400074cf
	or	a6, a6, a8              # 400074d2
	or	a6, a6, a7              # 400074d5
	s32i.n	a6, a1, 0               # 400074d8
	movi.n	a10, 1                  # 400074da
	mov.n	a11, a1                 # 400074dc
	movi.n	a12, 1                  # 400074de
	call8	fn_40006be8             # 400074e0
	movi.n	a10, 2                  # 400074e3
	call8	fn_4000912c             # 400074e5
	retw.n                          # 400074e8
	.size	fn_400074b4, . - fn_400074b4
