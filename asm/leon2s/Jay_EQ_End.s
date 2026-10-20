# leon2s Jay_EQ_End 0xa009d5cc-0xa009d87c (688 bytes)
a009d5cc:  9d e3 bf 98  save  %sp, -104, %sp
a009d5d0:  a6 0e 20 ff  and  %i0, 0xff, %l3
a009d5d4:  80 a4 e0 00  cmp  %l3, 0
a009d5d8:  02 80 00 05  be  0xa009d5ec
a009d5dc:  a4 10 20 02  mov  2, %l2
a009d5e0:  80 a4 e0 01  cmp  %l3, 1
a009d5e4:  12 80 00 a3  bne  0xa009d870
a009d5e8:  a4 10 20 03  mov  3, %l2
a009d5ec:  2b 2a 01 f6  sethi  %hi(0xa807d800), %l5
a009d5f0:  a2 15 63 00  or  %l5, 0x300, %l1	! 0xa807db00
a009d5f4:  a0 5c e0 34  smul  %l3, 0x34, %l0
a009d5f8:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d5fc:  92 02 60 04  add  %o1, 4, %o1
a009d600:  40 00 27 6b  call  0xa00a73ac
a009d604:  90 10 20 0c  mov  0xc, %o0
a009d608:  a0 04 00 11  add  %l0, %l1, %l0
a009d60c:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a009d610:  92 02 60 30  add  %o1, 0x30, %o1
a009d614:  40 00 27 70  call  0xa00a73d4
a009d618:  90 10 20 18  mov  0x18, %o0
a009d61c:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a009d620:  92 02 60 30  add  %o1, 0x30, %o1
a009d624:  40 00 27 6c  call  0xa00a73d4
a009d628:  90 10 20 19  mov  0x19, %o0
a009d62c:  40 00 0a 0d  call  0xa009fe60
a009d630:  90 10 00 13  mov  %l3, %o0
a009d634:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a009d638:  9a 15 23 e0  or  %l4, 0x3e0, %o5	! 0xa807d7e0
a009d63c:  82 5c e1 90  smul  %l3, 0x190, %g1
a009d640:  82 00 40 0d  add  %g1, %o5, %g1
a009d644:  c2 08 60 04  ldub  [ %g1 + 4 ], %g1
a009d648:  80 a0 60 01  cmp  %g1, 1
a009d64c:  12 80 00 05  bne  0xa009d660
a009d650:  98 0c a0 ff  and  %l2, 0xff, %o4
a009d654:  7f ff fc 8a  call  0xa009c87c
a009d658:  90 10 00 13  mov  %l3, %o0
a009d65c:  98 0c a0 ff  and  %l2, 0xff, %o4
a009d660:  82 03 00 0c  add  %o4, %o4, %g1
a009d664:  82 00 40 0c  add  %g1, %o4, %g1
a009d668:  17 2a 01 f3  sethi  %hi(0xa807cc00), %o3
a009d66c:  83 28 60 03  sll  %g1, 3, %g1
a009d670:  9a 12 e0 64  or  %o3, 0x64, %o5
a009d674:  82 00 40 0d  add  %g1, %o5, %g1
a009d678:  e2 08 60 01  ldub  [ %g1 + 1 ], %l1
a009d67c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009d680:  82 10 60 c8  or  %g1, 0xc8, %g1	! 0xa80790c8
a009d684:  80 a4 60 01  cmp  %l1, 1
a009d688:  12 80 00 70  bne  0xa009d848
a009d68c:  c0 28 40 13  clrb  [ %g1 + %l3 ]
a009d690:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009d694:  83 2c e0 02  sll  %l3, 2, %g1
a009d698:  9a 13 62 48  or  %o5, 0x248, %o5
a009d69c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009d6a0:  80 a0 60 09  cmp  %g1, 9
a009d6a4:  12 80 00 1a  bne  0xa009d70c
a009d6a8:  82 03 00 0c  add  %o4, %o4, %g1
a009d6ac:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a009d6b0:  92 02 60 30  add  %o1, 0x30, %o1
a009d6b4:  40 00 27 3e  call  0xa00a73ac
a009d6b8:  90 10 20 18  mov  0x18, %o0
a009d6bc:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a009d6c0:  92 02 60 30  add  %o1, 0x30, %o1
a009d6c4:  40 00 27 3a  call  0xa00a73ac
a009d6c8:  90 10 20 19  mov  0x19, %o0
a009d6cc:  9a 04 c0 13  add  %l3, %l3, %o5
a009d6d0:  9a 03 40 13  add  %o5, %l3, %o5
a009d6d4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009d6d8:  9b 2b 60 03  sll  %o5, 3, %o5
a009d6dc:  d2 04 20 0c  ld  [ %l0 + 0xc ], %o1
a009d6e0:  82 10 62 50  or  %g1, 0x250, %g1
a009d6e4:  e2 20 40 0d  st  %l1, [ %g1 + %o5 ]
a009d6e8:  92 02 60 7c  add  %o1, 0x7c, %o1
a009d6ec:  40 00 27 3a  call  0xa00a73d4
a009d6f0:  90 10 20 0b  mov  0xb, %o0
a009d6f4:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d6f8:  92 10 20 de  mov  0xde, %o1
a009d6fc:  7f ff 56 52  call  0xa0073044
a009d700:  90 12 21 f8  or  %o0, 0x1f8, %o0
a009d704:  10 80 00 5c  b  0xa009d874
a009d708:  b0 10 20 01  mov  1, %i0
a009d70c:  82 00 40 0c  add  %g1, %o4, %g1
a009d710:  9a 12 e0 64  or  %o3, 0x64, %o5
a009d714:  83 28 60 03  sll  %g1, 3, %g1
a009d718:  82 00 40 0d  add  %g1, %o5, %g1
a009d71c:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a009d720:  80 a0 60 01  cmp  %g1, 1
a009d724:  12 80 00 49  bne  0xa009d848
a009d728:  82 15 23 e0  or  %l4, 0x3e0, %g1
a009d72c:  9a 5c e1 90  smul  %l3, 0x190, %o5
a009d730:  a4 03 40 01  add  %o5, %g1, %l2
a009d734:  c2 0c a0 01  ldub  [ %l2 + 1 ], %g1
a009d738:  80 a0 60 00  cmp  %g1, 0
a009d73c:  12 80 00 44  bne  0xa009d84c
a009d740:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009d744:  a2 15 63 00  or  %l5, 0x300, %l1
a009d748:  a0 5c e0 34  smul  %l3, 0x34, %l0
a009d74c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009d750:  82 10 60 a8  or  %g1, 0xa8, %g1	! 0xa80790a8
a009d754:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d758:  c0 28 40 13  clrb  [ %g1 + %l3 ]
a009d75c:  92 02 60 08  add  %o1, 8, %o1
a009d760:  40 00 27 1d  call  0xa00a73d4
a009d764:  90 10 20 0c  mov  0xc, %o0
a009d768:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d76c:  92 02 60 08  add  %o1, 8, %o1
a009d770:  40 00 27 0f  call  0xa00a73ac
a009d774:  90 10 20 0d  mov  0xd, %o0
a009d778:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d77c:  92 02 60 08  add  %o1, 8, %o1
a009d780:  40 00 27 15  call  0xa00a73d4
a009d784:  90 10 20 0f  mov  0xf, %o0
a009d788:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d78c:  92 10 20 01  mov  1, %o1
a009d790:  7f ff 56 2d  call  0xa0073044
a009d794:  90 12 22 18  or  %o0, 0x218, %o0
a009d798:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d79c:  c0 2c a0 2d  clrb  [ %l2 + 0x2d ]
a009d7a0:  92 02 60 84  add  %o1, 0x84, %o1
a009d7a4:  40 00 27 02  call  0xa00a73ac
a009d7a8:  90 10 20 14  mov  0x14, %o0
a009d7ac:  a4 04 00 11  add  %l0, %l1, %l2
a009d7b0:  da 04 a0 20  ld  [ %l2 + 0x20 ], %o5
a009d7b4:  c2 03 60 80  ld  [ %o5 + 0x80 ], %g1
a009d7b8:  82 10 60 07  or  %g1, 7, %g1
a009d7bc:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d7c0:  c2 23 60 80  st  %g1, [ %o5 + 0x80 ]
a009d7c4:  92 02 60 08  add  %o1, 8, %o1
a009d7c8:  40 00 27 03  call  0xa00a73d4
a009d7cc:  90 10 20 0b  mov  0xb, %o0
a009d7d0:  9a 04 c0 13  add  %l3, %l3, %o5
a009d7d4:  9a 03 40 13  add  %o5, %l3, %o5
a009d7d8:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a009d7dc:  98 13 22 50  or  %o4, 0x250, %o4	! 0xa807d650
a009d7e0:  9b 2b 60 03  sll  %o5, 3, %o5
a009d7e4:  d2 04 a0 04  ld  [ %l2 + 4 ], %o1
a009d7e8:  96 03 40 0c  add  %o5, %o4, %o3
a009d7ec:  82 10 20 0a  mov  0xa, %g1
a009d7f0:  c2 2a e0 04  stb  %g1, [ %o3 + 4 ]
a009d7f4:  82 10 20 04  mov  4, %g1
a009d7f8:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a009d7fc:  92 02 60 34  add  %o1, 0x34, %o1
a009d800:  40 00 26 f5  call  0xa00a73d4
a009d804:  90 10 20 1c  mov  0x1c, %o0
a009d808:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009d80c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009d810:  80 88 60 04  btst  4, %g1
a009d814:  22 80 00 18  be,a   0xa009d874
a009d818:  b0 10 20 01  mov  1, %i0
a009d81c:  40 00 52 12  call  0xa00b2064
a009d820:  01 00 00 00  nop
a009d824:  94 10 00 08  mov  %o0, %o2
a009d828:  92 06 20 41  add  %i0, 0x41, %o1
a009d82c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009d830:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009d834:  90 12 22 28  or  %o0, 0x228, %o0	! 0xa006aa28
a009d838:  7f ff 56 03  call  0xa0073044
a009d83c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009d840:  10 80 00 0d  b  0xa009d874
a009d844:  b0 10 20 01  mov  1, %i0
a009d848:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009d84c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009d850:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a009d854:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009d858:  9a 03 40 01  add  %o5, %g1, %o5
a009d85c:  90 10 00 10  mov  %l0, %o0
a009d860:  7f ff e4 91  call  0xa0096aa4
a009d864:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a009d868:  7f ff e4 9c  call  0xa0096ad8
a009d86c:  90 10 00 10  mov  %l0, %o0
a009d870:  b0 10 20 00  clr  %i0
a009d874:  81 c7 e0 08  ret
a009d878:  81 e8 00 00  restore
