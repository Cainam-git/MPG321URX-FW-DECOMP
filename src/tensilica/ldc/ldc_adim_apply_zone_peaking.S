# ldc_adim_apply_zone_peaking  (fn_40002418): 0x40002418-0x400024e2 (firmware file offset 0x32418-0x324e2), 87 instructions
# Name basis: derived - settings +68 = ZonePeakingPercent (printed name in ldc_print_debug_dump)
# Called from: ldc_run_adim_path
# Addresses loaded: ldc_dimming_settings
#
# ADIM path step (ldc_run_adim_path): counts the channels whose ADIM value is above 0 (active), then raises every
# channel by adim * ZonePeakingPercent (dimming settings +68) * (channel_count - active) / (channel_count - 1) / 255,
# so the fewer channels are lit, the larger the boost. It then works out the value clamped to min..max but keeps it
# only in a local: the array is not clamped. The caller passes ADIM_Max (settings +12) and ADIM_Min (settings +8).
# Arguments: a2 = adim (32-bit words, changed), a3 = max, a4 = min.
# Locals: a1+0 = i, a1+4 = active, a1+8 = clamped (not used afterwards).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_adim_apply_zone_peaking, @function
ldc_adim_apply_zone_peaking:            # fn_40002418
	entry	a1, 64                  # 40002418
	s32i.n	a2, a1, 16              # 4000241b
	s32i.n	a3, a1, 20              # 4000241d
	s32i.n	a4, a1, 24              # 4000241f
	# i = 0; active = 0
	movi.n	a11, 0                  # 40002421
	s32i.n	a11, a1, 0              # 40002423
	movi.n	a10, 0                  # 40002425
	s32i.n	a10, a1, 4              # 40002427
	# for (i = 0; i < cfg->channel_count; i++) if (adim[i] > 0) active++
	movi.n	a9, 0                   # 40002429
	s32i.n	a9, a1, 0               # 4000242b
	l32r	a8, lit_3ffe1a98        # 4000242d  = ldc_dimming_settings
	l32i.n	a8, a8, 0               # 40002430
	l32i.n	a7, a1, 0               # 40002432
	bgeu	a7, a8, .L4000245b      # 40002434
.L40002437:
	l32i.n	a13, a1, 0              # 40002437
	l32i.n	a14, a1, 16             # 40002439
	addx4	a13, a13, a14           # 4000243b
	l32i.n	a13, a13, 0             # 4000243e
	movi.n	a12, 0                  # 40002440
	bgeu	a12, a13, .L4000244b    # 40002442
	l32i.n	a15, a1, 4              # 40002445
	addi.n	a15, a15, 1             # 40002447
	s32i.n	a15, a1, 4              # 40002449
.L4000244b:
	l32i.n	a4, a1, 0               # 4000244b
	addi.n	a4, a4, 1               # 4000244d
	s32i.n	a4, a1, 0               # 4000244f
	l32r	a3, lit_3ffe1a98        # 40002451  = ldc_dimming_settings
	l32i.n	a3, a3, 0               # 40002454
	l32i.n	a2, a1, 0               # 40002456
	bltu	a2, a3, .L40002437      # 40002458
.L4000245b:
	# for (i = 0; i < cfg->channel_count; i++)
	movi.n	a7, 0                   # 4000245b
	s32i.n	a7, a1, 0               # 4000245d
	l32r	a6, lit_3ffe1a98        # 4000245f  = ldc_dimming_settings
	l32i.n	a6, a6, 0               # 40002462
	l32i.n	a5, a1, 0               # 40002464
	bgeu	a5, a6, .L400024e1      # 40002466
.L40002469:
	# adim[i] += adim[i] * cfg->ZonePeakingPercent * (channel_count - active) / (channel_count - 1) / 255
	l32i.n	a12, a1, 0              # 40002469
	l32i.n	a13, a1, 16             # 4000246b
	addx4	a12, a12, a13           # 4000246d
	movi	a14, 255                # 40002470
	l32r	a15, lit_3ffe1a98       # 40002473  = ldc_dimming_settings
	l32i.n	a15, a15, 0             # 40002476
	addi.n	a15, a15, -1            # 40002478
	l32i.n	a3, a1, 4               # 4000247a
	l32r	a2, lit_3ffe1a98        # 4000247c  = ldc_dimming_settings
	l32i.n	a2, a2, 0               # 4000247f
	sub	a2, a2, a3              # 40002481
	l32r	a3, lit_3ffe1a98        # 40002484  = ldc_dimming_settings
	l32i	a3, a3, 68              # 40002487
	l32i.n	a13, a1, 0              # 4000248a
	l32i.n	a4, a1, 16              # 4000248c
	addx4	a13, a13, a4            # 4000248e
	l32i.n	a13, a13, 0             # 40002491
	mull	a13, a13, a3            # 40002493
	mull	a13, a13, a2            # 40002496
	quou	a13, a13, a15           # 40002499
	quou	a13, a13, a14           # 4000249c
	l32i.n	a11, a1, 0              # 4000249f
	l32i.n	a14, a1, 16             # 400024a1
	addx4	a11, a11, a14           # 400024a3
	l32i.n	a11, a11, 0             # 400024a6
	add.n	a11, a11, a13           # 400024a8
	s32i.n	a11, a12, 0             # 400024aa
	# clamped = (adim[i] <= max) ? max(adim[i], min) : max   (result not stored back)
	l32i.n	a9, a1, 0               # 400024ac
	l32i.n	a10, a1, 16             # 400024ae
	addx4	a9, a9, a10             # 400024b0
	l32i.n	a9, a9, 0               # 400024b3
	l32i.n	a8, a1, 20              # 400024b5
	bltu	a8, a9, .L400024cd      # 400024b7
	l32i.n	a15, a1, 24             # 400024ba
	l32i.n	a14, a1, 0              # 400024bc
	l32i.n	a2, a1, 16              # 400024be
	addx4	a14, a14, a2            # 400024c0
	l32i.n	a14, a14, 0             # 400024c3
	maxu	a14, a14, a15           # 400024c5
	s32i.n	a14, a1, 8              # 400024c8
	j	.L400024d1              # 400024ca
.L400024cd:
	l32i.n	a2, a1, 20              # 400024cd
	s32i.n	a2, a1, 8               # 400024cf
.L400024d1:
	# (i++, loop while i < channel_count)
	l32i.n	a5, a1, 0               # 400024d1
	addi.n	a5, a5, 1               # 400024d3
	s32i.n	a5, a1, 0               # 400024d5
	l32r	a4, lit_3ffe1a98        # 400024d7  = ldc_dimming_settings
	l32i.n	a4, a4, 0               # 400024da
	l32i.n	a3, a1, 0               # 400024dc
	bltu	a3, a4, .L40002469      # 400024de
.L400024e1:
	retw.n                          # 400024e1
	.size	ldc_adim_apply_zone_peaking, . - ldc_adim_apply_zone_peaking
