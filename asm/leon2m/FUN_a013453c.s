# leon2m FUN_a013453c 0xa013453c-0xa0134684 (328 bytes)
a013453c:  9d e3 bf 90  save  %sp, -112, %sp
a0134540:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0134544:  c0 27 bf f4  clr  [ %fp + -12 ]
a0134548:  e2 0c 23 8d  ldub  [ %l0 + 0x38d ], %l1
a013454c:  10 80 00 06  b  0xa0134564
a0134550:  b0 10 20 00  clr  %i0
a0134554:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134558:  80 a2 e0 03  cmp  %o3, 3
a013455c:  18 80 00 19  bgu  0xa01345c0
a0134560:  c0 2c 23 8d  clrb  [ %l0 + 0x38d ]
a0134564:  d8 0c 23 8d  ldub  [ %l0 + 0x38d ], %o4
a0134568:  97 2b 20 02  sll  %o4, 2, %o3
a013456c:  94 02 c0 0c  add  %o3, %o4, %o2
a0134570:  91 2a a0 02  sll  %o2, 2, %o0
a0134574:  92 02 20 10  add  %o0, 0x10, %o1
a0134578:  92 0a 60 fc  and  %o1, 0xfc, %o1
a013457c:  90 10 20 00  clr  %o0
a0134580:  94 07 bf f4  add  %fp, -12, %o2
a0134584:  67 fd 5f d3  call  0x4008c4d0
a0134588:  96 10 20 01  mov  1, %o3
a013458c:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0134590:  80 88 60 0f  btst  0xf, %g1
a0134594:  02 80 00 37  be  0xa0134670
a0134598:  de 0c 23 8d  ldub  [ %l0 + 0x38d ], %o7
a013459c:  82 03 e0 01  add  %o7, 1, %g1
a01345a0:  9a 08 60 ff  and  %g1, 0xff, %o5
a01345a4:  80 a3 60 03  cmp  %o5, 3
a01345a8:  18 bf ff eb  bgu  0xa0134554
a01345ac:  b0 06 20 01  inc  %i0
a01345b0:  96 0e 20 ff  and  %i0, 0xff, %o3
a01345b4:  80 a2 e0 03  cmp  %o3, 3
a01345b8:  08 bf ff eb  bleu  0xa0134564
a01345bc:  c2 2c 23 8d  stb  %g1, [ %l0 + 0x38d ]
a01345c0:  80 a0 00 0b  cmp  %g0, %o3
a01345c4:  82 40 20 00  addx  %g0, 0, %g1
a01345c8:  92 1a e0 04  xor  %o3, 4, %o1
a01345cc:  80 a0 00 09  cmp  %g0, %o1
a01345d0:  b0 40 20 00  addx  %g0, 0, %i0
a01345d4:  80 88 40 18  btst  %g1, %i0
a01345d8:  02 80 00 22  be  0xa0134660
a01345dc:  80 a2 e0 04  cmp  %o3, 4
a01345e0:  e2 2c 23 8d  stb  %l1, [ %l0 + 0x38d ]
a01345e4:  10 80 00 06  b  0xa01345fc
a01345e8:  b0 10 20 00  clr  %i0
a01345ec:  96 0e 20 ff  and  %i0, 0xff, %o3
a01345f0:  80 a2 e0 03  cmp  %o3, 3
a01345f4:  18 80 00 1a  bgu  0xa013465c
a01345f8:  c0 2c 23 8d  clrb  [ %l0 + 0x38d ]
a01345fc:  da 0c 23 8d  ldub  [ %l0 + 0x38d ], %o5
a0134600:  99 2b 60 02  sll  %o5, 2, %o4
a0134604:  96 03 00 0d  add  %o4, %o5, %o3
a0134608:  95 2a e0 02  sll  %o3, 2, %o2
a013460c:  90 02 a0 10  add  %o2, 0x10, %o0
a0134610:  92 0a 20 fc  and  %o0, 0xfc, %o1
a0134614:  90 10 20 00  clr  %o0
a0134618:  94 07 bf f4  add  %fp, -12, %o2
a013461c:  67 fd 5f ad  call  0x4008c4d0
a0134620:  96 10 20 01  mov  1, %o3
a0134624:  e2 07 bf f4  ld  [ %fp + -12 ], %l1
a0134628:  80 8c 60 0f  btst  0xf, %l1
a013462c:  02 80 00 0c  be  0xa013465c
a0134630:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134634:  c2 0c 23 8d  ldub  [ %l0 + 0x38d ], %g1
a0134638:  82 00 60 01  inc  %g1
a013463c:  9e 08 60 ff  and  %g1, 0xff, %o7
a0134640:  80 a3 e0 03  cmp  %o7, 3
a0134644:  18 bf ff ea  bgu  0xa01345ec
a0134648:  b0 06 20 01  inc  %i0
a013464c:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134650:  80 a2 e0 03  cmp  %o3, 3
a0134654:  08 bf ff ea  bleu  0xa01345fc
a0134658:  c2 2c 23 8d  stb  %g1, [ %l0 + 0x38d ]
a013465c:  80 a2 e0 04  cmp  %o3, 4
a0134660:  02 80 00 06  be  0xa0134678
a0134664:  b0 10 3f ff  mov  -1, %i0
a0134668:  10 80 00 04  b  0xa0134678
a013466c:  f0 0c 23 8d  ldub  [ %l0 + 0x38d ], %i0
a0134670:  10 bf ff d4  b  0xa01345c0
a0134674:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134678:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013467c:  81 c7 e0 08  ret
a0134680:  81 e8 00 00  restore
