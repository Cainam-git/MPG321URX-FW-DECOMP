# leon2m FUN_a01213a4 0xa01213a4-0xa01215c8 (548 bytes)
a01213a4:  9d e3 bf 98  save  %sp, -104, %sp
a01213a8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a01213ac:  7f ff 71 1d  call  0xa00fd820
a01213b0:  90 10 00 11  mov  %l1, %o0
a01213b4:  a0 0a 20 ff  and  %o0, 0xff, %l0
a01213b8:  90 10 00 10  mov  %l0, %o0
a01213bc:  7f ff fe 8a  call  0xa0120de4
a01213c0:  92 10 00 11  mov  %l1, %o1
a01213c4:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a01213c8:  da 03 21 e4  ld  [ %o4 + 0x1e4 ], %o5	! 0xa802c9e4
a01213cc:  83 33 40 11  srl  %o5, %l1, %g1
a01213d0:  a4 10 00 18  mov  %i0, %l2
a01213d4:  82 08 60 01  and  %g1, 1, %g1
a01213d8:  80 a0 60 01  cmp  %g1, 1
a01213dc:  02 80 00 52  be  0xa0121524
a01213e0:  b0 10 00 08  mov  %o0, %i0
a01213e4:  82 06 3f fe  add  %i0, -2, %g1
a01213e8:  b2 08 60 ff  and  %g1, 0xff, %i1
a01213ec:  80 a6 60 04  cmp  %i1, 4
a01213f0:  b2 0e 20 ff  and  %i0, 0xff, %i1
a01213f4:  9e 0e a0 ff  and  %i2, 0xff, %o7
a01213f8:  98 60 20 00  subx  %g0, 0, %o4
a01213fc:  96 1e 40 0f  xor  %i1, %o7, %o3
a0121400:  80 a0 00 0b  cmp  %g0, %o3
a0121404:  9a 40 20 00  addx  %g0, 0, %o5
a0121408:  80 8b 00 0d  btst  %o4, %o5
a012140c:  02 80 00 6d  be  0xa01215c0
a0121410:  90 10 00 12  mov  %l2, %o0
a0121414:  80 a4 20 61  cmp  %l0, 0x61
a0121418:  a4 10 20 3c  mov  0x3c, %l2
a012141c:  02 80 00 40  be  0xa012151c
a0121420:  b4 10 20 07  mov  7, %i2
a0121424:  80 a4 20 61  cmp  %l0, 0x61
a0121428:  14 80 00 28  bg  0xa01214c8
a012142c:  80 a4 20 b1  cmp  %l0, 0xb1
a0121430:  80 a4 20 21  cmp  %l0, 0x21
a0121434:  22 80 00 0a  be,a   0xa012145c
a0121438:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a012143c:  14 80 00 31  bg  0xa0121500
a0121440:  80 a4 20 41  cmp  %l0, 0x41
a0121444:  a2 04 3f ef  add  %l0, -17, %l1
a0121448:  80 a4 60 02  cmp  %l1, 2
a012144c:  18 80 00 04  bgu  0xa012145c
a0121450:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0121454:  b4 10 20 07  mov  7, %i2
a0121458:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a012145c:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0121460:  a2 06 00 18  add  %i0, %i0, %l1
a0121464:  82 04 40 18  add  %l1, %i0, %g1
a0121468:  98 12 e2 ac  or  %o3, 0x2ac, %o4
a012146c:  9f 28 60 02  sll  %g1, 2, %o7
a0121470:  96 03 c0 0c  add  %o7, %o4, %o3
a0121474:  d0 0a e0 08  ldub  [ %o3 + 8 ], %o0
a0121478:  80 a2 20 00  cmp  %o0, 0
a012147c:  32 80 00 02  bne,a   0xa0121484
a0121480:  a4 0c a0 df  and  %l2, 0xdf, %l2
a0121484:  90 10 00 18  mov  %i0, %o0
a0121488:  92 10 20 1e  mov  0x1e, %o1
a012148c:  7f ff 42 d5  call  0xa00f1fe0
a0121490:  94 10 20 3f  mov  0x3f, %o2
a0121494:  90 10 00 18  mov  %i0, %o0
a0121498:  92 10 20 1f  mov  0x1f, %o1
a012149c:  7f ff 42 d1  call  0xa00f1fe0
a01214a0:  94 10 20 1f  mov  0x1f, %o2
a01214a4:  90 10 00 18  mov  %i0, %o0
a01214a8:  94 0c a0 ff  and  %l2, 0xff, %o2
a01214ac:  7f ff 42 cd  call  0xa00f1fe0
a01214b0:  92 10 20 1c  mov  0x1c, %o1
a01214b4:  90 10 00 18  mov  %i0, %o0
a01214b8:  94 0e a0 17  and  %i2, 0x17, %o2
a01214bc:  7f ff 42 c9  call  0xa00f1fe0
a01214c0:  92 10 20 1d  mov  0x1d, %o1
a01214c4:  30 80 00 3f  b,a   0xa01215c0
a01214c8:  02 80 00 0c  be  0xa01214f8
a01214cc:  80 a4 20 b1  cmp  %l0, 0xb1
a01214d0:  14 80 00 23  bg  0xa012155c
a01214d4:  80 a4 20 e1  cmp  %l0, 0xe1
a01214d8:  80 a4 20 81  cmp  %l0, 0x81
a01214dc:  22 bf ff df  be,a   0xa0121458
a01214e0:  b4 10 20 03  mov  3, %i2
a01214e4:  14 80 00 29  bg  0xa0121588
a01214e8:  80 a4 20 91  cmp  %l0, 0x91
a01214ec:  80 a4 20 71  cmp  %l0, 0x71
a01214f0:  12 bf ff db  bne  0xa012145c
a01214f4:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a01214f8:  10 bf ff d8  b  0xa0121458
a01214fc:  b4 10 20 03  mov  3, %i2
a0121500:  02 80 00 07  be  0xa012151c
a0121504:  80 a4 20 41  cmp  %l0, 0x41
a0121508:  14 80 00 03  bg  0xa0121514
a012150c:  80 a4 20 51  cmp  %l0, 0x51
a0121510:  80 a4 20 31  cmp  %l0, 0x31
a0121514:  12 bf ff d2  bne  0xa012145c
a0121518:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a012151c:  10 bf ff cf  b  0xa0121458
a0121520:  b4 10 20 13  mov  0x13, %i2
a0121524:  95 28 40 11  sll  %g1, %l1, %o2
a0121528:  92 2b 40 0a  andn  %o5, %o2, %o1
a012152c:  d2 23 21 e4  st  %o1, [ %o4 + 0x1e4 ]
a0121530:  92 0e 60 ff  and  %i1, 0xff, %o1
a0121534:  90 10 00 11  mov  %l1, %o0
a0121538:  7f ff ff 51  call  0xa012127c
a012153c:  94 10 20 00  clr  %o2
a0121540:  11 00 06 8b  sethi  %hi(0x1a2c00), %o0
a0121544:  b0 10 20 01  mov  1, %i0
a0121548:  92 10 00 11  mov  %l1, %o1
a012154c:  7f fe f7 09  call  0xa00df170
a0121550:  90 12 23 f8  or  %o0, 0x3f8, %o0
a0121554:  10 bf ff a5  b  0xa01213e8
a0121558:  82 06 3f fe  add  %i0, -2, %g1
a012155c:  06 bf ff c0  bl  0xa012145c
a0121560:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0121564:  80 a4 20 e2  cmp  %l0, 0xe2
a0121568:  24 bf ff bd  ble,a   0xa012145c
a012156c:  b4 10 20 03  mov  3, %i2
a0121570:  80 a4 20 e8  cmp  %l0, 0xe8
a0121574:  12 bf ff bb  bne  0xa0121460
a0121578:  b0 0a 20 ff  and  %o0, 0xff, %i0
a012157c:  a4 10 20 00  clr  %l2
a0121580:  10 bf ff b8  b  0xa0121460
a0121584:  b4 10 20 00  clr  %i2
a0121588:  12 bf ff b5  bne  0xa012145c
a012158c:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0121590:  9a 04 40 11  add  %l1, %l1, %o5
a0121594:  94 03 40 11  add  %o5, %l1, %o2
a0121598:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a012159c:  b5 2a a0 02  sll  %o2, 2, %i2
a01215a0:  92 12 e2 ac  or  %o3, 0x2ac, %o1
a01215a4:  b0 06 80 09  add  %i2, %o1, %i0
a01215a8:  e0 0e 20 09  ldub  [ %i0 + 9 ], %l0
a01215ac:  80 a4 20 00  cmp  %l0, 0
a01215b0:  02 bf ff ab  be  0xa012145c
a01215b4:  b4 10 20 03  mov  3, %i2
a01215b8:  10 bf ff a9  b  0xa012145c
a01215bc:  b4 10 20 02  mov  2, %i2
a01215c0:  81 c7 e0 08  ret
a01215c4:  91 e8 00 19  restore  %g0, %i1, %o0
