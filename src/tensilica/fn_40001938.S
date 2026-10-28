# fn_40001938: 0x40001938-0x40001990 (firmware file offset 0x31938-0x31990), 35 instructions
# Address stored in the words at: 0x4000d364
# Calls: fn_40006904
# Addresses loaded: data_3ffe2410, data_3ffe23e0, data_3ffe2420, data_3ffe2450

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001938, @function
fn_40001938:
	entry	a1, 64                  # 40001938
	s32i.n	a2, a1, 16              # 4000193b
	s32i.n	a3, a1, 20              # 4000193d
	l32i.n	a8, a1, 20              # 4000193f
	extui	a8, a8, 0, 8            # 40001941
	s32i.n	a8, a1, 0               # 40001944
	l32i.n	a7, a1, 0               # 40001946
	s32i.n	a7, a1, 4               # 40001948
	movi.n	a6, 0                   # 4000194a
	l32i.n	a5, a1, 4               # 4000194c
	beq	a5, a6, .L40001963      # 4000194e
	l32i.n	a9, a1, 4               # 40001951
	beqi	a9, 1, .L4000196e       # 40001953
	l32i.n	a10, a1, 4              # 40001956
	beqi	a10, 2, .L40001979      # 40001958
	l32i.n	a11, a1, 4              # 4000195b
	beqi	a11, 3, .L40001984      # 4000195d
	j	.L40001963              # 40001960
.L40001963:
	l32r	a10, lit_3ffe1b24       # 40001963  = data_3ffe2410
	movi.n	a11, 2                  # 40001966
	call8	fn_40006904             # 40001968
	j	.L4000198f              # 4000196b
.L4000196e:
	l32r	a10, lit_3ffe1b20       # 4000196e  = data_3ffe23e0
	movi.n	a11, 5                  # 40001971
	call8	fn_40006904             # 40001973
	j	.L4000198f              # 40001976
.L40001979:
	l32r	a10, lit_3ffe1b60       # 40001979  = data_3ffe2420
	movi.n	a11, 5                  # 4000197c
	call8	fn_40006904             # 4000197e
	j	.L4000198f              # 40001981
.L40001984:
	l32r	a10, lit_3ffe1b64       # 40001984  = data_3ffe2450
	movi.n	a11, 5                  # 40001987
	call8	fn_40006904             # 40001989
	j	.L4000198f              # 4000198c
.L4000198f:
	retw.n                          # 4000198f
	.size	fn_40001938, . - fn_40001938
