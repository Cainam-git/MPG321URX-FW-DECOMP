# lib_unused_return_zero  (fn_40009a34): 0x40009a34-0x40009a4a (firmware file offset 0x39a34-0x39a4a), 11 instructions
# Name basis: descriptive - code only
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Stores its six argument registers a2..a7 in stack slots a1+0..a1+20, copies slot a1+0 onto itself and returns 0.
# Nothing calls it and no stored word holds its address.
# Arguments: a2..a7, not used beyond being stored.
# Locals: a1+0..a1+20 the stored a2..a7.
# Returns: 0.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_unused_return_zero, @function
lib_unused_return_zero:                 # fn_40009a34
	entry	a1, 64                  # 40009a34
# store a2..a7 in a1+0..a1+20
	s32i.n	a2, a1, 0               # 40009a37
	s32i.n	a3, a1, 4               # 40009a39
	s32i.n	a4, a1, 8               # 40009a3b
	s32i.n	a5, a1, 12              # 40009a3d
	s32i.n	a6, a1, 16              # 40009a3f
	s32i.n	a7, a1, 20              # 40009a41
# slot0 = slot0;
	l32i.n	a11, a1, 0              # 40009a43
	s32i.n	a11, a1, 0              # 40009a45
# return 0;
	movi.n	a2, 0                   # 40009a47
	retw.n                          # 40009a49
	.size	lib_unused_return_zero, . - lib_unused_return_zero
