# leon2s FUN_a00d791c 0xa00d791c-0xa00d7bf8 (732 bytes)
a00d791c:  9d e3 be 98  save  %sp, -360, %sp
a00d7920:  83 2f 20 10  sll  %i4, 0x10, %g1
a00d7924:  83 30 60 10  srl  %g1, 0x10, %g1
a00d7928:  90 10 00 18  mov  %i0, %o0
a00d792c:  80 a0 60 00  cmp  %g1, 0
a00d7930:  b0 10 20 00  clr  %i0
a00d7934:  02 80 00 0b  be  0xa00d7960
a00d7938:  94 10 20 00  clr  %o2
a00d793c:  98 10 00 01  mov  %g1, %o4
a00d7940:  96 07 bf f8  add  %fp, -8, %o3
a00d7944:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d7948:  94 02 a0 01  inc  %o2
a00d794c:  82 02 c0 01  add  %o3, %g1, %g1
a00d7950:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00d7954:  80 a3 40 0c  cmp  %o5, %o4
a00d7958:  0a bf ff fb  bcs  0xa00d7944
a00d795c:  c0 28 7f 00  clrb  [ %g1 + -256 ]
a00d7960:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00d7964:  80 a6 e0 08  cmp  %i3, 8
a00d7968:  02 80 00 4b  be  0xa00d7a94
a00d796c:  01 00 00 00  nop
a00d7970:  14 80 00 16  bg  0xa00d79c8
a00d7974:  80 a6 e0 0c  cmp  %i3, 0xc
a00d7978:  80 a6 e0 02  cmp  %i3, 2
a00d797c:  02 80 00 36  be  0xa00d7a54
a00d7980:  01 00 00 00  nop
a00d7984:  14 80 00 09  bg  0xa00d79a8
a00d7988:  80 a6 e0 06  cmp  %i3, 6
a00d798c:  80 a6 e0 00  cmp  %i3, 0
a00d7990:  02 80 00 25  be  0xa00d7a24
a00d7994:  80 a6 e0 01  cmp  %i3, 1
a00d7998:  02 80 00 27  be  0xa00d7a34
a00d799c:  82 0e 60 ff  and  %i1, 0xff, %g1
a00d79a0:  10 80 00 5a  b  0xa00d7b08
a00d79a4:  80 a0 60 02  cmp  %g1, 2
a00d79a8:  02 80 00 33  be  0xa00d7a74
a00d79ac:  80 a6 e0 06  cmp  %i3, 6
a00d79b0:  14 80 00 35  bg  0xa00d7a84
a00d79b4:  80 a6 e0 03  cmp  %i3, 3
a00d79b8:  02 80 00 2b  be  0xa00d7a64
a00d79bc:  82 0e 60 ff  and  %i1, 0xff, %g1
a00d79c0:  10 80 00 52  b  0xa00d7b08
a00d79c4:  80 a0 60 02  cmp  %g1, 2
a00d79c8:  02 80 00 43  be  0xa00d7ad4
a00d79cc:  80 a6 e0 0c  cmp  %i3, 0xc
a00d79d0:  14 80 00 08  bg  0xa00d79f0
a00d79d4:  80 a6 e0 11  cmp  %i3, 0x11
a00d79d8:  80 a6 e0 0a  cmp  %i3, 0xa
a00d79dc:  02 80 00 36  be  0xa00d7ab4
a00d79e0:  01 00 00 00  nop
a00d79e4:  14 80 00 38  bg  0xa00d7ac4
a00d79e8:  01 00 00 00  nop
a00d79ec:  30 80 00 2e  b,a   0xa00d7aa4
a00d79f0:  02 80 00 15  be  0xa00d7a44
a00d79f4:  80 a6 e0 11  cmp  %i3, 0x11
a00d79f8:  14 80 00 07  bg  0xa00d7a14
a00d79fc:  80 a6 e0 38  cmp  %i3, 0x38
a00d7a00:  80 a6 e0 0f  cmp  %i3, 0xf
a00d7a04:  02 80 00 3c  be  0xa00d7af4
a00d7a08:  82 0e 60 ff  and  %i1, 0xff, %g1
a00d7a0c:  10 80 00 3f  b  0xa00d7b08
a00d7a10:  80 a0 60 02  cmp  %g1, 2
a00d7a14:  02 80 00 34  be  0xa00d7ae4
a00d7a18:  82 0e 60 ff  and  %i1, 0xff, %g1
a00d7a1c:  10 80 00 3b  b  0xa00d7b08
a00d7a20:  80 a0 60 02  cmp  %g1, 2
a00d7a24:  7f ff fe b2  call  0xa00d74ec
a00d7a28:  92 07 be f8  add  %fp, -264, %o1
a00d7a2c:  10 80 00 35  b  0xa00d7b00
a00d7a30:  b0 10 20 00  clr  %i0
a00d7a34:  7f ff ff 01  call  0xa00d7638
a00d7a38:  92 07 be f8  add  %fp, -264, %o1
a00d7a3c:  10 80 00 31  b  0xa00d7b00
a00d7a40:  b0 10 20 00  clr  %i0
a00d7a44:  7f ff ff 01  call  0xa00d7648
a00d7a48:  92 07 be f8  add  %fp, -264, %o1
a00d7a4c:  10 80 00 2d  b  0xa00d7b00
a00d7a50:  b0 10 20 01  mov  1, %i0
a00d7a54:  7f ff ff 16  call  0xa00d76ac
a00d7a58:  92 07 be f8  add  %fp, -264, %o1
a00d7a5c:  10 80 00 29  b  0xa00d7b00
a00d7a60:  b0 10 20 00  clr  %i0
a00d7a64:  7f ff ff 24  call  0xa00d76f4
a00d7a68:  92 07 be f8  add  %fp, -264, %o1
a00d7a6c:  10 80 00 25  b  0xa00d7b00
a00d7a70:  b0 10 20 00  clr  %i0
a00d7a74:  7f ff ff 30  call  0xa00d7734
a00d7a78:  92 07 be f8  add  %fp, -264, %o1
a00d7a7c:  10 80 00 21  b  0xa00d7b00
a00d7a80:  b0 10 20 00  clr  %i0
a00d7a84:  7f ff ff 30  call  0xa00d7744
a00d7a88:  92 07 be f8  add  %fp, -264, %o1
a00d7a8c:  10 80 00 1d  b  0xa00d7b00
a00d7a90:  b0 10 20 00  clr  %i0
a00d7a94:  7f ff ff 45  call  0xa00d77a8
a00d7a98:  92 07 be f8  add  %fp, -264, %o1
a00d7a9c:  10 80 00 19  b  0xa00d7b00
a00d7aa0:  b0 10 20 00  clr  %i0
a00d7aa4:  7f ff ff 48  call  0xa00d77c4
a00d7aa8:  92 07 be f8  add  %fp, -264, %o1
a00d7aac:  10 80 00 15  b  0xa00d7b00
a00d7ab0:  b0 10 20 00  clr  %i0
a00d7ab4:  7f ff ff 5d  call  0xa00d7828
a00d7ab8:  92 07 be f8  add  %fp, -264, %o1
a00d7abc:  10 80 00 11  b  0xa00d7b00
a00d7ac0:  b0 10 20 00  clr  %i0
a00d7ac4:  7f ff ff 60  call  0xa00d7844
a00d7ac8:  92 07 be f8  add  %fp, -264, %o1
a00d7acc:  10 80 00 0d  b  0xa00d7b00
a00d7ad0:  b0 10 20 00  clr  %i0
a00d7ad4:  7f ff ff 63  call  0xa00d7860
a00d7ad8:  92 07 be f8  add  %fp, -264, %o1
a00d7adc:  10 80 00 09  b  0xa00d7b00
a00d7ae0:  b0 10 20 00  clr  %i0
a00d7ae4:  7f ff ff 66  call  0xa00d787c
a00d7ae8:  92 07 be f8  add  %fp, -264, %o1
a00d7aec:  10 80 00 05  b  0xa00d7b00
a00d7af0:  b0 10 20 00  clr  %i0
a00d7af4:  7f ff ff 79  call  0xa00d78d8
a00d7af8:  92 07 be f8  add  %fp, -264, %o1
a00d7afc:  b0 10 20 00  clr  %i0
a00d7b00:  82 0e 60 ff  and  %i1, 0xff, %g1
a00d7b04:  80 a0 60 02  cmp  %g1, 2
a00d7b08:  12 80 00 3a  bne  0xa00d7bf0
a00d7b0c:  82 0e a0 ff  and  %i2, 0xff, %g1
a00d7b10:  80 a0 60 01  cmp  %g1, 1
a00d7b14:  12 80 00 37  bne  0xa00d7bf0
a00d7b18:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7b1c:  d6 08 60 32  ldub  [ %g1 + 0x32 ], %o3	! 0xa8078832
a00d7b20:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00d7b24:  82 10 60 f8  or  %g1, 0xf8, %g1	! 0xa807a4f8
a00d7b28:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00d7b2c:  9b 2a e0 04  sll  %o3, 4, %o5
a00d7b30:  9a 03 40 01  add  %o5, %g1, %o5
a00d7b34:  b7 2f 20 10  sll  %i4, 0x10, %i3
a00d7b38:  98 14 20 08  or  %l0, 8, %o4
a00d7b3c:  c2 0b 00 0b  ldub  [ %o4 + %o3 ], %g1
a00d7b40:  91 36 e0 10  srl  %i3, 0x10, %o0
a00d7b44:  f8 2b 40 01  stb  %i4, [ %o5 + %g1 ]
a00d7b48:  80 a2 20 00  cmp  %o0, 0
a00d7b4c:  02 80 00 15  be  0xa00d7ba0
a00d7b50:  94 10 20 00  clr  %o2
a00d7b54:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7b58:  9a 02 c0 0b  add  %o3, %o3, %o5
a00d7b5c:  82 10 60 0e  or  %g1, 0xe, %g1
a00d7b60:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a00d7b64:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d7b68:  99 2a e0 09  sll  %o3, 9, %o4
a00d7b6c:  82 10 63 98  or  %g1, 0x398, %g1
a00d7b70:  96 03 00 01  add  %o4, %g1, %o3
a00d7b74:  9e 07 bf f8  add  %fp, -8, %o7
a00d7b78:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d7b7c:  9a 03 c0 01  add  %o7, %g1, %o5
a00d7b80:  82 02 40 01  add  %o1, %g1, %g1
a00d7b84:  94 02 a0 01  inc  %o2
a00d7b88:  82 08 61 ff  and  %g1, 0x1ff, %g1
a00d7b8c:  da 0b 7f 00  ldub  [ %o5 + -256 ], %o5
a00d7b90:  98 0a a0 ff  and  %o2, 0xff, %o4
a00d7b94:  80 a3 00 08  cmp  %o4, %o0
a00d7b98:  0a bf ff f8  bcs  0xa00d7b78
a00d7b9c:  da 2a c0 01  stb  %o5, [ %o3 + %g1 ]
a00d7ba0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d7ba4:  d2 08 60 32  ldub  [ %g1 + 0x32 ], %o1	! 0xa8078832
a00d7ba8:  15 2a 01 e2  sethi  %hi(0xa8078800), %o2
a00d7bac:  94 12 a0 0e  or  %o2, 0xe, %o2	! 0xa807880e
a00d7bb0:  90 02 40 09  add  %o1, %o1, %o0
a00d7bb4:  83 36 e0 10  srl  %i3, 0x10, %g1
a00d7bb8:  da 12 80 08  lduh  [ %o2 + %o0 ], %o5
a00d7bbc:  a0 14 20 08  or  %l0, 8, %l0
a00d7bc0:  9a 03 40 01  add  %o5, %g1, %o5
a00d7bc4:  de 0c 00 09  ldub  [ %l0 + %o1 ], %o7
a00d7bc8:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d7bcc:  98 03 e0 01  add  %o7, 1, %o4
a00d7bd0:  97 2a 60 04  sll  %o1, 4, %o3
a00d7bd4:  82 10 60 62  or  %g1, 0x62, %g1
a00d7bd8:  96 02 c0 01  add  %o3, %g1, %o3
a00d7bdc:  9a 0b 61 ff  and  %o5, 0x1ff, %o5
a00d7be0:  98 0b 20 0f  and  %o4, 0xf, %o4
a00d7be4:  da 32 80 08  sth  %o5, [ %o2 + %o0 ]
a00d7be8:  d8 2c 00 09  stb  %o4, [ %l0 + %o1 ]
a00d7bec:  f0 2a c0 0f  stb  %i0, [ %o3 + %o7 ]
a00d7bf0:  81 c7 e0 08  ret
a00d7bf4:  81 e8 00 00  restore
