# leon2s FUN_a00a67b8 0xa00a67b8-0xa00a68d0 (280 bytes)
a00a67b8:  9d e3 bf 98  save  %sp, -104, %sp
a00a67bc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a67c0:  80 a6 20 02  cmp  %i0, 2
a00a67c4:  9a 10 00 19  mov  %i1, %o5
a00a67c8:  18 80 00 40  bgu  0xa00a68c8
a00a67cc:  98 10 00 1a  mov  %i2, %o4
a00a67d0:  80 a6 20 02  cmp  %i0, 2
a00a67d4:  12 80 00 21  bne  0xa00a6858
a00a67d8:  80 a6 20 01  cmp  %i0, 1
a00a67dc:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a67e0:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a67e4:  96 10 61 9c  or  %g1, 0x19c, %o3	! 0xa00b4d9c
a00a67e8:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a67ec:  9e 0e e0 ff  and  %i3, 0xff, %o7
a00a67f0:  b4 38 00 1a  xnor  %g0, %i2, %i2
a00a67f4:  b8 10 20 00  clr  %i4
a00a67f8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a67fc:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a6800:  ba 00 40 01  add  %g1, %g1, %i5
a00a6804:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a6808:  82 00 40 19  add  %g1, %i1, %g1
a00a680c:  83 28 60 02  sll  %g1, 2, %g1
a00a6810:  82 10 40 0d  or  %g1, %o5, %g1
a00a6814:  b8 07 20 01  inc  %i4
a00a6818:  c2 00 40 00  ld  [ %g1 ], %g1
a00a681c:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00a6820:  80 a3 e0 01  cmp  %o7, 1
a00a6824:  02 80 00 03  be  0xa00a6830
a00a6828:  b6 10 40 0c  or  %g1, %o4, %i3
a00a682c:  b6 08 40 1a  and  %g1, %i2, %i3
a00a6830:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a6834:  82 00 40 19  add  %g1, %i1, %g1
a00a6838:  83 28 60 02  sll  %g1, 2, %g1
a00a683c:  82 10 40 0d  or  %g1, %o5, %g1
a00a6840:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a6844:  fa 20 40 00  st  %i5, [ %g1 ]
a00a6848:  80 a6 20 01  cmp  %i0, 1
a00a684c:  08 bf ff ed  bleu  0xa00a6800
a00a6850:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a6854:  30 80 00 1d  b,a   0xa00a68c8
a00a6858:  18 80 00 1c  bgu  0xa00a68c8
a00a685c:  1f 28 02 d3  sethi  %hi(0xa00b4c00), %o7
a00a6860:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a6864:  b8 13 e1 9c  or  %o7, 0x19c, %i4
a00a6868:  82 06 00 18  add  %i0, %i0, %g1
a00a686c:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a6870:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a6874:  82 00 40 1d  add  %g1, %i5, %g1
a00a6878:  83 28 60 02  sll  %g1, 2, %g1
a00a687c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a6880:  82 10 40 1d  or  %g1, %i5, %g1
a00a6884:  f2 00 40 00  ld  [ %g1 ], %i1
a00a6888:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a688c:  80 a0 60 01  cmp  %g1, 1
a00a6890:  02 80 00 04  be  0xa00a68a0
a00a6894:  b6 16 40 1a  or  %i1, %i2, %i3
a00a6898:  b6 2e 40 1a  andn  %i1, %i2, %i3
a00a689c:  b8 13 e1 9c  or  %o7, 0x19c, %i4
a00a68a0:  82 06 00 18  add  %i0, %i0, %g1
a00a68a4:  bb 2b 60 10  sll  %o5, 0x10, %i5
a00a68a8:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a68ac:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a68b0:  82 00 40 1d  add  %g1, %i5, %g1
a00a68b4:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a68b8:  83 28 60 02  sll  %g1, 2, %g1
a00a68bc:  82 10 40 1d  or  %g1, %i5, %g1
a00a68c0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a68c4:  fa 20 40 00  st  %i5, [ %g1 ]
a00a68c8:  81 c7 e0 08  ret
a00a68cc:  81 e8 00 00  restore
