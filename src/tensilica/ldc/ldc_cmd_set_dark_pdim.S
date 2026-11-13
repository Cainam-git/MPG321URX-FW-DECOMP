# ldc_cmd_set_dark_pdim  (fn_40001510): 0x40001510-0x40001539 (firmware file offset 0x31510-0x31539), 16 instructions
# Name basis: descriptive - panel +0x14C, read by ldc_pdim_select_user_or_dark for entries <= 9
# Address stored in the words at: 0x4000d2d4
# Addresses loaded: ldc_dimming_settings
# Other literal values: 0x3ffe2bf0
#
# Command 0x32: stores the value at panel +0x14C, at most usUserPDIM. ldc_pdim_select_user_or_dark gives this value to the
# channels whose entry in its input array is 9 or less, and usUserPDIM to the others.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_dark_pdim, @function
ldc_cmd_set_dark_pdim:                  # fn_40001510
	entry	a1, 48                  # 40001510
	s32i.n	a2, a1, 0               # 40001513
	s32i.n	a3, a1, 4               # 40001515
	# panel.dark_pdim = value   (panel +0x14C)
	l32r	a8, lit_3ffe1a80        # 40001517  = 0x3ffe2bf0
	l32i.n	a7, a1, 4               # 4000151a
	s32i	a7, a8, 0x14c           # 4000151c
	# if (panel.dark_pdim > cfg.user_pdim) panel.dark_pdim = cfg.user_pdim
	l32r	a6, lit_3ffe1a80        # 4000151f  = 0x3ffe2bf0
	l32i	a6, a6, 0x14c           # 40001522
	l32r	a5, lit_3ffe1a98        # 40001525  = ldc_dimming_settings
	l32i.n	a5, a5, 16              # 40001528
	bgeu	a5, a6, .L40001538      # 4000152a
	l32r	a9, lit_3ffe1a80        # 4000152d  = 0x3ffe2bf0
	l32r	a8, lit_3ffe1a98        # 40001530  = ldc_dimming_settings
	l32i.n	a8, a8, 16              # 40001533
	s32i	a8, a9, 0x14c           # 40001535
.L40001538:
	retw.n                          # 40001538
	.size	ldc_cmd_set_dark_pdim, . - ldc_cmd_set_dark_pdim
