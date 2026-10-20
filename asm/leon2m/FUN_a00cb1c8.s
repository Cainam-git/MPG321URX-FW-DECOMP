# leon2m FUN_a00cb1c8 0xa00cb1c8-0xa00cb3a8 (480 bytes)
a00cb1c8:  9d e3 bf 98  save  %sp, -104, %sp
a00cb1cc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00cb1d0:  80 a4 20 02  cmp  %l0, 2
a00cb1d4:  02 80 00 53  be  0xa00cb320
a00cb1d8:  80 a4 20 03  cmp  %l0, 3
a00cb1dc:  02 80 00 54  be  0xa00cb32c
a00cb1e0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb1e4:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cb1e8:  9a 08 60 ff  and  %g1, 0xff, %o5
a00cb1ec:  96 03 7f d0  add  %o5, -48, %o3
a00cb1f0:  94 0a e0 ff  and  %o3, 0xff, %o2
a00cb1f4:  80 a2 a0 02  cmp  %o2, 2
a00cb1f8:  18 80 00 6a  bgu  0xa00cb3a0
a00cb1fc:  b0 10 20 ff  mov  0xff, %i0
a00cb200:  9a 03 7f d1  add  %o5, -47, %o5
a00cb204:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00cb208:  40 00 3e 7e  call  0xa00dac00
a00cb20c:  da 2b 20 79  stb  %o5, [ %o4 + 0x79 ]	! 0xa802d479
a00cb210:  7f ff b5 af  call  0xa00b88cc
a00cb214:  01 00 00 00  nop
a00cb218:  80 a4 20 02  cmp  %l0, 2
a00cb21c:  02 80 00 24  be  0xa00cb2ac
a00cb220:  80 a4 20 03  cmp  %l0, 3
a00cb224:  02 80 00 45  be  0xa00cb338
a00cb228:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cb22c:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00cb230:  90 10 20 30  mov  0x30, %o0
a00cb234:  9a 10 20 35  mov  0x35, %o5
a00cb238:  9e 10 20 36  mov  0x36, %o7
a00cb23c:  98 10 20 2b  mov  0x2b, %o4
a00cb240:  92 10 20 0d  mov  0xd, %o1
a00cb244:  da 2a e0 78  stb  %o5, [ %o3 + 0x78 ]
a00cb248:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00cb24c:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00cb250:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00cb254:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00cb258:  80 a4 20 02  cmp  %l0, 2
a00cb25c:  02 80 00 21  be  0xa00cb2e0
a00cb260:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00cb264:  80 a4 20 03  cmp  %l0, 3
a00cb268:  02 80 00 41  be  0xa00cb36c
a00cb26c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cb270:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00cb274:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00cb278:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00cb27c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00cb280:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00cb284:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00cb288:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00cb28c:  80 a4 20 02  cmp  %l0, 2
a00cb290:  02 80 00 1d  be  0xa00cb304
a00cb294:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00cb298:  80 a4 20 03  cmp  %l0, 3
a00cb29c:  12 80 00 1d  bne  0xa00cb310
a00cb2a0:  90 10 00 10  mov  %l0, %o0
a00cb2a4:  10 80 00 3c  b  0xa00cb394
a00cb2a8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb2ac:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb2b0:  9e 12 61 28  or  %o1, 0x128, %o7	! 0xa802d128
a00cb2b4:  a0 10 20 30  mov  0x30, %l0
a00cb2b8:  94 10 20 35  mov  0x35, %o2
a00cb2bc:  90 10 20 0d  mov  0xd, %o0
a00cb2c0:  82 10 20 36  mov  0x36, %g1
a00cb2c4:  b0 10 20 2b  mov  0x2b, %i0
a00cb2c8:  d4 2a 61 28  stb  %o2, [ %o1 + 0x128 ]
a00cb2cc:  d0 2b e0 05  stb  %o0, [ %o7 + 5 ]
a00cb2d0:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00cb2d4:  e0 2b e0 03  stb  %l0, [ %o7 + 3 ]
a00cb2d8:  f0 2b e0 04  stb  %i0, [ %o7 + 4 ]
a00cb2dc:  e0 2b e0 02  stb  %l0, [ %o7 + 2 ]
a00cb2e0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00cb2e4:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00cb2e8:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00cb2ec:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00cb2f0:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00cb2f4:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00cb2f8:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00cb2fc:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00cb300:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00cb304:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cb308:  94 13 61 28  or  %o5, 0x128, %o2	! 0xa802d128
a00cb30c:  90 10 20 02  mov  2, %o0
a00cb310:  40 01 f5 36  call  0xa01487e8
a00cb314:  92 10 20 06  mov  6, %o1
a00cb318:  10 80 00 22  b  0xa00cb3a0
a00cb31c:  b0 10 20 00  clr  %i0
a00cb320:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cb324:  10 bf ff b1  b  0xa00cb1e8
a00cb328:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cb32c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cb330:  10 bf ff ae  b  0xa00cb1e8
a00cb334:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cb338:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00cb33c:  98 16 21 08  or  %i0, 0x108, %o4	! 0xa802d108
a00cb340:  9e 10 20 30  mov  0x30, %o7
a00cb344:  82 10 20 35  mov  0x35, %g1
a00cb348:  a0 10 20 0d  mov  0xd, %l0
a00cb34c:  9a 10 20 36  mov  0x36, %o5
a00cb350:  96 10 20 2b  mov  0x2b, %o3
a00cb354:  c2 2e 21 08  stb  %g1, [ %i0 + 0x108 ]
a00cb358:  e0 2b 20 05  stb  %l0, [ %o4 + 5 ]
a00cb35c:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a00cb360:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00cb364:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00cb368:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00cb36c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cb370:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00cb374:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cb378:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cb37c:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00cb380:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00cb384:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00cb388:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00cb38c:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00cb390:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cb394:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00cb398:  10 bf ff de  b  0xa00cb310
a00cb39c:  90 10 20 03  mov  3, %o0
a00cb3a0:  81 c7 e0 08  ret
a00cb3a4:  81 e8 00 00  restore
