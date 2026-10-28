# fn_400008c0: 0x400008c0-0x4000099e (firmware file offset 0x308c0-0x3099e), 95 instructions
# Called from: fn_40000e20, fn_40001344, fn_400013b4
# Calls: fn_4000082c
# Addresses loaded: data_3ffe2760
# Other literal values: 0x3ffe2bf0, 0x3ffe4450, 0x3ffe2d70, 0x00000800, 0x3ffe3d70

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400008c0, @function
fn_400008c0:
	entry	a1, 0x20c0              # 400008c0
	movi.n	a7, 32                  # 400008c3
	add.n	a7, a1, a7              # 400008c5
	l32r	a10, lit_3ffe1a80       # 400008c7  = 0x3ffe2bf0
	l32i.n	a10, a10, 16            # 400008ca
	s32i.n	a10, a1, 4              # 400008cc
	l32r	a9, lit_3ffe1a80        # 400008ce  = 0x3ffe2bf0
	l32i.n	a9, a9, 20              # 400008d1
	s32i.n	a9, a1, 8               # 400008d3
	l32r	a8, lit_3ffe1a84        # 400008d5  = 0x3ffe4450
	l32i.n	a8, a8, 0               # 400008d8
	s32i.n	a8, a1, 12              # 400008da
	l32r	a6, lit_3ffe1a84        # 400008dc  = 0x3ffe4450
	l32i.n	a6, a6, 4               # 400008df
	s32i.n	a6, a1, 16              # 400008e1
	movi.n	a5, 0                   # 400008e3
	s32i.n	a5, a1, 20              # 400008e5
	movi.n	a4, 0                   # 400008e7
	s32i.n	a4, a1, 20              # 400008e9
	l32i.n	a3, a1, 20              # 400008eb
	movi.n	a2, 31                  # 400008ed
	bltu	a2, a3, .L4000090a      # 400008ef
.L400008f2:
	l32i.n	a15, a1, 20             # 400008f2
	mov.n	a2, a7                  # 400008f4
	addx4	a15, a15, a2            # 400008f6
	movi.n	a14, 0                  # 400008f9
	s32i.n	a14, a15, 0             # 400008fb
	l32i.n	a13, a1, 20             # 400008fd
	addi.n	a13, a13, 1             # 400008ff
	s32i.n	a13, a1, 20             # 40000901
	l32i.n	a12, a1, 20             # 40000903
	movi.n	a11, 31                 # 40000905
	bgeu	a11, a12, .L400008f2    # 40000907
.L4000090a:
	movi.n	a5, 0                   # 4000090a
	s32i.n	a5, a1, 20              # 4000090c
	l32r	a4, lit_3ffe1a88        # 4000090e  = data_3ffe2760
	l32i.n	a4, a4, 0               # 40000911
	l32i.n	a3, a1, 20              # 40000913
	bgeu	a3, a4, .L40000985      # 40000915
.L40000918:
	l32i.n	a13, a1, 20             # 40000918
	addi	a14, a7, 127            # 4000091a
	addi.n	a14, a14, 1             # 4000091d
	addx4	a13, a13, a14           # 4000091f
	l32i.n	a2, a1, 16              # 40000922
	l32i.n	a3, a1, 12              # 40000924
	l32i.n	a4, a1, 20              # 40000926
	l32i.n	a15, a1, 4              # 40000928
	mull	a15, a15, a4            # 4000092a
	quou	a15, a15, a3            # 4000092d
	quou	a15, a15, a2            # 40000930
	l32i.n	a14, a1, 8              # 40000933
	mull	a14, a14, a15           # 40000935
	l32i.n	a15, a1, 12             # 40000938
	l32i.n	a3, a1, 12              # 4000093a
	l32i.n	a2, a1, 20              # 4000093c
	remu	a2, a2, a3              # 4000093e
	l32i.n	a12, a1, 8              # 40000941
	mull	a12, a12, a2            # 40000943
	quou	a12, a12, a15           # 40000946
	add.n	a12, a12, a14           # 40000949
	s32i.n	a12, a13, 0             # 4000094b
	l32i.n	a10, a1, 20             # 4000094d
	addi	a11, a7, 127            # 4000094f
	addi.n	a11, a11, 1             # 40000952
	addx4	a10, a10, a11           # 40000954
	l32i.n	a10, a10, 0             # 40000957
	l32i.n	a11, a1, 20             # 40000959
	addi	a12, a7, 127            # 4000095b
	addi.n	a12, a12, 1             # 4000095e
	addx4	a11, a11, a12           # 40000960
	l32i.n	a11, a11, 0             # 40000963
	mov.n	a12, a7                 # 40000965
	addx4	a11, a11, a12           # 40000967
	mov.n	a12, a7                 # 4000096a
	addx4	a10, a10, a12           # 4000096c
	l32i.n	a10, a10, 0             # 4000096f
	addi.n	a10, a10, 1             # 40000971
	s32i.n	a10, a11, 0             # 40000973
	l32i.n	a9, a1, 20              # 40000975
	addi.n	a9, a9, 1               # 40000977
	s32i.n	a9, a1, 20              # 40000979
	l32r	a8, lit_3ffe1a88        # 4000097b  = data_3ffe2760
	l32i.n	a8, a8, 0               # 4000097e
	l32i.n	a6, a1, 20              # 40000980
	bltu	a6, a8, .L40000918      # 40000982
.L40000985:
	addi	a10, a7, 127            # 40000985
	addi.n	a10, a10, 1             # 40000988
	l32r	a11, lit_3ffe1a8c       # 4000098a  = 0x3ffe2d70
	l32r	a12, lit_3ffe1a90       # 4000098d  = 0x00000800
	call8	fn_4000082c             # 40000990
	mov.n	a10, a7                 # 40000993
	l32r	a11, lit_3ffe1a94       # 40000995  = 0x3ffe3d70
	movi.n	a12, 32                 # 40000998
	call8	fn_4000082c             # 4000099a
	retw.n                          # 4000099d
	.size	fn_400008c0, . - fn_400008c0
