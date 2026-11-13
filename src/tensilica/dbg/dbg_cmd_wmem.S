# dbg_cmd_wmem  (fn_40004bcc): 0x40004bcc-0x40004c13 (firmware file offset 0x34bcc-0x34c13), 28 instructions
# Name basis: proven - command table 'wmem'/'mww' + help 'write data to memory', text 'Address Fail'
# Address stored in the words at: 0x4000b36c, 0x4000b3b4
#
# Handler of the debug commands "wmem" and "mww" (help text "wmem [addr] [data]: write data to memory"): prints
# "\n [<addr>] : ", then, when addr is 4-byte aligned, writes data to addr and prints data in 8 hex digits and a
# newline; an unaligned addr prints "Address Fail\n" and writes nothing.
# Arguments: a2 addr (word address), a3 data (value to write), a4 third command word (not used).
# Locals: a1+0 addr, a1+4 data, a1+8 third word.
# Returns: nothing.
# Note: does nothing when addr is 0.
# Calls: dbg_printf, uart_put_hex_word (print 8 hex digits), lib_write_word
# Text loaded: "\n [", "] : ", "Address Fail\n"
# Addresses loaded: ro_3ffe08be ("\n")

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_cmd_wmem, @function
dbg_cmd_wmem:                           # fn_40004bcc
	entry	a1, 48                  # 40004bcc
	s32i.n	a2, a1, 0               # 40004bcf
	s32i.n	a3, a1, 4               # 40004bd1
	s32i.n	a4, a1, 8               # 40004bd3
	# if (addr == 0) return
	movi.n	a8, 0                   # 40004bd5
	l32i.n	a7, a1, 0               # 40004bd7
	bne	a7, a8, .L40004bdf      # 40004bd9
	j	.L40004c12              # 40004bdc
.L40004bdf:
	# dbg_printf("\n ["); print_hex8(addr); dbg_printf("] : ")
	l32r	a10, lit_3ffe1d5c       # 40004bdf  = ro_3ffe08cc "\n ["
	call8	dbg_printf              # 40004be2
	l32i.n	a10, a1, 0              # 40004be5
	call8	uart_put_hex_word       # 40004be7
	l32r	a10, lit_3ffe1d60       # 40004bea  = ro_3ffe08d0 "] : "
	call8	dbg_printf              # 40004bed
	# if (addr & 3) { dbg_printf("Address Fail\n"); return; }
	l32i.n	a12, a1, 0              # 40004bf0
	movi.n	a11, 3                  # 40004bf2
	bnone	a11, a12, .L40004c00    # 40004bf4
	l32r	a10, lit_3ffe1d64       # 40004bf7  = ro_3ffe08d8 "Address Fail\n"
	call8	dbg_printf              # 40004bfa
	j	.L40004c12              # 40004bfd
.L40004c00:
	# lib_write_word(addr, data); print_hex8(data); dbg_printf("\n")
	l32i.n	a10, a1, 0              # 40004c00
	l32i.n	a11, a1, 4              # 40004c02
	call8	lib_write_word          # 40004c04
	l32i.n	a10, a1, 4              # 40004c07
	call8	uart_put_hex_word       # 40004c09
	l32r	a10, lit_3ffe1d54       # 40004c0c  = ro_3ffe08be
	call8	dbg_printf              # 40004c0f
.L40004c12:
	retw.n                          # 40004c12
	.size	dbg_cmd_wmem, . - dbg_cmd_wmem
