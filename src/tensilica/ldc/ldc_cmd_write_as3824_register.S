# ldc_cmd_write_as3824_register  (fn_400019c4): 0x400019c4-0x400019e1 (firmware file offset 0x319c4-0x319e1), 12 instructions
# Name basis: derived - ldc_as3824_write_byte is the register send of the 'LED AS3824 ...' writers (reg 7 =
#   CURR CTRL)
# Address stored in the words at: 0x4000d3ac
# Calls: ldc_as3824_write_byte
# Other literal values: 0x3ffe2bf0
#
# Command 0x61 (sent by ldc_send_led_driver_register and ldc_user_send_cmd_0x61, the latter with sub-code 7): with LED driver type 1 (panel +24) calls ldc_as3824_write_byte with
# the sub-code and the low byte of the value; ldc_as3824_write_byte is the routine through which the "LED AS3824 ..."
# writers send a register number and a value (e.g. register 7 for "CURR CTRL"). Other driver types do
# nothing.
# a2 = sub: sub-code of the mailbox command (bits 16..23 of the command word), the register number
# a3 = value: 16-bit value of the command (bits 0..15), the register value (low byte)
# Locals: a1+0 = sub, a1+4 = value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_cmd_write_as3824_register, @function
ldc_cmd_write_as3824_register:          # fn_400019c4
	entry	a1, 48                  # 400019c4
	# sub = a2; value = a3
	s32i.n	a2, a1, 0               # 400019c7
	s32i.n	a3, a1, 4               # 400019c9
	# if (panel.driver_type == 1)
	l32r	a5, lit_3ffe1a80        # 400019cb  = 0x3ffe2bf0
	l32i.n	a5, a5, 24              # 400019ce
	bnei	a5, 1, .L400019e0       # 400019d0
	# ldc_as3824_write_byte((uint8_t)sub, (uint8_t)value)
	l32i.n	a10, a1, 0              # 400019d3
	extui	a10, a10, 0, 8          # 400019d5
	l32i.n	a11, a1, 4              # 400019d8
	extui	a11, a11, 0, 8          # 400019da
	call8	ldc_as3824_write_byte   # 400019dd
.L400019e0:
	retw.n                          # 400019e0
	.size	ldc_cmd_write_as3824_register, . - ldc_cmd_write_as3824_register
