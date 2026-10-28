# fn_40008af8: 0x40008af8-0x40008be4 (firmware file offset 0x38af8-0x38be4), 82 instructions
# Called from: fn_40005cac
# Calls: fn_400099bc
# Text loaded: "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
# Addresses loaded: ro_3ffe1550

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008af8, @function
fn_40008af8:
	entry	a1, 64                  # 40008af8
	s32i.n	a2, a1, 16              # 40008afb
	l32i.n	a5, a1, 16              # 40008afd
	s32i.n	a5, a1, 0               # 40008aff
	l32i.n	a4, a1, 0               # 40008b01
	s32i.n	a4, a1, 4               # 40008b03
	bltui	a4, 32, .L40008b0b      # 40008b05
	j	.L40008bd8              # 40008b08
.L40008b0b:
	l32r	a7, lit_3ffe2218        # 40008b0b  = ro_3ffe1550
	l32i.n	a6, a1, 4               # 40008b0e
	addx4	a6, a6, a7              # 40008b10
	l32i.n	a6, a6, 0               # 40008b13
	jx	a6                      # 40008b15
.L40008b18:
	setb_expstate	0               # 40008b18
	j	.L40008be3              # 40008b1b
.L40008b1e:
	setb_expstate	1               # 40008b1e
	j	.L40008be3              # 40008b21
.L40008b24:
	setb_expstate	2               # 40008b24
	j	.L40008be3              # 40008b27
.L40008b2a:
	setb_expstate	3               # 40008b2a
	j	.L40008be3              # 40008b2d
.L40008b30:
	setb_expstate	4               # 40008b30
	j	.L40008be3              # 40008b33
.L40008b36:
	setb_expstate	5               # 40008b36
	j	.L40008be3              # 40008b39
.L40008b3c:
	setb_expstate	6               # 40008b3c
	j	.L40008be3              # 40008b3f
.L40008b42:
	setb_expstate	7               # 40008b42
	j	.L40008be3              # 40008b45
.L40008b48:
	setb_expstate	8               # 40008b48
	j	.L40008be3              # 40008b4b
.L40008b4e:
	setb_expstate	9               # 40008b4e
	j	.L40008be3              # 40008b51
.L40008b54:
	setb_expstate	10              # 40008b54
	j	.L40008be3              # 40008b57
.L40008b5a:
	setb_expstate	11              # 40008b5a
	j	.L40008be3              # 40008b5d
.L40008b60:
	setb_expstate	12              # 40008b60
	j	.L40008be3              # 40008b63
.L40008b66:
	setb_expstate	13              # 40008b66
	j	.L40008be3              # 40008b69
.L40008b6c:
	setb_expstate	14              # 40008b6c
	j	.L40008be3              # 40008b6f
.L40008b72:
	setb_expstate	15              # 40008b72
	j	.L40008be3              # 40008b75
.L40008b78:
	setb_expstate	16              # 40008b78
	j	.L40008be3              # 40008b7b
.L40008b7e:
	setb_expstate	17              # 40008b7e
	j	.L40008be3              # 40008b81
.L40008b84:
	setb_expstate	18              # 40008b84
	j	.L40008be3              # 40008b87
.L40008b8a:
	setb_expstate	19              # 40008b8a
	j	.L40008be3              # 40008b8d
.L40008b90:
	setb_expstate	20              # 40008b90
	j	.L40008be3              # 40008b93
.L40008b96:
	setb_expstate	21              # 40008b96
	j	.L40008be3              # 40008b99
.L40008b9c:
	setb_expstate	22              # 40008b9c
	j	.L40008be3              # 40008b9f
.L40008ba2:
	setb_expstate	23              # 40008ba2
	j	.L40008be3              # 40008ba5
.L40008ba8:
	setb_expstate	24              # 40008ba8
	j	.L40008be3              # 40008bab
.L40008bae:
	setb_expstate	25              # 40008bae
	j	.L40008be3              # 40008bb1
.L40008bb4:
	setb_expstate	26              # 40008bb4
	j	.L40008be3              # 40008bb7
.L40008bba:
	setb_expstate	27              # 40008bba
	j	.L40008be3              # 40008bbd
.L40008bc0:
	setb_expstate	28              # 40008bc0
	j	.L40008be3              # 40008bc3
.L40008bc6:
	setb_expstate	29              # 40008bc6
	j	.L40008be3              # 40008bc9
.L40008bcc:
	setb_expstate	30              # 40008bcc
	j	.L40008be3              # 40008bcf
.L40008bd2:
	setb_expstate	31              # 40008bd2
	j	.L40008be3              # 40008bd5
.L40008bd8:
	l32r	a10, lit_3ffe2214       # 40008bd8  = ro_3ffe1490 "[ERR] gpio_set_output: gpio index out of range (%bu)\n"
	l32i.n	a11, a1, 16             # 40008bdb
	call8	fn_400099bc             # 40008bdd
	j	.L40008be3              # 40008be0
.L40008be3:
	retw.n                          # 40008be3
	.size	fn_40008af8, . - fn_40008af8
