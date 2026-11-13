# lib_swap_byte_order  (fn_40004844): 0x40004844-0x40004883 (firmware file offset 0x34844-0x34883), 27 instructions
# Name basis: proven - code: byte shuffle with mask 0xFF00; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Returns a 32-bit value with its four bytes in reverse order.
# Arguments: a2 x (value).
# Locals: a1+0 r (result).
# Returns: (x >> 24) + ((x >> 8) & 0xFF00) + ((x & 0xFF00) << 8) + ((x & 0xFF) << 24).
# Note: nothing calls it and no word holds its address.
# Other literal values: 0x0000ff00

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_swap_byte_order, @function
lib_swap_byte_order:                    # fn_40004844
	entry	a1, 64                  # 40004844
	s32i.n	a2, a1, 16              # 40004847
	# r = x >> 24
	l32i.n	a10, a1, 16             # 40004849
	extui	a10, a10, 24, 8         # 4000484b
	s32i.n	a10, a1, 0              # 4000484e
	# r += (x >> 8) & 0xFF00
	l32r	a10, lit_3ffe1d3c       # 40004850  = 0x0000ff00
	l32i.n	a9, a1, 16              # 40004853
	srli	a9, a9, 8               # 40004855
	and	a9, a9, a10             # 40004858
	l32i.n	a8, a1, 0               # 4000485b
	add.n	a8, a8, a9              # 4000485d
	s32i.n	a8, a1, 0               # 4000485f
	# r += (x & 0xFF00) << 8
	l32r	a8, lit_3ffe1d3c        # 40004861  = 0x0000ff00
	l32i.n	a7, a1, 16              # 40004864
	and	a7, a7, a8              # 40004866
	slli	a7, a7, 8               # 40004869
	l32i.n	a6, a1, 0               # 4000486c
	add.n	a6, a6, a7              # 4000486e
	s32i.n	a6, a1, 0               # 40004870
	# r += (x & 0xFF) << 24
	l32i.n	a5, a1, 16              # 40004872
	extui	a5, a5, 0, 8            # 40004874
	slli	a5, a5, 24              # 40004877
	l32i.n	a4, a1, 0               # 4000487a
	add.n	a4, a4, a5              # 4000487c
	s32i.n	a4, a1, 0               # 4000487e
	# return r
	l32i.n	a2, a1, 0               # 40004880
	retw.n                          # 40004882
	.size	lib_swap_byte_order, . - lib_swap_byte_order
