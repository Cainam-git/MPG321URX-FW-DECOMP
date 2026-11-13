# reg_read8_wrap  (fn_40004180): 0x40004180-0x4000418d (firmware file offset 0x34180-0x3418d), 6 instructions
# Name basis: derived - code: only calls reg_read8; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Returns the byte at an address by calling reg_read8 and passing its result on.
# Arguments: a2 address.
# Locals: a1+0 address.
# Returns: the byte read (0..255).
# Note: nothing calls it and no word holds its address.
# Calls: reg_read8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_read8_wrap, @function
reg_read8_wrap:                         # fn_40004180
	entry	a1, 48                  # 40004180
	# return reg_read8(address)
	s32i.n	a2, a1, 0               # 40004183
	l32i.n	a10, a1, 0              # 40004185
	call8	reg_read8               # 40004187
	mov.n	a2, a10                 # 4000418a
	retw.n                          # 4000418c
	.size	reg_read8_wrap, . - reg_read8_wrap
