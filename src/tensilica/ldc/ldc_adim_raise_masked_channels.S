# ldc_adim_raise_masked_channels  (fn_40002ca0): 0x40002ca0-0x40002d0b (firmware file offset 0x32ca0-0x32d0b), 46 instructions
# Name basis: descriptive - code; mailbox +0x38 written by main processor ldc_write_status_word
# Called from: ldc_run_adim_path
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0xe0091038
#
# ADIM path step (ldc_run_adim_path): reads mailbox word 0xE0091038 (portal 2 +0x38, written by the main processor's
# ldc_write_status_word). When it is not 0, every channel whose bit is set in it and whose ADIM is at most 31 gets
# ADIM 32.
# Arguments: a2 = adim (32-bit words, changed).
# Locals: a1+0 = i, a1+4 = mask.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_adim_raise_masked_channels, @function
ldc_adim_raise_masked_channels:         # fn_40002ca0
	entry	a1, 64                  # 40002ca0
	s32i.n	a2, a1, 16              # 40002ca3
	# i = 0; mask = 0
	movi.n	a6, 0                   # 40002ca5
	s32i.n	a6, a1, 0               # 40002ca7
	movi.n	a5, 0                   # 40002ca9
	s32i.n	a5, a1, 4               # 40002cab
	# if (mailbox[0x38] != 0)
	movi.n	a5, 0                   # 40002cad
	l32r	a4, lit_3ffe1bd8        # 40002caf  = 0xe0091038
	memw                            # 40002cb2
	l32i.n	a4, a4, 0               # 40002cb5
	beq	a4, a5, .L40002d0a      # 40002cb7
	# mask = mailbox[0x38]
	l32r	a10, lit_3ffe1bd8       # 40002cba  = 0xe0091038
	memw                            # 40002cbd
	l32i.n	a10, a10, 0             # 40002cc0
	s32i.n	a10, a1, 4              # 40002cc2
	# for (i = 0; i < cfg->channel_count; i++)
	movi.n	a9, 0                   # 40002cc4
	s32i.n	a9, a1, 0               # 40002cc6
	l32r	a8, lit_3ffe1a98        # 40002cc8  = ldc_dimming_settings
	l32i.n	a8, a8, 0               # 40002ccb
	l32i.n	a7, a1, 0               # 40002ccd
	bgeu	a7, a8, .L40002d0a      # 40002ccf
.L40002cd2:
	# if (((mask >> i) & 1) && adim[i] <= 31) adim[i] = 32
	l32i.n	a11, a1, 4              # 40002cd2
	l32i.n	a12, a1, 0              # 40002cd4
	ssr	a12                     # 40002cd6
	srl	a11, a11                # 40002cd9
	extui	a11, a11, 0, 1          # 40002cdc
	beqz.n	a11, .L40002cfa         # 40002cdf
	l32i.n	a14, a1, 0              # 40002ce1
	l32i.n	a15, a1, 16             # 40002ce3
	addx4	a14, a14, a15           # 40002ce5
	l32i.n	a14, a14, 0             # 40002ce8
	movi.n	a13, 31                 # 40002cea
	bltu	a13, a14, .L40002cfa    # 40002cec
	l32i.n	a3, a1, 0               # 40002cef
	l32i.n	a4, a1, 16              # 40002cf1
	addx4	a3, a3, a4              # 40002cf3
	movi.n	a2, 32                  # 40002cf6
	s32i.n	a2, a3, 0               # 40002cf8
.L40002cfa:
	# (i++, loop while i < channel_count)
	l32i.n	a7, a1, 0               # 40002cfa
	addi.n	a7, a7, 1               # 40002cfc
	s32i.n	a7, a1, 0               # 40002cfe
	l32r	a6, lit_3ffe1a98        # 40002d00  = ldc_dimming_settings
	l32i.n	a6, a6, 0               # 40002d03
	l32i.n	a5, a1, 0               # 40002d05
	bltu	a5, a6, .L40002cd2      # 40002d07
.L40002d0a:
	retw.n                          # 40002d0a
	.size	ldc_adim_raise_masked_channels, . - ldc_adim_raise_masked_channels
