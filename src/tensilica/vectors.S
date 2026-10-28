# vectors: 0x40000000-0x400003ff (firmware file offset 0x30000-0x303ff)
# The reset code writes 0x40000000 (vec_base) to VECBASE. Each vector slot is 0x40 bytes and is
# placed with .org; the bytes between the instructions are zero. Slot names: the window vectors
# are at fixed offsets in the Xtensa ISA, the others follow the usual Xtensa LX layout (a core
# configuration choice); the note after each name says what the slot's instructions do.
# fn_40000010 is entered through the exception-cause table at ro_3ffe19fc (entry 5); it is placed
# in the free space of the window overflow 4 and underflow 4 slots.

# ---- 0x40000000  window overflow 4: s32e/rfwo
vec_base:
	s32e	a0, a5, -16             # 40000000
	s32e	a1, a5, -12             # 40000003
	s32e	a2, a5, -8              # 40000006
	s32e	a3, a5, -4              # 40000009
	rfwo                            # 4000000c
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x40000010
fn_40000010:
	l32i.n	a2, a1, 16              # 40000010
	l32i.n	a3, a1, 20              # 40000012
	l32i.n	a4, a1, 24              # 40000014
	addmi	a1, a1, 0x100           # 40000016
	wsr.excsave1	a0              # 40000019
	rsr.windowbase	a0              # 4000001c
	rotw	-1                      # 4000001f
	rsr.ps	a2                      # 40000022
	extui	a3, a2, 8, 4            # 40000025
	xor	a3, a3, a4              # 40000028
	j	.L40000050              # 4000002b

# ---- 0x40000040  window underflow 4: l32e/rfwu
	.org	0x040, 0
vec_40000040:
	l32e	a0, a5, -16             # 40000040
	l32e	a1, a5, -12             # 40000043
	l32e	a2, a5, -8              # 40000046
	l32e	a3, a5, -4              # 40000049
	rfwu                            # 4000004c
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x40000050
.L40000050:
	rsr.excsave1	a4              # 40000050
	slli	a3, a3, 8               # 40000053
	xor	a2, a2, a3              # 40000056
	wsr.ps	a2                      # 40000059
	rsync                           # 4000005c
	bbci	a4, 31, vec_40000040    # 4000005f
	rotw	-1                      # 40000062
	bbci	a8, 30, vec_400000c0    # 40000065
	rotw	-1                      # 40000068
	j	vec_40000140            # 4000006b

# ---- 0x40000080  window overflow 8: s32e/rfwo
	.org	0x080, 0
vec_40000080:
	s32e	a0, a9, -16             # 40000080
	l32e	a0, a1, -12             # 40000083
	s32e	a1, a9, -12             # 40000086
	s32e	a2, a9, -8              # 40000089
	s32e	a3, a9, -4              # 4000008c
	s32e	a4, a0, -32             # 4000008f
	s32e	a5, a0, -28             # 40000092
	s32e	a6, a0, -24             # 40000095
	s32e	a7, a0, -20             # 40000098
	rfwo                            # 4000009b

# ---- 0x400000c0  window underflow 8: l32e/rfwu
	.org	0x0c0, 0
vec_400000c0:
	l32e	a0, a9, -16             # 400000c0
	l32e	a1, a9, -12             # 400000c3
	l32e	a2, a9, -8              # 400000c6
	l32e	a7, a1, -12             # 400000c9
	l32e	a3, a9, -4              # 400000cc
	l32e	a4, a7, -32             # 400000cf
	l32e	a5, a7, -28             # 400000d2
	l32e	a6, a7, -24             # 400000d5
	l32e	a7, a7, -20             # 400000d8
	rfwu                            # 400000db

# ---- 0x40000100  window overflow 12: s32e/rfwo
	.org	0x100, 0
vec_40000100:
	s32e	a0, a13, -16            # 40000100
	l32e	a0, a1, -12             # 40000103
	s32e	a1, a13, -12            # 40000106
	s32e	a2, a13, -8             # 40000109
	s32e	a3, a13, -4             # 4000010c
	s32e	a4, a0, -48             # 4000010f
	s32e	a5, a0, -44             # 40000112
	s32e	a6, a0, -40             # 40000115
	s32e	a7, a0, -36             # 40000118
	s32e	a8, a0, -32             # 4000011b
	s32e	a9, a0, -28             # 4000011e
	s32e	a10, a0, -24            # 40000121
	s32e	a11, a0, -20            # 40000124
	rfwo                            # 40000127

# ---- 0x40000140  window underflow 12: l32e/rfwu
	.org	0x140, 0
vec_40000140:
	l32e	a0, a13, -16            # 40000140
	l32e	a1, a13, -12            # 40000143
	l32e	a2, a13, -8             # 40000146
	l32e	a11, a1, -12            # 40000149
	l32e	a3, a13, -4             # 4000014c
	l32e	a4, a11, -48            # 4000014f
	l32e	a5, a11, -44            # 40000152
	l32e	a6, a11, -40            # 40000155
	l32e	a7, a11, -36            # 40000158
	l32e	a8, a11, -32            # 4000015b
	l32e	a9, a11, -28            # 4000015e
	l32e	a10, a11, -24           # 40000161
	l32e	a11, a11, -20           # 40000164
	rfwu                            # 40000167

# ---- 0x40000180  level-2 interrupt: break 1, 2, then a jump to itself
	.org	0x180, 0
vec_40000180:
	break	1, 2                    # 40000180
.L40000183:
	j	.L40000183              # 40000183

# ---- 0x400001c0  level-3 interrupt: jumps to the address in EXCSAVE3
	.org	0x1c0, 0
vec_400001c0:
	xsr.excsave3	a2              # 400001c0
	jx	a2                      # 400001c3

# ---- 0x40000200  level-4 interrupt: break 1, 2, then a jump to itself
	.org	0x200, 0
vec_40000200:
	break	1, 2                    # 40000200
.L40000203:
	j	.L40000203              # 40000203

# ---- 0x40000240  level-5 interrupt: jumps to the address in EXCSAVE5
	.org	0x240, 0
vec_40000240:
	xsr.excsave5	a2              # 40000240
	jx	a2                      # 40000243

# ---- 0x40000280  debug exception: a jump to itself
	.org	0x280, 0
vec_40000280:
	j	vec_40000280            # 40000280

# ---- 0x400002c0  NMI (level 7): rfi 7
	.org	0x2c0, 0
vec_400002c0:
	rfi	7                       # 400002c0

# ---- 0x40000300  kernel exception: break 1, 0, then a jump to itself
	.org	0x300, 0
vec_40000300:
	break	1, 0                    # 40000300
	j	vec_40000300            # 40000303
	.space	50, 0                   # 50 zero bytes, 0x40000306-0x40000337
lit_40000338:
	.word	ro_3ffe19fc             # 40000338

# ---- 0x40000340  user exception: jumps through a table indexed by EXCCAUSE
	.org	0x340, 0
vec_40000340:
	addmi	a1, a1, 0xffffff00      # 40000340
	s32i.n	a2, a1, 16              # 40000343
	s32i	a3, a1, 20              # 40000345
	rsr.exccause	a2              # 40000348
	l32r	a3, lit_40000338        # 4000034b  = ro_3ffe19fc
	bgeui	a2, 6, .L40000354       # 4000034e
	addx4	a3, a2, a3              # 40000351
.L40000354:
	l32i.n	a3, a3, 0               # 40000354
	s32i.n	a4, a1, 24              # 40000356
	jx	a3                      # 40000358

# ---- 0x40000380  offset 0x380: zero bytes only
	.org	0x380, 0

# ---- 0x400003c0  double exception: break 1, 4, then a jump to itself
	.org	0x3c0, 0
vec_400003c0:
	break	1, 4                    # 400003c0
	j	vec_400003c0            # 400003c3
	.org	0x400, 0
