# fn_400058dc: 0x400058dc-0x40005ba7 (firmware file offset 0x358dc-0x35ba7), 276 instructions
# Called from: fn_4000a3cc
# Calls: fn_40009f70, fn_40005050, fn_400099bc, fn_40009fc8, fn_40004788, fn_40004fc0, fn_4000574c,
#        fn_40005574
# Text loaded: "\n\rDBG >>", "*CB00000", "{#UTIL#}"
# Addresses loaded: ro_3ffe0914, ro_3ffe08be
# Other literal values: 0x3ffe4240, 0x3ffe42f0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400058dc, @function
fn_400058dc:
	entry	a1, 64                  # 400058dc
	mov.n	a10, a1                 # 400058df
	call8	fn_40009f70             # 400058e1
	s32i.n	a10, a1, 4              # 400058e4
	movi.n	a3, 0                   # 400058e6
	l32i.n	a2, a1, 4               # 400058e8
	bne	a2, a3, .L400058f0      # 400058ea
	j	.L40005ba6              # 400058ed
.L400058f0:
	movi.n	a5, 0                   # 400058f0
	l32r	a4, lit_3ffe1d70        # 400058f2  = 0x3ffe4240
	l8ui	a4, a4, 25              # 400058f5
	beq	a4, a5, .L40005977      # 400058f8
	l8ui	a7, a1, 0               # 400058fb
	s32i.n	a7, a1, 8               # 400058fe
	movi.n	a6, 28                  # 40005900
	l32i.n	a5, a1, 8               # 40005902
	beq	a5, a6, .L40005918      # 40005904
	movi.n	a9, 94                  # 40005907
	l32i.n	a8, a1, 8               # 40005909
	beq	a8, a9, .L40005918      # 4000590b
	movi.n	a11, 13                 # 4000590e
	l32i.n	a10, a1, 8              # 40005910
	beq	a10, a11, .L40005922    # 40005912
	j	.L4000594a              # 40005915
.L40005918:
	l32r	a13, lit_3ffe1d70       # 40005918  = 0x3ffe4240
	movi.n	a12, 0                  # 4000591b
	s32i.n	a12, a13, 28            # 4000591d
	j	.L40005974              # 4000591f
.L40005922:
	l32r	a14, lit_3ffe1d70       # 40005922  = 0x3ffe4240
	l32i.n	a14, a14, 28            # 40005925
	blti	a14, 2, .L40005938      # 40005927
	l32r	a10, lit_3ffe1d70       # 4000592a  = 0x3ffe4240
	l32i.n	a10, a10, 28            # 4000592d
	sext	a10, a10, 7             # 4000592f
	extui	a10, a10, 0, 8          # 40005932
	call8	fn_40005050             # 40005935
.L40005938:
	l32r	a14, lit_3ffe1d70       # 40005938  = 0x3ffe4240
	movi.n	a13, 0                  # 4000593b
	s32i.n	a13, a14, 28            # 4000593d
	l32r	a12, lit_3ffe1d70       # 4000593f  = 0x3ffe4240
	movi.n	a11, 0                  # 40005942
	s8i	a11, a12, 25            # 40005944
	j	.L40005974              # 40005947
.L4000594a:
	l32r	a2, lit_3ffe1d70        # 4000594a  = 0x3ffe4240
	l32i.n	a2, a2, 28              # 4000594d
	movi	a15, 253                # 4000594f
	blt	a15, a2, .L40005971     # 40005952
	l32r	a6, lit_3ffe1d84        # 40005955  = 0x3ffe42f0
	l32r	a5, lit_3ffe1d70        # 40005958  = 0x3ffe4240
	l32i.n	a5, a5, 28              # 4000595b
	add.n	a5, a5, a6              # 4000595d
	l8ui	a4, a1, 0               # 4000595f
	s8i	a4, a5, 0               # 40005962
	l32r	a4, lit_3ffe1d70        # 40005965  = 0x3ffe4240
	l32r	a3, lit_3ffe1d70        # 40005968  = 0x3ffe4240
	l32i.n	a3, a3, 28              # 4000596b
	addi.n	a3, a3, 1               # 4000596d
	s32i.n	a3, a4, 28              # 4000596f
.L40005971:
	j	.L40005974              # 40005971
.L40005974:
	j	.L40005ba6              # 40005974
.L40005977:
	movi.n	a8, 0                   # 40005977
	s32i.n	a8, a1, 12              # 40005979
	l8ui	a7, a1, 0               # 4000597b
	s32i.n	a7, a1, 16              # 4000597e
	l32i.n	a6, a1, 16              # 40005980
	beqi	a6, 8, .L40005996       # 40005982
	movi.n	a10, 13                 # 40005985
	l32i.n	a9, a1, 16              # 40005987
	beq	a9, a10, .L400059b5     # 40005989
	movi.n	a12, 27                 # 4000598c
	l32i.n	a11, a1, 16             # 4000598e
	beq	a11, a12, .L400059bc    # 40005990
	j	.L400059cc              # 40005993
.L40005996:
	l32r	a14, lit_3ffe1d70       # 40005996  = 0x3ffe4240
	l32i.n	a14, a14, 28            # 40005999
	movi.n	a13, 0                  # 4000599b
	bge	a13, a14, .L400059b2    # 4000599d
	l32r	a2, lit_3ffe1d70        # 400059a0  = 0x3ffe4240
	l32r	a15, lit_3ffe1d70       # 400059a3  = 0x3ffe4240
	l32i.n	a15, a15, 28            # 400059a6
	addi.n	a15, a15, -1            # 400059a8
	s32i.n	a15, a2, 28             # 400059aa
	l32r	a10, lit_3ffe1df4       # 400059ac  = ro_3ffe0914
	call8	fn_400099bc             # 400059af
.L400059b2:
	j	.L40005a66              # 400059b2
.L400059b5:
	movi.n	a2, 1                   # 400059b5
	s32i.n	a2, a1, 12              # 400059b7
	j	.L40005a66              # 400059b9
.L400059bc:
	l32r	a4, lit_3ffe1d70        # 400059bc  = 0x3ffe4240
	movi.n	a3, 0                   # 400059bf
	s32i.n	a3, a4, 28              # 400059c1
	l32r	a10, lit_3ffe1df8       # 400059c3  = ro_3ffe0918 "\n\rDBG >>"
	call8	fn_400099bc             # 400059c6
	j	.L40005a66              # 400059c9
.L400059cc:
	movi.n	a6, 0                   # 400059cc
	l32r	a5, lit_3ffe1d70        # 400059ce  = 0x3ffe4240
	l32i.n	a5, a5, 28              # 400059d1
	bne	a5, a6, .L400059f0      # 400059d3
	movi.n	a7, 94                  # 400059d6
	l8ui	a6, a1, 0               # 400059d8
	bne	a6, a7, .L400059f0      # 400059db
	l32r	a11, lit_3ffe1d70       # 400059de  = 0x3ffe4240
	movi.n	a10, 1                  # 400059e1
	s8i	a10, a11, 25            # 400059e3
	l32r	a9, lit_3ffe1d70        # 400059e6  = 0x3ffe4240
	movi.n	a8, 0                   # 400059e9
	s32i.n	a8, a9, 28              # 400059eb
	j	.L40005a66              # 400059ed
.L400059f0:
	l32r	a13, lit_3ffe1d70       # 400059f0  = 0x3ffe4240
	l32i.n	a13, a13, 28            # 400059f3
	movi	a12, 253                # 400059f5
	blt	a12, a13, .L40005a63    # 400059f8
	movi	a11, 252                # 400059fb
	l32r	a10, lit_3ffe1d70       # 400059fe  = 0x3ffe4240
	l32i.n	a10, a10, 28            # 40005a01
	and	a10, a10, a11           # 40005a03
	l32r	a11, lit_3ffe1d84       # 40005a06  = 0x3ffe42f0
	addx4	a10, a10, a11           # 40005a09
	s32i.n	a10, a1, 20             # 40005a0c
	l32r	a9, lit_3ffe1d70        # 40005a0e  = 0x3ffe4240
	l32i.n	a9, a9, 28              # 40005a11
	extui	a9, a9, 0, 2            # 40005a13
	l32i.n	a6, a1, 20              # 40005a16
	movi.n	a8, -1                  # 40005a18
	movi	a7, 255                 # 40005a1a
	slli	a9, a9, 3               # 40005a1d
	ssl	a9                      # 40005a20
	sll	a7, a7                  # 40005a23
	xor	a7, a7, a8              # 40005a26
	l32i.n	a5, a1, 20              # 40005a29
	l32i.n	a5, a5, 0               # 40005a2b
	and	a5, a5, a7              # 40005a2d
	s32i.n	a5, a6, 0               # 40005a30
	l32r	a4, lit_3ffe1d70        # 40005a32  = 0x3ffe4240
	l32i.n	a4, a4, 28              # 40005a35
	extui	a4, a4, 0, 2            # 40005a37
	l32i.n	a2, a1, 20              # 40005a3a
	l8ui	a3, a1, 0               # 40005a3c
	slli	a4, a4, 3               # 40005a3f
	ssl	a4                      # 40005a42
	sll	a3, a3                  # 40005a45
	l32i.n	a15, a1, 20             # 40005a48
	l32i.n	a15, a15, 0             # 40005a4a
	or	a15, a15, a3            # 40005a4c
	s32i.n	a15, a2, 0              # 40005a4f
	l32r	a15, lit_3ffe1d70       # 40005a51  = 0x3ffe4240
	l32r	a14, lit_3ffe1d70       # 40005a54  = 0x3ffe4240
	l32i.n	a14, a14, 28            # 40005a57
	addi.n	a14, a14, 1             # 40005a59
	s32i.n	a14, a15, 28            # 40005a5b
	l8ui	a10, a1, 0              # 40005a5d
	call8	fn_40009fc8             # 40005a60
.L40005a63:
	j	.L40005a66              # 40005a63
.L40005a66:
	movi.n	a12, 0                  # 40005a66
	l32i.n	a11, a1, 12             # 40005a68
	bne	a11, a12, .L40005a70    # 40005a6a
	j	.L40005ba6              # 40005a6d
.L40005a70:
	l32r	a10, lit_3ffe1d54       # 40005a70  = ro_3ffe08be
	call8	fn_400099bc             # 40005a73
	l32r	a14, lit_3ffe1d70       # 40005a76  = 0x3ffe4240
	l32i.n	a14, a14, 28            # 40005a79
	movi	a13, 255                # 40005a7b
	blt	a13, a14, .L40005ac3    # 40005a7e
	movi	a8, 252                 # 40005a81
	l32r	a7, lit_3ffe1d70        # 40005a84  = 0x3ffe4240
	l32i.n	a7, a7, 28              # 40005a87
	and	a7, a7, a8              # 40005a89
	l32r	a8, lit_3ffe1d84        # 40005a8c  = 0x3ffe42f0
	addx4	a7, a7, a8              # 40005a8f
	s32i.n	a7, a1, 20              # 40005a92
	l32r	a6, lit_3ffe1d70        # 40005a94  = 0x3ffe4240
	l32i.n	a6, a6, 28              # 40005a97
	extui	a6, a6, 0, 2            # 40005a99
	l32i.n	a3, a1, 20              # 40005a9c
	movi.n	a5, -1                  # 40005a9e
	movi	a4, 255                 # 40005aa0
	slli	a6, a6, 3               # 40005aa3
	ssl	a6                      # 40005aa6
	sll	a4, a4                  # 40005aa9
	xor	a4, a4, a5              # 40005aac
	l32i.n	a2, a1, 20              # 40005aaf
	l32i.n	a2, a2, 0               # 40005ab1
	and	a2, a2, a4              # 40005ab3
	s32i.n	a2, a3, 0               # 40005ab6
	l32i.n	a2, a1, 20              # 40005ab8
	l32i.n	a15, a1, 20             # 40005aba
	l32i.n	a15, a15, 0             # 40005abc
	s32i.n	a15, a2, 0              # 40005abe
	j	.L40005b1b              # 40005ac0
.L40005ac3:
	movi.n	a9, 0                   # 40005ac3
	l32r	a8, lit_3ffe1d70        # 40005ac5  = 0x3ffe4240
	l32i.n	a8, a8, 28              # 40005ac8
	beq	a8, a9, .L40005b13      # 40005aca
	movi	a2, 252                 # 40005acd
	l32r	a15, lit_3ffe1d70       # 40005ad0  = 0x3ffe4240
	l32i.n	a15, a15, 28            # 40005ad3
	addi.n	a15, a15, -1            # 40005ad5
	and	a15, a15, a2            # 40005ad7
	l32r	a2, lit_3ffe1d84        # 40005ada  = 0x3ffe42f0
	addx4	a15, a15, a2            # 40005add
	s32i.n	a15, a1, 20             # 40005ae0
	l32r	a14, lit_3ffe1d70       # 40005ae2  = 0x3ffe4240
	l32i.n	a14, a14, 28            # 40005ae5
	addi.n	a14, a14, -1            # 40005ae7
	extui	a14, a14, 0, 2          # 40005ae9
	l32i.n	a11, a1, 20             # 40005aec
	movi.n	a13, -1                 # 40005aee
	movi	a12, 255                # 40005af0
	slli	a14, a14, 3             # 40005af3
	ssl	a14                     # 40005af6
	sll	a12, a12                # 40005af9
	xor	a12, a12, a13           # 40005afc
	l32i.n	a10, a1, 20             # 40005aff
	l32i.n	a10, a10, 0             # 40005b01
	and	a10, a10, a12           # 40005b03
	s32i.n	a10, a11, 0             # 40005b06
	l32i.n	a10, a1, 20             # 40005b08
	l32i.n	a9, a1, 20              # 40005b0a
	l32i.n	a9, a9, 0               # 40005b0c
	s32i.n	a9, a10, 0              # 40005b0e
	j	.L40005b1b              # 40005b10
.L40005b13:
	l32r	a3, lit_3ffe1d84        # 40005b13  = 0x3ffe42f0
	movi.n	a2, 0                   # 40005b16
	s8i	a2, a3, 0               # 40005b18
.L40005b1b:
	movi.n	a5, 0                   # 40005b1b
	l32r	a4, lit_3ffe1d70        # 40005b1d  = 0x3ffe4240
	l8ui	a4, a4, 32              # 40005b20
	bne	a4, a5, .L40005b78      # 40005b23
	movi.n	a6, 42                  # 40005b26
	l32r	a5, lit_3ffe1d84        # 40005b28  = 0x3ffe42f0
	l8ui	a5, a5, 0               # 40005b2b
	bne	a5, a6, .L40005b4a      # 40005b2e
	l32r	a10, lit_3ffe1dfc       # 40005b31  = ro_3ffe07a0 "*CB00000"
	l32r	a11, lit_3ffe1d84       # 40005b34  = 0x3ffe42f0
	call8	fn_40004788             # 40005b37
	movi.n	a6, 0                   # 40005b3a
	bne	a10, a6, .L40005b47     # 40005b3c
	l32r	a8, lit_3ffe1d70        # 40005b3f  = 0x3ffe4240
	movi.n	a7, 1                   # 40005b42
	s8i	a7, a8, 32              # 40005b44
.L40005b47:
	j	.L40005b75              # 40005b47
.L40005b4a:
	movi	a10, 123                # 40005b4a
	l32r	a9, lit_3ffe1d84        # 40005b4d  = 0x3ffe42f0
	l8ui	a9, a9, 0               # 40005b50
	bne	a9, a10, .L40005b6f     # 40005b53
	l32r	a10, lit_3ffe1e00       # 40005b56  = ro_3ffe07b0 "{#UTIL#}"
	l32r	a11, lit_3ffe1d84       # 40005b59  = 0x3ffe42f0
	call8	fn_40004788             # 40005b5c
	movi.n	a11, 0                  # 40005b5f
	bne	a10, a11, .L40005b6c    # 40005b61
	l32r	a13, lit_3ffe1d70       # 40005b64  = 0x3ffe4240
	movi.n	a12, 1                  # 40005b67
	s8i	a12, a13, 32            # 40005b69
.L40005b6c:
	j	.L40005b75              # 40005b6c
.L40005b6f:
	l32r	a10, lit_3ffe1d84       # 40005b6f  = 0x3ffe42f0
	call8	fn_40004fc0             # 40005b72
.L40005b75:
	j	.L40005b9f              # 40005b75
.L40005b78:
	l32r	a14, lit_3ffe1d70       # 40005b78  = 0x3ffe4240
	l32i.n	a14, a14, 28            # 40005b7b
	blti	a14, 3, .L40005b9f      # 40005b7d
	l32r	a10, lit_3ffe1d84       # 40005b80  = 0x3ffe42f0
	call8	fn_4000574c             # 40005b83
	movi.n	a15, 0                  # 40005b86
	beq	a10, a15, .L40005b9f    # 40005b88
	call8	fn_40005574             # 40005b8b
	s32i.n	a10, a1, 4              # 40005b8e
	movi.n	a3, 0                   # 40005b90
	l32i.n	a2, a1, 4               # 40005b92
	beq	a2, a3, .L40005b9f      # 40005b94
	l32r	a5, lit_3ffe1d70        # 40005b97  = 0x3ffe4240
	movi.n	a4, 0                   # 40005b9a
	s8i	a4, a5, 32              # 40005b9c
.L40005b9f:
	l32r	a7, lit_3ffe1d70        # 40005b9f  = 0x3ffe4240
	movi.n	a6, 0                   # 40005ba2
	s32i.n	a6, a7, 28              # 40005ba4
.L40005ba6:
	retw.n                          # 40005ba6
	.size	fn_400058dc, . - fn_400058dc
