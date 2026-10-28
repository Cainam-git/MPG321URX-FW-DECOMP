# fn_40001830: 0x40001830-0x40001857 (firmware file offset 0x31830-0x31857), 16 instructions
# Address stored in the words at: 0x4000d304
# Calls: fn_4000153c
# Addresses loaded: data_3ffe2390

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40001830, @function
fn_40001830:
	entry	a1, 48                  # 40001830
	s32i.n	a2, a1, 0               # 40001833
	s32i.n	a3, a1, 4               # 40001835
	l32r	a13, lit_3ffe1a98       # 40001837  = data_3ffe2390
	l32i.n	a14, a1, 0              # 4000183a
	extui	a14, a14, 0, 8          # 4000183c
	slli	a14, a14, 2             # 4000183f
	l32i.n	a12, a1, 4              # 40001842
	srli	a12, a12, 14            # 40001844
	or	a12, a12, a14           # 40001847
	s32i.n	a12, a13, 28            # 4000184a
	movi.n	a10, 0                  # 4000184c
	l32i.n	a11, a1, 4              # 4000184e
	extui	a11, a11, 0, 10         # 40001850
	call8	fn_4000153c             # 40001853
	retw.n                          # 40001856
	.size	fn_40001830, . - fn_40001830
