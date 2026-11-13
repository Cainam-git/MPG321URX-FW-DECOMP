# lib_read_word  (fn_4000496c): 0x4000496c-0x4000497a (firmware file offset 0x3496c-0x3497a), 7 instructions
# Name basis: proven - code: plain load; callers debug memory commands
# Called from: dbg_cmd_mem, dbg_cmd_mdw, dbg_run_hex_packet, dbg_run_star_request
#
# Returns the 32-bit word at an address (plain read, no memw). Used by the debug memory commands.
# Arguments: a2 addr.
# Locals: a1+0 value.
# Returns: the word read.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_read_word, @function
lib_read_word:                          # fn_4000496c
	entry	a1, 64                  # 4000496c
	# value = *(u32 *)addr; return value
	s32i.n	a2, a1, 16              # 4000496f
	l32i.n	a4, a1, 16              # 40004971
	l32i.n	a4, a4, 0               # 40004973
	s32i.n	a4, a1, 0               # 40004975
	l32i.n	a2, a1, 0               # 40004977
	retw.n                          # 40004979
	.size	lib_read_word, . - lib_read_word
