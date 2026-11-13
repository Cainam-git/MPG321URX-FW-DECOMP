# leon2s FUN_a00af764 0xa00af764-0xa00af858 (244 bytes)
a00af764:  9d e3 bf 98  save  %sp, -104, %sp
a00af768:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af76c:  7f c4 5b ae  call  0x9f1c6624
a00af770:  90 10 00 18  mov  %i0, %o0
a00af774:  92 0a 20 ff  and  %o0, 0xff, %o1
a00af778:  7f ff f9 74  call  0xa00add48
a00af77c:  90 10 00 18  mov  %i0, %o0
a00af780:  82 0a 20 ff  and  %o0, 0xff, %g1
a00af784:  80 a0 60 01  cmp  %g1, 1
a00af788:  18 80 00 04  bgu  0xa00af798
a00af78c:  a0 10 3f ff  mov  -1, %l0
a00af790:  10 80 00 13  b  0xa00af7dc
a00af794:  a0 10 20 01  mov  1, %l0
a00af798:  82 02 3f fe  add  %o0, -2, %g1
a00af79c:  82 08 60 ff  and  %g1, 0xff, %g1
a00af7a0:  80 a0 60 01  cmp  %g1, 1
a00af7a4:  18 80 00 04  bgu  0xa00af7b4
a00af7a8:  82 02 3f fc  add  %o0, -4, %g1
a00af7ac:  10 80 00 0c  b  0xa00af7dc
a00af7b0:  a0 10 20 02  mov  2, %l0
a00af7b4:  82 08 60 ff  and  %g1, 0xff, %g1
a00af7b8:  80 a0 60 01  cmp  %g1, 1
a00af7bc:  18 80 00 04  bgu  0xa00af7cc
a00af7c0:  82 02 3f fa  add  %o0, -6, %g1
a00af7c4:  10 80 00 06  b  0xa00af7dc
a00af7c8:  a0 10 20 04  mov  4, %l0
a00af7cc:  82 08 60 ff  and  %g1, 0xff, %g1
a00af7d0:  80 a0 60 01  cmp  %g1, 1
a00af7d4:  28 80 00 02  bleu,a   0xa00af7dc
a00af7d8:  a0 10 20 08  mov  8, %l0
a00af7dc:  7f ff 78 09  call  0xa008d800
a00af7e0:  01 00 00 00  nop
a00af7e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00af7e8:  80 a2 20 81  cmp  %o0, 0x81
a00af7ec:  38 80 00 0d  bgu,a   0xa00af820
a00af7f0:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00af7f4:  80 a6 20 00  cmp  %i0, 0
a00af7f8:  12 80 00 0a  bne  0xa00af820
a00af7fc:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00af800:  7f c4 5b 89  call  0x9f1c6624
a00af804:  90 10 20 00  clr  %o0
a00af808:  80 8a 20 ff  btst  0xff, %o0
a00af80c:  12 80 00 05  bne  0xa00af820
a00af810:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00af814:  7f ff 6d 81  call  0xa008ae18
a00af818:  90 10 20 01  mov  1, %o0
a00af81c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00af820:  80 a6 20 ff  cmp  %i0, 0xff
a00af824:  02 80 00 0b  be  0xa00af850
a00af828:  21 33 c0 49  sethi  %hi(0xcf012400), %l0
a00af82c:  a0 14 20 b8  or  %l0, 0xb8, %l0	! 0xcf0124b8
a00af830:  c2 04 00 00  ld  [ %l0 ], %g1
a00af834:  82 10 40 18  or  %g1, %i0, %g1
a00af838:  c2 24 00 00  st  %g1, [ %l0 ]
a00af83c:  40 00 07 d6  call  0xa00b1794
a00af840:  90 10 20 01  mov  1, %o0
a00af844:  c2 04 00 00  ld  [ %l0 ], %g1
a00af848:  82 28 40 18  andn  %g1, %i0, %g1
a00af84c:  c2 24 00 00  st  %g1, [ %l0 ]
a00af850:  81 c7 e0 08  ret
a00af854:  81 e8 00 00  restore
