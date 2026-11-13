# leon2s FUN_a006d61c 0xa006d61c-0xa006d7a8 (396 bytes)
a006d61c:  9d e3 bf 98  save  %sp, -104, %sp
a006d620:  a0 0e 60 ff  and  %i1, 0xff, %l0
a006d624:  40 00 88 5e  call  0xa008f79c
a006d628:  90 10 00 10  mov  %l0, %o0
a006d62c:  90 0a 20 ff  and  %o0, 0xff, %o0
a006d630:  80 8a 20 01  btst  1, %o0
a006d634:  12 80 00 05  bne  0xa006d648
a006d638:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d63c:  80 8a 20 04  btst  4, %o0
a006d640:  02 80 00 04  be  0xa006d650
a006d644:  01 00 00 00  nop
a006d648:  10 80 00 03  b  0xa006d654
a006d64c:  82 10 60 04  or  %g1, 4, %g1
a006d650:  82 08 7f fb  and  %g1, -5, %g1
a006d654:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006d658:  80 8a 20 02  btst  2, %o0
a006d65c:  02 80 00 04  be  0xa006d66c
a006d660:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d664:  10 80 00 03  b  0xa006d670
a006d668:  82 10 60 08  or  %g1, 8, %g1
a006d66c:  82 08 7f f7  and  %g1, -9, %g1
a006d670:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006d674:  80 8a 20 10  btst  0x10, %o0
a006d678:  02 80 00 04  be  0xa006d688
a006d67c:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d680:  10 80 00 03  b  0xa006d68c
a006d684:  82 10 60 10  or  %g1, 0x10, %g1
a006d688:  82 08 7f ef  and  %g1, -17, %g1
a006d68c:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006d690:  80 8a 20 08  btst  8, %o0
a006d694:  02 80 00 04  be  0xa006d6a4
a006d698:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d69c:  10 80 00 03  b  0xa006d6a8
a006d6a0:  82 10 7f 80  or  %g1, -128, %g1
a006d6a4:  82 08 60 7f  and  %g1, 0x7f, %g1
a006d6a8:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006d6ac:  40 00 88 ce  call  0xa008f9e4
a006d6b0:  90 10 00 10  mov  %l0, %o0
a006d6b4:  80 8a 20 ff  btst  0xff, %o0
a006d6b8:  02 80 00 05  be  0xa006d6cc
a006d6bc:  da 16 20 0e  lduh  [ %i0 + 0xe ], %o5
a006d6c0:  03 00 00 10  sethi  %hi(0x4000), %g1
a006d6c4:  10 80 00 04  b  0xa006d6d4
a006d6c8:  82 13 40 01  or  %o5, %g1, %g1
a006d6cc:  03 00 00 10  sethi  %hi(0x4000), %g1
a006d6d0:  82 2b 40 01  andn  %o5, %g1, %g1
a006d6d4:  c2 36 20 0e  sth  %g1, [ %i0 + 0xe ]
a006d6d8:  40 00 88 ba  call  0xa008f9c0
a006d6dc:  90 10 00 10  mov  %l0, %o0
a006d6e0:  80 8a 20 ff  btst  0xff, %o0
a006d6e4:  da 16 20 0e  lduh  [ %i0 + 0xe ], %o5
a006d6e8:  02 80 00 05  be  0xa006d6fc
a006d6ec:  d8 0e 00 00  ldub  [ %i0 ], %o4
a006d6f0:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a006d6f4:  10 80 00 04  b  0xa006d704
a006d6f8:  82 13 40 01  or  %o5, %g1, %g1
a006d6fc:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a006d700:  82 2b 40 01  andn  %o5, %g1, %g1
a006d704:  80 a3 20 05  cmp  %o4, 5
a006d708:  02 80 00 07  be  0xa006d724
a006d70c:  c2 36 20 0e  sth  %g1, [ %i0 + 0xe ]
a006d710:  92 10 00 10  mov  %l0, %o1
a006d714:  40 00 8f 43  call  0xa0091420
a006d718:  90 10 20 01  mov  1, %o0
a006d71c:  10 80 00 0a  b  0xa006d744
a006d720:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006d724:  92 10 00 10  mov  %l0, %o1
a006d728:  40 00 8f 3e  call  0xa0091420
a006d72c:  90 10 20 00  clr  %o0
a006d730:  80 8a 20 ff  btst  0xff, %o0
a006d734:  02 80 00 04  be  0xa006d744
a006d738:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006d73c:  10 80 00 03  b  0xa006d748
a006d740:  82 10 60 40  or  %g1, 0x40, %g1
a006d744:  82 08 7f bf  and  %g1, -65, %g1
a006d748:  c2 36 20 12  sth  %g1, [ %i0 + 0x12 ]
a006d74c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006d750:  c2 08 60 35  ldub  [ %g1 + 0x35 ], %g1	! 0xa8078c35
a006d754:  b2 0e 60 ff  and  %i1, 0xff, %i1
a006d758:  83 38 40 19  sra  %g1, %i1, %g1
a006d75c:  80 88 60 01  btst  1, %g1
a006d760:  02 80 00 04  be  0xa006d770
a006d764:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d768:  10 80 00 03  b  0xa006d774
a006d76c:  82 10 60 40  or  %g1, 0x40, %g1
a006d770:  82 08 7f bf  and  %g1, -65, %g1
a006d774:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006d778:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a006d77c:  c2 08 60 5b  ldub  [ %g1 + 0x5b ], %g1	! 0xa8078c5b
a006d780:  83 38 40 19  sra  %g1, %i1, %g1
a006d784:  80 88 60 01  btst  1, %g1
a006d788:  02 80 00 04  be  0xa006d798
a006d78c:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d790:  10 80 00 03  b  0xa006d79c
a006d794:  82 10 60 20  or  %g1, 0x20, %g1
a006d798:  82 08 7f df  and  %g1, -33, %g1
a006d79c:  c2 2e 20 0d  stb  %g1, [ %i0 + 0xd ]
a006d7a0:  81 c7 e0 08  ret
a006d7a4:  81 e8 00 00  restore
