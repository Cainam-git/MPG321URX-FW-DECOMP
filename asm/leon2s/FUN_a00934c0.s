# leon2s FUN_a00934c0 0xa00934c0-0xa0094308 (3656 bytes)
a00934c0:  9d e3 bf 98  save  %sp, -104, %sp
a00934c4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00934c8:  ae 10 00 18  mov  %i0, %l7
a00934cc:  80 a4 20 01  cmp  %l0, 1
a00934d0:  aa 10 20 00  clr  %l5
a00934d4:  ba 10 20 00  clr  %i5
a00934d8:  18 80 03 89  bgu  0xa00942fc
a00934dc:  b0 10 20 00  clr  %i0
a00934e0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00934e4:  80 a6 60 0e  cmp  %i1, 0xe
a00934e8:  18 80 00 83  bgu  0xa00936f4
a00934ec:  82 10 20 01  mov  1, %g1
a00934f0:  9b 28 40 19  sll  %g1, %i1, %o5
a00934f4:  03 00 00 15  sethi  %hi(0x5400), %g1
a00934f8:  82 10 61 00  or  %g1, 0x100, %g1	! 0x5500
a00934fc:  80 8b 40 01  btst  %o5, %g1
a0093500:  12 80 00 06  bne  0xa0093518
a0093504:  03 28 02 99  sethi  %hi(0xa00a6400), %g1
a0093508:  80 8b 60 50  btst  0x50, %o5
a009350c:  12 80 00 50  bne  0xa009364c
a0093510:  80 a6 60 04  cmp  %i1, 4
a0093514:  30 80 00 78  b,a   0xa00936f4
a0093518:  80 a6 60 08  cmp  %i1, 8
a009351c:  02 80 00 0b  be  0xa0093548
a0093520:  82 10 61 7c  or  %g1, 0x17c, %g1
a0093524:  03 28 02 99  sethi  %hi(0xa00a6400), %g1
a0093528:  80 a6 60 0a  cmp  %i1, 0xa
a009352c:  02 80 00 0e  be  0xa0093564
a0093530:  82 10 61 7c  or  %g1, 0x17c, %g1
a0093534:  80 a6 60 0c  cmp  %i1, 0xc
a0093538:  12 80 00 07  bne  0xa0093554
a009353c:  80 a6 60 0e  cmp  %i1, 0xe
a0093540:  03 28 02 9a  sethi  %hi(0xa00a6800), %g1
a0093544:  82 10 61 b4  or  %g1, 0x1b4, %g1	! 0xa00a69b4
a0093548:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009354c:  10 80 00 09  b  0xa0093570
a0093550:  c2 23 61 b8  st  %g1, [ %o5 + 0x1b8 ]	! 0xa807d5b8
a0093554:  12 80 00 08  bne  0xa0093574
a0093558:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009355c:  03 28 02 9a  sethi  %hi(0xa00a6800), %g1
a0093560:  82 10 61 b4  or  %g1, 0x1b4, %g1	! 0xa00a69b4
a0093564:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0093568:  c2 23 61 b8  st  %g1, [ %o5 + 0x1b8 ]	! 0xa807d5b8
a009356c:  aa 10 20 01  mov  1, %l5
a0093570:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a0093574:  a4 0d 60 ff  and  %l5, 0xff, %l2
a0093578:  c2 04 61 b8  ld  [ %l1 + 0x1b8 ], %g1
a009357c:  90 10 00 12  mov  %l2, %o0
a0093580:  9f c0 40 00  call  %g1
a0093584:  92 10 21 2a  mov  0x12a, %o1
a0093588:  80 8a 20 02  btst  2, %o0
a009358c:  02 80 00 1a  be  0xa00935f4
a0093590:  90 10 00 10  mov  %l0, %o0
a0093594:  c2 04 61 b8  ld  [ %l1 + 0x1b8 ], %g1
a0093598:  90 10 00 12  mov  %l2, %o0
a009359c:  9f c0 40 00  call  %g1
a00935a0:  92 10 22 80  mov  0x280, %o1
a00935a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00935a8:  80 a2 20 09  cmp  %o0, 9
a00935ac:  12 80 00 12  bne  0xa00935f4
a00935b0:  90 10 00 10  mov  %l0, %o0
a00935b4:  92 10 20 00  clr  %o1
a00935b8:  94 10 21 24  mov  0x124, %o2
a00935bc:  40 00 52 a6  call  0xa00a8054
a00935c0:  96 10 20 9b  mov  0x9b, %o3
a00935c4:  90 10 00 10  mov  %l0, %o0
a00935c8:  92 10 20 00  clr  %o1
a00935cc:  94 10 21 2f  mov  0x12f, %o2
a00935d0:  96 10 20 06  mov  6, %o3
a00935d4:  40 00 52 be  call  0xa00a80cc
a00935d8:  98 10 20 00  clr  %o4
a00935dc:  90 10 00 10  mov  %l0, %o0
a00935e0:  92 10 20 00  clr  %o1
a00935e4:  94 10 21 1d  mov  0x11d, %o2
a00935e8:  96 10 20 80  mov  0x80, %o3
a00935ec:  10 80 00 11  b  0xa0093630
a00935f0:  98 10 20 01  mov  1, %o4
a00935f4:  92 10 20 00  clr  %o1
a00935f8:  94 10 21 24  mov  0x124, %o2
a00935fc:  40 00 52 96  call  0xa00a8054
a0093600:  96 10 20 2b  mov  0x2b, %o3
a0093604:  90 10 00 10  mov  %l0, %o0
a0093608:  92 10 20 00  clr  %o1
a009360c:  94 10 21 2f  mov  0x12f, %o2
a0093610:  96 10 20 04  mov  4, %o3
a0093614:  40 00 52 ae  call  0xa00a80cc
a0093618:  98 10 20 00  clr  %o4
a009361c:  90 10 00 10  mov  %l0, %o0
a0093620:  92 10 20 00  clr  %o1
a0093624:  94 10 21 2f  mov  0x12f, %o2
a0093628:  96 10 20 02  mov  2, %o3
a009362c:  98 10 20 00  clr  %o4
a0093630:  40 00 52 a7  call  0xa00a80cc
a0093634:  01 00 00 00  nop
a0093638:  90 10 00 12  mov  %l2, %o0
a009363c:  7f ff fe f0  call  0xa00931fc
a0093640:  92 0d e0 ff  and  %l7, 0xff, %o1
a0093644:  10 80 00 3a  b  0xa009372c
a0093648:  80 a6 60 0e  cmp  %i1, 0xe
a009364c:  02 80 00 04  be  0xa009365c
a0093650:  80 a6 60 06  cmp  %i1, 6
a0093654:  22 80 00 02  be,a   0xa009365c
a0093658:  aa 10 20 01  mov  1, %l5
a009365c:  a2 0d 60 ff  and  %l5, 0xff, %l1
a0093660:  90 10 00 11  mov  %l1, %o0
a0093664:  40 00 4d 55  call  0xa00a6bb8
a0093668:  92 10 20 51  mov  0x51, %o1
a009366c:  90 0a 20 1c  and  %o0, 0x1c, %o0
a0093670:  80 a2 20 1c  cmp  %o0, 0x1c
a0093674:  12 80 00 11  bne  0xa00936b8
a0093678:  90 10 00 10  mov  %l0, %o0
a009367c:  92 10 20 00  clr  %o1
a0093680:  94 10 21 24  mov  0x124, %o2
a0093684:  40 00 52 74  call  0xa00a8054
a0093688:  96 10 20 2b  mov  0x2b, %o3
a009368c:  90 10 00 10  mov  %l0, %o0
a0093690:  92 10 20 00  clr  %o1
a0093694:  94 10 21 2f  mov  0x12f, %o2
a0093698:  96 10 20 04  mov  4, %o3
a009369c:  40 00 52 8c  call  0xa00a80cc
a00936a0:  98 10 20 00  clr  %o4
a00936a4:  90 10 00 10  mov  %l0, %o0
a00936a8:  92 10 20 00  clr  %o1
a00936ac:  94 10 21 2f  mov  0x12f, %o2
a00936b0:  10 80 00 0a  b  0xa00936d8
a00936b4:  96 10 20 02  mov  2, %o3
a00936b8:  92 10 20 00  clr  %o1
a00936bc:  94 10 21 24  mov  0x124, %o2
a00936c0:  40 00 52 65  call  0xa00a8054
a00936c4:  96 10 20 2b  mov  0x2b, %o3
a00936c8:  90 10 00 10  mov  %l0, %o0
a00936cc:  92 10 20 00  clr  %o1
a00936d0:  94 10 21 2f  mov  0x12f, %o2
a00936d4:  96 10 20 06  mov  6, %o3
a00936d8:  40 00 52 7d  call  0xa00a80cc
a00936dc:  98 10 20 00  clr  %o4
a00936e0:  90 10 00 11  mov  %l1, %o0
a00936e4:  7f ff ff 12  call  0xa009332c
a00936e8:  92 0d e0 ff  and  %l7, 0xff, %o1
a00936ec:  10 80 00 10  b  0xa009372c
a00936f0:  80 a6 60 0e  cmp  %i1, 0xe
a00936f4:  7f ff fe 9c  call  0xa0093164
a00936f8:  90 10 00 10  mov  %l0, %o0
a00936fc:  90 10 00 10  mov  %l0, %o0
a0093700:  92 10 20 00  clr  %o1
a0093704:  94 10 21 24  mov  0x124, %o2
a0093708:  40 00 52 53  call  0xa00a8054
a009370c:  96 10 20 2b  mov  0x2b, %o3
a0093710:  90 10 00 10  mov  %l0, %o0
a0093714:  92 10 20 00  clr  %o1
a0093718:  94 10 21 2f  mov  0x12f, %o2
a009371c:  96 10 20 06  mov  6, %o3
a0093720:  40 00 52 6b  call  0xa00a80cc
a0093724:  98 10 20 00  clr  %o4
a0093728:  80 a6 60 0e  cmp  %i1, 0xe
a009372c:  18 80 02 dd  bgu  0xa00942a0
a0093730:  82 10 20 01  mov  1, %g1
a0093734:  9b 28 40 19  sll  %g1, %i1, %o5
a0093738:  03 00 00 15  sethi  %hi(0x5400), %g1
a009373c:  82 10 61 00  or  %g1, 0x100, %g1	! 0x5500
a0093740:  80 8b 40 01  btst  %o5, %g1
a0093744:  12 80 00 07  bne  0xa0093760
a0093748:  80 a6 60 08  cmp  %i1, 8
a009374c:  80 8b 60 50  btst  0x50, %o5
a0093750:  12 80 01 f2  bne  0xa0093f18
a0093754:  80 a6 60 04  cmp  %i1, 4
a0093758:  10 80 02 d3  b  0xa00942a4
a009375c:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0093760:  12 80 00 09  bne  0xa0093784
a0093764:  80 a6 60 0a  cmp  %i1, 0xa
a0093768:  03 28 02 99  sethi  %hi(0xa00a6400), %g1
a009376c:  82 10 61 7c  or  %g1, 0x17c, %g1	! 0xa00a657c
a0093770:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0093774:  c2 23 61 b8  st  %g1, [ %o5 + 0x1b8 ]	! 0xa807d5b8
a0093778:  aa 10 20 00  clr  %l5
a009377c:  10 80 00 1c  b  0xa00937ec
a0093780:  ba 10 20 00  clr  %i5
a0093784:  12 80 00 09  bne  0xa00937a8
a0093788:  80 a6 60 0c  cmp  %i1, 0xc
a009378c:  03 28 02 99  sethi  %hi(0xa00a6400), %g1
a0093790:  82 10 61 7c  or  %g1, 0x17c, %g1	! 0xa00a657c
a0093794:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0093798:  c2 23 61 b8  st  %g1, [ %o5 + 0x1b8 ]	! 0xa807d5b8
a009379c:  aa 10 20 01  mov  1, %l5
a00937a0:  10 80 00 13  b  0xa00937ec
a00937a4:  ba 10 20 01  mov  1, %i5
a00937a8:  12 80 00 09  bne  0xa00937cc
a00937ac:  80 a6 60 0e  cmp  %i1, 0xe
a00937b0:  03 28 02 9a  sethi  %hi(0xa00a6800), %g1
a00937b4:  82 10 61 b4  or  %g1, 0x1b4, %g1	! 0xa00a69b4
a00937b8:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00937bc:  c2 23 61 b8  st  %g1, [ %o5 + 0x1b8 ]	! 0xa807d5b8
a00937c0:  aa 10 20 00  clr  %l5
a00937c4:  10 80 00 0a  b  0xa00937ec
a00937c8:  ba 10 20 02  mov  2, %i5
a00937cc:  12 80 00 09  bne  0xa00937f0
a00937d0:  ac 0d e0 ff  and  %l7, 0xff, %l6
a00937d4:  03 28 02 9a  sethi  %hi(0xa00a6800), %g1
a00937d8:  82 10 61 b4  or  %g1, 0x1b4, %g1	! 0xa00a69b4
a00937dc:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00937e0:  c2 23 61 b8  st  %g1, [ %o5 + 0x1b8 ]	! 0xa807d5b8
a00937e4:  aa 10 20 01  mov  1, %l5
a00937e8:  ba 10 20 03  mov  3, %i5
a00937ec:  ac 0d e0 ff  and  %l7, 0xff, %l6
a00937f0:  90 10 00 16  mov  %l6, %o0
a00937f4:  92 10 20 00  clr  %o1
a00937f8:  94 10 21 01  mov  0x101, %o2
a00937fc:  96 10 20 02  mov  2, %o3
a0093800:  40 00 52 33  call  0xa00a80cc
a0093804:  98 10 20 01  mov  1, %o4
a0093808:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a009380c:  a2 0d 60 ff  and  %l5, 0xff, %l1
a0093810:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a0093814:  90 10 00 11  mov  %l1, %o0
a0093818:  9f c0 40 00  call  %g1
a009381c:  92 10 21 00  mov  0x100, %o1
a0093820:  80 8a 20 08  btst  8, %o0
a0093824:  02 80 00 12  be  0xa009386c
a0093828:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a009382c:  92 10 21 05  mov  0x105, %o1
a0093830:  9f c0 40 00  call  %g1
a0093834:  90 10 00 11  mov  %l1, %o0
a0093838:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009383c:  92 10 21 04  mov  0x104, %o1
a0093840:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a0093844:  9f c0 40 00  call  %g1
a0093848:  90 10 00 11  mov  %l1, %o0
a009384c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093850:  91 2a 20 08  sll  %o0, 8, %o0
a0093854:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0093858:  a0 04 00 08  add  %l0, %o0, %l0
a009385c:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a0093860:  90 10 00 11  mov  %l1, %o0
a0093864:  10 80 00 11  b  0xa00938a8
a0093868:  92 10 21 03  mov  0x103, %o1
a009386c:  92 10 21 08  mov  0x108, %o1
a0093870:  9f c0 40 00  call  %g1
a0093874:  90 10 00 11  mov  %l1, %o0
a0093878:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009387c:  92 10 21 07  mov  0x107, %o1
a0093880:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a0093884:  9f c0 40 00  call  %g1
a0093888:  90 10 00 11  mov  %l1, %o0
a009388c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093890:  91 2a 20 08  sll  %o0, 8, %o0
a0093894:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0093898:  a0 04 00 08  add  %l0, %o0, %l0
a009389c:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a00938a0:  90 10 00 11  mov  %l1, %o0
a00938a4:  92 10 21 06  mov  0x106, %o1
a00938a8:  9f c0 40 00  call  %g1
a00938ac:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a00938b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00938b4:  a4 04 00 08  add  %l0, %o0, %l2
a00938b8:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a00938bc:  90 10 00 11  mov  %l1, %o0
a00938c0:  9f c0 40 00  call  %g1
a00938c4:  92 10 21 00  mov  0x100, %o1
a00938c8:  80 8a 20 10  btst  0x10, %o0
a00938cc:  02 80 00 12  be  0xa0093914
a00938d0:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a00938d4:  92 10 21 0b  mov  0x10b, %o1
a00938d8:  9f c0 40 00  call  %g1
a00938dc:  90 10 00 11  mov  %l1, %o0
a00938e0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00938e4:  92 10 21 0a  mov  0x10a, %o1
a00938e8:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a00938ec:  9f c0 40 00  call  %g1
a00938f0:  90 10 00 11  mov  %l1, %o0
a00938f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00938f8:  91 2a 20 08  sll  %o0, 8, %o0
a00938fc:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0093900:  a0 04 00 08  add  %l0, %o0, %l0
a0093904:  c2 04 e1 b8  ld  [ %l3 + 0x1b8 ], %g1
a0093908:  90 10 00 11  mov  %l1, %o0
a009390c:  10 80 00 11  b  0xa0093950
a0093910:  92 10 21 09  mov  0x109, %o1
a0093914:  92 10 21 0e  mov  0x10e, %o1
a0093918:  9f c0 40 00  call  %g1
a009391c:  90 10 00 11  mov  %l1, %o0
a0093920:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0093924:  92 10 21 0d  mov  0x10d, %o1
a0093928:  c2 05 21 b8  ld  [ %l4 + 0x1b8 ], %g1
a009392c:  9f c0 40 00  call  %g1
a0093930:  90 10 00 11  mov  %l1, %o0
a0093934:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093938:  91 2a 20 08  sll  %o0, 8, %o0
a009393c:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0093940:  a0 04 00 08  add  %l0, %o0, %l0
a0093944:  c2 05 21 b8  ld  [ %l4 + 0x1b8 ], %g1
a0093948:  90 10 00 11  mov  %l1, %o0
a009394c:  92 10 21 0c  mov  0x10c, %o1
a0093950:  9f c0 40 00  call  %g1
a0093954:  01 00 00 00  nop
a0093958:  90 0a 20 ff  and  %o0, 0xff, %o0
a009395c:  a0 04 00 08  add  %l0, %o0, %l0
a0093960:  80 a4 20 7c  cmp  %l0, 0x7c
a0093964:  28 80 00 02  bleu,a   0xa009396c
a0093968:  a0 10 20 7d  mov  0x7d, %l0
a009396c:  82 1e 60 0c  xor  %i1, 0xc, %g1
a0093970:  80 a0 00 01  cmp  %g0, %g1
a0093974:  9a 60 3f ff  subx  %g0, -1, %o5
a0093978:  82 1e 60 0e  xor  %i1, 0xe, %g1
a009397c:  80 a0 00 01  cmp  %g0, %g1
a0093980:  82 60 3f ff  subx  %g0, -1, %g1
a0093984:  80 93 40 01  orcc  %o5, %g1, %g0
a0093988:  02 80 00 cf  be  0xa0093cc4
a009398c:  82 1e 60 08  xor  %i1, 8, %g1
a0093990:  40 00 3c 08  call  0xa00a29b0
a0093994:  90 10 00 11  mov  %l1, %o0
a0093998:  90 0a 20 ff  and  %o0, 0xff, %o0
a009399c:  80 a2 20 01  cmp  %o0, 1
a00939a0:  12 80 00 c9  bne  0xa0093cc4
a00939a4:  82 1e 60 08  xor  %i1, 8, %g1
a00939a8:  7f ff 7f 10  call  0xa00735e8
a00939ac:  90 0f 60 03  and  %i5, 3, %o0
a00939b0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00939b4:  80 a0 60 06  cmp  %g1, 6
a00939b8:  38 80 00 02  bgu,a   0xa00939c0
a00939bc:  90 10 20 06  mov  6, %o0
a00939c0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00939c4:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a00939c8:  9a 03 40 0d  add  %o5, %o5, %o5
a00939cc:  82 10 60 7c  or  %g1, 0x7c, %g1
a00939d0:  d8 10 40 0d  lduh  [ %g1 + %o5 ], %o4
a00939d4:  1b 04 18 93  sethi  %hi(0x10624c00), %o5
a00939d8:  9a 13 61 d3  or  %o5, 0x1d3, %o5	! 0x10624dd3
a00939dc:  80 54 00 0d  umul  %l0, %o5, %g0
a00939e0:  9b 40 00 00  rd  %y, %o5
a00939e4:  83 34 a0 07  srl  %l2, 7, %g1
a00939e8:  82 58 40 0c  smul  %g1, %o4, %g1
a00939ec:  9b 33 60 03  srl  %o5, 3, %o5
a00939f0:  81 80 00 00  mov  %g0, %y
a00939f4:  01 00 00 00  nop
a00939f8:  01 00 00 00  nop
a00939fc:  01 00 00 00  nop
a0093a00:  82 70 40 0d  udiv  %g1, %o5, %g1
a0093a04:  83 28 60 13  sll  %g1, 0x13, %g1
a0093a08:  91 30 60 10  srl  %g1, 0x10, %o0
a0093a0c:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0093a10:  98 10 60 8a  or  %g1, 0x8a, %o4	! 0xa00b408a
a0093a14:  9a 10 20 00  clr  %o5
a0093a18:  82 0b 60 ff  and  %o5, 0xff, %g1
a0093a1c:  82 00 40 01  add  %g1, %g1, %g1
a0093a20:  c2 13 00 01  lduh  [ %o4 + %g1 ], %g1
a0093a24:  82 22 00 01  sub  %o0, %g1, %g1
a0093a28:  82 00 60 08  add  %g1, 8, %g1
a0093a2c:  80 a0 60 10  cmp  %g1, 0x10
a0093a30:  08 80 00 08  bleu  0xa0093a50
a0093a34:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0093a38:  9a 03 60 01  inc  %o5
a0093a3c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0093a40:  80 a0 60 11  cmp  %g1, 0x11
a0093a44:  08 bf ff f7  bleu  0xa0093a20
a0093a48:  82 00 40 01  add  %g1, %g1, %g1
a0093a4c:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0093a50:  a2 0b 60 ff  and  %o5, 0xff, %l1
a0093a54:  82 10 62 ab  or  %g1, 0x2ab, %g1
a0093a58:  80 54 40 01  umul  %l1, %g1, %g0
a0093a5c:  83 40 00 00  rd  %y, %g1
a0093a60:  a1 30 60 02  srl  %g1, 2, %l0
a0093a64:  82 0c 20 ff  and  %l0, 0xff, %g1
a0093a68:  80 a0 60 01  cmp  %g1, 1
a0093a6c:  02 80 00 3d  be  0xa0093b60
a0093a70:  80 a0 60 02  cmp  %g1, 2
a0093a74:  02 80 00 54  be  0xa0093bc4
a0093a78:  01 00 00 00  nop
a0093a7c:  7f ff f7 b0  call  0xa009193c
a0093a80:  90 10 00 16  mov  %l6, %o0
a0093a84:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093a88:  80 a2 20 05  cmp  %o0, 5
a0093a8c:  02 80 00 25  be  0xa0093b20
a0093a90:  82 04 00 10  add  %l0, %l0, %g1
a0093a94:  14 80 00 07  bg  0xa0093ab0
a0093a98:  80 a2 20 06  cmp  %o0, 6
a0093a9c:  80 a2 20 02  cmp  %o0, 2
a0093aa0:  06 80 00 07  bl  0xa0093abc
a0093aa4:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0093aa8:  10 80 00 12  b  0xa0093af0
a0093aac:  82 10 62 ab  or  %g1, 0x2ab, %g1	! 0xaaaaaaab
a0093ab0:  22 80 00 24  be,a   0xa0093b40
a0093ab4:  82 04 00 10  add  %l0, %l0, %g1
a0093ab8:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0093abc:  82 10 62 ab  or  %g1, 0x2ab, %g1	! 0xaaaaaaab
a0093ac0:  80 54 40 01  umul  %l1, %g1, %g0
a0093ac4:  83 40 00 00  rd  %y, %g1
a0093ac8:  83 30 60 02  srl  %g1, 2, %g1
a0093acc:  9a 00 40 01  add  %g1, %g1, %o5
a0093ad0:  9a 03 40 01  add  %o5, %g1, %o5
a0093ad4:  9a 03 40 0d  add  %o5, %o5, %o5
a0093ad8:  9a 24 40 0d  sub  %l1, %o5, %o5
a0093adc:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0093ae0:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0093ae4:  9b 2b 60 02  sll  %o5, 2, %o5
a0093ae8:  10 80 00 52  b  0xa0093c30
a0093aec:  82 10 60 b0  or  %g1, 0xb0, %g1
a0093af0:  80 54 40 01  umul  %l1, %g1, %g0
a0093af4:  83 40 00 00  rd  %y, %g1
a0093af8:  83 30 60 02  srl  %g1, 2, %g1
a0093afc:  9a 00 40 01  add  %g1, %g1, %o5
a0093b00:  9a 03 40 01  add  %o5, %g1, %o5
a0093b04:  9a 03 40 0d  add  %o5, %o5, %o5
a0093b08:  9a 24 40 0d  sub  %l1, %o5, %o5
a0093b0c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0093b10:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0093b14:  9b 2b 60 02  sll  %o5, 2, %o5
a0093b18:  10 80 00 53  b  0xa0093c64
a0093b1c:  82 10 60 b0  or  %g1, 0xb0, %g1
a0093b20:  82 00 40 10  add  %g1, %l0, %g1
a0093b24:  82 00 40 01  add  %g1, %g1, %g1
a0093b28:  82 24 40 01  sub  %l1, %g1, %g1
a0093b2c:  82 08 60 ff  and  %g1, 0xff, %g1
a0093b30:  1b 28 02 d0  sethi  %hi(0xa00b4000), %o5
a0093b34:  83 28 60 02  sll  %g1, 2, %g1
a0093b38:  10 80 00 55  b  0xa0093c8c
a0093b3c:  9a 13 60 b0  or  %o5, 0xb0, %o5
a0093b40:  82 00 40 10  add  %g1, %l0, %g1
a0093b44:  82 00 40 01  add  %g1, %g1, %g1
a0093b48:  82 24 40 01  sub  %l1, %g1, %g1
a0093b4c:  82 08 60 ff  and  %g1, 0xff, %g1
a0093b50:  1b 28 02 d0  sethi  %hi(0xa00b4000), %o5
a0093b54:  83 28 60 02  sll  %g1, 2, %g1
a0093b58:  10 80 00 58  b  0xa0093cb8
a0093b5c:  9a 13 60 b0  or  %o5, 0xb0, %o5
a0093b60:  7f ff f7 77  call  0xa009193c
a0093b64:  90 10 00 16  mov  %l6, %o0
a0093b68:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093b6c:  90 02 3f fc  add  %o0, -4, %o0
a0093b70:  80 a2 20 02  cmp  %o0, 2
a0093b74:  82 04 00 10  add  %l0, %l0, %g1
a0093b78:  08 80 00 0a  bleu  0xa0093ba0
a0093b7c:  1b 28 02 d0  sethi  %hi(0xa00b4000), %o5
a0093b80:  82 00 40 10  add  %g1, %l0, %g1
a0093b84:  82 00 40 01  add  %g1, %g1, %g1
a0093b88:  82 24 40 01  sub  %l1, %g1, %g1
a0093b8c:  82 08 60 ff  and  %g1, 0xff, %g1
a0093b90:  9a 13 61 10  or  %o5, 0x110, %o5
a0093b94:  83 28 60 02  sll  %g1, 2, %g1
a0093b98:  10 80 00 ce  b  0xa0093ed0
a0093b9c:  e4 03 40 01  ld  [ %o5 + %g1 ], %l2
a0093ba0:  82 00 40 10  add  %g1, %l0, %g1
a0093ba4:  82 00 40 01  add  %g1, %g1, %g1
a0093ba8:  82 24 40 01  sub  %l1, %g1, %g1
a0093bac:  82 08 60 ff  and  %g1, 0xff, %g1
a0093bb0:  9a 13 61 10  or  %o5, 0x110, %o5
a0093bb4:  83 28 60 02  sll  %g1, 2, %g1
a0093bb8:  82 00 40 0d  add  %g1, %o5, %g1
a0093bbc:  10 80 00 c5  b  0xa0093ed0
a0093bc0:  e4 00 60 18  ld  [ %g1 + 0x18 ], %l2
a0093bc4:  7f ff f7 5e  call  0xa009193c
a0093bc8:  90 10 00 16  mov  %l6, %o0
a0093bcc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093bd0:  80 a2 20 05  cmp  %o0, 5
a0093bd4:  02 80 00 27  be  0xa0093c70
a0093bd8:  82 04 00 10  add  %l0, %l0, %g1
a0093bdc:  14 80 00 07  bg  0xa0093bf8
a0093be0:  80 a2 20 06  cmp  %o0, 6
a0093be4:  80 a2 20 02  cmp  %o0, 2
a0093be8:  06 80 00 06  bl  0xa0093c00
a0093bec:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0093bf0:  10 80 00 12  b  0xa0093c38
a0093bf4:  82 10 62 ab  or  %g1, 0x2ab, %g1	! 0xaaaaaaab
a0093bf8:  02 80 00 28  be  0xa0093c98
a0093bfc:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0093c00:  82 10 62 ab  or  %g1, 0x2ab, %g1	! 0xaaaaaaab
a0093c04:  80 54 40 01  umul  %l1, %g1, %g0
a0093c08:  83 40 00 00  rd  %y, %g1
a0093c0c:  83 30 60 02  srl  %g1, 2, %g1
a0093c10:  9a 00 40 01  add  %g1, %g1, %o5
a0093c14:  9a 03 40 01  add  %o5, %g1, %o5
a0093c18:  9a 03 40 0d  add  %o5, %o5, %o5
a0093c1c:  9a 24 40 0d  sub  %l1, %o5, %o5
a0093c20:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0093c24:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0093c28:  9b 2b 60 02  sll  %o5, 2, %o5
a0093c2c:  82 10 61 40  or  %g1, 0x140, %g1
a0093c30:  10 80 00 a8  b  0xa0093ed0
a0093c34:  e4 00 40 0d  ld  [ %g1 + %o5 ], %l2
a0093c38:  80 54 40 01  umul  %l1, %g1, %g0
a0093c3c:  83 40 00 00  rd  %y, %g1
a0093c40:  83 30 60 02  srl  %g1, 2, %g1
a0093c44:  9a 00 40 01  add  %g1, %g1, %o5
a0093c48:  9a 03 40 01  add  %o5, %g1, %o5
a0093c4c:  9a 03 40 0d  add  %o5, %o5, %o5
a0093c50:  9a 24 40 0d  sub  %l1, %o5, %o5
a0093c54:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0093c58:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0093c5c:  9b 2b 60 02  sll  %o5, 2, %o5
a0093c60:  82 10 61 40  or  %g1, 0x140, %g1
a0093c64:  9a 03 40 01  add  %o5, %g1, %o5
a0093c68:  10 80 00 9a  b  0xa0093ed0
a0093c6c:  e4 03 60 18  ld  [ %o5 + 0x18 ], %l2
a0093c70:  82 00 40 10  add  %g1, %l0, %g1
a0093c74:  82 00 40 01  add  %g1, %g1, %g1
a0093c78:  82 24 40 01  sub  %l1, %g1, %g1
a0093c7c:  82 08 60 ff  and  %g1, 0xff, %g1
a0093c80:  1b 28 02 d0  sethi  %hi(0xa00b4000), %o5
a0093c84:  83 28 60 02  sll  %g1, 2, %g1
a0093c88:  9a 13 61 40  or  %o5, 0x140, %o5
a0093c8c:  82 00 40 0d  add  %g1, %o5, %g1
a0093c90:  10 80 00 90  b  0xa0093ed0
a0093c94:  e4 00 60 30  ld  [ %g1 + 0x30 ], %l2
a0093c98:  82 04 00 10  add  %l0, %l0, %g1
a0093c9c:  82 00 40 10  add  %g1, %l0, %g1
a0093ca0:  82 00 40 01  add  %g1, %g1, %g1
a0093ca4:  82 24 40 01  sub  %l1, %g1, %g1
a0093ca8:  82 08 60 ff  and  %g1, 0xff, %g1
a0093cac:  1b 28 02 d0  sethi  %hi(0xa00b4000), %o5
a0093cb0:  83 28 60 02  sll  %g1, 2, %g1
a0093cb4:  9a 13 61 40  or  %o5, 0x140, %o5
a0093cb8:  82 00 40 0d  add  %g1, %o5, %g1
a0093cbc:  10 80 00 85  b  0xa0093ed0
a0093cc0:  e4 00 60 48  ld  [ %g1 + 0x48 ], %l2
a0093cc4:  80 a0 00 01  cmp  %g0, %g1
a0093cc8:  9a 60 3f ff  subx  %g0, -1, %o5
a0093ccc:  82 1e 60 0a  xor  %i1, 0xa, %g1
a0093cd0:  80 a0 00 01  cmp  %g0, %g1
a0093cd4:  82 60 3f ff  subx  %g0, -1, %g1
a0093cd8:  80 93 40 01  orcc  %o5, %g1, %g0
a0093cdc:  90 0d 60 ff  and  %l5, 0xff, %o0
a0093ce0:  02 80 00 16  be  0xa0093d38
a0093ce4:  a3 34 a0 07  srl  %l2, 7, %l1
a0093ce8:  7f ff f4 b3  call  0xa0090fb4
a0093cec:  01 00 00 00  nop
a0093cf0:  91 2a 20 10  sll  %o0, 0x10, %o0
a0093cf4:  91 32 20 10  srl  %o0, 0x10, %o0
a0093cf8:  90 5c 40 08  smul  %l1, %o0, %o0
a0093cfc:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a0093d00:  9b 2a 20 02  sll  %o0, 2, %o5
a0093d04:  82 10 61 d3  or  %g1, 0x1d3, %g1
a0093d08:  9a 03 40 08  add  %o5, %o0, %o5
a0093d0c:  80 54 00 01  umul  %l0, %g1, %g0
a0093d10:  83 40 00 00  rd  %y, %g1
a0093d14:  9a 03 40 0d  add  %o5, %o5, %o5
a0093d18:  83 30 60 03  srl  %g1, 3, %g1
a0093d1c:  81 80 00 00  mov  %g0, %y
a0093d20:  01 00 00 00  nop
a0093d24:  01 00 00 00  nop
a0093d28:  01 00 00 00  nop
a0093d2c:  9a 73 40 01  udiv  %o5, %g1, %o5
a0093d30:  10 80 00 12  b  0xa0093d78
a0093d34:  91 2b 60 03  sll  %o5, 3, %o0
a0093d38:  40 00 38 e3  call  0xa00a20c4
a0093d3c:  01 00 00 00  nop
a0093d40:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a0093d44:  91 2a 20 10  sll  %o0, 0x10, %o0
a0093d48:  82 10 61 d3  or  %g1, 0x1d3, %g1
a0093d4c:  80 54 00 01  umul  %l0, %g1, %g0
a0093d50:  83 40 00 00  rd  %y, %g1
a0093d54:  91 32 20 10  srl  %o0, 0x10, %o0
a0093d58:  90 5c 40 08  smul  %l1, %o0, %o0
a0093d5c:  83 30 60 03  srl  %g1, 3, %g1
a0093d60:  81 80 00 00  mov  %g0, %y
a0093d64:  01 00 00 00  nop
a0093d68:  01 00 00 00  nop
a0093d6c:  01 00 00 00  nop
a0093d70:  90 72 00 01  udiv  %o0, %g1, %o0
a0093d74:  91 2a 20 03  sll  %o0, 3, %o0
a0093d78:  82 02 3e c8  add  %o0, -312, %g1
a0093d7c:  83 28 60 10  sll  %g1, 0x10, %g1
a0093d80:  83 30 60 10  srl  %g1, 0x10, %g1
a0093d84:  80 a0 60 10  cmp  %g1, 0x10
a0093d88:  18 80 00 04  bgu  0xa0093d98
a0093d8c:  82 02 3d 88  add  %o0, -632, %g1
a0093d90:  10 80 00 50  b  0xa0093ed0
a0093d94:  25 00 00 04  sethi  %hi(0x1000), %l2
a0093d98:  83 28 60 10  sll  %g1, 0x10, %g1
a0093d9c:  83 30 60 10  srl  %g1, 0x10, %g1
a0093da0:  80 a0 60 10  cmp  %g1, 0x10
a0093da4:  18 80 00 04  bgu  0xa0093db4
a0093da8:  82 02 3b 08  add  %o0, -1272, %g1
a0093dac:  10 80 00 49  b  0xa0093ed0
a0093db0:  25 00 00 08  sethi  %hi(0x2000), %l2
a0093db4:  83 28 60 10  sll  %g1, 0x10, %g1
a0093db8:  83 30 60 10  srl  %g1, 0x10, %g1
a0093dbc:  80 a0 60 10  cmp  %g1, 0x10
a0093dc0:  18 80 00 04  bgu  0xa0093dd0
a0093dc4:  82 02 36 08  add  %o0, -2552, %g1
a0093dc8:  10 80 00 42  b  0xa0093ed0
a0093dcc:  25 00 00 10  sethi  %hi(0x4000), %l2
a0093dd0:  83 28 60 10  sll  %g1, 0x10, %g1
a0093dd4:  83 30 60 10  srl  %g1, 0x10, %g1
a0093dd8:  80 a0 60 10  cmp  %g1, 0x10
a0093ddc:  18 80 00 04  bgu  0xa0093dec
a0093de0:  82 02 3e 4f  add  %o0, -433, %g1
a0093de4:  10 80 00 3b  b  0xa0093ed0
a0093de8:  25 00 00 20  sethi  %hi(0x8000), %l2
a0093dec:  83 28 60 10  sll  %g1, 0x10, %g1
a0093df0:  83 30 60 10  srl  %g1, 0x10, %g1
a0093df4:  80 a0 60 10  cmp  %g1, 0x10
a0093df8:  18 80 00 05  bgu  0xa0093e0c
a0093dfc:  82 02 3c 96  add  %o0, -874, %g1
a0093e00:  03 00 00 06  sethi  %hi(0x1800), %g1
a0093e04:  10 80 00 33  b  0xa0093ed0
a0093e08:  a4 10 60 80  or  %g1, 0x80, %l2	! 0x1880
a0093e0c:  83 28 60 10  sll  %g1, 0x10, %g1
a0093e10:  83 30 60 10  srl  %g1, 0x10, %g1
a0093e14:  80 a0 60 10  cmp  %g1, 0x10
a0093e18:  18 80 00 05  bgu  0xa0093e2c
a0093e1c:  82 02 39 24  add  %o0, -1756, %g1
a0093e20:  03 00 00 0c  sethi  %hi(0x3000), %g1
a0093e24:  10 80 00 2b  b  0xa0093ed0
a0093e28:  a4 10 61 00  or  %g1, 0x100, %l2	! 0x3100
a0093e2c:  83 28 60 10  sll  %g1, 0x10, %g1
a0093e30:  83 30 60 10  srl  %g1, 0x10, %g1
a0093e34:  80 a0 60 10  cmp  %g1, 0x10
a0093e38:  18 80 00 05  bgu  0xa0093e4c
a0093e3c:  82 02 32 40  add  %o0, -3520, %g1
a0093e40:  03 00 00 18  sethi  %hi(0x6000), %g1
a0093e44:  10 80 00 23  b  0xa0093ed0
a0093e48:  a4 10 62 00  or  %g1, 0x200, %l2	! 0x6200
a0093e4c:  83 28 60 10  sll  %g1, 0x10, %g1
a0093e50:  83 30 60 10  srl  %g1, 0x10, %g1
a0093e54:  80 a0 60 10  cmp  %g1, 0x10
a0093e58:  18 80 00 04  bgu  0xa0093e68
a0093e5c:  82 02 3e 28  add  %o0, -472, %g1
a0093e60:  10 80 00 1c  b  0xa0093ed0
a0093e64:  25 00 00 31  sethi  %hi(0xc400), %l2
a0093e68:  83 28 60 10  sll  %g1, 0x10, %g1
a0093e6c:  83 30 60 10  srl  %g1, 0x10, %g1
a0093e70:  80 a0 60 10  cmp  %g1, 0x10
a0093e74:  18 80 00 04  bgu  0xa0093e84
a0093e78:  82 02 3c 48  add  %o0, -952, %g1
a0093e7c:  10 80 00 15  b  0xa0093ed0
a0093e80:  25 00 00 06  sethi  %hi(0x1800), %l2
a0093e84:  83 28 60 10  sll  %g1, 0x10, %g1
a0093e88:  83 30 60 10  srl  %g1, 0x10, %g1
a0093e8c:  80 a0 60 10  cmp  %g1, 0x10
a0093e90:  18 80 00 04  bgu  0xa0093ea0
a0093e94:  82 02 38 88  add  %o0, -1912, %g1
a0093e98:  10 80 00 0e  b  0xa0093ed0
a0093e9c:  25 00 00 0c  sethi  %hi(0x3000), %l2
a0093ea0:  83 28 60 10  sll  %g1, 0x10, %g1
a0093ea4:  83 30 60 10  srl  %g1, 0x10, %g1
a0093ea8:  80 a0 60 10  cmp  %g1, 0x10
a0093eac:  18 80 00 04  bgu  0xa0093ebc
a0093eb0:  82 02 31 08  add  %o0, -3832, %g1
a0093eb4:  10 80 00 07  b  0xa0093ed0
a0093eb8:  25 00 00 18  sethi  %hi(0x6000), %l2
a0093ebc:  83 28 60 10  sll  %g1, 0x10, %g1
a0093ec0:  83 30 60 10  srl  %g1, 0x10, %g1
a0093ec4:  80 a0 60 10  cmp  %g1, 0x10
a0093ec8:  28 80 00 02  bleu,a   0xa0093ed0
a0093ecc:  25 00 00 30  sethi  %hi(0xc000), %l2
a0093ed0:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0093ed4:  97 34 a0 10  srl  %l2, 0x10, %o3
a0093ed8:  96 0a e0 ff  and  %o3, 0xff, %o3
a0093edc:  90 10 00 10  mov  %l0, %o0
a0093ee0:  92 10 20 00  clr  %o1
a0093ee4:  40 00 50 5c  call  0xa00a8054
a0093ee8:  94 10 21 05  mov  0x105, %o2
a0093eec:  97 34 a0 08  srl  %l2, 8, %o3
a0093ef0:  96 0a e0 ff  and  %o3, 0xff, %o3
a0093ef4:  90 10 00 10  mov  %l0, %o0
a0093ef8:  92 10 20 00  clr  %o1
a0093efc:  40 00 50 56  call  0xa00a8054
a0093f00:  94 10 21 04  mov  0x104, %o2
a0093f04:  90 10 00 10  mov  %l0, %o0
a0093f08:  96 0c a0 ff  and  %l2, 0xff, %o3
a0093f0c:  92 10 20 00  clr  %o1
a0093f10:  10 80 00 f9  b  0xa00942f4
a0093f14:  94 10 21 03  mov  0x103, %o2
a0093f18:  12 80 00 04  bne  0xa0093f28
a0093f1c:  80 a6 60 06  cmp  %i1, 6
a0093f20:  10 80 00 04  b  0xa0093f30
a0093f24:  aa 10 20 00  clr  %l5
a0093f28:  22 80 00 02  be,a   0xa0093f30
a0093f2c:  aa 10 20 01  mov  1, %l5
a0093f30:  a8 0d e0 ff  and  %l7, 0xff, %l4
a0093f34:  96 10 20 02  mov  2, %o3
a0093f38:  98 10 20 01  mov  1, %o4
a0093f3c:  94 10 21 01  mov  0x101, %o2
a0093f40:  90 10 00 14  mov  %l4, %o0
a0093f44:  40 00 50 62  call  0xa00a80cc
a0093f48:  92 10 20 00  clr  %o1
a0093f4c:  a2 0d 60 ff  and  %l5, 0xff, %l1
a0093f50:  92 10 20 81  mov  0x81, %o1
a0093f54:  40 00 4b 19  call  0xa00a6bb8
a0093f58:  90 10 00 11  mov  %l1, %o0
a0093f5c:  a0 10 00 08  mov  %o0, %l0
a0093f60:  aa 0a 20 ff  and  %o0, 0xff, %l5
a0093f64:  94 0d 60 df  and  %l5, 0xdf, %o2
a0093f68:  90 10 00 11  mov  %l1, %o0
a0093f6c:  40 00 4b 25  call  0xa00a6c00
a0093f70:  92 10 20 81  mov  0x81, %o1
a0093f74:  92 10 20 82  mov  0x82, %o1
a0093f78:  40 00 4b 10  call  0xa00a6bb8
a0093f7c:  90 10 00 11  mov  %l1, %o0
a0093f80:  a6 0a 20 ff  and  %o0, 0xff, %l3
a0093f84:  92 10 20 83  mov  0x83, %o1
a0093f88:  40 00 4b 0c  call  0xa00a6bb8
a0093f8c:  90 10 00 11  mov  %l1, %o0
a0093f90:  83 2c e0 08  sll  %l3, 8, %g1
a0093f94:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093f98:  a6 10 40 08  or  %g1, %o0, %l3
a0093f9c:  92 10 20 84  mov  0x84, %o1
a0093fa0:  40 00 4b 06  call  0xa00a6bb8
a0093fa4:  90 10 00 11  mov  %l1, %o0
a0093fa8:  83 2c e0 08  sll  %l3, 8, %g1
a0093fac:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093fb0:  a6 10 40 08  or  %g1, %o0, %l3
a0093fb4:  92 10 20 85  mov  0x85, %o1
a0093fb8:  40 00 4b 00  call  0xa00a6bb8
a0093fbc:  90 10 00 11  mov  %l1, %o0
a0093fc0:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0093fc4:  92 10 20 86  mov  0x86, %o1
a0093fc8:  40 00 4a fc  call  0xa00a6bb8
a0093fcc:  90 10 00 11  mov  %l1, %o0
a0093fd0:  83 2e 60 08  sll  %i1, 8, %g1
a0093fd4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093fd8:  b2 10 40 08  or  %g1, %o0, %i1
a0093fdc:  92 10 20 87  mov  0x87, %o1
a0093fe0:  40 00 4a f6  call  0xa00a6bb8
a0093fe4:  90 10 00 11  mov  %l1, %o0
a0093fe8:  83 2e 60 08  sll  %i1, 8, %g1
a0093fec:  90 0a 20 ff  and  %o0, 0xff, %o0
a0093ff0:  b2 10 40 08  or  %g1, %o0, %i1
a0093ff4:  a0 14 20 20  or  %l0, 0x20, %l0
a0093ff8:  94 0c 20 ff  and  %l0, 0xff, %o2
a0093ffc:  90 10 00 11  mov  %l1, %o0
a0094000:  40 00 4b 00  call  0xa00a6c00
a0094004:  92 10 20 81  mov  0x81, %o1
a0094008:  92 10 20 82  mov  0x82, %o1
a009400c:  40 00 4a eb  call  0xa00a6bb8
a0094010:  90 10 00 11  mov  %l1, %o0
a0094014:  a4 0a 20 ff  and  %o0, 0xff, %l2
a0094018:  92 10 20 83  mov  0x83, %o1
a009401c:  40 00 4a e7  call  0xa00a6bb8
a0094020:  90 10 00 11  mov  %l1, %o0
a0094024:  83 2c a0 08  sll  %l2, 8, %g1
a0094028:  90 0a 20 ff  and  %o0, 0xff, %o0
a009402c:  a4 10 40 08  or  %g1, %o0, %l2
a0094030:  92 10 20 84  mov  0x84, %o1
a0094034:  40 00 4a e1  call  0xa00a6bb8
a0094038:  90 10 00 11  mov  %l1, %o0
a009403c:  83 2c a0 08  sll  %l2, 8, %g1
a0094040:  90 0a 20 ff  and  %o0, 0xff, %o0
a0094044:  a4 10 40 08  or  %g1, %o0, %l2
a0094048:  92 10 20 85  mov  0x85, %o1
a009404c:  40 00 4a db  call  0xa00a6bb8
a0094050:  90 10 00 11  mov  %l1, %o0
a0094054:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0094058:  92 10 20 86  mov  0x86, %o1
a009405c:  40 00 4a d7  call  0xa00a6bb8
a0094060:  90 10 00 11  mov  %l1, %o0
a0094064:  83 2c 20 08  sll  %l0, 8, %g1
a0094068:  90 0a 20 ff  and  %o0, 0xff, %o0
a009406c:  a0 10 40 08  or  %g1, %o0, %l0
a0094070:  90 10 00 11  mov  %l1, %o0
a0094074:  40 00 4a d1  call  0xa00a6bb8
a0094078:  92 10 20 87  mov  0x87, %o1
a009407c:  80 a0 00 19  cmp  %g0, %i1
a0094080:  83 2c 20 08  sll  %l0, 8, %g1
a0094084:  90 0a 20 ff  and  %o0, 0xff, %o0
a0094088:  a0 10 40 08  or  %g1, %o0, %l0
a009408c:  9a 60 3f ff  subx  %g0, -1, %o5
a0094090:  80 a0 00 10  cmp  %g0, %l0
a0094094:  82 60 3f ff  subx  %g0, -1, %g1
a0094098:  80 93 40 01  orcc  %o5, %g1, %g0
a009409c:  12 80 00 98  bne  0xa00942fc
a00940a0:  b0 10 20 01  mov  1, %i0
a00940a4:  90 10 00 11  mov  %l1, %o0
a00940a8:  40 00 4a c4  call  0xa00a6bb8
a00940ac:  92 10 20 80  mov  0x80, %o1
a00940b0:  80 8a 20 03  btst  3, %o0
a00940b4:  12 80 00 06  bne  0xa00940cc
a00940b8:  03 00 06 2e  sethi  %hi(0x18b800), %g1
a00940bc:  82 10 60 20  or  %g1, 0x20, %g1	! 0x18b820
a00940c0:  82 5c 80 01  smul  %l2, %g1, %g1
a00940c4:  10 80 00 0d  b  0xa00940f8
a00940c8:  9a 5c e6 54  smul  %l3, 0x654, %o5
a00940cc:  90 10 00 11  mov  %l1, %o0
a00940d0:  40 00 4a ba  call  0xa00a6bb8
a00940d4:  92 10 20 80  mov  0x80, %o1
a00940d8:  90 0a 20 03  and  %o0, 3, %o0
a00940dc:  80 a2 20 01  cmp  %o0, 1
a00940e0:  12 80 00 13  bne  0xa009412c
a00940e4:  1b 00 14 99  sethi  %hi(0x526400), %o5
a00940e8:  03 00 0a 4c  sethi  %hi(0x293000), %g1
a00940ec:  82 10 62 e0  or  %g1, 0x2e0, %g1	! 0x2932e0
a00940f0:  82 5c 80 01  smul  %l2, %g1, %g1
a00940f4:  9a 5c ea 8c  smul  %l3, 0xa8c, %o5
a00940f8:  81 80 00 00  mov  %g0, %y
a00940fc:  01 00 00 00  nop
a0094100:  01 00 00 00  nop
a0094104:  01 00 00 00  nop
a0094108:  9a 73 40 19  udiv  %o5, %i1, %o5
a009410c:  83 30 60 09  srl  %g1, 9, %g1
a0094110:  81 80 00 00  mov  %g0, %y
a0094114:  01 00 00 00  nop
a0094118:  01 00 00 00  nop
a009411c:  01 00 00 00  nop
a0094120:  b2 70 40 10  udiv  %g1, %l0, %i1
a0094124:  10 80 00 13  b  0xa0094170
a0094128:  a0 03 40 0d  add  %o5, %o5, %l0
a009412c:  03 00 00 05  sethi  %hi(0x1400), %g1
a0094130:  9a 13 61 c0  or  %o5, 0x1c0, %o5
a0094134:  82 10 61 18  or  %g1, 0x118, %g1
a0094138:  9a 5c 80 0d  smul  %l2, %o5, %o5
a009413c:  82 5c c0 01  smul  %l3, %g1, %g1
a0094140:  81 80 00 00  mov  %g0, %y
a0094144:  01 00 00 00  nop
a0094148:  01 00 00 00  nop
a009414c:  01 00 00 00  nop
a0094150:  82 70 40 19  udiv  %g1, %i1, %g1
a0094154:  9b 33 60 09  srl  %o5, 9, %o5
a0094158:  81 80 00 00  mov  %g0, %y
a009415c:  01 00 00 00  nop
a0094160:  01 00 00 00  nop
a0094164:  01 00 00 00  nop
a0094168:  b2 73 40 10  udiv  %o5, %l0, %i1
a009416c:  a0 00 40 01  add  %g1, %g1, %l0
a0094170:  90 10 00 11  mov  %l1, %o0
a0094174:  94 10 00 15  mov  %l5, %o2
a0094178:  40 00 4a a2  call  0xa00a6c00
a009417c:  92 10 20 81  mov  0x81, %o1
a0094180:  82 06 7e 4c  add  %i1, -436, %g1
a0094184:  80 a0 60 0a  cmp  %g1, 0xa
a0094188:  08 80 00 07  bleu  0xa00941a4
a009418c:  82 10 20 00  clr  %g1
a0094190:  82 06 7e 25  add  %i1, -475, %g1
a0094194:  80 a0 60 0a  cmp  %g1, 0xa
a0094198:  08 80 00 03  bleu  0xa00941a4
a009419c:  82 10 20 02  mov  2, %g1
a00941a0:  82 10 20 01  mov  1, %g1
a00941a4:  80 a4 21 04  cmp  %l0, 0x104
a00941a8:  04 80 00 0f  ble  0xa00941e4
a00941ac:  9a 10 20 00  clr  %o5
a00941b0:  80 a4 21 95  cmp  %l0, 0x195
a00941b4:  04 80 00 0c  ble  0xa00941e4
a00941b8:  9a 10 20 01  mov  1, %o5
a00941bc:  80 a4 22 80  cmp  %l0, 0x280
a00941c0:  04 80 00 09  ble  0xa00941e4
a00941c4:  9a 10 20 02  mov  2, %o5
a00941c8:  80 a4 24 56  cmp  %l0, 0x456
a00941cc:  04 80 00 06  ble  0xa00941e4
a00941d0:  9a 10 20 03  mov  3, %o5
a00941d4:  80 a4 28 b1  cmp  %l0, 0x8b1
a00941d8:  04 80 00 03  ble  0xa00941e4
a00941dc:  9a 10 20 04  mov  4, %o5
a00941e0:  9a 10 20 05  mov  5, %o5
a00941e4:  82 08 60 ff  and  %g1, 0xff, %g1
a00941e8:  a0 00 40 01  add  %g1, %g1, %l0
a00941ec:  a0 04 00 01  add  %l0, %g1, %l0
a00941f0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00941f4:  a0 04 00 10  add  %l0, %l0, %l0
a00941f8:  a0 04 00 01  add  %l0, %g1, %l0
a00941fc:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0094200:  82 10 61 a0  or  %g1, 0x1a0, %g1	! 0xa00b41a0
a0094204:  a1 2c 20 02  sll  %l0, 2, %l0
a0094208:  e2 00 40 10  ld  [ %g1 + %l0 ], %l1
a009420c:  96 0c 60 ff  and  %l1, 0xff, %o3
a0094210:  90 10 00 14  mov  %l4, %o0
a0094214:  92 10 20 00  clr  %o1
a0094218:  40 00 4f 8f  call  0xa00a8054
a009421c:  94 10 21 03  mov  0x103, %o2
a0094220:  97 34 60 08  srl  %l1, 8, %o3
a0094224:  96 0a e0 ff  and  %o3, 0xff, %o3
a0094228:  90 10 00 14  mov  %l4, %o0
a009422c:  92 10 20 00  clr  %o1
a0094230:  40 00 4f 89  call  0xa00a8054
a0094234:  94 10 21 04  mov  0x104, %o2
a0094238:  a3 34 60 10  srl  %l1, 0x10, %l1
a009423c:  96 0c 60 ff  and  %l1, 0xff, %o3
a0094240:  90 10 00 14  mov  %l4, %o0
a0094244:  92 10 20 00  clr  %o1
a0094248:  40 00 4f 83  call  0xa00a8054
a009424c:  94 10 21 05  mov  0x105, %o2
a0094250:  03 28 02 d0  sethi  %hi(0xa00b4000), %g1
a0094254:  82 10 61 e8  or  %g1, 0x1e8, %g1	! 0xa00b41e8
a0094258:  e0 00 40 10  ld  [ %g1 + %l0 ], %l0
a009425c:  96 0c 20 ff  and  %l0, 0xff, %o3
a0094260:  90 10 00 14  mov  %l4, %o0
a0094264:  92 10 20 00  clr  %o1
a0094268:  40 00 4f 7b  call  0xa00a8054
a009426c:  94 10 21 06  mov  0x106, %o2
a0094270:  97 34 20 08  srl  %l0, 8, %o3
a0094274:  96 0a e0 ff  and  %o3, 0xff, %o3
a0094278:  90 10 00 14  mov  %l4, %o0
a009427c:  92 10 20 00  clr  %o1
a0094280:  40 00 4f 75  call  0xa00a8054
a0094284:  94 10 21 07  mov  0x107, %o2
a0094288:  a1 34 20 10  srl  %l0, 0x10, %l0
a009428c:  90 10 00 14  mov  %l4, %o0
a0094290:  96 0c 20 ff  and  %l0, 0xff, %o3
a0094294:  92 10 20 00  clr  %o1
a0094298:  10 80 00 17  b  0xa00942f4
a009429c:  94 10 21 08  mov  0x108, %o2
a00942a0:  a0 0d e0 ff  and  %l7, 0xff, %l0
a00942a4:  98 10 20 01  mov  1, %o4
a00942a8:  90 10 00 10  mov  %l0, %o0
a00942ac:  92 10 20 00  clr  %o1
a00942b0:  94 10 21 01  mov  0x101, %o2
a00942b4:  40 00 4f 86  call  0xa00a80cc
a00942b8:  96 10 20 02  mov  2, %o3
a00942bc:  90 10 00 10  mov  %l0, %o0
a00942c0:  92 10 20 00  clr  %o1
a00942c4:  94 10 21 03  mov  0x103, %o2
a00942c8:  40 00 4f 63  call  0xa00a8054
a00942cc:  96 10 20 00  clr  %o3
a00942d0:  90 10 00 10  mov  %l0, %o0
a00942d4:  92 10 20 00  clr  %o1
a00942d8:  94 10 21 04  mov  0x104, %o2
a00942dc:  40 00 4f 5e  call  0xa00a8054
a00942e0:  96 10 20 18  mov  0x18, %o3
a00942e4:  90 10 00 10  mov  %l0, %o0
a00942e8:  92 10 20 00  clr  %o1
a00942ec:  94 10 21 05  mov  0x105, %o2
a00942f0:  96 10 20 00  clr  %o3
a00942f4:  40 00 4f 58  call  0xa00a8054
a00942f8:  b0 10 20 01  mov  1, %i0
a00942fc:  01 00 00 00  nop
a0094300:  81 c7 e0 08  ret
a0094304:  81 e8 00 00  restore
