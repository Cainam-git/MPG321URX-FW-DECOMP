# fn_40003a70: 0x40003a70-0x40003b66 (firmware file offset 0x33a70-0x33b66), 95 instructions
# Address stored in the words at: 0x4000d424
# Calls: fn_4000a120, fn_4000a1f4, fn_4000a2cc

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003a70, @function
fn_40003a70:
	entry	a1, 176                 # 40003a70
	s32i	a2, a1, 128             # 40003a73
	s32i	a3, a1, 132             # 40003a76
	movi.n	a15, 0                  # 40003a79
	s8i	a15, a1, 0              # 40003a7b
	movi.n	a14, 0                  # 40003a7e
	s32i.n	a14, a1, 4              # 40003a80
	movi.n	a13, 0                  # 40003a82
	s32i.n	a13, a1, 8              # 40003a84
	movi.n	a12, 4                  # 40003a86
	s32i.n	a12, a1, 12             # 40003a88
	movi.n	a11, 0                  # 40003a8a
	s32i.n	a11, a1, 16             # 40003a8c
	l32i	a10, a1, 128            # 40003a8e
	l32i	a11, a1, 132            # 40003a91
	addi	a12, a1, 32             # 40003a94
	call8	fn_4000a120             # 40003a97
	s32i	a10, a1, 128            # 40003a9a
	movi.n	a3, 0                   # 40003a9d
	l32i	a2, a1, 128             # 40003a9f
	bne	a2, a3, .L40003aa8      # 40003aa2
	j	.L40003b4d              # 40003aa5
.L40003aa8:
	addi	a10, a1, 32             # 40003aa8
	call8	fn_4000a1f4             # 40003aab
	s32i.n	a10, a1, 4              # 40003aae
	l32i	a10, a1, 128            # 40003ab0
	l32i	a11, a1, 132            # 40003ab3
	addi	a12, a1, 32             # 40003ab6
	call8	fn_4000a120             # 40003ab9
	s32i	a10, a1, 128            # 40003abc
	movi.n	a12, 0                  # 40003abf
	l32i	a11, a1, 128            # 40003ac1
	bne	a11, a12, .L40003aca    # 40003ac4
	j	.L40003b4d              # 40003ac7
.L40003aca:
	addi	a10, a1, 32             # 40003aca
	call8	fn_4000a2cc             # 40003acd
	s32i.n	a10, a1, 12             # 40003ad0
	movi.n	a14, 0                  # 40003ad2
	l32i.n	a13, a1, 12             # 40003ad4
	bne	a13, a14, .L40003add    # 40003ad6
	movi.n	a15, 4                  # 40003ad9
	s32i.n	a15, a1, 12             # 40003adb
.L40003add:
	movi.n	a11, 1                  # 40003add
	s8i	a11, a1, 0              # 40003adf
	l32i	a10, a1, 128            # 40003ae2
	l32i	a11, a1, 132            # 40003ae5
	addi	a12, a1, 32             # 40003ae8
	call8	fn_4000a120             # 40003aeb
	s32i	a10, a1, 128            # 40003aee
	movi.n	a13, 0                  # 40003af1
	l32i	a12, a1, 128            # 40003af3
	beq	a12, a13, .L40003b4d    # 40003af6
.L40003af9:
	addi	a10, a1, 32             # 40003af9
	call8	fn_4000a1f4             # 40003afc
	s32i.n	a10, a1, 16             # 40003aff
	l32i.n	a14, a1, 12             # 40003b01
	bnei	a14, 4, .L40003b12      # 40003b03
	l32i.n	a2, a1, 4               # 40003b06
	l32i.n	a15, a1, 16             # 40003b08
	memw                            # 40003b0a
	s32i.n	a15, a2, 0              # 40003b0d
	j	.L40003b2e              # 40003b0f
.L40003b12:
	l32i.n	a3, a1, 12              # 40003b12
	bnei	a3, 2, .L40003b24       # 40003b14
	l32i.n	a5, a1, 4               # 40003b17
	l32i.n	a4, a1, 16              # 40003b19
	memw                            # 40003b1b
	s16i	a4, a5, 0               # 40003b1e
	j	.L40003b2e              # 40003b21
.L40003b24:
	l32i.n	a7, a1, 4               # 40003b24
	l32i.n	a6, a1, 16              # 40003b26
	memw                            # 40003b28
	s8i	a6, a7, 0               # 40003b2b
.L40003b2e:
	l32i	a10, a1, 128            # 40003b2e
	l32i	a11, a1, 132            # 40003b31
	addi	a12, a1, 32             # 40003b34
	call8	fn_4000a120             # 40003b37
	s32i	a10, a1, 128            # 40003b3a
	l32i.n	a13, a1, 12             # 40003b3d
	l32i.n	a12, a1, 4              # 40003b3f
	add.n	a12, a12, a13           # 40003b41
	s32i.n	a12, a1, 4              # 40003b43
	movi.n	a12, 0                  # 40003b45
	l32i	a11, a1, 128            # 40003b47
	bne	a11, a12, .L40003af9    # 40003b4a
.L40003b4d:
	movi.n	a2, 0                   # 40003b4d
	l8ui	a15, a1, 0              # 40003b4f
	bne	a15, a2, .L40003b5d     # 40003b52
	movi.n	a3, 1                   # 40003b55
	s32i	a3, a1, 112             # 40003b57
	j	.L40003b62              # 40003b5a
.L40003b5d:
	movi.n	a4, 0                   # 40003b5d
	s32i	a4, a1, 112             # 40003b5f
.L40003b62:
	l32i	a2, a1, 112             # 40003b62
	retw.n                          # 40003b65
	.size	fn_40003a70, . - fn_40003a70
