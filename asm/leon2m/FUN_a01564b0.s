# leon2m FUN_a01564b0 0xa01564b0-0xa01566b0 (512 bytes)
a01564b0:  9d e3 bf 58  save  %sp, -168, %sp
a01564b4:  a4 07 bf e0  add  %fp, -32, %l2
a01564b8:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a01564bc:  90 07 bf c0  add  %fp, -64, %o0
a01564c0:  92 10 00 12  mov  %l2, %o1
a01564c4:  40 00 03 a2  call  0xa015734c
a01564c8:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a01564cc:  b6 07 bf c8  add  %fp, -56, %i3
a01564d0:  90 07 bf b8  add  %fp, -72, %o0
a01564d4:  40 00 03 9e  call  0xa015734c
a01564d8:  92 10 00 1b  mov  %i3, %o1
a01564dc:  d8 07 bf e0  ld  [ %fp + -32 ], %o4
a01564e0:  80 a3 20 01  cmp  %o4, 1
a01564e4:  08 80 00 6e  bleu  0xa015669c
a01564e8:  90 10 00 12  mov  %l2, %o0
a01564ec:  d6 07 bf c8  ld  [ %fp + -56 ], %o3
a01564f0:  80 a2 e0 01  cmp  %o3, 1
a01564f4:  08 80 00 6a  bleu  0xa015669c
a01564f8:  90 10 00 1b  mov  %i3, %o0
a01564fc:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0156500:  da 07 bf cc  ld  [ %fp + -52 ], %o5
a0156504:  82 18 40 0d  xor  %g1, %o5, %g1
a0156508:  80 a3 20 04  cmp  %o4, 4
a015650c:  02 80 00 0f  be  0xa0156548
a0156510:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a0156514:  80 a3 20 02  cmp  %o4, 2
a0156518:  22 80 00 0d  be,a   0xa015654c
a015651c:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0156520:  80 a2 e0 04  cmp  %o3, 4
a0156524:  22 80 00 0f  be,a   0xa0156560
a0156528:  98 10 20 00  clr  %o4
a015652c:  80 a2 e0 02  cmp  %o3, 2
a0156530:  12 80 00 11  bne  0xa0156574
a0156534:  da 07 bf e8  ld  [ %fp + -24 ], %o5
a0156538:  82 10 20 04  mov  4, %g1
a015653c:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a0156540:  10 80 00 57  b  0xa015669c
a0156544:  90 10 00 12  mov  %l2, %o0
a0156548:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a015654c:  80 a3 00 0b  cmp  %o4, %o3
a0156550:  02 80 00 53  be  0xa015669c
a0156554:  90 10 62 c0  or  %g1, 0x2c0, %o0
a0156558:  10 80 00 51  b  0xa015669c
a015655c:  90 10 00 12  mov  %l2, %o0
a0156560:  9a 10 20 00  clr  %o5
a0156564:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0156568:  c0 27 bf e8  clr  [ %fp + -24 ]
a015656c:  10 80 00 4c  b  0xa015669c
a0156570:  90 10 00 12  mov  %l2, %o0
a0156574:  c2 07 bf d0  ld  [ %fp + -48 ], %g1
a0156578:  9a 23 40 01  sub  %o5, %g1, %o5
a015657c:  d0 1f bf f0  ldd  [ %fp + -16 ], %o0
a0156580:  e0 1f bf d8  ldd  [ %fp + -40 ], %l0
a0156584:  80 a4 00 08  cmp  %l0, %o0
a0156588:  18 80 00 3b  bgu  0xa0156674
a015658c:  da 27 bf e8  st  %o5, [ %fp + -24 ]
a0156590:  80 a4 00 08  cmp  %l0, %o0
a0156594:  02 80 00 36  be  0xa015666c
a0156598:  80 a4 40 09  cmp  %l1, %o1
a015659c:  31 04 00 00  sethi  %hi(0x10000000), %i0
a01565a0:  b2 10 20 00  clr  %i1
a01565a4:  a8 10 20 00  clr  %l4
a01565a8:  10 80 00 0f  b  0xa01565e4
a01565ac:  aa 10 20 00  clr  %l5
a01565b0:  90 62 00 10  subx  %o0, %l0, %o0
a01565b4:  a8 15 00 18  or  %l4, %i0, %l4
a01565b8:  aa 15 40 19  or  %l5, %i1, %l5
a01565bc:  9b 32 60 1f  srl  %o1, 0x1f, %o5
a01565c0:  82 02 00 08  add  %o0, %o0, %g1
a01565c4:  94 13 40 01  or  %o5, %g1, %o2
a01565c8:  96 02 40 09  add  %o1, %o1, %o3
a01565cc:  b0 10 00 1a  mov  %i2, %i0
a01565d0:  b2 10 00 1b  mov  %i3, %i1
a01565d4:  90 10 00 0a  mov  %o2, %o0
a01565d8:  80 96 80 1b  orcc  %i2, %i3, %g0
a01565dc:  02 80 00 10  be  0xa015661c
a01565e0:  92 10 00 0b  mov  %o3, %o1
a01565e4:  9b 2e 20 1f  sll  %i0, 0x1f, %o5
a01565e8:  83 36 60 01  srl  %i1, 1, %g1
a01565ec:  b6 13 40 01  or  %o5, %g1, %i3
a01565f0:  80 a4 00 08  cmp  %l0, %o0
a01565f4:  18 bf ff f2  bgu  0xa01565bc
a01565f8:  b5 36 20 01  srl  %i0, 1, %i2
a01565fc:  80 a4 00 08  cmp  %l0, %o0
a0156600:  32 bf ff ec  bne,a   0xa01565b0
a0156604:  92 a2 40 11  subcc  %o1, %l1, %o1
a0156608:  80 a4 40 09  cmp  %l1, %o1
a015660c:  18 bf ff ed  bgu  0xa01565c0
a0156610:  9b 32 60 1f  srl  %o1, 0x1f, %o5
a0156614:  10 bf ff e7  b  0xa01565b0
a0156618:  92 a2 40 11  subcc  %o1, %l1, %o1
a015661c:  98 0d 20 00  and  %l4, 0, %o4
a0156620:  80 a3 20 00  cmp  %o4, 0
a0156624:  12 80 00 05  bne  0xa0156638
a0156628:  9a 0d 60 ff  and  %l5, 0xff, %o5
a015662c:  80 a3 60 80  cmp  %o5, 0x80
a0156630:  02 80 00 05  be  0xa0156644
a0156634:  9a 0d 61 00  and  %l5, 0x100, %o5
a0156638:  e8 3c a0 10  std  %l4, [ %l2 + 0x10 ]
a015663c:  10 80 00 18  b  0xa015669c
a0156640:  90 10 00 12  mov  %l2, %o0
a0156644:  80 93 00 0d  orcc  %o4, %o5, %g0
a0156648:  32 80 00 06  bne,a   0xa0156660
a015664c:  aa 85 60 80  addcc  %l5, 0x80, %l5
a0156650:  80 92 80 0b  orcc  %o2, %o3, %g0
a0156654:  22 bf ff fa  be,a   0xa015663c
a0156658:  e8 3c a0 10  std  %l4, [ %l2 + 0x10 ]
a015665c:  aa 85 60 80  addcc  %l5, 0x80, %l5
a0156660:  a8 45 20 00  addx  %l4, 0, %l4
a0156664:  10 bf ff f6  b  0xa015663c
a0156668:  e8 3c a0 10  std  %l4, [ %l2 + 0x10 ]
a015666c:  28 bf ff cd  bleu,a   0xa01565a0
a0156670:  31 04 00 00  sethi  %hi(0x10000000), %i0
a0156674:  95 32 60 1f  srl  %o1, 0x1f, %o2
a0156678:  96 02 00 08  add  %o0, %o0, %o3
a015667c:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a0156680:  98 12 80 0b  or  %o2, %o3, %o4
a0156684:  9a 02 40 09  add  %o1, %o1, %o5
a0156688:  82 00 7f ff  add  %g1, -1, %g1
a015668c:  c2 24 a0 08  st  %g1, [ %l2 + 8 ]
a0156690:  90 10 00 0c  mov  %o4, %o0
a0156694:  10 bf ff c2  b  0xa015659c
a0156698:  92 10 00 0d  mov  %o5, %o1
a015669c:  40 00 02 ac  call  0xa015714c
a01566a0:  01 00 00 00  nop
a01566a4:  b0 10 00 08  mov  %o0, %i0
a01566a8:  81 c7 e0 08  ret
a01566ac:  93 e8 00 09  restore  %g0, %o1, %o1
