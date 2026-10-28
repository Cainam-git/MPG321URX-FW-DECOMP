# fn_40003190: 0x40003190-0x40003556 (firmware file offset 0x33190-0x33556), 364 instructions
# Called from: fn_400035d0
# Calls: fn_400099bc
# Text loaded: "Input Duty:\n", "\t%04X ", "LDC_GainTable_ANV1: \n", "\t%04d, \t%04d \n",
#              "\t%04d, \t%04d \n\n", "LDC_GainTable_ANV2: \n", "LDC_GainTable_ANV3: \n",
#              "LED_Mode = \t%04X\n", "LDC_Mode = \t%04X\n", "usUserPDIM = \t%04X\n",
#              "usUserADIM = \t%04X\n", "ADIM_Max = \t%04X\n", "ADIM_Min = \t%04X\n",
#              "ADIM_BrighPercent = \t%04X\n", "PercentADIM = \t%04X\n", "LimitUpperBound = \t%04X\n",
#              "ZonePeakingPercent = \t%04X\n", "UserGlobalGain = \t%04X\n", "ApplyGlobalGain = \t%04X\n",
#              "GainFilterMode = \t%04X\n", "Input Duty:", "\n  %02d. ", "Merged Segment:", "LED ADIM:",
#              "LED PDIM:", "Pure Pattern: %d\n", "ApplyGlobalGain: 0x%04X\n"
# Addresses loaded: data_3ffe2760, ro_3ffe027c, ro_3ffe0288, data_3ffe23e0, data_3ffe23e8, data_3ffe23f0,
#                   data_3ffe23f8, data_3ffe2400, data_3ffe2420, data_3ffe2428, data_3ffe2430, data_3ffe2438,
#                   data_3ffe2440, data_3ffe2450, data_3ffe2458, data_3ffe2460, data_3ffe2468, data_3ffe2470,
#                   data_3ffe2390
# Other literal values: 0xe0091084, 0xe0091080, 0x3ffe4450, 0x3ffe4490, 0x3ffe2bf0, 0x3ffe3f44, 0x3ffe3ef0,
#                       0x3ffe3eb0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003190, @function
fn_40003190:
	entry	a1, 64                  # 40003190
	s32i.n	a2, a1, 16              # 40003193
	movi.n	a5, 0                   # 40003195
	s32i.n	a5, a1, 0               # 40003197
	movi.n	a5, 0                   # 40003199
	l32r	a4, lit_3ffe1bf4        # 4000319b  = 0xe0091084
	memw                            # 4000319e
	l32i.n	a4, a4, 0               # 400031a1
	bne	a4, a5, .L400031a9      # 400031a3
	j	.L40003555              # 400031a6
.L400031a9:
	movi	a7, 170                 # 400031a9
	l32r	a6, lit_3ffe1bf8        # 400031ac  = 0xe0091080
	memw                            # 400031af
	l32i.n	a6, a6, 0               # 400031b2
	extui	a6, a6, 0, 8            # 400031b4
	bne	a6, a7, .L40003214      # 400031b7
	l32r	a10, lit_3ffe1bfc       # 400031ba  = ro_3ffe026c "Input Duty:\n"
	call8	fn_400099bc             # 400031bd
	movi.n	a9, 0                   # 400031c0
	s32i.n	a9, a1, 0               # 400031c2
	l32r	a8, lit_3ffe1a88        # 400031c4  = data_3ffe2760
	l32i.n	a8, a8, 0               # 400031c7
	l32i.n	a7, a1, 0               # 400031c9
	bgeu	a7, a8, .L40003204      # 400031cb
.L400031ce:
	movi.n	a11, 0                  # 400031ce
	l32r	a12, lit_3ffe1a84       # 400031d0  = 0x3ffe4450
	l32i.n	a12, a12, 0             # 400031d3
	l32i.n	a10, a1, 0              # 400031d5
	remu	a10, a10, a12           # 400031d7
	bne	a10, a11, .L400031e3    # 400031da
	l32r	a10, lit_3ffe1c00       # 400031dd  = ro_3ffe027c
	call8	fn_400099bc             # 400031e0
.L400031e3:
	l32r	a10, lit_3ffe1c04       # 400031e3  = ro_3ffe0280 "\t%04X "
	l32i.n	a11, a1, 0              # 400031e6
	l32r	a12, lit_3ffe1b88       # 400031e8  = 0x3ffe4490
	addx2	a11, a11, a12           # 400031eb
	l16ui	a11, a11, 0             # 400031ee
	call8	fn_400099bc             # 400031f1
	l32i.n	a15, a1, 0              # 400031f4
	addi.n	a15, a15, 1             # 400031f6
	s32i.n	a15, a1, 0              # 400031f8
	l32r	a14, lit_3ffe1a88       # 400031fa  = data_3ffe2760
	l32i.n	a14, a14, 0             # 400031fd
	l32i.n	a13, a1, 0              # 400031ff
	bltu	a13, a14, .L400031ce    # 40003201
.L40003204:
	l32r	a10, lit_3ffe1c08       # 40003204  = ro_3ffe0288
	call8	fn_400099bc             # 40003207
	l32r	a3, lit_3ffe1bf8        # 4000320a  = 0xe0091080
	movi.n	a2, 0                   # 4000320d
	memw                            # 4000320f
	s32i.n	a2, a3, 0               # 40003212
.L40003214:
	movi	a5, 171                 # 40003214
	l32r	a4, lit_3ffe1bf8        # 40003217  = 0xe0091080
	memw                            # 4000321a
	l32i.n	a4, a4, 0               # 4000321d
	extui	a4, a4, 0, 8            # 4000321f
	beq	a4, a5, .L40003228      # 40003222
	j	.L40003334              # 40003225
.L40003228:
	l32r	a10, lit_3ffe1c0c       # 40003228  = ro_3ffe028c "LDC_GainTable_ANV1: \n"
	call8	fn_400099bc             # 4000322b
	l32r	a10, lit_3ffe1c10       # 4000322e  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1b20       # 40003231  = data_3ffe23e0
	l32i.n	a11, a11, 0             # 40003234
	l32r	a12, lit_3ffe1b20       # 40003236  = data_3ffe23e0
	l32i.n	a12, a12, 4             # 40003239
	call8	fn_400099bc             # 4000323b
	l32r	a10, lit_3ffe1c10       # 4000323e  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c14       # 40003241  = data_3ffe23e8
	l32i.n	a11, a11, 0             # 40003244
	l32r	a12, lit_3ffe1c14       # 40003246  = data_3ffe23e8
	l32i.n	a12, a12, 4             # 40003249
	call8	fn_400099bc             # 4000324b
	l32r	a10, lit_3ffe1c10       # 4000324e  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c18       # 40003251  = data_3ffe23f0
	l32i.n	a11, a11, 0             # 40003254
	l32r	a12, lit_3ffe1c18       # 40003256  = data_3ffe23f0
	l32i.n	a12, a12, 4             # 40003259
	call8	fn_400099bc             # 4000325b
	l32r	a10, lit_3ffe1c10       # 4000325e  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c1c       # 40003261  = data_3ffe23f8
	l32i.n	a11, a11, 0             # 40003264
	l32r	a12, lit_3ffe1c1c       # 40003266  = data_3ffe23f8
	l32i.n	a12, a12, 4             # 40003269
	call8	fn_400099bc             # 4000326b
	l32r	a10, lit_3ffe1c20       # 4000326e  = ro_3ffe02b4 "\t%04d, \t%04d \n\n"
	l32r	a11, lit_3ffe1c24       # 40003271  = data_3ffe2400
	l32i.n	a11, a11, 0             # 40003274
	l32r	a12, lit_3ffe1c24       # 40003276  = data_3ffe2400
	l32i.n	a12, a12, 4             # 40003279
	call8	fn_400099bc             # 4000327b
	l32r	a10, lit_3ffe1c28       # 4000327e  = ro_3ffe02c4 "LDC_GainTable_ANV2: \n"
	call8	fn_400099bc             # 40003281
	l32r	a10, lit_3ffe1c10       # 40003284  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1b60       # 40003287  = data_3ffe2420
	l32i.n	a11, a11, 0             # 4000328a
	l32r	a12, lit_3ffe1b60       # 4000328c  = data_3ffe2420
	l32i.n	a12, a12, 4             # 4000328f
	call8	fn_400099bc             # 40003291
	l32r	a10, lit_3ffe1c10       # 40003294  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c2c       # 40003297  = data_3ffe2428
	l32i.n	a11, a11, 0             # 4000329a
	l32r	a12, lit_3ffe1c2c       # 4000329c  = data_3ffe2428
	l32i.n	a12, a12, 4             # 4000329f
	call8	fn_400099bc             # 400032a1
	l32r	a10, lit_3ffe1c10       # 400032a4  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c30       # 400032a7  = data_3ffe2430
	l32i.n	a11, a11, 0             # 400032aa
	l32r	a12, lit_3ffe1c30       # 400032ac  = data_3ffe2430
	l32i.n	a12, a12, 4             # 400032af
	call8	fn_400099bc             # 400032b1
	l32r	a10, lit_3ffe1c10       # 400032b4  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c34       # 400032b7  = data_3ffe2438
	l32i.n	a11, a11, 0             # 400032ba
	l32r	a12, lit_3ffe1c34       # 400032bc  = data_3ffe2438
	l32i.n	a12, a12, 4             # 400032bf
	call8	fn_400099bc             # 400032c1
	l32r	a10, lit_3ffe1c20       # 400032c4  = ro_3ffe02b4 "\t%04d, \t%04d \n\n"
	l32r	a11, lit_3ffe1c38       # 400032c7  = data_3ffe2440
	l32i.n	a11, a11, 0             # 400032ca
	l32r	a12, lit_3ffe1c38       # 400032cc  = data_3ffe2440
	l32i.n	a12, a12, 4             # 400032cf
	call8	fn_400099bc             # 400032d1
	l32r	a10, lit_3ffe1c3c       # 400032d4  = ro_3ffe02dc "LDC_GainTable_ANV3: \n"
	call8	fn_400099bc             # 400032d7
	l32r	a10, lit_3ffe1c10       # 400032da  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1b64       # 400032dd  = data_3ffe2450
	l32i.n	a11, a11, 0             # 400032e0
	l32r	a12, lit_3ffe1b64       # 400032e2  = data_3ffe2450
	l32i.n	a12, a12, 4             # 400032e5
	call8	fn_400099bc             # 400032e7
	l32r	a10, lit_3ffe1c10       # 400032ea  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c40       # 400032ed  = data_3ffe2458
	l32i.n	a11, a11, 0             # 400032f0
	l32r	a12, lit_3ffe1c40       # 400032f2  = data_3ffe2458
	l32i.n	a12, a12, 4             # 400032f5
	call8	fn_400099bc             # 400032f7
	l32r	a10, lit_3ffe1c10       # 400032fa  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c44       # 400032fd  = data_3ffe2460
	l32i.n	a11, a11, 0             # 40003300
	l32r	a12, lit_3ffe1c44       # 40003302  = data_3ffe2460
	l32i.n	a12, a12, 4             # 40003305
	call8	fn_400099bc             # 40003307
	l32r	a10, lit_3ffe1c10       # 4000330a  = ro_3ffe02a4 "\t%04d, \t%04d \n"
	l32r	a11, lit_3ffe1c48       # 4000330d  = data_3ffe2468
	l32i.n	a11, a11, 0             # 40003310
	l32r	a12, lit_3ffe1c48       # 40003312  = data_3ffe2468
	l32i.n	a12, a12, 4             # 40003315
	call8	fn_400099bc             # 40003317
	l32r	a10, lit_3ffe1c20       # 4000331a  = ro_3ffe02b4 "\t%04d, \t%04d \n\n"
	l32r	a11, lit_3ffe1c4c       # 4000331d  = data_3ffe2470
	l32i.n	a11, a11, 0             # 40003320
	l32r	a12, lit_3ffe1c4c       # 40003322  = data_3ffe2470
	l32i.n	a12, a12, 4             # 40003325
	call8	fn_400099bc             # 40003327
	l32r	a13, lit_3ffe1bf8       # 4000332a  = 0xe0091080
	movi.n	a12, 0                  # 4000332d
	memw                            # 4000332f
	s32i.n	a12, a13, 0             # 40003332
.L40003334:
	movi	a15, 172                # 40003334
	l32r	a14, lit_3ffe1bf8       # 40003337  = 0xe0091080
	memw                            # 4000333a
	l32i.n	a14, a14, 0             # 4000333d
	extui	a14, a14, 0, 8          # 4000333f
	beq	a14, a15, .L40003348    # 40003342
	j	.L400033e6              # 40003345
.L40003348:
	l32r	a10, lit_3ffe1c50       # 40003348  = ro_3ffe02f4 "LED_Mode = \t%04X\n"
	l32r	a11, lit_3ffe1a80       # 4000334b  = 0x3ffe2bf0
	l32i	a11, a11, 0x140         # 4000334e
	call8	fn_400099bc             # 40003351
	l32r	a10, lit_3ffe1c54       # 40003354  = ro_3ffe0308 "LDC_Mode = \t%04X\n"
	l32r	a11, lit_3ffe1a80       # 40003357  = 0x3ffe2bf0
	l32i	a11, a11, 0x144         # 4000335a
	call8	fn_400099bc             # 4000335d
	l32r	a10, lit_3ffe1c58       # 40003360  = ro_3ffe031c "usUserPDIM = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 40003363  = data_3ffe2390
	l32i.n	a11, a11, 16            # 40003366
	call8	fn_400099bc             # 40003368
	l32r	a10, lit_3ffe1c5c       # 4000336b  = ro_3ffe0330 "usUserADIM = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 4000336e  = data_3ffe2390
	l32i.n	a11, a11, 24            # 40003371
	call8	fn_400099bc             # 40003373
	l32r	a10, lit_3ffe1c60       # 40003376  = ro_3ffe0344 "ADIM_Max = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 40003379  = data_3ffe2390
	l32i.n	a11, a11, 12            # 4000337c
	call8	fn_400099bc             # 4000337e
	l32r	a10, lit_3ffe1c64       # 40003381  = ro_3ffe0358 "ADIM_Min = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 40003384  = data_3ffe2390
	l32i.n	a11, a11, 8             # 40003387
	call8	fn_400099bc             # 40003389
	l32r	a10, lit_3ffe1c68       # 4000338c  = ro_3ffe036c "ADIM_BrighPercent = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 4000338f  = data_3ffe2390
	l32i.n	a11, a11, 28            # 40003392
	call8	fn_400099bc             # 40003394
	l32r	a10, lit_3ffe1c6c       # 40003397  = ro_3ffe0388 "PercentADIM = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 4000339a  = data_3ffe2390
	l32i.n	a11, a11, 20            # 4000339d
	call8	fn_400099bc             # 4000339f
	l32r	a10, lit_3ffe1c70       # 400033a2  = ro_3ffe03a0 "LimitUpperBound = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 400033a5  = data_3ffe2390
	l32i	a11, a11, 64            # 400033a8
	call8	fn_400099bc             # 400033ab
	l32r	a10, lit_3ffe1c74       # 400033ae  = ro_3ffe03bc "ZonePeakingPercent = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 400033b1  = data_3ffe2390
	l32i	a11, a11, 68            # 400033b4
	call8	fn_400099bc             # 400033b7
	l32r	a10, lit_3ffe1c78       # 400033ba  = ro_3ffe03d8 "UserGlobalGain = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 400033bd  = data_3ffe2390
	l32i.n	a11, a11, 32            # 400033c0
	call8	fn_400099bc             # 400033c2
	l32r	a10, lit_3ffe1c7c       # 400033c5  = ro_3ffe03f0 "ApplyGlobalGain = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 400033c8  = data_3ffe2390
	l32i	a11, a11, 72            # 400033cb
	call8	fn_400099bc             # 400033ce
	l32r	a10, lit_3ffe1c80       # 400033d1  = ro_3ffe040c "GainFilterMode = \t%04X\n"
	l32r	a11, lit_3ffe1a98       # 400033d4  = data_3ffe2390
	l32i.n	a11, a11, 4             # 400033d7
	call8	fn_400099bc             # 400033d9
	l32r	a13, lit_3ffe1bf8       # 400033dc  = 0xe0091080
	movi.n	a12, 0                  # 400033df
	memw                            # 400033e1
	s32i.n	a12, a13, 0             # 400033e4
.L400033e6:
	movi.n	a15, 0                  # 400033e6
	movi	a2, 180                 # 400033e8
	l32r	a14, lit_3ffe1c84       # 400033eb  = 0x3ffe3f44
	l32i.n	a14, a14, 0             # 400033ee
	remu	a14, a14, a2            # 400033f0
	beq	a14, a15, .L400033f9    # 400033f3
	j	.L40003549              # 400033f6
.L400033f9:
	l32r	a10, lit_3ffe1c88       # 400033f9  = ro_3ffe0424 "Input Duty:"
	call8	fn_400099bc             # 400033fc
	movi.n	a3, 0                   # 400033ff
	s32i.n	a3, a1, 0               # 40003401
	l32r	a2, lit_3ffe1a84        # 40003403  = 0x3ffe4450
	l32i.n	a2, a2, 0               # 40003406
	l32i.n	a15, a1, 0              # 40003408
	bgeu	a15, a2, .L40003440     # 4000340a
.L4000340d:
	l32i.n	a4, a1, 0               # 4000340d
	extui	a4, a4, 0, 4            # 4000340f
	bnez.n	a4, .L4000341f          # 40003412
	l32r	a10, lit_3ffe1c8c       # 40003414  = ro_3ffe0430 "\n  %02d. "
	l32i.n	a11, a1, 0              # 40003417
	srli	a11, a11, 4             # 40003419
	call8	fn_400099bc             # 4000341c
.L4000341f:
	l32r	a10, lit_3ffe1c04       # 4000341f  = ro_3ffe0280 "\t%04X "
	l32i.n	a11, a1, 0              # 40003422
	l32r	a12, lit_3ffe1b88       # 40003424  = 0x3ffe4490
	addx2	a11, a11, a12           # 40003427
	l16ui	a11, a11, 0             # 4000342a
	call8	fn_400099bc             # 4000342d
	l32i.n	a15, a1, 0              # 40003430
	addi.n	a15, a15, 1             # 40003432
	s32i.n	a15, a1, 0              # 40003434
	l32r	a14, lit_3ffe1a84       # 40003436  = 0x3ffe4450
	l32i.n	a14, a14, 0             # 40003439
	l32i.n	a13, a1, 0              # 4000343b
	bltu	a13, a14, .L4000340d    # 4000343d
.L40003440:
	l32r	a10, lit_3ffe1c08       # 40003440  = ro_3ffe0288
	call8	fn_400099bc             # 40003443
	l32r	a10, lit_3ffe1c90       # 40003446  = ro_3ffe043c "Merged Segment:"
	call8	fn_400099bc             # 40003449
	movi.n	a4, 0                   # 4000344c
	s32i.n	a4, a1, 0               # 4000344e
	l32r	a3, lit_3ffe1a98        # 40003450  = data_3ffe2390
	l32i.n	a3, a3, 0               # 40003453
	l32i.n	a2, a1, 0               # 40003455
	bgeu	a2, a3, .L4000348e      # 40003457
.L4000345a:
	movi.n	a6, 0                   # 4000345a
	l32r	a7, lit_3ffe1a80        # 4000345c  = 0x3ffe2bf0
	l32i.n	a7, a7, 20              # 4000345f
	l32i.n	a5, a1, 0               # 40003461
	remu	a5, a5, a7              # 40003463
	bne	a5, a6, .L4000346f      # 40003466
	l32r	a10, lit_3ffe1c08       # 40003469  = ro_3ffe0288
	call8	fn_400099bc             # 4000346c
.L4000346f:
	l32r	a10, lit_3ffe1c04       # 4000346f  = ro_3ffe0280 "\t%04X "
	l32i.n	a11, a1, 0              # 40003472
	l32i.n	a12, a1, 16             # 40003474
	addx4	a11, a11, a12           # 40003476
	l32i.n	a11, a11, 0             # 40003479
	call8	fn_400099bc             # 4000347b
	l32i.n	a15, a1, 0              # 4000347e
	addi.n	a15, a15, 1             # 40003480
	s32i.n	a15, a1, 0              # 40003482
	l32r	a14, lit_3ffe1a98       # 40003484  = data_3ffe2390
	l32i.n	a14, a14, 0             # 40003487
	l32i.n	a13, a1, 0              # 40003489
	bltu	a13, a14, .L4000345a    # 4000348b
.L4000348e:
	l32r	a10, lit_3ffe1c08       # 4000348e  = ro_3ffe0288
	call8	fn_400099bc             # 40003491
	l32r	a10, lit_3ffe1c94       # 40003494  = ro_3ffe044c "LED ADIM:"
	call8	fn_400099bc             # 40003497
	movi.n	a4, 0                   # 4000349a
	s32i.n	a4, a1, 0               # 4000349c
	l32r	a3, lit_3ffe1a98        # 4000349e  = data_3ffe2390
	l32i.n	a3, a3, 0               # 400034a1
	l32i.n	a2, a1, 0               # 400034a3
	bgeu	a2, a3, .L400034de      # 400034a5
.L400034a8:
	movi.n	a6, 0                   # 400034a8
	l32r	a7, lit_3ffe1a80        # 400034aa  = 0x3ffe2bf0
	l32i.n	a7, a7, 20              # 400034ad
	l32i.n	a5, a1, 0               # 400034af
	remu	a5, a5, a7              # 400034b1
	bne	a5, a6, .L400034bd      # 400034b4
	l32r	a10, lit_3ffe1c08       # 400034b7  = ro_3ffe0288
	call8	fn_400099bc             # 400034ba
.L400034bd:
	l32r	a10, lit_3ffe1c04       # 400034bd  = ro_3ffe0280 "\t%04X "
	l32i.n	a11, a1, 0              # 400034c0
	l32r	a12, lit_3ffe1ac4       # 400034c2  = 0x3ffe3ef0
	addx2	a11, a11, a12           # 400034c5
	l16ui	a11, a11, 0             # 400034c8
	call8	fn_400099bc             # 400034cb
	l32i.n	a15, a1, 0              # 400034ce
	addi.n	a15, a15, 1             # 400034d0
	s32i.n	a15, a1, 0              # 400034d2
	l32r	a14, lit_3ffe1a98       # 400034d4  = data_3ffe2390
	l32i.n	a14, a14, 0             # 400034d7
	l32i.n	a13, a1, 0              # 400034d9
	bltu	a13, a14, .L400034a8    # 400034db
.L400034de:
	l32r	a10, lit_3ffe1c08       # 400034de  = ro_3ffe0288
	call8	fn_400099bc             # 400034e1
	l32r	a10, lit_3ffe1c98       # 400034e4  = ro_3ffe0458 "LED PDIM:"
	call8	fn_400099bc             # 400034e7
	movi.n	a4, 0                   # 400034ea
	s32i.n	a4, a1, 0               # 400034ec
	l32r	a3, lit_3ffe1a98        # 400034ee  = data_3ffe2390
	l32i.n	a3, a3, 0               # 400034f1
	l32i.n	a2, a1, 0               # 400034f3
	bgeu	a2, a3, .L4000352e      # 400034f5
.L400034f8:
	movi.n	a6, 0                   # 400034f8
	l32r	a7, lit_3ffe1a80        # 400034fa  = 0x3ffe2bf0
	l32i.n	a7, a7, 20              # 400034fd
	l32i.n	a5, a1, 0               # 400034ff
	remu	a5, a5, a7              # 40003501
	bne	a5, a6, .L4000350d      # 40003504
	l32r	a10, lit_3ffe1c08       # 40003507  = ro_3ffe0288
	call8	fn_400099bc             # 4000350a
.L4000350d:
	l32r	a10, lit_3ffe1c04       # 4000350d  = ro_3ffe0280 "\t%04X "
	l32i.n	a11, a1, 0              # 40003510
	l32r	a12, lit_3ffe1ac0       # 40003512  = 0x3ffe3eb0
	addx2	a11, a11, a12           # 40003515
	l16ui	a11, a11, 0             # 40003518
	call8	fn_400099bc             # 4000351b
	l32i.n	a15, a1, 0              # 4000351e
	addi.n	a15, a15, 1             # 40003520
	s32i.n	a15, a1, 0              # 40003522
	l32r	a14, lit_3ffe1a98       # 40003524  = data_3ffe2390
	l32i.n	a14, a14, 0             # 40003527
	l32i.n	a13, a1, 0              # 40003529
	bltu	a13, a14, .L400034f8    # 4000352b
.L4000352e:
	l32r	a10, lit_3ffe1c08       # 4000352e  = ro_3ffe0288
	call8	fn_400099bc             # 40003531
	l32r	a10, lit_3ffe1c9c       # 40003534  = ro_3ffe0464 "Pure Pattern: %d\n"
	l32i	a11, a1, 64             # 40003537
	call8	fn_400099bc             # 4000353a
	l32r	a10, lit_3ffe1ca0       # 4000353d  = ro_3ffe0478 "ApplyGlobalGain: 0x%04X\n"
	l32r	a11, lit_3ffe1a98       # 40003540  = data_3ffe2390
	l32i	a11, a11, 72            # 40003543
	call8	fn_400099bc             # 40003546
.L40003549:
	l32r	a13, lit_3ffe1c84       # 40003549  = 0x3ffe3f44
	l32r	a12, lit_3ffe1c84       # 4000354c  = 0x3ffe3f44
	l32i.n	a12, a12, 0             # 4000354f
	addi.n	a12, a12, 1             # 40003551
	s32i.n	a12, a13, 0             # 40003553
.L40003555:
	retw.n                          # 40003555
	.size	fn_40003190, . - fn_40003190
