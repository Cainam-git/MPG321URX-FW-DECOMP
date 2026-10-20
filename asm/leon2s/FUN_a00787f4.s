# leon2s FUN_a00787f4 0xa00787f4-0xa007890c (280 bytes)
a00787f4:  9d e3 bf 98  save  %sp, -104, %sp
a00787f8:  a4 10 20 00  clr  %l2
a00787fc:  83 2c a0 10  sll  %l2, 0x10, %g1
a0078800:  83 30 60 10  srl  %g1, 0x10, %g1
a0078804:  90 10 20 01  mov  1, %o0
a0078808:  92 10 20 04  mov  4, %o1
a007880c:  94 0e 20 ff  and  %i0, 0xff, %o2
a0078810:  27 3f c0 3f  sethi  %hi(0xff00fc00), %l3
a0078814:  80 a0 60 02  cmp  %g1, 2
a0078818:  18 80 00 19  bgu  0xa007887c
a007881c:  a0 00 40 01  add  %g1, %g1, %l0
a0078820:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078824:  82 10 63 0a  or  %g1, 0x30a, %g1	! 0xa00b3b0a
a0078828:  e2 10 40 10  lduh  [ %g1 + %l0 ], %l1
a007882c:  40 00 ba fe  call  0xa00a7424
a0078830:  96 10 00 11  mov  %l1, %o3
a0078834:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0078838:  82 10 63 04  or  %g1, 0x304, %g1	! 0xa00b3b04
a007883c:  e0 10 40 10  lduh  [ %g1 + %l0 ], %l0
a0078840:  90 10 20 00  clr  %o0
a0078844:  92 10 20 00  clr  %o1
a0078848:  94 0e 20 ff  and  %i0, 0xff, %o2
a007884c:  40 00 ba f6  call  0xa00a7424
a0078850:  96 10 00 10  mov  %l0, %o3
a0078854:  92 10 00 10  mov  %l0, %o1
a0078858:  90 0e 20 ff  and  %i0, 0xff, %o0
a007885c:  94 14 e3 ff  or  %l3, 0x3ff, %o2
a0078860:  40 00 bb 0a  call  0xa00a7488
a0078864:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a0078868:  92 10 00 11  mov  %l1, %o1
a007886c:  94 14 e3 ff  or  %l3, 0x3ff, %o2
a0078870:  90 0e 20 ff  and  %i0, 0xff, %o0
a0078874:  40 00 bb 05  call  0xa00a7488
a0078878:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a007887c:  9a 04 a0 01  add  %l2, 1, %o5
a0078880:  83 2b 60 10  sll  %o5, 0x10, %g1
a0078884:  83 30 60 10  srl  %g1, 0x10, %g1
a0078888:  80 a0 60 02  cmp  %g1, 2
a007888c:  08 bf ff dc  bleu  0xa00787fc
a0078890:  a4 10 00 0d  mov  %o5, %l2
a0078894:  40 00 e3 c0  call  0xa00b1794
a0078898:  90 10 20 01  mov  1, %o0
a007889c:  a4 10 20 00  clr  %l2
a00788a0:  83 2c a0 10  sll  %l2, 0x10, %g1
a00788a4:  83 30 60 10  srl  %g1, 0x10, %g1
a00788a8:  90 10 20 01  mov  1, %o0
a00788ac:  92 10 20 00  clr  %o1
a00788b0:  94 0e 20 ff  and  %i0, 0xff, %o2
a00788b4:  80 a0 60 02  cmp  %g1, 2
a00788b8:  18 80 00 0d  bgu  0xa00788ec
a00788bc:  a0 00 40 01  add  %g1, %g1, %l0
a00788c0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00788c4:  82 10 63 04  or  %g1, 0x304, %g1	! 0xa00b3b04
a00788c8:  40 00 ba d7  call  0xa00a7424
a00788cc:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a00788d0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00788d4:  82 10 63 0a  or  %g1, 0x30a, %g1	! 0xa00b3b0a
a00788d8:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a00788dc:  90 10 20 00  clr  %o0
a00788e0:  92 10 20 04  mov  4, %o1
a00788e4:  40 00 ba d0  call  0xa00a7424
a00788e8:  94 0e 20 ff  and  %i0, 0xff, %o2
a00788ec:  9a 04 a0 01  add  %l2, 1, %o5
a00788f0:  83 2b 60 10  sll  %o5, 0x10, %g1
a00788f4:  83 30 60 10  srl  %g1, 0x10, %g1
a00788f8:  80 a0 60 02  cmp  %g1, 2
a00788fc:  08 bf ff e9  bleu  0xa00788a0
a0078900:  a4 10 00 0d  mov  %o5, %l2
a0078904:  81 c7 e0 08  ret
a0078908:  81 e8 00 00  restore
