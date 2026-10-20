# leon2m FUN_a0150da4 0xa0150da4-0xa0150df8 (84 bytes)
a0150da4:  9d e3 bf 98  save  %sp, -104, %sp
a0150da8:  7f fe 9a e5  call  0xa00f793c
a0150dac:  01 00 00 00  nop
a0150db0:  17 00 03 4f  sethi  %hi(0xd3c00), %o3
a0150db4:  7f fe 9e 7f  call  0xa00f87b0
a0150db8:  90 12 e1 a0  or  %o3, 0x1a0, %o0	! 0xd3da0
a0150dbc:  7f fe 95 80  call  0xa00f63bc
a0150dc0:  90 10 20 00  clr  %o0
a0150dc4:  7f ff aa 48  call  0xa013b6e4
a0150dc8:  90 10 20 00  clr  %o0
a0150dcc:  7f ff aa 51  call  0xa013b710
a0150dd0:  90 10 20 00  clr  %o0
a0150dd4:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a0150dd8:  d2 0b 20 b8  ldub  [ %o4 + 0xb8 ], %o1	! 0xa802a4b8
a0150ddc:  94 0a 60 f0  and  %o1, 0xf0, %o2
a0150de0:  9a 12 a0 30  or  %o2, 0x30, %o5
a0150de4:  90 0a 60 0f  and  %o1, 0xf, %o0
a0150de8:  82 12 00 0d  or  %o0, %o5, %g1
a0150dec:  c2 2b 20 b8  stb  %g1, [ %o4 + 0xb8 ]
a0150df0:  81 c7 e0 08  ret
a0150df4:  81 e8 00 00  restore
