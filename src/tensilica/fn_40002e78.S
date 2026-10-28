# fn_40002e78: 0x40002e78-0x400030b1 (firmware file offset 0x32e78-0x330b1), 219 instructions
# Called from: fn_400030b4
# Calls: fn_40003f10
# Other literal values: 0xe0091094, 0x00000d70, 0x3ffe2bf0, 0x00001400, 0x3ffe4490, 0xe0080370, 0xe0080700,
#                       0xe0080704, 0xe0080708, 0xe0091090

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002e78, @function
fn_40002e78:
	entry	a1, 112                 # 40002e78
	movi.n	a6, 0                   # 40002e7b
	s32i.n	a6, a1, 0               # 40002e7d
	movi.n	a5, 0                   # 40002e7f
	s32i.n	a5, a1, 4               # 40002e81
	movi.n	a4, 0                   # 40002e83
	s32i.n	a4, a1, 8               # 40002e85
	l32r	a3, lit_3ffe1be0        # 40002e87  = 0xe0091094
	memw                            # 40002e8a
	l32i.n	a3, a3, 0               # 40002e8d
	s32i.n	a3, a1, 12              # 40002e8f
	l32r	a3, lit_3ffe1b18        # 40002e91  = 0x00000d70
	l32r	a2, lit_3ffe1a80        # 40002e94  = 0x3ffe2bf0
	l32i.n	a2, a2, 0               # 40002e97
	beq	a2, a3, .L40002eaa      # 40002e99
	l32r	a8, lit_3ffe1b1c        # 40002e9c  = 0x00001400
	l32r	a7, lit_3ffe1a80        # 40002e9f  = 0x3ffe2bf0
	l32i.n	a7, a7, 0               # 40002ea2
	beq	a7, a8, .L40002eaa      # 40002ea4
	j	.L40002f2e              # 40002ea7
.L40002eaa:
	movi.n	a10, 0                  # 40002eaa
	s32i.n	a10, a1, 0              # 40002eac
	l32i.n	a9, a1, 0               # 40002eae
	movi	a8, 0x7ff               # 40002eb0
	bltu	a8, a9, .L40002efd      # 40002eb3
.L40002eb6:
	l32i.n	a12, a1, 12             # 40002eb6
	movi	a11, 0x2ee              # 40002eb8
	bgeu	a11, a12, .L40002ed8    # 40002ebb
	l32i.n	a14, a1, 0              # 40002ebe
	l32r	a15, lit_3ffe1b88       # 40002ec0  = 0x3ffe4490
	addx2	a14, a14, a15           # 40002ec3
	l16ui	a14, a14, 0             # 40002ec6
	movi	a13, 192                # 40002ec9
	bgeu	a13, a14, .L40002ed5    # 40002ecc
	l32i.n	a2, a1, 4               # 40002ecf
	addi.n	a2, a2, 1               # 40002ed1
	s32i.n	a2, a1, 4               # 40002ed3
.L40002ed5:
	j	.L40002eef              # 40002ed5
.L40002ed8:
	l32i.n	a4, a1, 0               # 40002ed8
	l32r	a5, lit_3ffe1b88        # 40002eda  = 0x3ffe4490
	addx2	a4, a4, a5              # 40002edd
	l16ui	a4, a4, 0               # 40002ee0
	movi	a3, 128                 # 40002ee3
	bgeu	a3, a4, .L40002eef      # 40002ee6
	l32i.n	a6, a1, 4               # 40002ee9
	addi.n	a6, a6, 1               # 40002eeb
	s32i.n	a6, a1, 4               # 40002eed
.L40002eef:
	l32i.n	a9, a1, 0               # 40002eef
	addi.n	a9, a9, 1               # 40002ef1
	s32i.n	a9, a1, 0               # 40002ef3
	l32i.n	a8, a1, 0               # 40002ef5
	movi	a7, 0x7ff               # 40002ef7
	bgeu	a7, a8, .L40002eb6      # 40002efa
.L40002efd:
	movi	a13, 100                # 40002efd
	l32i.n	a12, a1, 4              # 40002f00
	mull	a12, a12, a13           # 40002f02
	srli	a12, a12, 11            # 40002f05
	s32i.n	a12, a1, 8              # 40002f08
	movi.n	a11, 0                  # 40002f0a
	l32i.n	a10, a1, 8              # 40002f0c
	bne	a10, a11, .L40002f23    # 40002f0e
	l32i.n	a15, a1, 4              # 40002f11
	movi.n	a14, 0                  # 40002f13
	bgeu	a14, a15, .L40002f23    # 40002f15
	l32r	a3, lit_3ffe1a80        # 40002f18  = 0x3ffe2bf0
	movi.n	a2, 1                   # 40002f1b
	s32i	a2, a3, 0x15c           # 40002f1d
	j	.L40002f2b              # 40002f20
.L40002f23:
	l32r	a5, lit_3ffe1a80        # 40002f23  = 0x3ffe2bf0
	l32i.n	a4, a1, 8               # 40002f26
	s32i	a4, a5, 0x15c           # 40002f28
.L40002f2b:
	j	.L400030a2              # 40002f2b
.L40002f2e:
	l32r	a10, lit_3ffe1be4       # 40002f2e  = 0xe0080370
	call8	fn_40003f10             # 40002f31
	extui	a9, a10, 0, 8           # 40002f34
	l32r	a10, lit_3ffe1a80       # 40002f37  = 0x3ffe2bf0
	l32i.n	a10, a10, 4             # 40002f3a
	l32r	a8, lit_3ffe1a80        # 40002f3c  = 0x3ffe2bf0
	l32i.n	a8, a8, 0               # 40002f3f
	mull	a8, a8, a10             # 40002f41
	quou	a8, a8, a9              # 40002f44
	s32i.n	a8, a1, 16              # 40002f47
	l32i.n	a7, a1, 12              # 40002f49
	movi	a6, 0x2ee               # 40002f4b
	bltu	a6, a7, .L40002f54      # 40002f4e
	j	.L4000300b              # 40002f51
.L40002f54:
	l32r	a10, lit_3ffe1b78       # 40002f54  = 0xe0080700
	call8	fn_40003f10             # 40002f57
	s32i.n	a10, a1, 20             # 40002f5a
	l32r	a10, lit_3ffe1be8       # 40002f5c  = 0xe0080704
	call8	fn_40003f10             # 40002f5f
	s32i.n	a10, a1, 24             # 40002f62
	l32r	a10, lit_3ffe1bec       # 40002f64  = 0xe0080708
	call8	fn_40003f10             # 40002f67
	l32i.n	a14, a1, 16             # 40002f6a
	movi	a15, 100                # 40002f6c
	l32i.n	a13, a1, 20             # 40002f6f
	l32i.n	a2, a1, 24              # 40002f71
	add.n	a13, a13, a2            # 40002f73
	add.n	a13, a10, a13           # 40002f75
	mull	a13, a13, a15           # 40002f77
	quou	a13, a13, a14           # 40002f7a
	movi	a12, 99                 # 40002f7d
	sub	a12, a12, a13           # 40002f80
	movi	a11, 100                # 40002f83
	bltu	a11, a12, .L40002ffb    # 40002f86
	l32r	a10, lit_3ffe1b78       # 40002f89  = 0xe0080700
	call8	fn_40003f10             # 40002f8c
	s32i.n	a10, a1, 28             # 40002f8f
	l32r	a10, lit_3ffe1be8       # 40002f91  = 0xe0080704
	call8	fn_40003f10             # 40002f94
	s32i.n	a10, a1, 32             # 40002f97
	l32r	a10, lit_3ffe1bec       # 40002f99  = 0xe0080708
	call8	fn_40003f10             # 40002f9c
	l32i.n	a6, a1, 16              # 40002f9f
	movi	a7, 100                 # 40002fa1
	l32i.n	a5, a1, 28              # 40002fa4
	l32i.n	a8, a1, 32              # 40002fa6
	add.n	a5, a5, a8              # 40002fa8
	add.n	a5, a10, a5             # 40002faa
	mull	a5, a5, a7              # 40002fac
	quou	a5, a5, a6              # 40002faf
	movi	a4, 99                  # 40002fb2
	sub	a4, a4, a5              # 40002fb5
	movi.n	a3, 0                   # 40002fb8
	beqz.n	a3, .L40002fc3          # 40002fba
	movi.n	a9, 0                   # 40002fbc
	s32i.n	a9, a1, 36              # 40002fbe
	j	.L40002ff4              # 40002fc0
.L40002fc3:
	l32r	a10, lit_3ffe1b78       # 40002fc3  = 0xe0080700
	call8	fn_40003f10             # 40002fc6
	s32i.n	a10, a1, 40             # 40002fc9
	l32r	a10, lit_3ffe1be8       # 40002fcb  = 0xe0080704
	call8	fn_40003f10             # 40002fce
	s32i.n	a10, a1, 44             # 40002fd1
	l32r	a10, lit_3ffe1bec       # 40002fd3  = 0xe0080708
	call8	fn_40003f10             # 40002fd6
	l32i.n	a12, a1, 16             # 40002fd9
	movi	a13, 100                # 40002fdb
	l32i.n	a11, a1, 40             # 40002fde
	l32i.n	a14, a1, 44             # 40002fe0
	add.n	a11, a11, a14           # 40002fe2
	add.n	a11, a10, a11           # 40002fe4
	mull	a11, a11, a13           # 40002fe6
	quou	a11, a11, a12           # 40002fe9
	movi	a10, 99                 # 40002fec
	sub	a10, a10, a11           # 40002fef
	s32i.n	a10, a1, 36             # 40002ff2
.L40002ff4:
	l32i.n	a15, a1, 36             # 40002ff4
	s32i.n	a15, a1, 48             # 40002ff6
	j	.L40003000              # 40002ff8
.L40002ffb:
	movi	a2, 100                 # 40002ffb
	s32i.n	a2, a1, 48              # 40002ffe
.L40003000:
	l32r	a4, lit_3ffe1a80        # 40003000  = 0x3ffe2bf0
	l32i.n	a3, a1, 48              # 40003003
	s32i	a3, a4, 0x15c           # 40003005
	j	.L400030a2              # 40003008
.L4000300b:
	l32r	a10, lit_3ffe1b78       # 4000300b  = 0xe0080700
	call8	fn_40003f10             # 4000300e
	s32i.n	a10, a1, 52             # 40003011
	l32r	a10, lit_3ffe1be8       # 40003013  = 0xe0080704
	call8	fn_40003f10             # 40003016
	l32i.n	a8, a1, 16              # 40003019
	movi	a9, 100                 # 4000301b
	l32i.n	a7, a1, 52              # 4000301e
	add.n	a7, a7, a10             # 40003020
	mull	a7, a7, a9              # 40003022
	quou	a7, a7, a8              # 40003025
	movi	a6, 99                  # 40003028
	sub	a6, a6, a7              # 4000302b
	movi	a5, 100                 # 4000302e
	bltu	a5, a6, .L40003093      # 40003031
	l32r	a10, lit_3ffe1b78       # 40003034  = 0xe0080700
	call8	fn_40003f10             # 40003037
	s32i.n	a10, a1, 56             # 4000303a
	l32r	a10, lit_3ffe1be8       # 4000303c  = 0xe0080704
	call8	fn_40003f10             # 4000303f
	mov.n	a13, a10                # 40003042
	l32i.n	a11, a1, 16             # 40003044
	movi	a12, 100                # 40003046
	l32i.n	a10, a1, 56             # 40003049
	add.n	a10, a10, a13           # 4000304b
	mull	a10, a10, a12           # 4000304d
	quou	a10, a10, a11           # 40003050
	movi	a9, 99                  # 40003053
	sub	a9, a9, a10             # 40003056
	movi.n	a8, 0                   # 40003059
	beqz.n	a8, .L40003064          # 4000305b
	movi.n	a14, 0                  # 4000305d
	s32i.n	a14, a1, 60             # 4000305f
	j	.L4000308b              # 40003061
.L40003064:
	l32r	a10, lit_3ffe1b78       # 40003064  = 0xe0080700
	call8	fn_40003f10             # 40003067
	s32i	a10, a1, 64             # 4000306a
	l32r	a10, lit_3ffe1be8       # 4000306d  = 0xe0080704
	call8	fn_40003f10             # 40003070
	l32i.n	a3, a1, 16              # 40003073
	movi	a4, 100                 # 40003075
	l32i	a2, a1, 64              # 40003078
	add.n	a2, a2, a10             # 4000307b
	mull	a2, a2, a4              # 4000307d
	quou	a2, a2, a3              # 40003080
	movi	a15, 99                 # 40003083
	sub	a15, a15, a2            # 40003086
	s32i.n	a15, a1, 60             # 40003089
.L4000308b:
	l32i.n	a3, a1, 60              # 4000308b
	s32i	a3, a1, 68              # 4000308d
	j	.L40003099              # 40003090
.L40003093:
	movi	a4, 100                 # 40003093
	s32i	a4, a1, 68              # 40003096
.L40003099:
	l32r	a6, lit_3ffe1a80        # 40003099  = 0x3ffe2bf0
	l32i	a5, a1, 68              # 4000309c
	s32i	a5, a6, 0x15c           # 4000309f
.L400030a2:
	l32r	a8, lit_3ffe1bf0        # 400030a2  = 0xe0091090
	l32r	a7, lit_3ffe1a80        # 400030a5  = 0x3ffe2bf0
	l32i	a7, a7, 0x15c           # 400030a8
	memw                            # 400030ab
	s32i.n	a7, a8, 0               # 400030ae
	retw.n                          # 400030b0
	.size	fn_40002e78, . - fn_40002e78
