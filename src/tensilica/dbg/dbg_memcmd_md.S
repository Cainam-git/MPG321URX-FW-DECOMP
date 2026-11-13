# dbg_memcmd_md  (fn_40003b68): 0x40003b68-0x40003b95 (firmware file offset 0x33b68-0x33b95), 17 instructions
# Name basis: derived - name 'md' in table dbg_memcmd_table; code
# Address stored in the words at: 0x4000d42c
# Calls: lib_copy_next_word, lib_parse_decimal_text
# Addresses loaded: dbg_memcmd_verbose
#
# Handler of the command "md" of the second command console (table dbg_memcmd_table): sets the byte flag
# dbg_memcmd_verbose to the decimal number given. That flag switches the echo of typed characters, the prompt and the
# row addresses and line ends of "mr" on (not 0) or off (0).
# Arguments: a2 = text (rest of the command line), a3 = length.
# Locals: a1+0 = word[80] (current word), a1+80 = text, a1+84 = length.
# Returns: 0.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_memcmd_md, @function
dbg_memcmd_md:                          # fn_40003b68
	entry	a1, 128                 # 40003b68
	s32i	a2, a1, 80              # 40003b6b
	s32i	a3, a1, 84              # 40003b6e
	# if ((text = next_word(text, length, word)) != 0) dbg_memcmd_verbose = parse_dec(word)
	l32i	a10, a1, 80             # 40003b71
	l32i	a11, a1, 84             # 40003b74
	mov.n	a12, a1                 # 40003b77
	call8	lib_copy_next_word      # 40003b79
	s32i	a10, a1, 80             # 40003b7c
	movi.n	a12, 0                  # 40003b7f
	l32i	a11, a1, 80             # 40003b81
	beq	a11, a12, .L40003b92    # 40003b84
	mov.n	a10, a1                 # 40003b87
	call8	lib_parse_decimal_text  # 40003b89
	l32r	a13, lit_3ffe1ce0       # 40003b8c  = dbg_memcmd_verbose
	s8i	a10, a13, 0             # 40003b8f
.L40003b92:
	# return 0
	movi.n	a2, 0                   # 40003b92
	retw.n                          # 40003b94
	.size	dbg_memcmd_md, . - dbg_memcmd_md
