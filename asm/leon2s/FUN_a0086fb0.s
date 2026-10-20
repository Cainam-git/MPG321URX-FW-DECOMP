# leon2s FUN_a0086fb0 0xa0086fb0-0xa0087074 (196 bytes)
a0086fb0:  9d e3 bf 98  save  %sp, -104, %sp
a0086fb4:  b2 0e 60 0f  and  %i1, 0xf, %i1
a0086fb8:  9a 10 00 1b  mov  %i3, %o5
a0086fbc:  9e 10 00 1a  mov  %i2, %o7
a0086fc0:  80 a6 60 01  cmp  %i1, 1
a0086fc4:  f8 0e 20 08  ldub  [ %i0 + 8 ], %i4
a0086fc8:  04 80 00 27  ble  0xa0087064
a0086fcc:  f6 0e 20 0c  ldub  [ %i0 + 0xc ], %i3
a0086fd0:  c2 0e 20 09  ldub  [ %i0 + 9 ], %g1
a0086fd4:  80 a0 40 1c  cmp  %g1, %i4
a0086fd8:  38 80 00 02  bgu,a   0xa0086fe0
a0086fdc:  b8 10 00 01  mov  %g1, %i4
a0086fe0:  f4 0e 20 0d  ldub  [ %i0 + 0xd ], %i2
a0086fe4:  ba 0e e0 ff  and  %i3, 0xff, %i5
a0086fe8:  82 0e a0 ff  and  %i2, 0xff, %g1
a0086fec:  80 a7 40 01  cmp  %i5, %g1
a0086ff0:  2a 80 00 02  bcs,a   0xa0086ff8
a0086ff4:  b6 10 00 1a  mov  %i2, %i3
a0086ff8:  80 a6 60 04  cmp  %i1, 4
a0086ffc:  32 80 00 1b  bne,a   0xa0087068
a0087000:  f8 2b c0 00  stb  %i4, [ %o7 ]
a0087004:  f2 0e 20 0a  ldub  [ %i0 + 0xa ], %i1
a0087008:  ba 0f 20 ff  and  %i4, 0xff, %i5
a008700c:  82 0e 60 ff  and  %i1, 0xff, %g1
a0087010:  80 a7 40 01  cmp  %i5, %g1
a0087014:  2a 80 00 02  bcs,a   0xa008701c
a0087018:  b8 10 00 19  mov  %i1, %i4
a008701c:  f2 0e 20 0b  ldub  [ %i0 + 0xb ], %i1
a0087020:  ba 0f 20 ff  and  %i4, 0xff, %i5
a0087024:  82 0e 60 ff  and  %i1, 0xff, %g1
a0087028:  80 a7 40 01  cmp  %i5, %g1
a008702c:  2a 80 00 02  bcs,a   0xa0087034
a0087030:  b8 10 00 19  mov  %i1, %i4
a0087034:  f2 0e 20 0e  ldub  [ %i0 + 0xe ], %i1
a0087038:  ba 0e e0 ff  and  %i3, 0xff, %i5
a008703c:  82 0e 60 ff  and  %i1, 0xff, %g1
a0087040:  80 a7 40 01  cmp  %i5, %g1
a0087044:  2a 80 00 02  bcs,a   0xa008704c
a0087048:  b6 10 00 19  mov  %i1, %i3
a008704c:  f0 0e 20 0f  ldub  [ %i0 + 0xf ], %i0
a0087050:  ba 0e e0 ff  and  %i3, 0xff, %i5
a0087054:  82 0e 20 ff  and  %i0, 0xff, %g1
a0087058:  80 a7 40 01  cmp  %i5, %g1
a008705c:  2a 80 00 02  bcs,a   0xa0087064
a0087060:  b6 10 00 18  mov  %i0, %i3
a0087064:  f8 2b c0 00  stb  %i4, [ %o7 ]
a0087068:  f6 2b 40 00  stb  %i3, [ %o5 ]
a008706c:  81 c7 e0 08  ret
a0087070:  81 e8 00 00  restore
