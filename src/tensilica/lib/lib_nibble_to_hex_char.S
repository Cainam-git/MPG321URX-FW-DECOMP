# lib_nibble_to_hex_char  (fn_40005424): 0x40005424-0x4000545f (firmware file offset 0x35424-0x3545f), 21 instructions
# Name basis: proven - code: +48 / +55
# Called from: lib_format_hex_word
# Converts a value 0-15 to its upper-case hex digit character.
# Arguments: a2 n (value, as a byte).
# Locals: a1+0 ch (result), a1+16 n.
# Returns: '0'-'9' or 'A'-'F'; '0' for a value above 15.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_nibble_to_hex_char, @function
lib_nibble_to_hex_char:                 # fn_40005424
	entry	a1, 64                  # 40005424
	extui	a2, a2, 0, 8            # 40005427
	s8i	a2, a1, 16              # 4000542a
	# if (n <= 9) ch = n + '0';
	l8ui	a5, a1, 16              # 4000542d
	movi.n	a4, 9                   # 40005430
	bltu	a4, a5, .L40005441      # 40005432
	l8ui	a6, a1, 16              # 40005435
	addi	a6, a6, 48              # 40005438
	s8i	a6, a1, 0               # 4000543b
	j	.L4000545b              # 4000543e
.L40005441:
	# else if (n - 10 < 6) ch = n + 55;
	l8ui	a7, a1, 16              # 40005441
	addi	a7, a7, -10             # 40005444
	bgeui	a7, 6, .L40005456       # 40005447
	l8ui	a8, a1, 16              # 4000544a
	addi	a8, a8, 55              # 4000544d
	s8i	a8, a1, 0               # 40005450
	j	.L4000545b              # 40005453
.L40005456:
	# else ch = '0';
	movi.n	a9, 48                  # 40005456
	s8i	a9, a1, 0               # 40005458
.L4000545b:
	# return ch;
	l8ui	a2, a1, 0               # 4000545b
	retw.n                          # 4000545e
	.size	lib_nibble_to_hex_char, . - lib_nibble_to_hex_char
