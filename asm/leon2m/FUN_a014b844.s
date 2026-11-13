# leon2m FUN_a014b844 0xa014b844-0xa014b900 (188 bytes)
a014b844:  9d e3 bf 98  save  %sp, -104, %sp
a014b848:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014b84c:  80 a6 20 00  cmp  %i0, 0
a014b850:  12 80 00 16  bne  0xa014b8a8
a014b854:  80 a6 20 01  cmp  %i0, 1
a014b858:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014b85c:  9a 0e 60 ff  and  %i1, 0xff, %o5
a014b860:  82 16 23 d0  or  %i0, 0x3d0, %g1
a014b864:  f2 28 60 2a  stb  %i1, [ %g1 + 0x2a ]
a014b868:  90 10 20 02  mov  2, %o0
a014b86c:  80 a3 60 01  cmp  %o5, 1
a014b870:  02 80 00 04  be  0xa014b880
a014b874:  92 10 20 01  mov  1, %o1
a014b878:  90 10 20 02  mov  2, %o0
a014b87c:  92 10 20 00  clr  %o1
a014b880:  7f ff 92 89  call  0xa01302a4
a014b884:  01 00 00 00  nop
a014b888:  90 10 20 02  mov  2, %o0	! 0x2
a014b88c:  7f ff 8e 58  call  0xa012f1ec
a014b890:  92 10 20 00  clr  %o1
a014b894:  92 16 23 d0  or  %i0, 0x3d0, %o1
a014b898:  7f ff 9b b6  call  0xa0132770
a014b89c:  d0 0a 60 2a  ldub  [ %o1 + 0x2a ], %o0
a014b8a0:  7f ff 96 7f  call  0xa013129c
a014b8a4:  81 e8 00 00  restore
a014b8a8:  12 bf ff fe  bne  0xa014b8a0
a014b8ac:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014b8b0:  90 16 23 d0  or  %i0, 0x3d0, %o0	! 0xa802e3d0
a014b8b4:  94 0e 60 ff  and  %i1, 0xff, %o2
a014b8b8:  f2 2a 20 2c  stb  %i1, [ %o0 + 0x2c ]
a014b8bc:  90 10 20 03  mov  3, %o0
a014b8c0:  80 a2 a0 01  cmp  %o2, 1
a014b8c4:  02 80 00 04  be  0xa014b8d4
a014b8c8:  92 10 20 01  mov  1, %o1
a014b8cc:  90 10 20 03  mov  3, %o0
a014b8d0:  92 10 20 00  clr  %o1
a014b8d4:  7f ff 92 74  call  0xa01302a4
a014b8d8:  01 00 00 00  nop
a014b8dc:  90 10 20 03  mov  3, %o0	! 0x3
a014b8e0:  7f ff 8e 43  call  0xa012f1ec
a014b8e4:  92 10 20 00  clr  %o1
a014b8e8:  96 16 23 d0  or  %i0, 0x3d0, %o3
a014b8ec:  7f ff 9b bd  call  0xa01327e0
a014b8f0:  d0 0a e0 2c  ldub  [ %o3 + 0x2c ], %o0
a014b8f4:  7f ff 96 6a  call  0xa013129c
a014b8f8:  81 e8 00 00  restore
a014b8fc:  01 00 00 00  nop
