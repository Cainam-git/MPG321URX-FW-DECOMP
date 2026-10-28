# fn_4000a9c0: 0x4000a9c0-0x4000aa60 (firmware file offset 0x3a9c0-0x3aa60), 52 instructions
# Called from: fn_4000a890
# Addresses loaded: .L4000a9f4
# Other literal values: 0xe0000000

	.space	12, 0                   # 12 zero bytes after the previous function, 0x4000a9b4-0x4000a9bf
	.type	fn_4000a9c0, @function
fn_4000a9c0:
	entry	a1, 16                  # 4000a9c0
	l32r	a5, lit_3ffe2384        # 4000a9c3  = 0xe0000000
	l32r	a6, lit_3ffe2388        # 4000a9c6  = .L4000a9f4
	movi.n	a3, 0                   # 4000a9c9
	mov.n	a7, a2                  # 4000a9cb
	and	a6, a6, a5              # 4000a9cd
	j	.L4000a9f4              # 4000a9d0
	.space	13, 0                   # 13 zero bytes, 0x4000a9d3-0x4000a9df
.L4000a9e0:
	witlb	a4, a3                  # 4000a9e0
	isync                           # 4000a9e3
	nop.n                           # 4000a9e6
	nop                             # 4000a9e8
	sub	a3, a3, a5              # 4000a9eb
	bltui	a3, 16, .L4000aa06      # 4000a9ee
.L4000a9f1:
	srli	a7, a7, 4               # 4000a9f1
.L4000a9f4:
	extui	a4, a7, 0, 4            # 4000a9f4
	beq	a3, a6, .L4000a9e0      # 4000a9f7
	witlb	a4, a3                  # 4000a9fa
	sub	a3, a3, a5              # 4000a9fd
	bgeui	a3, 16, .L4000a9f1      # 4000aa00
	isync                           # 4000aa03
.L4000aa06:
	l32r	a5, lit_3ffe2384        # 4000aa06  = 0xe0000000
	movi.n	a3, 0                   # 4000aa09
	mov.n	a7, a2                  # 4000aa0b
.L4000aa0d:
	extui	a4, a7, 0, 4            # 4000aa0d
	wdtlb	a4, a3                  # 4000aa10
	sub	a3, a3, a5              # 4000aa13
	srli	a7, a7, 4               # 4000aa16
	bgeui	a3, 16, .L4000aa0d      # 4000aa19
	dsync                           # 4000aa1c
	retw.n                          # 4000aa1f
	.space	4, 0                    # 4 zero bytes, 0x4000aa21-0x4000aa24
.L4000aa25:
	loopnez	a4, .L4000aa32          # 4000aa25
	l8ui	a6, a3, 0               # 4000aa28
	addi.n	a3, a3, 1               # 4000aa2b
	s8i	a6, a5, 0               # 4000aa2d
	addi.n	a5, a5, 1               # 4000aa30
.L4000aa32:
	retw.n                          # 4000aa32
.L4000aa34:
	bltui	a4, 7, .L4000aa25       # 4000aa34
	l8ui	a6, a3, 0               # 4000aa37
	addi.n	a3, a3, 1               # 4000aa3a
	addi	a4, a4, -1              # 4000aa3c
	s8i	a6, a5, 0               # 4000aa3f
	addi	a5, a5, 1               # 4000aa42
	bbci	a5, 1, .L4000aa70       # 4000aa45
.L4000aa48:
	bltui	a4, 6, .L4000aa25       # 4000aa48
	l8ui	a6, a3, 0               # 4000aa4b
	l8ui	a7, a3, 1               # 4000aa4e
	addi.n	a3, a3, 2               # 4000aa51
	addi	a4, a4, -2              # 4000aa53
	s8i	a6, a5, 0               # 4000aa56
	s8i	a7, a5, 1               # 4000aa59
	addi.n	a5, a5, 2               # 4000aa5c
	j	.L4000aa70              # 4000aa5e
	.size	fn_4000a9c0, . - fn_4000a9c0
