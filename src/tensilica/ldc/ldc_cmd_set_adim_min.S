# ldc_cmd_set_adim_min  (fn_400017a0): 0x400017a0-0x400017bc (firmware file offset 0x317a0-0x317bc), 12 instructions
# Name basis: proven - cfg +8 printed as 'ADIM_Min' by ldc_print_debug_dump
# Address stored in the words at: 0x4000d2e4
# Addresses loaded: ldc_dimming_settings
#
# Command 0x34 (sent by ldc_send_adim_min): stores the low 10 bits of the value as ADIM_Min (cfg +8), but only
# when the value is below ADIM_Max (cfg +12).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_adim_min, @function
ldc_cmd_set_adim_min:                   # fn_400017a0
	entry	a1, 48                  # 400017a0
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 400017a3
	s32i.n	a3, a1, 4               # 400017a5
	# if (value < cfg.adim_max)
	l32r	a6, lit_3ffe1a98        # 400017a7  = ldc_dimming_settings
	l32i.n	a6, a6, 12              # 400017aa
	l32i.n	a5, a1, 4               # 400017ac
	bgeu	a5, a6, .L400017bb      # 400017ae
	# cfg.adim_min = value & 0x3FF
	l32r	a8, lit_3ffe1a98        # 400017b1  = ldc_dimming_settings
	l32i.n	a7, a1, 4               # 400017b4
	extui	a7, a7, 0, 10           # 400017b6
	s32i.n	a7, a8, 8               # 400017b9
.L400017bb:
	retw.n                          # 400017bb
	.size	ldc_cmd_set_adim_min, . - ldc_cmd_set_adim_min
