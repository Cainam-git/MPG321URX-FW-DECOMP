# lib_string_length  (fn_40004758): 0x40004758-0x40004784 (firmware file offset 0x34758-0x34784), 20 instructions
# Name basis: proven - code: counts bytes to the zero; callers dbg parsers
# Called from: dbg_parse_word_number, dbg_split_command_words
#
# Counts the bytes of a zero-terminated text before its terminating zero.
# Arguments: a2 text (zero-terminated byte string).
# Locals: a1+0 n (count).
# Returns: the number of bytes before the zero byte.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_string_length, @function
lib_string_length:                      # fn_40004758
	entry	a1, 64                  # 40004758
	s32i.n	a2, a1, 16              # 4000475b
	# n = 0
	movi.n	a5, 0                   # 4000475d
	s32i.n	a5, a1, 0               # 4000475f
	# while (*text != 0) { n++; text++; }
	movi.n	a5, 0                   # 40004761
	l32i.n	a4, a1, 16              # 40004763
	l8ui	a4, a4, 0               # 40004765
	beq	a4, a5, .L40004781      # 40004768
.L4000476b:
	l32i.n	a8, a1, 0               # 4000476b
	addi.n	a8, a8, 1               # 4000476d
	s32i.n	a8, a1, 0               # 4000476f
	l32i.n	a7, a1, 16              # 40004771
	addi.n	a7, a7, 1               # 40004773
	s32i.n	a7, a1, 16              # 40004775
	movi.n	a7, 0                   # 40004777
	l32i.n	a6, a1, 16              # 40004779
	l8ui	a6, a6, 0               # 4000477b
	bne	a6, a7, .L4000476b      # 4000477e
.L40004781:
	# return n
	l32i.n	a2, a1, 0               # 40004781
	retw.n                          # 40004783
	.size	lib_string_length, . - lib_string_length
