# leon2s FUN_a00d378c 0xa00d378c-0xa00d38a8 (284 bytes)
a00d378c:  9d e3 bf 98  save  %sp, -104, %sp
a00d3790:  11 2d c2 44  sethi  %hi(0xb7091000), %o0
a00d3794:  40 3a 77 65  call  0xa0f71528
a00d3798:  90 12 20 90  or  %o0, 0x90, %o0	! 0xb7091090
a00d379c:  03 2a 01 da  sethi  %hi(0xa8076800), %g1
a00d37a0:  a0 10 00 08  mov  %o0, %l0
a00d37a4:  31 2d c2 00  sethi  %hi(0xb7080000), %i0
a00d37a8:  aa 10 61 d8  or  %g1, 0x1d8, %l5
a00d37ac:  40 3a 77 5f  call  0xa0f71528
a00d37b0:  90 16 23 a0  or  %i0, 0x3a0, %o0
a00d37b4:  9a 0a 23 ff  and  %o0, 0x3ff, %o5
a00d37b8:  03 2a 01 da  sethi  %hi(0xa8076800), %g1
a00d37bc:  a8 10 60 44  or  %g1, 0x44, %l4	! 0xa8076844
a00d37c0:  9b 2b 60 02  sll  %o5, 2, %o5
a00d37c4:  c2 05 40 0d  ld  [ %l5 + %o5 ], %g1
a00d37c8:  a1 2c 20 02  sll  %l0, 2, %l0
a00d37cc:  da 05 00 10  ld  [ %l4 + %l0 ], %o5
a00d37d0:  82 58 40 0d  smul  %g1, %o5, %g1
a00d37d4:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a00d37d8:  a2 13 61 1f  or  %o5, 0x11f, %l1	! 0x51eb851f
a00d37dc:  80 50 40 11  umul  %g1, %l1, %g0
a00d37e0:  83 40 00 00  rd  %y, %g1
a00d37e4:  83 30 60 05  srl  %g1, 5, %g1
a00d37e8:  25 2a 01 e3  sethi  %hi(0xa8078c00), %l2
a00d37ec:  80 a0 64 00  cmp  %g1, 0x400
a00d37f0:  90 16 23 a0  or  %i0, 0x3a0, %o0
a00d37f4:  b2 10 20 01  mov  1, %i1
a00d37f8:  82 10 20 64  mov  0x64, %g1
a00d37fc:  18 80 00 10  bgu  0xa00d383c
a00d3800:  a6 14 a0 3c  or  %l2, 0x3c, %l3
a00d3804:  40 3a 77 49  call  0xa0f71528
a00d3808:  01 00 00 00  nop
a00d380c:  40 3a 77 47  call  0xa0f71528
a00d3810:  90 16 23 a0  or  %i0, 0x3a0, %o0
a00d3814:  90 0a 23 ff  and  %o0, 0x3ff, %o0
a00d3818:  91 2a 20 02  sll  %o0, 2, %o0
a00d381c:  c2 05 40 08  ld  [ %l5 + %o0 ], %g1
a00d3820:  da 05 00 10  ld  [ %l4 + %l0 ], %o5
a00d3824:  82 58 40 0d  smul  %g1, %o5, %g1
a00d3828:  80 50 40 11  umul  %g1, %l1, %g0
a00d382c:  83 40 00 00  rd  %y, %g1
a00d3830:  83 30 60 05  srl  %g1, 5, %g1
a00d3834:  82 58 60 64  smul  %g1, 0x64, %g1
a00d3838:  83 30 60 0a  srl  %g1, 0xa, %g1
a00d383c:  1b 2a 01 d9  sethi  %hi(0xa8076400), %o5
a00d3840:  c2 24 c0 00  st  %g1, [ %l3 ]
a00d3844:  d8 03 62 b0  ld  [ %o5 + 0x2b0 ], %o4
a00d3848:  c2 04 a0 3c  ld  [ %l2 + 0x3c ], %g1
a00d384c:  83 28 60 02  sll  %g1, 2, %g1
a00d3850:  98 5b 20 64  smul  %o4, 0x64, %o4
a00d3854:  9a 13 62 b0  or  %o5, 0x2b0, %o5
a00d3858:  81 80 00 00  mov  %g0, %y
a00d385c:  d6 03 40 01  ld  [ %o5 + %g1 ], %o3
a00d3860:  01 00 00 00  nop
a00d3864:  01 00 00 00  nop
a00d3868:  96 73 00 0b  udiv  %o4, %o3, %o3
a00d386c:  03 2a 01 e0  sethi  %hi(0xa8078000), %g1
a00d3870:  f0 10 63 dc  lduh  [ %g1 + 0x3dc ], %i0	! 0xa80783dc
a00d3874:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a00d3878:  82 10 61 1f  or  %g1, 0x11f, %g1	! 0x51eb851f
a00d387c:  b0 5e 00 0b  smul  %i0, %o3, %i0
a00d3880:  80 56 00 01  umul  %i0, %g1, %g0
a00d3884:  b1 40 00 00  rd  %y, %i0
a00d3888:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d388c:  d6 20 61 e4  st  %o3, [ %g1 + 0x1e4 ]	! 0xa80785e4
a00d3890:  b1 36 20 05  srl  %i0, 5, %i0
a00d3894:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3898:  f0 20 60 40  st  %i0, [ %g1 + 0x40 ]	! 0xa8078c40
a00d389c:  7f ff ff 9a  call  0xa00d3704
a00d38a0:  81 e8 00 00  restore
a00d38a4:  01 00 00 00  nop
