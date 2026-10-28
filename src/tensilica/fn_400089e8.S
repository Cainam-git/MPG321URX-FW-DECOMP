# fn_400089e8: 0x400089e8-0x40008ad4 (firmware file offset 0x389e8-0x38ad4), 82 instructions
# Called from: fn_40005cac
# Calls: fn_400099bc
# Text loaded: "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
# Addresses loaded: ro_3ffe14d0

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400089e8, @function
fn_400089e8:
	entry	a1, 64                  # 400089e8
	s32i.n	a2, a1, 16              # 400089eb
	l32i.n	a5, a1, 16              # 400089ed
	s32i.n	a5, a1, 0               # 400089ef
	l32i.n	a4, a1, 0               # 400089f1
	s32i.n	a4, a1, 4               # 400089f3
	bltui	a4, 32, .L400089fb      # 400089f5
	j	.L40008ac8              # 400089f8
.L400089fb:
	l32r	a7, lit_3ffe2210        # 400089fb  = ro_3ffe14d0
	l32i.n	a6, a1, 4               # 400089fe
	addx4	a6, a6, a7              # 40008a00
	l32i.n	a6, a6, 0               # 40008a03
	jx	a6                      # 40008a05
.L40008a08:
	clrb_expstate	0               # 40008a08
	j	.L40008ad3              # 40008a0b
.L40008a0e:
	clrb_expstate	1               # 40008a0e
	j	.L40008ad3              # 40008a11
.L40008a14:
	clrb_expstate	2               # 40008a14
	j	.L40008ad3              # 40008a17
.L40008a1a:
	clrb_expstate	3               # 40008a1a
	j	.L40008ad3              # 40008a1d
.L40008a20:
	clrb_expstate	4               # 40008a20
	j	.L40008ad3              # 40008a23
.L40008a26:
	clrb_expstate	5               # 40008a26
	j	.L40008ad3              # 40008a29
.L40008a2c:
	clrb_expstate	6               # 40008a2c
	j	.L40008ad3              # 40008a2f
.L40008a32:
	clrb_expstate	7               # 40008a32
	j	.L40008ad3              # 40008a35
.L40008a38:
	clrb_expstate	8               # 40008a38
	j	.L40008ad3              # 40008a3b
.L40008a3e:
	clrb_expstate	9               # 40008a3e
	j	.L40008ad3              # 40008a41
.L40008a44:
	clrb_expstate	10              # 40008a44
	j	.L40008ad3              # 40008a47
.L40008a4a:
	clrb_expstate	11              # 40008a4a
	j	.L40008ad3              # 40008a4d
.L40008a50:
	clrb_expstate	12              # 40008a50
	j	.L40008ad3              # 40008a53
.L40008a56:
	clrb_expstate	13              # 40008a56
	j	.L40008ad3              # 40008a59
.L40008a5c:
	clrb_expstate	14              # 40008a5c
	j	.L40008ad3              # 40008a5f
.L40008a62:
	clrb_expstate	15              # 40008a62
	j	.L40008ad3              # 40008a65
.L40008a68:
	clrb_expstate	16              # 40008a68
	j	.L40008ad3              # 40008a6b
.L40008a6e:
	clrb_expstate	17              # 40008a6e
	j	.L40008ad3              # 40008a71
.L40008a74:
	clrb_expstate	18              # 40008a74
	j	.L40008ad3              # 40008a77
.L40008a7a:
	clrb_expstate	19              # 40008a7a
	j	.L40008ad3              # 40008a7d
.L40008a80:
	clrb_expstate	20              # 40008a80
	j	.L40008ad3              # 40008a83
.L40008a86:
	clrb_expstate	21              # 40008a86
	j	.L40008ad3              # 40008a89
.L40008a8c:
	clrb_expstate	22              # 40008a8c
	j	.L40008ad3              # 40008a8f
.L40008a92:
	clrb_expstate	23              # 40008a92
	j	.L40008ad3              # 40008a95
.L40008a98:
	clrb_expstate	24              # 40008a98
	j	.L40008ad3              # 40008a9b
.L40008a9e:
	clrb_expstate	25              # 40008a9e
	j	.L40008ad3              # 40008aa1
.L40008aa4:
	clrb_expstate	26              # 40008aa4
	j	.L40008ad3              # 40008aa7
.L40008aaa:
	clrb_expstate	27              # 40008aaa
	j	.L40008ad3              # 40008aad
.L40008ab0:
	clrb_expstate	28              # 40008ab0
	j	.L40008ad3              # 40008ab3
.L40008ab6:
	clrb_expstate	29              # 40008ab6
	j	.L40008ad3              # 40008ab9
.L40008abc:
	clrb_expstate	30              # 40008abc
	j	.L40008ad3              # 40008abf
.L40008ac2:
	clrb_expstate	31              # 40008ac2
	j	.L40008ad3              # 40008ac5
.L40008ac8:
	l32r	a10, lit_3ffe2214       # 40008ac8  = ro_3ffe1490 "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
	l32i.n	a11, a1, 16             # 40008acb
	call8	fn_400099bc             # 40008acd
	j	.L40008ad3              # 40008ad0
.L40008ad3:
	retw.n                          # 40008ad3
	.size	fn_400089e8, . - fn_400089e8
