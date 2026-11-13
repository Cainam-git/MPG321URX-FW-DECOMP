# dbg_request_check_char  (fn_40005518): 0x40005518-0x40005573 (firmware file offset 0x35518-0x35573), 40 instructions
# Name basis: derived - compared with line[7]/line[15] of *RD/*CB/*WD requests
# Called from: dbg_run_star_request, dbg_parse_star_request
# Builds the check character of a "*xx" request or reply: adds up the bytes of two 32-bit words (each word is
# shifted right by 8 until it is 0) and returns '0' + (sum & 0xF).
# Arguments: a2 a (first word, e.g. the address), a3 b (second word, e.g. the data; 0 when there is none).
# Locals: a1+0 sum, a1+16 a, a1+20 b.
# Returns: a character '0'..'?' (0x30-0x3F).

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	dbg_request_check_char, @function
dbg_request_check_char:                 # fn_40005518
	entry	a1, 64                  # 40005518
	s32i.n	a2, a1, 16              # 4000551b
	s32i.n	a3, a1, 20              # 4000551d
	# sum = 0;
	movi.n	a6, 0                   # 4000551f
	s32i.n	a6, a1, 0               # 40005521
	# while (a != 0) { sum += a & 0xFF; a >>= 8; }
	movi.n	a6, 0                   # 40005523
	l32i.n	a5, a1, 16              # 40005525
	beq	a5, a6, .L40005543      # 40005527
.L4000552a:
	l32i.n	a10, a1, 16             # 4000552a
	extui	a10, a10, 0, 8          # 4000552c
	l32i.n	a9, a1, 0               # 4000552f
	add.n	a9, a9, a10             # 40005531
	s32i.n	a9, a1, 0               # 40005533
	l32i.n	a8, a1, 16              # 40005535
	srli	a8, a8, 8               # 40005537
	s32i.n	a8, a1, 16              # 4000553a
	movi.n	a8, 0                   # 4000553c
	l32i.n	a7, a1, 16              # 4000553e
	bne	a7, a8, .L4000552a      # 40005540
.L40005543:
	# while (b != 0) { sum += b & 0xFF; b >>= 8; }
	movi.n	a12, 0                  # 40005543
	l32i.n	a11, a1, 20             # 40005545
	beq	a11, a12, .L40005563    # 40005547
.L4000554a:
	l32i.n	a15, a1, 20             # 4000554a
	extui	a15, a15, 0, 8          # 4000554c
	l32i.n	a14, a1, 0              # 4000554f
	add.n	a14, a14, a15           # 40005551
	s32i.n	a14, a1, 0              # 40005553
	l32i.n	a13, a1, 20             # 40005555
	srli	a13, a13, 8             # 40005557
	s32i.n	a13, a1, 20             # 4000555a
	movi.n	a13, 0                  # 4000555c
	l32i.n	a12, a1, 20             # 4000555e
	bne	a12, a13, .L4000554a    # 40005560
.L40005563:
	# sum = (sum & 0xF) + '0';
	l32i.n	a3, a1, 0               # 40005563
	extui	a3, a3, 0, 4            # 40005565
	addi	a3, a3, 48              # 40005568
	s32i.n	a3, a1, 0               # 4000556b
	# return (unsigned char)sum;
	l32i.n	a2, a1, 0               # 4000556d
	extui	a2, a2, 0, 8            # 4000556f
	retw.n                          # 40005572
	.size	dbg_request_check_char, . - dbg_request_check_char
