# ldc_units_copy_words_and_start  (fn_40006be8): 0x40006be8-0x40006c99 (firmware file offset 0x36be8-0x36c99), 73 instructions
# Name basis: descriptive - called by the LED driver routines; register writes only
# Called from: ldc_as3824_write_pwm_ht, ldc_as3824_write_bdac, ldc_as3824_write_byte,
#              ldc_as3824_write_byte_to_device, ldc_as3824_send_dev1_reg_bit7, ldc_as3824_write_word,
#              ldc_as3824_write_word_to_device,
# Copies count words into the buffer at 0xC01A0004, writes 0x84000000 | (count << 2) to 0xC01A0000, and for
# each set bit k (0..3) of the unit mask writes count + 1 to 0xC0197040 + k * 0x1000 and 1 to
# 0xC019700C + k * 0x1000. Called by the LED driver routines (ldc_as3824_write_pwm_ht .. ldc_set_direct_pwm_type0).
# Arguments: a2 count, a3 data (word array), a4 unit_mask (bits 0..3).
# Locals: a1+0 len (count + 1), a1+4 buf (0xC01A0004), a1+8 data, a1+12 i, a1+16 count, a1+20 data,
#   a1+24 unit_mask.
# Returns: nothing.
# Note: reg_write32(addr, value) is reg_write32: *addr = value.
#              ldc_as3824_write_bytes, ldc_as3824_set_dac, ldc_led_driver_type2_update, ldc_led_driver_type0_update, ldc_set_direct_pwm_type0
# Calls: reg_write32
# Other literal values: 0xc01a0004, 0xc01a0000, 0x84000000, 0xc0197040, 0xc019700c, 0xc0198040, 0xc019800c,
#                       0xc0199040, 0xc019900c, 0xc019a040, 0xc019a00c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_units_copy_words_and_start, @function
ldc_units_copy_words_and_start:         # fn_40006be8
	entry	a1, 64                  # 40006be8
	s32i.n	a2, a1, 16              # 40006beb
	s32i.n	a3, a1, 20              # 40006bed
	s32i.n	a4, a1, 24              # 40006bef
	# len = count; buf = 0xC01A0004; src = data;
	l32i.n	a12, a1, 16             # 40006bf1
	s32i.n	a12, a1, 0              # 40006bf3
	l32r	a11, lit_3ffe1f48       # 40006bf5  = 0xc01a0004
	s32i.n	a11, a1, 4              # 40006bf8
	l32i.n	a10, a1, 20             # 40006bfa
	s32i.n	a10, a1, 8              # 40006bfc
	# for (i = 0; i < count; i++)
	movi.n	a9, 0                   # 40006bfe
	s32i.n	a9, a1, 12              # 40006c00
	l32i.n	a8, a1, 16              # 40006c02
	l32i.n	a7, a1, 12              # 40006c04
	bgeu	a7, a8, .L40006c28      # 40006c06
.L40006c09:
	#     buf[i] = src[i];
	l32i.n	a3, a1, 12              # 40006c09
	l32i.n	a4, a1, 4               # 40006c0b
	addx4	a3, a3, a4              # 40006c0d
	l32i.n	a2, a1, 12              # 40006c10
	l32i.n	a4, a1, 8               # 40006c12
	addx4	a2, a2, a4              # 40006c14
	l32i.n	a2, a2, 0               # 40006c17
	s32i.n	a2, a3, 0               # 40006c19
	#     /* i++, loop while i < count */
	l32i.n	a15, a1, 12             # 40006c1b
	addi.n	a15, a15, 1             # 40006c1d
	s32i.n	a15, a1, 12             # 40006c1f
	l32i.n	a14, a1, 16             # 40006c21
	l32i.n	a13, a1, 12             # 40006c23
	bltu	a13, a14, .L40006c09    # 40006c25
.L40006c28:
	# reg_write32(0xC01A0000, 0x84000000 | (count << 2));
	l32r	a10, lit_3ffe1f4c       # 40006c28  = 0xc01a0000
	l32r	a12, lit_3ffe1f50       # 40006c2b  = 0x84000000
	l32i.n	a11, a1, 16             # 40006c2e
	slli	a11, a11, 2             # 40006c30
	or	a11, a11, a12           # 40006c33
	call8	reg_write32             # 40006c36
	j	.L40006c3c              # 40006c39
.L40006c3c:
	# len = count + 1;
	l32i.n	a13, a1, 16             # 40006c3c
	addi.n	a13, a13, 1             # 40006c3e
	s32i.n	a13, a1, 0              # 40006c40
	# if (unit_mask & 1) { reg_write32(0xC0197040, len); reg_write32(0xC019700C, 1); }
	l32i.n	a12, a1, 24             # 40006c42
	extui	a12, a12, 0, 1          # 40006c44
	beqz.n	a12, .L40006c59         # 40006c47
	l32r	a10, lit_3ffe1f54       # 40006c49  = 0xc0197040
	l32i.n	a11, a1, 0              # 40006c4c
	call8	reg_write32             # 40006c4e
	l32r	a10, lit_3ffe1f58       # 40006c51  = 0xc019700c
	movi.n	a11, 1                  # 40006c54
	call8	reg_write32             # 40006c56
.L40006c59:
	# if (unit_mask & 2) { reg_write32(0xC0198040, len); reg_write32(0xC019800C, 1); }
	l32i.n	a14, a1, 24             # 40006c59
	bbci	a14, 1, .L40006c6e      # 40006c5b
	l32r	a10, lit_3ffe1f5c       # 40006c5e  = 0xc0198040
	l32i.n	a11, a1, 0              # 40006c61
	call8	reg_write32             # 40006c63
	l32r	a10, lit_3ffe1f60       # 40006c66  = 0xc019800c
	movi.n	a11, 1                  # 40006c69
	call8	reg_write32             # 40006c6b
.L40006c6e:
	# if (unit_mask & 4) { reg_write32(0xC0199040, len); reg_write32(0xC019900C, 1); }
	l32i.n	a15, a1, 24             # 40006c6e
	bbci	a15, 2, .L40006c83      # 40006c70
	l32r	a10, lit_3ffe1f64       # 40006c73  = 0xc0199040
	l32i.n	a11, a1, 0              # 40006c76
	call8	reg_write32             # 40006c78
	l32r	a10, lit_3ffe1f68       # 40006c7b  = 0xc019900c
	movi.n	a11, 1                  # 40006c7e
	call8	reg_write32             # 40006c80
.L40006c83:
	# if (unit_mask & 8) { reg_write32(0xC019A040, len); reg_write32(0xC019A00C, 1); }
	l32i.n	a2, a1, 24              # 40006c83
	bbci	a2, 3, .L40006c98       # 40006c85
	l32r	a10, lit_3ffe1f6c       # 40006c88  = 0xc019a040
	l32i.n	a11, a1, 0              # 40006c8b
	call8	reg_write32             # 40006c8d
	l32r	a10, lit_3ffe1f70       # 40006c90  = 0xc019a00c
	movi.n	a11, 1                  # 40006c93
	call8	reg_write32             # 40006c95
.L40006c98:
	retw.n                          # 40006c98
	.size	ldc_units_copy_words_and_start, . - ldc_units_copy_words_and_start
