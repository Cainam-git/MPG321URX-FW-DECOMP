# leon2s FUN_a00d74ec 0xa00d74ec-0xa00d7638 (332 bytes)
a00d74ec:  9d e3 bf 98  save  %sp, -104, %sp
a00d74f0:  c2 0e 00 00  ldub  [ %i0 ], %g1
a00d74f4:  98 10 00 18  mov  %i0, %o4
a00d74f8:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d74fc:  b0 10 00 19  mov  %i1, %i0
a00d7500:  c2 2e 40 00  stb  %g1, [ %i1 ]
a00d7504:  b2 10 20 01  mov  1, %i1
a00d7508:  b4 10 20 00  clr  %i2
a00d750c:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d7510:  82 03 00 01  add  %o4, %g1, %g1
a00d7514:  b8 10 00 19  mov  %i1, %i4
a00d7518:  fa 08 60 01  ldub  [ %g1 + 1 ], %i5
a00d751c:  b4 06 a0 01  inc  %i2
a00d7520:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00d7524:  b8 07 20 01  inc  %i4
a00d7528:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d752c:  fa 2e 00 1b  stb  %i5, [ %i0 + %i3 ]
a00d7530:  80 a0 60 0f  cmp  %g1, 0xf
a00d7534:  08 bf ff f7  bleu  0xa00d7510
a00d7538:  b2 10 00 1c  mov  %i4, %i1
a00d753c:  c2 0b 20 11  ldub  [ %o4 + 0x11 ], %g1
a00d7540:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7544:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00d7548:  c2 2e 00 1d  stb  %g1, [ %i0 + %i5 ]
a00d754c:  c2 0b 20 11  ldub  [ %o4 + 0x11 ], %g1
a00d7550:  80 88 60 0f  btst  0xf, %g1
a00d7554:  b2 07 20 01  add  %i4, 1, %i1
a00d7558:  02 80 00 36  be  0xa00d7630
a00d755c:  9a 10 20 00  clr  %o5
a00d7560:  ba 0b 60 ff  and  %o5, 0xff, %i5
a00d7564:  83 2f 60 02  sll  %i5, 2, %g1
a00d7568:  82 00 40 1d  add  %g1, %i5, %g1
a00d756c:  83 28 60 02  sll  %g1, 2, %g1
a00d7570:  b6 00 40 0c  add  %g1, %o4, %i3
a00d7574:  c2 0e e0 12  ldub  [ %i3 + 0x12 ], %g1
a00d7578:  ba 0e 60 ff  and  %i1, 0xff, %i5
a00d757c:  c2 2e 00 1d  stb  %g1, [ %i0 + %i5 ]
a00d7580:  c2 0e e0 12  ldub  [ %i3 + 0x12 ], %g1
a00d7584:  83 30 60 07  srl  %g1, 7, %g1
a00d7588:  b8 06 60 01  add  %i1, 1, %i4
a00d758c:  80 a0 60 00  cmp  %g1, 0
a00d7590:  b4 07 20 01  add  %i4, 1, %i2
a00d7594:  12 80 00 1c  bne  0xa00d7604
a00d7598:  c2 0e e0 13  ldub  [ %i3 + 0x13 ], %g1
a00d759c:  ba 08 60 e0  and  %g1, 0xe0, %i5
a00d75a0:  82 0f 20 ff  and  %i4, 0xff, %g1
a00d75a4:  fa 2e 00 01  stb  %i5, [ %i0 + %g1 ]
a00d75a8:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00d75ac:  c2 0e e0 14  ldub  [ %i3 + 0x14 ], %g1
a00d75b0:  c2 2e 00 1d  stb  %g1, [ %i0 + %i5 ]
a00d75b4:  b2 07 20 02  add  %i4, 2, %i1
a00d75b8:  9e 10 00 1b  mov  %i3, %o7
a00d75bc:  b4 10 20 00  clr  %i2
a00d75c0:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d75c4:  82 03 c0 01  add  %o7, %g1, %g1
a00d75c8:  b8 10 00 19  mov  %i1, %i4
a00d75cc:  fa 08 60 15  ldub  [ %g1 + 0x15 ], %i5
a00d75d0:  b4 06 a0 01  inc  %i2
a00d75d4:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00d75d8:  b8 07 20 01  inc  %i4
a00d75dc:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d75e0:  fa 2e 00 1b  stb  %i5, [ %i0 + %i3 ]
a00d75e4:  80 a0 60 0f  cmp  %g1, 0xf
a00d75e8:  08 bf ff f7  bleu  0xa00d75c4
a00d75ec:  b2 10 00 1c  mov  %i4, %i1
a00d75f0:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00d75f4:  c2 0b e0 25  ldub  [ %o7 + 0x25 ], %g1
a00d75f8:  c2 2e 00 1d  stb  %g1, [ %i0 + %i5 ]
a00d75fc:  10 80 00 06  b  0xa00d7614
a00d7600:  b2 07 20 01  add  %i4, 1, %i1
a00d7604:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00d7608:  82 08 60 c0  and  %g1, 0xc0, %g1
a00d760c:  c2 2e 00 1d  stb  %g1, [ %i0 + %i5 ]
a00d7610:  b2 10 00 1a  mov  %i2, %i1
a00d7614:  9a 03 60 01  inc  %o5
a00d7618:  c2 0b 20 11  ldub  [ %o4 + 0x11 ], %g1
a00d761c:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7620:  ba 0b 60 ff  and  %o5, 0xff, %i5
a00d7624:  80 a7 40 01  cmp  %i5, %g1
a00d7628:  0a bf ff d0  bcs  0xa00d7568
a00d762c:  83 2f 60 02  sll  %i5, 2, %g1
a00d7630:  81 c7 e0 08  ret
a00d7634:  81 e8 00 00  restore
