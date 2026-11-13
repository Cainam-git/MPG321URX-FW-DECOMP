# lib_write_word  (fn_4000497c): 0x4000497c-0x4000498a (firmware file offset 0x3497c-0x3498a), 7 instructions
# Name basis: proven - code: plain store; callers debug memory commands
# Called from: dbg_cmd_wmem, dbg_run_hex_packet, dbg_run_star_request
#
# Writes a 32-bit word to an address (plain write, no memw). Used by the debug memory commands.
# Arguments: a2 addr, a3 value.
# Locals: a1+0 addr, a1+4 value.
# Returns: nothing.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_write_word, @function
lib_write_word:                         # fn_4000497c
	entry	a1, 48                  # 4000497c
	# *(u32 *)addr = value
	s32i.n	a2, a1, 0               # 4000497f
	s32i.n	a3, a1, 4               # 40004981
	l32i.n	a6, a1, 0               # 40004983
	l32i.n	a5, a1, 4               # 40004985
	s32i.n	a5, a6, 0               # 40004987
	retw.n                          # 40004989
	.size	lib_write_word, . - lib_write_word
