# gpio_output_clear_masked  (fn_40008ad8): 0x40008ad8-0x40008af5 (firmware file offset 0x38ad8-0x38af5), 13 instructions
# Name basis: descriptive - wrmsk_expstate(0, 1<<n); no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Clears bit n of the EXPSTATE register with one masked write (wrmsk_expstate value 0, mask 1 << n).
# a2 = n: bit number.
# Locals: a1+16 n, a1+0 value (0), a1+4 mask (1 << n).
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	gpio_output_clear_masked, @function
gpio_output_clear_masked:               # fn_40008ad8
	entry	a1, 64                  # 40008ad8
	s32i.n	a2, a1, 16              # 40008adb
	# value = 0;
	movi.n	a8, 0                   # 40008add
	s32i.n	a8, a1, 0               # 40008adf
	# mask = 1 << n;
	movi.n	a6, 1                   # 40008ae1
	l32i.n	a7, a1, 16              # 40008ae3
	ssl	a7                      # 40008ae5
	sll	a6, a6                  # 40008ae8
	s32i.n	a6, a1, 4               # 40008aeb
	# EXPSTATE = (EXPSTATE & ~mask) | (value & mask);
	l32i.n	a4, a1, 0               # 40008aed
	l32i.n	a5, a1, 4               # 40008aef
	wrmsk_expstate	a4, a5          # 40008af1
	retw.n                          # 40008af4
	.size	gpio_output_clear_masked, . - gpio_output_clear_masked
