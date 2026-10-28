# fn_4000233c: 0x4000233c-0x40002416 (firmware file offset 0x3233c-0x32416), 94 instructions
# Called from: fn_400030c8
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000233c, @function
fn_4000233c:
	entry	a1, 80                  # 4000233c
	s32i.n	a2, a1, 32              # 4000233f
	s32i.n	a3, a1, 36              # 40002341
	s32i.n	a4, a1, 40              # 40002343
	movi.n	a14, 0                  # 40002345
	s32i.n	a14, a1, 0              # 40002347
	movi	a12, 255                # 40002349
	l32i.n	a13, a1, 36             # 4000234c
	l32r	a11, lit_3ffe1a98       # 4000234e  = data_3ffe2390
	l32i	a11, a11, 64            # 40002351
	mull	a11, a11, a13           # 40002354
	quou	a11, a11, a12           # 40002357
	s32i.n	a11, a1, 4              # 4000235a
	movi.n	a10, 0                  # 4000235c
	s32i.n	a10, a1, 8              # 4000235e
	movi.n	a9, 0                   # 40002360
	s32i.n	a9, a1, 12              # 40002362
	movi.n	a8, 0                   # 40002364
	s32i.n	a8, a1, 16              # 40002366
	movi	a8, 255                 # 40002368
	l32r	a7, lit_3ffe1a98        # 4000236b  = data_3ffe2390
	l32i	a7, a7, 64              # 4000236e
	bne	a7, a8, .L40002377      # 40002371
	j	.L40002415              # 40002374
.L40002377:
	movi.n	a3, 0                   # 40002377
	s32i.n	a3, a1, 0               # 40002379
	l32r	a2, lit_3ffe1a98        # 4000237b  = data_3ffe2390
	l32i.n	a2, a2, 0               # 4000237e
	l32i.n	a15, a1, 0              # 40002380
	bgeu	a15, a2, .L400023a4     # 40002382
.L40002385:
	l32i.n	a8, a1, 8               # 40002385
	l32i.n	a7, a1, 0               # 40002387
	l32i.n	a9, a1, 32              # 40002389
	addx4	a7, a7, a9              # 4000238b
	l32i.n	a7, a7, 0               # 4000238e
	add.n	a7, a7, a8              # 40002390
	s32i.n	a7, a1, 8               # 40002392
	l32i.n	a6, a1, 0               # 40002394
	addi.n	a6, a6, 1               # 40002396
	s32i.n	a6, a1, 0               # 40002398
	l32r	a5, lit_3ffe1a98        # 4000239a  = data_3ffe2390
	l32i.n	a5, a5, 0               # 4000239d
	l32i.n	a4, a1, 0               # 4000239f
	bltu	a4, a5, .L40002385      # 400023a1
.L400023a4:
	l32r	a13, lit_3ffe1a98       # 400023a4  = data_3ffe2390
	l32i.n	a13, a13, 0             # 400023a7
	l32i.n	a12, a1, 8              # 400023a9
	quou	a12, a12, a13           # 400023ab
	s32i.n	a12, a1, 12             # 400023ae
	l32i.n	a11, a1, 12             # 400023b0
	l32i.n	a10, a1, 4              # 400023b2
	bgeu	a10, a11, .L40002415    # 400023b4
	movi.n	a2, 0                   # 400023b7
	s32i.n	a2, a1, 0               # 400023b9
	l32r	a15, lit_3ffe1a98       # 400023bb  = data_3ffe2390
	l32i.n	a15, a15, 0             # 400023be
	l32i.n	a14, a1, 0              # 400023c0
	bgeu	a14, a15, .L40002415    # 400023c2
.L400023c5:
	l32i.n	a6, a1, 12              # 400023c5
	l32i.n	a7, a1, 4               # 400023c7
	l32i.n	a5, a1, 0               # 400023c9
	l32i.n	a8, a1, 32              # 400023cb
	addx4	a5, a5, a8              # 400023cd
	l32i.n	a5, a5, 0               # 400023d0
	mull	a5, a5, a7              # 400023d2
	quou	a5, a5, a6              # 400023d5
	s32i.n	a5, a1, 16              # 400023d8
	l32i.n	a4, a1, 40              # 400023da
	l32i.n	a3, a1, 16              # 400023dc
	bgeu	a3, a4, .L400023f6      # 400023de
	l32i.n	a10, a1, 0              # 400023e1
	l32i.n	a11, a1, 32             # 400023e3
	addx4	a10, a10, a11           # 400023e5
	l32i.n	a10, a10, 0             # 400023e8
	movi.n	a9, 0                   # 400023ea
	bgeu	a9, a10, .L400023f6     # 400023ec
	l32i.n	a12, a1, 40             # 400023ef
	s32i.n	a12, a1, 20             # 400023f1
	j	.L400023fa              # 400023f3
.L400023f6:
	l32i.n	a13, a1, 16             # 400023f6
	s32i.n	a13, a1, 20             # 400023f8
.L400023fa:
	l32i.n	a4, a1, 0               # 400023fa
	l32i.n	a5, a1, 32              # 400023fc
	addx4	a4, a4, a5              # 400023fe
	l32i.n	a3, a1, 20              # 40002401
	s32i.n	a3, a4, 0               # 40002403
	l32i.n	a2, a1, 0               # 40002405
	addi.n	a2, a2, 1               # 40002407
	s32i.n	a2, a1, 0               # 40002409
	l32r	a15, lit_3ffe1a98       # 4000240b  = data_3ffe2390
	l32i.n	a15, a15, 0             # 4000240e
	l32i.n	a14, a1, 0              # 40002410
	bltu	a14, a15, .L400023c5    # 40002412
.L40002415:
	retw.n                          # 40002415
	.size	fn_4000233c, . - fn_4000233c
