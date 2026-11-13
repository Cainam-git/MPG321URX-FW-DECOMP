# ldc_unit_set_length_and_flag  (fn_40006de8): 0x40006de8-0x40006e91 (firmware file offset 0x36de8-0x36e91), 65 instructions
# Name basis: descriptive - mechanics only; unit = lowest set bit of the mask
# Called from: ldc_units_init, ldc_units_setup_driver_type2
# For the lowest set bit k (0..3) of the unit mask: writes n - 1 to bits 4..13 and bit 0 of flag to bit 3 of
# the unit's control register 0xC0192000 + k * 0x100. Only one unit is handled per call. ldc_units_init passes
# (1, 0, 12); ldc_units_setup_driver_type2 is the other caller.
# Arguments: a2 unit_mask (bits 0..3), a3 flag, a4 n.
# Locals: a1+0 unit_mask, a1+4 flag, a1+8 n.
# Returns: nothing.
# Calls: reg_write32_masked
# Other literal values: 0xc0192000, 0x00003ff0, 0xc0192100, 0xc0192200, 0xc0192300

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_unit_set_length_and_flag, @function
ldc_unit_set_length_and_flag:           # fn_40006de8
	entry	a1, 48                  # 40006de8
	s32i.n	a2, a1, 0               # 40006deb
	s32i.n	a3, a1, 4               # 40006ded
	s32i.n	a4, a1, 8               # 40006def
	# if (unit_mask & 1) {
	l32i.n	a7, a1, 0               # 40006df1
	extui	a7, a7, 0, 1            # 40006df3
	beqz.n	a7, .L40006e1b          # 40006df6
	#     reg_write32_masked(0xC0192000, (n - 1) << 4, 0x3FF0);
	l32r	a10, lit_3ffe1f74       # 40006df8  = 0xc0192000
	l32i.n	a11, a1, 8              # 40006dfb
	addi.n	a11, a11, -1            # 40006dfd
	slli	a11, a11, 4             # 40006dff
	l32r	a12, lit_3ffe1fa0       # 40006e02  = 0x00003ff0
	call8	reg_write32_masked      # 40006e05
	#     reg_write32_masked(0xC0192000, (flag & 1) << 3, 8);
	l32r	a10, lit_3ffe1f74       # 40006e08  = 0xc0192000
	l32i.n	a11, a1, 4              # 40006e0b
	extui	a11, a11, 0, 1          # 40006e0d
	slli	a11, a11, 3             # 40006e10
	movi.n	a12, 8                  # 40006e13
	call8	reg_write32_masked      # 40006e15
	# }
	j	.L40006e90              # 40006e18
.L40006e1b:
	# else if (unit_mask & 2) {
	l32i.n	a12, a1, 0              # 40006e1b
	bbci	a12, 1, .L40006e43      # 40006e1d
	#     reg_write32_masked(0xC0192100, (n - 1) << 4, 0x3FF0);
	l32r	a10, lit_3ffe1f88       # 40006e20  = 0xc0192100
	l32i.n	a11, a1, 8              # 40006e23
	addi.n	a11, a11, -1            # 40006e25
	slli	a11, a11, 4             # 40006e27
	l32r	a12, lit_3ffe1fa0       # 40006e2a  = 0x00003ff0
	call8	reg_write32_masked      # 40006e2d
	#     reg_write32_masked(0xC0192100, (flag & 1) << 3, 8);
	l32r	a10, lit_3ffe1f88       # 40006e30  = 0xc0192100
	l32i.n	a11, a1, 4              # 40006e33
	extui	a11, a11, 0, 1          # 40006e35
	slli	a11, a11, 3             # 40006e38
	movi.n	a12, 8                  # 40006e3b
	call8	reg_write32_masked      # 40006e3d
	# }
	j	.L40006e90              # 40006e40
.L40006e43:
	# else if (unit_mask & 4) {
	l32i.n	a12, a1, 0              # 40006e43
	bbci	a12, 2, .L40006e6b      # 40006e45
	#     reg_write32_masked(0xC0192200, (n - 1) << 4, 0x3FF0);
	l32r	a10, lit_3ffe1f90       # 40006e48  = 0xc0192200
	l32i.n	a11, a1, 8              # 40006e4b
	addi.n	a11, a11, -1            # 40006e4d
	slli	a11, a11, 4             # 40006e4f
	l32r	a12, lit_3ffe1fa0       # 40006e52  = 0x00003ff0
	call8	reg_write32_masked      # 40006e55
	#     reg_write32_masked(0xC0192200, (flag & 1) << 3, 8);
	l32r	a10, lit_3ffe1f90       # 40006e58  = 0xc0192200
	l32i.n	a11, a1, 4              # 40006e5b
	extui	a11, a11, 0, 1          # 40006e5d
	slli	a11, a11, 3             # 40006e60
	movi.n	a12, 8                  # 40006e63
	call8	reg_write32_masked      # 40006e65
	# }
	j	.L40006e90              # 40006e68
.L40006e6b:
	# else if (unit_mask & 8) {
	l32i.n	a12, a1, 0              # 40006e6b
	bbci	a12, 3, .L40006e90      # 40006e6d
	#     reg_write32_masked(0xC0192300, (n - 1) << 4, 0x3FF0);
	l32r	a10, lit_3ffe1f98       # 40006e70  = 0xc0192300
	l32i.n	a11, a1, 8              # 40006e73
	addi.n	a11, a11, -1            # 40006e75
	slli	a11, a11, 4             # 40006e77
	l32r	a12, lit_3ffe1fa0       # 40006e7a  = 0x00003ff0
	call8	reg_write32_masked      # 40006e7d
	#     reg_write32_masked(0xC0192300, (flag & 1) << 3, 8);
	l32r	a10, lit_3ffe1f98       # 40006e80  = 0xc0192300
	l32i.n	a11, a1, 4              # 40006e83
	extui	a11, a11, 0, 1          # 40006e85
	slli	a11, a11, 3             # 40006e88
	movi.n	a12, 8                  # 40006e8b
	call8	reg_write32_masked      # 40006e8d
.L40006e90:
	# }
	retw.n                          # 40006e90
	.size	ldc_unit_set_length_and_flag, . - ldc_unit_set_length_and_flag
