# fn_40003904: 0x40003904-0x40003a6e (firmware file offset 0x33904-0x33a6e), 137 instructions
# Address stored in the words at: 0x4000d41c
# Calls: fn_4000a120, fn_4000a1f4, fn_4000a2cc, fn_400099bc
# Text loaded: "%08X:   ", " %08X", " %04X", " %02X"
# Addresses loaded: data_3ffe2700, ro_3ffe0524

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40003904, @function
fn_40003904:
	entry	a1, 160                 # 40003904
	s32i	a2, a1, 112             # 40003907
	s32i	a3, a1, 116             # 4000390a
	movi.n	a14, 0                  # 4000390d
	s8i	a14, a1, 0              # 4000390f
	movi.n	a13, 0                  # 40003912
	s32i.n	a13, a1, 4              # 40003914
	movi.n	a12, 0                  # 40003916
	s32i.n	a12, a1, 8              # 40003918
	movi.n	a11, 4                  # 4000391a
	s32i.n	a11, a1, 12             # 4000391c
	l32i	a10, a1, 112            # 4000391e
	l32i	a11, a1, 116            # 40003921
	addi	a12, a1, 16             # 40003924
	call8	fn_4000a120             # 40003927
	s32i	a10, a1, 112            # 4000392a
	movi.n	a2, 0                   # 4000392d
	l32i	a15, a1, 112            # 4000392f
	beq	a15, a2, .L40003980     # 40003932
	addi	a10, a1, 16             # 40003935
	call8	fn_4000a1f4             # 40003938
	s32i.n	a10, a1, 4              # 4000393b
	l32i	a10, a1, 112            # 4000393d
	l32i	a11, a1, 116            # 40003940
	addi	a12, a1, 16             # 40003943
	call8	fn_4000a120             # 40003946
	s32i	a10, a1, 112            # 40003949
	movi.n	a12, 0                  # 4000394c
	l32i	a11, a1, 112            # 4000394e
	beq	a11, a12, .L40003980    # 40003951
	addi	a10, a1, 16             # 40003954
	call8	fn_4000a2cc             # 40003957
	s32i.n	a10, a1, 8              # 4000395a
	l32i	a10, a1, 112            # 4000395c
	l32i	a11, a1, 116            # 4000395f
	addi	a12, a1, 16             # 40003962
	call8	fn_4000a120             # 40003965
	s32i	a10, a1, 112            # 40003968
	movi.n	a12, 0                  # 4000396b
	l32i	a11, a1, 112            # 4000396d
	beq	a11, a12, .L40003980    # 40003970
	addi	a10, a1, 16             # 40003973
	call8	fn_4000a2cc             # 40003976
	s32i.n	a10, a1, 12             # 40003979
	movi.n	a13, 1                  # 4000397b
	s8i	a13, a1, 0              # 4000397d
.L40003980:
	movi.n	a15, 0                  # 40003980
	l8ui	a14, a1, 0              # 40003982
	bne	a14, a15, .L40003990    # 40003985
	movi.n	a2, 1                   # 40003988
	s32i	a2, a1, 104             # 4000398a
	j	.L40003a6a              # 4000398d
.L40003990:
	movi.n	a4, 0                   # 40003990
	l32i.n	a3, a1, 12              # 40003992
	bne	a3, a4, .L4000399b      # 40003994
	movi.n	a5, 4                   # 40003997
	s32i.n	a5, a1, 12              # 40003999
.L4000399b:
	movi.n	a8, 0                   # 4000399b
	s32i	a8, a1, 96              # 4000399d
	l32i.n	a7, a1, 8               # 400039a0
	l32i	a6, a1, 96              # 400039a2
	bltu	a6, a7, .L400039ab      # 400039a5
	j	.L40003a54              # 400039a8
.L400039ab:
	movi.n	a10, 0                  # 400039ab
	l32r	a9, lit_3ffe1ce0        # 400039ad  = data_3ffe2700
	l8ui	a9, a9, 0               # 400039b0
	beq	a9, a10, .L400039be     # 400039b3
	l32r	a10, lit_3ffe1ce4       # 400039b6  = ro_3ffe0500 "%08X:   "
	l32i.n	a11, a1, 4              # 400039b9
	call8	fn_400099bc             # 400039bb
.L400039be:
	movi.n	a12, 0                  # 400039be
	s32i	a12, a1, 100            # 400039c0
	l32i	a11, a1, 100            # 400039c3
	movi.n	a10, 15                 # 400039c6
	bltu	a10, a11, .L40003a38    # 400039c8
	l32i.n	a14, a1, 8              # 400039cb
	l32i	a13, a1, 96             # 400039cd
	bgeu	a13, a14, .L40003a38    # 400039d0
.L400039d3:
	l32i.n	a15, a1, 12             # 400039d3
	bnei	a15, 4, .L400039e8      # 400039d5
	l32r	a10, lit_3ffe1ce8       # 400039d8  = ro_3ffe050c " %08X"
	l32i.n	a11, a1, 4              # 400039db
	memw                            # 400039dd
	l32i.n	a11, a11, 0             # 400039e0
	call8	fn_400099bc             # 400039e2
	j	.L40003a0c              # 400039e5
.L400039e8:
	l32i.n	a12, a1, 12             # 400039e8
	bnei	a12, 2, .L400039fe      # 400039ea
	l32r	a10, lit_3ffe1cec       # 400039ed  = ro_3ffe0514 " %04X"
	l32i.n	a11, a1, 4              # 400039f0
	memw                            # 400039f2
	l16ui	a11, a11, 0             # 400039f5
	call8	fn_400099bc             # 400039f8
	j	.L40003a0c              # 400039fb
.L400039fe:
	l32r	a10, lit_3ffe1cf0       # 400039fe  = ro_3ffe051c " %02X"
	l32i.n	a11, a1, 4              # 40003a01
	memw                            # 40003a03
	l8ui	a11, a11, 0             # 40003a06
	call8	fn_400099bc             # 40003a09
.L40003a0c:
	l32i	a5, a1, 100             # 40003a0c
	l32i.n	a4, a1, 12              # 40003a0f
	add.n	a4, a4, a5              # 40003a11
	s32i	a4, a1, 100             # 40003a13
	l32i	a3, a1, 96              # 40003a16
	l32i.n	a2, a1, 12              # 40003a19
	add.n	a2, a2, a3              # 40003a1b
	s32i	a2, a1, 96              # 40003a1d
	l32i.n	a15, a1, 12             # 40003a20
	l32i.n	a14, a1, 4              # 40003a22
	add.n	a14, a14, a15           # 40003a24
	s32i.n	a14, a1, 4              # 40003a26
	l32i	a13, a1, 100            # 40003a28
	movi.n	a12, 15                 # 40003a2b
	bltu	a12, a13, .L40003a38    # 40003a2d
	l32i.n	a7, a1, 8               # 40003a30
	l32i	a6, a1, 96              # 40003a32
	bltu	a6, a7, .L400039d3      # 40003a35
.L40003a38:
	movi.n	a9, 0                   # 40003a38
	l32r	a8, lit_3ffe1ce0        # 40003a3a  = data_3ffe2700
	l8ui	a8, a8, 0               # 40003a3d
	beq	a8, a9, .L40003a49      # 40003a40
	l32r	a10, lit_3ffe1cf4       # 40003a43  = ro_3ffe0524
	call8	fn_400099bc             # 40003a46
.L40003a49:
	l32i.n	a10, a1, 8              # 40003a49
	l32i	a9, a1, 96              # 40003a4b
	bgeu	a9, a10, .L40003a54     # 40003a4e
	j	.L400039ab              # 40003a51
.L40003a54:
	movi.n	a12, 0                  # 40003a54
	l32r	a11, lit_3ffe1ce0       # 40003a56  = data_3ffe2700
	l8ui	a11, a11, 0             # 40003a59
	beq	a11, a12, .L40003a65    # 40003a5c
	l32r	a10, lit_3ffe1cf4       # 40003a5f  = ro_3ffe0524
	call8	fn_400099bc             # 40003a62
.L40003a65:
	movi.n	a12, 0                  # 40003a65
	s32i	a12, a1, 104            # 40003a67
.L40003a6a:
	l32i	a2, a1, 104             # 40003a6a
	retw.n                          # 40003a6d
	.size	fn_40003904, . - fn_40003904
