# leon2m FUN_a012f1ec 0xa012f1ec-0xa012f2dc (240 bytes)
a012f1ec:  9d e3 bf 98  save  %sp, -104, %sp
a012f1f0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a012f1f4:  80 a6 60 02  cmp  %i1, 2
a012f1f8:  02 80 00 0c  be  0xa012f228
a012f1fc:  b8 10 20 07  mov  7, %i4
a012f200:  80 a6 60 02  cmp  %i1, 2
a012f204:  04 80 00 29  ble  0xa012f2a8
a012f208:  80 a6 60 00  cmp  %i1, 0
a012f20c:  80 a6 60 03  cmp  %i1, 3
a012f210:  02 80 00 06  be  0xa012f228
a012f214:  b8 10 20 08  mov  8, %i4
a012f218:  80 a6 60 04  cmp  %i1, 4
a012f21c:  02 80 00 03  be  0xa012f228
a012f220:  b8 10 20 09  mov  9, %i4
a012f224:  b8 10 20 06  mov  6, %i4
a012f228:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012f22c:  80 a6 20 ff  cmp  %i0, 0xff
a012f230:  02 80 00 29  be  0xa012f2d4
a012f234:  80 a6 20 03  cmp  %i0, 3
a012f238:  18 80 00 27  bgu  0xa012f2d4
a012f23c:  b3 2e 20 04  sll  %i0, 4, %i1
a012f240:  82 26 40 18  sub  %i1, %i0, %g1
a012f244:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a012f248:  b2 16 a3 30  or  %i2, 0x330, %i1	! 0xa802df30
a012f24c:  b7 28 60 03  sll  %g1, 3, %i3
a012f250:  fa 06 40 1b  ld  [ %i1 + %i3 ], %i5
a012f254:  9e 0f 20 ff  and  %i4, 0xff, %o7
a012f258:  bb 37 60 1c  srl  %i5, 0x1c, %i5
a012f25c:  80 a3 c0 1d  cmp  %o7, %i5
a012f260:  18 80 00 1d  bgu  0xa012f2d4
a012f264:  80 a7 60 0c  cmp  %i5, 0xc
a012f268:  02 80 00 14  be  0xa012f2b8
a012f26c:  b4 06 c0 19  add  %i3, %i1, %i2
a012f270:  c2 06 40 1b  ld  [ %i1 + %i3 ], %g1
a012f274:  39 3c 00 00  sethi  %hi(0xf0000000), %i4
a012f278:  ba 28 40 1c  andn  %g1, %i4, %i5
a012f27c:  83 2b e0 1c  sll  %o7, 0x1c, %g1
a012f280:  39 00 3c 00  sethi  %hi(0xf00000), %i4
a012f284:  ba 17 40 01  or  %i5, %g1, %i5
a012f288:  82 2f 40 1c  andn  %i5, %i4, %g1
a012f28c:  c2 26 40 1b  st  %g1, [ %i1 + %i3 ]
a012f290:  f8 06 a0 70  ld  [ %i2 + 0x70 ], %i4
a012f294:  33 00 10 00  sethi  %hi(0x400000), %i1
a012f298:  b6 2f 00 19  andn  %i4, %i1, %i3
a012f29c:  f6 26 a0 70  st  %i3, [ %i2 + 0x70 ]
a012f2a0:  40 00 89 8a  call  0xa01518c8
a012f2a4:  81 e8 00 00  restore
a012f2a8:  02 bf ff e0  be  0xa012f228
a012f2ac:  b8 10 20 05  mov  5, %i4
a012f2b0:  10 bf ff de  b  0xa012f228
a012f2b4:  b8 10 20 06  mov  6, %i4
a012f2b8:  c2 06 a0 70  ld  [ %i2 + 0x70 ], %g1
a012f2bc:  3b 00 00 30  sethi  %hi(0xc000), %i5
a012f2c0:  ba 28 40 1d  andn  %g1, %i5, %i5
a012f2c4:  39 00 00 20  sethi  %hi(0x8000), %i4
a012f2c8:  ba 17 40 1c  or  %i5, %i4, %i5
a012f2cc:  10 bf ff e9  b  0xa012f270
a012f2d0:  fa 26 a0 70  st  %i5, [ %i2 + 0x70 ]
a012f2d4:  81 c7 e0 08  ret
a012f2d8:  81 e8 00 00  restore
