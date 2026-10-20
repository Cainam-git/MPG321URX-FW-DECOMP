# leon2m FUN_a00b37a4 0xa00b37a4-0xa00b3860 (188 bytes)
a00b37a4:  9d e3 bf 88  save  %sp, -120, %sp
a00b37a8:  40 00 94 e4  call  0xa00d8b38
a00b37ac:  01 00 00 00  nop
a00b37b0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00b37b4:  a0 07 bf e8  add  %fp, -24, %l0
a00b37b8:  13 00 06 60  sethi  %hi(0x198000), %o1
a00b37bc:  92 12 61 d8  or  %o1, 0x1d8, %o1	! 0x1981d8
a00b37c0:  95 32 a0 10  srl  %o2, 0x10, %o2
a00b37c4:  40 02 90 0c  call  0xa01577f4
a00b37c8:  90 10 00 10  mov  %l0, %o0
a00b37cc:  98 10 20 00  clr  %o4
a00b37d0:  82 10 20 00  clr  %g1
a00b37d4:  96 07 bf f8  add  %fp, -8, %o3
a00b37d8:  82 02 c0 01  add  %o3, %g1, %g1
a00b37dc:  da 08 7f f0  ldub  [ %g1 + -16 ], %o5
a00b37e0:  80 a3 60 00  cmp  %o5, 0
a00b37e4:  22 80 00 08  be,a   0xa00b3804
a00b37e8:  90 03 3f ff  add  %o4, -1, %o0
a00b37ec:  98 03 20 01  inc  %o4
a00b37f0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b37f4:  80 a0 60 0f  cmp  %g1, 0xf
a00b37f8:  08 bf ff f9  bleu  0xa00b37dc
a00b37fc:  82 02 c0 01  add  %o3, %g1, %g1
a00b3800:  90 03 3f ff  add  %o4, -1, %o0
a00b3804:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00b3808:  90 10 20 02  mov  2, %o0
a00b380c:  40 02 4c d8  call  0xa0146b6c
a00b3810:  92 10 20 00  clr  %o1
a00b3814:  90 10 21 b5  mov  0x1b5, %o0
a00b3818:  40 02 4c ce  call  0xa0146b50
a00b381c:  92 10 20 00  clr  %o1
a00b3820:  90 10 20 0e  mov  0xe, %o0
a00b3824:  92 10 20 02  mov  2, %o1
a00b3828:  94 10 20 08  mov  8, %o2
a00b382c:  96 10 25 96  mov  0x596, %o3
a00b3830:  40 02 4c 94  call  0xa0146a80
a00b3834:  98 10 20 00  clr  %o4
a00b3838:  98 10 00 10  mov  %l0, %o4
a00b383c:  90 10 20 00  clr  %o0
a00b3840:  92 10 20 0e  mov  0xe, %o1
a00b3844:  94 10 20 02  mov  2, %o2
a00b3848:  96 10 20 08  mov  8, %o3
a00b384c:  7f ff be 56  call  0xa00a31a4
a00b3850:  9a 10 20 00  clr  %o5
a00b3854:  01 00 00 00  nop
a00b3858:  81 c7 e0 08  ret
a00b385c:  81 e8 00 00  restore
