# fn_40006f00: 0x40006f00-0x40007138 (firmware file offset 0x36f00-0x37138), 206 instructions
# Called from: fn_400013a0, fn_4000a3cc
# Calls: fn_40003f24, fn_40006c9c, fn_40006de8, fn_40006e94
# Other literal values: 0xc0192000, 0x02000002, 0xc019200c, 0xc019203c, 0xc0192030, 0xc0192038, 0xc0192100,
#                       0xc019210c, 0xc019213c, 0xc0192130, 0xc0192138, 0xc0192200, 0xc019220c, 0xc019223c,
#                       0xc0192230, 0xc0192238, 0xc0192300, 0xc019230c, 0xc019233c, 0xc0192330, 0xc0192338,
#                       0xc0193008, 0xc0193010, 0xc0193014, 0xc0193018, 0xc019301c, 0xc0193020, 0xc0197040,
#                       0xc0197080, 0xc01a0000, 0xc0197084, 0xc0197088, 0xc019708c, 0x3ffe5490, 0x00010000,
#                       0xc0197000, 0xc0198040, 0xc0198080, 0xc01a1000, 0xc0198084, 0xc0198088, 0xc019808c,
#                       0xc0198000, 0xc0199040, 0xc0199080, 0xc01a2000, 0xc0199084, 0xc0199088, 0xc019908c,
#                       0xc0199000, 0xc019a040, 0xc019a080, 0xc01a3000, 0xc019a084, 0xc019a088, 0xc019a08c,
#                       0xc019a000, 0x01010013

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40006f00, @function
fn_40006f00:
	entry	a1, 32                  # 40006f00
	l32r	a10, lit_3ffe1f74       # 40006f03  = 0xc0192000
	l32r	a11, lit_3ffe1fb8       # 40006f06  = 0x02000002
	call8	fn_40003f24             # 40006f09
	l32r	a10, lit_3ffe1fbc       # 40006f0c  = 0xc019200c
	movi.n	a11, 8                  # 40006f0f
	call8	fn_40003f24             # 40006f11
	l32r	a10, lit_3ffe1fc0       # 40006f14  = 0xc019203c
	movi.n	a11, 0                  # 40006f17
	call8	fn_40003f24             # 40006f19
	l32r	a10, lit_3ffe1fc4       # 40006f1c  = 0xc0192030
	movi.n	a11, 1                  # 40006f1f
	call8	fn_40003f24             # 40006f21
	l32r	a10, lit_3ffe1fa4       # 40006f24  = 0xc0192038
	movi.n	a11, 1                  # 40006f27
	call8	fn_40003f24             # 40006f29
	l32r	a10, lit_3ffe1f88       # 40006f2c  = 0xc0192100
	l32r	a11, lit_3ffe1fb8       # 40006f2f  = 0x02000002
	call8	fn_40003f24             # 40006f32
	l32r	a10, lit_3ffe1fc8       # 40006f35  = 0xc019210c
	movi.n	a11, 8                  # 40006f38
	call8	fn_40003f24             # 40006f3a
	l32r	a10, lit_3ffe1fcc       # 40006f3d  = 0xc019213c
	movi.n	a11, 0                  # 40006f40
	call8	fn_40003f24             # 40006f42
	l32r	a10, lit_3ffe1fd0       # 40006f45  = 0xc0192130
	movi.n	a11, 1                  # 40006f48
	call8	fn_40003f24             # 40006f4a
	l32r	a10, lit_3ffe1fac       # 40006f4d  = 0xc0192138
	movi.n	a11, 1                  # 40006f50
	call8	fn_40003f24             # 40006f52
	l32r	a10, lit_3ffe1f90       # 40006f55  = 0xc0192200
	l32r	a11, lit_3ffe1fb8       # 40006f58  = 0x02000002
	call8	fn_40003f24             # 40006f5b
	l32r	a10, lit_3ffe1fd4       # 40006f5e  = 0xc019220c
	movi.n	a11, 8                  # 40006f61
	call8	fn_40003f24             # 40006f63
	l32r	a10, lit_3ffe1fd8       # 40006f66  = 0xc019223c
	movi.n	a11, 0                  # 40006f69
	call8	fn_40003f24             # 40006f6b
	l32r	a10, lit_3ffe1fdc       # 40006f6e  = 0xc0192230
	movi.n	a11, 1                  # 40006f71
	call8	fn_40003f24             # 40006f73
	l32r	a10, lit_3ffe1fb0       # 40006f76  = 0xc0192238
	movi.n	a11, 1                  # 40006f79
	call8	fn_40003f24             # 40006f7b
	l32r	a10, lit_3ffe1f98       # 40006f7e  = 0xc0192300
	l32r	a11, lit_3ffe1fb8       # 40006f81  = 0x02000002
	call8	fn_40003f24             # 40006f84
	l32r	a10, lit_3ffe1fe0       # 40006f87  = 0xc019230c
	movi.n	a11, 8                  # 40006f8a
	call8	fn_40003f24             # 40006f8c
	l32r	a10, lit_3ffe1fe4       # 40006f8f  = 0xc019233c
	movi.n	a11, 0                  # 40006f92
	call8	fn_40003f24             # 40006f94
	l32r	a10, lit_3ffe1fe8       # 40006f97  = 0xc0192330
	movi.n	a11, 1                  # 40006f9a
	call8	fn_40003f24             # 40006f9c
	l32r	a10, lit_3ffe1fb4       # 40006f9f  = 0xc0192338
	movi.n	a11, 1                  # 40006fa2
	call8	fn_40003f24             # 40006fa4
	l32r	a10, lit_3ffe1fec       # 40006fa7  = 0xc0193008
	movi.n	a11, 1                  # 40006faa
	call8	fn_40003f24             # 40006fac
	l32r	a10, lit_3ffe1ff0       # 40006faf  = 0xc0193010
	movi.n	a11, 0                  # 40006fb2
	call8	fn_40003f24             # 40006fb4
	l32r	a10, lit_3ffe1ff4       # 40006fb7  = 0xc0193014
	movi	a11, 230                # 40006fba
	call8	fn_40003f24             # 40006fbd
	l32r	a10, lit_3ffe1ff8       # 40006fc0  = 0xc0193018
	movi.n	a11, 0                  # 40006fc3
	call8	fn_40003f24             # 40006fc5
	l32r	a10, lit_3ffe1ffc       # 40006fc8  = 0xc019301c
	movi.n	a11, 0                  # 40006fcb
	call8	fn_40003f24             # 40006fcd
	l32r	a10, lit_3ffe2000       # 40006fd0  = 0xc0193020
	movi.n	a11, 0                  # 40006fd3
	call8	fn_40003f24             # 40006fd5
	l32r	a10, lit_3ffe1f54       # 40006fd8  = 0xc0197040
	movi.n	a11, 0                  # 40006fdb
	call8	fn_40003f24             # 40006fdd
	l32r	a10, lit_3ffe2004       # 40006fe0  = 0xc0197080
	l32r	a11, lit_3ffe1f4c       # 40006fe3  = 0xc01a0000
	call8	fn_40003f24             # 40006fe6
	l32r	a10, lit_3ffe2008       # 40006fe9  = 0xc0197084
	l32r	a11, lit_3ffe1f4c       # 40006fec  = 0xc01a0000
	call8	fn_40003f24             # 40006fef
	l32r	a10, lit_3ffe200c       # 40006ff2  = 0xc0197088
	l32r	a11, lit_3ffe1f4c       # 40006ff5  = 0xc01a0000
	call8	fn_40003f24             # 40006ff8
	l32r	a10, lit_3ffe2010       # 40006ffb  = 0xc019708c
	l32r	a11, lit_3ffe1f4c       # 40006ffe  = 0xc01a0000
	call8	fn_40003f24             # 40007001
	l32r	a13, lit_3ffe1f7c       # 40007004  = 0x3ffe5490
	l32r	a12, lit_3ffe2014       # 40007007  = 0x00010000
	s32i.n	a12, a13, 0             # 4000700a
	l32r	a10, lit_3ffe1f84       # 4000700c  = 0xc0197000
	l32r	a11, lit_3ffe1f7c       # 4000700f  = 0x3ffe5490
	l32i.n	a11, a11, 0             # 40007012
	call8	fn_40003f24             # 40007014
	l32r	a10, lit_3ffe1f5c       # 40007017  = 0xc0198040
	movi.n	a11, 0                  # 4000701a
	call8	fn_40003f24             # 4000701c
	l32r	a10, lit_3ffe2018       # 4000701f  = 0xc0198080
	l32r	a11, lit_3ffe201c       # 40007022  = 0xc01a1000
	call8	fn_40003f24             # 40007025
	l32r	a10, lit_3ffe2020       # 40007028  = 0xc0198084
	l32r	a11, lit_3ffe201c       # 4000702b  = 0xc01a1000
	call8	fn_40003f24             # 4000702e
	l32r	a10, lit_3ffe2024       # 40007031  = 0xc0198088
	l32r	a11, lit_3ffe201c       # 40007034  = 0xc01a1000
	call8	fn_40003f24             # 40007037
	l32r	a10, lit_3ffe2028       # 4000703a  = 0xc019808c
	l32r	a11, lit_3ffe201c       # 4000703d  = 0xc01a1000
	call8	fn_40003f24             # 40007040
	l32r	a13, lit_3ffe1f7c       # 40007043  = 0x3ffe5490
	l32r	a12, lit_3ffe2014       # 40007046  = 0x00010000
	s32i.n	a12, a13, 4             # 40007049
	l32r	a10, lit_3ffe1f8c       # 4000704b  = 0xc0198000
	l32r	a11, lit_3ffe1f7c       # 4000704e  = 0x3ffe5490
	l32i.n	a11, a11, 4             # 40007051
	call8	fn_40003f24             # 40007053
	l32r	a10, lit_3ffe1f64       # 40007056  = 0xc0199040
	movi.n	a11, 0                  # 40007059
	call8	fn_40003f24             # 4000705b
	l32r	a10, lit_3ffe202c       # 4000705e  = 0xc0199080
	l32r	a11, lit_3ffe2030       # 40007061  = 0xc01a2000
	call8	fn_40003f24             # 40007064
	l32r	a10, lit_3ffe2034       # 40007067  = 0xc0199084
	l32r	a11, lit_3ffe2030       # 4000706a  = 0xc01a2000
	call8	fn_40003f24             # 4000706d
	l32r	a10, lit_3ffe2038       # 40007070  = 0xc0199088
	l32r	a11, lit_3ffe2030       # 40007073  = 0xc01a2000
	call8	fn_40003f24             # 40007076
	l32r	a10, lit_3ffe203c       # 40007079  = 0xc019908c
	l32r	a11, lit_3ffe2030       # 4000707c  = 0xc01a2000
	call8	fn_40003f24             # 4000707f
	l32r	a13, lit_3ffe1f7c       # 40007082  = 0x3ffe5490
	l32r	a12, lit_3ffe2014       # 40007085  = 0x00010000
	s32i.n	a12, a13, 8             # 40007088
	l32r	a10, lit_3ffe1f94       # 4000708a  = 0xc0199000
	l32r	a11, lit_3ffe1f7c       # 4000708d  = 0x3ffe5490
	l32i.n	a11, a11, 8             # 40007090
	call8	fn_40003f24             # 40007092
	l32r	a10, lit_3ffe1f6c       # 40007095  = 0xc019a040
	movi.n	a11, 0                  # 40007098
	call8	fn_40003f24             # 4000709a
	l32r	a10, lit_3ffe2040       # 4000709d  = 0xc019a080
	l32r	a11, lit_3ffe2044       # 400070a0  = 0xc01a3000
	call8	fn_40003f24             # 400070a3
	l32r	a10, lit_3ffe2048       # 400070a6  = 0xc019a084
	l32r	a11, lit_3ffe2044       # 400070a9  = 0xc01a3000
	call8	fn_40003f24             # 400070ac
	l32r	a10, lit_3ffe204c       # 400070af  = 0xc019a088
	l32r	a11, lit_3ffe2044       # 400070b2  = 0xc01a3000
	call8	fn_40003f24             # 400070b5
	l32r	a10, lit_3ffe2050       # 400070b8  = 0xc019a08c
	l32r	a11, lit_3ffe2044       # 400070bb  = 0xc01a3000
	call8	fn_40003f24             # 400070be
	l32r	a13, lit_3ffe1f7c       # 400070c1  = 0x3ffe5490
	l32r	a12, lit_3ffe2014       # 400070c4  = 0x00010000
	s32i.n	a12, a13, 12            # 400070c7
	l32r	a10, lit_3ffe1f9c       # 400070c9  = 0xc019a000
	l32r	a11, lit_3ffe1f7c       # 400070cc  = 0x3ffe5490
	l32i.n	a11, a11, 12            # 400070cf
	call8	fn_40003f24             # 400070d1
	l32r	a5, lit_3ffe1f7c        # 400070d4  = 0x3ffe5490
	l32r	a4, lit_3ffe2054        # 400070d7  = 0x01010013
	s32i.n	a4, a5, 0               # 400070da
	l32r	a3, lit_3ffe1f7c        # 400070dc  = 0x3ffe5490
	l32r	a2, lit_3ffe2054        # 400070df  = 0x01010013
	s32i.n	a2, a3, 4               # 400070e2
	l32r	a15, lit_3ffe1f7c       # 400070e4  = 0x3ffe5490
	l32r	a14, lit_3ffe2054       # 400070e7  = 0x01010013
	s32i.n	a14, a15, 8             # 400070ea
	l32r	a13, lit_3ffe1f7c       # 400070ec  = 0x3ffe5490
	l32r	a12, lit_3ffe2054       # 400070ef  = 0x01010013
	s32i.n	a12, a13, 12            # 400070f2
	l32r	a10, lit_3ffe1f84       # 400070f4  = 0xc0197000
	l32r	a11, lit_3ffe1f7c       # 400070f7  = 0x3ffe5490
	l32i.n	a11, a11, 0             # 400070fa
	call8	fn_40003f24             # 400070fc
	l32r	a10, lit_3ffe1f8c       # 400070ff  = 0xc0198000
	l32r	a11, lit_3ffe1f7c       # 40007102  = 0x3ffe5490
	l32i.n	a11, a11, 4             # 40007105
	call8	fn_40003f24             # 40007107
	l32r	a10, lit_3ffe1f94       # 4000710a  = 0xc0199000
	l32r	a11, lit_3ffe1f7c       # 4000710d  = 0x3ffe5490
	l32i.n	a11, a11, 8             # 40007110
	call8	fn_40003f24             # 40007112
	l32r	a10, lit_3ffe1f9c       # 40007115  = 0xc019a000
	l32r	a11, lit_3ffe1f7c       # 40007118  = 0x3ffe5490
	l32i.n	a11, a11, 12            # 4000711b
	call8	fn_40003f24             # 4000711d
	movi.n	a10, 1                  # 40007120
	movi.n	a11, 0                  # 40007122
	call8	fn_40006c9c             # 40007124
	movi.n	a10, 1                  # 40007127
	movi.n	a11, 0                  # 40007129
	movi.n	a12, 12                 # 4000712b
	call8	fn_40006de8             # 4000712d
	movi.n	a10, 1                  # 40007130
	movi.n	a11, 0                  # 40007132
	call8	fn_40006e94             # 40007134
	retw.n                          # 40007137
	.size	fn_40006f00, . - fn_40006f00
