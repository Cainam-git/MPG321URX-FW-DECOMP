# leon2m FUN_a0105910 0xa0105910-0xa0105a3c (300 bytes)
a0105910:  9d e3 bf 98  save  %sp, -104, %sp
a0105914:  a4 10 00 19  mov  %i1, %l2
a0105918:  83 2e a0 10  sll  %i2, 0x10, %g1
a010591c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0105920:  b3 30 60 10  srl  %g1, 0x10, %i1
a0105924:  92 10 20 64  mov  0x64, %o1
a0105928:  90 10 00 11  mov  %l1, %o0
a010592c:  80 a4 60 03  cmp  %l1, 3
a0105930:  94 10 00 19  mov  %i1, %o2
a0105934:  18 80 00 40  bgu  0xa0105a34
a0105938:  f0 0f a0 5f  ldub  [ %fp + 0x5f ], %i0
a010593c:  7f ff b2 d3  call  0xa00f2488
a0105940:  a7 2c a0 10  sll  %l2, 0x10, %l3
a0105944:  a9 34 e0 10  srl  %l3, 0x10, %l4
a0105948:  90 10 00 11  mov  %l1, %o0
a010594c:  92 10 20 68  mov  0x68, %o1
a0105950:  7f ff b2 ce  call  0xa00f2488
a0105954:  94 10 00 14  mov  %l4, %o2
a0105958:  83 2e e0 10  sll  %i3, 0x10, %g1
a010595c:  a7 30 60 10  srl  %g1, 0x10, %l3
a0105960:  90 10 00 11  mov  %l1, %o0
a0105964:  92 10 20 66  mov  0x66, %o1
a0105968:  7f ff b2 c8  call  0xa00f2488
a010596c:  94 10 00 13  mov  %l3, %o2
a0105970:  9f 2f 20 10  sll  %i4, 0x10, %o7
a0105974:  a1 33 e0 10  srl  %o7, 0x10, %l0
a0105978:  94 10 00 10  mov  %l0, %o2
a010597c:  90 10 00 11  mov  %l1, %o0
a0105980:  7f ff b2 c2  call  0xa00f2488
a0105984:  92 10 20 62  mov  0x62, %o1
a0105988:  9b 2f 60 10  sll  %i5, 0x10, %o5
a010598c:  95 33 60 10  srl  %o5, 0x10, %o2
a0105990:  90 10 00 11  mov  %l1, %o0
a0105994:  7f ff b2 bd  call  0xa00f2488
a0105998:  92 10 20 a0  mov  0xa0, %o1
a010599c:  94 0e 20 ff  and  %i0, 0xff, %o2
a01059a0:  90 10 00 11  mov  %l1, %o0
a01059a4:  7f ff b2 b9  call  0xa00f2488
a01059a8:  92 10 20 be  mov  0xbe, %o1
a01059ac:  92 10 20 5b  mov  0x5b, %o1
a01059b0:  7f ff b3 12  call  0xa00f25f8
a01059b4:  90 10 00 11  mov  %l1, %o0
a01059b8:  98 06 80 1c  add  %i2, %i4, %o4
a01059bc:  97 2a 20 10  sll  %o0, 0x10, %o3
a01059c0:  92 03 20 10  add  %o4, 0x10, %o1
a01059c4:  a0 06 40 10  add  %i1, %l0, %l0
a01059c8:  91 32 e0 10  srl  %o3, 0x10, %o0
a01059cc:  95 2a 60 10  sll  %o1, 0x10, %o2
a01059d0:  80 a2 00 10  cmp  %o0, %l0
a01059d4:  b0 10 00 11  mov  %l1, %i0
a01059d8:  b2 10 20 5e  mov  0x5e, %i1
a01059dc:  95 32 a0 10  srl  %o2, 0x10, %o2
a01059e0:  90 10 00 11  mov  %l1, %o0
a01059e4:  04 80 00 10  ble  0xa0105a24
a01059e8:  92 10 20 5b  mov  0x5b, %o1
a01059ec:  90 10 00 11  mov  %l1, %o0
a01059f0:  92 10 20 5e  mov  0x5e, %o1
a01059f4:  7f ff b3 01  call  0xa00f25f8
a01059f8:  ba 04 80 1b  add  %l2, %i3, %i5
a01059fc:  b8 07 60 10  add  %i5, 0x10, %i4
a0105a00:  b7 2a 20 10  sll  %o0, 0x10, %i3
a0105a04:  b5 2f 20 10  sll  %i4, 0x10, %i2
a0105a08:  a2 05 00 13  add  %l4, %l3, %l1
a0105a0c:  a5 36 e0 10  srl  %i3, 0x10, %l2
a0105a10:  80 a4 80 11  cmp  %l2, %l1
a0105a14:  14 80 00 08  bg  0xa0105a34
a0105a18:  b5 36 a0 10  srl  %i2, 0x10, %i2
a0105a1c:  7f ff b2 9b  call  0xa00f2488
a0105a20:  81 e8 00 00  restore
a0105a24:  7f ff b2 99  call  0xa00f2488
a0105a28:  01 00 00 00  nop
a0105a2c:  10 bf ff f1  b  0xa01059f0
a0105a30:  90 10 00 11  mov  %l1, %o0
a0105a34:  81 c7 e0 08  ret
a0105a38:  81 e8 00 00  restore
