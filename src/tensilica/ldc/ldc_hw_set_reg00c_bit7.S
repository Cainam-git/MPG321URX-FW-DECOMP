# ldc_hw_set_reg00c_bit7  (fn_40006884): 0x40006884-0x400068be (firmware file offset 0x36884-0x368be), 22 instructions
# Name basis: descriptive - command 0x43 handler; the bit gates the table write of ldc_hw_write_result_table
# Called from: ldc_cmd_set_reg00c_bit7
# Sets bit 7 of the low byte of register 0xE008000C when the value is not 0, clears it when it is 0 (byte
# access). Called by the command 0x43 handler ldc_cmd_set_reg00c_bit7. ldc_hw_write_result_table writes its table only while this bit
# is set.
# Arguments: a2 on.
# Locals: a1+0 v (new byte value), a1+16 on.
# Returns: nothing.
# Other literal values: 0xe008000c

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_hw_set_reg00c_bit7, @function
ldc_hw_set_reg00c_bit7:                 # fn_40006884
	entry	a1, 64                  # 40006884
	s32i.n	a2, a1, 16              # 40006887
	# if (on == 0) v = *(volatile u8 *)0xE008000C & 0x7F;
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
	# else v = *(volatile u8 *)0xE008000C | 0x80;
	movi	a7, 128                 # 400068a1
	l32r	a6, lit_3ffe1e74        # 400068a4  = 0xe008000c
	memw                            # 400068a7
	l8ui	a6, a6, 0               # 400068aa
	or	a6, a6, a7              # 400068ad
	s32i.n	a6, a1, 0               # 400068b0
.L400068b2:
	# *(volatile u8 *)0xE008000C = v;
	l32r	a8, lit_3ffe1e74        # 400068b2  = 0xe008000c
	memw                            # 400068b5
	l32i.n	a7, a1, 0               # 400068b8
	s8i	a7, a8, 0               # 400068ba
	retw.n                          # 400068bd
	.size	ldc_hw_set_reg00c_bit7, . - ldc_hw_set_reg00c_bit7
