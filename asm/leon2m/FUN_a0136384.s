# leon2m FUN_a0136384 0xa0136384-0xa0136600 (636 bytes)
a0136384:  9d e3 bf 68  save  %sp, -152, %sp
a0136388:  98 10 20 00  clr  %o4
a013638c:  9a 10 20 00  clr  %o5
a0136390:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0136394:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0136398:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a013639c:  c0 27 bf f0  clr  [ %fp + -16 ]
a01363a0:  c0 37 bf f4  clrh  [ %fp + -12 ]
a01363a4:  7f ff f3 f8  call  0xa0133384
a01363a8:  d8 3f bf d0  std  %o4, [ %fp + -48 ]
a01363ac:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a01363b0:  92 10 61 a0  or  %g1, 0x1a0, %o1	! 0xa802d9a0
a01363b4:  ae 10 20 10  mov  0x10, %l7
a01363b8:  a2 10 20 00  clr  %l1
a01363bc:  82 10 20 00  clr  %g1
a01363c0:  94 07 bf f8  add  %fp, -8, %o2
a01363c4:  96 00 60 01  add  %g1, 1, %o3
a01363c8:  a5 28 60 10  sll  %g1, 0x10, %l2
a01363cc:  9f 34 a0 10  srl  %l2, 0x10, %o7
a01363d0:  a1 2a e0 10  sll  %o3, 0x10, %l0
a01363d4:  d8 0a 40 0f  ldub  [ %o1 + %o7 ], %o4
a01363d8:  9b 34 20 10  srl  %l0, 0x10, %o5
a01363dc:  90 02 80 0f  add  %o2, %o7, %o0
a01363e0:  d8 2a 3f e8  stb  %o4, [ %o0 + -24 ]
a01363e4:  80 a3 60 11  cmp  %o5, 0x11
a01363e8:  08 bf ff f7  bleu  0xa01363c4
a01363ec:  82 10 00 0b  mov  %o3, %g1
a01363f0:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a01363f4:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a01363f8:  10 80 00 04  b  0xa0136408
a01363fc:  a0 10 20 12  mov  0x12, %l0
a0136400:  7f ff fb 37  call  0xa01350dc
a0136404:  01 00 00 00  nop
a0136408:  d6 0c a3 97  ldub  [ %l2 + 0x397 ], %o3
a013640c:  d8 0c e3 96  ldub  [ %l3 + 0x396 ], %o4
a0136410:  94 0a e0 ff  and  %o3, 0xff, %o2
a0136414:  92 0b 20 ff  and  %o4, 0xff, %o1
a0136418:  a8 22 40 0a  sub  %o1, %o2, %l4
a013641c:  92 0a e0 ff  and  %o3, 0xff, %o1
a0136420:  94 0b 20 ff  and  %o4, 0xff, %o2
a0136424:  80 a2 40 0a  cmp  %o1, %o2
a0136428:  18 80 00 09  bgu  0xa013644c
a013642c:  82 05 20 24  add  %l4, 0x24, %g1
a0136430:  aa 0b 20 ff  and  %o4, 0xff, %l5
a0136434:  ac 0a e0 ff  and  %o3, 0xff, %l6
a0136438:  80 a2 40 0a  cmp  %o1, %o2
a013643c:  9a 25 40 16  sub  %l5, %l6, %o5
a0136440:  1a 80 00 03  bcc  0xa013644c
a0136444:  82 10 20 24  mov  0x24, %g1
a0136448:  82 03 7f ff  add  %o5, -1, %g1
a013644c:  97 28 60 14  sll  %g1, 0x14, %o3
a0136450:  83 32 e0 10  srl  %o3, 0x10, %g1
a0136454:  80 a4 00 01  cmp  %l0, %g1
a0136458:  18 bf ff ea  bgu  0xa0136400
a013645c:  1b 2a 00 b6  sethi  %hi(0xa802d800), %o5
a0136460:  a8 13 62 6c  or  %o5, 0x26c, %l4	! 0xa802da6c
a0136464:  a0 10 20 00  clr  %l0
a0136468:  ac 07 bf e0  add  %fp, -32, %l6
a013646c:  90 07 bf d0  add  %fp, -48, %o0
a0136470:  aa 10 20 12  mov  0x12, %l5
a0136474:  de 0c a3 97  ldub  [ %l2 + 0x397 ], %o7
a0136478:  93 2c 20 10  sll  %l0, 0x10, %o1
a013647c:  83 32 60 10  srl  %o1, 0x10, %g1
a0136480:  98 25 40 01  sub  %l5, %g1, %o4
a0136484:  80 a3 20 0f  cmp  %o4, 0xf
a0136488:  28 80 00 02  bleu,a   0xa0136490
a013648c:  ae 25 40 10  sub  %l5, %l0, %l7
a0136490:  92 05 80 01  add  %l6, %g1, %o1
a0136494:  94 10 20 00  clr  %o2
a0136498:  9a 10 20 00  clr  %o5
a013649c:  97 2b 60 02  sll  %o5, 2, %o3
a01364a0:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a01364a4:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a01364a8:  98 02 c0 09  add  %o3, %o1, %o4
a01364ac:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a01364b0:  83 28 60 08  sll  %g1, 8, %g1
a01364b4:  82 00 40 0d  add  %g1, %o5, %g1
a01364b8:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a01364bc:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a01364c0:  83 28 60 08  sll  %g1, 8, %g1
a01364c4:  82 00 40 0d  add  %g1, %o5, %g1
a01364c8:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a01364cc:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a01364d0:  99 28 60 08  sll  %g1, 8, %o4
a01364d4:  82 03 00 0d  add  %o4, %o5, %g1
a01364d8:  94 02 a0 01  inc  %o2
a01364dc:  9a 0a a0 ff  and  %o2, 0xff, %o5
a01364e0:  80 a3 60 04  cmp  %o5, 4
a01364e4:  0a bf ff ee  bcs  0xa013649c
a01364e8:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a01364ec:  96 0b e0 ff  and  %o7, 0xff, %o3
a01364f0:  83 2a e0 02  sll  %o3, 2, %g1
a01364f4:  94 00 40 0b  add  %g1, %o3, %o2
a01364f8:  92 0d e0 ff  and  %l7, 0xff, %o1
a01364fc:  83 2a a0 02  sll  %o2, 2, %g1
a0136500:  99 2a 60 10  sll  %o1, 0x10, %o4
a0136504:  9b 2c 60 18  sll  %l1, 0x18, %o5
a0136508:  92 03 40 0c  add  %o5, %o4, %o1
a013650c:  94 03 e0 01  add  %o7, 1, %o2
a0136510:  9e 02 60 0a  add  %o1, 0xa, %o7
a0136514:  de 25 00 01  st  %o7, [ %l4 + %g1 ]
a0136518:  92 00 40 14  add  %g1, %l4, %o1
a013651c:  d6 07 bf dc  ld  [ %fp + -36 ], %o3
a0136520:  9e 0a a0 ff  and  %o2, 0xff, %o7
a0136524:  d6 22 60 10  st  %o3, [ %o1 + 0x10 ]
a0136528:  da 07 bf d0  ld  [ %fp + -48 ], %o5
a013652c:  d8 07 bf d4  ld  [ %fp + -44 ], %o4
a0136530:  d6 07 bf d8  ld  [ %fp + -40 ], %o3
a0136534:  80 a3 e0 24  cmp  %o7, 0x24
a0136538:  da 22 60 04  st  %o5, [ %o1 + 4 ]
a013653c:  d8 22 60 08  st  %o4, [ %o1 + 8 ]
a0136540:  d6 22 60 0c  st  %o3, [ %o1 + 0xc ]
a0136544:  18 80 00 03  bgu  0xa0136550
a0136548:  9e 10 20 00  clr  %o7
a013654c:  9e 10 00 0a  mov  %o2, %o7
a0136550:  94 04 20 10  add  %l0, 0x10, %o2
a0136554:  9b 2a a0 10  sll  %o2, 0x10, %o5
a0136558:  a1 33 60 10  srl  %o5, 0x10, %l0
a013655c:  80 a4 20 11  cmp  %l0, 0x11
a0136560:  a2 04 60 01  inc  %l1
a0136564:  08 bf ff c5  bleu  0xa0136478
a0136568:  a0 10 00 0a  mov  %o2, %l0
a013656c:  de 2c a3 97  stb  %o7, [ %l2 + 0x397 ]
a0136570:  c0 27 bf cc  clr  [ %fp + -52 ]
a0136574:  10 80 00 05  b  0xa0136588
a0136578:  9a 0b e0 ff  and  %o7, 0xff, %o5
a013657c:  7f ff fa d8  call  0xa01350dc
a0136580:  01 00 00 00  nop
a0136584:  da 0c a3 97  ldub  [ %l2 + 0x397 ], %o5
a0136588:  e2 0c e3 96  ldub  [ %l3 + 0x396 ], %l1
a013658c:  80 a3 40 11  cmp  %o5, %l1
a0136590:  12 bf ff fb  bne  0xa013657c
a0136594:  a2 10 20 00  clr  %l1
a0136598:  a0 10 20 00  clr  %l0
a013659c:  98 10 20 00  clr  %o4
a01365a0:  83 2b 20 02  sll  %o4, 2, %g1
a01365a4:  9e 00 40 0c  add  %g1, %o4, %o7
a01365a8:  ad 2b e0 02  sll  %o7, 2, %l6
a01365ac:  aa 05 a0 10  add  %l6, 0x10, %l5
a01365b0:  90 10 20 00  clr  %o0
a01365b4:  92 0d 60 fc  and  %l5, 0xfc, %o1
a01365b8:  94 07 bf cc  add  %fp, -52, %o2
a01365bc:  67 fd 57 c5  call  0x4008c4d0
a01365c0:  96 10 20 01  mov  1, %o3
a01365c4:  a0 04 20 01  inc  %l0
a01365c8:  98 0c 20 ff  and  %l0, 0xff, %o4
a01365cc:  a9 2b 20 02  sll  %o4, 2, %l4
a01365d0:  a4 05 00 0c  add  %l4, %o4, %l2
a01365d4:  91 2c a0 02  sll  %l2, 2, %o0
a01365d8:  a6 02 20 10  add  %o0, 0x10, %l3
a01365dc:  ee 07 bf cc  ld  [ %fp + -52 ], %l7
a01365e0:  80 a4 e0 50  cmp  %l3, 0x50
a01365e4:  04 bf ff ef  ble  0xa01365a0
a01365e8:  a2 14 40 17  or  %l1, %l7, %l1
a01365ec:  80 a4 60 00  cmp  %l1, 0
a01365f0:  12 bf ff ea  bne  0xa0136598
a01365f4:  a2 10 20 00  clr  %l1
a01365f8:  81 c7 e0 08  ret
a01365fc:  81 e8 00 00  restore
