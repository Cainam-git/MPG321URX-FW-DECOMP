# reg_write32_masked_wrap  (fn_4000416c): 0x4000416c-0x4000417f (firmware file offset 0x3416c-0x3417f), 9 instructions
# Name basis: derived - code: only calls reg_write32_masked; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Changes the masked bits of a 32-bit word by calling reg_write32_masked with the same arguments.
# Arguments: a2 address, a3 value, a4 mask (bits that take the value).
# Locals: a1+0 address, a1+4 value, a1+8 mask.
# Returns: nothing.
# Note: nothing calls it and no word holds its address.
# Calls: reg_write32_masked

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_write32_masked_wrap, @function
reg_write32_masked_wrap:                # fn_4000416c
	entry	a1, 48                  # 4000416c
	# reg_write32_masked(address, value, mask)
	s32i.n	a2, a1, 0               # 4000416f
	s32i.n	a3, a1, 4               # 40004171
	s32i.n	a4, a1, 8               # 40004173
	l32i.n	a10, a1, 0              # 40004175
	l32i.n	a11, a1, 4              # 40004177
	l32i.n	a12, a1, 8              # 40004179
	call8	reg_write32_masked      # 4000417b
	retw.n                          # 4000417e
	.size	reg_write32_masked_wrap, . - reg_write32_masked_wrap
