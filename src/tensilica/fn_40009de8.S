# fn_40009de8: 0x40009de8-0x40009e85 (firmware file offset 0x39de8-0x39e85), 64 instructions
# Called from: fn_400091d0
# Other literal values: 0xe00a0014, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40009de8, @function
fn_40009de8:
	entry	a1, 64                  # 40009de8
	s32i.n	a2, a1, 16              # 40009deb
	movi.n	a5, 0                   # 40009ded
	s32i.n	a5, a1, 0               # 40009def
	movi.n	a5, 0                   # 40009df1
	l32i.n	a4, a1, 16              # 40009df3
	bne	a4, a5, .L40009dff      # 40009df5
	movi.n	a6, -1                  # 40009df8
	s32i.n	a6, a1, 8               # 40009dfa
	j	.L40009e82              # 40009dfc
.L40009dff:
	movi.n	a8, 0                   # 40009dff
	l32i.n	a9, a1, 0               # 40009e01
	l32i.n	a7, a1, 16              # 40009e03
	add.n	a7, a7, a9              # 40009e05
	l8ui	a7, a7, 0               # 40009e07
	beq	a7, a8, .L40009e7e      # 40009e0a
.L40009e0d:
	l32r	a8, lit_3ffe2318        # 40009e0d  = 0xe00a0014
	memw                            # 40009e10
	l32i.n	a8, a8, 0               # 40009e13
	bbci	a8, 5, .L40009e70       # 40009e15
.L40009e18:
	l32i.n	a11, a1, 0              # 40009e18
	l32i.n	a10, a1, 16             # 40009e1a
	add.n	a10, a10, a11           # 40009e1c
	l8ui	a10, a10, 0             # 40009e1e
	s8i	a10, a1, 4              # 40009e21
	l8ui	a9, a1, 4               # 40009e24
	bnei	a9, 10, .L40009e51      # 40009e27
	l32r	a13, lit_3ffe2300       # 40009e2a  = 0xe00a0000
	movi.n	a12, 13                 # 40009e2d
	memw                            # 40009e2f
	s32i.n	a12, a13, 0             # 40009e32
	l32r	a11, lit_3ffe2318       # 40009e34  = 0xe00a0014
	memw                            # 40009e37
	l32i.n	a11, a11, 0             # 40009e3a
	bbsi	a11, 5, .L40009e51      # 40009e3c
.L40009e3f:
	movi.n	a15, 0                  # 40009e3f
	movi.n	a2, 32                  # 40009e41
	l32r	a14, lit_3ffe2318       # 40009e43  = 0xe00a0014
	memw                            # 40009e46
	l32i.n	a14, a14, 0             # 40009e49
	and	a14, a14, a2            # 40009e4b
	beq	a14, a15, .L40009e3f    # 40009e4e
.L40009e51:
	l32r	a4, lit_3ffe2300        # 40009e51  = 0xe00a0000
	l8ui	a3, a1, 4               # 40009e54
	memw                            # 40009e57
	s32i.n	a3, a4, 0               # 40009e5a
	l32i.n	a2, a1, 0               # 40009e5c
	addi.n	a2, a2, 1               # 40009e5e
	s32i.n	a2, a1, 0               # 40009e60
	l32r	a15, lit_3ffe2318       # 40009e62  = 0xe00a0014
	memw                            # 40009e65
	l32i.n	a15, a15, 0             # 40009e68
	extui	a15, a15, 5, 1          # 40009e6a
	bnez	a15, .L40009e18         # 40009e6d
.L40009e70:
	movi.n	a6, 0                   # 40009e70
	l32i.n	a7, a1, 0               # 40009e72
	l32i.n	a5, a1, 16              # 40009e74
	add.n	a5, a5, a7              # 40009e76
	l8ui	a5, a5, 0               # 40009e78
	bne	a5, a6, .L40009e0d      # 40009e7b
.L40009e7e:
	movi.n	a6, 0                   # 40009e7e
	s32i.n	a6, a1, 8               # 40009e80
.L40009e82:
	l32i.n	a2, a1, 8               # 40009e82
	retw.n                          # 40009e84
	.size	fn_40009de8, . - fn_40009de8
