# fn_40003b98: 0x40003b98-0x40003c92 (firmware file offset 0x33b98-0x33c92), 89 instructions
# Address stored in the words at: 0x4000d434
# Calls: fn_4000a120, fn_4000a2cc, fn_4000a1f4, fn_400099bc
# Text loaded: "val = 0x%08X\n"

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003b98, @function
fn_40003b98:
	entry	a1, 160                 # 40003b98
	s32i	a2, a1, 112             # 40003b9b
	s32i	a3, a1, 116             # 40003b9e
	movi.n	a13, 0                  # 40003ba1
	s8i	a13, a1, 0              # 40003ba3
	movi.n	a12, 0                  # 40003ba6
	s32i.n	a12, a1, 4              # 40003ba8
	movi.n	a11, 0                  # 40003baa
	s32i.n	a11, a1, 8              # 40003bac
	l32i	a10, a1, 112            # 40003bae
	l32i	a11, a1, 116            # 40003bb1
	addi	a12, a1, 16             # 40003bb4
	call8	fn_4000a120             # 40003bb7
	s32i	a10, a1, 112            # 40003bba
	movi.n	a15, 0                  # 40003bbd
	l32i	a14, a1, 112            # 40003bbf
	bne	a14, a15, .L40003bc8    # 40003bc2
	j	.L40003c79              # 40003bc5
.L40003bc8:
	addi	a10, a1, 16             # 40003bc8
	call8	fn_4000a2cc             # 40003bcb
	s32i	a10, a1, 96             # 40003bce
	movi.n	a11, 1                  # 40003bd1
	s8i	a11, a1, 0              # 40003bd3
	l32i	a10, a1, 112            # 40003bd6
	l32i	a11, a1, 116            # 40003bd9
	addi	a12, a1, 16             # 40003bdc
	call8	fn_4000a120             # 40003bdf
	s32i	a10, a1, 112            # 40003be2
	movi.n	a13, 0                  # 40003be5
	l32i	a12, a1, 112            # 40003be7
	beq	a12, a13, .L40003c30    # 40003bea
	addi	a10, a1, 16             # 40003bed
	call8	fn_4000a1f4             # 40003bf0
	s32i.n	a10, a1, 8              # 40003bf3
	l32i	a2, a1, 96              # 40003bf5
	s32i	a2, a1, 100             # 40003bf8
	movi.n	a15, 0                  # 40003bfb
	l32i	a14, a1, 100            # 40003bfd
	beq	a14, a15, .L40003c1e    # 40003c00
	l32i	a3, a1, 100             # 40003c03
	beqi	a3, 1, .L40003c21       # 40003c06
	l32i	a4, a1, 100             # 40003c09
	beqi	a4, 2, .L40003c24       # 40003c0c
	l32i	a5, a1, 100             # 40003c0f
	beqi	a5, 3, .L40003c27       # 40003c12
	l32i	a6, a1, 100             # 40003c15
	beqi	a6, 5, .L40003c2a       # 40003c18
	j	.L40003c2d              # 40003c1b
.L40003c1e:
	j	.L40003c2d              # 40003c1e
.L40003c21:
	j	.L40003c2d              # 40003c21
.L40003c24:
	j	.L40003c2d              # 40003c24
.L40003c27:
	j	.L40003c2d              # 40003c27
.L40003c2a:
	j	.L40003c2d              # 40003c2a
.L40003c2d:
	j	.L40003c79              # 40003c2d
.L40003c30:
	l32i	a9, a1, 96              # 40003c30
	s32i	a9, a1, 104             # 40003c33
	movi.n	a8, 0                   # 40003c36
	l32i	a7, a1, 104             # 40003c38
	beq	a7, a8, .L40003c5f      # 40003c3b
	l32i	a10, a1, 104            # 40003c3e
	beqi	a10, 1, .L40003c62      # 40003c41
	l32i	a11, a1, 104            # 40003c44
	beqi	a11, 2, .L40003c65      # 40003c47
	l32i	a12, a1, 104            # 40003c4a
	beqi	a12, 3, .L40003c68      # 40003c4d
	l32i	a13, a1, 104            # 40003c50
	beqi	a13, 4, .L40003c6b      # 40003c53
	l32i	a14, a1, 104            # 40003c56
	beqi	a14, 5, .L40003c6e      # 40003c59
	j	.L40003c71              # 40003c5c
.L40003c5f:
	j	.L40003c71              # 40003c5f
.L40003c62:
	j	.L40003c71              # 40003c62
.L40003c65:
	j	.L40003c71              # 40003c65
.L40003c68:
	j	.L40003c71              # 40003c68
.L40003c6b:
	j	.L40003c71              # 40003c6b
.L40003c6e:
	j	.L40003c71              # 40003c6e
.L40003c71:
	l32r	a10, lit_3ffe1cf8       # 40003c71  = ro_3ffe0528 "val = 0x%08X\n"
	l32i.n	a11, a1, 8              # 40003c74
	call8	fn_400099bc             # 40003c76
.L40003c79:
	movi.n	a2, 0                   # 40003c79
	l8ui	a15, a1, 0              # 40003c7b
	bne	a15, a2, .L40003c89     # 40003c7e
	movi.n	a3, 1                   # 40003c81
	s32i	a3, a1, 108             # 40003c83
	j	.L40003c8e              # 40003c86
.L40003c89:
	movi.n	a4, 0                   # 40003c89
	s32i	a4, a1, 108             # 40003c8b
.L40003c8e:
	l32i	a2, a1, 108             # 40003c8e
	retw.n                          # 40003c91
	.size	fn_40003b98, . - fn_40003b98
