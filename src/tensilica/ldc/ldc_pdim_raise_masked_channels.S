# ldc_pdim_raise_masked_channels  (fn_40002d0c): 0x40002d0c-0x40002d78 (firmware file offset 0x32d0c-0x32d78), 46 instructions
# Name basis: descriptive - code; mailbox +0x38 written by main processor ldc_write_status_word
# Called from: ldc_run_pdim_path
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0xe0091038, 0x00000fff
#
# PDIM path step (ldc_run_pdim_path): reads mailbox word 0xE0091038 (portal 2 +0x38, written by the main processor's
# ldc_write_status_word). When it is not 0, every channel whose bit is set in it and whose PDIM is at most 15 gets
# PDIM 0xFFF.
# Arguments: a2 = pdim (32-bit words, changed).
# Locals: a1+0 = i, a1+4 = mask.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_pdim_raise_masked_channels, @function
ldc_pdim_raise_masked_channels:         # fn_40002d0c
	entry	a1, 64                  # 40002d0c
	s32i.n	a2, a1, 16              # 40002d0f
	# i = 0; mask = 0
	movi.n	a6, 0                   # 40002d11
	s32i.n	a6, a1, 0               # 40002d13
	movi.n	a5, 0                   # 40002d15
	s32i.n	a5, a1, 4               # 40002d17
	# if (mailbox[0x38] != 0)
	movi.n	a5, 0                   # 40002d19
	l32r	a4, lit_3ffe1bd8        # 40002d1b  = 0xe0091038
	memw                            # 40002d1e
	l32i.n	a4, a4, 0               # 40002d21
	beq	a4, a5, .L40002d77      # 40002d23
	# mask = mailbox[0x38]
	l32r	a10, lit_3ffe1bd8       # 40002d26  = 0xe0091038
	memw                            # 40002d29
	l32i.n	a10, a10, 0             # 40002d2c
	s32i.n	a10, a1, 4              # 40002d2e
	# for (i = 0; i < cfg->channel_count; i++)
	movi.n	a9, 0                   # 40002d30
	s32i.n	a9, a1, 0               # 40002d32
	l32r	a8, lit_3ffe1a98        # 40002d34  = ldc_dimming_settings
	l32i.n	a8, a8, 0               # 40002d37
	l32i.n	a7, a1, 0               # 40002d39
	bgeu	a7, a8, .L40002d77      # 40002d3b
.L40002d3e:
	# if (((mask >> i) & 1) && pdim[i] <= 15) pdim[i] = 0xFFF
	l32i.n	a11, a1, 4              # 40002d3e
	l32i.n	a12, a1, 0              # 40002d40
	ssr	a12                     # 40002d42
	srl	a11, a11                # 40002d45
	extui	a11, a11, 0, 1          # 40002d48
	beqz.n	a11, .L40002d67         # 40002d4b
	l32i.n	a14, a1, 0              # 40002d4d
	l32i.n	a15, a1, 16             # 40002d4f
	addx4	a14, a14, a15           # 40002d51
	l32i.n	a14, a14, 0             # 40002d54
	movi.n	a13, 15                 # 40002d56
	bltu	a13, a14, .L40002d67    # 40002d58
	l32i.n	a3, a1, 0               # 40002d5b
	l32i.n	a4, a1, 16              # 40002d5d
	addx4	a3, a3, a4              # 40002d5f
	l32r	a2, lit_3ffe1abc        # 40002d62  = 0x00000fff
	s32i.n	a2, a3, 0               # 40002d65
.L40002d67:
	# (i++, loop while i < channel_count)
	l32i.n	a7, a1, 0               # 40002d67
	addi.n	a7, a7, 1               # 40002d69
	s32i.n	a7, a1, 0               # 40002d6b
	l32r	a6, lit_3ffe1a98        # 40002d6d  = ldc_dimming_settings
	l32i.n	a6, a6, 0               # 40002d70
	l32i.n	a5, a1, 0               # 40002d72
	bltu	a5, a6, .L40002d3e      # 40002d74
.L40002d77:
	retw.n                          # 40002d77
	.size	ldc_pdim_raise_masked_channels, . - ldc_pdim_raise_masked_channels
