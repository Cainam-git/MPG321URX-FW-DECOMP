# leon2m FUN_a00a9468 0xa00a9468-0xa00a9650 (488 bytes)
a00a9468:  9d e3 bf 98  save  %sp, -104, %sp
a00a946c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a9470:  80 a6 20 02  cmp  %i0, 2
a00a9474:  a6 10 20 00  clr  %l3
a00a9478:  9a 10 20 00  clr  %o5
a00a947c:  96 10 20 00  clr  %o3
a00a9480:  02 80 00 06  be  0xa00a9498
a00a9484:  92 10 20 06  mov  6, %o1
a00a9488:  80 a0 00 18  cmp  %g0, %i0
a00a948c:  90 60 20 00  subx  %g0, 0, %o0
a00a9490:  82 0a 20 05  and  %o0, 5, %g1
a00a9494:  92 00 60 0b  add  %g1, 0xb, %o1
a00a9498:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a949c:  80 a6 60 06  cmp  %i1, 6
a00a94a0:  02 80 00 13  be  0xa00a94ec
a00a94a4:  80 a6 60 05  cmp  %i1, 5
a00a94a8:  02 80 00 2a  be  0xa00a9550
a00a94ac:  80 a6 60 04  cmp  %i1, 4
a00a94b0:  02 80 00 0b  be  0xa00a94dc
a00a94b4:  80 a6 60 00  cmp  %i1, 0
a00a94b8:  02 80 00 54  be  0xa00a9608
a00a94bc:  1f 00 00 0f  sethi  %hi(0x3c00), %o7
a00a94c0:  80 a6 60 01  cmp  %i1, 1
a00a94c4:  02 80 00 54  be  0xa00a9614
a00a94c8:  80 a6 60 02  cmp  %i1, 2
a00a94cc:  02 80 00 5a  be  0xa00a9634
a00a94d0:  80 a6 60 03  cmp  %i1, 3
a00a94d4:  02 80 00 55  be  0xa00a9628
a00a94d8:  31 00 00 13  sethi  %hi(0x4c00), %i0
a00a94dc:  80 a6 60 06  cmp  %i1, 6
a00a94e0:  12 80 00 21  bne  0xa00a9564
a00a94e4:  b0 0a 60 ff  and  %o1, 0xff, %i0
a00a94e8:  30 80 00 58  b,a   0xa00a9648
a00a94ec:  a2 0a 60 ff  and  %o1, 0xff, %l1
a00a94f0:  b2 10 20 00  clr  %i1
a00a94f4:  98 0e 60 ff  and  %i1, 0xff, %o4
a00a94f8:  96 04 40 0c  add  %l1, %o4, %o3
a00a94fc:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a9500:  a1 32 a0 10  srl  %o2, 0x10, %l0
a00a9504:  90 10 20 37  mov  0x37, %o0
a00a9508:  92 10 00 10  mov  %l0, %o1
a00a950c:  94 10 20 04  mov  4, %o2
a00a9510:  96 10 27 92  mov  0x792, %o3
a00a9514:  40 02 75 5b  call  0xa0146a80
a00a9518:  98 10 20 00  clr  %o4
a00a951c:  92 10 20 37  mov  0x37, %o1
a00a9520:  94 10 00 10  mov  %l0, %o2
a00a9524:  90 10 20 00  clr  %o0
a00a9528:  96 10 20 04  mov  4, %o3
a00a952c:  98 10 20 00  clr  %o4
a00a9530:  40 02 75 7c  call  0xa0146b20
a00a9534:  9a 10 20 00  clr  %o5
a00a9538:  b2 06 60 01  inc  %i1
a00a953c:  92 0e 60 ff  and  %i1, 0xff, %o1
a00a9540:  80 a2 60 03  cmp  %o1, 3
a00a9544:  08 bf ff ed  bleu  0xa00a94f8
a00a9548:  98 0e 60 ff  and  %i1, 0xff, %o4
a00a954c:  30 80 00 3f  b,a   0xa00a9648
a00a9550:  1b 00 00 0e  sethi  %hi(0x3800), %o5
a00a9554:  a6 13 61 9e  or  %o5, 0x19e, %l3	! 0x399e
a00a9558:  9a 10 27 92  mov  0x792, %o5
a00a955c:  96 10 29 92  mov  0x992, %o3
a00a9560:  b0 0a 60 ff  and  %o1, 0xff, %i0
a00a9564:  a5 2b 60 10  sll  %o5, 0x10, %l2
a00a9568:  a3 2a e0 10  sll  %o3, 0x10, %l1
a00a956c:  b2 10 20 00  clr  %i1
a00a9570:  94 0e 60 ff  and  %i1, 0xff, %o2
a00a9574:  92 06 00 0a  add  %i0, %o2, %o1
a00a9578:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a957c:  a1 32 20 10  srl  %o0, 0x10, %l0
a00a9580:  90 10 20 37  mov  0x37, %o0
a00a9584:  92 10 00 10  mov  %l0, %o1
a00a9588:  94 10 20 01  mov  1, %o2
a00a958c:  97 34 a0 10  srl  %l2, 0x10, %o3
a00a9590:  40 02 75 3c  call  0xa0146a80
a00a9594:  98 10 20 00  clr  %o4
a00a9598:  92 10 00 10  mov  %l0, %o1
a00a959c:  90 10 20 3a  mov  0x3a, %o0
a00a95a0:  94 10 20 01  mov  1, %o2
a00a95a4:  97 34 60 10  srl  %l1, 0x10, %o3
a00a95a8:  40 02 75 36  call  0xa0146a80
a00a95ac:  98 10 20 00  clr  %o4
a00a95b0:  b2 06 60 01  inc  %i1
a00a95b4:  82 0e 60 ff  and  %i1, 0xff, %g1
a00a95b8:  80 a0 60 02  cmp  %g1, 2
a00a95bc:  08 bf ff ee  bleu  0xa00a9574
a00a95c0:  94 0e 60 ff  and  %i1, 0xff, %o2
a00a95c4:  b3 2c e0 10  sll  %l3, 0x10, %i1
a00a95c8:  a0 10 20 00  clr  %l0
a00a95cc:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a95d0:  98 06 00 0d  add  %i0, %o5, %o4
a00a95d4:  97 2b 20 10  sll  %o4, 0x10, %o3
a00a95d8:  93 32 e0 10  srl  %o3, 0x10, %o1
a00a95dc:  90 10 20 38  mov  0x38, %o0
a00a95e0:  94 10 20 02  mov  2, %o2
a00a95e4:  97 36 60 10  srl  %i1, 0x10, %o3
a00a95e8:  98 10 20 00  clr  %o4
a00a95ec:  40 02 75 25  call  0xa0146a80
a00a95f0:  a0 04 20 01  inc  %l0
a00a95f4:  a6 0c 20 ff  and  %l0, 0xff, %l3
a00a95f8:  80 a4 e0 02  cmp  %l3, 2
a00a95fc:  08 bf ff f5  bleu  0xa00a95d0
a00a9600:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a9604:  30 80 00 11  b,a   0xa00a9648
a00a9608:  a6 13 e2 9e  or  %o7, 0x29e, %l3
a00a960c:  10 bf ff d4  b  0xa00a955c
a00a9610:  9a 10 29 92  mov  0x992, %o5
a00a9614:  23 00 00 10  sethi  %hi(0x4000), %l1
a00a9618:  a6 14 63 9e  or  %l1, 0x39e, %l3	! 0x439e
a00a961c:  9a 10 27 92  mov  0x792, %o5
a00a9620:  10 bf ff d0  b  0xa00a9560
a00a9624:  96 10 27 92  mov  0x792, %o3
a00a9628:  a6 16 21 9e  or  %i0, 0x19e, %l3
a00a962c:  10 bf ff cc  b  0xa00a955c
a00a9630:  9a 10 29 92  mov  0x992, %o5
a00a9634:  25 00 00 12  sethi  %hi(0x4800), %l2
a00a9638:  a6 14 a0 9e  or  %l2, 0x9e, %l3	! 0x489e
a00a963c:  9a 10 29 92  mov  0x992, %o5
a00a9640:  10 bf ff c8  b  0xa00a9560
a00a9644:  96 10 27 92  mov  0x792, %o3
a00a9648:  81 c7 e0 08  ret
a00a964c:  81 e8 00 00  restore
