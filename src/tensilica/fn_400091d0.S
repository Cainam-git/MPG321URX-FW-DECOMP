# fn_400091d0: 0x400091d0-0x400091f0 (firmware file offset 0x391d0-0x391f0), 14 instructions
# Called from: fn_400099bc
# Calls: fn_40009de8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400091d0, @function
fn_400091d0:
	entry	a1, 64                  # 400091d0
	s32i.n	a2, a1, 16              # 400091d3
	l32i.n	a10, a1, 16             # 400091d5
	call8	fn_40009de8             # 400091d7
	movi.n	a11, 0                  # 400091da
	blt	a10, a11, .L400091e6    # 400091dc
	movi.n	a12, 0                  # 400091df
	s32i.n	a12, a1, 0              # 400091e1
	j	.L400091ed              # 400091e3
.L400091e6:
	movi.n	a13, -1                 # 400091e6
	s32i.n	a13, a1, 0              # 400091e8
	j	.L400091ed              # 400091ea
.L400091ed:
	l32i.n	a2, a1, 0               # 400091ed
	retw.n                          # 400091ef
	.size	fn_400091d0, . - fn_400091d0
