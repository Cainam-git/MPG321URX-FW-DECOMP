# leon2m FUN_a014667c 0xa014667c-0xa0146870 (296 bytes)
a014667c:  9d e3 bf 88  save  %sp, -120, %sp
a0146680:  82 0e 20 ff  and  %i0, 0xff, %g1
a0146684:  d6 0f a0 6f  ldub  [ %fp + 0x6f ], %o3
a0146688:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014668c:  c0 2f bf f2  clrb  [ %fp + -14 ]
a0146690:  80 a0 60 08  cmp  %g1, 8
a0146694:  e2 0f a0 5f  ldub  [ %fp + 0x5f ], %l1
a0146698:  e4 0f a0 63  ldub  [ %fp + 0x63 ], %l2
a014669c:  e6 0f a0 67  ldub  [ %fp + 0x67 ], %l3
a01466a0:  e0 0f a0 6b  ldub  [ %fp + 0x6b ], %l0
a01466a4:  18 80 00 0f  bgu  0xa01466e0
a01466a8:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01466ac:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a01466b0:  83 28 60 02  sll  %g1, 2, %g1
a01466b4:  9a 12 22 dc  or  %o0, 0x2dc, %o5
a01466b8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a01466bc:  81 c3 00 00  jmp  %o4
a01466c0:  01 00 00 00  nop
a01466c4:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01466c8:  c0 2f bf f1  clrb  [ %fp + -15 ]
a01466cc:  c0 2f bf f3  clrb  [ %fp + -13 ]
a01466d0:  c0 2f bf f4  clrb  [ %fp + -12 ]
a01466d4:  90 10 20 00  clr  %o0
a01466d8:  67 fd 20 03  call  0x4008e6e4
a01466dc:  92 10 00 18  mov  %i0, %o1
a01466e0:  80 8e 60 ff  btst  0xff, %i1
a01466e4:  02 80 00 14  be  0xa0146734
a01466e8:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a01466ec:  d2 0f bf f0  ldub  [ %fp + -16 ], %o1
a01466f0:  82 12 60 01  or  %o1, 1, %g1
a01466f4:  80 8e a0 ff  btst  0xff, %i2
a01466f8:  02 80 00 13  be  0xa0146744
a01466fc:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0146700:  d6 0f bf f0  ldub  [ %fp + -16 ], %o3
a0146704:  82 12 e0 04  or  %o3, 4, %g1
a0146708:  80 8e e0 ff  btst  0xff, %i3
a014670c:  02 80 00 13  be  0xa0146758
a0146710:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0146714:  f2 0f bf f0  ldub  [ %fp + -16 ], %i1
a0146718:  82 16 60 02  or  %i1, 2, %g1
a014671c:  80 8f 20 ff  btst  0xff, %i4
a0146720:  02 80 00 13  be  0xa014676c
a0146724:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0146728:  f6 0f bf f0  ldub  [ %fp + -16 ], %i3
a014672c:  10 80 00 3f  b  0xa0146828
a0146730:  82 16 e0 08  or  %i3, 8, %g1
a0146734:  82 0a bf fe  and  %o2, -2, %g1
a0146738:  80 8e a0 ff  btst  0xff, %i2
a014673c:  12 bf ff f1  bne  0xa0146700
a0146740:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0146744:  de 0f bf f0  ldub  [ %fp + -16 ], %o7
a0146748:  82 0b ff fb  and  %o7, -5, %g1
a014674c:  80 8e e0 ff  btst  0xff, %i3
a0146750:  12 bf ff f1  bne  0xa0146714
a0146754:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0146758:  f4 0f bf f0  ldub  [ %fp + -16 ], %i2
a014675c:  82 0e bf fd  and  %i2, -3, %g1
a0146760:  80 8f 20 ff  btst  0xff, %i4
a0146764:  12 bf ff f1  bne  0xa0146728
a0146768:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014676c:  f8 0f bf f0  ldub  [ %fp + -16 ], %i4
a0146770:  10 80 00 2e  b  0xa0146828
a0146774:  82 0f 3f f7  and  %i4, -9, %g1
a0146778:  10 bf ff da  b  0xa01466e0
a014677c:  b0 0a e0 ff  and  %o3, 0xff, %i0
a0146780:  b0 0a e0 ff  and  %o3, 0xff, %i0
a0146784:  c0 2f bf f1  clrb  [ %fp + -15 ]
a0146788:  c0 2f bf f3  clrb  [ %fp + -13 ]
a014678c:  c0 2f bf f4  clrb  [ %fp + -12 ]
a0146790:  10 bf ff d2  b  0xa01466d8
a0146794:  90 10 20 01  mov  1, %o0
a0146798:  b0 0a e0 ff  and  %o3, 0xff, %i0
a014679c:  c0 2f bf f1  clrb  [ %fp + -15 ]
a01467a0:  c0 2f bf f3  clrb  [ %fp + -13 ]
a01467a4:  c0 2f bf f4  clrb  [ %fp + -12 ]
a01467a8:  10 bf ff cc  b  0xa01466d8
a01467ac:  90 10 20 02  mov  2, %o0
a01467b0:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01467b4:  c0 2f bf f1  clrb  [ %fp + -15 ]
a01467b8:  c0 2f bf f3  clrb  [ %fp + -13 ]
a01467bc:  c0 2f bf f4  clrb  [ %fp + -12 ]
a01467c0:  10 bf ff c6  b  0xa01466d8
a01467c4:  90 10 20 03  mov  3, %o0
a01467c8:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01467cc:  c0 2f bf f1  clrb  [ %fp + -15 ]
a01467d0:  c0 2f bf f3  clrb  [ %fp + -13 ]
a01467d4:  c0 2f bf f4  clrb  [ %fp + -12 ]
a01467d8:  10 bf ff c0  b  0xa01466d8
a01467dc:  90 10 20 04  mov  4, %o0
a01467e0:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01467e4:  c0 2f bf f1  clrb  [ %fp + -15 ]
a01467e8:  c0 2f bf f3  clrb  [ %fp + -13 ]
a01467ec:  c0 2f bf f4  clrb  [ %fp + -12 ]
a01467f0:  10 bf ff ba  b  0xa01466d8
a01467f4:  90 10 20 05  mov  5, %o0
a01467f8:  b0 0a e0 ff  and  %o3, 0xff, %i0
a01467fc:  c0 2f bf f1  clrb  [ %fp + -15 ]
a0146800:  c0 2f bf f3  clrb  [ %fp + -13 ]
a0146804:  c0 2f bf f4  clrb  [ %fp + -12 ]
a0146808:  10 bf ff b4  b  0xa01466d8
a014680c:  90 10 20 06  mov  6, %o0
a0146810:  b0 0a e0 ff  and  %o3, 0xff, %i0
a0146814:  c0 2f bf f1  clrb  [ %fp + -15 ]
a0146818:  c0 2f bf f3  clrb  [ %fp + -13 ]
a014681c:  c0 2f bf f4  clrb  [ %fp + -12 ]
a0146820:  10 bf ff ae  b  0xa01466d8
a0146824:  90 10 20 07  mov  7, %o0
a0146828:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014682c:  83 2c 60 04  sll  %l1, 4, %g1
a0146830:  98 08 60 30  and  %g1, 0x30, %o4
a0146834:  9a 0c a0 0f  and  %l2, 0xf, %o5
a0146838:  a4 13 00 0d  or  %o4, %o5, %l2
a014683c:  fa 2f bf f1  stb  %i5, [ %fp + -15 ]
a0146840:  e4 2f bf f2  stb  %l2, [ %fp + -14 ]
a0146844:  e6 2f bf f3  stb  %l3, [ %fp + -13 ]
a0146848:  e2 07 bf f0  ld  [ %fp + -16 ], %l1
a014684c:  e2 27 bf e8  st  %l1, [ %fp + -24 ]
a0146850:  e0 2f bf ec  stb  %l0, [ %fp + -20 ]
a0146854:  e0 2f bf f4  stb  %l0, [ %fp + -12 ]
a0146858:  92 10 00 18  mov  %i0, %o1
a014685c:  7f ff 4f 46  call  0xa011a574
a0146860:  90 07 bf e8  add  %fp, -24, %o0
a0146864:  01 00 00 00  nop
a0146868:  81 c7 e0 08  ret
a014686c:  81 e8 00 00  restore
