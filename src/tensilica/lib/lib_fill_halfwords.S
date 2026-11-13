# lib_fill_halfwords  (fn_4000087c): 0x4000087c-0x400008bf (firmware file offset 0x3087c-0x308bf), 30 instructions
# Name basis: derived - value | value << 16 into count/2 words; fills LED PDIM / LED ADIM tables
# Called from: ldc_init_panel_defaults, ldc_cmd_set_ldc_mode, ldc_cmd_set_user_pdim, ldc_cmd_set_user_adim,
#              ldc_cmd_set_adim_bright_percent
#
# Writes one value into count 16-bit entries: each of the count / 2 words of dst gets value | (value << 16).
# a2 = value: 16-bit value
# a3 = dst: array of 16-bit entries (written a word at a time)
# a4 = count: number of 16-bit entries
# Locals: a1+0 = pair (value | value << 16), a1+4 = i (word index), a1+8 = out (address of word i).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_fill_halfwords, @function
lib_fill_halfwords:                     # fn_4000087c
	entry	a1, 64                  # 4000087c
	s32i.n	a2, a1, 16              # 4000087f
	s32i.n	a3, a1, 20              # 40000881
	s32i.n	a4, a1, 24              # 40000883
	# pair = value | (value << 16)
	l32i.n	a11, a1, 16             # 40000885
	slli	a11, a11, 16            # 40000887
	l32i.n	a10, a1, 16             # 4000088a
	or	a10, a10, a11           # 4000088c
	s32i.n	a10, a1, 0              # 4000088f
	# for (i = 0; i < count / 2; i++)
	movi.n	a9, 0                   # 40000891
	s32i.n	a9, a1, 4               # 40000893
	l32i.n	a8, a1, 24              # 40000895
	srli	a8, a8, 1               # 40000897
	l32i.n	a7, a1, 4               # 4000089a
	bgeu	a7, a8, .L400008be      # 4000089c
.L4000089f:
	# out = (word *)dst + i; *out = pair
	l32i.n	a3, a1, 4               # 4000089f
	l32i.n	a4, a1, 20              # 400008a1
	addx4	a3, a3, a4              # 400008a3
	s32i.n	a3, a1, 8               # 400008a6
	l32i.n	a2, a1, 8               # 400008a8
	l32i.n	a15, a1, 0              # 400008aa
	s32i.n	a15, a2, 0              # 400008ac
	# i++; loop while i < count / 2
	l32i.n	a14, a1, 4              # 400008ae
	addi.n	a14, a14, 1             # 400008b0
	s32i.n	a14, a1, 4              # 400008b2
	l32i.n	a13, a1, 24             # 400008b4
	srli	a13, a13, 1             # 400008b6
	l32i.n	a12, a1, 4              # 400008b9
	bltu	a12, a13, .L4000089f    # 400008bb
.L400008be:
	retw.n                          # 400008be
	.size	lib_fill_halfwords, . - lib_fill_halfwords
