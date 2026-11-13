# leon2m FUN_a00c6228 0xa00c6228-0xa00c6424 (508 bytes)
a00c6228:  9d e3 bf 98  save  %sp, -104, %sp
a00c622c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c6230:  80 a4 20 02  cmp  %l0, 2
a00c6234:  02 80 00 5a  be  0xa00c639c
a00c6238:  80 a4 20 03  cmp  %l0, 3
a00c623c:  02 80 00 5b  be  0xa00c63a8
a00c6240:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c6244:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c6248:  96 08 60 ff  and  %g1, 0xff, %o3
a00c624c:  94 02 ff d0  add  %o3, -48, %o2
a00c6250:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c6254:  80 a0 60 01  cmp  %g1, 1
a00c6258:  18 80 00 71  bgu  0xa00c641c
a00c625c:  b0 10 20 ff  mov  0xff, %i0
a00c6260:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6264:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a00c6268:  90 08 60 01  and  %g1, 1, %o0
a00c626c:  d2 03 20 ac  ld  [ %o4 + 0xac ], %o1
a00c6270:  03 00 00 80  sethi  %hi(0x20000), %g1
a00c6274:  b0 2a 40 01  andn  %o1, %g1, %i0
a00c6278:  9b 2a 20 11  sll  %o0, 0x11, %o5
a00c627c:  9e 16 00 0d  or  %i0, %o5, %o7
a00c6280:  de 23 20 ac  st  %o7, [ %o4 + 0xac ]
a00c6284:  40 00 3e 95  call  0xa00d5cd8
a00c6288:  01 00 00 00  nop
a00c628c:  7f ff c9 90  call  0xa00b88cc
a00c6290:  01 00 00 00  nop
a00c6294:  80 a4 20 02  cmp  %l0, 2
a00c6298:  02 80 00 24  be  0xa00c6328
a00c629c:  80 a4 20 03  cmp  %l0, 3
a00c62a0:  02 80 00 45  be  0xa00c63b4
a00c62a4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c62a8:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c62ac:  b0 10 20 30  mov  0x30, %i0
a00c62b0:  82 10 20 35  mov  0x35, %g1
a00c62b4:  92 10 20 36  mov  0x36, %o1
a00c62b8:  90 10 20 2b  mov  0x2b, %o0
a00c62bc:  9a 10 20 0d  mov  0xd, %o5
a00c62c0:  c2 2b 20 78  stb  %g1, [ %o4 + 0x78 ]
a00c62c4:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c62c8:  f0 2a a0 03  stb  %i0, [ %o2 + 3 ]
a00c62cc:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00c62d0:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c62d4:  80 a4 20 02  cmp  %l0, 2
a00c62d8:  02 80 00 21  be  0xa00c635c
a00c62dc:  f0 2a a0 02  stb  %i0, [ %o2 + 2 ]
a00c62e0:  80 a4 20 03  cmp  %l0, 3
a00c62e4:  02 80 00 41  be  0xa00c63e8
a00c62e8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c62ec:  90 12 60 d0  or  %o1, 0xd0, %o0	! 0xa802d0d0
a00c62f0:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c62f4:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]	! 0xa802b09c
a00c62f8:  c0 2a 60 d0  clrb  [ %o1 + 0xd0 ]
a00c62fc:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c6300:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c6304:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c6308:  80 a4 20 02  cmp  %l0, 2
a00c630c:  02 80 00 1d  be  0xa00c6380
a00c6310:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c6314:  80 a4 20 03  cmp  %l0, 3
a00c6318:  12 80 00 1d  bne  0xa00c638c
a00c631c:  90 10 00 10  mov  %l0, %o0
a00c6320:  10 80 00 3c  b  0xa00c6410
a00c6324:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6328:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c632c:  a0 13 61 28  or  %o5, 0x128, %l0	! 0xa802d128
a00c6330:  98 10 20 30  mov  0x30, %o4
a00c6334:  90 10 20 35  mov  0x35, %o0
a00c6338:  b0 10 20 0d  mov  0xd, %i0
a00c633c:  9e 10 20 36  mov  0x36, %o7
a00c6340:  96 10 20 2b  mov  0x2b, %o3
a00c6344:  d0 2b 61 28  stb  %o0, [ %o5 + 0x128 ]
a00c6348:  f0 2c 20 05  stb  %i0, [ %l0 + 5 ]
a00c634c:  de 2c 20 01  stb  %o7, [ %l0 + 1 ]
a00c6350:  d8 2c 20 03  stb  %o4, [ %l0 + 3 ]
a00c6354:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c6358:  d8 2c 20 02  stb  %o4, [ %l0 + 2 ]
a00c635c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c6360:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c6364:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c6368:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c636c:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c6370:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c6374:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c6378:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c637c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c6380:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c6384:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c6388:  90 10 20 02  mov  2, %o0
a00c638c:  40 02 09 17  call  0xa01487e8
a00c6390:  92 10 20 06  mov  6, %o1
a00c6394:  10 80 00 22  b  0xa00c641c
a00c6398:  b0 10 20 00  clr  %i0
a00c639c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c63a0:  10 bf ff aa  b  0xa00c6248
a00c63a4:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c63a8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c63ac:  10 bf ff a7  b  0xa00c6248
a00c63b0:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c63b4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c63b8:  92 12 e1 08  or  %o3, 0x108, %o1	! 0xa802d108
a00c63bc:  94 10 20 30  mov  0x30, %o2
a00c63c0:  9e 10 20 35  mov  0x35, %o7
a00c63c4:  98 10 20 0d  mov  0xd, %o4
a00c63c8:  a0 10 20 36  mov  0x36, %l0
a00c63cc:  82 10 20 2b  mov  0x2b, %g1
a00c63d0:  de 2a e1 08  stb  %o7, [ %o3 + 0x108 ]
a00c63d4:  d8 2a 60 05  stb  %o4, [ %o1 + 5 ]
a00c63d8:  e0 2a 60 01  stb  %l0, [ %o1 + 1 ]
a00c63dc:  d4 2a 60 03  stb  %o2, [ %o1 + 3 ]
a00c63e0:  c2 2a 60 04  stb  %g1, [ %o1 + 4 ]
a00c63e4:  d4 2a 60 02  stb  %o2, [ %o1 + 2 ]
a00c63e8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c63ec:  9e 16 20 98  or  %i0, 0x98, %o7	! 0xa802d098
a00c63f0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c63f4:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]	! 0xa802b098
a00c63f8:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]
a00c63fc:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c6400:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c6404:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c6408:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c640c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c6410:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c6414:  10 bf ff de  b  0xa00c638c
a00c6418:  90 10 20 03  mov  3, %o0
a00c641c:  81 c7 e0 08  ret
a00c6420:  81 e8 00 00  restore
