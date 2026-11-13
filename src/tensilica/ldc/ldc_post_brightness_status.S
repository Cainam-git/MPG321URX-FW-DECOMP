# ldc_post_brightness_status  (fn_400011e4): 0x400011e4-0x40001343 (firmware file offset 0x311e4-0x31343), 145 instructions
# Name basis: derived - writes 0xE009104C, read by ldc_get_reply_byte0..2 / ldc_is_reply_byte_set on the
#   main processor
# Called from: ldc_cmd_set_ldc_mode, ldc_cmd_set_user_pdim, ldc_cmd_set_user_adim, ldc_cmd_set_peaking,
#              ldc_cmd_set_adim_bright_percent, ldc_run_frame_pass
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe3f30, 0x3ffe3eb0, 0x3ffe3ef0, 0x00000fff, 0x3ffe2bf0, 0xe009104c
#
# Computes the average LED PDIM and LED ADIM over all channels as percentages and posts them in mailbox word
# 0xE009104C (portal 2 +0x4C, read by ldc_get_reply_byte0..2 and ldc_is_reply_byte_set on the main processor):
# bits 24..31 ADIM percent, bits 16..23 PDIM percent, bits 8..15 their product / 100, bit 0 set when LED_Mode
# is 4 or more. With force 0 it posts only on every 61st call (counter at 0x3FFE3F30).
# a2 = force: 0 = count calls and post every 61st; other = post now
# Locals: a1+0 = total_pct, a1+4 = pdim_pct, a1+8 = adim_pct, a1+12 = ch, a1+16 = pdim_sum, a1+20 = adim_sum,
#   a1+24 = pdim_avg, a1+28 = adim_avg, a1+32 = word.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_post_brightness_status, @function
ldc_post_brightness_status:             # fn_400011e4
	entry	a1, 96                  # 400011e4
	s32i.n	a2, a1, 48              # 400011e7
	# total_pct = pdim_pct = adim_pct = ch = pdim_sum = adim_sum = pdim_avg = adim_avg = 0
	movi.n	a12, 0                  # 400011e9
	s32i.n	a12, a1, 0              # 400011eb
	movi.n	a11, 0                  # 400011ed
	s32i.n	a11, a1, 4              # 400011ef
	movi.n	a10, 0                  # 400011f1
	s32i.n	a10, a1, 8              # 400011f3
	movi.n	a9, 0                   # 400011f5
	s32i.n	a9, a1, 12              # 400011f7
	movi.n	a8, 0                   # 400011f9
	s32i.n	a8, a1, 16              # 400011fb
	movi.n	a7, 0                   # 400011fd
	s32i.n	a7, a1, 20              # 400011ff
	movi.n	a6, 0                   # 40001201
	s32i.n	a6, a1, 24              # 40001203
	movi.n	a5, 0                   # 40001205
	s32i.n	a5, a1, 28              # 40001207
	# if (force == 0)
	movi.n	a5, 0                   # 40001209
	l32i.n	a4, a1, 48              # 4000120b
	bne	a4, a5, .L40001230      # 4000120d
	#     if (post_counter <= 59) { post_counter++; return; }
	l32r	a14, lit_3ffe1b10       # 40001210  = 0x3ffe3f30
	l32i.n	a14, a14, 0             # 40001213
	movi.n	a13, 59                 # 40001215
	bltu	a13, a14, .L40001229    # 40001217
	l32r	a2, lit_3ffe1b10        # 4000121a  = 0x3ffe3f30
	l32r	a15, lit_3ffe1b10       # 4000121d  = 0x3ffe3f30
	l32i.n	a15, a15, 0             # 40001220
	addi.n	a15, a15, 1             # 40001222
	s32i.n	a15, a2, 0              # 40001224
	j	.L40001342              # 40001226
.L40001229:
	#     post_counter = 0
	l32r	a3, lit_3ffe1b10        # 40001229  = 0x3ffe3f30
	movi.n	a2, 0                   # 4000122c
	s32i.n	a2, a3, 0               # 4000122e
.L40001230:
	# for (ch = 0; ch < channel_count; ch++)
	movi.n	a6, 0                   # 40001230
	s32i.n	a6, a1, 12              # 40001232
	l32r	a5, lit_3ffe1a98        # 40001234  = ldc_dimming_settings
	l32i.n	a5, a5, 0               # 40001237
	l32i.n	a4, a1, 12              # 40001239
	bgeu	a4, a5, .L40001270      # 4000123b
.L4000123e:
	# pdim_sum += led_pdim[ch]; adim_sum += led_adim[ch]
	l32i.n	a14, a1, 16             # 4000123e
	l32i.n	a13, a1, 12             # 40001240
	l32r	a15, lit_3ffe1ac0       # 40001242  = 0x3ffe3eb0
	addx2	a13, a13, a15           # 40001245
	l16ui	a13, a13, 0             # 40001248
	add.n	a13, a13, a14           # 4000124b
	s32i.n	a13, a1, 16             # 4000124d
	l32i.n	a11, a1, 20             # 4000124f
	l32i.n	a10, a1, 12             # 40001251
	l32r	a12, lit_3ffe1ac4       # 40001253  = 0x3ffe3ef0
	addx2	a10, a10, a12           # 40001256
	l16ui	a10, a10, 0             # 40001259
	add.n	a10, a10, a11           # 4000125c
	s32i.n	a10, a1, 20             # 4000125e
	l32i.n	a9, a1, 12              # 40001260
	addi.n	a9, a9, 1               # 40001262
	s32i.n	a9, a1, 12              # 40001264
	l32r	a8, lit_3ffe1a98        # 40001266  = ldc_dimming_settings
	l32i.n	a8, a8, 0               # 40001269
	l32i.n	a7, a1, 12              # 4000126b
	bltu	a7, a8, .L4000123e      # 4000126d
.L40001270:
	# pdim_avg = pdim_sum / channel_count; adim_avg = adim_sum / channel_count
	l32r	a6, lit_3ffe1a98        # 40001270  = ldc_dimming_settings
	l32i.n	a6, a6, 0               # 40001273
	l32i.n	a5, a1, 16              # 40001275
	quou	a5, a5, a6              # 40001277
	s32i.n	a5, a1, 24              # 4000127a
	l32r	a4, lit_3ffe1a98        # 4000127c  = ldc_dimming_settings
	l32i.n	a4, a4, 0               # 4000127f
	l32i.n	a3, a1, 20              # 40001281
	quou	a3, a3, a4              # 40001283
	s32i.n	a3, a1, 28              # 40001286
	# if (adim_avg > cfg.adim_min)
	#     adim_pct = ((adim_avg - cfg.adim_min) * 1000 / (cfg.adim_max - cfg.adim_min) + 5) / 10
	l32i.n	a3, a1, 28              # 40001288
	l32r	a2, lit_3ffe1a98        # 4000128a  = ldc_dimming_settings
	l32i.n	a2, a2, 8               # 4000128d
	bgeu	a2, a3, .L400012be      # 4000128f
	movi.n	a8, 10                  # 40001292
	l32r	a10, lit_3ffe1a98       # 40001294  = ldc_dimming_settings
	l32i.n	a10, a10, 8             # 40001297
	l32r	a9, lit_3ffe1a98        # 40001299  = ldc_dimming_settings
	l32i.n	a9, a9, 12              # 4000129c
	sub	a9, a9, a10             # 4000129e
	movi	a10, 0x3e8              # 400012a1
	l32r	a11, lit_3ffe1a98       # 400012a4  = ldc_dimming_settings
	l32i.n	a11, a11, 8             # 400012a7
	l32i.n	a7, a1, 28              # 400012a9
	sub	a7, a7, a11             # 400012ab
	mull	a7, a7, a10             # 400012ae
	quou	a7, a7, a9              # 400012b1
	addi.n	a7, a7, 5               # 400012b4
	quou	a7, a7, a8              # 400012b6
	s32i.n	a7, a1, 8               # 400012b9
	j	.L400012c2              # 400012bb
.L400012be:
	# else adim_pct = 0
	movi.n	a11, 0                  # 400012be
	s32i.n	a11, a1, 8              # 400012c0
.L400012c2:
	# if (pdim_avg > 0) pdim_pct = (pdim_avg * 1000 / 0xFFF + 5) / 10
	l32i.n	a13, a1, 24             # 400012c2
	movi.n	a12, 0                  # 400012c4
	bgeu	a12, a13, .L400012e3    # 400012c6
	movi.n	a15, 10                 # 400012c9
	l32r	a2, lit_3ffe1abc        # 400012cb  = 0x00000fff
	movi	a3, 0x3e8               # 400012ce
	l32i.n	a14, a1, 24             # 400012d1
	mull	a14, a14, a3            # 400012d3
	quou	a14, a14, a2            # 400012d6
	addi.n	a14, a14, 5             # 400012d9
	quou	a14, a14, a15           # 400012db
	s32i.n	a14, a1, 4              # 400012de
	j	.L400012e7              # 400012e0
.L400012e3:
	# else pdim_pct = 0
	movi.n	a4, 0                   # 400012e3
	s32i.n	a4, a1, 4               # 400012e5
.L400012e7:
	# total_pct = (pdim_pct * adim_pct + 50) / 100
	movi	a7, 100                 # 400012e7
	l32i.n	a8, a1, 8               # 400012ea
	l32i.n	a6, a1, 4               # 400012ec
	mull	a6, a6, a8              # 400012ee
	addi	a6, a6, 50              # 400012f1
	quou	a6, a6, a7              # 400012f4
	s32i.n	a6, a1, 0               # 400012f7
	# if (panel.led_mode >= 4) word = adim_pct << 24 | pdim_pct << 16 | total_pct << 8 | 1
	l32r	a5, lit_3ffe1a80        # 400012f9  = 0x3ffe2bf0
	l32i	a5, a5, 0x140           # 400012fc
	bltui	a5, 4, .L40001321       # 400012ff
	movi.n	a10, 1                  # 40001302
	l32i.n	a11, a1, 0              # 40001304
	slli	a11, a11, 8             # 40001306
	l32i.n	a12, a1, 8              # 40001309
	slli	a12, a12, 24            # 4000130b
	l32i.n	a9, a1, 4               # 4000130e
	slli	a9, a9, 16              # 40001310
	or	a9, a9, a12             # 40001313
	or	a9, a9, a11             # 40001316
	or	a9, a9, a10             # 40001319
	s32i.n	a9, a1, 32              # 4000131c
	j	.L40001338              # 4000131e
.L40001321:
	# else word = adim_pct << 24 | pdim_pct << 16 | total_pct << 8
	l32i.n	a13, a1, 0              # 40001321
	slli	a13, a13, 8             # 40001323
	l32i.n	a14, a1, 8              # 40001326
	slli	a14, a14, 24            # 40001328
	l32i.n	a12, a1, 4              # 4000132b
	slli	a12, a12, 16            # 4000132d
	or	a12, a12, a14           # 40001330
	or	a12, a12, a13           # 40001333
	s32i.n	a12, a1, 32             # 40001336
.L40001338:
	# mailbox[0x4C] = word   (0xE009104C)
	l32r	a15, lit_3ffe1b14       # 40001338  = 0xe009104c
	memw                            # 4000133b
	l32i.n	a14, a1, 32             # 4000133e
	s32i.n	a14, a15, 0             # 40001340
.L40001342:
	retw.n                          # 40001342
	.size	ldc_post_brightness_status, . - ldc_post_brightness_status
