# fn_40004bcc: 0x40004bcc-0x40004c13 (firmware file offset 0x34bcc-0x34c13), 28 instructions
# Address stored in the words at: 0x4000b36c, 0x4000b3b4
# Calls: fn_400099bc, fn_4000a010, fn_4000497c
# Text loaded: "\n [", "] : ", "Address Fail\n"
# Addresses loaded: ro_3ffe08be

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40004bcc, @function
fn_40004bcc:
	entry	a1, 48                  # 40004bcc
	s32i.n	a2, a1, 0               # 40004bcf
	s32i.n	a3, a1, 4               # 40004bd1
	s32i.n	a4, a1, 8               # 40004bd3
	movi.n	a8, 0                   # 40004bd5
	l32i.n	a7, a1, 0               # 40004bd7
	bne	a7, a8, .L40004bdf      # 40004bd9
	j	.L40004c12              # 40004bdc
.L40004bdf:
	l32r	a10, lit_3ffe1d5c       # 40004bdf  = ro_3ffe08cc "\n ["
	call8	fn_400099bc             # 40004be2
	l32i.n	a10, a1, 0              # 40004be5
	call8	fn_4000a010             # 40004be7
	l32r	a10, lit_3ffe1d60       # 40004bea  = ro_3ffe08d0 "] : "
	call8	fn_400099bc             # 40004bed
	l32i.n	a12, a1, 0              # 40004bf0
	movi.n	a11, 3                  # 40004bf2
	bnone	a11, a12, .L40004c00    # 40004bf4
	l32r	a10, lit_3ffe1d64       # 40004bf7  = ro_3ffe08d8 "Address Fail\n"
	call8	fn_400099bc             # 40004bfa
	j	.L40004c12              # 40004bfd
.L40004c00:
	l32i.n	a10, a1, 0              # 40004c00
	l32i.n	a11, a1, 4              # 40004c02
	call8	fn_4000497c             # 40004c04
	l32i.n	a10, a1, 4              # 40004c07
	call8	fn_4000a010             # 40004c09
	l32r	a10, lit_3ffe1d54       # 40004c0c  = ro_3ffe08be
	call8	fn_400099bc             # 40004c0f
.L40004c12:
	retw.n                          # 40004c12
	.size	fn_40004bcc, . - fn_40004bcc
