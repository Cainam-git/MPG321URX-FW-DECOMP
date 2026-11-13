# sys_write_78_or_79  (fn_4000a39c): 0x4000a39c-0x4000a3c3 (firmware file offset 0x3a39c-0x3a3c3), 16 instructions
# Name basis: descriptive - code only; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Writes 79 to the word at address 0x15AC when on is not 0, else 78 (the value sys_write_78_and_set_bit7 writes there).
# Nothing in the program calls it.
# a2 = on: byte, selects 79 (not 0) or 78 (0).
# Locals: a1+0 value; a1+16 on.
# Returns: nothing.
# Other literal values: 0x000015ac

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_write_78_or_79, @function
sys_write_78_or_79:                     # fn_4000a39c
	entry	a1, 64                  # 4000a39c
	extui	a2, a2, 0, 8            # 4000a39f
	s8i	a2, a1, 16              # 4000a3a2
	# if (on != 0) value = 79;
	movi.n	a5, 0                   # 4000a3a5
	l8ui	a4, a1, 16              # 4000a3a7
	beq	a4, a5, .L4000a3b4      # 4000a3aa
	movi.n	a5, 79                  # 4000a3ad
	s32i.n	a5, a1, 0               # 4000a3af
	j	.L4000a3b8              # 4000a3b1
.L4000a3b4:
	# else value = 78;
	movi.n	a6, 78                  # 4000a3b4
	s32i.n	a6, a1, 0               # 4000a3b6
.L4000a3b8:
	# *(volatile u32 *)0x15AC = value;
	l32r	a8, lit_3ffe2328        # 4000a3b8  = 0x000015ac
	memw                            # 4000a3bb
	l32i.n	a7, a1, 0               # 4000a3be
	s32i.n	a7, a8, 0               # 4000a3c0
	retw.n                          # 4000a3c2
	.size	sys_write_78_or_79, . - sys_write_78_or_79
