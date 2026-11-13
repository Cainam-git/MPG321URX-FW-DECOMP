# leon2s FUN_a007f900 0xa007f900-0xa007f9d0 (208 bytes)
a007f900:  9d e3 bf 98  save  %sp, -104, %sp
a007f904:  a0 10 20 00  clr  %l0
a007f908:  83 2c 20 10  sll  %l0, 0x10, %g1
a007f90c:  9b 30 60 10  srl  %g1, 0x10, %o5
a007f910:  a2 0e 60 ff  and  %i1, 0xff, %l1
a007f914:  83 3c 40 0d  sra  %l1, %o5, %g1
a007f918:  80 88 60 01  btst  1, %g1
a007f91c:  22 80 00 0d  be,a   0xa007f950
a007f920:  9a 04 20 01  add  %l0, 1, %o5
a007f924:  98 03 40 0d  add  %o5, %o5, %o4
a007f928:  80 a3 60 03  cmp  %o5, 3
a007f92c:  90 10 20 01  mov  1, %o0
a007f930:  92 10 20 04  mov  4, %o1
a007f934:  18 80 00 06  bgu  0xa007f94c
a007f938:  94 0e 20 ff  and  %i0, 0xff, %o2
a007f93c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007f940:  82 10 63 68  or  %g1, 0x368, %g1	! 0xa00b3b68
a007f944:  40 00 9e b8  call  0xa00a7424
a007f948:  d6 10 40 0c  lduh  [ %g1 + %o4 ], %o3
a007f94c:  9a 04 20 01  add  %l0, 1, %o5
a007f950:  83 2b 60 10  sll  %o5, 0x10, %g1
a007f954:  83 30 60 10  srl  %g1, 0x10, %g1
a007f958:  80 a0 60 03  cmp  %g1, 3
a007f95c:  08 bf ff eb  bleu  0xa007f908
a007f960:  a0 10 00 0d  mov  %o5, %l0
a007f964:  40 00 c7 8c  call  0xa00b1794
a007f968:  90 10 20 01  mov  1, %o0
a007f96c:  a0 10 20 00  clr  %l0
a007f970:  83 2c 20 10  sll  %l0, 0x10, %g1
a007f974:  9b 30 60 10  srl  %g1, 0x10, %o5
a007f978:  83 3c 40 0d  sra  %l1, %o5, %g1
a007f97c:  80 88 60 01  btst  1, %g1
a007f980:  22 80 00 0d  be,a   0xa007f9b4
a007f984:  9a 04 20 01  add  %l0, 1, %o5
a007f988:  98 03 40 0d  add  %o5, %o5, %o4
a007f98c:  80 a3 60 03  cmp  %o5, 3
a007f990:  90 10 20 00  clr  %o0
a007f994:  92 10 20 04  mov  4, %o1
a007f998:  18 80 00 06  bgu  0xa007f9b0
a007f99c:  94 0e 20 ff  and  %i0, 0xff, %o2
a007f9a0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007f9a4:  82 10 63 68  or  %g1, 0x368, %g1	! 0xa00b3b68
a007f9a8:  40 00 9e 9f  call  0xa00a7424
a007f9ac:  d6 10 40 0c  lduh  [ %g1 + %o4 ], %o3
a007f9b0:  9a 04 20 01  add  %l0, 1, %o5
a007f9b4:  83 2b 60 10  sll  %o5, 0x10, %g1
a007f9b8:  83 30 60 10  srl  %g1, 0x10, %g1
a007f9bc:  80 a0 60 03  cmp  %g1, 3
a007f9c0:  08 bf ff ec  bleu  0xa007f970
a007f9c4:  a0 10 00 0d  mov  %o5, %l0
a007f9c8:  81 c7 e0 08  ret
a007f9cc:  81 e8 00 00  restore
