# leon2s FUN_a0090380 0xa0090380-0xa0090498 (280 bytes)
a0090380:  9d e3 bf 98  save  %sp, -104, %sp
a0090384:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0090388:  80 a6 60 83  cmp  %i1, 0x83
a009038c:  22 80 00 1a  be,a   0xa00903f4
a0090390:  b2 10 20 00  clr  %i1
a0090394:  14 80 00 06  bg  0xa00903ac
a0090398:  80 a6 60 84  cmp  %i1, 0x84
a009039c:  80 a6 60 82  cmp  %i1, 0x82
a00903a0:  02 80 00 08  be  0xa00903c0
a00903a4:  b2 10 20 00  clr  %i1
a00903a8:  30 80 00 3a  b,a   0xa0090490
a00903ac:  02 80 00 1f  be  0xa0090428
a00903b0:  80 a6 60 87  cmp  %i1, 0x87
a00903b4:  22 80 00 2b  be,a   0xa0090460
a00903b8:  b2 10 20 00  clr  %i1
a00903bc:  30 80 00 35  b,a   0xa0090490
a00903c0:  92 0e 60 ff  and  %i1, 0xff, %o1
a00903c4:  92 02 61 44  add  %o1, 0x144, %o1
a00903c8:  93 2a 60 10  sll  %o1, 0x10, %o1
a00903cc:  93 32 60 10  srl  %o1, 0x10, %o1
a00903d0:  40 00 58 6b  call  0xa00a657c
a00903d4:  90 0e 20 ff  and  %i0, 0xff, %o0
a00903d8:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00903dc:  b2 06 60 01  inc  %i1
a00903e0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00903e4:  80 a0 60 1b  cmp  %g1, 0x1b
a00903e8:  08 bf ff f6  bleu  0xa00903c0
a00903ec:  d0 2e 80 0d  stb  %o0, [ %i2 + %o5 ]
a00903f0:  30 80 00 28  b,a   0xa0090490
a00903f4:  92 0e 60 ff  and  %i1, 0xff, %o1
a00903f8:  92 02 61 64  add  %o1, 0x164, %o1
a00903fc:  93 2a 60 10  sll  %o1, 0x10, %o1
a0090400:  93 32 60 10  srl  %o1, 0x10, %o1
a0090404:  40 00 58 5e  call  0xa00a657c
a0090408:  90 0e 20 ff  and  %i0, 0xff, %o0
a009040c:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0090410:  b2 06 60 01  inc  %i1
a0090414:  82 0e 60 ff  and  %i1, 0xff, %g1
a0090418:  80 a0 60 1b  cmp  %g1, 0x1b
a009041c:  08 bf ff f6  bleu  0xa00903f4
a0090420:  d0 2e 80 0d  stb  %o0, [ %i2 + %o5 ]
a0090424:  30 80 00 1b  b,a   0xa0090490
a0090428:  b2 10 20 00  clr  %i1
a009042c:  92 0e 60 ff  and  %i1, 0xff, %o1
a0090430:  92 02 61 84  add  %o1, 0x184, %o1
a0090434:  93 2a 60 10  sll  %o1, 0x10, %o1
a0090438:  93 32 60 10  srl  %o1, 0x10, %o1
a009043c:  40 00 58 50  call  0xa00a657c
a0090440:  90 0e 20 ff  and  %i0, 0xff, %o0
a0090444:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0090448:  b2 06 60 01  inc  %i1
a009044c:  82 0e 60 ff  and  %i1, 0xff, %g1
a0090450:  80 a0 60 1b  cmp  %g1, 0x1b
a0090454:  08 bf ff f6  bleu  0xa009042c
a0090458:  d0 2e 80 0d  stb  %o0, [ %i2 + %o5 ]
a009045c:  30 80 00 0d  b,a   0xa0090490
a0090460:  92 0e 60 ff  and  %i1, 0xff, %o1
a0090464:  92 02 61 b0  add  %o1, 0x1b0, %o1
a0090468:  93 2a 60 10  sll  %o1, 0x10, %o1
a009046c:  93 32 60 10  srl  %o1, 0x10, %o1
a0090470:  40 00 58 43  call  0xa00a657c
a0090474:  90 0e 20 ff  and  %i0, 0xff, %o0
a0090478:  9a 0e 60 ff  and  %i1, 0xff, %o5
a009047c:  b2 06 60 01  inc  %i1
a0090480:  82 0e 60 ff  and  %i1, 0xff, %g1
a0090484:  80 a0 60 1b  cmp  %g1, 0x1b
a0090488:  08 bf ff f6  bleu  0xa0090460
a009048c:  d0 2e 80 0d  stb  %o0, [ %i2 + %o5 ]
a0090490:  81 c7 e0 08  ret
a0090494:  81 e8 00 00  restore
