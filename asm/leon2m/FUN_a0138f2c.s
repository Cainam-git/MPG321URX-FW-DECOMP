# leon2m FUN_a0138f2c 0xa0138f2c-0xa0138fb8 (140 bytes)
a0138f2c:  9d e3 bf 90  save  %sp, -112, %sp
a0138f30:  96 0e 20 ff  and  %i0, 0xff, %o3
a0138f34:  9e 1a e0 01  xor  %o3, 1, %o7
a0138f38:  80 a0 00 0f  cmp  %g0, %o7
a0138f3c:  98 0e 60 ff  and  %i1, 0xff, %o4
a0138f40:  82 60 3f ff  subx  %g0, -1, %g1
a0138f44:  94 1b 20 01  xor  %o4, 1, %o2
a0138f48:  80 a0 00 0a  cmp  %g0, %o2
a0138f4c:  92 0e a0 ff  and  %i2, 0xff, %o1
a0138f50:  9a 1a 60 01  xor  %o1, 1, %o5
a0138f54:  b2 60 3f ff  subx  %g0, -1, %i1
a0138f58:  80 a0 00 0d  cmp  %g0, %o5
a0138f5c:  c0 27 bf f0  clr  [ %fp + -16 ]
a0138f60:  90 0e e0 ff  and  %i3, 0xff, %o0
a0138f64:  9e 60 3f ff  subx  %g0, -1, %o7
a0138f68:  b6 1a 20 01  xor  %o0, 1, %i3
a0138f6c:  f4 0f bf f0  ldub  [ %fp + -16 ], %i2
a0138f70:  b0 16 80 01  or  %i2, %g1, %i0
a0138f74:  96 06 40 19  add  %i1, %i1, %o3
a0138f78:  80 a0 00 1b  cmp  %g0, %i3
a0138f7c:  98 12 c0 18  or  %o3, %i0, %o4
a0138f80:  95 2b e0 02  sll  %o7, 2, %o2
a0138f84:  92 60 3f ff  subx  %g0, -1, %o1
a0138f88:  91 2a 60 03  sll  %o1, 3, %o0
a0138f8c:  9a 12 80 0c  or  %o2, %o4, %o5
a0138f90:  82 12 00 0d  or  %o0, %o5, %g1
a0138f94:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0138f98:  90 10 20 a3  mov  0xa3, %o0
a0138f9c:  92 10 20 04  mov  4, %o1
a0138fa0:  94 07 bf f0  add  %fp, -16, %o2
a0138fa4:  7f ff f8 4e  call  0xa01370dc
a0138fa8:  96 10 20 00  clr  %o3
a0138fac:  01 00 00 00  nop
a0138fb0:  81 c7 e0 08  ret
a0138fb4:  81 e8 00 00  restore
