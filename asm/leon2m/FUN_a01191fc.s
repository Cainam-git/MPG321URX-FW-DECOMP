# leon2m FUN_a01191fc 0xa01191fc-0xa011926c (112 bytes)
a01191fc:  9d e3 bf 98  save  %sp, -104, %sp
a0119200:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0119204:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a0119208:  b8 13 e2 a8  or  %o7, 0x2a8, %i4	! 0xa8027aa8
a011920c:  ba 06 00 18  add  %i0, %i0, %i5
a0119210:  c2 17 00 1d  lduh  [ %i4 + %i5 ], %g1
a0119214:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0119218:  9a 10 00 1c  mov  %i4, %o5
a011921c:  b8 00 40 19  add  %g1, %i1, %i4
a0119220:  9e 10 00 1d  mov  %i5, %o7
a0119224:  b1 2f 20 02  sll  %i4, 2, %i0
a0119228:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a011922c:  82 16 00 1d  or  %i0, %i5, %g1
a0119230:  c2 00 40 00  ld  [ %g1 ], %g1
a0119234:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0119238:  80 a6 e0 01  cmp  %i3, 1
a011923c:  02 80 00 03  be  0xa0119248
a0119240:  b8 10 40 1a  or  %g1, %i2, %i4
a0119244:  b8 28 40 1a  andn  %g1, %i2, %i4
a0119248:  f0 13 40 0f  lduh  [ %o5 + %o7 ], %i0
a011924c:  82 06 00 19  add  %i0, %i1, %g1
a0119250:  b7 28 60 02  sll  %g1, 2, %i3
a0119254:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a0119258:  b2 16 c0 1d  or  %i3, %i5, %i1
a011925c:  b4 0f 20 ff  and  %i4, 0xff, %i2
a0119260:  f4 26 40 00  st  %i2, [ %i1 ]
a0119264:  81 c7 e0 08  ret
a0119268:  81 e8 00 00  restore
