# leon2m FUN_a0121d4c 0xa0121d4c-0xa0121e3c (240 bytes)
a0121d4c:  9d e3 bf 98  save  %sp, -104, %sp
a0121d50:  7f ff 6e b4  call  0xa00fd820
a0121d54:  90 0e 20 ff  and  %i0, 0xff, %o0
a0121d58:  90 0a 20 ff  and  %o0, 0xff, %o0
a0121d5c:  92 1a 20 31  xor  %o0, 0x31, %o1
a0121d60:  80 a0 00 09  cmp  %g0, %o1
a0121d64:  98 60 3f ff  subx  %g0, -1, %o4
a0121d68:  9a 1a 20 41  xor  %o0, 0x41, %o5
a0121d6c:  80 a0 00 0d  cmp  %g0, %o5
a0121d70:  82 60 3f ff  subx  %g0, -1, %g1
a0121d74:  94 1a 20 51  xor  %o0, 0x51, %o2
a0121d78:  80 93 00 01  orcc  %o4, %g1, %g0
a0121d7c:  12 80 00 0a  bne  0xa0121da4
a0121d80:  96 1a 20 61  xor  %o0, 0x61, %o3
a0121d84:  80 a0 00 0a  cmp  %g0, %o2
a0121d88:  9e 60 3f ff  subx  %g0, -1, %o7
a0121d8c:  80 a0 00 0b  cmp  %g0, %o3
a0121d90:  96 60 3f ff  subx  %g0, -1, %o3
a0121d94:  98 1a 20 71  xor  %o0, 0x71, %o4
a0121d98:  80 93 c0 0b  orcc  %o7, %o3, %g0
a0121d9c:  02 80 00 04  be  0xa0121dac
a0121da0:  94 1a 20 81  xor  %o0, 0x81, %o2
a0121da4:  10 80 00 24  b  0xa0121e34
a0121da8:  b0 10 20 00  clr  %i0
a0121dac:  80 a0 00 0c  cmp  %g0, %o4
a0121db0:  b0 60 3f ff  subx  %g0, -1, %i0
a0121db4:  80 a0 00 0a  cmp  %g0, %o2
a0121db8:  94 60 3f ff  subx  %g0, -1, %o2
a0121dbc:  96 1a 20 c1  xor  %o0, 0xc1, %o3
a0121dc0:  80 96 00 0a  orcc  %i0, %o2, %g0
a0121dc4:  12 bf ff f8  bne  0xa0121da4
a0121dc8:  98 1a 20 91  xor  %o0, 0x91, %o4
a0121dcc:  80 a0 00 0b  cmp  %g0, %o3
a0121dd0:  9a 60 3f ff  subx  %g0, -1, %o5
a0121dd4:  80 a0 00 0c  cmp  %g0, %o4
a0121dd8:  82 60 3f ff  subx  %g0, -1, %g1
a0121ddc:  94 1a 20 a1  xor  %o0, 0xa1, %o2
a0121de0:  80 93 40 01  orcc  %o5, %g1, %g0
a0121de4:  12 bf ff f0  bne  0xa0121da4
a0121de8:  96 1a 20 e1  xor  %o0, 0xe1, %o3
a0121dec:  80 a0 00 0a  cmp  %g0, %o2
a0121df0:  9e 60 3f ff  subx  %g0, -1, %o7
a0121df4:  80 a0 00 0b  cmp  %g0, %o3
a0121df8:  96 60 3f ff  subx  %g0, -1, %o3
a0121dfc:  92 1a 20 e2  xor  %o0, 0xe2, %o1
a0121e00:  80 93 c0 0b  orcc  %o7, %o3, %g0
a0121e04:  12 bf ff e8  bne  0xa0121da4
a0121e08:  98 1a 20 b1  xor  %o0, 0xb1, %o4
a0121e0c:  80 a0 00 09  cmp  %g0, %o1
a0121e10:  92 60 3f ff  subx  %g0, -1, %o1
a0121e14:  80 a0 00 0c  cmp  %g0, %o4
a0121e18:  98 60 3f ff  subx  %g0, -1, %o4
a0121e1c:  80 92 40 0c  orcc  %o1, %o4, %g0
a0121e20:  12 bf ff e1  bne  0xa0121da4
a0121e24:  b0 10 20 01  mov  1, %i0
a0121e28:  80 a2 20 e8  cmp  %o0, 0xe8
a0121e2c:  22 80 00 02  be,a   0xa0121e34
a0121e30:  b0 10 20 00  clr  %i0
a0121e34:  81 c7 e0 08  ret
a0121e38:  81 e8 00 00  restore
