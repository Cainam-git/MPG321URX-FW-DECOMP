# fn_40006c9c: 0x40006c9c-0x40006de5 (firmware file offset 0x36c9c-0x36de5), 126 instructions
# Called from: fn_40006f00, fn_40008010
# Calls: fn_40003f38, fn_40003f24
# Other literal values: 0xc0192000, 0xc0000000, 0x3ffe5490, 0xffffefff, 0x00001000, 0xc0197000, 0xc0192100,
#                       0xc0198000, 0xc0192200, 0xc0199000, 0xc0192300, 0xc019a000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006c9c, @function
fn_40006c9c:
	entry	a1, 64                  # 40006c9c
	s32i.n	a2, a1, 16              # 40006c9f
	s32i.n	a3, a1, 20              # 40006ca1
	l32r	a6, lit_3ffe1f74        # 40006ca3  = 0xc0192000
	s32i.n	a6, a1, 0               # 40006ca6
	l32i.n	a5, a1, 16              # 40006ca8
	extui	a5, a5, 0, 1            # 40006caa
	beqz	a5, .L40006cfa          # 40006cad
	l32r	a12, lit_3ffe1f74       # 40006cb0  = 0xc0192000
	s32i.n	a12, a1, 0              # 40006cb3
	l32i.n	a10, a1, 0              # 40006cb5
	l32i.n	a11, a1, 20             # 40006cb7
	slli	a11, a11, 30            # 40006cb9
	l32r	a12, lit_3ffe1f78       # 40006cbc  = 0xc0000000
	call8	fn_40003f38             # 40006cbf
	movi.n	a14, 0                  # 40006cc2
	l32i.n	a13, a1, 20             # 40006cc4
	bne	a13, a14, .L40006cdc    # 40006cc6
	l32r	a15, lit_3ffe1f7c       # 40006cc9  = 0x3ffe5490
	l32r	a2, lit_3ffe1f80        # 40006ccc  = 0xffffefff
	l32r	a14, lit_3ffe1f7c       # 40006ccf  = 0x3ffe5490
	l32i.n	a14, a14, 0             # 40006cd2
	and	a14, a14, a2            # 40006cd4
	s32i.n	a14, a15, 0             # 40006cd7
	j	.L40006cec              # 40006cd9
.L40006cdc:
	l32r	a2, lit_3ffe1f7c        # 40006cdc  = 0x3ffe5490
	l32r	a3, lit_3ffe1df0        # 40006cdf  = 0x00001000
	l32r	a15, lit_3ffe1f7c       # 40006ce2  = 0x3ffe5490
	l32i.n	a15, a15, 0             # 40006ce5
	or	a15, a15, a3            # 40006ce7
	s32i.n	a15, a2, 0              # 40006cea
.L40006cec:
	l32r	a10, lit_3ffe1f84       # 40006cec  = 0xc0197000
	l32r	a11, lit_3ffe1f7c       # 40006cef  = 0x3ffe5490
	l32i.n	a11, a11, 0             # 40006cf2
	call8	fn_40003f24             # 40006cf4
	j	.L40006de4              # 40006cf7
.L40006cfa:
	l32i.n	a12, a1, 16             # 40006cfa
	bbci	a12, 1, .L40006d49      # 40006cfc
	l32r	a12, lit_3ffe1f88       # 40006cff  = 0xc0192100
	s32i.n	a12, a1, 0              # 40006d02
	l32i.n	a10, a1, 0              # 40006d04
	l32i.n	a11, a1, 20             # 40006d06
	slli	a11, a11, 30            # 40006d08
	l32r	a12, lit_3ffe1f78       # 40006d0b  = 0xc0000000
	call8	fn_40003f38             # 40006d0e
	movi.n	a14, 0                  # 40006d11
	l32i.n	a13, a1, 20             # 40006d13
	bne	a13, a14, .L40006d2b    # 40006d15
	l32r	a15, lit_3ffe1f7c       # 40006d18  = 0x3ffe5490
	l32r	a2, lit_3ffe1f80        # 40006d1b  = 0xffffefff
	l32r	a14, lit_3ffe1f7c       # 40006d1e  = 0x3ffe5490
	l32i.n	a14, a14, 4             # 40006d21
	and	a14, a14, a2            # 40006d23
	s32i.n	a14, a15, 4             # 40006d26
	j	.L40006d3b              # 40006d28
.L40006d2b:
	l32r	a2, lit_3ffe1f7c        # 40006d2b  = 0x3ffe5490
	l32r	a3, lit_3ffe1df0        # 40006d2e  = 0x00001000
	l32r	a15, lit_3ffe1f7c       # 40006d31  = 0x3ffe5490
	l32i.n	a15, a15, 4             # 40006d34
	or	a15, a15, a3            # 40006d36
	s32i.n	a15, a2, 4              # 40006d39
.L40006d3b:
	l32r	a10, lit_3ffe1f8c       # 40006d3b  = 0xc0198000
	l32r	a11, lit_3ffe1f7c       # 40006d3e  = 0x3ffe5490
	l32i.n	a11, a11, 4             # 40006d41
	call8	fn_40003f24             # 40006d43
	j	.L40006de4              # 40006d46
.L40006d49:
	l32i.n	a12, a1, 16             # 40006d49
	bbci	a12, 2, .L40006d98      # 40006d4b
	l32r	a12, lit_3ffe1f90       # 40006d4e  = 0xc0192200
	s32i.n	a12, a1, 0              # 40006d51
	l32i.n	a10, a1, 0              # 40006d53
	l32i.n	a11, a1, 20             # 40006d55
	slli	a11, a11, 30            # 40006d57
	l32r	a12, lit_3ffe1f78       # 40006d5a  = 0xc0000000
	call8	fn_40003f38             # 40006d5d
	movi.n	a14, 0                  # 40006d60
	l32i.n	a13, a1, 20             # 40006d62
	bne	a13, a14, .L40006d7a    # 40006d64
	l32r	a15, lit_3ffe1f7c       # 40006d67  = 0x3ffe5490
	l32r	a2, lit_3ffe1f80        # 40006d6a  = 0xffffefff
	l32r	a14, lit_3ffe1f7c       # 40006d6d  = 0x3ffe5490
	l32i.n	a14, a14, 8             # 40006d70
	and	a14, a14, a2            # 40006d72
	s32i.n	a14, a15, 8             # 40006d75
	j	.L40006d8a              # 40006d77
.L40006d7a:
	l32r	a2, lit_3ffe1f7c        # 40006d7a  = 0x3ffe5490
	l32r	a3, lit_3ffe1df0        # 40006d7d  = 0x00001000
	l32r	a15, lit_3ffe1f7c       # 40006d80  = 0x3ffe5490
	l32i.n	a15, a15, 8             # 40006d83
	or	a15, a15, a3            # 40006d85
	s32i.n	a15, a2, 8              # 40006d88
.L40006d8a:
	l32r	a10, lit_3ffe1f94       # 40006d8a  = 0xc0199000
	l32r	a11, lit_3ffe1f7c       # 40006d8d  = 0x3ffe5490
	l32i.n	a11, a11, 8             # 40006d90
	call8	fn_40003f24             # 40006d92
	j	.L40006de4              # 40006d95
.L40006d98:
	l32i.n	a12, a1, 16             # 40006d98
	bbci	a12, 3, .L40006de4      # 40006d9a
	l32r	a12, lit_3ffe1f98       # 40006d9d  = 0xc0192300
	s32i.n	a12, a1, 0              # 40006da0
	l32i.n	a10, a1, 0              # 40006da2
	l32i.n	a11, a1, 20             # 40006da4
	slli	a11, a11, 30            # 40006da6
	l32r	a12, lit_3ffe1f78       # 40006da9  = 0xc0000000
	call8	fn_40003f38             # 40006dac
	movi.n	a14, 0                  # 40006daf
	l32i.n	a13, a1, 20             # 40006db1
	bne	a13, a14, .L40006dc9    # 40006db3
	l32r	a15, lit_3ffe1f7c       # 40006db6  = 0x3ffe5490
	l32r	a2, lit_3ffe1f80        # 40006db9  = 0xffffefff
	l32r	a14, lit_3ffe1f7c       # 40006dbc  = 0x3ffe5490
	l32i.n	a14, a14, 12            # 40006dbf
	and	a14, a14, a2            # 40006dc1
	s32i.n	a14, a15, 12            # 40006dc4
	j	.L40006dd9              # 40006dc6
.L40006dc9:
	l32r	a2, lit_3ffe1f7c        # 40006dc9  = 0x3ffe5490
	l32r	a3, lit_3ffe1df0        # 40006dcc  = 0x00001000
	l32r	a15, lit_3ffe1f7c       # 40006dcf  = 0x3ffe5490
	l32i.n	a15, a15, 12            # 40006dd2
	or	a15, a15, a3            # 40006dd4
	s32i.n	a15, a2, 12             # 40006dd7
.L40006dd9:
	l32r	a10, lit_3ffe1f9c       # 40006dd9  = 0xc019a000
	l32r	a11, lit_3ffe1f7c       # 40006ddc  = 0x3ffe5490
	l32i.n	a11, a11, 12            # 40006ddf
	call8	fn_40003f24             # 40006de1
.L40006de4:
	retw.n                          # 40006de4
	.size	fn_40006c9c, . - fn_40006c9c
