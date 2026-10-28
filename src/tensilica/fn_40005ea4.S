# fn_40005ea4: 0x40005ea4-0x40005f2b (firmware file offset 0x35ea4-0x35f2b), 57 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Indirect calls (callx): 2
# Other literal values: 0x3ffe4438
# Special registers: ps

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40005ea4, @function
fn_40005ea4:
	entry	a1, 64                  # 40005ea4
	rsil	a2, 15                  # 40005ea7
	s32i.n	a2, a1, 24              # 40005eaa
	l32i.n	a4, a1, 24              # 40005eac
	s32i.n	a4, a1, 0               # 40005eae
	l32i.n	a3, a1, 0               # 40005eb0
	s32i.n	a3, a1, 4               # 40005eb2
	l32i.n	a8, a1, 4               # 40005eb4
	s32i.n	a8, a1, 8               # 40005eb6
	l32r	a7, lit_3ffe1e60        # 40005eb8  = 0x3ffe4438
	l32i.n	a7, a7, 0               # 40005ebb
	s32i.n	a7, a1, 12              # 40005ebd
	movi.n	a6, 0                   # 40005ebf
	l32i.n	a5, a1, 12              # 40005ec1
	beq	a5, a6, .L40005ed2      # 40005ec3
	l32r	a10, lit_3ffe1e60       # 40005ec6  = 0x3ffe4438
	l32r	a9, lit_3ffe1e60        # 40005ec9  = 0x3ffe4438
	l32i.n	a9, a9, 0               # 40005ecc
	addi.n	a9, a9, -1              # 40005ece
	s32i.n	a9, a10, 0              # 40005ed0
.L40005ed2:
	l32r	a12, lit_3ffe1e60       # 40005ed2  = 0x3ffe4438
	l32i.n	a12, a12, 4             # 40005ed5
	s32i.n	a12, a1, 16             # 40005ed7
	movi.n	a11, 0                  # 40005ed9
	l32i.n	a10, a1, 16             # 40005edb
	beq	a10, a11, .L40005eec    # 40005edd
	l32r	a14, lit_3ffe1e60       # 40005ee0  = 0x3ffe4438
	l32r	a13, lit_3ffe1e60       # 40005ee3  = 0x3ffe4438
	l32i.n	a13, a13, 4             # 40005ee6
	addi.n	a13, a13, -1            # 40005ee8
	s32i.n	a13, a14, 4             # 40005eea
.L40005eec:
	l32i.n	a15, a1, 8              # 40005eec
	s32i.n	a15, a1, 20             # 40005eee
	l32i.n	a14, a1, 20             # 40005ef0
	wsr.ps	a14                     # 40005ef2
	rsync                           # 40005ef5
	movi.n	a3, 0                   # 40005ef8
	l32i.n	a2, a1, 12              # 40005efa
	beq	a2, a3, .L40005f11      # 40005efc
	movi.n	a5, 0                   # 40005eff
	l32r	a4, lit_3ffe1e60        # 40005f01  = 0x3ffe4438
	l32i.n	a4, a4, 8               # 40005f04
	beq	a4, a5, .L40005f11      # 40005f06
	l32r	a8, lit_3ffe1e60        # 40005f09  = 0x3ffe4438
	l32i.n	a8, a8, 8               # 40005f0c
	callx8	a8                      # 40005f0e
.L40005f11:
	movi.n	a10, 0                  # 40005f11
	l32i.n	a9, a1, 16              # 40005f13
	beq	a9, a10, .L40005f2a     # 40005f15
	movi.n	a12, 0                  # 40005f18
	l32r	a11, lit_3ffe1e60       # 40005f1a  = 0x3ffe4438
	l32i.n	a11, a11, 12            # 40005f1d
	beq	a11, a12, .L40005f2a    # 40005f1f
	l32r	a8, lit_3ffe1e60        # 40005f22  = 0x3ffe4438
	l32i.n	a8, a8, 12              # 40005f25
	callx8	a8                      # 40005f27
.L40005f2a:
	retw.n                          # 40005f2a
	.size	fn_40005ea4, . - fn_40005ea4
