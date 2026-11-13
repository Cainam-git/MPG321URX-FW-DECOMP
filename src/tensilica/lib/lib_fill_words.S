# lib_fill_words  (fn_40004664): 0x40004664-0x40004691 (firmware file offset 0x34664-0x34691), 21 instructions
# Name basis: proven - code: dst[i] = value loop; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
#
# Stores one 32-bit value into count consecutive words.
# Arguments: a2 dst (word array), a3 value, a4 count (number of words).
# Locals: a1+0 i (word index).
# Returns: nothing.
# Note: nothing calls it and no word holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_fill_words, @function
lib_fill_words:                         # fn_40004664
	entry	a1, 64                  # 40004664
	s32i.n	a2, a1, 16              # 40004667
	s32i.n	a3, a1, 20              # 40004669
	s32i.n	a4, a1, 24              # 4000466b
	# for (i = 0; i < count; i++)
	movi.n	a9, 0                   # 4000466d
	s32i.n	a9, a1, 0               # 4000466f
	l32i.n	a8, a1, 24              # 40004671
	l32i.n	a7, a1, 0               # 40004673
	bgeu	a7, a8, .L40004690      # 40004675
.L40004678:
	# dst[i] = value
	l32i.n	a14, a1, 0              # 40004678
	l32i.n	a15, a1, 16             # 4000467a
	addx4	a14, a14, a15           # 4000467c
	l32i.n	a13, a1, 20             # 4000467f
	s32i.n	a13, a14, 0             # 40004681
	l32i.n	a12, a1, 0              # 40004683
	addi.n	a12, a12, 1             # 40004685
	s32i.n	a12, a1, 0              # 40004687
	l32i.n	a11, a1, 24             # 40004689
	l32i.n	a10, a1, 0              # 4000468b
	bltu	a10, a11, .L40004678    # 4000468d
.L40004690:
	retw.n                          # 40004690
	.size	lib_fill_words, . - lib_fill_words
