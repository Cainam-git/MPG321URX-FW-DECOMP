# leon2m FUN_a0137344 0xa0137344-0xa0137644 (768 bytes)
a0137344:  9d e3 bf 70  save  %sp, -144, %sp
a0137348:  98 10 20 00  clr  %o4
a013734c:  9a 10 20 00  clr  %o5
a0137350:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0137354:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0137358:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a013735c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0137360:  a0 10 20 64  mov  0x64, %l0
a0137364:  80 8e 20 ff  btst  0xff, %i0
a0137368:  12 80 00 06  bne  0xa0137380
a013736c:  a2 07 bf d8  add  %fp, -40, %l1
a0137370:  10 80 00 42  b  0xa0137478
a0137374:  94 10 00 11  mov  %l1, %o2
a0137378:  67 fd 57 8a  call  0x4008d1a0
a013737c:  01 00 00 00  nop
a0137380:  90 10 20 01  mov  1, %o0	! 0x1
a0137384:  92 10 20 a0  mov  0xa0, %o1
a0137388:  94 10 00 11  mov  %l1, %o2
a013738c:  67 fd 54 51  call  0x4008c4d0
a0137390:  96 10 20 01  mov  1, %o3
a0137394:  c2 07 bf d8  ld  [ %fp + -40 ], %g1
a0137398:  80 a0 60 00  cmp  %g1, 0
a013739c:  02 bf ff f7  be  0xa0137378
a01373a0:  90 10 20 01  mov  1, %o0
a01373a4:  90 10 20 01  mov  1, %o0
a01373a8:  92 10 20 a0  mov  0xa0, %o1
a01373ac:  94 10 00 11  mov  %l1, %o2
a01373b0:  67 fd 54 48  call  0x4008c4d0
a01373b4:  96 10 20 08  mov  8, %o3
a01373b8:  d2 07 bf d8  ld  [ %fp + -40 ], %o1
a01373bc:  90 0a 60 ff  and  %o1, 0xff, %o0
a01373c0:  80 a2 20 55  cmp  %o0, 0x55
a01373c4:  98 10 20 00  clr  %o4
a01373c8:  02 80 00 49  be  0xa01374ec
a01373cc:  82 10 20 00  clr  %g1
a01373d0:  80 a0 60 00  cmp  %g1, 0
a01373d4:  02 80 00 9a  be  0xa013763c
a01373d8:  1f 00 00 3f  sethi  %hi(0xfc00), %o7
a01373dc:  9a 13 e3 00  or  %o7, 0x300, %o5	! 0xff00
a01373e0:  98 0a 40 0d  and  %o1, %o5, %o4
a01373e4:  83 33 20 08  srl  %o4, 8, %g1
a01373e8:  80 a0 60 79  cmp  %g1, 0x79
a01373ec:  22 80 00 64  be,a   0xa013757c
a01373f0:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a01373f4:  14 80 00 54  bg  0xa0137544
a01373f8:  80 a0 60 a1  cmp  %g1, 0xa1
a01373fc:  80 a0 60 45  cmp  %g1, 0x45
a0137400:  22 80 00 5f  be,a   0xa013757c
a0137404:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a0137408:  14 80 00 77  bg  0xa01375e4
a013740c:  80 a0 60 5c  cmp  %g1, 0x5c
a0137410:  80 a0 60 22  cmp  %g1, 0x22
a0137414:  22 80 00 5a  be,a   0xa013757c
a0137418:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a013741c:  14 80 00 80  bg  0xa013761c
a0137420:  80 a0 60 31  cmp  %g1, 0x31
a0137424:  80 a0 60 00  cmp  %g1, 0
a0137428:  32 80 00 0e  bne,a   0xa0137460
a013742c:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137430:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a0137434:  94 12 63 9c  or  %o1, 0x39c, %o2	! 0xa802cb9c
a0137438:  96 10 20 00  clr  %o3
a013743c:  98 10 20 00  clr  %o4
a0137440:  a1 2b 20 02  sll  %o4, 2, %l0
a0137444:  96 02 e0 01  inc  %o3
a0137448:  f0 04 40 10  ld  [ %l1 + %l0 ], %i0
a013744c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0137450:  80 a3 20 07  cmp  %o4, 7
a0137454:  08 bf ff fb  bleu  0xa0137440
a0137458:  f0 22 80 10  st  %i0, [ %o2 + %l0 ]
a013745c:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137460:  90 10 20 01  mov  1, %o0
a0137464:  92 10 20 a0  mov  0xa0, %o1
a0137468:  94 07 bf d4  add  %fp, -44, %o2
a013746c:  67 fd 54 63  call  0x4008c5f8
a0137470:  96 10 20 01  mov  1, %o3
a0137474:  30 80 00 72  b,a   0xa013763c
a0137478:  90 10 20 01  mov  1, %o0
a013747c:  92 10 20 a0  mov  0xa0, %o1
a0137480:  67 fd 54 14  call  0x4008c4d0
a0137484:  96 10 20 01  mov  1, %o3
a0137488:  d4 07 bf d8  ld  [ %fp + -40 ], %o2
a013748c:  90 10 20 01  mov  1, %o0
a0137490:  80 a2 a0 00  cmp  %o2, 0
a0137494:  12 bf ff c5  bne  0xa01373a8
a0137498:  a0 04 3f ff  add  %l0, -1, %l0
a013749c:  67 fd 57 41  call  0x4008d1a0
a01374a0:  01 00 00 00  nop
a01374a4:  7f fe 98 5c  call  0xa00dd614
a01374a8:  90 10 20 20  mov  0x20, %o0	! 0x20
a01374ac:  80 8a 20 ff  btst  0xff, %o0
a01374b0:  12 80 00 21  bne  0xa0137534
a01374b4:  19 00 06 95  sethi  %hi(0x1a5400), %o4
a01374b8:  80 8c 20 ff  btst  0xff, %l0
a01374bc:  12 bf ff ef  bne  0xa0137478
a01374c0:  94 10 00 11  mov  %l1, %o2
a01374c4:  90 10 20 01  mov  1, %o0
a01374c8:  92 10 20 a0  mov  0xa0, %o1
a01374cc:  67 fd 54 01  call  0x4008c4d0
a01374d0:  96 10 20 08  mov  8, %o3
a01374d4:  d2 07 bf d8  ld  [ %fp + -40 ], %o1
a01374d8:  90 0a 60 ff  and  %o1, 0xff, %o0
a01374dc:  80 a2 20 55  cmp  %o0, 0x55
a01374e0:  98 10 20 00  clr  %o4
a01374e4:  12 bf ff bb  bne  0xa01373d0
a01374e8:  82 10 20 00  clr  %g1
a01374ec:  94 10 20 00  clr  %o2
a01374f0:  91 28 60 02  sll  %g1, 2, %o0
a01374f4:  de 04 40 08  ld  [ %l1 + %o0 ], %o7
a01374f8:  b0 1b c0 0c  xor  %o7, %o4, %i0
a01374fc:  83 33 e0 08  srl  %o7, 8, %g1
a0137500:  a0 1e 00 01  xor  %i0, %g1, %l0
a0137504:  97 33 e0 10  srl  %o7, 0x10, %o3
a0137508:  94 02 a0 01  inc  %o2
a013750c:  98 1c 00 0b  xor  %l0, %o3, %o4
a0137510:  9b 33 e0 18  srl  %o7, 0x18, %o5
a0137514:  82 0a a0 ff  and  %o2, 0xff, %g1
a0137518:  80 a0 60 08  cmp  %g1, 8
a013751c:  0a bf ff f5  bcs  0xa01374f0
a0137520:  98 1b 00 0d  xor  %o4, %o5, %o4
a0137524:  94 0b 20 ff  and  %o4, 0xff, %o2
a0137528:  80 a0 00 0a  cmp  %g0, %o2
a013752c:  10 bf ff a9  b  0xa01373d0
a0137530:  82 60 3f ff  subx  %g0, -1, %g1
a0137534:  7f fe 9f 0f  call  0xa00df170
a0137538:  90 13 21 a8  or  %o4, 0x1a8, %o0
a013753c:  10 bf ff e0  b  0xa01374bc
a0137540:  80 8c 20 ff  btst  0xff, %l0
a0137544:  14 80 00 1f  bg  0xa01375c0
a0137548:  80 a0 60 f3  cmp  %g1, 0xf3
a013754c:  80 a0 60 a0  cmp  %g1, 0xa0
a0137550:  16 80 00 0b  bge  0xa013757c
a0137554:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a0137558:  80 a0 60 83  cmp  %g1, 0x83
a013755c:  02 80 00 09  be  0xa0137580
a0137560:  94 12 e3 9c  or  %o3, 0x39c, %o2
a0137564:  14 80 00 32  bg  0xa013762c
a0137568:  80 a0 60 87  cmp  %g1, 0x87
a013756c:  80 a0 60 7c  cmp  %g1, 0x7c
a0137570:  32 bf ff bc  bne,a   0xa0137460
a0137574:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137578:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a013757c:  94 12 e3 9c  or  %o3, 0x39c, %o2	! 0xa802cb9c
a0137580:  96 10 20 00  clr  %o3
a0137584:  98 10 20 00  clr  %o4
a0137588:  91 2b 20 02  sll  %o4, 2, %o0
a013758c:  96 02 e0 01  inc  %o3
a0137590:  c2 04 40 08  ld  [ %l1 + %o0 ], %g1
a0137594:  98 0a e0 ff  and  %o3, 0xff, %o4
a0137598:  80 a3 20 07  cmp  %o4, 7
a013759c:  08 bf ff fb  bleu  0xa0137588
a01375a0:  c2 22 80 08  st  %g1, [ %o2 + %o0 ]
a01375a4:  c0 27 bf d4  clr  [ %fp + -44 ]
a01375a8:  90 10 20 01  mov  1, %o0
a01375ac:  92 10 20 a0  mov  0xa0, %o1
a01375b0:  94 07 bf d4  add  %fp, -44, %o2
a01375b4:  67 fd 54 11  call  0x4008c5f8
a01375b8:  96 10 20 01  mov  1, %o3
a01375bc:  30 80 00 20  b,a   0xa013763c
a01375c0:  02 bf ff ee  be  0xa0137578
a01375c4:  80 a0 60 f3  cmp  %g1, 0xf3
a01375c8:  14 80 00 11  bg  0xa013760c
a01375cc:  80 a0 60 fd  cmp  %g1, 0xfd
a01375d0:  80 a0 60 a4  cmp  %g1, 0xa4
a01375d4:  32 bf ff a3  bne,a   0xa0137460
a01375d8:  c0 27 bf d4  clr  [ %fp + -44 ]
a01375dc:  10 bf ff e8  b  0xa013757c
a01375e0:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a01375e4:  26 bf ff 9f  bl,a   0xa0137460
a01375e8:  c0 27 bf d4  clr  [ %fp + -44 ]
a01375ec:  80 a0 60 5d  cmp  %g1, 0x5d
a01375f0:  04 bf ff e3  ble  0xa013757c
a01375f4:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a01375f8:  80 a0 60 71  cmp  %g1, 0x71
a01375fc:  32 bf ff 99  bne,a   0xa0137460
a0137600:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137604:  10 bf ff df  b  0xa0137580
a0137608:  94 12 e3 9c  or  %o3, 0x39c, %o2
a013760c:  32 bf ff 95  bne,a   0xa0137460
a0137610:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137614:  10 bf ff da  b  0xa013757c
a0137618:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a013761c:  32 bf ff 91  bne,a   0xa0137460
a0137620:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137624:  10 bf ff d6  b  0xa013757c
a0137628:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a013762c:  32 bf ff 8d  bne,a   0xa0137460
a0137630:  c0 27 bf d4  clr  [ %fp + -44 ]
a0137634:  10 bf ff d2  b  0xa013757c
a0137638:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a013763c:  81 c7 e0 08  ret
a0137640:  81 e8 00 00  restore
