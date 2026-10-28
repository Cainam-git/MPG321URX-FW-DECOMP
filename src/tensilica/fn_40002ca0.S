# fn_40002ca0: 0x40002ca0-0x40002d0b (firmware file offset 0x32ca0-0x32d0b), 46 instructions
# Called from: fn_400030c8
# Addresses loaded: data_3ffe2390
# Other literal values: 0xe0091038

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40002ca0, @function
fn_40002ca0:
	entry	a1, 64                  # 40002ca0
	s32i.n	a2, a1, 16              # 40002ca3
	movi.n	a6, 0                   # 40002ca5
	s32i.n	a6, a1, 0               # 40002ca7
	movi.n	a5, 0                   # 40002ca9
	s32i.n	a5, a1, 4               # 40002cab
	movi.n	a5, 0                   # 40002cad
	l32r	a4, lit_3ffe1bd8        # 40002caf  = 0xe0091038
	memw                            # 40002cb2
	l32i.n	a4, a4, 0               # 40002cb5
	beq	a4, a5, .L40002d0a      # 40002cb7
	l32r	a10, lit_3ffe1bd8       # 40002cba  = 0xe0091038
	memw                            # 40002cbd
	l32i.n	a10, a10, 0             # 40002cc0
	s32i.n	a10, a1, 4              # 40002cc2
	movi.n	a9, 0                   # 40002cc4
	s32i.n	a9, a1, 0               # 40002cc6
	l32r	a8, lit_3ffe1a98        # 40002cc8  = data_3ffe2390
	l32i.n	a8, a8, 0               # 40002ccb
	l32i.n	a7, a1, 0               # 40002ccd
	bgeu	a7, a8, .L40002d0a      # 40002ccf
.L40002cd2:
	l32i.n	a11, a1, 4              # 40002cd2
	l32i.n	a12, a1, 0              # 40002cd4
	ssr	a12                     # 40002cd6
	srl	a11, a11                # 40002cd9
	extui	a11, a11, 0, 1          # 40002cdc
	beqz.n	a11, .L40002cfa         # 40002cdf
	l32i.n	a14, a1, 0              # 40002ce1
	l32i.n	a15, a1, 16             # 40002ce3
	addx4	a14, a14, a15           # 40002ce5
	l32i.n	a14, a14, 0             # 40002ce8
	movi.n	a13, 31                 # 40002cea
	bltu	a13, a14, .L40002cfa    # 40002cec
	l32i.n	a3, a1, 0               # 40002cef
	l32i.n	a4, a1, 16              # 40002cf1
	addx4	a3, a3, a4              # 40002cf3
	movi.n	a2, 32                  # 40002cf6
	s32i.n	a2, a3, 0               # 40002cf8
.L40002cfa:
	l32i.n	a7, a1, 0               # 40002cfa
	addi.n	a7, a7, 1               # 40002cfc
	s32i.n	a7, a1, 0               # 40002cfe
	l32r	a6, lit_3ffe1a98        # 40002d00  = data_3ffe2390
	l32i.n	a6, a6, 0               # 40002d03
	l32i.n	a5, a1, 0               # 40002d05
	bltu	a5, a6, .L40002cd2      # 40002d07
.L40002d0a:
	retw.n                          # 40002d0a
	.size	fn_40002ca0, . - fn_40002ca0
