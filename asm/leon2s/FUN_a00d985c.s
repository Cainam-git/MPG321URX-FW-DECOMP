# leon2s FUN_a00d985c 0xa00d985c-0xa00d9988 (300 bytes)
a00d985c:  9d e3 bf 98  save  %sp, -104, %sp
a00d9860:  7f ff ff 61  call  0xa00d95e4
a00d9864:  01 00 00 00  nop
a00d9868:  90 02 3f f0  add  %o0, -16, %o0
a00d986c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9870:  80 a2 20 01  cmp  %o0, 1
a00d9874:  18 80 00 05  bgu  0xa00d9888
a00d9878:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d987c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9880:  c0 28 60 47  clrb  [ %g1 + 0x47 ]	! 0xa8078847
a00d9884:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9888:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4	! 0xa8078832
a00d988c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9890:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00d9894:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00d9898:  9a 03 00 0c  add  %o4, %o4, %o5
a00d989c:  82 08 60 0f  and  %g1, 0xf, %g1
a00d98a0:  9a 03 40 0c  add  %o5, %o4, %o5
a00d98a4:  98 00 40 01  add  %g1, %g1, %o4
a00d98a8:  98 03 00 01  add  %o4, %g1, %o4
a00d98ac:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00d98b0:  9b 2b 60 08  sll  %o5, 8, %o5
a00d98b4:  82 10 62 3d  or  %g1, 0x23d, %g1
a00d98b8:  90 03 40 01  add  %o5, %g1, %o0
a00d98bc:  93 2b 20 04  sll  %o4, 4, %o1
a00d98c0:  da 0a 00 09  ldub  [ %o0 + %o1 ], %o5
a00d98c4:  9b 33 60 04  srl  %o5, 4, %o5
a00d98c8:  9a 03 7f ff  add  %o5, -1, %o5
a00d98cc:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a00d98d0:  83 33 60 1f  srl  %o5, 0x1f, %g1
a00d98d4:  82 03 40 01  add  %o5, %g1, %g1
a00d98d8:  d8 0c e3 ff  ldub  [ %l3 + 0x3ff ], %o4
a00d98dc:  98 0b 20 0f  and  %o4, 0xf, %o4
a00d98e0:  97 38 60 01  sra  %g1, 1, %o3
a00d98e4:  82 03 00 0c  add  %o4, %o4, %g1
a00d98e8:  a4 00 40 0c  add  %g1, %o4, %l2
a00d98ec:  80 8b 60 01  btst  1, %o5
a00d98f0:  02 80 00 03  be  0xa00d98fc
a00d98f4:  94 10 00 0b  mov  %o3, %o2
a00d98f8:  94 02 e0 01  add  %o3, 1, %o2
a00d98fc:  82 02 00 09  add  %o0, %o1, %g1
a00d9900:  a2 0a a0 ff  and  %o2, 0xff, %l1
a00d9904:  98 00 40 11  add  %g1, %l1, %o4
a00d9908:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a00d990c:  a0 08 60 3f  and  %g1, 0x3f, %l0
a00d9910:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00d9914:  80 a3 e0 00  cmp  %o7, 0
a00d9918:  02 80 00 11  be  0xa00d995c
a00d991c:  96 10 20 00  clr  %o3
a00d9920:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00d9924:  9b 2c a0 04  sll  %l2, 4, %o5
a00d9928:  82 10 61 20  or  %g1, 0x120, %g1
a00d992c:  90 03 40 01  add  %o5, %g1, %o0
a00d9930:  92 10 00 0c  mov  %o4, %o1
a00d9934:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d9938:  9a 02 40 01  add  %o1, %g1, %o5
a00d993c:  82 02 00 01  add  %o0, %g1, %g1
a00d9940:  96 02 e0 01  inc  %o3
a00d9944:  82 00 40 11  add  %g1, %l1, %g1
a00d9948:  da 0b 60 03  ldub  [ %o5 + 3 ], %o5
a00d994c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d9950:  80 a3 00 0f  cmp  %o4, %o7
a00d9954:  0a bf ff f8  bcs  0xa00d9934
a00d9958:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a00d995c:  d6 0c e3 ff  ldub  [ %l3 + 0x3ff ], %o3
a00d9960:  9a 02 80 10  add  %o2, %l0, %o5
a00d9964:  98 02 e0 01  add  %o3, 1, %o4
a00d9968:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d996c:  9a 03 60 03  add  %o5, 3, %o5
a00d9970:  98 0b 20 0f  and  %o4, 0xf, %o4
a00d9974:  82 10 60 88  or  %g1, 0x88, %g1
a00d9978:  da 28 40 0b  stb  %o5, [ %g1 + %o3 ]
a00d997c:  d8 2c e3 ff  stb  %o4, [ %l3 + 0x3ff ]
a00d9980:  81 c7 e0 08  ret
a00d9984:  81 e8 00 00  restore
