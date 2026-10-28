# fn_4000498c: 0x4000498c-0x40004b05 (firmware file offset 0x3498c-0x34b05), 152 instructions
# Address stored in the words at: 0x4000b348
# Calls: fn_4000a010, fn_400099bc, fn_4000496c, fn_4000a08c, fn_40009fc8
# Text loaded: " : ", "            "
# Addresses loaded: ro_3ffe08b4, ro_3ffe08b8, ro_3ffe08bc, ro_3ffe08be

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_4000498c, @function
fn_4000498c:
	entry	a1, 112                 # 4000498c
	s32i	a2, a1, 64              # 4000498f
	s32i	a3, a1, 68              # 40004992
	s32i	a4, a1, 72              # 40004995
	movi.n	a8, 0                   # 40004998
	l32i	a7, a1, 64              # 4000499a
	bne	a7, a8, .L400049a3      # 4000499d
	j	.L40004b04              # 400049a0
.L400049a3:
	movi.n	a10, -4                 # 400049a3
	l32i	a9, a1, 64              # 400049a5
	and	a9, a9, a10             # 400049a8
	s32i	a9, a1, 64              # 400049ab
	movi.n	a9, 0                   # 400049ae
	l32i	a8, a1, 68              # 400049b0
	bne	a8, a9, .L400049bb      # 400049b3
	movi.n	a10, 32                 # 400049b6
	s32i	a10, a1, 68             # 400049b8
.L400049bb:
	l32i	a6, a1, 64              # 400049bb
	s32i.n	a6, a1, 0               # 400049be
	l32i	a5, a1, 68              # 400049c0
	l32i.n	a6, a1, 0               # 400049c3
	addx4	a5, a5, a6              # 400049c5
	s32i.n	a5, a1, 4               # 400049c8
	movi.n	a4, -16                 # 400049ca
	l32i.n	a3, a1, 0               # 400049cc
	and	a3, a3, a4              # 400049ce
	s32i.n	a3, a1, 8               # 400049d1
	movi.n	a3, -16                 # 400049d3
	l32i.n	a2, a1, 4               # 400049d5
	addi.n	a2, a2, 15              # 400049d7
	and	a2, a2, a3              # 400049d9
	s32i.n	a2, a1, 12              # 400049dc
	l32i.n	a15, a1, 8              # 400049de
	s32i.n	a15, a1, 16             # 400049e0
	l32i.n	a14, a1, 8              # 400049e2
	s32i.n	a14, a1, 20             # 400049e4
	l32i.n	a13, a1, 12             # 400049e6
	l32i.n	a12, a1, 20             # 400049e8
	bltu	a12, a13, .L400049f0    # 400049ea
	j	.L40004afe              # 400049ed
.L400049f0:
	l32i.n	a10, a1, 20             # 400049f0
	call8	fn_4000a010             # 400049f2
	l32r	a10, lit_3ffe1d40       # 400049f5  = ro_3ffe08a0 " : "
	call8	fn_400099bc             # 400049f8
	movi.n	a8, 0                   # 400049fb
	s32i.n	a8, a1, 24              # 400049fd
	l32i.n	a7, a1, 24              # 400049ff
	bgei	a7, 4, .L40004a83       # 40004a01
.L40004a04:
	l32i.n	a10, a1, 0              # 40004a04
	l32i.n	a9, a1, 16              # 40004a06
	bltu	a9, a10, .L40004a12     # 40004a08
	l32i.n	a12, a1, 4              # 40004a0b
	l32i.n	a11, a1, 16             # 40004a0d
	bltu	a11, a12, .L40004a27    # 40004a0f
.L40004a12:
	l32i.n	a14, a1, 24             # 40004a12
	addi	a15, a1, 32             # 40004a14
	addx4	a14, a14, a15           # 40004a17
	movi.n	a13, 0                  # 40004a1a
	s32i.n	a13, a14, 0             # 40004a1c
	l32r	a10, lit_3ffe1d44       # 40004a1e  = ro_3ffe08a4 "            "
	call8	fn_400099bc             # 40004a21
	j	.L40004a72              # 40004a24
.L40004a27:
	l32i.n	a10, a1, 16             # 40004a27
	call8	fn_4000496c             # 40004a29
	l32i.n	a6, a1, 24              # 40004a2c
	addi	a7, a1, 32              # 40004a2e
	addx4	a6, a6, a7              # 40004a31
	s32i.n	a10, a6, 0              # 40004a34
	l32i.n	a4, a1, 24              # 40004a36
	addi	a5, a1, 32              # 40004a38
	addx4	a4, a4, a5              # 40004a3b
	l32i.n	a4, a4, 0               # 40004a3e
	s32i.n	a4, a1, 48              # 40004a40
	movi.n	a3, 0                   # 40004a42
	s32i.n	a3, a1, 52              # 40004a44
	l32i.n	a2, a1, 52              # 40004a46
	bgei	a2, 4, .L40004a72       # 40004a48
.L40004a4b:
	l32i.n	a8, a1, 48              # 40004a4b
	l32i.n	a9, a1, 52              # 40004a4d
	slli	a9, a9, 3               # 40004a4f
	ssr	a9                      # 40004a52
	srl	a8, a8                  # 40004a55
	s8i	a8, a1, 56              # 40004a58
	l8ui	a10, a1, 56             # 40004a5b
	call8	fn_4000a08c             # 40004a5e
	l32r	a10, lit_3ffe1d48       # 40004a61  = ro_3ffe08b4
	call8	fn_400099bc             # 40004a64
	l32i.n	a11, a1, 52             # 40004a67
	addi.n	a11, a11, 1             # 40004a69
	s32i.n	a11, a1, 52             # 40004a6b
	l32i.n	a10, a1, 52             # 40004a6d
	blti	a10, 4, .L40004a4b      # 40004a6f
.L40004a72:
	l32i.n	a14, a1, 16             # 40004a72
	addi.n	a14, a14, 4             # 40004a74
	s32i.n	a14, a1, 16             # 40004a76
	l32i.n	a13, a1, 24             # 40004a78
	addi.n	a13, a13, 1             # 40004a7a
	s32i.n	a13, a1, 24             # 40004a7c
	l32i.n	a12, a1, 24             # 40004a7e
	blti	a12, 4, .L40004a04      # 40004a80
.L40004a83:
	l32r	a10, lit_3ffe1d4c       # 40004a83  = ro_3ffe08b8
	call8	fn_400099bc             # 40004a86
	movi.n	a2, 0                   # 40004a89
	s32i.n	a2, a1, 24              # 40004a8b
	l32i.n	a15, a1, 24             # 40004a8d
	bgei	a15, 4, .L40004ae7      # 40004a8f
.L40004a92:
	l32i.n	a5, a1, 24              # 40004a92
	addi	a6, a1, 32              # 40004a94
	addx4	a5, a5, a6              # 40004a97
	l32i.n	a5, a5, 0               # 40004a9a
	s32i.n	a5, a1, 48              # 40004a9c
	movi.n	a4, 0                   # 40004a9e
	s32i.n	a4, a1, 52              # 40004aa0
	l32i.n	a3, a1, 52              # 40004aa2
	bgei	a3, 4, .L40004adc       # 40004aa4
.L40004aa7:
	l32i.n	a9, a1, 48              # 40004aa7
	l32i.n	a10, a1, 52             # 40004aa9
	slli	a10, a10, 3             # 40004aab
	ssr	a10                     # 40004aae
	srl	a9, a9                  # 40004ab1
	s8i	a9, a1, 56              # 40004ab4
	l8ui	a8, a1, 56              # 40004ab7
	addi	a8, a8, -32             # 40004aba
	movi.n	a7, 94                  # 40004abd
	bltu	a7, a8, .L40004acb      # 40004abf
	l8ui	a10, a1, 56             # 40004ac2
	call8	fn_40009fc8             # 40004ac5
	j	.L40004ad1              # 40004ac8
.L40004acb:
	l32r	a10, lit_3ffe1d50       # 40004acb  = ro_3ffe08bc
	call8	fn_400099bc             # 40004ace
.L40004ad1:
	l32i.n	a12, a1, 52             # 40004ad1
	addi.n	a12, a12, 1             # 40004ad3
	s32i.n	a12, a1, 52             # 40004ad5
	l32i.n	a11, a1, 52             # 40004ad7
	blti	a11, 4, .L40004aa7      # 40004ad9
.L40004adc:
	l32i.n	a14, a1, 24             # 40004adc
	addi.n	a14, a14, 1             # 40004ade
	s32i.n	a14, a1, 24             # 40004ae0
	l32i.n	a13, a1, 24             # 40004ae2
	blti	a13, 4, .L40004a92      # 40004ae4
.L40004ae7:
	l32r	a10, lit_3ffe1d54       # 40004ae7  = ro_3ffe08be
	call8	fn_400099bc             # 40004aea
	l32i.n	a3, a1, 20              # 40004aed
	addi	a3, a3, 16              # 40004aef
	s32i.n	a3, a1, 20              # 40004af2
	l32i.n	a2, a1, 12              # 40004af4
	l32i.n	a15, a1, 20             # 40004af6
	bgeu	a15, a2, .L40004afe     # 40004af8
	j	.L400049f0              # 40004afb
.L40004afe:
	l32r	a10, lit_3ffe1d54       # 40004afe  = ro_3ffe08be
	call8	fn_400099bc             # 40004b01
.L40004b04:
	retw.n                          # 40004b04
	.size	fn_4000498c, . - fn_4000498c
