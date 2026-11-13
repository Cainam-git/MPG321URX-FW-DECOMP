# ldc_adim_hold_on_sudden_rise  (fn_400024e4): 0x400024e4-0x4000265c (firmware file offset 0x324e4-0x3265c), 159 instructions
# Name basis: descriptive - code only; state 0x3FFE3F38..40; result switches off ADIM smoothing
# Called from: ldc_run_adim_path
# Calls: timer_read_ticks
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe3f38, 0x0007a120, 0x3ffe3f3c, 0x000088b7, 0x3ffe3f40, 0x00000bb8
#
# ADIM path step (ldc_run_adim_path, enable = 1): watches the average of the merged channel values. When the previous
# average (0x3FFE3F40) was at most 199, and a channel lies more than 3000 away from it while the new average is
# higher, it sets the hold flag 0x3FFE3F3C and stores the time (tick counter at 0x3FFE5598 +24, via timer_read_ticks)
# in 0x3FFE3F38. While the flag is set, every channel's ADIM is set to percent until more than 34999 (0x88B7)
# ticks have passed, then the flag is cleared; the average is not updated during the hold. The stored time is also
# moved to now when more than 500000 (0x7A120) ticks have passed. The caller passes PercentADIM (settings +20)
# and uses the result to switch off the smoothing step (ldc_adim_smooth_toward_target) during the hold.
# Arguments: a2 = values (merged channel values), a3 = adim (32-bit words, may be written), a4 = percent,
# a5 = enable.
# Locals: a1+0 = i, a1+4 = now, a1+8 = sum, a1+12 = average, a1+16 = result, a1+20 = far.
# Returns: result, the hold flag (0 when enable is 0).

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_adim_hold_on_sudden_rise, @function
ldc_adim_hold_on_sudden_rise:           # fn_400024e4
	entry	a1, 80                  # 400024e4
	s32i.n	a2, a1, 32              # 400024e7
	s32i.n	a3, a1, 36              # 400024e9
	s32i.n	a4, a1, 40              # 400024eb
	s32i.n	a5, a1, 44              # 400024ed
	# i = 0; now = 0; sum = 0; average = 0
	movi.n	a12, 0                  # 400024ef
	s32i.n	a12, a1, 0              # 400024f1
	movi.n	a11, 0                  # 400024f3
	s32i.n	a11, a1, 4              # 400024f5
	movi.n	a10, 0                  # 400024f7
	s32i.n	a10, a1, 8              # 400024f9
	movi.n	a9, 0                   # 400024fb
	s32i.n	a9, a1, 12              # 400024fd
	# if (enable == 0) { result = 0; return result; }
	movi.n	a9, 0                   # 400024ff
	l32i.n	a8, a1, 44              # 40002501
	bne	a8, a9, .L4000250d      # 40002503
	movi.n	a13, 0                  # 40002506
	s32i.n	a13, a1, 16             # 40002508
	j	.L40002659              # 4000250a
.L4000250d:
	# now = timer_read_ticks()   (tick counter)
	call8	timer_read_ticks        # 4000250d
	s32i.n	a10, a1, 4              # 40002510
	# if (now - hold_start > 500000) hold_start = now
	l32r	a2, lit_3ffe1bb0        # 40002512  = 0x3ffe3f38
	l32i.n	a2, a2, 0               # 40002515
	l32i.n	a15, a1, 4              # 40002517
	sub	a15, a15, a2            # 40002519
	l32r	a14, lit_3ffe1bb4       # 4000251c  = 0x0007a120
	bgeu	a14, a15, .L40002529    # 4000251f
	l32r	a4, lit_3ffe1bb0        # 40002522  = 0x3ffe3f38
	l32i.n	a3, a1, 4               # 40002525
	s32i.n	a3, a4, 0               # 40002527
.L40002529:
	# if (hold_active == 1)
	l32r	a5, lit_3ffe1bb8        # 40002529  = 0x3ffe3f3c
	l32i.n	a5, a5, 0               # 4000252c
	bnei	a5, 1, .L40002577       # 4000252e
	# if (now - hold_start <= 34999)
	l32r	a8, lit_3ffe1bb0        # 40002531  = 0x3ffe3f38
	l32i.n	a8, a8, 0               # 40002534
	l32i.n	a7, a1, 4               # 40002536
	sub	a7, a7, a8              # 40002538
	l32r	a6, lit_3ffe1bbc        # 4000253b  = 0x000088b7
	bltu	a6, a7, .L4000256d      # 4000253e
	# for (i = 0; i < cfg->channel_count; i++) adim[i] = percent
	movi.n	a11, 0                  # 40002541
	s32i.n	a11, a1, 0              # 40002543
	l32r	a10, lit_3ffe1a98       # 40002545  = ldc_dimming_settings
	l32i.n	a10, a10, 0             # 40002548
	l32i.n	a9, a1, 0               # 4000254a
	bgeu	a9, a10, .L4000256a     # 4000254c
.L4000254f:
	l32i.n	a2, a1, 0               # 4000254f
	l32i.n	a3, a1, 36              # 40002551
	addx4	a2, a2, a3              # 40002553
	l32i.n	a15, a1, 40             # 40002556
	s32i.n	a15, a2, 0              # 40002558
	l32i.n	a14, a1, 0              # 4000255a
	addi.n	a14, a14, 1             # 4000255c
	s32i.n	a14, a1, 0              # 4000255e
	l32r	a13, lit_3ffe1a98       # 40002560  = ldc_dimming_settings
	l32i.n	a13, a13, 0             # 40002563
	l32i.n	a12, a1, 0              # 40002565
	bltu	a12, a13, .L4000254f    # 40002567
.L4000256a:
	j	.L40002574              # 4000256a
.L4000256d:
	# else hold_active = 0
	l32r	a5, lit_3ffe1bb8        # 4000256d  = 0x3ffe3f3c
	movi.n	a4, 0                   # 40002570
	s32i.n	a4, a5, 0               # 40002572
.L40002574:
	j	.L40002652              # 40002574
.L40002577:
	# for (i = 0; i < cfg->channel_count; i++) sum += values[i]
	movi.n	a8, 0                   # 40002577
	s32i.n	a8, a1, 0               # 40002579
	l32r	a7, lit_3ffe1a98        # 4000257b  = ldc_dimming_settings
	l32i.n	a7, a7, 0               # 4000257e
	l32i.n	a6, a1, 0               # 40002580
	bgeu	a6, a7, .L400025a4      # 40002582
.L40002585:
	l32i.n	a13, a1, 8              # 40002585
	l32i.n	a12, a1, 0              # 40002587
	l32i.n	a14, a1, 32             # 40002589
	addx4	a12, a12, a14           # 4000258b
	l32i.n	a12, a12, 0             # 4000258e
	add.n	a12, a12, a13           # 40002590
	s32i.n	a12, a1, 8              # 40002592
	l32i.n	a11, a1, 0              # 40002594
	addi.n	a11, a11, 1             # 40002596
	s32i.n	a11, a1, 0              # 40002598
	l32r	a10, lit_3ffe1a98       # 4000259a  = ldc_dimming_settings
	l32i.n	a10, a10, 0             # 4000259d
	l32i.n	a9, a1, 0               # 4000259f
	bltu	a9, a10, .L40002585     # 400025a1
.L400025a4:
	# average = sum / cfg->channel_count
	l32r	a4, lit_3ffe1a98        # 400025a4  = ldc_dimming_settings
	l32i.n	a4, a4, 0               # 400025a7
	l32i.n	a3, a1, 8               # 400025a9
	quou	a3, a3, a4              # 400025ab
	s32i.n	a3, a1, 12              # 400025ae
	# if (previous_average <= 199)
	l32r	a2, lit_3ffe1bc0        # 400025b0  = 0x3ffe3f40
	l32i.n	a2, a2, 0               # 400025b3
	movi	a15, 199                # 400025b5
	bgeu	a15, a2, .L400025be     # 400025b8
	j	.L4000264b              # 400025bb
.L400025be:
	# for (i = 0; i < cfg->channel_count; i++)
	movi.n	a7, 0                   # 400025be
	s32i.n	a7, a1, 0               # 400025c0
	l32r	a6, lit_3ffe1a98        # 400025c2  = ldc_dimming_settings
	l32i.n	a6, a6, 0               # 400025c5
	l32i.n	a5, a1, 0               # 400025c7
	bgeu	a5, a6, .L4000264b      # 400025c9
.L400025cc:
	# if (values[i] > previous_average) far = (values[i] - previous_average > 3000)
	l32i.n	a9, a1, 0               # 400025cc
	l32i.n	a10, a1, 32             # 400025ce
	addx4	a9, a9, a10             # 400025d0
	l32i.n	a9, a9, 0               # 400025d3
	l32r	a8, lit_3ffe1bc0        # 400025d5  = 0x3ffe3f40
	l32i.n	a8, a8, 0               # 400025d8
	bgeu	a8, a9, .L400025ff      # 400025da
	l32r	a11, lit_3ffe1bc4       # 400025dd  = 0x00000bb8
	l32r	a13, lit_3ffe1bc0       # 400025e0  = 0x3ffe3f40
	l32i.n	a13, a13, 0             # 400025e3
	l32i.n	a12, a1, 0              # 400025e5
	l32i.n	a14, a1, 32             # 400025e7
	addx4	a12, a12, a14           # 400025e9
	l32i.n	a12, a12, 0             # 400025ec
	sub	a12, a12, a13           # 400025ee
	movi.n	a13, 1                  # 400025f1
	s32i.n	a13, a1, 20             # 400025f3
	bltu	a11, a12, .L400025fc    # 400025f5
	movi.n	a14, 0                  # 400025f8
	s32i.n	a14, a1, 20             # 400025fa
.L400025fc:
	j	.L4000261e              # 400025fc
.L400025ff:
	# else far = (previous_average - values[i] > 3000)
	l32r	a15, lit_3ffe1bc4       # 400025ff  = 0x00000bb8
	l32i.n	a3, a1, 0               # 40002602
	l32i.n	a4, a1, 32              # 40002604
	addx4	a3, a3, a4              # 40002606
	l32i.n	a3, a3, 0               # 40002609
	l32r	a2, lit_3ffe1bc0        # 4000260b  = 0x3ffe3f40
	l32i.n	a2, a2, 0               # 4000260e
	sub	a2, a2, a3              # 40002610
	movi.n	a3, 1                   # 40002613
	s32i.n	a3, a1, 20              # 40002615
	bltu	a15, a2, .L4000261e     # 40002617
	movi.n	a5, 0                   # 4000261a
	s32i.n	a5, a1, 20              # 4000261c
.L4000261e:
	# if (far && average > previous_average) { hold_active = 1; hold_start = timer_read_ticks(); }
	l32i.n	a6, a1, 20              # 4000261e
	beqz.n	a6, .L4000263b          # 40002620
	l32i.n	a8, a1, 12              # 40002622
	l32r	a7, lit_3ffe1bc0        # 40002624  = 0x3ffe3f40
	l32i.n	a7, a7, 0               # 40002627
	bgeu	a7, a8, .L4000263b      # 40002629
	l32r	a9, lit_3ffe1bb8        # 4000262c  = 0x3ffe3f3c
	movi.n	a8, 1                   # 4000262f
	s32i.n	a8, a9, 0               # 40002631
	call8	timer_read_ticks        # 40002633
	l32r	a11, lit_3ffe1bb0       # 40002636  = 0x3ffe3f38
	s32i.n	a10, a11, 0             # 40002639
.L4000263b:
	# (i++, loop while i < channel_count)
	l32i.n	a14, a1, 0              # 4000263b
	addi.n	a14, a14, 1             # 4000263d
	s32i.n	a14, a1, 0              # 4000263f
	l32r	a13, lit_3ffe1a98       # 40002641  = ldc_dimming_settings
	l32i.n	a13, a13, 0             # 40002644
	l32i.n	a12, a1, 0              # 40002646
	bltu	a12, a13, .L400025cc    # 40002648
.L4000264b:
	# previous_average = average
	l32r	a2, lit_3ffe1bc0        # 4000264b  = 0x3ffe3f40
	l32i.n	a15, a1, 12             # 4000264e
	s32i.n	a15, a2, 0              # 40002650
.L40002652:
	# result = hold_active
	l32r	a3, lit_3ffe1bb8        # 40002652  = 0x3ffe3f3c
	l32i.n	a3, a3, 0               # 40002655
	s32i.n	a3, a1, 16              # 40002657
.L40002659:
	# return result
	l32i.n	a2, a1, 16              # 40002659
	retw.n                          # 4000265b
	.size	ldc_adim_hold_on_sudden_rise, . - ldc_adim_hold_on_sudden_rise
