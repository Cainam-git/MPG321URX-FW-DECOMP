# ldc_cmd_set_adim_level_and_percent  (fn_40001830): 0x40001830-0x40001857 (firmware file offset 0x31830-0x31857), 16 instructions
# Name basis: derived - sub<<2|value>>14 to cfg +28, then ldc_cmd_set_user_adim(0, value & 0x3FF)
# Address stored in the words at: 0x4000d304
# Calls: ldc_cmd_set_user_adim
# Addresses loaded: ldc_dimming_settings
#
# Command 0x39 (sent by ldc_send_adim_level_and_percent): one command carries two values. ADIM_BrighPercent (cfg +28) =
# (sub << 2) | (value >> 14), a 10-bit number from the sub-code and the top two bits of the value; then
# ldc_cmd_set_user_adim(0, value & 0x3FF) sets usUserADIM from the low 10 bits and recomputes PercentADIM.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_adim_level_and_percent, @function
ldc_cmd_set_adim_level_and_percent:     # fn_40001830
	entry	a1, 48                  # 40001830
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 40001833
	s32i.n	a3, a1, 4               # 40001835
	# cfg.adim_bright_percent = ((sub & 0xFF) << 2) | (value >> 14)
	l32r	a13, lit_3ffe1a98       # 40001837  = ldc_dimming_settings
	l32i.n	a14, a1, 0              # 4000183a
	extui	a14, a14, 0, 8          # 4000183c
	slli	a14, a14, 2             # 4000183f
	l32i.n	a12, a1, 4              # 40001842
	srli	a12, a12, 14            # 40001844
	or	a12, a12, a14           # 40001847
	s32i.n	a12, a13, 28            # 4000184a
	# ldc_cmd_set_user_adim(0, value & 0x3FF)
	movi.n	a10, 0                  # 4000184c
	l32i.n	a11, a1, 4              # 4000184e
	extui	a11, a11, 0, 10         # 40001850
	call8	ldc_cmd_set_user_adim   # 40001853
	retw.n                          # 40001856
	.size	ldc_cmd_set_adim_level_and_percent, . - ldc_cmd_set_adim_level_and_percent
