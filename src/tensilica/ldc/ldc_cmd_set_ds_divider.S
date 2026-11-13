# ldc_cmd_set_ds_divider  (fn_40001758): 0x40001758-0x40001768 (firmware file offset 0x31758-0x31768), 7 instructions
# Name basis: derived - ldc_set_ds_divider -> DRV_LDC_SetDSRegisters 'DRV_LDC_SetDSRegisters'
# Address stored in the words at: 0x4000d35c
# Calls: ldc_set_ds_divider
#
# Command 0x46: passes the low byte of the value to ldc_set_ds_divider, which stores it at segment_grid +48
# (0x3FFE4450 +48) and runs DRV_LDC_SetDSRegisters: bits 16..31 of 0xE0080040 = segment_grid
# +16 / divider, bits 0..7 of 0xE0080370 = divider. ldc_cmd_load_panel_and_start sets the same value (16 or 32).
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word)
# a3 = value: 16-bit value of the command (bits 0..15)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_set_ds_divider, @function
ldc_cmd_set_ds_divider:                 # fn_40001758
	entry	a1, 48                  # 40001758
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 4000175b
	s32i.n	a3, a1, 4               # 4000175d
	# ldc_set_ds_divider((uint8_t)value)
	l32i.n	a10, a1, 4              # 4000175f
	extui	a10, a10, 0, 8          # 40001761
	call8	ldc_set_ds_divider      # 40001764
	retw.n                          # 40001767
	.size	ldc_cmd_set_ds_divider, . - ldc_cmd_set_ds_divider
