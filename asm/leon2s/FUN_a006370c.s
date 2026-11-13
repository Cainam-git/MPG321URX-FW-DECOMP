# leon2s FUN_a006370c 0xa006370c-0xa00638a0 (404 bytes)
a006370c:  9d e3 bf 08  save  %sp, -248, %sp
a0063710:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a0063714:  82 10 60 0c  or  %g1, 0xc, %g1	! 0xcf03c80c
a0063718:  c2 00 40 00  ld  [ %g1 ], %g1
a006371c:  80 a0 60 99  cmp  %g1, 0x99
a0063720:  12 80 00 5d  bne  0xa0063894
a0063724:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a0063728:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a006372c:  c2 08 60 36  ldub  [ %g1 + 0x36 ], %g1
a0063730:  da 0b 60 37  ldub  [ %o5 + 0x37 ], %o5
a0063734:  83 38 40 0d  sra  %g1, %o5, %g1
a0063738:  80 88 60 01  btst  1, %g1
a006373c:  12 80 00 56  bne  0xa0063894
a0063740:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0063744:  d2 10 62 74  lduh  [ %g1 + 0x274 ], %o1	! 0xa8076274
a0063748:  21 2a 01 f3  sethi  %hi(0xa807cc00), %l0
a006374c:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a0063750:  c2 04 21 74  ld  [ %l0 + 0x174 ], %g1
a0063754:  9f c0 40 00  call  %g1
a0063758:  d0 0c 62 38  ldub  [ %l1 + 0x238 ], %o0
a006375c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0063760:  c2 08 62 72  ldub  [ %g1 + 0x272 ], %g1	! 0xa8076272
a0063764:  80 8a 00 01  btst  %o0, %g1
a0063768:  02 80 00 4b  be  0xa0063894
a006376c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0063770:  d2 10 62 6e  lduh  [ %g1 + 0x26e ], %o1	! 0xa807626e
a0063774:  c2 04 21 74  ld  [ %l0 + 0x174 ], %g1
a0063778:  9f c0 40 00  call  %g1
a006377c:  d0 0c 62 38  ldub  [ %l1 + 0x238 ], %o0
a0063780:  90 0a 20 ff  and  %o0, 0xff, %o0
a0063784:  80 a2 20 8b  cmp  %o0, 0x8b
a0063788:  12 80 00 43  bne  0xa0063894
a006378c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0063790:  d2 10 62 6c  lduh  [ %g1 + 0x26c ], %o1	! 0xa807626c
a0063794:  c2 04 21 74  ld  [ %l0 + 0x174 ], %g1
a0063798:  9f c0 40 00  call  %g1
a006379c:  d0 0c 62 38  ldub  [ %l1 + 0x238 ], %o0
a00637a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00637a4:  80 a2 20 84  cmp  %o0, 0x84
a00637a8:  12 80 00 3b  bne  0xa0063894
a00637ac:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00637b0:  d2 10 62 6a  lduh  [ %g1 + 0x26a ], %o1	! 0xa807626a
a00637b4:  c2 04 21 74  ld  [ %l0 + 0x174 ], %g1
a00637b8:  9f c0 40 00  call  %g1
a00637bc:  d0 0c 62 38  ldub  [ %l1 + 0x238 ], %o0
a00637c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00637c4:  80 a2 20 90  cmp  %o0, 0x90
a00637c8:  12 80 00 33  bne  0xa0063894
a00637cc:  01 00 00 00  nop
a00637d0:  40 01 3a 25  call  0xa00b2064
a00637d4:  01 00 00 00  nop
a00637d8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00637dc:  d0 20 62 3c  st  %o0, [ %g1 + 0x23c ]	! 0xa8078a3c
a00637e0:  9a 10 20 01  mov  1, %o5
a00637e4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00637e8:  da 28 62 3a  stb  %o5, [ %g1 + 0x23a ]	! 0xa8078a3a
a00637ec:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00637f0:  d2 10 62 70  lduh  [ %g1 + 0x270 ], %o1	! 0xa8076270
a00637f4:  da 04 21 74  ld  [ %l0 + 0x174 ], %o5
a00637f8:  9f c3 40 00  call  %o5
a00637fc:  d0 0c 62 38  ldub  [ %l1 + 0x238 ], %o0
a0063800:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0063804:  90 0a 20 ff  and  %o0, 0xff, %o0
a0063808:  c2 08 62 40  ldub  [ %g1 + 0x240 ], %g1
a006380c:  80 a2 00 01  cmp  %o0, %g1
a0063810:  12 80 00 08  bne  0xa0063830
a0063814:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a0063818:  7f ff f7 44  call  0xa0061528
a006381c:  90 12 23 fc  or  %o0, 0x3fc, %o0	! 0xd0013ffc
a0063820:  90 0a 20 ff  and  %o0, 0xff, %o0
a0063824:  80 a2 20 aa  cmp  %o0, 0xaa
a0063828:  02 80 00 1b  be  0xa0063894
a006382c:  01 00 00 00  nop
a0063830:  7f ff f9 4c  call  0xa0061d60
a0063834:  01 00 00 00  nop
a0063838:  a0 07 bf 68  add  %fp, -152, %l0
a006383c:  13 2a 01 e2  sethi  %hi(0xa8078800), %o1
a0063840:  92 12 62 a0  or  %o1, 0x2a0, %o1	! 0xa8078aa0
a0063844:  94 10 20 8a  mov  0x8a, %o2
a0063848:  40 01 37 64  call  0xa00b15d8
a006384c:  90 10 00 10  mov  %l0, %o0
a0063850:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0063854:  d0 00 62 90  ld  [ %g1 + 0x290 ], %o0	! 0xa8078a90
a0063858:  7f ff fd dc  call  0xa0062fc8
a006385c:  92 10 00 10  mov  %l0, %o1
a0063860:  80 8a 20 ff  btst  0xff, %o0
a0063864:  02 80 00 08  be  0xa0063884
a0063868:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a006386c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0063870:  d2 08 62 39  ldub  [ %g1 + 0x239 ], %o1	! 0xa8078a39
a0063874:  93 2a 60 10  sll  %o1, 0x10, %o1
a0063878:  90 12 23 fc  or  %o0, 0x3fc, %o0
a006387c:  10 80 00 04  b  0xa006388c
a0063880:  92 12 60 aa  or  %o1, 0xaa, %o1
a0063884:  90 12 23 fc  or  %o0, 0x3fc, %o0
a0063888:  92 10 20 ff  mov  0xff, %o1
a006388c:  7f ff f7 2a  call  0xa0061534
a0063890:  01 00 00 00  nop
a0063894:  01 00 00 00  nop
a0063898:  81 c7 e0 08  ret
a006389c:  81 e8 00 00  restore
