# leon2m FUN_a0149978 0xa0149978-0xa0149b8c (532 bytes)
a0149978:  9d e3 bf 98  save  %sp, -104, %sp
a014997c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0149980:  80 a6 20 01  cmp  %i0, 1
a0149984:  02 80 00 0b  be  0xa01499b0
a0149988:  82 10 20 01  mov  1, %g1
a014998c:  80 a6 20 01  cmp  %i0, 1
a0149990:  04 80 00 50  ble  0xa0149ad0
a0149994:  80 a6 20 02  cmp  %i0, 2
a0149998:  02 80 00 06  be  0xa01499b0
a014999c:  82 10 20 02  mov  2, %g1
a01499a0:  80 a6 20 03  cmp  %i0, 3
a01499a4:  02 80 00 03  be  0xa01499b0
a01499a8:  82 10 20 03  mov  3, %g1
a01499ac:  82 10 3f ff  mov  -1, %g1
a01499b0:  b0 08 60 ff  and  %g1, 0xff, %i0
a01499b4:  80 a6 20 03  cmp  %i0, 3
a01499b8:  38 80 00 42  bgu,a   0xa0149ac0
a01499bc:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01499c0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01499c4:  7f ff 6d f5  call  0xa0125198
a01499c8:  90 10 00 19  mov  %i1, %o0
a01499cc:  7f ff e2 13  call  0xa0142218
a01499d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01499d4:  7f ff e1 fc  call  0xa01421c4
a01499d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a01499dc:  92 0a 20 ff  and  %o0, 0xff, %o1
a01499e0:  90 10 00 18  mov  %i0, %o0
a01499e4:  7f ff 96 96  call  0xa012f43c
a01499e8:  94 10 20 00  clr  %o2
a01499ec:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a01499f0:  da 04 23 d0  ld  [ %l0 + 0x3d0 ], %o5	! 0xa802e3d0
a01499f4:  03 00 20 00  sethi  %hi(0x800000), %g1
a01499f8:  80 8b 40 01  btst  %o5, %g1
a01499fc:  12 80 00 18  bne  0xa0149a5c
a0149a00:  a2 14 23 d0  or  %l0, 0x3d0, %l1
a0149a04:  80 a6 20 00  cmp  %i0, 0
a0149a08:  12 80 00 11  bne  0xa0149a4c
a0149a0c:  80 a6 20 03  cmp  %i0, 3
a0149a10:  e2 04 23 d0  ld  [ %l0 + 0x3d0 ], %l1
a0149a14:  21 00 08 00  sethi  %hi(0x200000), %l0
a0149a18:  80 8c 40 10  btst  %l1, %l0
a0149a1c:  12 80 00 32  bne  0xa0149ae4
a0149a20:  01 00 00 00  nop
a0149a24:  95 2e 20 04  sll  %i0, 4, %o2
a0149a28:  82 22 80 18  sub  %o2, %i0, %g1
a0149a2c:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a0149a30:  91 28 60 03  sll  %g1, 3, %o0
a0149a34:  9a 12 63 30  or  %o1, 0x330, %o5
a0149a38:  f2 03 40 08  ld  [ %o5 + %o0 ], %i1
a0149a3c:  b1 36 60 0c  srl  %i1, 0xc, %i0
a0149a40:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0149a44:  7f ff e5 19  call  0xa0142ea8
a0149a48:  81 e8 00 00  restore
a0149a4c:  18 80 00 4e  bgu  0xa0149b84
a0149a50:  95 2e 20 04  sll  %i0, 4, %o2
a0149a54:  10 bf ff f6  b  0xa0149a2c
a0149a58:  82 22 80 18  sub  %o2, %i0, %g1
a0149a5c:  7f ff 6d cf  call  0xa0125198
a0149a60:  90 10 00 19  mov  %i1, %o0
a0149a64:  7f ff e1 ed  call  0xa0142218
a0149a68:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149a6c:  7f ff e1 d6  call  0xa01421c4
a0149a70:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149a74:  92 0a 20 ff  and  %o0, 0xff, %o1
a0149a78:  80 a2 60 71  cmp  %o1, 0x71
a0149a7c:  12 bf ff e3  bne  0xa0149a08
a0149a80:  80 a6 20 00  cmp  %i0, 0
a0149a84:  80 a6 20 01  cmp  %i0, 1
a0149a88:  22 80 00 3a  be,a   0xa0149b70
a0149a8c:  d6 0c 60 1f  ldub  [ %l1 + 0x1f ], %o3
a0149a90:  04 80 00 2f  ble  0xa0149b4c
a0149a94:  80 a6 20 02  cmp  %i0, 2
a0149a98:  02 80 00 27  be  0xa0149b34
a0149a9c:  80 a6 20 03  cmp  %i0, 3
a0149aa0:  12 bf ff da  bne  0xa0149a08
a0149aa4:  80 a6 20 00  cmp  %i0, 0
a0149aa8:  de 0c 60 21  ldub  [ %l1 + 0x21 ], %o7
a0149aac:  92 0b e0 03  and  %o7, 3, %o1
a0149ab0:  7f ff a3 89  call  0xa01328d4
a0149ab4:  90 10 20 03  mov  3, %o0
a0149ab8:  10 bf ff dc  b  0xa0149a28
a0149abc:  95 2e 20 04  sll  %i0, 4, %o2
a0149ac0:  7f fe 55 ac  call  0xa00df170
a0149ac4:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0149ac8:  10 bf ff be  b  0xa01499c0
a0149acc:  b0 10 20 00  clr  %i0
a0149ad0:  80 a6 20 00  cmp  %i0, 0
a0149ad4:  02 bf ff b7  be  0xa01499b0
a0149ad8:  82 10 20 00  clr  %g1
a0149adc:  10 bf ff b5  b  0xa01499b0
a0149ae0:  82 10 3f ff  mov  -1, %g1
a0149ae4:  7f ff 6d ad  call  0xa0125198
a0149ae8:  90 10 00 19  mov  %i1, %o0
a0149aec:  7f ff e1 cb  call  0xa0142218
a0149af0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149af4:  7f ff e1 b4  call  0xa01421c4
a0149af8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149afc:  92 0a 20 ff  and  %o0, 0xff, %o1
a0149b00:  90 10 20 03  mov  3, %o0
a0149b04:  7f ff 96 4e  call  0xa012f43c
a0149b08:  94 10 20 00  clr  %o2
a0149b0c:  95 2e 20 04  sll  %i0, 4, %o2
a0149b10:  82 22 80 18  sub  %o2, %i0, %g1
a0149b14:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a0149b18:  91 28 60 03  sll  %g1, 3, %o0
a0149b1c:  9a 12 63 30  or  %o1, 0x330, %o5
a0149b20:  f2 03 40 08  ld  [ %o5 + %o0 ], %i1
a0149b24:  b1 36 60 0c  srl  %i1, 0xc, %i0
a0149b28:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0149b2c:  7f ff e4 df  call  0xa0142ea8
a0149b30:  81 e8 00 00  restore
a0149b34:  d8 0c 60 20  ldub  [ %l1 + 0x20 ], %o4
a0149b38:  92 0b 20 03  and  %o4, 3, %o1
a0149b3c:  7f ff a3 66  call  0xa01328d4
a0149b40:  90 10 20 02  mov  2, %o0
a0149b44:  10 bf ff b9  b  0xa0149a28
a0149b48:  95 2e 20 04  sll  %i0, 4, %o2
a0149b4c:  80 a6 20 00  cmp  %i0, 0
a0149b50:  12 bf ff bf  bne  0xa0149a4c
a0149b54:  80 a6 20 03  cmp  %i0, 3
a0149b58:  d4 0c 60 1e  ldub  [ %l1 + 0x1e ], %o2
a0149b5c:  92 0a a0 03  and  %o2, 3, %o1
a0149b60:  7f ff a3 5d  call  0xa01328d4
a0149b64:  90 10 20 00  clr  %o0
a0149b68:  10 bf ff ab  b  0xa0149a14
a0149b6c:  e2 04 23 d0  ld  [ %l0 + 0x3d0 ], %l1
a0149b70:  92 0a e0 03  and  %o3, 3, %o1
a0149b74:  7f ff a3 58  call  0xa01328d4
a0149b78:  90 10 20 01  mov  1, %o0
a0149b7c:  10 bf ff ab  b  0xa0149a28
a0149b80:  95 2e 20 04  sll  %i0, 4, %o2
a0149b84:  81 c7 e0 08  ret
a0149b88:  81 e8 00 00  restore
