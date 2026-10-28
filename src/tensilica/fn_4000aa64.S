# fn_4000aa64: 0x4000aa64-0x4000ab58 (firmware file offset 0x3aa64-0x3ab58), 97 instructions
# Called from: fn_400035d0, fn_4000713c, fn_40007348, fn_40007e68

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000aa64, @function
fn_4000aa64:
	entry	a1, 16                  # 4000aa64
	or	a5, a2, a2              # 4000aa67
	bbsi	a2, 0, .L4000aa34       # 4000aa6a
	bbsi	a2, 1, .L4000aa48       # 4000aa6d
.L4000aa70:
	srli	a7, a4, 4               # 4000aa70
	slli	a8, a3, 30              # 4000aa73
	bnez	a8, .L4000aad4          # 4000aa76
	loopnez	a7, .L4000aa92          # 4000aa79
	l32i.n	a6, a3, 0               # 4000aa7c
	l32i.n	a7, a3, 4               # 4000aa7e
	s32i.n	a6, a5, 0               # 4000aa80
	l32i.n	a6, a3, 8               # 4000aa82
	s32i.n	a7, a5, 4               # 4000aa84
	l32i.n	a7, a3, 12              # 4000aa86
	s32i.n	a6, a5, 8               # 4000aa88
	addi	a3, a3, 16              # 4000aa8a
	s32i.n	a7, a5, 12              # 4000aa8d
	addi	a5, a5, 16              # 4000aa8f
.L4000aa92:
	bbci	a4, 3, .L4000aaa1       # 4000aa92
	l32i.n	a6, a3, 0               # 4000aa95
	l32i.n	a7, a3, 4               # 4000aa97
	addi.n	a3, a3, 8               # 4000aa99
	s32i.n	a6, a5, 0               # 4000aa9b
	s32i.n	a7, a5, 4               # 4000aa9d
	addi.n	a5, a5, 8               # 4000aa9f
.L4000aaa1:
	bbsi	a4, 2, .L4000aaac       # 4000aaa1
	bbsi	a4, 1, .L4000aabc       # 4000aaa4
	bbsi	a4, 0, .L4000aacc       # 4000aaa7
	retw.n                          # 4000aaaa
.L4000aaac:
	l32i.n	a6, a3, 0               # 4000aaac
	addi.n	a3, a3, 4               # 4000aaae
	s32i.n	a6, a5, 0               # 4000aab0
	addi.n	a5, a5, 4               # 4000aab2
	bbsi	a4, 1, .L4000aabc       # 4000aab4
	bbsi	a4, 0, .L4000aacc       # 4000aab7
	retw.n                          # 4000aaba
.L4000aabc:
	l16ui	a6, a3, 0               # 4000aabc
	addi.n	a3, a3, 2               # 4000aabf
	s16i	a6, a5, 0               # 4000aac1
	addi.n	a5, a5, 2               # 4000aac4
	bbsi	a4, 0, .L4000aacc       # 4000aac6
	retw.n                          # 4000aac9
	.balign	4, 0                    # 1 zero byte up to the 4-byte boundary 0x4000aacc
.L4000aacc:
	l8ui	a6, a3, 0               # 4000aacc
	s8i	a6, a5, 0               # 4000aacf
.L4000aad2:
	retw.n                          # 4000aad2
.L4000aad4:
	beqz	a4, .L4000aad2          # 4000aad4
	ssa8l	a3                      # 4000aad7
	extui	a11, a8, 30, 2          # 4000aada
	sub	a3, a3, a11             # 4000aadd
	l32i.n	a6, a3, 0               # 4000aae0
	loopnez	a7, .L4000ab07          # 4000aae2
	l32i.n	a7, a3, 4               # 4000aae5
	l32i.n	a8, a3, 8               # 4000aae7
	src	a6, a7, a6              # 4000aae9
	s32i.n	a6, a5, 0               # 4000aaec
	l32i.n	a9, a3, 12              # 4000aaee
	src	a7, a8, a7              # 4000aaf0
	s32i.n	a7, a5, 4               # 4000aaf3
	l32i.n	a6, a3, 16              # 4000aaf5
	src	a8, a9, a8              # 4000aaf7
	s32i.n	a8, a5, 8               # 4000aafa
	addi	a3, a3, 16              # 4000aafc
	src	a9, a6, a9              # 4000aaff
	s32i.n	a9, a5, 12              # 4000ab02
	addi	a5, a5, 16              # 4000ab04
.L4000ab07:
	bbci	a4, 3, .L4000ab20       # 4000ab07
	l32i.n	a7, a3, 4               # 4000ab0a
	l32i.n	a8, a3, 8               # 4000ab0c
	src	a6, a7, a6              # 4000ab0e
	s32i.n	a6, a5, 0               # 4000ab11
	addi.n	a3, a3, 8               # 4000ab13
	src	a7, a8, a7              # 4000ab15
	s32i.n	a7, a5, 4               # 4000ab18
	addi	a5, a5, 8               # 4000ab1a
	or	a6, a8, a8              # 4000ab1d
.L4000ab20:
	bbci	a4, 2, .L4000ab30       # 4000ab20
	l32i.n	a7, a3, 4               # 4000ab23
	addi.n	a3, a3, 4               # 4000ab25
	src	a6, a7, a6              # 4000ab27
	s32i.n	a6, a5, 0               # 4000ab2a
	addi.n	a5, a5, 4               # 4000ab2c
	mov.n	a6, a7                  # 4000ab2e
.L4000ab30:
	add.n	a3, a3, a11             # 4000ab30
	bbsi	a4, 1, .L4000ab3c       # 4000ab32
	bbsi	a4, 0, .L4000ab51       # 4000ab35
	retw.n                          # 4000ab38
	.balign	4, 0                    # 2 zero bytes up to the 4-byte boundary 0x4000ab3c
.L4000ab3c:
	l8ui	a6, a3, 0               # 4000ab3c
	l8ui	a7, a3, 1               # 4000ab3f
	addi.n	a3, a3, 2               # 4000ab42
	s8i	a6, a5, 0               # 4000ab44
	s8i	a7, a5, 1               # 4000ab47
	addi.n	a5, a5, 2               # 4000ab4a
	bbsi	a4, 0, .L4000ab51       # 4000ab4c
	retw.n                          # 4000ab4f
.L4000ab51:
	l8ui	a6, a3, 0               # 4000ab51
	s8i	a6, a5, 0               # 4000ab54
	retw.n                          # 4000ab57
	.size	fn_4000aa64, . - fn_4000aa64
