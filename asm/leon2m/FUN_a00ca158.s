# leon2m FUN_a00ca158 0xa00ca158-0xa00ca380 (552 bytes)
a00ca158:  9d e3 bf 98  save  %sp, -104, %sp
a00ca15c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00ca160:  80 a4 60 02  cmp  %l1, 2
a00ca164:  02 80 00 62  be  0xa00ca2ec
a00ca168:  80 a4 60 03  cmp  %l1, 3
a00ca16c:  02 80 00 66  be  0xa00ca304
a00ca170:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca174:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00ca178:  96 08 60 ff  and  %g1, 0xff, %o3
a00ca17c:  94 02 ff d0  add  %o3, -48, %o2
a00ca180:  a0 0a a0 ff  and  %o2, 0xff, %l0
a00ca184:  80 a4 20 01  cmp  %l0, 1
a00ca188:  18 80 00 7c  bgu  0xa00ca378
a00ca18c:  b0 10 20 ff  mov  0xff, %i0
a00ca190:  40 01 68 8b  call  0xa01243bc
a00ca194:  90 10 20 01  mov  1, %o0
a00ca198:  80 a4 20 01  cmp  %l0, 1
a00ca19c:  02 80 00 57  be  0xa00ca2f8
a00ca1a0:  01 00 00 00  nop
a00ca1a4:  40 01 6a 43  call  0xa0124ab0
a00ca1a8:  01 00 00 00  nop
a00ca1ac:  40 01 6a 65  call  0xa0124b40
a00ca1b0:  b0 0c 20 01  and  %l0, 1, %i0
a00ca1b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca1b8:  98 12 62 90  or  %o1, 0x290, %o4	! 0xa802d290
a00ca1bc:  d0 03 21 f4  ld  [ %o4 + 0x1f4 ], %o0
a00ca1c0:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00ca1c4:  a0 2a 00 01  andn  %o0, %g1, %l0
a00ca1c8:  9b 2e 20 1e  sll  %i0, 0x1e, %o5
a00ca1cc:  9e 14 00 0d  or  %l0, %o5, %o7
a00ca1d0:  de 23 21 f4  st  %o7, [ %o4 + 0x1f4 ]
a00ca1d4:  40 00 43 e8  call  0xa00db174
a00ca1d8:  01 00 00 00  nop
a00ca1dc:  7f ff b9 bc  call  0xa00b88cc
a00ca1e0:  01 00 00 00  nop
a00ca1e4:  80 a4 60 02  cmp  %l1, 2
a00ca1e8:  02 80 00 24  be  0xa00ca278
a00ca1ec:  80 a4 60 03  cmp  %l1, 3
a00ca1f0:  02 80 00 48  be  0xa00ca310
a00ca1f4:  9e 10 20 30  mov  0x30, %o7
a00ca1f8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ca1fc:  94 16 20 78  or  %i0, 0x78, %o2	! 0xa802d078
a00ca200:  90 10 20 35  mov  0x35, %o0
a00ca204:  9a 10 20 36  mov  0x36, %o5
a00ca208:  a0 10 20 2b  mov  0x2b, %l0
a00ca20c:  98 10 20 0d  mov  0xd, %o4
a00ca210:  d0 2e 20 78  stb  %o0, [ %i0 + 0x78 ]
a00ca214:  da 2a a0 01  stb  %o5, [ %o2 + 1 ]
a00ca218:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00ca21c:  e0 2a a0 04  stb  %l0, [ %o2 + 4 ]
a00ca220:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00ca224:  80 a4 60 02  cmp  %l1, 2
a00ca228:  02 80 00 21  be  0xa00ca2ac
a00ca22c:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ca230:  80 a4 60 03  cmp  %l1, 3
a00ca234:  02 80 00 44  be  0xa00ca344
a00ca238:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca23c:  a0 13 20 d0  or  %o4, 0xd0, %l0	! 0xa802d0d0
a00ca240:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00ca244:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00ca248:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ca24c:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00ca250:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00ca254:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00ca258:  80 a4 60 02  cmp  %l1, 2
a00ca25c:  02 80 00 1d  be  0xa00ca2d0
a00ca260:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00ca264:  80 a4 60 03  cmp  %l1, 3
a00ca268:  12 80 00 1d  bne  0xa00ca2dc
a00ca26c:  90 10 00 11  mov  %l1, %o0
a00ca270:  10 80 00 3f  b  0xa00ca36c
a00ca274:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca278:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00ca27c:  a2 14 21 28  or  %l0, 0x128, %l1	! 0xa802d128
a00ca280:  94 10 20 30  mov  0x30, %o2
a00ca284:  9a 10 20 35  mov  0x35, %o5
a00ca288:  9e 10 20 0d  mov  0xd, %o7
a00ca28c:  98 10 20 36  mov  0x36, %o4
a00ca290:  96 10 20 2b  mov  0x2b, %o3
a00ca294:  da 2c 21 28  stb  %o5, [ %l0 + 0x128 ]
a00ca298:  de 2c 60 05  stb  %o7, [ %l1 + 5 ]
a00ca29c:  d8 2c 60 01  stb  %o4, [ %l1 + 1 ]
a00ca2a0:  d4 2c 60 03  stb  %o2, [ %l1 + 3 ]
a00ca2a4:  d6 2c 60 04  stb  %o3, [ %l1 + 4 ]
a00ca2a8:  d4 2c 60 02  stb  %o2, [ %l1 + 2 ]
a00ca2ac:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ca2b0:  92 14 60 40  or  %l1, 0x40, %o1	! 0xa802d040
a00ca2b4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00ca2b8:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00ca2bc:  c0 2c 60 40  clrb  [ %l1 + 0x40 ]
a00ca2c0:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00ca2c4:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00ca2c8:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00ca2cc:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00ca2d0:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00ca2d4:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00ca2d8:  90 10 20 02  mov  2, %o0
a00ca2dc:  40 01 f9 43  call  0xa01487e8
a00ca2e0:  92 10 20 06  mov  6, %o1
a00ca2e4:  10 80 00 25  b  0xa00ca378
a00ca2e8:  b0 10 20 00  clr  %i0
a00ca2ec:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca2f0:  10 bf ff a2  b  0xa00ca178
a00ca2f4:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ca2f8:  40 01 69 dc  call  0xa0124a68
a00ca2fc:  01 00 00 00  nop
a00ca300:  30 bf ff ab  b,a   0xa00ca1ac
a00ca304:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca308:  10 bf ff 9c  b  0xa00ca178
a00ca30c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00ca310:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ca314:  b0 12 a1 08  or  %o2, 0x108, %i0	! 0xa802d108
a00ca318:  90 10 20 30  mov  0x30, %o0
a00ca31c:  96 10 20 35  mov  0x35, %o3
a00ca320:  a2 10 20 0d  mov  0xd, %l1
a00ca324:  92 10 20 36  mov  0x36, %o1
a00ca328:  82 10 20 2b  mov  0x2b, %g1
a00ca32c:  d6 2a a1 08  stb  %o3, [ %o2 + 0x108 ]
a00ca330:  e2 2e 20 05  stb  %l1, [ %i0 + 5 ]
a00ca334:  d2 2e 20 01  stb  %o1, [ %i0 + 1 ]
a00ca338:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00ca33c:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00ca340:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00ca344:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ca348:  94 12 e0 98  or  %o3, 0x98, %o2	! 0xa802d098
a00ca34c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00ca350:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00ca354:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]
a00ca358:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00ca35c:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00ca360:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00ca364:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00ca368:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ca36c:  94 12 21 08  or  %o0, 0x108, %o2	! 0xa802d108
a00ca370:  10 bf ff db  b  0xa00ca2dc
a00ca374:  90 10 20 03  mov  3, %o0
a00ca378:  81 c7 e0 08  ret
a00ca37c:  81 e8 00 00  restore
