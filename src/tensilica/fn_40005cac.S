# fn_40005cac: 0x40005cac-0x40005cf5 (firmware file offset 0x35cac-0x35cf5), 30 instructions
# Address stored in the words at: 0x4000b3d8
# Calls: fn_400089e8, fn_40008af8, fn_4000912c, fn_400099bc
# Text loaded: "GPIOtest done!!"

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005cac, @function
fn_40005cac:
	entry	a1, 64                  # 40005cac
	s32i.n	a2, a1, 16              # 40005caf
	rur.expstate	a9              # 40005cb1
	s32i.n	a9, a1, 0               # 40005cb4
	movi.n	a7, 0                   # 40005cb6
	movi.n	a8, -1                  # 40005cb8
	wrmsk_expstate	a7, a8          # 40005cba
	movi.n	a6, 0                   # 40005cbd
	s32i.n	a6, a1, 4               # 40005cbf
	l32i.n	a5, a1, 4               # 40005cc1
	movi	a4, 0x3e7               # 40005cc3
	blt	a4, a5, .L40005cee      # 40005cc6
.L40005cc9:
	l32i.n	a10, a1, 4              # 40005cc9
	bbsi	a10, 0, .L40005cd6      # 40005ccb
	l32i.n	a10, a1, 16             # 40005cce
	call8	fn_400089e8             # 40005cd0
	j	.L40005cdb              # 40005cd3
.L40005cd6:
	l32i.n	a10, a1, 16             # 40005cd6
	call8	fn_40008af8             # 40005cd8
.L40005cdb:
	movi.n	a10, 1                  # 40005cdb
	call8	fn_4000912c             # 40005cdd
	l32i.n	a13, a1, 4              # 40005ce0
	addi.n	a13, a13, 1             # 40005ce2
	s32i.n	a13, a1, 4              # 40005ce4
	l32i.n	a12, a1, 4              # 40005ce6
	movi	a11, 0x3e7              # 40005ce8
	bge	a11, a12, .L40005cc9    # 40005ceb
.L40005cee:
	l32r	a10, lit_3ffe1e28       # 40005cee  = ro_3ffe09d4 "GPIOtest done!!"
	call8	fn_400099bc             # 40005cf1
	retw.n                          # 40005cf4
	.size	fn_40005cac, . - fn_40005cac
