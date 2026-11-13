# reg_write32_wrap  (fn_4000415c): 0x4000415c-0x4000416b (firmware file offset 0x3415c-0x3416b), 7 instructions
# Name basis: derived - code: only calls reg_write32; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Writes a 32-bit word to an address by calling reg_write32.
# Arguments: a2 address, a3 value.
# Locals: a1+0 address, a1+4 value.
# Returns: nothing.
# Note: nothing calls it and no word holds its address.
# Calls: reg_write32

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_write32_wrap, @function
reg_write32_wrap:                       # fn_4000415c
	entry	a1, 48                  # 4000415c
	# reg_write32(address, value)
	s32i.n	a2, a1, 0               # 4000415f
	s32i.n	a3, a1, 4               # 40004161
	l32i.n	a10, a1, 0              # 40004163
	l32i.n	a11, a1, 4              # 40004165
	call8	reg_write32             # 40004167
	retw.n                          # 4000416a
	.size	reg_write32_wrap, . - reg_write32_wrap
