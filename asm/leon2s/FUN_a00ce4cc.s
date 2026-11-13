# leon2s FUN_a00ce4cc 0xa00ce4cc-0xa00ce66c (416 bytes)
a00ce4cc:  9d e3 bf 88  save  %sp, -120, %sp
a00ce4d0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ce4d4:  82 06 00 18  add  %i0, %i0, %g1
a00ce4d8:  82 00 40 18  add  %g1, %i0, %g1
a00ce4dc:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00ce4e0:  a1 28 60 03  sll  %g1, 3, %l0
a00ce4e4:  a2 14 e3 b0  or  %l3, 0x3b0, %l1
a00ce4e8:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00ce4ec:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ce4f0:  82 2b 40 01  andn  %o5, %g1, %g1
a00ce4f4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ce4f8:  82 10 40 0d  or  %g1, %o5, %g1
a00ce4fc:  a4 07 bf e8  add  %fp, -24, %l2
a00ce500:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00ce504:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ce508:  94 12 a0 93  or  %o2, 0x93, %o2
a00ce50c:  90 10 20 00  clr  %o0
a00ce510:  92 10 20 90  mov  0x90, %o1
a00ce514:  96 10 20 00  clr  %o3
a00ce518:  40 3b 1f ba  call  0xa0f96400
a00ce51c:  98 10 00 12  mov  %l2, %o4
a00ce520:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00ce524:  80 88 60 02  btst  2, %g1
a00ce528:  12 80 00 11  bne  0xa00ce56c
a00ce52c:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00ce530:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00ce534:  82 10 40 0d  or  %g1, %o5, %g1
a00ce538:  10 80 00 4b  b  0xa00ce664
a00ce53c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ce540:  9a 06 00 18  add  %i0, %i0, %o5
a00ce544:  9a 03 40 18  add  %o5, %i0, %o5
a00ce548:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00ce54c:  9b 2b 60 03  sll  %o5, 3, %o5
a00ce550:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00ce554:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ce558:  82 2b 00 01  andn  %o4, %g1, %g1
a00ce55c:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00ce560:  7f ff e5 1a  call  0xa00c79c8
a00ce564:  90 10 00 18  mov  %i0, %o0
a00ce568:  30 80 00 3f  b,a   0xa00ce664
a00ce56c:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00ce570:  94 12 a2 c0  or  %o2, 0x2c0, %o2	! 0x692c0
a00ce574:  96 10 20 0f  mov  0xf, %o3
a00ce578:  90 10 20 00  clr  %o0
a00ce57c:  92 10 20 90  mov  0x90, %o1
a00ce580:  40 3b 1f a0  call  0xa0f96400
a00ce584:  98 10 00 12  mov  %l2, %o4
a00ce588:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce58c:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00ce590:  96 10 20 00  clr  %o3
a00ce594:  a0 07 bf f8  add  %fp, -8, %l0
a00ce598:  99 2a e0 10  sll  %o3, 0x10, %o4
a00ce59c:  99 33 20 10  srl  %o4, 0x10, %o4
a00ce5a0:  96 02 e0 01  inc  %o3
a00ce5a4:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce5a8:  82 04 00 0c  add  %l0, %o4, %g1
a00ce5ac:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00ce5b0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce5b4:  80 a3 60 0f  cmp  %o5, 0xf
a00ce5b8:  08 bf ff f8  bleu  0xa00ce598
a00ce5bc:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00ce5c0:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00ce5c4:  94 12 a2 d0  or  %o2, 0x2d0, %o2	! 0x692d0
a00ce5c8:  96 10 20 0f  mov  0xf, %o3
a00ce5cc:  98 10 00 12  mov  %l2, %o4
a00ce5d0:  90 10 20 00  clr  %o0
a00ce5d4:  40 3b 1f 8b  call  0xa0f96400
a00ce5d8:  92 10 20 90  mov  0x90, %o1
a00ce5dc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce5e0:  94 10 61 88  or  %g1, 0x188, %o2	! 0xa807cd88
a00ce5e4:  96 10 20 00  clr  %o3
a00ce5e8:  83 2a e0 10  sll  %o3, 0x10, %g1
a00ce5ec:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce5f0:  96 02 e0 01  inc  %o3
a00ce5f4:  98 04 00 01  add  %l0, %g1, %o4
a00ce5f8:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce5fc:  d8 0b 3f f0  ldub  [ %o4 + -16 ], %o4
a00ce600:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce604:  82 00 40 0a  add  %g1, %o2, %g1
a00ce608:  80 a3 60 0f  cmp  %o5, 0xf
a00ce60c:  08 bf ff f7  bleu  0xa00ce5e8
a00ce610:  d8 28 60 10  stb  %o4, [ %g1 + 0x10 ]
a00ce614:  7f ff f0 30  call  0xa00ca6d4
a00ce618:  90 10 00 18  mov  %i0, %o0
a00ce61c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00ce620:  90 10 60 88  or  %g1, 0x88, %o0	! 0xa807d088
a00ce624:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce628:  92 10 61 88  or  %g1, 0x188, %o1	! 0xa807cd88
a00ce62c:  96 10 20 00  clr  %o3
a00ce630:  98 02 e0 01  add  %o3, 1, %o4
a00ce634:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00ce638:  83 2a e0 10  sll  %o3, 0x10, %g1
a00ce63c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce640:  95 33 60 10  srl  %o5, 0x10, %o2
a00ce644:  da 0a 40 01  ldub  [ %o1 + %g1 ], %o5
a00ce648:  c2 0a 00 01  ldub  [ %o0 + %g1 ], %g1
a00ce64c:  80 a0 40 0d  cmp  %g1, %o5
a00ce650:  12 bf ff bc  bne  0xa00ce540
a00ce654:  96 10 00 0c  mov  %o4, %o3
a00ce658:  80 a2 a0 1f  cmp  %o2, 0x1f
a00ce65c:  08 bf ff f6  bleu  0xa00ce634
a00ce660:  98 02 e0 01  add  %o3, 1, %o4
a00ce664:  81 c7 e0 08  ret
a00ce668:  81 e8 00 00  restore
