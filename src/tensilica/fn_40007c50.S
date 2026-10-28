# fn_40007c50: 0x40007c50-0x40007d3e (firmware file offset 0x37c50-0x37d3e), 92 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls: fn_400099bc
# Text loaded: "AS3824Buf.DevAddr = 0x%04X\n", "AS3824Buf.LockUnlock = 0x%04X\n",
#              "AS3824Buf.CurrOnOff = 0x%04X\n", "AS3824Buf.CurrOnNum = 0x%04X\n",
#              "AS3824Buf.CurrCtrl = 0x%04X\n", "AS3824Buf.PWM_Ctrl = 0x%04X\n",
#              "AS3824Buf.PWM_Period = 0x%04X\n", "AS3824Buf.DAC = 0x%04X\n", "AS3824Buf.Options = 0x%04X\n",
#              "AS3824Buf.HdrMode = 0x%04X\n", "AS3824Buf.BDAC[%02d] = 0x%04X\n",
#              "AS3824Buf.PWM_HT[%02d] = 0x%04X\n", "LED_Mode = 0x%04X\n", "LDC_Mode = 0x%04X\n"
# Addresses loaded: ro_3ffe0eb0
# Other literal values: 0x3ffe54a0, 0x3ffe54c0, 0x3ffe5500, 0x3ffe2d30, 0x3ffe2d34

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40007c50, @function
fn_40007c50:
	entry	a1, 48                  # 40007c50
	movi.n	a12, 0                  # 40007c53
	s32i.n	a12, a1, 0              # 40007c55
	l32r	a10, lit_3ffe2104       # 40007c57  = ro_3ffe0d64 "AS3824Buf.DevAddr = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c5a  = 0x3ffe54a0
	l32i.n	a11, a11, 0             # 40007c5d
	call8	fn_400099bc             # 40007c5f
	l32r	a10, lit_3ffe2108       # 40007c62  = ro_3ffe0d80 "AS3824Buf.LockUnlock = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c65  = 0x3ffe54a0
	l32i.n	a11, a11, 4             # 40007c68
	call8	fn_400099bc             # 40007c6a
	l32r	a10, lit_3ffe210c       # 40007c6d  = ro_3ffe0da0 "AS3824Buf.CurrOnOff = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c70  = 0x3ffe54a0
	l32i.n	a11, a11, 8             # 40007c73
	call8	fn_400099bc             # 40007c75
	l32r	a10, lit_3ffe2110       # 40007c78  = ro_3ffe0dc0 "AS3824Buf.CurrOnNum = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c7b  = 0x3ffe54a0
	l32i.n	a11, a11, 12            # 40007c7e
	call8	fn_400099bc             # 40007c80
	l32r	a10, lit_3ffe2114       # 40007c83  = ro_3ffe0de0 "AS3824Buf.CurrCtrl = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c86  = 0x3ffe54a0
	l32i.n	a11, a11, 16            # 40007c89
	call8	fn_400099bc             # 40007c8b
	l32r	a10, lit_3ffe2118       # 40007c8e  = ro_3ffe0e00 "AS3824Buf.PWM_Ctrl = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c91  = 0x3ffe54a0
	l32i.n	a11, a11, 20            # 40007c94
	call8	fn_400099bc             # 40007c96
	l32r	a10, lit_3ffe211c       # 40007c99  = ro_3ffe0e20 "AS3824Buf.PWM_Period = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007c9c  = 0x3ffe54a0
	l32i.n	a11, a11, 24            # 40007c9f
	call8	fn_400099bc             # 40007ca1
	l32r	a10, lit_3ffe2120       # 40007ca4  = ro_3ffe0e40 "AS3824Buf.DAC = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007ca7  = 0x3ffe54a0
	l32i.n	a11, a11, 28            # 40007caa
	call8	fn_400099bc             # 40007cac
	l32r	a10, lit_3ffe2124       # 40007caf  = ro_3ffe0e58 "AS3824Buf.Options = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007cb2  = 0x3ffe54a0
	l32i	a11, a11, 160           # 40007cb5
	call8	fn_400099bc             # 40007cb8
	l32r	a10, lit_3ffe2128       # 40007cbb  = ro_3ffe0e74 "AS3824Buf.HdrMode = 0x%04X\n"
	l32r	a11, lit_3ffe20ac       # 40007cbe  = 0x3ffe54a0
	l32i	a11, a11, 164           # 40007cc1
	call8	fn_400099bc             # 40007cc4
	movi.n	a14, 0                  # 40007cc7
	s32i.n	a14, a1, 0              # 40007cc9
	l32i.n	a13, a1, 0              # 40007ccb
	movi.n	a12, 15                 # 40007ccd
	bltu	a12, a13, .L40007cf1    # 40007ccf
.L40007cd2:
	l32r	a10, lit_3ffe212c       # 40007cd2  = ro_3ffe0e90 "AS3824Buf.BDAC[%02d] = 0x%04X\n"
	l32i.n	a11, a1, 0              # 40007cd5
	l32i.n	a12, a1, 0              # 40007cd7
	l32r	a13, lit_3ffe20ec       # 40007cd9  = 0x3ffe54c0
	addx4	a12, a12, a13           # 40007cdc
	l32i.n	a12, a12, 0             # 40007cdf
	call8	fn_400099bc             # 40007ce1
	l32i.n	a2, a1, 0               # 40007ce4
	addi.n	a2, a2, 1               # 40007ce6
	s32i.n	a2, a1, 0               # 40007ce8
	l32i.n	a15, a1, 0              # 40007cea
	movi.n	a14, 15                 # 40007cec
	bgeu	a14, a15, .L40007cd2    # 40007cee
.L40007cf1:
	l32r	a10, lit_3ffe2130       # 40007cf1  = ro_3ffe0eb0
	call8	fn_400099bc             # 40007cf4
	movi.n	a5, 0                   # 40007cf7
	s32i.n	a5, a1, 0               # 40007cf9
	l32i.n	a4, a1, 0               # 40007cfb
	movi.n	a3, 15                  # 40007cfd
	bltu	a3, a4, .L40007d21      # 40007cff
.L40007d02:
	l32r	a10, lit_3ffe2134       # 40007d02  = ro_3ffe0eb4 "AS3824Buf.PWM_HT[%02d] = 0x%04X\n"
	l32i.n	a11, a1, 0              # 40007d05
	l32i.n	a12, a1, 0              # 40007d07
	l32r	a13, lit_3ffe20e8       # 40007d09  = 0x3ffe5500
	addx4	a12, a12, a13           # 40007d0c
	l32i.n	a12, a12, 0             # 40007d0f
	call8	fn_400099bc             # 40007d11
	l32i.n	a2, a1, 0               # 40007d14
	addi.n	a2, a2, 1               # 40007d16
	s32i.n	a2, a1, 0               # 40007d18
	l32i.n	a15, a1, 0              # 40007d1a
	movi.n	a14, 15                 # 40007d1c
	bgeu	a14, a15, .L40007d02    # 40007d1e
.L40007d21:
	l32r	a10, lit_3ffe2138       # 40007d21  = ro_3ffe0ed8 "LED_Mode = 0x%04X\n"
	l32r	a11, lit_3ffe20e0       # 40007d24  = 0x3ffe2d30
	l32i.n	a11, a11, 0             # 40007d27
	call8	fn_400099bc             # 40007d29
	l32r	a10, lit_3ffe213c       # 40007d2c  = ro_3ffe0eec "LDC_Mode = 0x%04X\n"
	l32r	a11, lit_3ffe20f8       # 40007d2f  = 0x3ffe2d34
	l32i.n	a11, a11, 0             # 40007d32
	call8	fn_400099bc             # 40007d34
	l32r	a10, lit_3ffe2130       # 40007d37  = ro_3ffe0eb0
	call8	fn_400099bc             # 40007d3a
	retw.n                          # 40007d3d
	.size	fn_40007c50, . - fn_40007c50
