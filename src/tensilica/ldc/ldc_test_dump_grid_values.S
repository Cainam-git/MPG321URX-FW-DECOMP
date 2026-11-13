# ldc_test_dump_grid_values  (fn_40006afc): 0x40006afc-0x40006be5 (firmware file offset 0x36afc-0x36be5), 98 instructions
# Name basis: derived - prints 'LDC test function' and 'i = %d, %lX ...'; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Prints "LDC test function", then for each i 0..31 and j 0..63 writes (i << 16) + j to register 0xE00805A0
# and, for each k 0..8, writes k << 16 to register 0xE00805A4, waits (timer_wait_ticks(1000)) and reads the low 16
# bits of register 0xE00805D4; it prints "i = %d, ..." with i * 64 + j and the nine values. Nothing calls it.
# Arguments: none.
# Locals: a1+32 i, a1+36 j, a1+40 sel (value for 0x5A0), a1+44 k, a1+48 sel2 (value for 0x5A4),
#   a1+52 raw (value read from 0x5D4), a1+64..a1+96 vals[9]; a1+0..a1+16 hold the printf arguments 5..9.
# Returns: nothing.
# Calls: dbg_printf, timer_wait_ticks
# Text loaded: "LDC test function\r\n", "i = %d, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX\r\n"
# Other literal values: 0xe00805a0, 0xe00805a4, 0xe00805d4

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_test_dump_grid_values, @function
ldc_test_dump_grid_values:              # fn_40006afc
	entry	a1, 144                 # 40006afc
	# printf("LDC test function\r\n");
	l32r	a10, lit_3ffe1f38       # 40006aff  = ro_3ffe0b4c "LDC test function\r\n"
	call8	dbg_printf              # 40006b02
	# for (i = 0; i <= 31; i++) {
	movi.n	a4, 0                   # 40006b05
	s32i.n	a4, a1, 32              # 40006b07
	l32i.n	a3, a1, 32              # 40006b09
	movi.n	a2, 31                  # 40006b0b
	bge	a2, a3, .L40006b13      # 40006b0d
	j	.L40006be4              # 40006b10
.L40006b13:
	#     for (j = 0; j <= 63; j++) {
	movi.n	a7, 0                   # 40006b13
	s32i.n	a7, a1, 36              # 40006b15
	l32i.n	a6, a1, 36              # 40006b17
	movi.n	a5, 63                  # 40006b19
	bge	a5, a6, .L40006b21      # 40006b1b
	j	.L40006bd4              # 40006b1e
.L40006b21:
	#         sel = j + (i << 16);
	l32i.n	a14, a1, 32             # 40006b21
	slli	a14, a14, 16            # 40006b23
	l32i.n	a13, a1, 36             # 40006b26
	add.n	a13, a13, a14           # 40006b28
	s32i.n	a13, a1, 40             # 40006b2a
	#         reg[0x5A0] = sel;   /* reg[x] = 32-bit register at 0xE0080000 + x */
	l32r	a12, lit_3ffe1f3c       # 40006b2c  = 0xe00805a0
	l32i.n	a11, a1, 40             # 40006b2f
	memw                            # 40006b31
	s32i.n	a11, a12, 0             # 40006b34
	#         for (k = 0; k <= 8; k++) {
	movi.n	a10, 0                  # 40006b36
	s32i.n	a10, a1, 44             # 40006b38
	l32i.n	a9, a1, 44              # 40006b3a
	movi.n	a8, 8                   # 40006b3c
	blt	a8, a9, .L40006b7e      # 40006b3e
.L40006b41:
	#             sel2 = k << 16;
	l32i.n	a3, a1, 44              # 40006b41
	slli	a3, a3, 16              # 40006b43
	s32i.n	a3, a1, 48              # 40006b46
	#             reg[0x5A4] = sel2;
	l32r	a2, lit_3ffe1efc        # 40006b48  = 0xe00805a4
	l32i.n	a15, a1, 48             # 40006b4b
	memw                            # 40006b4d
	s32i.n	a15, a2, 0              # 40006b50
	#             timer_wait_ticks(1000);   /* waits until the counter at 0x3ffe5598 +24 has moved on by 1000 */
	movi	a10, 0x3e8              # 40006b52
	call8	timer_wait_ticks        # 40006b55
	#             raw = reg[0x5D4];
	l32r	a10, lit_3ffe1f40       # 40006b58  = 0xe00805d4
	memw                            # 40006b5b
	l32i.n	a10, a10, 0             # 40006b5e
	s32i.n	a10, a1, 52             # 40006b60
	#             vals[k] = raw & 0xFFFF;
	l32i.n	a8, a1, 44              # 40006b62
	addi	a9, a1, 64              # 40006b64
	addx4	a8, a8, a9              # 40006b67
	l32i.n	a7, a1, 52              # 40006b6a
	extui	a7, a7, 0, 16           # 40006b6c
	s32i.n	a7, a8, 0               # 40006b6f
	#             /* k++, loop while k <= 8 */
	#         }
	l32i.n	a6, a1, 44              # 40006b71
	addi.n	a6, a6, 1               # 40006b73
	s32i.n	a6, a1, 44              # 40006b75
	l32i.n	a5, a1, 44              # 40006b77
	movi.n	a4, 8                   # 40006b79
	bge	a4, a5, .L40006b41      # 40006b7b
.L40006b7e:
	#         printf("i = %d, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX\r\n", j + (i << 6), vals[0], ..., vals[8]);
	l32r	a10, lit_3ffe1f44       # 40006b7e  = ro_3ffe0b60 "i = %d, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX, %lX\r\n"
	l32i.n	a12, a1, 32             # 40006b81
	slli	a12, a12, 6             # 40006b83
	l32i.n	a11, a1, 36             # 40006b86
	add.n	a11, a11, a12           # 40006b88
	addi	a12, a1, 64             # 40006b8a
	l32i.n	a12, a12, 0             # 40006b8d
	addi	a13, a1, 68             # 40006b8f
	l32i.n	a13, a13, 0             # 40006b92
	addi	a14, a1, 72             # 40006b94
	l32i.n	a14, a14, 0             # 40006b97
	addi	a15, a1, 76             # 40006b99
	l32i.n	a15, a15, 0             # 40006b9c
	addi	a6, a1, 80              # 40006b9e
	l32i.n	a6, a6, 0               # 40006ba1
	s32i.n	a6, a1, 0               # 40006ba3
	addi	a5, a1, 84              # 40006ba5
	l32i.n	a5, a5, 0               # 40006ba8
	s32i.n	a5, a1, 4               # 40006baa
	addi	a4, a1, 88              # 40006bac
	l32i.n	a4, a4, 0               # 40006baf
	s32i.n	a4, a1, 8               # 40006bb1
	addi	a3, a1, 92              # 40006bb3
	l32i.n	a3, a3, 0               # 40006bb6
	s32i.n	a3, a1, 12              # 40006bb8
	addi	a2, a1, 96              # 40006bba
	l32i.n	a2, a2, 0               # 40006bbd
	s32i.n	a2, a1, 16              # 40006bbf
	call8	dbg_printf              # 40006bc1
	#         /* j++, loop while j <= 63 */
	#     }
	l32i.n	a15, a1, 36             # 40006bc4
	addi.n	a15, a15, 1             # 40006bc6
	s32i.n	a15, a1, 36             # 40006bc8
	l32i.n	a14, a1, 36             # 40006bca
	movi.n	a13, 63                 # 40006bcc
	blt	a13, a14, .L40006bd4    # 40006bce
	j	.L40006b21              # 40006bd1
.L40006bd4:
	#     /* i++, loop while i <= 31 */
	# }
	l32i.n	a4, a1, 32              # 40006bd4
	addi.n	a4, a4, 1               # 40006bd6
	s32i.n	a4, a1, 32              # 40006bd8
	l32i.n	a3, a1, 32              # 40006bda
	movi.n	a2, 31                  # 40006bdc
	blt	a2, a3, .L40006be4      # 40006bde
	j	.L40006b13              # 40006be1
.L40006be4:
	retw.n                          # 40006be4
	.size	ldc_test_dump_grid_values, . - ldc_test_dump_grid_values
