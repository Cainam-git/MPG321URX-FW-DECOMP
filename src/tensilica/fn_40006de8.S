# fn_40006de8: 0x40006de8-0x40006e91 (firmware file offset 0x36de8-0x36e91), 65 instructions
# Called from: fn_40006f00, fn_40008010
# Calls: fn_40003f38
# Other literal values: 0xc0192000, 0x00003ff0, 0xc0192100, 0xc0192200, 0xc0192300

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006de8, @function
fn_40006de8:
	entry	a1, 48                  # 40006de8
	s32i.n	a2, a1, 0               # 40006deb
	s32i.n	a3, a1, 4               # 40006ded
	s32i.n	a4, a1, 8               # 40006def
	l32i.n	a7, a1, 0               # 40006df1
	extui	a7, a7, 0, 1            # 40006df3
	beqz.n	a7, .L40006e1b          # 40006df6
	l32r	a10, lit_3ffe1f74       # 40006df8  = 0xc0192000
	l32i.n	a11, a1, 8              # 40006dfb
	addi.n	a11, a11, -1            # 40006dfd
	slli	a11, a11, 4             # 40006dff
	l32r	a12, lit_3ffe1fa0       # 40006e02  = 0x00003ff0
	call8	fn_40003f38             # 40006e05
	l32r	a10, lit_3ffe1f74       # 40006e08  = 0xc0192000
	l32i.n	a11, a1, 4              # 40006e0b
	extui	a11, a11, 0, 1          # 40006e0d
	slli	a11, a11, 3             # 40006e10
	movi.n	a12, 8                  # 40006e13
	call8	fn_40003f38             # 40006e15
	j	.L40006e90              # 40006e18
.L40006e1b:
	l32i.n	a12, a1, 0              # 40006e1b
	bbci	a12, 1, .L40006e43      # 40006e1d
	l32r	a10, lit_3ffe1f88       # 40006e20  = 0xc0192100
	l32i.n	a11, a1, 8              # 40006e23
	addi.n	a11, a11, -1            # 40006e25
	slli	a11, a11, 4             # 40006e27
	l32r	a12, lit_3ffe1fa0       # 40006e2a  = 0x00003ff0
	call8	fn_40003f38             # 40006e2d
	l32r	a10, lit_3ffe1f88       # 40006e30  = 0xc0192100
	l32i.n	a11, a1, 4              # 40006e33
	extui	a11, a11, 0, 1          # 40006e35
	slli	a11, a11, 3             # 40006e38
	movi.n	a12, 8                  # 40006e3b
	call8	fn_40003f38             # 40006e3d
	j	.L40006e90              # 40006e40
.L40006e43:
	l32i.n	a12, a1, 0              # 40006e43
	bbci	a12, 2, .L40006e6b      # 40006e45
	l32r	a10, lit_3ffe1f90       # 40006e48  = 0xc0192200
	l32i.n	a11, a1, 8              # 40006e4b
	addi.n	a11, a11, -1            # 40006e4d
	slli	a11, a11, 4             # 40006e4f
	l32r	a12, lit_3ffe1fa0       # 40006e52  = 0x00003ff0
	call8	fn_40003f38             # 40006e55
	l32r	a10, lit_3ffe1f90       # 40006e58  = 0xc0192200
	l32i.n	a11, a1, 4              # 40006e5b
	extui	a11, a11, 0, 1          # 40006e5d
	slli	a11, a11, 3             # 40006e60
	movi.n	a12, 8                  # 40006e63
	call8	fn_40003f38             # 40006e65
	j	.L40006e90              # 40006e68
.L40006e6b:
	l32i.n	a12, a1, 0              # 40006e6b
	bbci	a12, 3, .L40006e90      # 40006e6d
	l32r	a10, lit_3ffe1f98       # 40006e70  = 0xc0192300
	l32i.n	a11, a1, 8              # 40006e73
	addi.n	a11, a11, -1            # 40006e75
	slli	a11, a11, 4             # 40006e77
	l32r	a12, lit_3ffe1fa0       # 40006e7a  = 0x00003ff0
	call8	fn_40003f38             # 40006e7d
	l32r	a10, lit_3ffe1f98       # 40006e80  = 0xc0192300
	l32i.n	a11, a1, 4              # 40006e83
	extui	a11, a11, 0, 1          # 40006e85
	slli	a11, a11, 3             # 40006e88
	movi.n	a12, 8                  # 40006e8b
	call8	fn_40003f38             # 40006e8d
.L40006e90:
	retw.n                          # 40006e90
	.size	fn_40006de8, . - fn_40006de8
