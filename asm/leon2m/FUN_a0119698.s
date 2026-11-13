# leon2m FUN_a0119698 0xa0119698-0xa01198a0 (80 bytes)
a0119698:  9d e3 bf 98  save  %sp, -104, %sp
a011969c:  35 2a 00 9e  sethi  %hi(0xa8027800), %i2
a01196a0:  c2 16 a2 a8  lduh  [ %i2 + 0x2a8 ], %g1	! 0xa8027aa8
a01196a4:  9e 0e 60 ff  and  %i1, 0xff, %o7
a01196a8:  ba 00 40 0f  add  %g1, %o7, %i5
a01196ac:  b7 2f 60 02  sll  %i5, 2, %i3
a01196b0:  39 33 c0 00  sethi  %hi(0xcf000000), %i4
a01196b4:  82 16 c0 1c  or  %i3, %i4, %g1
a01196b8:  fa 00 40 00  ld  [ %g1 ], %i5
a01196bc:  80 a6 20 04  cmp  %i0, 4
a01196c0:  18 80 00 76  bgu  0xa0119898
a01196c4:  9a 0f 60 3f  and  %i5, 0x3f, %o5
a01196c8:  3b 00 02 e4  sethi  %hi(0xb9000), %i5
a01196cc:  b7 2e 20 02  sll  %i0, 2, %i3
a01196d0:  b8 17 61 48  or  %i5, 0x148, %i4
a01196d4:  f0 07 00 1b  ld  [ %i4 + %i3 ], %i0
a01196d8:  81 c6 00 00  jmp  %i0
a01196dc:  01 00 00 00  nop
a01196e0:  b0 16 a2 a8  or  %i2, 0x2a8, %i0
a01196e4:  b6 03 c0 0f  add  %o7, %o7, %i3
a01196e8:  fa 16 00 1b  lduh  [ %i0 + %i3 ], %i5
a01196ec:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a01196f0:  82 17 21 c0  or  %i4, 0x1c0, %g1	! 0xa802c9c0
a01196f4:  b2 07 60 a2  add  %i5, 0xa2, %i1
a01196f8:  b4 10 20 0a  mov  0xa, %i2
a01196fc:  b1 2e 60 02  sll  %i1, 2, %i0
a0119700:  f4 28 40 0f  stb  %i2, [ %g1 + %o7 ]
a0119704:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a0119708:  82 17 21 b8  or  %i4, 0x1b8, %g1	! 0xa802c9b8
a011970c:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a0119710:  b4 10 20 10  mov  0x10, %i2
a0119714:  f4 28 40 0f  stb  %i2, [ %g1 + %o7 ]
a0119718:  b6 16 00 19  or  %i0, %i1, %i3
a011971c:  b8 13 7f c0  or  %o5, -64, %i4
a0119720:  f4 06 c0 00  ld  [ %i3 ], %i2
a0119724:  82 16 80 1c  or  %i2, %i4, %g1
a0119728:  ba 07 60 a3  add  %i5, 0xa3, %i5
a011972c:  b0 08 60 ff  and  %g1, 0xff, %i0
a0119730:  b9 2f 60 02  sll  %i5, 2, %i4
a0119734:  f0 26 c0 00  st  %i0, [ %i3 ]
a0119738:  ba 17 00 19  or  %i4, %i1, %i5
a011973c:  f4 07 40 00  ld  [ %i5 ], %i2
a0119740:  82 0e a0 3f  and  %i2, 0x3f, %g1
a0119744:  c2 27 40 00  st  %g1, [ %i5 ]
a0119748:  30 80 00 54  b,a   0xa0119898
a011974c:  b2 16 a2 a8  or  %i2, 0x2a8, %i1
a0119750:  b6 03 c0 0f  add  %o7, %o7, %i3
a0119754:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0119758:  f0 16 40 1b  lduh  [ %i1 + %i3 ], %i0
a011975c:  b4 10 61 c0  or  %g1, 0x1c0, %i2
a0119760:  ba 10 20 18  mov  0x18, %i5
a0119764:  fa 2e 80 0f  stb  %i5, [ %i2 + %o7 ]
a0119768:  b8 06 20 a3  add  %i0, 0xa3, %i4
a011976c:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a0119770:  82 16 61 b8  or  %i1, 0x1b8, %g1	! 0xa802c9b8
a0119774:  b1 2f 20 02  sll  %i4, 2, %i0
a0119778:  b6 10 20 24  mov  0x24, %i3
a011977c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a0119780:  f6 28 40 0f  stb  %i3, [ %g1 + %o7 ]
a0119784:  b8 16 00 1d  or  %i0, %i5, %i4
a0119788:  f4 07 00 00  ld  [ %i4 ], %i2
a011978c:  b2 16 bf c0  or  %i2, -64, %i1
a0119790:  82 0e 60 ff  and  %i1, 0xff, %g1
a0119794:  c2 27 00 00  st  %g1, [ %i4 ]
a0119798:  30 80 00 40  b,a   0xa0119898
a011979c:  b8 16 a2 a8  or  %i2, 0x2a8, %i4
a01197a0:  b6 03 c0 0f  add  %o7, %o7, %i3
a01197a4:  fa 17 00 1b  lduh  [ %i4 + %i3 ], %i5
a01197a8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a01197ac:  b2 07 60 a2  add  %i5, 0xa2, %i1
a01197b0:  b4 10 20 0a  mov  0xa, %i2
a01197b4:  b0 10 61 c0  or  %g1, 0x1c0, %i0
a01197b8:  b7 2e 60 02  sll  %i1, 2, %i3
a01197bc:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a01197c0:  f4 2e 00 0f  stb  %i2, [ %i0 + %o7 ]
a01197c4:  82 17 21 b8  or  %i4, 0x1b8, %g1
a01197c8:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a01197cc:  b4 10 20 12  mov  0x12, %i2
a01197d0:  f4 28 40 0f  stb  %i2, [ %g1 + %o7 ]
a01197d4:  b6 16 c0 19  or  %i3, %i1, %i3
a01197d8:  10 bf ff d2  b  0xa0119720
a01197dc:  b8 13 60 40  or  %o5, 0x40, %i4
a01197e0:  b0 16 a2 a8  or  %i2, 0x2a8, %i0
a01197e4:  b6 03 c0 0f  add  %o7, %o7, %i3
a01197e8:  fa 16 00 1b  lduh  [ %i0 + %i3 ], %i5
a01197ec:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a01197f0:  82 17 21 c0  or  %i4, 0x1c0, %g1	! 0xa802c9c0
a01197f4:  b2 07 60 a2  add  %i5, 0xa2, %i1
a01197f8:  b4 10 20 0c  mov  0xc, %i2
a01197fc:  b1 2e 60 02  sll  %i1, 2, %i0
a0119800:  f4 28 40 0f  stb  %i2, [ %g1 + %o7 ]
a0119804:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a0119808:  82 17 21 b8  or  %i4, 0x1b8, %g1	! 0xa802c9b8
a011980c:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a0119810:  b4 10 20 10  mov  0x10, %i2
a0119814:  f4 28 40 0f  stb  %i2, [ %g1 + %o7 ]
a0119818:  b6 16 00 19  or  %i0, %i1, %i3
a011981c:  10 bf ff c1  b  0xa0119720
a0119820:  b8 13 7f 80  or  %o5, -128, %i4
a0119824:  37 2a 00 b2  sethi  %hi(0xa802c800), %i3
a0119828:  82 16 e1 c0  or  %i3, 0x1c0, %g1	! 0xa802c9c0
a011982c:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0119830:  ba 10 20 0c  mov  0xc, %i5
a0119834:  b8 10 20 12  mov  0x12, %i4
a0119838:  b6 16 21 b8  or  %i0, 0x1b8, %i3
a011983c:  fa 28 40 0f  stb  %i5, [ %g1 + %o7 ]
a0119840:  80 a3 e0 01  cmp  %o7, 1
a0119844:  08 80 00 03  bleu  0xa0119850
a0119848:  f8 2e c0 0f  stb  %i4, [ %i3 + %o7 ]
a011984c:  b2 10 20 00  clr  %i1
a0119850:  b6 0e 60 ff  and  %i1, 0xff, %i3
a0119854:  b8 16 a2 a8  or  %i2, 0x2a8, %i4
a0119858:  82 06 c0 1b  add  %i3, %i3, %g1
a011985c:  f0 17 00 01  lduh  [ %i4 + %g1 ], %i0
a0119860:  ba 03 c0 0f  add  %o7, %o7, %i5
a0119864:  f2 17 00 1d  lduh  [ %i4 + %i5 ], %i1
a0119868:  b4 06 20 a2  add  %i0, 0xa2, %i2
a011986c:  b8 06 60 a3  add  %i1, 0xa3, %i4
a0119870:  b7 2e a0 02  sll  %i2, 2, %i3
a0119874:  31 33 c0 00  sethi  %hi(0xcf000000), %i0
a0119878:  82 0b 60 ff  and  %o5, 0xff, %g1
a011987c:  ba 16 c0 18  or  %i3, %i0, %i5
a0119880:  b5 2f 20 02  sll  %i4, 2, %i2
a0119884:  c2 27 40 00  st  %g1, [ %i5 ]
a0119888:  b8 16 80 18  or  %i2, %i0, %i4
a011988c:  f2 07 00 00  ld  [ %i4 ], %i1
a0119890:  82 0e 60 3f  and  %i1, 0x3f, %g1
a0119894:  c2 27 00 00  st  %g1, [ %i4 ]
a0119898:  81 c7 e0 08  ret
a011989c:  81 e8 00 00  restore
