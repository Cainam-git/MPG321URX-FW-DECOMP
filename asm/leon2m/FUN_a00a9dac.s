# leon2m FUN_a00a9dac 0xa00a9dac-0xa00a9f30 (388 bytes)
a00a9dac:  9d e3 bf 88  save  %sp, -120, %sp
a00a9db0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a9db4:  80 a0 00 19  cmp  %g0, %i1
a00a9db8:  98 60 3f ff  subx  %g0, -1, %o4
a00a9dbc:  96 03 20 03  add  %o4, 3, %o3
a00a9dc0:  92 0e 20 ff  and  %i0, 0xff, %o1
a00a9dc4:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00a9dc8:  b0 02 40 09  add  %o1, %o1, %i0
a00a9dcc:  90 10 00 11  mov  %l1, %o0
a00a9dd0:  92 10 20 00  clr  %o1
a00a9dd4:  94 10 20 00  clr  %o2
a00a9dd8:  40 02 73 9a  call  0xa0146c40
a00a9ddc:  b0 06 20 05  add  %i0, 5, %i0
a00a9de0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a9de4:  91 2c 20 03  sll  %l0, 3, %o0
a00a9de8:  82 02 00 10  add  %o0, %l0, %g1
a00a9dec:  95 28 60 02  sll  %g1, 2, %o2
a00a9df0:  98 02 a0 51  add  %o2, 0x51, %o4
a00a9df4:  90 10 00 11  mov  %l1, %o0
a00a9df8:  92 10 23 a8  mov  0x3a8, %o1
a00a9dfc:  94 02 a0 1a  add  %o2, 0x1a, %o2
a00a9e00:  96 10 24 f7  mov  0x4f7, %o3
a00a9e04:  9a 10 20 00  clr  %o5
a00a9e08:  80 a6 60 00  cmp  %i1, 0
a00a9e0c:  c0 2f bf f0  clrb  [ %fp + -16 ]
a00a9e10:  c0 2f bf f2  clrb  [ %fp + -14 ]
a00a9e14:  c0 2f bf f3  clrb  [ %fp + -13 ]
a00a9e18:  02 80 00 11  be  0xa00a9e5c
a00a9e1c:  c0 2f bf f4  clrb  [ %fp + -12 ]
a00a9e20:  9e 10 20 04  mov  4, %o7
a00a9e24:  de 2f bf f1  stb  %o7, [ %fp + -15 ]
a00a9e28:  40 02 72 92  call  0xa0146870
a00a9e2c:  31 00 00 16  sethi  %hi(0x5800), %i0
a00a9e30:  90 10 00 11  mov  %l1, %o0
a00a9e34:  92 10 20 01  mov  1, %o1
a00a9e38:  40 02 73 82  call  0xa0146c40
a00a9e3c:  94 10 20 00  clr  %o2
a00a9e40:  90 10 20 01  mov  1, %o0
a00a9e44:  92 10 20 27  mov  0x27, %o1
a00a9e48:  94 10 00 10  mov  %l0, %o2
a00a9e4c:  80 a6 60 00  cmp  %i1, 0
a00a9e50:  02 80 00 35  be  0xa00a9f24
a00a9e54:  96 10 20 0e  mov  0xe, %o3
a00a9e58:  30 80 00 18  b,a   0xa00a9eb8
a00a9e5c:  91 2c 20 03  sll  %l0, 3, %o0
a00a9e60:  82 02 00 10  add  %o0, %l0, %g1
a00a9e64:  95 28 60 02  sll  %g1, 2, %o2
a00a9e68:  9a 10 20 0c  mov  0xc, %o5
a00a9e6c:  98 02 a0 55  add  %o2, 0x55, %o4
a00a9e70:  da 2f bf f1  stb  %o5, [ %fp + -15 ]
a00a9e74:  96 10 24 f7  mov  0x4f7, %o3
a00a9e78:  9a 10 20 00  clr  %o5
a00a9e7c:  90 10 00 11  mov  %l1, %o0
a00a9e80:  92 10 23 a8  mov  0x3a8, %o1
a00a9e84:  40 02 72 7b  call  0xa0146870
a00a9e88:  94 02 a0 16  add  %o2, 0x16, %o2
a00a9e8c:  90 10 00 11  mov  %l1, %o0
a00a9e90:  92 10 20 01  mov  1, %o1
a00a9e94:  40 02 73 6b  call  0xa0146c40
a00a9e98:  94 10 20 00  clr  %o2
a00a9e9c:  31 00 00 16  sethi  %hi(0x5800), %i0
a00a9ea0:  90 10 20 01  mov  1, %o0
a00a9ea4:  92 10 20 27  mov  0x27, %o1
a00a9ea8:  94 10 00 10  mov  %l0, %o2
a00a9eac:  80 a6 60 00  cmp  %i1, 0
a00a9eb0:  02 80 00 1d  be  0xa00a9f24
a00a9eb4:  96 10 20 0e  mov  0xe, %o3
a00a9eb8:  40 00 28 06  call  0xa00b3ed0
a00a9ebc:  b2 10 20 a6  mov  0xa6, %i1
a00a9ec0:  90 10 20 00  clr  %o0
a00a9ec4:  92 10 20 01  mov  1, %o1
a00a9ec8:  94 16 20 9a  or  %i0, 0x9a, %o2
a00a9ecc:  96 10 20 27  mov  0x27, %o3
a00a9ed0:  98 10 00 10  mov  %l0, %o4
a00a9ed4:  9a 10 20 03  mov  3, %o5
a00a9ed8:  40 00 25 03  call  0xa00b32e4
a00a9edc:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a00a9ee0:  a2 10 20 a9  mov  0xa9, %l1
a00a9ee4:  94 16 20 9a  or  %i0, 0x9a, %o2
a00a9ee8:  98 10 00 10  mov  %l0, %o4
a00a9eec:  90 10 20 00  clr  %o0
a00a9ef0:  92 10 20 01  mov  1, %o1
a00a9ef4:  96 10 20 34  mov  0x34, %o3
a00a9ef8:  9a 10 20 03  mov  3, %o5
a00a9efc:  40 00 24 fa  call  0xa00b32e4
a00a9f00:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a00a9f04:  90 10 20 01  mov  1, %o0
a00a9f08:  92 10 20 01  mov  1, %o1
a00a9f0c:  40 02 73 4d  call  0xa0146c40
a00a9f10:  94 10 20 00  clr  %o2
a00a9f14:  90 10 20 02  mov  2, %o0
a00a9f18:  92 10 20 01  mov  1, %o1
a00a9f1c:  40 02 73 49  call  0xa0146c40
a00a9f20:  94 10 20 00  clr  %o2
a00a9f24:  01 00 00 00  nop
a00a9f28:  81 c7 e0 08  ret
a00a9f2c:  81 e8 00 00  restore
