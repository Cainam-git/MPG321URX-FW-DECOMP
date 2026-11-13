# leon2m FUN_a013b92c 0xa013b92c-0xa013ba14 (232 bytes)
a013b92c:  9d e3 bf 98  save  %sp, -104, %sp
a013b930:  40 00 05 07  call  0xa013cd4c
a013b934:  90 0e 20 ff  and  %i0, 0xff, %o0
a013b938:  13 00 00 16  sethi  %hi(0x5800), %o1
a013b93c:  d6 12 20 3c  lduh  [ %o0 + 0x3c ], %o3
a013b940:  94 12 63 01  or  %o1, 0x301, %o2
a013b944:  9e 1a c0 0a  xor  %o3, %o2, %o7
a013b948:  15 00 00 17  sethi  %hi(0x5c00), %o2
a013b94c:  80 a0 00 0f  cmp  %g0, %o7
a013b950:  90 12 a0 01  or  %o2, 1, %o0
a013b954:  98 60 3f ff  subx  %g0, -1, %o4
a013b958:  9a 1a c0 08  xor  %o3, %o0, %o5
a013b95c:  80 a0 00 0d  cmp  %g0, %o5
a013b960:  82 60 3f ff  subx  %g0, -1, %g1
a013b964:  80 93 00 01  orcc  %o4, %g1, %g0
a013b968:  12 80 00 29  bne  0xa013ba0c
a013b96c:  b0 10 20 01  mov  1, %i0
a013b970:  b0 12 a1 01  or  %o2, 0x101, %i0
a013b974:  80 a2 c0 18  cmp  %o3, %i0
a013b978:  02 80 00 24  be  0xa013ba08
a013b97c:  80 a2 e8 00  cmp  %o3, 0x800
a013b980:  02 80 00 22  be  0xa013ba08
a013b984:  82 12 a3 01  or  %o2, 0x301, %g1
a013b988:  80 a2 c0 01  cmp  %o3, %g1
a013b98c:  02 80 00 1f  be  0xa013ba08
a013b990:  1b 00 00 18  sethi  %hi(0x6000), %o5
a013b994:  98 13 60 01  or  %o5, 1, %o4	! 0x6001
a013b998:  80 a2 c0 0c  cmp  %o3, %o4
a013b99c:  02 80 00 1b  be  0xa013ba08
a013b9a0:  90 13 61 01  or  %o5, 0x101, %o0
a013b9a4:  80 a2 c0 08  cmp  %o3, %o0
a013b9a8:  02 80 00 18  be  0xa013ba08
a013b9ac:  80 a2 c0 09  cmp  %o3, %o1
a013b9b0:  02 80 00 16  be  0xa013ba08
a013b9b4:  9e 12 61 00  or  %o1, 0x100, %o7
a013b9b8:  80 a2 c0 0f  cmp  %o3, %o7
a013b9bc:  02 80 00 13  be  0xa013ba08
a013b9c0:  31 00 00 08  sethi  %hi(0x2000), %i0
a013b9c4:  94 16 22 00  or  %i0, 0x200, %o2	! 0x2200
a013b9c8:  80 a2 c0 0a  cmp  %o3, %o2
a013b9cc:  02 80 00 0f  be  0xa013ba08
a013b9d0:  19 00 00 15  sethi  %hi(0x5400), %o4
a013b9d4:  82 13 23 00  or  %o4, 0x300, %g1	! 0x5700
a013b9d8:  80 a2 c0 01  cmp  %o3, %g1
a013b9dc:  02 80 00 0b  be  0xa013ba08
a013b9e0:  90 12 62 00  or  %o1, 0x200, %o0
a013b9e4:  80 a2 c0 08  cmp  %o3, %o0
a013b9e8:  02 80 00 08  be  0xa013ba08
a013b9ec:  92 13 63 01  or  %o5, 0x301, %o1
a013b9f0:  80 a2 c0 09  cmp  %o3, %o1
a013b9f4:  02 80 00 05  be  0xa013ba08
a013b9f8:  9e 13 62 01  or  %o5, 0x201, %o7
a013b9fc:  80 a2 c0 0f  cmp  %o3, %o7
a013ba00:  12 80 00 03  bne  0xa013ba0c
a013ba04:  b0 10 20 00  clr  %i0
a013ba08:  b0 10 20 01  mov  1, %i0
a013ba0c:  81 c7 e0 08  ret
a013ba10:  81 e8 00 00  restore
