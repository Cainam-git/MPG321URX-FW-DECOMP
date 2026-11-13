# dbg_run_hex_packet  (fn_40005050): 0x40005050-0x400053cd (firmware file offset 0x35050-0x353cd), 349 instructions
# Name basis: derived - op chars R/U/W, hex byte parsing, reads/writes via lib_read_word/lib_write_word
# Called from: dbg_console_poll
# Runs a '^' hex packet collected by dbg_console_poll. The first character of the line is the operation, the rest are
# pairs of hex digits (space or ',' allowed between pairs) that become up to 32 bytes in pkt[] (0x3ffe43f0).
# Bytes 0-3 are an address (most significant byte first). 'R'/'r' with 4 bytes reads the word at the address,
# 'W'/'w' with 8 bytes writes bytes 4-7 to it, 'U'/'u' with 12 bytes writes bytes 4-7 under the mask in bytes 8-11.
# The reply is printed as a string in pkt[]: 0x83, for a read eight bytes 0x90 + nibble (most significant nibble
# first), then 0x8F; any other case prints 0x82 0x8F.
# Arguments: a2 len (line length in characters, as a byte).
# Locals: a1+0 op (line[0]; 0xFF after a format error), a1+1 half (1 while a high nibble waits for its low nibble),
#   a1+2 hi (that high nibble), a1+4 count (bytes stored in pkt[]), a1+8 i, a1+12 c (character, then its value),
#   a1+16 addr, a1+20 value, a1+24 mask, a1+28 / a1+36 switch copies of op, a1+32 replied, a1+40 tmp,
#   a1+48 len.
# Returns: nothing.
# Calls: lib_read_word, dbg_printf, lib_write_word
# Other literal values: 0x3ffe42f0, 0x3ffe43f0, 0x3ffe43f9, 0x3ffe43fa, 0x3ffe43f1, 0x3ffe43f2

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_run_hex_packet, @function
dbg_run_hex_packet:                     # fn_40005050
	entry	a1, 96                  # 40005050
	extui	a2, a2, 0, 8            # 40005053
	s8i	a2, a1, 48              # 40005056
	# op = con.line[0]; half = 0; hi = 0; count = 0;
	l32r	a10, lit_3ffe1d84       # 40005059  = 0x3ffe42f0
	l8ui	a10, a10, 0             # 4000505c
	s8i	a10, a1, 0              # 4000505f
	movi.n	a9, 0                   # 40005062
	s8i	a9, a1, 1               # 40005064
	movi.n	a8, 0                   # 40005067
	s8i	a8, a1, 2               # 40005069
	movi.n	a7, 0                   # 4000506c
	s32i.n	a7, a1, 4               # 4000506e
	# for (i = 1; i < len; i++) {
	movi.n	a6, 1                   # 40005070
	s32i.n	a6, a1, 8               # 40005072
	l8ui	a5, a1, 48              # 40005074
	l32i.n	a4, a1, 8               # 40005077
	bltu	a4, a5, .L4000507f      # 40005079
	j	.L4000515a              # 4000507c
.L4000507f:
	# c = con.line[i];
	l32r	a13, lit_3ffe1d84       # 4000507f  = 0x3ffe42f0
	l32i.n	a12, a1, 8              # 40005082
	add.n	a12, a12, a13           # 40005084
	l8ui	a12, a12, 0             # 40005086
	s8i	a12, a1, 12             # 40005089
	# if (c - 'a' < 6) c -= 87;   /* 'a'..'f' -> 10..15 */
	l8ui	a11, a1, 12             # 4000508c
	addi	a11, a11, -97           # 4000508f
	bgeui	a11, 6, .L400050a1      # 40005092
	l8ui	a14, a1, 12             # 40005095
	addi	a14, a14, -87           # 40005098
	s8i	a14, a1, 12             # 4000509b
	j	.L400050fd              # 4000509e
.L400050a1:
	# else if (c - 'A' < 6) c -= 55;
	l8ui	a15, a1, 12             # 400050a1
	addi	a15, a15, -65           # 400050a4
	bgeui	a15, 6, .L400050b6      # 400050a7
	l8ui	a2, a1, 12              # 400050aa
	addi	a2, a2, -55             # 400050ad
	s8i	a2, a1, 12              # 400050b0
	j	.L400050fd              # 400050b3
.L400050b6:
	# else if (c - '0' <= 9) c -= '0';
	l8ui	a4, a1, 12              # 400050b6
	addi	a4, a4, -48             # 400050b9
	movi.n	a3, 9                   # 400050bc
	bltu	a3, a4, .L400050cd      # 400050be
	l8ui	a5, a1, 12              # 400050c1
	addi	a5, a5, -48             # 400050c4
	s8i	a5, a1, 12              # 400050c7
	j	.L400050fd              # 400050ca
.L400050cd:
	# else if (c == ' ' || c == ',') {
	l8ui	a6, a1, 12              # 400050cd
	beqi	a6, 32, .L400050db      # 400050d0
	movi.n	a8, 44                  # 400050d3
	l8ui	a7, a1, 12              # 400050d5
	bne	a7, a8, .L400050f4      # 400050d8
.L400050db:
	# if (half != 0) { op = 0xFF; break; }   /* separator inside a byte */
	movi.n	a10, 0                  # 400050db
	l8ui	a9, a1, 1               # 400050dd
	beq	a9, a10, .L400050ec     # 400050e0
	movi	a11, 255                # 400050e3
	s8i	a11, a1, 0              # 400050e6
	j	.L4000515a              # 400050e9
.L400050ec:
	# hi = 0; continue;
	movi.n	a12, 0                  # 400050ec
	s8i	a12, a1, 2              # 400050ee
	j	.L40005149              # 400050f1
.L400050f4:
	# } else { op = 0xFF; break; }
	movi	a13, 255                # 400050f4
	s8i	a13, a1, 0              # 400050f7
	j	.L4000515a              # 400050fa
.L400050fd:
	# if (half == 0) { half = 1; hi = c; }
	movi.n	a15, 0                  # 400050fd
	l8ui	a14, a1, 1              # 400050ff
	bne	a14, a15, .L40005113    # 40005102
	movi.n	a3, 1                   # 40005105
	s8i	a3, a1, 1               # 40005107
	l8ui	a2, a1, 12              # 4000510a
	s8i	a2, a1, 2               # 4000510d
	j	.L40005149              # 40005110
.L40005113:
	# else { half = 0; if (count <= 31) { pkt[count] = hi * 16 + c; count++; }
	movi.n	a6, 0                   # 40005113
	s8i	a6, a1, 1               # 40005115
	l32i.n	a5, a1, 4               # 40005118
	movi.n	a4, 31                  # 4000511a
	bltu	a4, a5, .L40005140      # 4000511c
	l32i.n	a7, a1, 4               # 4000511f
	l32r	a10, lit_3ffe1d88       # 40005121  = 0x3ffe43f0
	l32i.n	a9, a1, 4               # 40005124
	add.n	a9, a9, a10             # 40005126
	l8ui	a10, a1, 2              # 40005128
	slli	a10, a10, 4             # 4000512b
	l8ui	a8, a1, 12              # 4000512e
	add.n	a8, a8, a10             # 40005131
	sext	a8, a8, 7               # 40005133
	s8i	a8, a9, 0               # 40005136
	addi.n	a7, a7, 1               # 40005139
	s32i.n	a7, a1, 4               # 4000513b
	j	.L40005149              # 4000513d
.L40005140:
	# else { op = 0xFF; break; } }
	movi	a11, 255                # 40005140
	s8i	a11, a1, 0              # 40005143
	j	.L4000515a              # 40005146
.L40005149:
	# }   /* end for */
	l32i.n	a14, a1, 8              # 40005149
	addi.n	a14, a14, 1             # 4000514b
	s32i.n	a14, a1, 8              # 4000514d
	l8ui	a13, a1, 48             # 4000514f
	l32i.n	a12, a1, 8              # 40005152
	bgeu	a12, a13, .L4000515a    # 40005154
	j	.L4000507f              # 40005157
.L4000515a:
	# if (half != 0 && count <= 31) op = 0xFF;   /* odd number of digits */
	movi.n	a2, 0                   # 4000515a
	l8ui	a15, a1, 1              # 4000515c
	beq	a15, a2, .L4000516f     # 4000515f
	l32i.n	a4, a1, 4               # 40005162
	movi.n	a3, 31                  # 40005164
	bltu	a3, a4, .L4000516f      # 40005166
	movi	a5, 255                 # 40005169
	s8i	a5, a1, 0               # 4000516c
.L4000516f:
	# addr = 0; value = 0; mask = 0;
	movi.n	a11, 0                  # 4000516f
	s32i.n	a11, a1, 16             # 40005171
	movi.n	a10, 0                  # 40005173
	s32i.n	a10, a1, 20             # 40005175
	movi.n	a9, 0                   # 40005177
	s32i.n	a9, a1, 24              # 40005179
	# if (op == 'R' || op == 'U' || op == 'W' || op == 'r' || op == 'u' || op == 'w')
	l8ui	a8, a1, 0               # 4000517b
	s32i.n	a8, a1, 28              # 4000517e
	movi.n	a7, 82                  # 40005180
	l32i.n	a6, a1, 28              # 40005182
	beq	a6, a7, .L400051b0      # 40005184
	movi.n	a13, 85                 # 40005187
	l32i.n	a12, a1, 28             # 40005189
	beq	a12, a13, .L400051b0    # 4000518b
	movi.n	a15, 87                 # 4000518e
	l32i.n	a14, a1, 28             # 40005190
	beq	a14, a15, .L400051b0    # 40005192
	movi	a3, 114                 # 40005195
	l32i.n	a2, a1, 28              # 40005198
	beq	a2, a3, .L400051b0      # 4000519a
	movi	a5, 117                 # 4000519d
	l32i.n	a4, a1, 28              # 400051a0
	beq	a4, a5, .L400051b0      # 400051a2
	movi	a7, 119                 # 400051a5
	l32i.n	a6, a1, 28              # 400051a8
	beq	a6, a7, .L400051b0      # 400051aa
	j	.L400051da              # 400051ad
.L400051b0:
	# for (i = 0; i < 4; i++) addr = (addr << 8) + pkt[i];
	movi.n	a9, 0                   # 400051b0
	s32i.n	a9, a1, 8               # 400051b2
	l32i.n	a8, a1, 8               # 400051b4
	bgeui	a8, 4, .L400051d7       # 400051b6
.L400051b9:
	l32i.n	a13, a1, 16             # 400051b9
	slli	a13, a13, 8             # 400051bb
	l32r	a14, lit_3ffe1d88       # 400051be  = 0x3ffe43f0
	l32i.n	a12, a1, 8              # 400051c1
	add.n	a12, a12, a14           # 400051c3
	l8ui	a12, a12, 0             # 400051c5
	add.n	a12, a12, a13           # 400051c8
	s32i.n	a12, a1, 16             # 400051ca
	l32i.n	a11, a1, 8              # 400051cc
	addi.n	a11, a11, 1             # 400051ce
	s32i.n	a11, a1, 8              # 400051d0
	l32i.n	a10, a1, 8              # 400051d2
	bltui	a10, 4, .L400051b9      # 400051d4
.L400051d7:
	j	.L400051dd              # 400051d7
.L400051da:
	j	.L400051dd              # 400051da
.L400051dd:
	# replied = 0;
	# switch (op) {
	movi.n	a3, 0                   # 400051dd
	s8i	a3, a1, 32              # 400051df
	l8ui	a2, a1, 0               # 400051e2
	s32i.n	a2, a1, 36              # 400051e5
	movi.n	a15, 82                 # 400051e7
	l32i.n	a14, a1, 36             # 400051e9
	beq	a14, a15, .L40005223    # 400051eb
	movi	a5, 114                 # 400051ee
	l32i.n	a4, a1, 36              # 400051f1
	beq	a4, a5, .L40005223      # 400051f3
	movi.n	a7, 85                  # 400051f6
	l32i.n	a6, a1, 36              # 400051f8
	bne	a6, a7, .L40005200      # 400051fa
	j	.L4000529a              # 400051fd
.L40005200:
	movi	a9, 117                 # 40005200
	l32i.n	a8, a1, 36              # 40005203
	bne	a8, a9, .L4000520b      # 40005205
	j	.L4000529a              # 40005208
.L4000520b:
	movi.n	a11, 87                 # 4000520b
	l32i.n	a10, a1, 36             # 4000520d
	bne	a10, a11, .L40005215    # 4000520f
	j	.L40005346              # 40005212
.L40005215:
	movi	a13, 119                # 40005215
	l32i.n	a12, a1, 36             # 40005218
	bne	a12, a13, .L40005220    # 4000521a
	j	.L40005346              # 4000521d
.L40005220:
	j	.L400053a1              # 40005220
.L40005223:
	# case 'R': case 'r': if (count != 4) break;
	l32i.n	a14, a1, 4              # 40005223
	beqi	a14, 4, .L4000522b      # 40005225
	j	.L400053a4              # 40005228
.L4000522b:
	# value = lib_read_word(addr);   /* read the word at addr */
	l32i.n	a10, a1, 16             # 4000522b
	call8	lib_read_word           # 4000522d
	s32i.n	a10, a1, 20             # 40005230
	# pkt[0] = 0x83;
	l32r	a5, lit_3ffe1d88        # 40005232  = 0x3ffe43f0
	movi	a4, 131                 # 40005235
	s8i	a4, a5, 0               # 40005238
	# for (i = 1; i <= 8; i++) {
	movi.n	a3, 1                   # 4000523b
	s32i.n	a3, a1, 8               # 4000523d
	l32i.n	a2, a1, 8               # 4000523f
	movi.n	a15, 8                  # 40005241
	bltu	a15, a2, .L4000527b     # 40005243
.L40005246:
	# tmp = (value >> (32 - 4 * i)) & 0xF;
	l32i.n	a12, a1, 20             # 40005246
	l32i.n	a14, a1, 8              # 40005248
	slli	a14, a14, 2             # 4000524a
	movi.n	a13, 32                 # 4000524d
	sub	a13, a13, a14           # 4000524f
	ssr	a13                     # 40005252
	srl	a12, a12                # 40005255
	extui	a12, a12, 0, 4          # 40005258
	s32i.n	a12, a1, 40             # 4000525b
	# pkt[i] = 0x90 + tmp; }
	l32r	a11, lit_3ffe1d88       # 4000525d  = 0x3ffe43f0
	l32i.n	a10, a1, 8              # 40005260
	add.n	a10, a10, a11           # 40005262
	movi	a11, 144                # 40005264
	l32i.n	a9, a1, 40              # 40005267
	add.n	a9, a9, a11             # 40005269
	s8i	a9, a10, 0              # 4000526b
	l32i.n	a8, a1, 8               # 4000526e
	addi.n	a8, a8, 1               # 40005270
	s32i.n	a8, a1, 8               # 40005272
	l32i.n	a7, a1, 8               # 40005274
	movi.n	a6, 8                   # 40005276
	bgeu	a6, a7, .L40005246      # 40005278
.L4000527b:
	# pkt[9] = 0x8F; pkt[10] = 0;
	l32r	a4, lit_3ffe1d8c        # 4000527b  = 0x3ffe43f9
	movi	a3, 143                 # 4000527e
	s8i	a3, a4, 0               # 40005281
	l32r	a2, lit_3ffe1d90        # 40005284  = 0x3ffe43fa
	movi.n	a15, 0                  # 40005287
	s8i	a15, a2, 0              # 40005289
	# printf(pkt); replied = 1; break;
	l32r	a10, lit_3ffe1d88       # 4000528c  = 0x3ffe43f0
	call8	dbg_printf              # 4000528f
	movi.n	a5, 1                   # 40005292
	s8i	a5, a1, 32              # 40005294
	j	.L400053a4              # 40005297
.L4000529a:
	# case 'U': case 'u': if (count != 12) break;
	l32i.n	a6, a1, 4               # 4000529a
	beqi	a6, 12, .L400052a2      # 4000529c
	j	.L400053a4              # 4000529f
.L400052a2:
	# for (i = 4; i < 8; i++) value = (value << 8) + pkt[i];
	movi.n	a8, 4                   # 400052a2
	s32i.n	a8, a1, 8               # 400052a4
	l32i.n	a7, a1, 8               # 400052a6
	bgeui	a7, 8, .L400052c9       # 400052a8
.L400052ab:
	l32i.n	a12, a1, 20             # 400052ab
	slli	a12, a12, 8             # 400052ad
	l32r	a13, lit_3ffe1d88       # 400052b0  = 0x3ffe43f0
	l32i.n	a11, a1, 8              # 400052b3
	add.n	a11, a11, a13           # 400052b5
	l8ui	a11, a11, 0             # 400052b7
	add.n	a11, a11, a12           # 400052ba
	s32i.n	a11, a1, 20             # 400052bc
	l32i.n	a10, a1, 8              # 400052be
	addi.n	a10, a10, 1             # 400052c0
	s32i.n	a10, a1, 8              # 400052c2
	l32i.n	a9, a1, 8               # 400052c4
	bltui	a9, 8, .L400052ab       # 400052c6
.L400052c9:
	# for (i = 8; i <= 11; i++) mask = (mask << 8) + pkt[i];
	movi.n	a15, 8                  # 400052c9
	s32i.n	a15, a1, 8              # 400052cb
	l32i.n	a14, a1, 8              # 400052cd
	movi.n	a13, 11                 # 400052cf
	bltu	a13, a14, .L400052f4    # 400052d1
.L400052d4:
	l32i.n	a6, a1, 24              # 400052d4
	slli	a6, a6, 8               # 400052d6
	l32r	a7, lit_3ffe1d88        # 400052d9  = 0x3ffe43f0
	l32i.n	a5, a1, 8               # 400052dc
	add.n	a5, a5, a7              # 400052de
	l8ui	a5, a5, 0               # 400052e0
	add.n	a5, a5, a6              # 400052e3
	s32i.n	a5, a1, 24              # 400052e5
	l32i.n	a4, a1, 8               # 400052e7
	addi.n	a4, a4, 1               # 400052e9
	s32i.n	a4, a1, 8               # 400052eb
	l32i.n	a3, a1, 8               # 400052ed
	movi.n	a2, 11                  # 400052ef
	bgeu	a2, a3, .L400052d4      # 400052f1
.L400052f4:
	# value &= mask;
	l32i.n	a8, a1, 24              # 400052f4
	l32i.n	a7, a1, 20              # 400052f6
	and	a7, a7, a8              # 400052f8
	s32i.n	a7, a1, 20              # 400052fb
	# tmp = lib_read_word(addr);
	l32i.n	a10, a1, 16             # 400052fd
	call8	lib_read_word           # 400052ff
	s32i.n	a10, a1, 40             # 40005302
	# tmp = (tmp & ~mask) | value;
	movi.n	a12, -1                 # 40005304
	l32i.n	a11, a1, 24             # 40005306
	xor	a11, a11, a12           # 40005308
	l32i.n	a10, a1, 40             # 4000530b
	and	a10, a10, a11           # 4000530d
	l32i.n	a9, a1, 20              # 40005310
	or	a9, a9, a10             # 40005312
	s32i.n	a9, a1, 40              # 40005315
	# lib_write_word(addr, tmp);   /* write the word at addr */
	l32i.n	a10, a1, 16             # 40005317
	l32i.n	a11, a1, 40             # 40005319
	call8	lib_write_word          # 4000531b
	# pkt[0] = 0x83; pkt[1] = 0x8F; pkt[2] = 0;
	l32r	a4, lit_3ffe1d88        # 4000531e  = 0x3ffe43f0
	movi	a3, 131                 # 40005321
	s8i	a3, a4, 0               # 40005324
	l32r	a2, lit_3ffe1d94        # 40005327  = 0x3ffe43f1
	movi	a15, 143                # 4000532a
	s8i	a15, a2, 0              # 4000532d
	l32r	a14, lit_3ffe1d98       # 40005330  = 0x3ffe43f2
	movi.n	a13, 0                  # 40005333
	s8i	a13, a14, 0             # 40005335
	# printf(pkt); replied = 1; break;
	l32r	a10, lit_3ffe1d88       # 40005338  = 0x3ffe43f0
	call8	dbg_printf              # 4000533b
	movi.n	a5, 1                   # 4000533e
	s8i	a5, a1, 32              # 40005340
	j	.L400053a4              # 40005343
.L40005346:
	# case 'W': case 'w': if (count != 8) break;
	l32i.n	a6, a1, 4               # 40005346
	bnei	a6, 8, .L400053a4       # 40005348
	# for (i = 4; i < 8; i++) value = (value << 8) + pkt[i];
	movi.n	a8, 4                   # 4000534b
	s32i.n	a8, a1, 8               # 4000534d
	l32i.n	a7, a1, 8               # 4000534f
	bgeui	a7, 8, .L40005372       # 40005351
.L40005354:
	l32i.n	a12, a1, 20             # 40005354
	slli	a12, a12, 8             # 40005356
	l32r	a13, lit_3ffe1d88       # 40005359  = 0x3ffe43f0
	l32i.n	a11, a1, 8              # 4000535c
	add.n	a11, a11, a13           # 4000535e
	l8ui	a11, a11, 0             # 40005360
	add.n	a11, a11, a12           # 40005363
	s32i.n	a11, a1, 20             # 40005365
	l32i.n	a10, a1, 8              # 40005367
	addi.n	a10, a10, 1             # 40005369
	s32i.n	a10, a1, 8              # 4000536b
	l32i.n	a9, a1, 8               # 4000536d
	bltui	a9, 8, .L40005354       # 4000536f
.L40005372:
	# lib_write_word(addr, value);
	l32i.n	a10, a1, 16             # 40005372
	l32i.n	a11, a1, 20             # 40005374
	call8	lib_write_word          # 40005376
	# pkt[0] = 0x83; pkt[1] = 0x8F; pkt[2] = 0;
	l32r	a4, lit_3ffe1d88        # 40005379  = 0x3ffe43f0
	movi	a3, 131                 # 4000537c
	s8i	a3, a4, 0               # 4000537f
	l32r	a2, lit_3ffe1d94        # 40005382  = 0x3ffe43f1
	movi	a15, 143                # 40005385
	s8i	a15, a2, 0              # 40005388
	l32r	a14, lit_3ffe1d98       # 4000538b  = 0x3ffe43f2
	movi.n	a13, 0                  # 4000538e
	s8i	a13, a14, 0             # 40005390
	# printf(pkt); replied = 1; break;
	l32r	a10, lit_3ffe1d88       # 40005393  = 0x3ffe43f0
	call8	dbg_printf              # 40005396
	movi.n	a5, 1                   # 40005399
	s8i	a5, a1, 32              # 4000539b
	j	.L400053a4              # 4000539e
.L400053a1:
	# }   /* default: nothing */
	j	.L400053a4              # 400053a1
.L400053a4:
	# if (replied == 0) { pkt[0] = 0x82; pkt[1] = 0x8F; pkt[2] = 0; printf(pkt); }
	movi.n	a7, 0                   # 400053a4
	l8ui	a6, a1, 32              # 400053a6
	bne	a6, a7, .L400053cc      # 400053a9
	l32r	a13, lit_3ffe1d88       # 400053ac  = 0x3ffe43f0
	movi	a12, 130                # 400053af
	s8i	a12, a13, 0             # 400053b2
	l32r	a11, lit_3ffe1d94       # 400053b5  = 0x3ffe43f1
	movi	a10, 143                # 400053b8
	s8i	a10, a11, 0             # 400053bb
	l32r	a9, lit_3ffe1d98        # 400053be  = 0x3ffe43f2
	movi.n	a8, 0                   # 400053c1
	s8i	a8, a9, 0               # 400053c3
	l32r	a10, lit_3ffe1d88       # 400053c6  = 0x3ffe43f0
	call8	dbg_printf              # 400053c9
.L400053cc:
	retw.n                          # 400053cc
	.size	dbg_run_hex_packet, . - dbg_run_hex_packet
