# leon2s FUN_a00d95e4 0xa00d95e4-0xa00d9698 (180 bytes)
a00d95e4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d95e8:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4	! 0xa8078832
a00d95ec:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d95f0:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00d95f4:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00d95f8:  9a 03 00 0c  add  %o4, %o4, %o5
a00d95fc:  82 08 60 0f  and  %g1, 0xf, %g1
a00d9600:  9a 03 40 0c  add  %o5, %o4, %o5
a00d9604:  98 00 40 01  add  %g1, %g1, %o4
a00d9608:  98 03 00 01  add  %o4, %g1, %o4
a00d960c:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00d9610:  82 10 62 3d  or  %g1, 0x23d, %g1	! 0xa807963d
a00d9614:  9b 2b 60 08  sll  %o5, 8, %o5
a00d9618:  9a 03 40 01  add  %o5, %g1, %o5
a00d961c:  99 2b 20 04  sll  %o4, 4, %o4
a00d9620:  d6 0b 40 0c  ldub  [ %o5 + %o4 ], %o3
a00d9624:  82 0a e0 f0  and  %o3, 0xf0, %g1
a00d9628:  95 30 60 04  srl  %g1, 4, %o2
a00d962c:  90 03 40 0c  add  %o5, %o4, %o0
a00d9630:  9a 02 bf ff  add  %o2, -1, %o5
a00d9634:  83 33 60 1f  srl  %o5, 0x1f, %g1
a00d9638:  82 03 40 01  add  %o5, %g1, %g1
a00d963c:  99 38 60 01  sra  %g1, 1, %o4
a00d9640:  96 0a e0 0f  and  %o3, 0xf, %o3
a00d9644:  80 8b 60 01  btst  1, %o5
a00d9648:  96 0a e0 ff  and  %o3, 0xff, %o3
a00d964c:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d9650:  82 10 60 3d  or  %g1, 0x3d, %g1	! 0xa8079c3d
a00d9654:  9a 02 c0 0b  add  %o3, %o3, %o5
a00d9658:  92 03 40 01  add  %o5, %g1, %o1
a00d965c:  02 80 00 03  be  0xa00d9668
a00d9660:  82 10 00 0c  mov  %o4, %g1
a00d9664:  82 03 20 01  add  %o4, 1, %g1
a00d9668:  82 08 60 ff  and  %g1, 0xff, %g1
a00d966c:  9a 02 00 01  add  %o0, %g1, %o5
a00d9670:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a00d9674:  82 08 60 10  and  %g1, 0x10, %g1
a00d9678:  83 30 60 04  srl  %g1, 4, %g1
a00d967c:  80 a2 80 0b  cmp  %o2, %o3
a00d9680:  08 80 00 04  bleu  0xa00d9690
a00d9684:  98 08 60 ff  and  %g1, 0xff, %o4
a00d9688:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a00d968c:  c2 2a 40 0c  stb  %g1, [ %o1 + %o4 ]
a00d9690:  81 c3 e0 08  retl
a00d9694:  d0 0b 60 03  ldub  [ %o5 + 3 ], %o0
