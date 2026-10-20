# leon2m FUN_a014f208 0xa014f208-0xa014f32c (292 bytes)
a014f208:  9d e3 bf 98  save  %sp, -104, %sp
a014f20c:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f210:  98 10 60 80  or  %g1, 0x80, %o4	! 0xa802a480
a014f214:  96 10 20 00  clr  %o3
a014f218:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a014f21c:  b0 10 20 00  clr  %i0
a014f220:  9a 10 20 01  mov  1, %o5
a014f224:  f4 12 a0 80  lduh  [ %o2 + 0x80 ], %i2
a014f228:  bb 2e 20 02  sll  %i0, 2, %i5
a014f22c:  b3 3e 80 1d  sra  %i2, %i5, %i1
a014f230:  9e 0e 60 0f  and  %i1, 0xf, %o7
a014f234:  b2 10 20 00  clr  %i1
a014f238:  b8 10 20 00  clr  %i4
a014f23c:  ba 10 20 00  clr  %i5
a014f240:  10 80 00 05  b  0xa014f254
a014f244:  b4 0b e0 ff  and  %o7, 0xff, %i2
a014f248:  80 a7 60 08  cmp  %i5, 8
a014f24c:  18 80 00 0c  bgu  0xa014f27c
a014f250:  b7 2e 60 10  sll  %i1, 0x10, %i3
a014f254:  c2 0b 00 1d  ldub  [ %o4 + %i5 ], %g1
a014f258:  b8 07 20 01  inc  %i4
a014f25c:  b7 2b 40 1d  sll  %o5, %i5, %i3
a014f260:  80 a6 80 01  cmp  %i2, %g1
a014f264:  12 bf ff f9  bne  0xa014f248
a014f268:  ba 0f 20 ff  and  %i4, 0xff, %i5
a014f26c:  80 a7 60 08  cmp  %i5, 8
a014f270:  08 bf ff f9  bleu  0xa014f254
a014f274:  b2 16 c0 19  or  %i3, %i1, %i1
a014f278:  b7 2e 60 10  sll  %i1, 0x10, %i3
a014f27c:  80 a6 e0 00  cmp  %i3, 0
a014f280:  32 80 00 25  bne,a   0xa014f314
a014f284:  96 02 e0 01  inc  %o3
a014f288:  bb 2e 20 02  sll  %i0, 2, %i5
a014f28c:  b4 10 20 0f  mov  0xf, %i2
a014f290:  b3 2e 80 1d  sll  %i2, %i5, %i1
a014f294:  f8 12 a0 80  lduh  [ %o2 + 0x80 ], %i4
a014f298:  b0 2f 00 19  andn  %i4, %i1, %i0
a014f29c:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014f2a0:  f0 32 a0 80  sth  %i0, [ %o2 + 0x80 ]
a014f2a4:  b0 0b e0 ff  and  %o7, 0xff, %i0
a014f2a8:  b4 10 20 00  clr  %i2
a014f2ac:  b8 10 20 00  clr  %i4
a014f2b0:  f2 12 60 82  lduh  [ %o1 + 0x82 ], %i1
a014f2b4:  83 2e 60 10  sll  %i1, 0x10, %g1
a014f2b8:  b7 2f 20 02  sll  %i4, 2, %i3
a014f2bc:  bb 30 60 10  srl  %g1, 0x10, %i5
a014f2c0:  83 3f 40 1b  sra  %i5, %i3, %g1
a014f2c4:  b4 06 a0 01  inc  %i2
a014f2c8:  82 08 60 0f  and  %g1, 0xf, %g1
a014f2cc:  80 a0 40 18  cmp  %g1, %i0
a014f2d0:  02 80 00 07  be  0xa014f2ec
a014f2d4:  b8 0e a0 ff  and  %i2, 0xff, %i4
a014f2d8:  80 a7 20 03  cmp  %i4, 3
a014f2dc:  08 bf ff f7  bleu  0xa014f2b8
a014f2e0:  83 2e 60 10  sll  %i1, 0x10, %g1
a014f2e4:  10 80 00 0b  b  0xa014f310
a014f2e8:  f2 32 60 82  sth  %i1, [ %o1 + 0x82 ]
a014f2ec:  b0 10 20 10  mov  0x10, %i0
a014f2f0:  b8 06 e0 04  add  %i3, 4, %i4
a014f2f4:  82 26 00 1b  sub  %i0, %i3, %g1
a014f2f8:  b3 3f 40 1c  sra  %i5, %i4, %i1
a014f2fc:  bb 2f 40 01  sll  %i5, %g1, %i5
a014f300:  b5 3f 40 01  sra  %i5, %g1, %i2
a014f304:  b1 2e 40 1b  sll  %i1, %i3, %i0
a014f308:  b2 16 80 18  or  %i2, %i0, %i1
a014f30c:  f2 32 60 82  sth  %i1, [ %o1 + 0x82 ]
a014f310:  96 02 e0 01  inc  %o3
a014f314:  b0 0a e0 ff  and  %o3, 0xff, %i0
a014f318:  80 a6 20 03  cmp  %i0, 3
a014f31c:  08 bf ff c3  bleu  0xa014f228
a014f320:  f4 12 a0 80  lduh  [ %o2 + 0x80 ], %i2
a014f324:  81 c7 e0 08  ret
a014f328:  81 e8 00 00  restore
