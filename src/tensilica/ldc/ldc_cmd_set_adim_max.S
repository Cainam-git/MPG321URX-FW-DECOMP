# ldc_cmd_set_adim_max  (fn_40001780): 0x40001780-0x4000179c (firmware file offset 0x31780-0x3179c), 12 instructions
# Name basis: proven - cfg +12 printed as 'ADIM_Max' by ldc_print_debug_dump
# Address stored in the words at: 0x4000d2dc
# Addresses loaded: ldc_dimming_settings
#
# Command 0x33 (sent by ldc_send_adim_max): stores the low 10 bits of the value as ADIM_Max (cfg +12), but only
# when the value is above ADIM_Min (cfg +8).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_adim_max, @function
ldc_cmd_set_adim_max:                   # fn_40001780
	entry	a1, 48                  # 40001780
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001783
	s32i.n	a3, a1, 4               # 40001785
	# if (value > cfg.adim_min)
	l32i.n	a6, a1, 4               # 40001787
	l32r	a5, lit_3ffe1a98        # 40001789  = ldc_dimming_settings
	l32i.n	a5, a5, 8               # 4000178c
	bgeu	a5, a6, .L4000179b      # 4000178e
	# cfg.adim_max = value & 0x3FF
	l32r	a8, lit_3ffe1a98        # 40001791  = ldc_dimming_settings
	l32i.n	a7, a1, 4               # 40001794
	extui	a7, a7, 0, 10           # 40001796
	s32i.n	a7, a8, 12              # 40001799
.L4000179b:
	retw.n                          # 4000179b
	.size	ldc_cmd_set_adim_max, . - ldc_cmd_set_adim_max
