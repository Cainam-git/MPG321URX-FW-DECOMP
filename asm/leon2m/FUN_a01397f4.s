# leon2m FUN_a01397f4 0xa01397f4-0xa01398bc (200 bytes)
a01397f4:  9d e3 bf 90  save  %sp, -112, %sp
a01397f8:  25 2a 00 a9  sethi  %hi(0xa802a400), %l2
a01397fc:  da 0c a0 5a  ldub  [ %l2 + 0x5a ], %o5	! 0xa802a45a
a0139800:  82 0e 20 ff  and  %i0, 0xff, %g1
a0139804:  80 a3 40 01  cmp  %o5, %g1
a0139808:  02 80 00 2a  be  0xa01398b0
a013980c:  92 10 3f ff  mov  -1, %o1
a0139810:  d2 27 bf f4  st  %o1, [ %fp + -12 ]
a0139814:  90 10 20 02  mov  2, %o0
a0139818:  92 10 20 20  mov  0x20, %o1
a013981c:  94 07 bf f4  add  %fp, -12, %o2
a0139820:  67 fd 4b 2c  call  0x4008c4d0
a0139824:  96 10 20 01  mov  1, %o3
a0139828:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a013982c:  80 a2 20 00  cmp  %o0, 0
a0139830:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0139834:  02 80 00 10  be  0xa0139874
a0139838:  a0 10 20 64  mov  0x64, %l0
a013983c:  67 fd 4e 59  call  0x4008d1a0
a0139840:  90 10 20 01  mov  1, %o0
a0139844:  90 10 20 02  mov  2, %o0
a0139848:  92 10 20 20  mov  0x20, %o1
a013984c:  94 07 bf f4  add  %fp, -12, %o2
a0139850:  67 fd 4b 20  call  0x4008c4d0
a0139854:  96 10 20 01  mov  1, %o3
a0139858:  a0 04 3f ff  add  %l0, -1, %l0
a013985c:  80 a4 20 00  cmp  %l0, 0
a0139860:  02 80 00 10  be  0xa01398a0
a0139864:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139868:  80 a2 a0 00  cmp  %o2, 0
a013986c:  12 bf ff f4  bne  0xa013983c
a0139870:  01 00 00 00  nop
a0139874:  9e 0c 60 ff  and  %l1, 0xff, %o7
a0139878:  21 20 80 00  sethi  %hi(0x82000000), %l0
a013987c:  98 13 c0 10  or  %o7, %l0, %o4
a0139880:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a0139884:  90 10 20 02  mov  2, %o0
a0139888:  92 10 20 20  mov  0x20, %o1
a013988c:  94 07 bf f4  add  %fp, -12, %o2
a0139890:  67 fd 4b 5a  call  0x4008c5f8
a0139894:  96 10 20 01  mov  1, %o3
a0139898:  10 80 00 07  b  0xa01398b4
a013989c:  f0 2c a0 5a  stb  %i0, [ %l2 + 0x5a ]
a01398a0:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a01398a4:  80 a2 e0 00  cmp  %o3, 0
a01398a8:  02 bf ff f4  be  0xa0139878
a01398ac:  9e 0c 60 ff  and  %l1, 0xff, %o7
a01398b0:  f0 2c a0 5a  stb  %i0, [ %l2 + 0x5a ]
a01398b4:  81 c7 e0 08  ret
a01398b8:  81 e8 00 00  restore
