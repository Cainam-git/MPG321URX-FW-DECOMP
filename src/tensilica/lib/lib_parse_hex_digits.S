# lib_parse_hex_digits  (fn_40005460): 0x40005460-0x400054a1 (firmware file offset 0x35460-0x354a1), 29 instructions
# Name basis: proven - code: v = v*16 + digit for n characters
# Called from: dbg_parse_star_request
# Reads a fixed number of hex digit characters and returns the number they form (first digit most significant).
# Arguments: a2 text (first digit), a3 n (number of digits).
# Locals: a1+0 v (result), a1+4 i, a1+8 d (digit value).
# Returns: the value; characters that are not hex digits count as 0.
# Calls: lib_hex_digit_value

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_parse_hex_digits, @function
lib_parse_hex_digits:                   # fn_40005460
	entry	a1, 64                  # 40005460
	s32i.n	a2, a1, 16              # 40005463
	s32i.n	a3, a1, 20              # 40005465
	# v = 0;
	movi.n	a8, 0                   # 40005467
	s32i.n	a8, a1, 0               # 40005469
	# for (i = 0; i < n; i++) {
	movi.n	a7, 0                   # 4000546b
	s32i.n	a7, a1, 4               # 4000546d
	l32i.n	a6, a1, 20              # 4000546f
	l32i.n	a5, a1, 4               # 40005471
	bge	a5, a6, .L4000549e      # 40005473
.L40005476:
	# d = lib_hex_digit_value(text[i]);
	l32i.n	a11, a1, 4              # 40005476
	l32i.n	a10, a1, 16             # 40005478
	add.n	a10, a10, a11           # 4000547a
	l8ui	a10, a10, 0             # 4000547c
	call8	lib_hex_digit_value     # 4000547f
	s8i	a10, a1, 8              # 40005482
	# v = (v << 4) + d;
	l32i.n	a15, a1, 0              # 40005485
	slli	a15, a15, 4             # 40005487
	l8ui	a14, a1, 8              # 4000548a
	add.n	a14, a14, a15           # 4000548d
	s32i.n	a14, a1, 0              # 4000548f
	# }
	l32i.n	a13, a1, 4              # 40005491
	addi.n	a13, a13, 1             # 40005493
	s32i.n	a13, a1, 4              # 40005495
	l32i.n	a12, a1, 20             # 40005497
	l32i.n	a11, a1, 4              # 40005499
	blt	a11, a12, .L40005476    # 4000549b
.L4000549e:
	# return v;
	l32i.n	a2, a1, 0               # 4000549e
	retw.n                          # 400054a0
	.size	lib_parse_hex_digits, . - lib_parse_hex_digits
