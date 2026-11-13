# uart_put_hex_word  (fn_4000a010): 0x4000a010-0x4000a088 (firmware file offset 0x3a010-0x3a088), 49 instructions
# Name basis: derived - code; table '0123456789ABCDEF'
# Called from: dbg_cmd_mem, dbg_cmd_mdw, dbg_cmd_wmem, dbg_print_sw_value
# Sends a 32-bit value as 8 upper-case hex digits, highest digit first; each digit is written to 0xE00A0000 after
# waiting for bit 5 of 0xE00A0014 at most 0xFFFFF polls (same wait as uart_putc_timeout). The digits come from
# "0123456789ABCDEF" (ro_3ffe19b0). Callers: dbg_cmd_mem, dbg_cmd_mdw, dbg_cmd_wmem, dbg_print_sw_value
# (dbg_print_sw_value).
# Arguments: a2 value.
# Locals: a1+16 value (argument), a1+0 i (digit index), a1+4 shift, a1+8 digit (character), a1+12 polls.
# Returns: nothing.
# Text loaded: "0123456789ABCDEF\nGot power down command..\n"
# Other literal values: 0xe00a0014, 0x000ffffe, 0xe00a0000

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	uart_put_hex_word, @function
uart_put_hex_word:                      # fn_4000a010
	entry	a1, 64                  # 4000a010
	s32i.n	a2, a1, 16              # 4000a013
# for (i = 0; i < 8; i++) {
	movi.n	a5, 0                   # 4000a015
	s32i.n	a5, a1, 0               # 4000a017
	l32i.n	a4, a1, 0               # 4000a019
	bgei	a4, 8, .L4000a087       # 4000a01b
.L4000a01e:
#   shift = 28 - i * 4;
	l32i.n	a10, a1, 0              # 4000a01e
	slli	a10, a10, 2             # 4000a020
	movi.n	a9, 28                  # 4000a023
	sub	a9, a9, a10             # 4000a025
	s32i.n	a9, a1, 4               # 4000a028
#   digit = "0123456789ABCDEF"[(value >> shift) & 15];
	l32r	a9, lit_3ffe2324        # 4000a02a  = ro_3ffe19b0 "0123456789ABCDEF\nGot power down command..\n"
	l32i.n	a8, a1, 16              # 4000a02d
	l32i.n	a10, a1, 4              # 4000a02f
	ssr	a10                     # 4000a031
	srl	a8, a8                  # 4000a034
	extui	a8, a8, 0, 4            # 4000a037
	add.n	a8, a8, a9              # 4000a03a
	l8ui	a8, a8, 0               # 4000a03c
	s8i	a8, a1, 8               # 4000a03f
#   polls = 0; while (!(reg[0xE00A0014] & 0x20)) { if (++polls > 0xFFFFE) break; }
	movi.n	a7, 0                   # 4000a042
	s32i.n	a7, a1, 12              # 4000a044
	l32r	a6, lit_3ffe2318        # 4000a046  = 0xe00a0014
	memw                            # 4000a049
	l32i.n	a6, a6, 0               # 4000a04c
	bbsi	a6, 5, .L4000a071       # 4000a04e
.L4000a051:
	l32i.n	a13, a1, 12             # 4000a051
	addi.n	a13, a13, 1             # 4000a053
	s32i.n	a13, a1, 12             # 4000a055
	l32i.n	a12, a1, 12             # 4000a057
	l32r	a11, lit_3ffe2320       # 4000a059  = 0x000ffffe
	bltu	a11, a12, .L4000a071    # 4000a05c
	movi.n	a15, 0                  # 4000a05f
	movi.n	a2, 32                  # 4000a061
	l32r	a14, lit_3ffe2318       # 4000a063  = 0xe00a0014
	memw                            # 4000a066
	l32i.n	a14, a14, 0             # 4000a069
	and	a14, a14, a2            # 4000a06b
	beq	a14, a15, .L4000a051    # 4000a06e
.L4000a071:
#   reg[0xE00A0000] = digit;
	l32r	a4, lit_3ffe2300        # 4000a071  = 0xe00a0000
	l8ui	a3, a1, 8               # 4000a074
	memw                            # 4000a077
	s32i.n	a3, a4, 0               # 4000a07a
# }
	l32i.n	a2, a1, 0               # 4000a07c
	addi.n	a2, a2, 1               # 4000a07e
	s32i.n	a2, a1, 0               # 4000a080
	l32i.n	a15, a1, 0              # 4000a082
	blti	a15, 8, .L4000a01e      # 4000a084
.L4000a087:
	retw.n                          # 4000a087
	.size	uart_put_hex_word, . - uart_put_hex_word
