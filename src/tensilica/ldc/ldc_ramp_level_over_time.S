# ldc_ramp_level_over_time  (fn_400020d0): 0x400020d0-0x400021cc (firmware file offset 0x320d0-0x321cc), 104 instructions
# Name basis: descriptive - code only; panel +0x150/+0x158, settings +60 (cmd 0x82); uncalled
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: timer_read_ticks
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe2bf0, 0x3ffe3f34, 0x000112a8, 0xe009104c
#
# Moves a level between min and max by a step that grows with the time since the start time in panel word +0x158:
# step = ((now - start) >> 8) * (max - min) / 70312 (0x112A8), with now = the tick counter at 0x3FFE5598 +24 read by
# timer_read_ticks. With panel +0x150 = 1 it steps down from level and keeps the result in 0x3FFE3F34; otherwise it steps
# up from the value kept in 0x3FFE3F34 (without storing the new one). When the step would pass min or max it sets
# dimming settings +60 to 1 and writes 0 (going down) or 1 (going up) to mailbox word 0xE009104C (portal 2 +0x4C).
# While settings +60 is 1 it only stores or returns the kept value. Command 0x82 with value 0 (ldc_cmd_set_peaking)
# clears panel +0x150 and sets settings +60 to 1. Nothing calls this routine and its address is not stored.
# Arguments: a2 = level, a3 = max, a4 = min.
# Locals: a1+0 = now, a1+4 = elapsed, a1+8 = step, a1+12 = out, a1+16 = result.
# Returns: result, the level to use.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_ramp_level_over_time, @function
ldc_ramp_level_over_time:               # fn_400020d0
	entry	a1, 80                  # 400020d0
	s32i.n	a2, a1, 32              # 400020d3
	s32i.n	a3, a1, 36              # 400020d5
	s32i.n	a4, a1, 40              # 400020d7
	# now = 0; elapsed = 0; step = 0; out = level
	movi.n	a11, 0                  # 400020d9
	s32i.n	a11, a1, 0              # 400020db
	movi.n	a10, 0                  # 400020dd
	s32i.n	a10, a1, 4              # 400020df
	movi.n	a9, 0                   # 400020e1
	s32i.n	a9, a1, 8               # 400020e3
	l32i.n	a8, a1, 32              # 400020e5
	s32i.n	a8, a1, 12              # 400020e7
	# if (cfg[+60] == 1)
	l32r	a7, lit_3ffe1a98        # 400020e9  = ldc_dimming_settings
	l32i.n	a7, a7, 60              # 400020ec
	bnei	a7, 1, .L40002112       # 400020ee
	# if (panel[+0x150] == 1) { result = kept_level; return result; }
	l32r	a12, lit_3ffe1a80       # 400020f1  = 0x3ffe2bf0
	l32i	a12, a12, 0x150         # 400020f4
	bnei	a12, 1, .L40002104      # 400020f7
	l32r	a13, lit_3ffe1ba4       # 400020fa  = 0x3ffe3f34
	l32i.n	a13, a13, 0             # 400020fd
	s32i.n	a13, a1, 16             # 400020ff
	j	.L400021c9              # 40002101
.L40002104:
	# else { kept_level = out; result = out; return result; }
	l32r	a2, lit_3ffe1ba4        # 40002104  = 0x3ffe3f34
	l32i.n	a15, a1, 12             # 40002107
	s32i.n	a15, a2, 0              # 40002109
	l32i.n	a14, a1, 12             # 4000210b
	s32i.n	a14, a1, 16             # 4000210d
	j	.L400021c9              # 4000210f
.L40002112:
	# now = timer_read_ticks()   (tick counter)
	call8	timer_read_ticks        # 40002112
	s32i.n	a10, a1, 0              # 40002115
	# if (now >= panel[+0x158]) elapsed = now - panel[+0x158]
	l32r	a4, lit_3ffe1a80        # 40002117  = 0x3ffe2bf0
	l32i	a4, a4, 0x158           # 4000211a
	l32i.n	a3, a1, 0               # 4000211d
	bltu	a3, a4, .L40002132      # 4000211f
	l32r	a6, lit_3ffe1a80        # 40002122  = 0x3ffe2bf0
	l32i	a6, a6, 0x158           # 40002125
	l32i.n	a5, a1, 0               # 40002128
	sub	a5, a5, a6              # 4000212a
	s32i.n	a5, a1, 4               # 4000212d
	j	.L4000213f              # 4000212f
.L40002132:
	# else elapsed = now - panel[+0x158]
	l32r	a8, lit_3ffe1a80        # 40002132  = 0x3ffe2bf0
	l32i	a8, a8, 0x158           # 40002135
	l32i.n	a7, a1, 0               # 40002138
	sub	a7, a7, a8              # 4000213a
	s32i.n	a7, a1, 4               # 4000213d
.L4000213f:
	# step = (elapsed >> 8) * (max - min) / 70312
	l32r	a11, lit_3ffe1ba8       # 4000213f  = 0x000112a8
	l32i.n	a13, a1, 40             # 40002142
	l32i.n	a12, a1, 36             # 40002144
	sub	a12, a12, a13           # 40002146
	l32i.n	a10, a1, 4              # 40002149
	srli	a10, a10, 8             # 4000214b
	mull	a10, a10, a12           # 4000214e
	quou	a10, a10, a11           # 40002151
	s32i.n	a10, a1, 8              # 40002154
	# if (panel[+0x150] == 1)
	l32r	a9, lit_3ffe1a80        # 40002156  = 0x3ffe2bf0
	l32i	a9, a9, 0x150           # 40002159
	bnei	a9, 1, .L40002198       # 4000215c
	# if (min + step <= level) { out = level - step; kept_level = out; }
	l32i.n	a2, a1, 8               # 4000215f
	l32i.n	a15, a1, 40             # 40002161
	add.n	a15, a15, a2            # 40002163
	l32i.n	a14, a1, 32             # 40002165
	bltu	a14, a15, .L4000217d    # 40002167
	l32i.n	a5, a1, 8               # 4000216a
	l32i.n	a4, a1, 32              # 4000216c
	sub	a4, a4, a5              # 4000216e
	s32i.n	a4, a1, 12              # 40002171
	l32r	a3, lit_3ffe1ba4        # 40002173  = 0x3ffe3f34
	l32i.n	a2, a1, 12              # 40002176
	s32i.n	a2, a3, 0               # 40002178
	j	.L40002195              # 4000217a
.L4000217d:
	# else { out = kept_level; cfg[+60] = 1; mailbox[0x4C] = 0; }
	l32r	a9, lit_3ffe1ba4        # 4000217d  = 0x3ffe3f34
	l32i.n	a9, a9, 0               # 40002180
	s32i.n	a9, a1, 12              # 40002182
	l32r	a8, lit_3ffe1a98        # 40002184  = ldc_dimming_settings
	movi.n	a7, 1                   # 40002187
	s32i.n	a7, a8, 60              # 40002189
	l32r	a6, lit_3ffe1b14        # 4000218b  = 0xe009104c
	movi.n	a5, 0                   # 4000218e
	memw                            # 40002190
	s32i.n	a5, a6, 0               # 40002193
.L40002195:
	j	.L400021c5              # 40002195
.L40002198:
	# else if (kept_level + step <= max) out = kept_level + step
	l32i.n	a12, a1, 8              # 40002198
	l32r	a11, lit_3ffe1ba4       # 4000219a  = 0x3ffe3f34
	l32i.n	a11, a11, 0             # 4000219d
	add.n	a11, a11, a12           # 4000219f
	l32i.n	a10, a1, 36             # 400021a1
	bltu	a10, a11, .L400021b4    # 400021a3
	l32i.n	a13, a1, 8              # 400021a6
	l32r	a12, lit_3ffe1ba4       # 400021a8  = 0x3ffe3f34
	l32i.n	a12, a12, 0             # 400021ab
	add.n	a12, a12, a13           # 400021ad
	s32i.n	a12, a1, 12             # 400021af
	j	.L400021c5              # 400021b1
.L400021b4:
	# else { cfg[+60] = 1; mailbox[0x4C] = 1; }
	l32r	a2, lit_3ffe1a98        # 400021b4  = ldc_dimming_settings
	movi.n	a15, 1                  # 400021b7
	s32i.n	a15, a2, 60             # 400021b9
	l32r	a14, lit_3ffe1b14       # 400021bb  = 0xe009104c
	movi.n	a13, 1                  # 400021be
	memw                            # 400021c0
	s32i.n	a13, a14, 0             # 400021c3
.L400021c5:
	# result = out
	l32i.n	a3, a1, 12              # 400021c5
	s32i.n	a3, a1, 16              # 400021c7
.L400021c9:
	# return result
	l32i.n	a2, a1, 16              # 400021c9
	retw.n                          # 400021cb
	.size	ldc_ramp_level_over_time, . - ldc_ramp_level_over_time
