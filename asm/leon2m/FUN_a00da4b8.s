# leon2m FUN_a00da4b8 0xa00da4b8-0xa00da65c (420 bytes)
a00da4b8:  9d e3 bf 98  save  %sp, -104, %sp
a00da4bc:  7f fe a6 31  call  0xa0083d80
a00da4c0:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00da4c4:  b8 16 e2 90  or  %i3, 0x290, %i4	! 0xa802d290
a00da4c8:  da 07 20 ac  ld  [ %i4 + 0xac ], %o5
a00da4cc:  03 00 04 00  sethi  %hi(0x100000), %g1
a00da4d0:  80 8b 40 01  btst  %o5, %g1
a00da4d4:  02 80 00 06  be  0xa00da4ec
a00da4d8:  d0 2f 21 b4  stb  %o0, [ %i4 + 0x1b4 ]
a00da4dc:  d2 0f 20 1f  ldub  [ %i4 + 0x1f ], %o1
a00da4e0:  80 a2 60 00  cmp  %o1, 0
a00da4e4:  02 80 00 1c  be  0xa00da554
a00da4e8:  94 0a 20 ff  and  %o0, 0xff, %o2
a00da4ec:  94 16 e2 90  or  %i3, 0x290, %o2
a00da4f0:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00da4f4:  f4 02 a0 a8  ld  [ %o2 + 0xa8 ], %i2
a00da4f8:  96 10 63 f4  or  %g1, 0x3f4, %o3
a00da4fc:  f0 12 e0 0a  lduh  [ %o3 + 0xa ], %i0
a00da500:  9b 2e a0 02  sll  %i2, 2, %o5
a00da504:  d2 0a a1 86  ldub  [ %o2 + 0x186 ], %o1
a00da508:  f8 0a a1 85  ldub  [ %o2 + 0x185 ], %i4
a00da50c:  b2 0b 68 00  and  %o5, 0x800, %i1
a00da510:  98 0e b7 ff  and  %i2, -2049, %o4
a00da514:  9e 0e 3f 7f  and  %i0, -129, %o7
a00da518:  de 32 e0 0a  sth  %o7, [ %o3 + 0xa ]
a00da51c:  90 13 00 19  or  %o4, %i1, %o0
a00da520:  f8 2a a1 81  stb  %i4, [ %o2 + 0x181 ]
a00da524:  d0 22 a0 a8  st  %o0, [ %o2 + 0xa8 ]
a00da528:  d2 2a a1 82  stb  %o1, [ %o2 + 0x182 ]
a00da52c:  94 16 e2 90  or  %i3, 0x290, %o2
a00da530:  d0 02 a0 a8  ld  [ %o2 + 0xa8 ], %o0
a00da534:  b7 32 20 0b  srl  %o0, 0xb, %i3
a00da538:  13 00 06 62  sethi  %hi(0x198800), %o1
a00da53c:  b4 0e e0 01  and  %i3, 1, %i2
a00da540:  f8 0a a1 81  ldub  [ %o2 + 0x181 ], %i4
a00da544:  f2 0a a1 b4  ldub  [ %o2 + 0x1b4 ], %i1
a00da548:  f6 0a a1 82  ldub  [ %o2 + 0x182 ], %i3
a00da54c:  40 00 13 09  call  0xa00df170
a00da550:  91 ea 60 f8  restore  %o1, 0xf8, %o0
a00da554:  80 a2 a0 02  cmp  %o2, 2
a00da558:  18 bf ff e6  bgu  0xa00da4f0
a00da55c:  94 16 e2 90  or  %i3, 0x290, %o2
a00da560:  40 01 a7 cb  call  0xa014448c
a00da564:  90 10 20 00  clr  %o0
a00da568:  40 01 a8 25  call  0xa01445fc
a00da56c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da570:  80 8a 20 ff  btst  0xff, %o0
a00da574:  12 bf ff df  bne  0xa00da4f0
a00da578:  94 16 e2 90  or  %i3, 0x290, %o2
a00da57c:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00da580:  d2 07 20 a8  ld  [ %i4 + 0xa8 ], %o1
a00da584:  96 12 23 f4  or  %o0, 0x3f4, %o3
a00da588:  f4 12 e0 0a  lduh  [ %o3 + 0xa ], %i2
a00da58c:  94 02 40 09  add  %o1, %o1, %o2
a00da590:  de 0f 21 84  ldub  [ %i4 + 0x184 ], %o7
a00da594:  f0 0f 21 83  ldub  [ %i4 + 0x183 ], %i0
a00da598:  82 0a a8 00  and  %o2, 0x800, %g1
a00da59c:  9a 0a 77 ff  and  %o1, -2049, %o5
a00da5a0:  b2 16 a0 80  or  %i2, 0x80, %i1
a00da5a4:  f2 32 e0 0a  sth  %i1, [ %o3 + 0xa ]
a00da5a8:  98 13 40 01  or  %o5, %g1, %o4
a00da5ac:  f0 2f 21 81  stb  %i0, [ %i4 + 0x181 ]
a00da5b0:  d8 27 20 a8  st  %o4, [ %i4 + 0xa8 ]
a00da5b4:  de 2f 21 82  stb  %o7, [ %i4 + 0x182 ]
a00da5b8:  40 01 c5 ee  call  0xa014bd70
a00da5bc:  90 10 20 00  clr  %o0
a00da5c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da5c4:  80 a2 20 01  cmp  %o0, 1
a00da5c8:  02 80 00 14  be  0xa00da618
a00da5cc:  96 16 e2 90  or  %i3, 0x290, %o3
a00da5d0:  40 01 a4 c3  call  0xa01438dc
a00da5d4:  90 10 20 00  clr  %o0
a00da5d8:  b8 0a 20 ff  and  %o0, 0xff, %i4
a00da5dc:  80 a7 20 01  cmp  %i4, 1
a00da5e0:  12 bf ff d4  bne  0xa00da530
a00da5e4:  94 16 e2 90  or  %i3, 0x290, %o2
a00da5e8:  40 01 c5 20  call  0xa014ba68
a00da5ec:  01 00 00 00  nop
a00da5f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da5f4:  80 a2 20 02  cmp  %o0, 2
a00da5f8:  02 80 00 08  be  0xa00da618
a00da5fc:  96 16 e2 90  or  %i3, 0x290, %o3
a00da600:  14 80 00 14  bg  0xa00da650
a00da604:  80 a2 20 03  cmp  %o0, 3
a00da608:  80 a2 20 01  cmp  %o0, 1
a00da60c:  12 bf ff c9  bne  0xa00da530
a00da610:  94 16 e2 90  or  %i3, 0x290, %o2
a00da614:  96 16 e2 90  or  %i3, 0x290, %o3
a00da618:  f0 0a e1 81  ldub  [ %o3 + 0x181 ], %i0
a00da61c:  98 06 3f fc  add  %i0, -4, %o4
a00da620:  9e 0b 20 ff  and  %o4, 0xff, %o7
a00da624:  80 a3 e0 02  cmp  %o7, 2
a00da628:  38 bf ff c2  bgu,a   0xa00da530
a00da62c:  94 16 e2 90  or  %i3, 0x290, %o2
a00da630:  35 2a 00 ac  sethi  %hi(0xa802b000), %i2
a00da634:  c2 0e a0 8e  ldub  [ %i2 + 0x8e ], %g1	! 0xa802b08e
a00da638:  b2 10 20 07  mov  7, %i1
a00da63c:  9a 10 60 02  or  %g1, 2, %o5
a00da640:  f2 2a e1 83  stb  %i1, [ %o3 + 0x183 ]
a00da644:  da 2e a0 8e  stb  %o5, [ %i2 + 0x8e ]
a00da648:  10 bf ff b9  b  0xa00da52c
a00da64c:  f2 2a e1 81  stb  %i1, [ %o3 + 0x181 ]
a00da650:  02 bf ff f1  be  0xa00da614
a00da654:  80 a2 20 04  cmp  %o0, 4
a00da658:  30 bf ff ed  b,a   0xa00da60c
