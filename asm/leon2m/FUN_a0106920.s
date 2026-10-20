# leon2m FUN_a0106920 0xa0106920-0xa0106b08 (488 bytes)
a0106920:  9d e3 bf 98  save  %sp, -104, %sp
a0106924:  80 8e 20 ff  btst  0xff, %i0
a0106928:  12 80 00 76  bne  0xa0106b00
a010692c:  01 00 00 00  nop
a0106930:  40 00 59 96  call  0xa011cf88
a0106934:  01 00 00 00  nop
a0106938:  90 0a 20 ff  and  %o0, 0xff, %o0
a010693c:  80 a2 20 81  cmp  %o0, 0x81
a0106940:  18 80 00 2b  bgu  0xa01069ec
a0106944:  80 8e 60 ff  btst  0xff, %i1
a0106948:  02 80 00 3f  be  0xa0106a44
a010694c:  01 00 00 00  nop
a0106950:  40 00 59 8e  call  0xa011cf88
a0106954:  01 00 00 00  nop
a0106958:  82 0a 20 ff  and  %o0, 0xff, %g1
a010695c:  80 a0 60 80  cmp  %g1, 0x80
a0106960:  18 80 00 62  bgu  0xa0106ae8
a0106964:  17 33 c0 3c  sethi  %hi(0xcf00f000), %o3
a0106968:  92 10 20 86  mov  0x86, %o1
a010696c:  7f ff ae 3a  call  0xa00f2254
a0106970:  90 10 20 00  clr  %o0
a0106974:  9e 0a 3f f3  and  %o0, -13, %o7
a0106978:  98 13 e0 18  or  %o7, 0x18, %o4
a010697c:  94 0b 20 fb  and  %o4, 0xfb, %o2
a0106980:  90 10 20 00  clr  %o0
a0106984:  7f ff ae 45  call  0xa00f2298
a0106988:  92 10 20 86  mov  0x86, %o1
a010698c:  40 00 0f b6  call  0xa010a864
a0106990:  01 00 00 00  nop
a0106994:  80 8a 20 ff  btst  0xff, %o0
a0106998:  12 80 00 5a  bne  0xa0106b00
a010699c:  90 10 20 00  clr  %o0
a01069a0:  7f ff ae 2d  call  0xa00f2254
a01069a4:  92 10 20 7d  mov  0x7d, %o1
a01069a8:  80 8a 20 20  btst  0x20, %o0
a01069ac:  12 80 00 55  bne  0xa0106b00
a01069b0:  90 10 20 00  clr  %o0
a01069b4:  33 33 c0 3b  sethi  %hi(0xcf00ec00), %i1
a01069b8:  92 10 20 7d  mov  0x7d, %o1
a01069bc:  94 10 20 20  mov  0x20, %o2
a01069c0:  7f ff ae 5b  call  0xa00f232c
a01069c4:  96 10 20 01  mov  1, %o3
a01069c8:  b4 16 61 58  or  %i1, 0x158, %i2
a01069cc:  d0 06 80 00  ld  [ %i2 ], %o0
a01069d0:  b6 0a 3f ef  and  %o0, -17, %i3
a01069d4:  f6 26 80 00  st  %i3, [ %i2 ]
a01069d8:  9a 16 61 84  or  %i1, 0x184, %o5
a01069dc:  f0 03 40 00  ld  [ %o5 ], %i0
a01069e0:  82 0e 3f fe  and  %i0, -2, %g1
a01069e4:  c2 23 40 00  st  %g1, [ %o5 ]
a01069e8:  30 80 00 46  b,a   0xa0106b00
a01069ec:  02 80 00 0d  be  0xa0106a20
a01069f0:  90 10 20 00  clr  %o0
a01069f4:  92 10 20 86  mov  0x86, %o1
a01069f8:  94 10 20 08  mov  8, %o2
a01069fc:  7f ff ae 4c  call  0xa00f232c
a0106a00:  96 10 20 01  mov  1, %o3
a0106a04:  67 fe 19 e7  call  0x4008d1a0
a0106a08:  90 10 20 50  mov  0x50, %o0
a0106a0c:  b0 10 20 00  clr  %i0
a0106a10:  b2 10 20 86  mov  0x86, %i1
a0106a14:  b4 10 20 10  mov  0x10, %i2
a0106a18:  7f ff ae 45  call  0xa00f232c
a0106a1c:  97 e8 20 01  restore  %g0, 1, %o3
a0106a20:  92 10 20 86  mov  0x86, %o1
a0106a24:  94 10 20 08  mov  8, %o2
a0106a28:  7f ff ae 41  call  0xa00f232c
a0106a2c:  96 10 20 00  clr  %o3
a0106a30:  b0 10 20 00  clr  %i0
a0106a34:  b2 10 20 86  mov  0x86, %i1
a0106a38:  b4 10 20 10  mov  0x10, %i2
a0106a3c:  7f ff ae 3c  call  0xa00f232c
a0106a40:  97 e8 20 00  restore  %g0, 0, %o3
a0106a44:  40 00 59 51  call  0xa011cf88
a0106a48:  01 00 00 00  nop
a0106a4c:  82 0a 20 ff  and  %o0, 0xff, %g1
a0106a50:  80 a0 60 80  cmp  %g1, 0x80
a0106a54:  18 80 00 1f  bgu  0xa0106ad0
a0106a58:  17 33 c0 3c  sethi  %hi(0xcf00f000), %o3
a0106a5c:  92 10 20 86  mov  0x86, %o1
a0106a60:  7f ff ad fd  call  0xa00f2254
a0106a64:  90 10 20 00  clr  %o0
a0106a68:  9e 0a 3f f3  and  %o0, -13, %o7
a0106a6c:  98 13 e0 10  or  %o7, 0x10, %o4
a0106a70:  94 0b 20 f3  and  %o4, 0xf3, %o2
a0106a74:  90 10 20 00  clr  %o0
a0106a78:  7f ff ae 08  call  0xa00f2298
a0106a7c:  92 10 20 86  mov  0x86, %o1
a0106a80:  90 10 20 00  clr  %o0
a0106a84:  7f ff ad f4  call  0xa00f2254
a0106a88:  92 10 20 7d  mov  0x7d, %o1
a0106a8c:  80 8a 20 20  btst  0x20, %o0
a0106a90:  02 80 00 1c  be  0xa0106b00
a0106a94:  90 10 20 00  clr  %o0
a0106a98:  33 33 c0 3b  sethi  %hi(0xcf00ec00), %i1
a0106a9c:  92 10 20 7d  mov  0x7d, %o1
a0106aa0:  94 10 20 20  mov  0x20, %o2
a0106aa4:  7f ff ae 22  call  0xa00f232c
a0106aa8:  96 10 20 00  clr  %o3
a0106aac:  b4 16 61 58  or  %i1, 0x158, %i2
a0106ab0:  d0 06 80 00  ld  [ %i2 ], %o0
a0106ab4:  b6 12 20 10  or  %o0, 0x10, %i3
a0106ab8:  f6 26 80 00  st  %i3, [ %i2 ]
a0106abc:  9a 16 61 84  or  %i1, 0x184, %o5
a0106ac0:  f0 03 40 00  ld  [ %o5 ], %i0
a0106ac4:  82 16 20 01  or  %i0, 1, %g1
a0106ac8:  c2 23 40 00  st  %g1, [ %o5 ]
a0106acc:  30 80 00 0d  b,a   0xa0106b00
a0106ad0:  9a 12 e1 c0  or  %o3, 0x1c0, %o5
a0106ad4:  d4 03 40 00  ld  [ %o5 ], %o2
a0106ad8:  92 0a bf fe  and  %o2, -2, %o1
a0106adc:  d2 23 40 00  st  %o1, [ %o5 ]
a0106ae0:  10 bf ff e0  b  0xa0106a60
a0106ae4:  92 10 20 86  mov  0x86, %o1
a0106ae8:  9a 12 e1 c0  or  %o3, 0x1c0, %o5
a0106aec:  d4 03 40 00  ld  [ %o5 ], %o2
a0106af0:  92 12 a0 01  or  %o2, 1, %o1
a0106af4:  d2 23 40 00  st  %o1, [ %o5 ]
a0106af8:  10 bf ff 9d  b  0xa010696c
a0106afc:  92 10 20 86  mov  0x86, %o1
a0106b00:  81 c7 e0 08  ret
a0106b04:  81 e8 00 00  restore
