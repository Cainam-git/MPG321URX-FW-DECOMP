# leon2s FUN_a008d1d8 0xa008d1d8-0xa008d280 (168 bytes)
a008d1d8:  9d e3 bf 98  save  %sp, -104, %sp
a008d1dc:  83 2e 20 10  sll  %i0, 0x10, %g1
a008d1e0:  83 30 60 10  srl  %g1, 0x10, %g1
a008d1e4:  80 a0 67 ff  cmp  %g1, 0x7ff
a008d1e8:  08 80 00 06  bleu  0xa008d200
a008d1ec:  ba 10 20 00  clr  %i5
a008d1f0:  10 80 00 04  b  0xa008d200
a008d1f4:  ba 10 20 01  mov  1, %i5
a008d1f8:  10 80 00 20  b  0xa008d278
a008d1fc:  b0 10 20 01  mov  1, %i0
a008d200:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a008d204:  f6 08 60 02  ldub  [ %g1 + 2 ], %i3	! 0xa8078c02
a008d208:  1f 2a 01 e3  sethi  %hi(0xa8078c00), %o7
a008d20c:  80 a6 e0 00  cmp  %i3, 0
a008d210:  02 80 00 19  be  0xa008d274
a008d214:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a008d218:  82 0f 60 ff  and  %i5, 0xff, %g1
a008d21c:  bb 28 60 02  sll  %g1, 2, %i5
a008d220:  ba 07 40 01  add  %i5, %g1, %i5
a008d224:  b9 2e 20 10  sll  %i0, 0x10, %i4
a008d228:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a008d22c:  b1 37 20 10  srl  %i4, 0x10, %i0
a008d230:  98 10 62 52  or  %g1, 0x252, %o4
a008d234:  9a 07 40 1d  add  %i5, %i5, %o5
a008d238:  b2 10 00 1b  mov  %i3, %i1
a008d23c:  b8 10 00 0f  mov  %o7, %i4
a008d240:  c2 0b e0 01  ldub  [ %o7 + 1 ], %g1
a008d244:  ba 08 60 ff  and  %g1, 0xff, %i5
a008d248:  ba 03 40 1d  add  %o5, %i5, %i5
a008d24c:  b4 00 60 01  add  %g1, 1, %i2
a008d250:  ba 07 40 1d  add  %i5, %i5, %i5
a008d254:  c2 13 00 1d  lduh  [ %o4 + %i5 ], %g1
a008d258:  b6 0e a0 ff  and  %i2, 0xff, %i3
a008d25c:  80 a0 40 18  cmp  %g1, %i0
a008d260:  02 bf ff e6  be  0xa008d1f8
a008d264:  1f 2a 01 e3  sethi  %hi(0xa8078c00), %o7
a008d268:  80 a6 c0 19  cmp  %i3, %i1
a008d26c:  0a bf ff f5  bcs  0xa008d240
a008d270:  f4 2f 20 01  stb  %i2, [ %i4 + 1 ]
a008d274:  b0 10 20 00  clr  %i0
a008d278:  81 c7 e0 08  ret
a008d27c:  81 e8 00 00  restore
