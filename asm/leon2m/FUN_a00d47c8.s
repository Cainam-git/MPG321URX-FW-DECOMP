# leon2m FUN_a00d47c8 0xa00d47c8-0xa00d4888 (192 bytes)
a00d47c8:  9d e3 bf 98  save  %sp, -104, %sp
a00d47cc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d47d0:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d47d4:  da 08 60 06  ldub  [ %g1 + 6 ], %o5
a00d47d8:  98 0b 60 ff  and  %o5, 0xff, %o4
a00d47dc:  80 a3 20 04  cmp  %o4, 4
a00d47e0:  08 80 00 04  bleu  0xa00d47f0
a00d47e4:  b2 10 20 02  mov  2, %i1
a00d47e8:  98 10 20 04  mov  4, %o4
a00d47ec:  9a 10 20 04  mov  4, %o5
a00d47f0:  80 a3 20 02  cmp  %o4, 2
a00d47f4:  02 80 00 09  be  0xa00d4818
a00d47f8:  da 28 60 06  stb  %o5, [ %g1 + 6 ]
a00d47fc:  80 a3 20 02  cmp  %o4, 2
a00d4800:  14 80 00 0e  bg  0xa00d4838
a00d4804:  b2 10 20 03  mov  3, %i1
a00d4808:  80 a3 20 01  cmp  %o4, 1
a00d480c:  22 80 00 16  be,a   0xa00d4864
a00d4810:  90 10 20 00  clr  %o0
a00d4814:  b2 10 20 00  clr  %i1
a00d4818:  90 10 20 00  clr  %o0
a00d481c:  40 01 c9 69  call  0xa0146dc0
a00d4820:  92 10 20 00  clr  %o1
a00d4824:  40 01 d2 b3  call  0xa01492f0
a00d4828:  90 0e 60 03  and  %i1, 3, %o0
a00d482c:  b0 10 20 01  mov  1, %i0
a00d4830:  40 01 c9 64  call  0xa0146dc0
a00d4834:  93 e8 20 00  restore  %g0, 0, %o1
a00d4838:  80 a3 20 03  cmp  %o4, 3
a00d483c:  32 bf ff f7  bne,a   0xa00d4818
a00d4840:  b2 10 20 00  clr  %i1
a00d4844:  90 10 20 00  clr  %o0
a00d4848:  40 01 c9 5e  call  0xa0146dc0
a00d484c:  92 10 20 00  clr  %o1
a00d4850:  40 01 d2 a8  call  0xa01492f0
a00d4854:  90 0e 60 03  and  %i1, 3, %o0
a00d4858:  b0 10 20 01  mov  1, %i0
a00d485c:  40 01 c9 59  call  0xa0146dc0
a00d4860:  93 e8 20 00  restore  %g0, 0, %o1
a00d4864:  92 10 20 00  clr  %o1
a00d4868:  40 01 c9 56  call  0xa0146dc0
a00d486c:  b2 10 20 01  mov  1, %i1
a00d4870:  40 01 d2 a0  call  0xa01492f0
a00d4874:  90 0e 60 03  and  %i1, 3, %o0
a00d4878:  b0 10 20 01  mov  1, %i0
a00d487c:  40 01 c9 51  call  0xa0146dc0
a00d4880:  93 e8 20 00  restore  %g0, 0, %o1
a00d4884:  01 00 00 00  nop
