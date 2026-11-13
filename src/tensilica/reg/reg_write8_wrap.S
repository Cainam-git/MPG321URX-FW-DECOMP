# reg_write8_wrap  (fn_40004190): 0x40004190-0x400041a4 (firmware file offset 0x34190-0x341a4), 8 instructions
# Name basis: derived - code: only calls reg_write8; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Writes a byte to an address by calling reg_write8 with the low 8 bits of the value.
# Arguments: a2 address, a3 value (only bits 0..7 are used).
# Locals: a1+0 address, a1+4 value (byte).
# Returns: nothing.
# Note: nothing calls it and no word holds its address.
# Calls: reg_write8

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_write8_wrap, @function
reg_write8_wrap:                        # fn_40004190
	entry	a1, 48                  # 40004190
	# reg_write8(address, (u8)value)
	s32i.n	a2, a1, 0               # 40004193
	extui	a2, a3, 0, 8            # 40004195
	s8i	a2, a1, 4               # 40004198
	l32i.n	a10, a1, 0              # 4000419b
	l8ui	a11, a1, 4              # 4000419d
	call8	reg_write8              # 400041a0
	retw.n                          # 400041a3
	.size	reg_write8_wrap, . - reg_write8_wrap
