# lib_parse_decimal_text  (fn_4000a2cc): 0x4000a2cc-0x4000a371 (firmware file offset 0x3a2cc-0x3a371), 72 instructions
# Name basis: proven - code: '0'..'9' times place value 1,10,100..; operands of dbg_memcmd_* (mr/mw/md/cfg)
# Called from: dbg_memcmd_mr, dbg_memcmd_mw, dbg_memcmd_md, dbg_memcmd_cfg
# Reads a zero-terminated text as a decimal number, starting at its last character and working towards the
# first: digits '0'..'9' add digit * place value (place value 1, 10, 100, ...), spaces are skipped, and the
# first other character stops the scan. Used by the second console's commands (mr/mw/md/cfg) for their operands.
# a2 = text: zero-terminated text.
# Locals: a1+0 value, a1+4 place (place value), a1+8 len (length of the text), a1+12 i (position, from the
#         end), a1+16 is_digit (byte), a1+20 ch (character, then digit value); a1+32 text.
# Returns: value (the digits found after the last character that is neither a digit nor a space).

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	lib_parse_decimal_text, @function
lib_parse_decimal_text:                 # fn_4000a2cc
	entry	a1, 80                  # 4000a2cc
	s32i.n	a2, a1, 32              # 4000a2cf
	# value = 0;
	movi.n	a7, 0                   # 4000a2d1
	s32i.n	a7, a1, 0               # 4000a2d3
	# place = 1;
	movi.n	a6, 1                   # 4000a2d5
	s32i.n	a6, a1, 4               # 4000a2d7
	# for (len = 0; text[len] != 0; len++) ;
	movi.n	a5, 0                   # 4000a2d9
	s32i.n	a5, a1, 8               # 4000a2db
	movi.n	a5, 0                   # 4000a2dd
	l32i.n	a6, a1, 8               # 4000a2df
	l32i.n	a4, a1, 32              # 4000a2e1
	add.n	a4, a4, a6              # 4000a2e3
	l8ui	a4, a4, 0               # 4000a2e5
	beq	a4, a5, .L4000a2ff      # 4000a2e8
.L4000a2eb:
	l32i.n	a9, a1, 8               # 4000a2eb
	addi.n	a9, a9, 1               # 4000a2ed
	s32i.n	a9, a1, 8               # 4000a2ef
	movi.n	a9, 0                   # 4000a2f1
	l32i.n	a10, a1, 8              # 4000a2f3
	l32i.n	a8, a1, 32              # 4000a2f5
	add.n	a8, a8, a10             # 4000a2f7
	l8ui	a8, a8, 0               # 4000a2f9
	bne	a8, a9, .L4000a2eb      # 4000a2fc
.L4000a2ff:
	# for (i = len - 1; i >= 0; i--) {
	l32i.n	a12, a1, 8              # 4000a2ff
	addi.n	a12, a12, -1            # 4000a301
	s32i.n	a12, a1, 12             # 4000a303
	movi.n	a11, 0                  # 4000a305
	l32i.n	a10, a1, 12             # 4000a307
	blt	a10, a11, .L4000a36e    # 4000a309
.L4000a30c:
	#   is_digit = 0;
	movi.n	a15, 0                  # 4000a30c
	s8i	a15, a1, 16             # 4000a30e
	#   ch = text[i];
	l32i.n	a15, a1, 12             # 4000a311
	l32i.n	a14, a1, 32             # 4000a313
	add.n	a14, a14, a15           # 4000a315
	l8ui	a14, a14, 0             # 4000a317
	s32i.n	a14, a1, 20             # 4000a31a
	#   if (ch == ' ') continue;
	l32i.n	a13, a1, 20             # 4000a31c
	bnei	a13, 32, .L4000a324     # 4000a31e
	j	.L4000a361              # 4000a321
.L4000a324:
	#   if ((unsigned)(ch - '0') <= 9) { ch = ch - '0'; is_digit = 1; }
	l32i.n	a3, a1, 20              # 4000a324
	addi	a3, a3, -48             # 4000a326
	movi.n	a2, 9                   # 4000a329
	bltu	a2, a3, .L4000a33a      # 4000a32b
	l32i.n	a5, a1, 20              # 4000a32e
	addi	a5, a5, -48             # 4000a330
	s32i.n	a5, a1, 20              # 4000a333
	movi.n	a4, 1                   # 4000a335
	s8i	a4, a1, 16              # 4000a337
.L4000a33a:
	#   if (is_digit) { value += place * ch; place = place * 10; }
	movi.n	a7, 0                   # 4000a33a
	l8ui	a6, a1, 16              # 4000a33c
	beq	a6, a7, .L4000a35e      # 4000a33f
	l32i.n	a12, a1, 20             # 4000a342
	l32i.n	a11, a1, 4              # 4000a344
	mull	a11, a11, a12           # 4000a346
	l32i.n	a10, a1, 0              # 4000a349
	add.n	a10, a10, a11           # 4000a34b
	s32i.n	a10, a1, 0              # 4000a34d
	l32i.n	a8, a1, 4               # 4000a34f
	l32i.n	a9, a1, 4               # 4000a351
	addx4	a8, a8, a9              # 4000a353
	slli	a8, a8, 1               # 4000a356
	s32i.n	a8, a1, 4               # 4000a359
	j	.L4000a361              # 4000a35b
.L4000a35e:
	#   else break;
	j	.L4000a36e              # 4000a35e
.L4000a361:
	# }   (i--; loop while i >= 0)
	l32i.n	a15, a1, 12             # 4000a361
	addi.n	a15, a15, -1            # 4000a363
	s32i.n	a15, a1, 12             # 4000a365
	movi.n	a14, 0                  # 4000a367
	l32i.n	a13, a1, 12             # 4000a369
	bge	a13, a14, .L4000a30c    # 4000a36b
.L4000a36e:
	# return value;
	l32i.n	a2, a1, 0               # 4000a36e
	retw.n                          # 4000a370
	.size	lib_parse_decimal_text, . - lib_parse_decimal_text
