# ldc_hw_set_reg28c_bits4_6  (fn_40006854): 0x40006854-0x4000686b (firmware file offset 0x36854-0x3686b), 9 instructions
# Name basis: descriptive - command 0x42 handler and start-up value 3; mechanics only
# Called from: ldc_cmd_set_reg28c_bits4_6, ldc_hw_init
# Writes the low 3 bits of the value to bits 4..6 of register 0xE008028C. ldc_hw_init passes 3; command 0x42
# (ldc_cmd_set_reg28c_bits4_6) passes its value.
# Arguments: a2 value.
# Locals: a1+0 value.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0xe008028c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_set_reg28c_bits4_6, @function
ldc_hw_set_reg28c_bits4_6:              # fn_40006854
	entry	a1, 48                  # 40006854
	s32i.n	a2, a1, 0               # 40006857
	# reg_write32_masked(0xE008028C, (value & 7) << 4, 0x70);
	l32r	a10, lit_3ffe1f08       # 40006859  = 0xe008028c
	l32i.n	a11, a1, 0              # 4000685c
	extui	a11, a11, 0, 3          # 4000685e
	slli	a11, a11, 4             # 40006861
	movi	a12, 112                # 40006864
	call8	reg_write32_masked      # 40006867
	retw.n                          # 4000686a
	.size	ldc_hw_set_reg28c_bits4_6, . - ldc_hw_set_reg28c_bits4_6
