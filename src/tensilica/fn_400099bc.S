# fn_400099bc: 0x400099bc-0x40009a31 (firmware file offset 0x399bc-0x39a31), 52 instructions
# Called from: fn_40000fb4, fn_4000165c, fn_400016a4, fn_400016d4, fn_40001894, fn_40003190, fn_40003814,
#              fn_40003904, fn_40003b98, fn_40003c94, fn_40003cd0, fn_4000498c, fn_40004b08, fn_40004bcc,
#              fn_40004dfc, fn_40004fc0, fn_40005050, fn_40005574, fn_400058dc, fn_40005ba8, fn_40005c24,
#              fn_40005c3c, fn_40005cac, fn_40005de8, fn_40006374, fn_40006434, fn_4000660c, fn_400066d4,
#              fn_40006904, fn_40006afc, fn_4000770c, fn_400077a4, fn_400077fc, fn_40007820, fn_4000784c,
#              fn_40007878, fn_400078a0, fn_400078e8, fn_40007914, fn_40007998, fn_400079b8, fn_40007c50,
#              fn_40008300, fn_400086a4, fn_400089e8, fn_40008af8, fn_40009a90, fn_4000a3cc
# Calls: fn_40009218, fn_400091d0
# Other literal values: 0x00000400, 0x00000404, 0x00000408, 0x0000040c, 0x00000410, 0x00000414, 0x00000420

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_400099bc, @function
fn_400099bc:
	entry	a1, 0x460               # 400099bc
	mov.n	a8, a7                  # 400099bf
	movi.n	a7, 32                  # 400099c1
	add.n	a7, a1, a7              # 400099c3
	l32r	a14, lit_3ffe228c       # 400099c5  = 0x00000400
	add.n	a14, a7, a14            # 400099c8
	s32i.n	a2, a14, 0              # 400099ca
	l32r	a13, lit_3ffe2290       # 400099cc  = 0x00000404
	add.n	a13, a7, a13            # 400099cf
	s32i.n	a3, a13, 0              # 400099d1
	l32r	a12, lit_3ffe2294       # 400099d3  = 0x00000408
	add.n	a12, a7, a12            # 400099d6
	s32i.n	a4, a12, 0              # 400099d8
	l32r	a11, lit_3ffe2298       # 400099da  = 0x0000040c
	add.n	a11, a7, a11            # 400099dd
	s32i.n	a5, a11, 0              # 400099df
	l32r	a10, lit_3ffe229c       # 400099e1  = 0x00000410
	add.n	a10, a7, a10            # 400099e4
	s32i.n	a6, a10, 0              # 400099e6
	l32r	a9, lit_3ffe22a0        # 400099e8  = 0x00000414
	add.n	a9, a7, a9              # 400099eb
	s32i.n	a8, a9, 0               # 400099ed
	addi	a2, a7, 16              # 400099ef
	s32i.n	a2, a1, 4               # 400099f2
	addi.n	a2, a1, 8               # 400099f4
	l32r	a15, lit_3ffe22a4       # 400099f6  = 0x00000420
	add.n	a15, a7, a15            # 400099f9
	mov.n	a15, a15                # 400099fb
	s32i.n	a15, a2, 0              # 400099fd
	addi.n	a15, a1, 8              # 400099ff
	l32r	a14, lit_3ffe228c       # 40009a01  = 0x00000400
	add.n	a14, a7, a14            # 40009a04
	mov.n	a14, a14                # 40009a06
	s32i.n	a14, a15, 4             # 40009a08
	addi.n	a13, a1, 8              # 40009a0a
	movi.n	a12, 4                  # 40009a0c
	s32i.n	a12, a13, 8             # 40009a0e
	l32i.n	a10, a1, 4              # 40009a10
	l32r	a11, lit_3ffe228c       # 40009a12  = 0x00000400
	add.n	a11, a7, a11            # 40009a15
	l32i.n	a11, a11, 0             # 40009a17
	addi.n	a14, a1, 8              # 40009a19
	l32i.n	a12, a14, 0             # 40009a1b
	l32i.n	a13, a14, 4             # 40009a1d
	l32i.n	a14, a14, 8             # 40009a1f
	call8	fn_40009218             # 40009a21
	s32i.n	a10, a1, 20             # 40009a24
	addi.n	a3, a1, 8               # 40009a26
	addi	a10, a7, 16             # 40009a28
	call8	fn_400091d0             # 40009a2b
	l32i.n	a2, a1, 20              # 40009a2e
	retw.n                          # 40009a30
	.size	fn_400099bc, . - fn_400099bc
