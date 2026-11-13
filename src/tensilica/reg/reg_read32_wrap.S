# reg_read32_wrap  (fn_4000414c): 0x4000414c-0x40004159 (firmware file offset 0x3414c-0x34159), 6 instructions
# Name basis: derived - code: only calls reg_read32; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Returns the 32-bit word at an address by calling reg_read32 and passing its result on.
# Arguments: a2 address.
# Locals: a1+0 address.
# Returns: the word read.
# Note: nothing calls it and no word holds its address.
# Calls: reg_read32

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_read32_wrap, @function
reg_read32_wrap:                        # fn_4000414c
	entry	a1, 48                  # 4000414c
	# return reg_read32(address)
	s32i.n	a2, a1, 0               # 4000414f
	l32i.n	a10, a1, 0              # 40004151
	call8	reg_read32              # 40004153
	mov.n	a2, a10                 # 40004156
	retw.n                          # 40004158
	.size	reg_read32_wrap, . - reg_read32_wrap
