# leon2m FUN_a00c9788 0xa00c9788-0xa00c9980 (504 bytes)
a00c9788:  9d e3 bf 98  save  %sp, -104, %sp
a00c978c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9790:  80 a4 20 02  cmp  %l0, 2
a00c9794:  02 80 00 59  be  0xa00c98f8
a00c9798:  80 a4 20 03  cmp  %l0, 3
a00c979c:  02 80 00 5a  be  0xa00c9904
a00c97a0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c97a4:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c97a8:  96 08 60 ff  and  %g1, 0xff, %o3
a00c97ac:  94 02 ff d0  add  %o3, -48, %o2
a00c97b0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c97b4:  80 a0 60 01  cmp  %g1, 1
a00c97b8:  18 80 00 70  bgu  0xa00c9978
a00c97bc:  b0 10 20 ff  mov  0xff, %i0
a00c97c0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c97c4:  92 08 60 01  and  %g1, 1, %o1
a00c97c8:  c2 03 22 90  ld  [ %o4 + 0x290 ], %g1
a00c97cc:  91 2a 60 09  sll  %o1, 9, %o0
a00c97d0:  b0 08 7d ff  and  %g1, -513, %i0
a00c97d4:  9e 16 00 08  or  %i0, %o0, %o7
a00c97d8:  9b 33 e0 09  srl  %o7, 9, %o5
a00c97dc:  de 23 22 90  st  %o7, [ %o4 + 0x290 ]
a00c97e0:  40 01 fd 6e  call  0xa0148d98
a00c97e4:  90 0b 60 01  and  %o5, 1, %o0
a00c97e8:  7f ff bc 39  call  0xa00b88cc
a00c97ec:  01 00 00 00  nop
a00c97f0:  80 a4 20 02  cmp  %l0, 2
a00c97f4:  02 80 00 24  be  0xa00c9884
a00c97f8:  80 a4 20 03  cmp  %l0, 3
a00c97fc:  02 80 00 45  be  0xa00c9910
a00c9800:  9e 10 20 30  mov  0x30, %o7
a00c9804:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9808:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c980c:  82 10 20 35  mov  0x35, %g1
a00c9810:  90 10 20 36  mov  0x36, %o0
a00c9814:  b0 10 20 2b  mov  0x2b, %i0
a00c9818:  98 10 20 0d  mov  0xd, %o4
a00c981c:  c2 2a 60 78  stb  %g1, [ %o1 + 0x78 ]
a00c9820:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c9824:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c9828:  f0 2a a0 04  stb  %i0, [ %o2 + 4 ]
a00c982c:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c9830:  80 a4 20 02  cmp  %l0, 2
a00c9834:  02 80 00 21  be  0xa00c98b8
a00c9838:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c983c:  80 a4 20 03  cmp  %l0, 3
a00c9840:  02 80 00 41  be  0xa00c9944
a00c9844:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c9848:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c984c:  b0 12 20 d0  or  %o0, 0xd0, %i0	! 0xa802d0d0
a00c9850:  c0 2a 60 9c  clrb  [ %o1 + 0x9c ]
a00c9854:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00c9858:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c985c:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c9860:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c9864:  80 a4 20 02  cmp  %l0, 2
a00c9868:  02 80 00 1d  be  0xa00c98dc
a00c986c:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c9870:  80 a4 20 03  cmp  %l0, 3
a00c9874:  12 80 00 1d  bne  0xa00c98e8
a00c9878:  90 10 00 10  mov  %l0, %o0
a00c987c:  10 80 00 3c  b  0xa00c996c
a00c9880:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c9884:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c9888:  a0 13 e1 28  or  %o7, 0x128, %l0	! 0xa802d128
a00c988c:  94 10 20 30  mov  0x30, %o2
a00c9890:  b0 10 20 35  mov  0x35, %i0
a00c9894:  98 10 20 0d  mov  0xd, %o4
a00c9898:  9a 10 20 36  mov  0x36, %o5
a00c989c:  96 10 20 2b  mov  0x2b, %o3
a00c98a0:  f0 2b e1 28  stb  %i0, [ %o7 + 0x128 ]
a00c98a4:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00c98a8:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00c98ac:  d4 2c 20 03  stb  %o2, [ %l0 + 3 ]
a00c98b0:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c98b4:  d4 2c 20 02  stb  %o2, [ %l0 + 2 ]
a00c98b8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c98bc:  a0 12 a0 40  or  %o2, 0x40, %l0	! 0xa802d040
a00c98c0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c98c4:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c98c8:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00c98cc:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c98d0:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c98d4:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c98d8:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c98dc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c98e0:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c98e4:  90 10 20 02  mov  2, %o0
a00c98e8:  40 01 fb c0  call  0xa01487e8
a00c98ec:  92 10 20 06  mov  6, %o1
a00c98f0:  10 80 00 22  b  0xa00c9978
a00c98f4:  b0 10 20 00  clr  %i0
a00c98f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c98fc:  10 bf ff ab  b  0xa00c97a8
a00c9900:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c9904:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9908:  10 bf ff a8  b  0xa00c97a8
a00c990c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c9910:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c9914:  90 12 e1 08  or  %o3, 0x108, %o0	! 0xa802d108
a00c9918:  92 10 20 30  mov  0x30, %o1
a00c991c:  9a 10 20 35  mov  0x35, %o5
a00c9920:  94 10 20 0d  mov  0xd, %o2
a00c9924:  a0 10 20 36  mov  0x36, %l0
a00c9928:  82 10 20 2b  mov  0x2b, %g1
a00c992c:  da 2a e1 08  stb  %o5, [ %o3 + 0x108 ]
a00c9930:  d4 2a 20 05  stb  %o2, [ %o0 + 5 ]
a00c9934:  e0 2a 20 01  stb  %l0, [ %o0 + 1 ]
a00c9938:  d2 2a 20 03  stb  %o1, [ %o0 + 3 ]
a00c993c:  c2 2a 20 04  stb  %g1, [ %o0 + 4 ]
a00c9940:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00c9944:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c9948:  9a 13 e0 98  or  %o7, 0x98, %o5	! 0xa802d098
a00c994c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c9950:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00c9954:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00c9958:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c995c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c9960:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c9964:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c9968:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c996c:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00c9970:  10 bf ff de  b  0xa00c98e8
a00c9974:  90 10 20 03  mov  3, %o0
a00c9978:  81 c7 e0 08  ret
a00c997c:  81 e8 00 00  restore
