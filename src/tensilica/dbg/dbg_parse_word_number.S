# dbg_parse_word_number  (fn_40004c14): 0x40004c14-0x40004df8 (firmware file offset 0x34c14-0x34df8), 205 instructions
# Name basis: derived - code; called for words 1..3 by dbg_find_and_run_command
# Called from: dbg_find_and_run_command
#
# Converts one 32-byte word of a typed debug command into a number. The word is first cut at its first "\n",
# "\r" or zero byte (at most at index 31). A word starting with "0x" or "0X" is read as hexadecimal up to the
# first space or tab; any other word is read as decimal.
# Arguments: a2 s (word text, 32 bytes).
# Locals: a1+0 i (index), a1+4 wp (word that receives the cut), a1+8 len (lib_string_length(s)), a1+12 value,
#   a1+16 result.
# Returns: 0 when s is 0; the number; -1 for a decimal word longer than 9 characters.
# Note: the cut clears byte (i & 3) of the 32-bit word at s + (i & 0xFC) * 4, which is byte i of s only for
#   i < 4. In hexadecimal, characters other than 0-9, a-f, A-F shift the value by 4 bits and add nothing; in
#   decimal, every character adds (c - '0') without a check.
# Calls: lib_string_length

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_parse_word_number, @function
dbg_parse_word_number:                  # fn_40004c14
	entry	a1, 80                  # 40004c14
	s32i.n	a2, a1, 32              # 40004c17
	# if (s == 0) { result = 0; goto out; }
	movi.n	a5, 0                   # 40004c19
	l32i.n	a4, a1, 32              # 40004c1b
	bne	a4, a5, .L40004c27      # 40004c1d
	movi.n	a5, 0                   # 40004c20
	s32i.n	a5, a1, 16              # 40004c22
	j	.L40004df5              # 40004c24
.L40004c27:
	# for (i = 0; i <= 31; i++) if (s[i] == '\n' || s[i] == '\r' || s[i] == 0) break
	movi.n	a8, 0                   # 40004c27
	s32i.n	a8, a1, 0               # 40004c29
	l32i.n	a7, a1, 0               # 40004c2b
	movi.n	a6, 31                  # 40004c2d
	blt	a6, a7, .L40004c67      # 40004c2f
.L40004c32:
	l32i.n	a10, a1, 0              # 40004c32
	l32i.n	a9, a1, 32              # 40004c34
	add.n	a9, a9, a10             # 40004c36
	l8ui	a9, a9, 0               # 40004c38
	beqi	a9, 10, .L40004c67      # 40004c3b
	movi.n	a11, 13                 # 40004c3e
	l32i.n	a12, a1, 0              # 40004c40
	l32i.n	a10, a1, 32             # 40004c42
	add.n	a10, a10, a12           # 40004c44
	l8ui	a10, a10, 0             # 40004c46
	beq	a10, a11, .L40004c67    # 40004c49
	movi.n	a12, 0                  # 40004c4c
	l32i.n	a13, a1, 0              # 40004c4e
	l32i.n	a11, a1, 32             # 40004c50
	add.n	a11, a11, a13           # 40004c52
	l8ui	a11, a11, 0             # 40004c54
	beq	a11, a12, .L40004c67    # 40004c57
	l32i.n	a14, a1, 0              # 40004c5a
	addi.n	a14, a14, 1             # 40004c5c
	s32i.n	a14, a1, 0              # 40004c5e
	l32i.n	a13, a1, 0              # 40004c60
	movi.n	a12, 31                 # 40004c62
	bge	a12, a13, .L40004c32    # 40004c64
.L40004c67:
	# if (i == 32) i--
	l32i.n	a15, a1, 0              # 40004c67
	bnei	a15, 32, .L40004c72     # 40004c69
	l32i.n	a2, a1, 0               # 40004c6c
	addi.n	a2, a2, -1              # 40004c6e
	s32i.n	a2, a1, 0               # 40004c70
.L40004c72:
	# wp = (u32 *)s + (i & 0xFC); *wp &= ~(0xFF << ((i & 3) * 8))
	movi	a3, 252                 # 40004c72
	l32i.n	a2, a1, 0               # 40004c75
	and	a2, a2, a3              # 40004c77
	l32i.n	a3, a1, 32              # 40004c7a
	addx4	a2, a2, a3              # 40004c7c
	s32i.n	a2, a1, 4               # 40004c7f
	l32i.n	a15, a1, 0              # 40004c81
	extui	a15, a15, 0, 2          # 40004c83
	l32i.n	a12, a1, 4              # 40004c86
	movi.n	a14, -1                 # 40004c88
	movi	a13, 255                # 40004c8a
	slli	a15, a15, 3             # 40004c8d
	ssl	a15                     # 40004c90
	sll	a13, a13                # 40004c93
	xor	a13, a13, a14           # 40004c96
	l32i.n	a11, a1, 4              # 40004c99
	l32i.n	a11, a11, 0             # 40004c9b
	and	a11, a11, a13           # 40004c9d
	s32i.n	a11, a12, 0             # 40004ca0
	# len = lib_string_length(s); value = 0
	l32i.n	a10, a1, 32             # 40004ca2
	call8	lib_string_length       # 40004ca4
	s32i.n	a10, a1, 8              # 40004ca7
	movi.n	a5, 0                   # 40004ca9
	s32i.n	a5, a1, 12              # 40004cab
	# if (s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
	movi.n	a5, 48                  # 40004cad
	l32i.n	a4, a1, 32              # 40004caf
	l8ui	a4, a4, 0               # 40004cb1
	beq	a4, a5, .L40004cba      # 40004cb4
	j	.L40004db0              # 40004cb7
.L40004cba:
	movi.n	a7, 88                  # 40004cba
	l32i.n	a6, a1, 32              # 40004cbc
	l8ui	a6, a6, 1               # 40004cbe
	beq	a6, a7, .L40004cd2      # 40004cc1
	movi	a8, 120                 # 40004cc4
	l32i.n	a7, a1, 32              # 40004cc7
	l8ui	a7, a7, 1               # 40004cc9
	beq	a7, a8, .L40004cd2      # 40004ccc
	j	.L40004db0              # 40004ccf
.L40004cd2:
	# for (i = 2; i < len; i++) {
	movi.n	a10, 2                  # 40004cd2
	s32i.n	a10, a1, 0              # 40004cd4
	l32i.n	a9, a1, 8               # 40004cd6
	l32i.n	a8, a1, 0               # 40004cd8
	blt	a8, a9, .L40004ce0      # 40004cda
	j	.L40004da9              # 40004cdd
.L40004ce0:
	# if (s[i] == ' ') break
	l32i.n	a12, a1, 0              # 40004ce0
	l32i.n	a11, a1, 32             # 40004ce2
	add.n	a11, a11, a12           # 40004ce4
	l8ui	a11, a11, 0             # 40004ce6
	bnei	a11, 32, .L40004cef     # 40004ce9
	j	.L40004da9              # 40004cec
.L40004cef:
	# if (s[i] == '\t') break
	movi.n	a13, 9                  # 40004cef
	l32i.n	a14, a1, 0              # 40004cf1
	l32i.n	a12, a1, 32             # 40004cf3
	add.n	a12, a12, a14           # 40004cf5
	l8ui	a12, a12, 0             # 40004cf7
	bne	a12, a13, .L40004d00    # 40004cfa
	j	.L40004da9              # 40004cfd
.L40004d00:
	# value <<= 4
	l32i.n	a15, a1, 12             # 40004d00
	slli	a15, a15, 4             # 40004d02
	s32i.n	a15, a1, 12             # 40004d05
	# if (s[i] >= '0' && s[i] <= '9') value += s[i] - '0'
	l32i.n	a15, a1, 0              # 40004d07
	l32i.n	a14, a1, 32             # 40004d09
	add.n	a14, a14, a15           # 40004d0b
	l8ui	a14, a14, 0             # 40004d0d
	movi.n	a13, 47                 # 40004d10
	bgeu	a13, a14, .L40004d38    # 40004d12
	l32i.n	a4, a1, 0               # 40004d15
	l32i.n	a3, a1, 32              # 40004d17
	add.n	a3, a3, a4              # 40004d19
	l8ui	a3, a3, 0               # 40004d1b
	movi.n	a2, 57                  # 40004d1e
	bltu	a2, a3, .L40004d38      # 40004d20
	l32i.n	a5, a1, 12              # 40004d23
	l32i.n	a6, a1, 0               # 40004d25
	l32i.n	a4, a1, 32              # 40004d27
	add.n	a4, a4, a6              # 40004d29
	l8ui	a4, a4, 0               # 40004d2b
	add.n	a4, a4, a5              # 40004d2e
	addi	a4, a4, -48             # 40004d30
	s32i.n	a4, a1, 12              # 40004d33
	j	.L40004d99              # 40004d35
.L40004d38:
	# else if (s[i] >= 'a' && s[i] <= 'f') value += s[i] - 'a' + 10
	l32i.n	a7, a1, 0               # 40004d38
	l32i.n	a6, a1, 32              # 40004d3a
	add.n	a6, a6, a7              # 40004d3c
	l8ui	a6, a6, 0               # 40004d3e
	movi	a5, 96                  # 40004d41
	bgeu	a5, a6, .L40004d6b      # 40004d44
	l32i.n	a9, a1, 0               # 40004d47
	l32i.n	a8, a1, 32              # 40004d49
	add.n	a8, a8, a9              # 40004d4b
	l8ui	a8, a8, 0               # 40004d4d
	movi	a7, 102                 # 40004d50
	bltu	a7, a8, .L40004d6b      # 40004d53
	l32i.n	a10, a1, 12             # 40004d56
	l32i.n	a11, a1, 0              # 40004d58
	l32i.n	a9, a1, 32              # 40004d5a
	add.n	a9, a9, a11             # 40004d5c
	l8ui	a9, a9, 0               # 40004d5e
	add.n	a9, a9, a10             # 40004d61
	addi	a9, a9, -87             # 40004d63
	s32i.n	a9, a1, 12              # 40004d66
	j	.L40004d99              # 40004d68
.L40004d6b:
	# else if (s[i] >= 'A' && s[i] <= 'F') value += s[i] - 'A' + 10
	l32i.n	a12, a1, 0              # 40004d6b
	l32i.n	a11, a1, 32             # 40004d6d
	add.n	a11, a11, a12           # 40004d6f
	l8ui	a11, a11, 0             # 40004d71
	movi.n	a10, 64                 # 40004d74
	bgeu	a10, a11, .L40004d99    # 40004d76
	l32i.n	a14, a1, 0              # 40004d79
	l32i.n	a13, a1, 32             # 40004d7b
	add.n	a13, a13, a14           # 40004d7d
	l8ui	a13, a13, 0             # 40004d7f
	movi.n	a12, 70                 # 40004d82
	bltu	a12, a13, .L40004d99    # 40004d84
	l32i.n	a15, a1, 12             # 40004d87
	l32i.n	a2, a1, 0               # 40004d89
	l32i.n	a14, a1, 32             # 40004d8b
	add.n	a14, a14, a2            # 40004d8d
	l8ui	a14, a14, 0             # 40004d8f
	add.n	a14, a14, a15           # 40004d92
	addi	a14, a14, -55           # 40004d94
	s32i.n	a14, a1, 12             # 40004d97
.L40004d99:
	# }   /* i++ */
	l32i.n	a3, a1, 0               # 40004d99
	addi.n	a3, a3, 1               # 40004d9b
	s32i.n	a3, a1, 0               # 40004d9d
	l32i.n	a2, a1, 8               # 40004d9f
	l32i.n	a15, a1, 0              # 40004da1
	bge	a15, a2, .L40004da9     # 40004da3
	j	.L40004ce0              # 40004da6
.L40004da9:
	# result = value; goto out; }
	l32i.n	a4, a1, 12              # 40004da9
	s32i.n	a4, a1, 16              # 40004dab
	j	.L40004df5              # 40004dad
.L40004db0:
	# if (len > 9) { result = -1; goto out; }
	l32i.n	a6, a1, 8               # 40004db0
	movi.n	a5, 9                   # 40004db2
	bge	a5, a6, .L40004dbe      # 40004db4
	movi.n	a7, -1                  # 40004db7
	s32i.n	a7, a1, 16              # 40004db9
	j	.L40004df5              # 40004dbb
.L40004dbe:
	# for (i = 0; i < len; i++) value = value * 10 + s[i] - '0'
	movi.n	a10, 0                  # 40004dbe
	s32i.n	a10, a1, 0              # 40004dc0
	l32i.n	a9, a1, 8               # 40004dc2
	l32i.n	a8, a1, 0               # 40004dc4
	bge	a8, a9, .L40004dee      # 40004dc6
.L40004dc9:
	l32i.n	a14, a1, 12             # 40004dc9
	l32i.n	a15, a1, 12             # 40004dcb
	addx4	a14, a14, a15           # 40004dcd
	l32i.n	a2, a1, 0               # 40004dd0
	l32i.n	a15, a1, 32             # 40004dd2
	add.n	a15, a15, a2            # 40004dd4
	l8ui	a15, a15, 0             # 40004dd6
	addx2	a14, a14, a15           # 40004dd9
	addi	a14, a14, -48           # 40004ddc
	s32i.n	a14, a1, 12             # 40004ddf
	l32i.n	a13, a1, 0              # 40004de1
	addi.n	a13, a13, 1             # 40004de3
	s32i.n	a13, a1, 0              # 40004de5
	l32i.n	a12, a1, 8              # 40004de7
	l32i.n	a11, a1, 0              # 40004de9
	blt	a11, a12, .L40004dc9    # 40004deb
.L40004dee:
	# result = value
	l32i.n	a2, a1, 12              # 40004dee
	s32i.n	a2, a1, 16              # 40004df0
	j	.L40004df5              # 40004df2
.L40004df5:
	# out: return result
	l32i.n	a2, a1, 16              # 40004df5
	retw.n                          # 40004df7
	.size	dbg_parse_word_number, . - dbg_parse_word_number
