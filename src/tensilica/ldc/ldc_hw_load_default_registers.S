# ldc_hw_load_default_registers  (fn_40006144): 0x40006144-0x4000617d (firmware file offset 0x36144-0x3617d), 25 instructions
# Name basis: proven - loop over the address/value table, called first by the start-up set-up
# Called from: ldc_hw_init
# Writes the 59 {register address, value} pairs of the table at ldc_hw_default_registers (0xE0080000..0xE0080A2C, the
# last pair writes 0xE008000C again) into the dimming block, in table order.
# Arguments: none.
# Locals: a1+0 count (59), a1+4 i.
# Returns: nothing.
# Addresses loaded: ldc_hw_default_registers

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_load_default_registers, @function
ldc_hw_load_default_registers:          # fn_40006144
	entry	a1, 48                  # 40006144
	# count = 59;
	movi.n	a5, 59                  # 40006147
	s32i.n	a5, a1, 0               # 40006149
	# for (i = 0; i < count; i++)
	movi.n	a4, 0                   # 4000614b
	s32i.n	a4, a1, 4               # 4000614d
	l32i.n	a3, a1, 0               # 4000614f
	l32i.n	a2, a1, 4               # 40006151
	bgeu	a2, a3, .L4000617c      # 40006153
.L40006156:
	#     *(volatile u32 *)table[i].reg = table[i].value;   /* table = ldc_hw_default_registers, 8 bytes per entry */
	l32i.n	a10, a1, 4              # 40006156
	l32r	a11, lit_3ffe1e84       # 40006158  = ldc_hw_default_registers
	addx8	a10, a10, a11           # 4000615b
	l32i.n	a10, a10, 0             # 4000615e
	l32i.n	a9, a1, 4               # 40006160
	l32r	a11, lit_3ffe1e84       # 40006162  = ldc_hw_default_registers
	addx8	a9, a9, a11             # 40006165
	l32i.n	a9, a9, 4               # 40006168
	memw                            # 4000616a
	s32i.n	a9, a10, 0              # 4000616d
	#     /* i++, loop while i < count */
	l32i.n	a8, a1, 4               # 4000616f
	addi.n	a8, a8, 1               # 40006171
	s32i.n	a8, a1, 4               # 40006173
	l32i.n	a7, a1, 0               # 40006175
	l32i.n	a6, a1, 4               # 40006177
	bltu	a6, a7, .L40006156      # 40006179
.L4000617c:
	retw.n                          # 4000617c
	.size	ldc_hw_load_default_registers, . - ldc_hw_load_default_registers
