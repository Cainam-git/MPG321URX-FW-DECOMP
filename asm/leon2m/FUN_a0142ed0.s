# leon2m FUN_a0142ed0 0xa0142ed0-0xa0142fcc (252 bytes)
a0142ed0:  9d e3 bf 98  save  %sp, -104, %sp
a0142ed4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0142ed8:  25 2a 00 b8  sethi  %hi(0xa802e000), %l2
a0142edc:  96 14 a2 24  or  %l2, 0x224, %o3	! 0xa802e224
a0142ee0:  9e 5e 20 2a  smul  %i0, 0x2a, %o7
a0142ee4:  a2 03 c0 0b  add  %o7, %o3, %l1
a0142ee8:  d4 0c 60 0a  ldub  [ %l1 + 0xa ], %o2
a0142eec:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0142ef0:  a0 0e 60 ff  and  %i1, 0xff, %l0
a0142ef4:  90 1b 40 10  xor  %o5, %l0, %o0
a0142ef8:  80 a0 00 08  cmp  %g0, %o0
a0142efc:  98 40 20 00  addx  %g0, 0, %o4
a0142f00:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0142f04:  80 a0 00 1a  cmp  %g0, %i2
a0142f08:  92 02 bf ef  add  %o2, -17, %o1
a0142f0c:  82 40 20 00  addx  %g0, 0, %g1
a0142f10:  96 0a 60 ff  and  %o1, 0xff, %o3
a0142f14:  80 93 00 01  orcc  %o4, %g1, %g0
a0142f18:  02 80 00 2b  be  0xa0142fc4
a0142f1c:  9a 1b 60 21  xor  %o5, 0x21, %o5
a0142f20:  80 a2 e0 03  cmp  %o3, 3
a0142f24:  b4 60 20 00  subx  %g0, 0, %i2
a0142f28:  80 a0 00 0d  cmp  %g0, %o5
a0142f2c:  82 0e a0 01  and  %i2, 1, %g1
a0142f30:  98 60 3f ff  subx  %g0, -1, %o4
a0142f34:  80 90 40 0c  orcc  %g1, %o4, %g0
a0142f38:  12 80 00 1f  bne  0xa0142fb4
a0142f3c:  90 10 00 18  mov  %i0, %o0
a0142f40:  9e 10 20 02  mov  2, %o7
a0142f44:  92 10 00 10  mov  %l0, %o1
a0142f48:  f2 2c 60 0a  stb  %i1, [ %l1 + 0xa ]
a0142f4c:  de 2c 60 02  stb  %o7, [ %l1 + 2 ]
a0142f50:  7f fe e9 91  call  0xa00fd594
a0142f54:  90 10 00 18  mov  %i0, %o0
a0142f58:  92 10 00 10  mov  %l0, %o1
a0142f5c:  7f fe ea 91  call  0xa00fd9a0
a0142f60:  90 10 00 18  mov  %i0, %o0
a0142f64:  d2 0c 60 0a  ldub  [ %l1 + 0xa ], %o1
a0142f68:  96 02 7f ef  add  %o1, -17, %o3
a0142f6c:  94 0a e0 ff  and  %o3, 0xff, %o2
a0142f70:  80 a2 a0 03  cmp  %o2, 3
a0142f74:  90 60 20 00  subx  %g0, 0, %o0
a0142f78:  9a 1a 60 21  xor  %o1, 0x21, %o5
a0142f7c:  80 a0 00 0d  cmp  %g0, %o5
a0142f80:  b2 0a 20 01  and  %o0, 1, %i1
a0142f84:  a0 60 3f ff  subx  %g0, -1, %l0
a0142f88:  80 96 40 10  orcc  %i1, %l0, %g0
a0142f8c:  02 80 00 03  be  0xa0142f98
a0142f90:  82 10 20 64  mov  0x64, %g1
a0142f94:  82 10 23 e8  mov  0x3e8, %g1
a0142f98:  c2 34 60 10  sth  %g1, [ %l1 + 0x10 ]
a0142f9c:  82 14 a2 24  or  %l2, 0x224, %g1
a0142fa0:  98 5e 20 2a  smul  %i0, 0x2a, %o4
a0142fa4:  a2 03 00 01  add  %o4, %g1, %l1
a0142fa8:  a4 10 20 05  mov  5, %l2
a0142fac:  10 80 00 06  b  0xa0142fc4
a0142fb0:  e4 2c 60 0e  stb  %l2, [ %l1 + 0xe ]
a0142fb4:  7f fe eb b8  call  0xa00fde94
a0142fb8:  01 00 00 00  nop
a0142fbc:  10 bf ff e2  b  0xa0142f44
a0142fc0:  9e 10 20 02  mov  2, %o7	! 0x2
a0142fc4:  81 c7 e0 08  ret
a0142fc8:  81 e8 00 00  restore
