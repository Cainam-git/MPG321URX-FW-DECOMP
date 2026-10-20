# leon2m FUN_a00972cc 0xa00972cc-0xa0097498 (460 bytes)
a00972cc:  9d e3 bf 98  save  %sp, -104, %sp
a00972d0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00972d4:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a00972d8:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00972dc:  d8 0b 60 56  ldub  [ %o5 + 0x56 ], %o4	! 0xa8025c56
a00972e0:  c2 0c 21 a3  ldub  [ %l0 + 0x1a3 ], %g1
a00972e4:  80 a0 40 0c  cmp  %g1, %o4
a00972e8:  02 80 00 37  be  0xa00973c4
a00972ec:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a00972f0:  a2 13 63 f4  or  %o5, 0x3f4, %l1	! 0xa802cff4
a00972f4:  da 14 60 04  lduh  [ %l1 + 4 ], %o5
a00972f8:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00972fc:  82 0b 40 08  and  %o5, %o0, %g1
a0097300:  99 28 60 10  sll  %g1, 0x10, %o4
a0097304:  80 a3 20 00  cmp  %o4, 0
a0097308:  12 80 00 29  bne  0xa00973ac
a009730c:  92 13 64 00  or  %o5, 0x400, %o1
a0097310:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0097314:  40 00 77 5b  call  0xa00b5080
a0097318:  c0 23 63 ec  clr  [ %o5 + 0x3ec ]	! 0xa802afec
a009731c:  c2 14 60 18  lduh  [ %l1 + 0x18 ], %g1
a0097320:  11 00 00 10  sethi  %hi(0x4000), %o0
a0097324:  9e 10 40 08  or  %g1, %o0, %o7
a0097328:  19 00 00 08  sethi  %hi(0x2000), %o4
a009732c:  d4 0c 21 a3  ldub  [ %l0 + 0x1a3 ], %o2
a0097330:  96 13 c0 0c  or  %o7, %o4, %o3
a0097334:  d6 34 60 18  sth  %o3, [ %l1 + 0x18 ]
a0097338:  80 a2 a0 00  cmp  %o2, 0
a009733c:  02 80 00 50  be  0xa009747c
a0097340:  d4 2c 20 1f  stb  %o2, [ %l0 + 0x1f ]
a0097344:  e2 0c 20 4a  ldub  [ %l0 + 0x4a ], %l1
a0097348:  80 a4 60 01  cmp  %l1, 1
a009734c:  22 80 00 42  be,a   0xa0097454
a0097350:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a0097354:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0097358:  80 88 60 80  btst  0x80, %g1
a009735c:  12 80 00 27  bne  0xa00973f8
a0097360:  92 08 7f 7f  and  %g1, -129, %o1
a0097364:  7f ff b1 20  call  0xa00837e4
a0097368:  01 00 00 00  nop
a009736c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0097370:  80 a2 a0 01  cmp  %o2, 1
a0097374:  22 80 00 2d  be,a   0xa0097428
a0097378:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a009737c:  d6 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o3
a0097380:  80 a2 e0 03  cmp  %o3, 3
a0097384:  02 80 00 2d  be  0xa0097438
a0097388:  de 04 20 b0  ld  [ %l0 + 0xb0 ], %o7
a009738c:  80 a3 e0 00  cmp  %o7, 0
a0097390:  12 80 00 2d  bne  0xa0097444
a0097394:  01 00 00 00  nop
a0097398:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a009739c:  03 00 04 00  sethi  %hi(0x100000), %g1
a00973a0:  98 2a 00 01  andn  %o0, %g1, %o4
a00973a4:  10 80 00 36  b  0xa009747c
a00973a8:  d8 24 20 ac  st  %o4, [ %l0 + 0xac ]
a00973ac:  d2 34 60 04  sth  %o1, [ %l1 + 4 ]
a00973b0:  90 10 20 04  mov  4, %o0
a00973b4:  7f ff a5 3e  call  0xa00808ac
a00973b8:  92 10 20 00  clr  %o1
a00973bc:  10 bf ff d6  b  0xa0097314
a00973c0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00973c4:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00973c8:  98 13 e3 f4  or  %o7, 0x3f4, %o4	! 0xa802cff4
a00973cc:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a00973d0:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a00973d4:  94 0b 40 0b  and  %o5, %o3, %o2
a00973d8:  93 2a a0 10  sll  %o2, 0x10, %o1
a00973dc:  80 a2 60 00  cmp  %o1, 0
a00973e0:  12 80 00 21  bne  0xa0097464
a00973e4:  a0 13 64 00  or  %o5, 0x400, %l0
a00973e8:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00973ec:  c0 24 63 ec  clr  [ %l1 + 0x3ec ]	! 0xa802afec
a00973f0:  40 00 77 24  call  0xa00b5080
a00973f4:  81 e8 00 00  restore
a00973f8:  d2 24 20 a8  st  %o1, [ %l0 + 0xa8 ]
a00973fc:  40 01 07 80  call  0xa00d91fc
a0097400:  90 10 20 00  clr  %o0
a0097404:  40 01 0b 60  call  0xa00da184
a0097408:  01 00 00 00  nop
a009740c:  7f ff b0 f6  call  0xa00837e4
a0097410:  01 00 00 00  nop
a0097414:  94 0a 20 ff  and  %o0, 0xff, %o2
a0097418:  80 a2 a0 01  cmp  %o2, 1
a009741c:  32 bf ff d9  bne,a   0xa0097380
a0097420:  d6 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o3
a0097424:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a0097428:  d6 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o3
a009742c:  80 a2 e0 03  cmp  %o3, 3
a0097430:  12 bf ff d7  bne  0xa009738c
a0097434:  de 04 20 b0  ld  [ %l0 + 0xb0 ], %o7
a0097438:  80 a3 e0 00  cmp  %o7, 0
a009743c:  02 bf ff d7  be  0xa0097398
a0097440:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a0097444:  40 00 fa be  call  0xa00d5f3c
a0097448:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a009744c:  10 bf ff d4  b  0xa009739c
a0097450:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a0097454:  40 00 fa 96  call  0xa00d5eac
a0097458:  90 10 20 00  clr  %o0
a009745c:  10 bf ff bf  b  0xa0097358
a0097460:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0097464:  e0 33 20 04  sth  %l0, [ %o4 + 4 ]
a0097468:  90 10 20 04  mov  4, %o0
a009746c:  7f ff a5 10  call  0xa00808ac
a0097470:  92 10 20 00  clr  %o1
a0097474:  10 bf ff de  b  0xa00973ec
a0097478:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a009747c:  40 01 0b 76  call  0xa00da254
a0097480:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a0097484:  e2 0c 20 8e  ldub  [ %l0 + 0x8e ], %l1	! 0xa802b08e
a0097488:  9a 14 60 02  or  %l1, 2, %o5
a009748c:  da 2c 20 8e  stb  %o5, [ %l0 + 0x8e ]
a0097490:  81 c7 e0 08  ret
a0097494:  81 e8 00 00  restore
