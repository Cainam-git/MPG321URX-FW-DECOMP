# leon2m FUN_a00b77b4 0xa00b77b4-0xa00b789c (232 bytes)
a00b77b4:  9d e3 bf 98  save  %sp, -104, %sp
a00b77b8:  90 10 21 11  mov  0x111, %o0
a00b77bc:  40 02 3c e5  call  0xa0146b50
a00b77c0:  92 10 20 00  clr  %o1
a00b77c4:  90 10 20 00  clr  %o0
a00b77c8:  40 02 3c e9  call  0xa0146b6c
a00b77cc:  92 10 20 00  clr  %o1
a00b77d0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b77d4:  82 14 22 90  or  %l0, 0x290, %g1	! 0xa802d290
a00b77d8:  11 00 06 4c  sethi  %hi(0x193000), %o0
a00b77dc:  d2 08 60 08  ldub  [ %g1 + 8 ], %o1
a00b77e0:  7f ff b0 19  call  0xa00a3844
a00b77e4:  90 12 22 48  or  %o0, 0x248, %o0
a00b77e8:  98 10 00 08  mov  %o0, %o4
a00b77ec:  90 10 20 00  clr  %o0
a00b77f0:  92 10 20 2a  mov  0x2a, %o1
a00b77f4:  94 10 20 06  mov  6, %o2
a00b77f8:  96 10 20 01  mov  1, %o3
a00b77fc:  7f ff ae 6a  call  0xa00a31a4
a00b7800:  9a 10 20 00  clr  %o5
a00b7804:  b2 10 20 01  mov  1, %i1
a00b7808:  31 00 06 4c  sethi  %hi(0x193000), %i0
a00b780c:  b4 10 20 01  mov  1, %i2
a00b7810:  98 0e 60 ff  and  %i1, 0xff, %o4
a00b7814:  96 03 3f ff  add  %o4, -1, %o3
a00b7818:  93 2a e0 10  sll  %o3, 0x10, %o1
a00b781c:  93 32 60 10  srl  %o1, 0x10, %o1
a00b7820:  7f ff b0 09  call  0xa00a3844
a00b7824:  90 16 23 30  or  %i0, 0x330, %o0
a00b7828:  98 10 00 08  mov  %o0, %o4
a00b782c:  94 06 80 1a  add  %i2, %i2, %o2
a00b7830:  94 02 a0 06  add  %o2, 6, %o2
a00b7834:  90 10 20 00  clr  %o0
a00b7838:  92 10 20 2a  mov  0x2a, %o1
a00b783c:  96 10 20 01  mov  1, %o3
a00b7840:  9a 10 20 00  clr  %o5
a00b7844:  7f ff ae 58  call  0xa00a31a4
a00b7848:  b2 06 60 01  inc  %i1
a00b784c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b7850:  80 a6 a0 03  cmp  %i2, 3
a00b7854:  08 bf ff f0  bleu  0xa00b7814
a00b7858:  98 0e 60 ff  and  %i1, 0xff, %o4
a00b785c:  9a 14 22 90  or  %l0, 0x290, %o5
a00b7860:  c2 03 60 a8  ld  [ %o5 + 0xa8 ], %g1
a00b7864:  80 88 60 40  btst  0x40, %g1
a00b7868:  02 80 00 05  be  0xa00b787c
a00b786c:  b2 10 20 00  clr  %i1
a00b7870:  a1 30 60 05  srl  %g1, 5, %l0
a00b7874:  9e 0c 20 01  and  %l0, 1, %o7
a00b7878:  b2 03 e0 01  add  %o7, 1, %i1
a00b787c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b7880:  90 10 00 19  mov  %i1, %o0
a00b7884:  7f ff c7 73  call  0xa00a9650
a00b7888:  92 10 20 00  clr  %o1
a00b788c:  b0 10 20 01  mov  1, %i0
a00b7890:  7f ff c2 2b  call  0xa00a813c
a00b7894:  95 e8 20 01  restore  %g0, 1, %o2
a00b7898:  01 00 00 00  nop
