# ldc_hw_write_reg160  (fn_40006750): 0x40006750-0x40006760 (firmware file offset 0x36750-0x36760), 7 instructions
# Name basis: descriptive - single register write, start-up value 0x08802000
# Called from: ldc_hw_init
# Writes the value to register 0xE0080160. ldc_hw_init passes 0x08802000.
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Other literal values: 0xe0080160

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_write_reg160, @function
ldc_hw_write_reg160:                    # fn_40006750
	entry	a1, 48                  # 40006750
	s32i.n	a2, a1, 0               # 40006753
	# *(volatile u32 *)0xE0080160 = value;
	l32r	a5, lit_3ffe1ef8        # 40006755  = 0xe0080160
	l32i.n	a4, a1, 0               # 40006758
	memw                            # 4000675a
	s32i.n	a4, a5, 0               # 4000675d
	retw.n                          # 4000675f
	.size	ldc_hw_write_reg160, . - ldc_hw_write_reg160
