# gpio_output_toggle  (fn_40008c10): 0x40008c10-0x40008c37 (firmware file offset 0x38c10-0x38c37), 17 instructions
# Name basis: descriptive - rur.expstate, xor, wrmsk_expstate; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Inverts bit n of the EXPSTATE register: reads EXPSTATE, flips bit n, writes it back with mask 1 << n.
# a2 = n: bit number.
# Locals: a1+16 n, a1+0 value (EXPSTATE, then EXPSTATE ^ mask), a1+4 mask (1 << n).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	gpio_output_toggle, @function
gpio_output_toggle:                     # fn_40008c10
	entry	a1, 64                  # 40008c10
	s32i.n	a2, a1, 16              # 40008c13
	# value = EXPSTATE;
	rur.expstate	a10             # 40008c15
	s32i.n	a10, a1, 0              # 40008c18
	# mask = 1 << n;
	movi.n	a8, 1                   # 40008c1a
	l32i.n	a9, a1, 16              # 40008c1c
	ssl	a9                      # 40008c1e
	sll	a8, a8                  # 40008c21
	s32i.n	a8, a1, 4               # 40008c24
	# value = value ^ mask;
	l32i.n	a7, a1, 4               # 40008c26
	l32i.n	a6, a1, 0               # 40008c28
	xor	a6, a6, a7              # 40008c2a
	s32i.n	a6, a1, 0               # 40008c2d
	# EXPSTATE = (EXPSTATE & ~mask) | (value & mask);
	l32i.n	a4, a1, 0               # 40008c2f
	l32i.n	a5, a1, 4               # 40008c31
	wrmsk_expstate	a4, a5          # 40008c33
	retw.n                          # 40008c36
	.size	gpio_output_toggle, . - gpio_output_toggle
