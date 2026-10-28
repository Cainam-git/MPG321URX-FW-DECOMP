# fn_40006884: 0x40006884-0x400068be (firmware file offset 0x36884-0x368be), 22 instructions
# Called from: fn_4000176c
# Other literal values: 0xe008000c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006884, @function
fn_40006884:
	entry	a1, 64                  # 40006884
	s32i.n	a2, a1, 16              # 40006887
	movi.n	a5, 0                   # 40006889
	l32i.n	a4, a1, 16              # 4000688b
	bne	a4, a5, .L400068a1      # 4000688d
	l32r	a5, lit_3ffe1e74        # 40006890  = 0xe008000c
	memw                            # 40006893
	l8ui	a5, a5, 0               # 40006896
	extui	a5, a5, 0, 7            # 40006899
	s32i.n	a5, a1, 0               # 4000689c
	j	.L400068b2              # 4000689e
.L400068a1:
	movi	a7, 128                 # 400068a1
	l32r	a6, lit_3ffe1e74        # 400068a4  = 0xe008000c
	memw                            # 400068a7
	l8ui	a6, a6, 0               # 400068aa
	or	a6, a6, a7              # 400068ad
	s32i.n	a6, a1, 0               # 400068b0
.L400068b2:
	l32r	a8, lit_3ffe1e74        # 400068b2  = 0xe008000c
	memw                            # 400068b5
	l32i.n	a7, a1, 0               # 400068b8
	s8i	a7, a8, 0               # 400068ba
	retw.n                          # 400068bd
	.size	fn_40006884, . - fn_40006884
