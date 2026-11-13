# leon2m FUN_a011e220 0xa011e220-0xa011e388 (80 bytes)
a011e220:  9d e3 bf 90  save  %sp, -112, %sp
a011e224:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011e228:  b6 10 20 02  mov  2, %i3
a011e22c:  ba 10 20 01  mov  1, %i5
a011e230:  82 10 20 03  mov  3, %g1
a011e234:  f6 2f bf f0  stb  %i3, [ %fp + -16 ]
a011e238:  fa 2f bf f1  stb  %i5, [ %fp + -15 ]
a011e23c:  c2 2f bf f3  stb  %g1, [ %fp + -13 ]
a011e240:  c0 2f bf f2  clrb  [ %fp + -14 ]
a011e244:  80 a6 20 1f  cmp  %i0, 0x1f
a011e248:  18 80 00 4e  bgu  0xa011e380
a011e24c:  b2 0e 60 03  and  %i1, 3, %i1
a011e250:  83 2e 20 02  sll  %i0, 2, %g1
a011e254:  3b 00 02 f5  sethi  %hi(0xbd400), %i5
a011e258:  b0 17 60 f0  or  %i5, 0xf0, %i0	! 0xbd4f0
a011e25c:  f8 06 00 01  ld  [ %i0 + %g1 ], %i4
a011e260:  81 c7 00 00  jmp  %i4
a011e264:  01 00 00 00  nop
a011e268:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011e26c:  80 a6 60 00  cmp  %i1, 0
a011e270:  12 80 00 3e  bne  0xa011e368
a011e274:  39 33 c0 59  sethi  %hi(0xcf016400), %i4
a011e278:  3b 33 c0 59  sethi  %hi(0xcf016400), %i5
a011e27c:  f6 07 40 00  ld  [ %i5 ], %i3
a011e280:  b2 0e ff df  and  %i3, -33, %i1
a011e284:  f2 27 40 00  st  %i1, [ %i5 ]
a011e288:  30 80 00 3e  b,a   0xa011e380
a011e28c:  37 33 c0 58  sethi  %hi(0xcf016000), %i3
a011e290:  b8 16 e1 20  or  %i3, 0x120, %i4	! 0xcf016120
a011e294:  b0 0e 60 ff  and  %i1, 0xff, %i0
a011e298:  f2 07 00 00  ld  [ %i4 ], %i1
a011e29c:  82 0e 60 cf  and  %i1, 0xcf, %g1
a011e2a0:  bb 2e 20 04  sll  %i0, 4, %i5
a011e2a4:  b6 10 40 1d  or  %g1, %i5, %i3
a011e2a8:  f6 27 00 00  st  %i3, [ %i4 ]
a011e2ac:  30 80 00 35  b,a   0xa011e380
a011e2b0:  39 33 c0 58  sethi  %hi(0xcf016000), %i4
a011e2b4:  10 bf ff f8  b  0xa011e294
a011e2b8:  b8 17 21 38  or  %i4, 0x138, %i4	! 0xcf016138
a011e2bc:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a011e2c0:  10 bf ff f5  b  0xa011e294
a011e2c4:  b8 10 61 50  or  %g1, 0x150, %i4	! 0xcf016150
a011e2c8:  3b 33 c0 58  sethi  %hi(0xcf016000), %i5
a011e2cc:  10 bf ff f2  b  0xa011e294
a011e2d0:  b8 17 61 68  or  %i5, 0x168, %i4	! 0xcf016168
a011e2d4:  37 33 c0 58  sethi  %hi(0xcf016000), %i3
a011e2d8:  10 bf ff ef  b  0xa011e294
a011e2dc:  b8 16 e1 80  or  %i3, 0x180, %i4	! 0xcf016180
a011e2e0:  39 33 c0 58  sethi  %hi(0xcf016000), %i4
a011e2e4:  10 bf ff ec  b  0xa011e294
a011e2e8:  b8 17 21 98  or  %i4, 0x198, %i4	! 0xcf016198
a011e2ec:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011e2f0:  31 33 c0 59  sethi  %hi(0xcf016400), %i0
a011e2f4:  80 a6 60 00  cmp  %i1, 0
a011e2f8:  02 bf ff e1  be  0xa011e27c
a011e2fc:  ba 16 20 94  or  %i0, 0x94, %i5
a011e300:  39 33 c0 59  sethi  %hi(0xcf016400), %i4
a011e304:  ba 17 20 94  or  %i4, 0x94, %i5	! 0xcf016494
a011e308:  c2 07 40 00  ld  [ %i5 ], %g1
a011e30c:  b6 07 80 19  add  %fp, %i1, %i3
a011e310:  b2 10 60 20  or  %g1, 0x20, %i1
a011e314:  f2 27 40 00  st  %i1, [ %i5 ]
a011e318:  b8 17 20 04  or  %i4, 4, %i4
a011e31c:  f2 0e ff f0  ldub  [ %i3 + -16 ], %i1
a011e320:  c2 07 00 00  ld  [ %i4 ], %g1
a011e324:  82 08 60 3f  and  %g1, 0x3f, %g1
a011e328:  bb 2e 60 06  sll  %i1, 6, %i5
a011e32c:  b6 10 40 1d  or  %g1, %i5, %i3
a011e330:  f6 27 00 00  st  %i3, [ %i4 ]
a011e334:  30 80 00 13  b,a   0xa011e380
a011e338:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011e33c:  80 a6 60 01  cmp  %i1, 1
a011e340:  38 80 00 02  bgu,a   0xa011e348
a011e344:  b2 10 20 01  mov  1, %i1
a011e348:  03 33 c0 59  sethi  %hi(0xcf016400), %g1
a011e34c:  b6 10 60 c0  or  %g1, 0xc0, %i3	! 0xcf0164c0
a011e350:  f0 06 c0 00  ld  [ %i3 ], %i0
a011e354:  ba 0e 20 cf  and  %i0, 0xcf, %i5
a011e358:  b9 2e 60 04  sll  %i1, 4, %i4
a011e35c:  b0 17 40 1c  or  %i5, %i4, %i0
a011e360:  f0 26 c0 00  st  %i0, [ %i3 ]
a011e364:  30 80 00 07  b,a   0xa011e380
a011e368:  f0 07 00 00  ld  [ %i4 ], %i0
a011e36c:  ba 16 20 20  or  %i0, 0x20, %i5
a011e370:  b6 07 80 19  add  %fp, %i1, %i3
a011e374:  fa 27 00 00  st  %i5, [ %i4 ]
a011e378:  10 bf ff e9  b  0xa011e31c
a011e37c:  b8 17 20 04  or  %i4, 4, %i4
a011e380:  81 c7 e0 08  ret
a011e384:  81 e8 00 00  restore
