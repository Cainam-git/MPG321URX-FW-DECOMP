# leon2s TMDS_PowerOff 0xa0074cf8-0xa0074e38 (320 bytes)
a0074cf8:  9d e3 bf 98  save  %sp, -104, %sp
a0074cfc:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0074d00:  90 10 00 11  mov  %l1, %o0
a0074d04:  7f ff fb c8  call  0xa0073c24
a0074d08:  92 10 20 00  clr  %o1
a0074d0c:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a0074d10:  92 10 00 11  mov  %l1, %o1
a0074d14:  7f ff f8 cc  call  0xa0073044
a0074d18:  90 12 22 60  or  %o0, 0x260, %o0
a0074d1c:  90 10 00 11  mov  %l1, %o0
a0074d20:  7f ff fa bf  call  0xa007381c
a0074d24:  92 10 20 00  clr  %o1
a0074d28:  a0 10 00 18  mov  %i0, %l0
a0074d2c:  25 00 00 07  sethi  %hi(0x1c00), %l2
a0074d30:  82 0e 60 ff  and  %i1, 0xff, %g1
a0074d34:  96 14 a0 04  or  %l2, 4, %o3
a0074d38:  90 10 20 01  mov  1, %o0
a0074d3c:  92 10 20 07  mov  7, %o1
a0074d40:  94 10 00 11  mov  %l1, %o2
a0074d44:  b4 10 00 11  mov  %l1, %i2
a0074d48:  b6 14 a3 40  or  %l2, 0x340, %i3
a0074d4c:  b0 10 00 11  mov  %l1, %i0
a0074d50:  b2 10 20 18  mov  0x18, %i1
a0074d54:  80 a0 60 01  cmp  %g1, 1
a0074d58:  12 80 00 24  bne  0xa0074de8
a0074d5c:  a0 04 3f fe  add  %l0, -2, %l0
a0074d60:  40 00 c9 b1  call  0xa00a7424
a0074d64:  b0 10 20 01  mov  1, %i0
a0074d68:  82 0c 20 ff  and  %l0, 0xff, %g1
a0074d6c:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a0074d70:  80 a0 60 01  cmp  %g1, 1
a0074d74:  96 12 e0 04  or  %o3, 4, %o3
a0074d78:  90 10 20 01  mov  1, %o0
a0074d7c:  92 10 20 07  mov  7, %o1
a0074d80:  18 80 00 04  bgu  0xa0074d90
a0074d84:  94 10 00 11  mov  %l1, %o2
a0074d88:  40 00 c9 a7  call  0xa00a7424
a0074d8c:  01 00 00 00  nop
a0074d90:  90 10 00 11  mov  %l1, %o0
a0074d94:  13 00 00 04  sethi  %hi(0x1000), %o1
a0074d98:  94 10 3f 00  mov  -256, %o2
a0074d9c:  40 00 c9 bb  call  0xa00a7488
a0074da0:  96 10 20 f9  mov  0xf9, %o3
a0074da4:  90 10 20 01  mov  1, %o0
a0074da8:  92 10 20 02  mov  2, %o1
a0074dac:  94 10 00 11  mov  %l1, %o2
a0074db0:  40 00 c9 9d  call  0xa00a7424
a0074db4:  96 14 a0 04  or  %l2, 4, %o3
a0074db8:  90 10 20 01  mov  1, %o0
a0074dbc:  92 10 20 10  mov  0x10, %o1
a0074dc0:  94 10 00 11  mov  %l1, %o2
a0074dc4:  40 00 c9 98  call  0xa00a7424
a0074dc8:  96 14 a0 04  or  %l2, 4, %o3
a0074dcc:  90 10 20 01  mov  1, %o0
a0074dd0:  92 10 20 11  mov  0x11, %o1
a0074dd4:  94 10 00 11  mov  %l1, %o2
a0074dd8:  40 00 c9 93  call  0xa00a7424
a0074ddc:  96 14 a0 04  or  %l2, 4, %o3
a0074de0:  40 00 c9 91  call  0xa00a7424
a0074de4:  81 e8 00 00  restore
a0074de8:  90 10 20 00  clr  %o0
a0074dec:  92 10 20 07  mov  7, %o1
a0074df0:  40 00 c9 8d  call  0xa00a7424
a0074df4:  94 10 00 11  mov  %l1, %o2
a0074df8:  82 0c 20 ff  and  %l0, 0xff, %g1
a0074dfc:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a0074e00:  33 00 00 04  sethi  %hi(0x1000), %i1
a0074e04:  b4 10 3f fe  mov  -2, %i2
a0074e08:  b6 10 20 00  clr  %i3
a0074e0c:  80 a0 60 01  cmp  %g1, 1
a0074e10:  96 12 e0 04  or  %o3, 4, %o3
a0074e14:  90 10 20 00  clr  %o0
a0074e18:  92 10 20 07  mov  7, %o1
a0074e1c:  18 80 00 04  bgu  0xa0074e2c
a0074e20:  94 10 00 11  mov  %l1, %o2
a0074e24:  40 00 c9 80  call  0xa00a7424
a0074e28:  01 00 00 00  nop
a0074e2c:  40 00 c9 97  call  0xa00a7488
a0074e30:  81 e8 00 00  restore
a0074e34:  01 00 00 00  nop
