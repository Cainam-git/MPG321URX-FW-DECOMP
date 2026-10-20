# leon2m FUN_a010c194 0xa010c194-0xa010c390 (336 bytes)
a010c194:  9d e3 bf 98  save  %sp, -104, %sp
a010c198:  9a 10 00 19  mov  %i1, %o5
a010c19c:  9e 0e 20 ff  and  %i0, 0xff, %o7
a010c1a0:  b2 10 00 1a  mov  %i2, %i1
a010c1a4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010c1a8:  80 a3 e0 01  cmp  %o7, 1
a010c1ac:  02 80 00 06  be  0xa010c1c4
a010c1b0:  b4 10 63 c4  or  %g1, 0x3c4, %i2
a010c1b4:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a010c1b8:  80 a3 e0 02  cmp  %o7, 2
a010c1bc:  02 80 00 45  be  0xa010c2d0
a010c1c0:  b4 16 e3 44  or  %i3, 0x344, %i2
a010c1c4:  f2 2e a0 26  stb  %i1, [ %i2 + 0x26 ]
a010c1c8:  80 a3 e0 02  cmp  %o7, 2
a010c1cc:  08 80 00 03  bleu  0xa010c1d8
a010c1d0:  da 2e a0 25  stb  %o5, [ %i2 + 0x25 ]
a010c1d4:  b0 10 20 00  clr  %i0
a010c1d8:  82 0e 20 ff  and  %i0, 0xff, %g1
a010c1dc:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010c1e0:  b7 28 60 02  sll  %g1, 2, %i3
a010c1e4:  ba 13 22 d8  or  %o4, 0x2d8, %i5
a010c1e8:  f0 07 40 1b  ld  [ %i5 + %i3 ], %i0
a010c1ec:  f6 06 20 10  ld  [ %i0 + 0x10 ], %i3
a010c1f0:  39 3f c0 00  sethi  %hi(0xff000000), %i4
a010c1f4:  b0 0e 60 ff  and  %i1, 0xff, %i0
a010c1f8:  82 17 20 ff  or  %i4, 0xff, %g1
a010c1fc:  b2 0e c0 01  and  %i3, %g1, %i1
a010c200:  bb 2e 20 10  sll  %i0, 0x10, %i5
a010c204:  82 0b 60 ff  and  %o5, 0xff, %g1
a010c208:  80 a0 60 09  cmp  %g1, 9
a010c20c:  18 80 00 08  bgu  0xa010c22c
a010c210:  b0 16 40 1d  or  %i1, %i5, %i0
a010c214:  3b 00 02 ac  sethi  %hi(0xab000), %i5
a010c218:  b9 28 60 02  sll  %g1, 2, %i4
a010c21c:  b6 17 63 bc  or  %i5, 0x3bc, %i3
a010c220:  f2 06 c0 1c  ld  [ %i3 + %i4 ], %i1
a010c224:  81 c6 40 00  jmp  %i1
a010c228:  01 00 00 00  nop
a010c22c:  ba 10 20 20  mov  0x20, %i5	! 0x20
a010c230:  fa 2e a0 24  stb  %i5, [ %i2 + 0x24 ]
a010c234:  b0 16 22 00  or  %i0, 0x200, %i0
a010c238:  80 a3 e0 02  cmp  %o7, 2
a010c23c:  08 80 00 14  bleu  0xa010c28c
a010c240:  b0 16 20 01  or  %i0, 1, %i0
a010c244:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010c248:  b6 10 62 d8  or  %g1, 0x2d8, %i3	! 0x19aed8
a010c24c:  b8 10 20 00  clr  %i4
a010c250:  b5 2f 20 02  sll  %i4, 2, %i2
a010c254:  f2 06 c0 1a  ld  [ %i3 + %i2 ], %i1
a010c258:  b8 07 20 01  inc  %i4
a010c25c:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010c260:  80 a7 20 02  cmp  %i4, 2
a010c264:  28 bf ff fc  bleu,a   0xa010c254
a010c268:  b5 2f 20 02  sll  %i4, 2, %i2
a010c26c:  80 a3 e0 02  cmp  %o7, 2
a010c270:  18 80 00 0e  bgu  0xa010c2a8
a010c274:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010c278:  b7 2b e0 02  sll  %o7, 2, %i3
a010c27c:  ba 10 62 cc  or  %g1, 0x2cc, %i5
a010c280:  f8 07 40 1b  ld  [ %i5 + %i3 ], %i4
a010c284:  f0 27 20 10  st  %i0, [ %i4 + 0x10 ]
a010c288:  30 80 00 40  b,a   0xa010c388
a010c28c:  ba 13 22 d8  or  %o4, 0x2d8, %i5
a010c290:  b7 2b e0 02  sll  %o7, 2, %i3
a010c294:  f8 07 40 1b  ld  [ %i5 + %i3 ], %i4
a010c298:  f0 27 20 10  st  %i0, [ %i4 + 0x10 ]
a010c29c:  80 a3 e0 02  cmp  %o7, 2
a010c2a0:  08 bf ff f6  bleu  0xa010c278
a010c2a4:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010c2a8:  b6 10 62 cc  or  %g1, 0x2cc, %i3	! 0x19aecc
a010c2ac:  b8 10 20 00  clr  %i4
a010c2b0:  b5 2f 20 02  sll  %i4, 2, %i2
a010c2b4:  f2 06 c0 1a  ld  [ %i3 + %i2 ], %i1
a010c2b8:  b8 07 20 01  inc  %i4
a010c2bc:  f0 26 60 10  st  %i0, [ %i1 + 0x10 ]
a010c2c0:  80 a7 20 02  cmp  %i4, 2
a010c2c4:  08 bf ff fc  bleu  0xa010c2b4
a010c2c8:  b5 2f 20 02  sll  %i4, 2, %i2
a010c2cc:  30 80 00 2f  b,a   0xa010c388
a010c2d0:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a010c2d4:  10 bf ff bc  b  0xa010c1c4
a010c2d8:  b4 17 23 84  or  %i4, 0x384, %i2	! 0xa802d784
a010c2dc:  b6 10 20 20  mov  0x20, %i3
a010c2e0:  f6 2e a0 24  stb  %i3, [ %i2 + 0x24 ]
a010c2e4:  10 bf ff d5  b  0xa010c238
a010c2e8:  b0 16 2a 00  or  %i0, 0xa00, %i0
a010c2ec:  82 10 20 08  mov  8, %g1
a010c2f0:  10 bf ff d2  b  0xa010c238
a010c2f4:  c2 2e a0 24  stb  %g1, [ %i2 + 0x24 ]
a010c2f8:  b2 10 20 10  mov  0x10, %i1
a010c2fc:  f2 2e a0 24  stb  %i1, [ %i2 + 0x24 ]
a010c300:  10 bf ff ce  b  0xa010c238
a010c304:  b0 16 21 00  or  %i0, 0x100, %i0
a010c308:  b8 10 20 10  mov  0x10, %i4
a010c30c:  03 00 00 08  sethi  %hi(0x2000), %g1
a010c310:  f8 2e a0 24  stb  %i4, [ %i2 + 0x24 ]
a010c314:  82 10 61 00  or  %g1, 0x100, %g1
a010c318:  10 bf ff c8  b  0xa010c238
a010c31c:  b0 16 00 01  or  %i0, %g1, %i0
a010c320:  b6 10 20 10  mov  0x10, %i3
a010c324:  03 00 00 10  sethi  %hi(0x4000), %g1
a010c328:  f6 2e a0 24  stb  %i3, [ %i2 + 0x24 ]
a010c32c:  10 bf ff fb  b  0xa010c318
a010c330:  82 10 61 00  or  %g1, 0x100, %g1
a010c334:  ba 10 20 10  mov  0x10, %i5
a010c338:  03 00 00 18  sethi  %hi(0x6000), %g1
a010c33c:  fa 2e a0 24  stb  %i5, [ %i2 + 0x24 ]
a010c340:  10 bf ff f6  b  0xa010c318
a010c344:  82 10 61 00  or  %g1, 0x100, %g1
a010c348:  82 10 20 10  mov  0x10, %g1
a010c34c:  c2 2e a0 24  stb  %g1, [ %i2 + 0x24 ]
a010c350:  03 00 00 20  sethi  %hi(0x8000), %g1
a010c354:  10 bf ff f1  b  0xa010c318
a010c358:  82 10 61 00  or  %g1, 0x100, %g1	! 0x8100
a010c35c:  b2 10 20 10  mov  0x10, %i1
a010c360:  03 00 00 28  sethi  %hi(0xa000), %g1
a010c364:  f2 2e a0 24  stb  %i1, [ %i2 + 0x24 ]
a010c368:  10 bf ff ec  b  0xa010c318
a010c36c:  82 10 61 00  or  %g1, 0x100, %g1
a010c370:  b8 10 20 20  mov  0x20, %i4
a010c374:  f8 2e a0 24  stb  %i4, [ %i2 + 0x24 ]
a010c378:  35 00 00 04  sethi  %hi(0x1000), %i2
a010c37c:  82 16 a2 00  or  %i2, 0x200, %g1	! 0x1200
a010c380:  10 bf ff ae  b  0xa010c238
a010c384:  b0 16 00 01  or  %i0, %g1, %i0
a010c388:  81 c7 e0 08  ret
a010c38c:  81 e8 00 00  restore
