# leon2m FUN_a01398bc 0xa01398bc-0xa0139968 (172 bytes)
a01398bc:  9d e3 bf 90  save  %sp, -112, %sp
a01398c0:  90 10 3f ff  mov  -1, %o0
a01398c4:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a01398c8:  90 10 20 02  mov  2, %o0
a01398cc:  92 10 20 20  mov  0x20, %o1
a01398d0:  94 07 bf f4  add  %fp, -12, %o2
a01398d4:  67 fd 4a ff  call  0x4008c4d0
a01398d8:  96 10 20 01  mov  1, %o3
a01398dc:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a01398e0:  80 a0 60 00  cmp  %g1, 0
a01398e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01398e8:  02 80 00 10  be  0xa0139928
a01398ec:  a0 10 20 64  mov  0x64, %l0
a01398f0:  67 fd 4e 2c  call  0x4008d1a0
a01398f4:  90 10 20 01  mov  1, %o0
a01398f8:  90 10 20 02  mov  2, %o0
a01398fc:  92 10 20 20  mov  0x20, %o1
a0139900:  94 07 bf f4  add  %fp, -12, %o2
a0139904:  67 fd 4a f3  call  0x4008c4d0
a0139908:  96 10 20 01  mov  1, %o3
a013990c:  a0 04 3f ff  add  %l0, -1, %l0
a0139910:  80 a4 20 00  cmp  %l0, 0
a0139914:  02 80 00 0f  be  0xa0139950
a0139918:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013991c:  80 a2 60 00  cmp  %o1, 0
a0139920:  12 bf ff f4  bne  0xa01398f0
a0139924:  01 00 00 00  nop
a0139928:  98 0e 20 ff  and  %i0, 0xff, %o4
a013992c:  1b 18 00 00  sethi  %hi(0x60000000), %o5
a0139930:  96 13 00 0d  or  %o4, %o5, %o3
a0139934:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a0139938:  90 10 20 02  mov  2, %o0
a013993c:  92 10 20 20  mov  0x20, %o1
a0139940:  94 07 bf f4  add  %fp, -12, %o2
a0139944:  67 fd 4b 2d  call  0x4008c5f8
a0139948:  96 10 20 01  mov  1, %o3
a013994c:  30 80 00 05  b,a   0xa0139960
a0139950:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a0139954:  80 a2 a0 00  cmp  %o2, 0
a0139958:  02 bf ff f5  be  0xa013992c
a013995c:  98 0e 20 ff  and  %i0, 0xff, %o4
a0139960:  81 c7 e0 08  ret
a0139964:  81 e8 00 00  restore
