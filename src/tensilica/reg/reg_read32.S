# reg_read32  (fn_40003f10): 0x40003f10-0x40003f21 (firmware file offset 0x33f10-0x33f21), 8 instructions
# Name basis: proven - code
# Called from: ldc_post_segment_percent, reg_read32_wrap
#
# Returns the 32-bit word at an address (a volatile read). Used for registers of the dimming block, for example
# 0xE0080370 and 0xE0080700 in ldc_post_segment_percent.
# Arguments: a2 = address.
# Locals: a1+0 = value.
# Returns: the word read.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	reg_read32, @function
reg_read32:                             # fn_40003f10
	entry	a1, 64                  # 40003f10
	# value = *(volatile u32 *)address; return value
	s32i.n	a2, a1, 16              # 40003f13
	l32i.n	a4, a1, 16              # 40003f15
	memw                            # 40003f17
	l32i.n	a4, a4, 0               # 40003f1a
	s32i.n	a4, a1, 0               # 40003f1c
	l32i.n	a2, a1, 0               # 40003f1e
	retw.n                          # 40003f20
	.size	reg_read32, . - reg_read32
