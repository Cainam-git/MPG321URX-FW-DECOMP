# leon2m FUN_a00a5908 0xa00a5908-0xa00a5e68 (1376 bytes)  [FUN_a00a5e60 = unreachable ret/restore tail, merged]
a00a5908:  9d e3 bf 60  save  %sp, -160, %sp
a00a590c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a5910:  82 10 20 11  mov  0x11, %g1
a00a5914:  f4 27 bf cc  st  %i2, [ %fp + -52 ]
a00a5918:  f2 37 bf ee  sth  %i1, [ %fp + -18 ]
a00a591c:  80 a6 a0 02  cmp  %i2, 2
a00a5920:  f0 37 bf f6  sth  %i0, [ %fp + -10 ]
a00a5924:  c2 2f bf e7  stb  %g1, [ %fp + -25 ]
a00a5928:  02 80 00 14  be  0xa00a5978
a00a592c:  b7 2e 20 10  sll  %i0, 0x10, %i3
a00a5930:  90 10 20 16  mov  0x16, %o0
a00a5934:  d0 2f bf e7  stb  %o0, [ %fp + -25 ]
a00a5938:  a0 10 20 00  clr  %l0
a00a593c:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a5940:  da 17 bf ee  lduh  [ %fp + -18 ], %o5
a00a5944:  96 03 00 0d  add  %o4, %o5, %o3
a00a5948:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a594c:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a5950:  91 36 e0 10  srl  %i3, 0x10, %o0
a00a5954:  94 10 20 16  mov  0x16, %o2
a00a5958:  96 10 27 96  mov  0x796, %o3
a00a595c:  40 02 84 49  call  0xa0146a80
a00a5960:  98 10 20 00  clr  %o4
a00a5964:  a0 04 20 01  inc  %l0
a00a5968:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a596c:  80 a2 60 16  cmp  %o1, 0x16
a00a5970:  0a bf ff f4  bcs  0xa00a5940
a00a5974:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a5978:  d8 17 bf f6  lduh  [ %fp + -10 ], %o4
a00a597c:  da 17 bf ee  lduh  [ %fp + -18 ], %o5
a00a5980:  a2 03 20 02  add  %o4, 2, %l1
a00a5984:  ab 2c 60 10  sll  %l1, 0x10, %l5
a00a5988:  ba 03 60 02  add  %o5, 2, %i5
a00a598c:  ac 10 00 0d  mov  %o5, %l6
a00a5990:  ab 35 60 10  srl  %l5, 0x10, %l5
a00a5994:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00a5998:  a8 10 20 09  mov  9, %l4
a00a599c:  96 10 00 15  mov  %l5, %o3
a00a59a0:  98 10 00 1d  mov  %i5, %o4
a00a59a4:  e8 23 a0 5c  st  %l4, [ %sp + 0x5c ]
a00a59a8:  90 10 20 01  mov  1, %o0
a00a59ac:  92 10 20 01  mov  1, %o1
a00a59b0:  94 10 25 92  mov  0x592, %o2
a00a59b4:  40 00 36 4c  call  0xa00b32e4
a00a59b8:  9a 10 20 02  mov  2, %o5
a00a59bc:  d6 0f bf e7  ldub  [ %fp + -25 ], %o3
a00a59c0:  e6 17 bf f6  lduh  [ %fp + -10 ], %l3
a00a59c4:  a8 02 c0 16  add  %o3, %l6, %l4
a00a59c8:  a0 04 e0 01  add  %l3, 1, %l0
a00a59cc:  af 2c 20 10  sll  %l0, 0x10, %l7
a00a59d0:  b2 05 3f fb  add  %l4, -5, %i1
a00a59d4:  af 35 e0 10  srl  %l7, 0x10, %l7
a00a59d8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a59dc:  b4 10 20 0b  mov  0xb, %i2
a00a59e0:  98 10 00 19  mov  %i1, %o4
a00a59e4:  f4 23 a0 5c  st  %i2, [ %sp + 0x5c ]
a00a59e8:  90 10 20 01  mov  1, %o0
a00a59ec:  92 10 20 00  clr  %o1
a00a59f0:  94 10 25 92  mov  0x592, %o2
a00a59f4:  96 10 00 17  mov  %l7, %o3
a00a59f8:  40 00 36 3b  call  0xa00b32e4
a00a59fc:  9a 10 20 01  mov  1, %o5
a00a5a00:  d4 17 bf f6  lduh  [ %fp + -10 ], %o2
a00a5a04:  92 05 3f fc  add  %l4, -4, %o1
a00a5a08:  b8 02 a0 04  add  %o2, 4, %i4
a00a5a0c:  b0 0a 60 ff  and  %o1, 0xff, %i0
a00a5a10:  a5 2f 20 10  sll  %i4, 0x10, %l2
a00a5a14:  f0 27 bf d8  st  %i0, [ %fp + -40 ]
a00a5a18:  90 10 20 0c  mov  0xc, %o0
a00a5a1c:  b1 34 a0 10  srl  %l2, 0x10, %i0
a00a5a20:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00a5a24:  96 10 00 18  mov  %i0, %o3
a00a5a28:  90 10 20 01  mov  1, %o0
a00a5a2c:  92 10 20 00  clr  %o1
a00a5a30:  94 10 25 92  mov  0x592, %o2
a00a5a34:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a00a5a38:  40 00 36 2b  call  0xa00b32e4
a00a5a3c:  9a 10 20 01  mov  1, %o5
a00a5a40:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00a5a44:  9a 00 60 12  add  %g1, 0x12, %o5
a00a5a48:  9e 05 3f fd  add  %l4, -3, %o7
a00a5a4c:  99 2b 60 10  sll  %o5, 0x10, %o4
a00a5a50:  a2 0b e0 ff  and  %o7, 0xff, %l1
a00a5a54:  b8 10 20 0d  mov  0xd, %i4
a00a5a58:  97 33 20 10  srl  %o4, 0x10, %o3
a00a5a5c:  98 10 00 11  mov  %l1, %o4
a00a5a60:  e2 27 bf d0  st  %l1, [ %fp + -48 ]
a00a5a64:  f8 23 a0 5c  st  %i4, [ %sp + 0x5c ]
a00a5a68:  90 10 20 01  mov  1, %o0
a00a5a6c:  92 10 20 00  clr  %o1
a00a5a70:  94 10 25 92  mov  0x592, %o2
a00a5a74:  40 00 36 1c  call  0xa00b32e4
a00a5a78:  9a 10 20 01  mov  1, %o5
a00a5a7c:  d6 17 bf f6  lduh  [ %fp + -10 ], %o3
a00a5a80:  a6 02 e0 13  add  %o3, 0x13, %l3
a00a5a84:  a1 2c e0 10  sll  %l3, 0x10, %l0
a00a5a88:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a5a8c:  b4 10 20 0e  mov  0xe, %i2
a00a5a90:  96 10 00 10  mov  %l0, %o3
a00a5a94:  f4 23 a0 5c  st  %i2, [ %sp + 0x5c ]
a00a5a98:  90 10 20 00  clr  %o0
a00a5a9c:  92 10 20 01  mov  1, %o1
a00a5aa0:  94 10 25 92  mov  0x592, %o2
a00a5aa4:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a00a5aa8:  40 00 36 0f  call  0xa00b32e4
a00a5aac:  9a 10 20 02  mov  2, %o5
a00a5ab0:  d4 17 bf ee  lduh  [ %fp + -18 ], %o2
a00a5ab4:  27 00 00 26  sethi  %hi(0x9800), %l3
a00a5ab8:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00a5abc:  94 14 e2 aa  or  %l3, 0x2aa, %o2
a00a5ac0:  98 10 00 1a  mov  %i2, %o4
a00a5ac4:  f8 23 a0 5c  st  %i4, [ %sp + 0x5c ]
a00a5ac8:  90 10 20 01  mov  1, %o0
a00a5acc:  92 10 20 01  mov  1, %o1
a00a5ad0:  96 10 00 17  mov  %l7, %o3
a00a5ad4:  40 00 36 04  call  0xa00b32e4
a00a5ad8:  9a 10 20 03  mov  3, %o5
a00a5adc:  92 05 a0 01  add  %l6, 1, %o1
a00a5ae0:  90 10 20 10  mov  0x10, %o0
a00a5ae4:  b9 36 e0 10  srl  %i3, 0x10, %i4
a00a5ae8:  a2 0a 60 ff  and  %o1, 0xff, %l1
a00a5aec:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00a5af0:  94 14 e2 aa  or  %l3, 0x2aa, %o2
a00a5af4:  98 10 00 11  mov  %l1, %o4
a00a5af8:  90 10 20 01  mov  1, %o0
a00a5afc:  92 10 20 01  mov  1, %o1
a00a5b00:  96 10 00 1c  mov  %i4, %o3
a00a5b04:  40 00 35 f8  call  0xa00b32e4
a00a5b08:  9a 10 20 03  mov  3, %o5
a00a5b0c:  82 10 20 13  mov  0x13, %g1
a00a5b10:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00a5b14:  94 14 e2 aa  or  %l3, 0x2aa, %o2
a00a5b18:  98 10 00 1d  mov  %i5, %o4
a00a5b1c:  90 10 20 01  mov  1, %o0
a00a5b20:  92 10 20 01  mov  1, %o1
a00a5b24:  96 10 00 1c  mov  %i4, %o3
a00a5b28:  40 00 35 ef  call  0xa00b32e4
a00a5b2c:  9a 10 20 02  mov  2, %o5
a00a5b30:  9e 10 20 11  mov  0x11, %o7
a00a5b34:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00a5b38:  96 10 00 18  mov  %i0, %o3
a00a5b3c:  94 14 e2 ae  or  %l3, 0x2ae, %o2
a00a5b40:  98 10 00 1a  mov  %i2, %o4
a00a5b44:  90 10 20 01  mov  1, %o0
a00a5b48:  92 10 20 01  mov  1, %o1
a00a5b4c:  40 00 35 e6  call  0xa00b32e4
a00a5b50:  9a 10 20 0f  mov  0xf, %o5
a00a5b54:  25 00 00 27  sethi  %hi(0x9c00), %l2
a00a5b58:  b0 10 20 15  mov  0x15, %i0
a00a5b5c:  94 14 a3 aa  or  %l2, 0x3aa, %o2
a00a5b60:  96 10 00 10  mov  %l0, %o3
a00a5b64:  98 10 00 1a  mov  %i2, %o4
a00a5b68:  f0 23 a0 5c  st  %i0, [ %sp + 0x5c ]
a00a5b6c:  90 10 20 01  mov  1, %o0
a00a5b70:  92 10 20 01  mov  1, %o1
a00a5b74:  40 00 35 dc  call  0xa00b32e4
a00a5b78:  9a 10 20 03  mov  3, %o5
a00a5b7c:  9a 10 20 18  mov  0x18, %o5
a00a5b80:  da 23 a0 5c  st  %o5, [ %sp + 0x5c ]
a00a5b84:  98 10 00 11  mov  %l1, %o4
a00a5b88:  94 14 a3 aa  or  %l2, 0x3aa, %o2
a00a5b8c:  96 10 00 10  mov  %l0, %o3
a00a5b90:  90 10 20 01  mov  1, %o0
a00a5b94:  92 10 20 01  mov  1, %o1
a00a5b98:  40 00 35 d3  call  0xa00b32e4
a00a5b9c:  9a 10 20 03  mov  3, %o5
a00a5ba0:  98 10 20 1b  mov  0x1b, %o4
a00a5ba4:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00a5ba8:  37 00 00 28  sethi  %hi(0xa000), %i3
a00a5bac:  94 16 e2 9a  or  %i3, 0x29a, %o2	! 0xa29a
a00a5bb0:  98 10 00 1d  mov  %i5, %o4
a00a5bb4:  96 10 00 10  mov  %l0, %o3
a00a5bb8:  90 10 20 01  mov  1, %o0
a00a5bbc:  92 10 20 01  mov  1, %o1
a00a5bc0:  40 00 35 c9  call  0xa00b32e4
a00a5bc4:  9a 10 20 03  mov  3, %o5
a00a5bc8:  ba 05 a0 03  add  %l6, 3, %i5
a00a5bcc:  96 10 20 1e  mov  0x1e, %o3
a00a5bd0:  b6 0f 60 ff  and  %i5, 0xff, %i3
a00a5bd4:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00a5bd8:  94 14 e2 aa  or  %l3, 0x2aa, %o2
a00a5bdc:  96 10 00 10  mov  %l0, %o3
a00a5be0:  98 10 00 1b  mov  %i3, %o4
a00a5be4:  90 10 20 01  mov  1, %o0
a00a5be8:  92 10 20 01  mov  1, %o1
a00a5bec:  40 00 35 be  call  0xa00b32e4
a00a5bf0:  9a 10 20 03  mov  3, %o5
a00a5bf4:  94 10 20 21  mov  0x21, %o2
a00a5bf8:  a2 05 a0 04  add  %l6, 4, %l1
a00a5bfc:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a00a5c00:  94 14 e2 aa  or  %l3, 0x2aa, %o2
a00a5c04:  96 10 00 10  mov  %l0, %o3
a00a5c08:  98 0c 60 ff  and  %l1, 0xff, %o4
a00a5c0c:  90 10 20 01  mov  1, %o0
a00a5c10:  92 10 20 01  mov  1, %o1
a00a5c14:  40 00 35 b4  call  0xa00b32e4
a00a5c18:  9a 10 20 03  mov  3, %o5
a00a5c1c:  92 10 20 24  mov  0x24, %o1
a00a5c20:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a00a5c24:  94 14 a3 aa  or  %l2, 0x3aa, %o2
a00a5c28:  90 10 20 01  mov  1, %o0
a00a5c2c:  92 10 20 01  mov  1, %o1
a00a5c30:  96 10 00 1c  mov  %i4, %o3
a00a5c34:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a00a5c38:  40 00 35 ab  call  0xa00b32e4
a00a5c3c:  9a 10 20 02  mov  2, %o5
a00a5c40:  90 10 20 26  mov  0x26, %o0
a00a5c44:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00a5c48:  94 14 a3 aa  or  %l2, 0x3aa, %o2
a00a5c4c:  90 10 20 01  mov  1, %o0
a00a5c50:  92 10 20 01  mov  1, %o1
a00a5c54:  96 10 00 1c  mov  %i4, %o3
a00a5c58:  d8 07 bf d0  ld  [ %fp + -48 ], %o4
a00a5c5c:  40 00 35 a2  call  0xa00b32e4
a00a5c60:  9a 10 20 02  mov  2, %o5
a00a5c64:  82 05 3f fe  add  %l4, -2, %g1
a00a5c68:  a2 08 60 ff  and  %g1, 0xff, %l1
a00a5c6c:  a6 10 20 28  mov  0x28, %l3
a00a5c70:  94 14 a3 aa  or  %l2, 0x3aa, %o2
a00a5c74:  98 10 00 11  mov  %l1, %o4
a00a5c78:  e6 23 a0 5c  st  %l3, [ %sp + 0x5c ]
a00a5c7c:  90 10 20 01  mov  1, %o0
a00a5c80:  92 10 20 01  mov  1, %o1
a00a5c84:  96 10 00 1c  mov  %i4, %o3
a00a5c88:  40 00 35 97  call  0xa00b32e4
a00a5c8c:  9a 10 20 01  mov  1, %o5
a00a5c90:  9e 10 20 10  mov  0x10, %o7
a00a5c94:  21 00 00 0c  sethi  %hi(0x3000), %l0
a00a5c98:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00a5c9c:  98 10 00 19  mov  %i1, %o4
a00a5ca0:  94 14 20 92  or  %l0, 0x92, %o2
a00a5ca4:  96 10 00 15  mov  %l5, %o3
a00a5ca8:  90 10 20 01  mov  1, %o0
a00a5cac:  92 10 20 01  mov  1, %o1
a00a5cb0:  40 00 35 8d  call  0xa00b32e4
a00a5cb4:  9a 10 20 02  mov  2, %o5
a00a5cb8:  9a 10 20 12  mov  0x12, %o5
a00a5cbc:  da 23 a0 5c  st  %o5, [ %sp + 0x5c ]
a00a5cc0:  94 14 20 92  or  %l0, 0x92, %o2
a00a5cc4:  96 10 00 15  mov  %l5, %o3
a00a5cc8:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a00a5ccc:  90 10 20 01  mov  1, %o0
a00a5cd0:  92 10 20 01  mov  1, %o1
a00a5cd4:  40 00 35 84  call  0xa00b32e4
a00a5cd8:  9a 10 20 02  mov  2, %o5
a00a5cdc:  98 10 20 14  mov  0x14, %o4
a00a5ce0:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00a5ce4:  96 10 00 15  mov  %l5, %o3
a00a5ce8:  94 14 20 92  or  %l0, 0x92, %o2
a00a5cec:  d8 07 bf d0  ld  [ %fp + -48 ], %o4
a00a5cf0:  90 10 20 01  mov  1, %o0
a00a5cf4:  92 10 20 01  mov  1, %o1
a00a5cf8:  40 00 35 7b  call  0xa00b32e4
a00a5cfc:  9a 10 20 01  mov  1, %o5
a00a5d00:  94 14 20 92  or  %l0, 0x92, %o2
a00a5d04:  98 10 00 11  mov  %l1, %o4
a00a5d08:  f0 23 a0 5c  st  %i0, [ %sp + 0x5c ]
a00a5d0c:  90 10 20 01  mov  1, %o0
a00a5d10:  92 10 20 01  mov  1, %o1
a00a5d14:  96 10 00 17  mov  %l7, %o3
a00a5d18:  40 00 35 73  call  0xa00b32e4
a00a5d1c:  9a 10 20 01  mov  1, %o5
a00a5d20:  96 10 20 01  mov  1, %o3
a00a5d24:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00a5d28:  98 10 00 1a  mov  %i2, %o4
a00a5d2c:  90 10 20 01  mov  1, %o0
a00a5d30:  92 10 20 00  clr  %o1
a00a5d34:  94 10 28 a2  mov  0x8a2, %o2
a00a5d38:  96 10 00 1c  mov  %i4, %o3
a00a5d3c:  40 00 35 6a  call  0xa00b32e4
a00a5d40:  9a 10 20 01  mov  1, %o5
a00a5d44:  d4 0f bf e7  ldub  [ %fp + -25 ], %o2
a00a5d48:  90 02 bf f9  add  %o2, -7, %o0
a00a5d4c:  92 10 20 07  mov  7, %o1
a00a5d50:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a5d54:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a00a5d58:  98 10 00 1b  mov  %i3, %o4
a00a5d5c:  90 10 20 00  clr  %o0
a00a5d60:  92 10 20 00  clr  %o1
a00a5d64:  94 10 28 a2  mov  0x8a2, %o2
a00a5d68:  40 00 35 5f  call  0xa00b32e4
a00a5d6c:  96 10 00 1c  mov  %i4, %o3
a00a5d70:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00a5d74:  b4 00 60 15  add  %g1, 0x15, %i2
a00a5d78:  f6 0f bf e7  ldub  [ %fp + -25 ], %i3
a00a5d7c:  bb 2e a0 10  sll  %i2, 0x10, %i5
a00a5d80:  a1 37 60 10  srl  %i5, 0x10, %l0
a00a5d84:  ac 05 a0 05  add  %l6, 5, %l6
a00a5d88:  b0 06 ff fa  add  %i3, -6, %i0
a00a5d8c:  b2 10 20 08  mov  8, %i1
a00a5d90:  98 0d a0 ff  and  %l6, 0xff, %o4
a00a5d94:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a5d98:  90 10 20 00  clr  %o0
a00a5d9c:  92 10 20 00  clr  %o1
a00a5da0:  94 10 28 a2  mov  0x8a2, %o2
a00a5da4:  96 10 00 10  mov  %l0, %o3
a00a5da8:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a00a5dac:  40 00 35 4e  call  0xa00b32e4
a00a5db0:  aa 05 3f ff  add  %l4, -1, %l5
a00a5db4:  a8 0d 60 ff  and  %l5, 0xff, %l4
a00a5db8:  a6 10 20 03  mov  3, %l3
a00a5dbc:  90 10 20 01  mov  1, %o0
a00a5dc0:  92 10 20 00  clr  %o1
a00a5dc4:  94 10 28 a2  mov  0x8a2, %o2
a00a5dc8:  96 10 00 1c  mov  %i4, %o3
a00a5dcc:  98 10 00 14  mov  %l4, %o4
a00a5dd0:  9a 10 20 01  mov  1, %o5
a00a5dd4:  40 00 35 44  call  0xa00b32e4
a00a5dd8:  e6 23 a0 5c  st  %l3, [ %sp + 0x5c ]
a00a5ddc:  a4 10 20 06  mov  6, %l2
a00a5de0:  96 10 00 17  mov  %l7, %o3
a00a5de4:  90 10 20 01  mov  1, %o0
a00a5de8:  92 10 20 00  clr  %o1
a00a5dec:  94 10 28 a2  mov  0x8a2, %o2
a00a5df0:  98 10 00 14  mov  %l4, %o4
a00a5df4:  9a 10 20 14  mov  0x14, %o5
a00a5df8:  40 00 35 3b  call  0xa00b32e4
a00a5dfc:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00a5e00:  a2 10 20 04  mov  4, %l1
a00a5e04:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a00a5e08:  96 10 00 10  mov  %l0, %o3
a00a5e0c:  98 10 00 14  mov  %l4, %o4
a00a5e10:  90 10 20 01  mov  1, %o0
a00a5e14:  92 10 20 00  clr  %o1
a00a5e18:  94 10 28 a2  mov  0x8a2, %o2
a00a5e1c:  40 00 35 32  call  0xa00b32e4
a00a5e20:  9a 10 20 01  mov  1, %o5
a00a5e24:  de 07 bf cc  ld  [ %fp + -52 ], %o7
a00a5e28:  80 a3 e0 01  cmp  %o7, 1
a00a5e2c:  12 80 00 0c  bne  0xa00a5e5c
a00a5e30:  90 10 21 01  mov  0x101, %o0
a00a5e34:  40 02 83 47  call  0xa0146b50
a00a5e38:  92 10 20 00  clr  %o1
a00a5e3c:  90 10 20 02  mov  2, %o0
a00a5e40:  40 02 83 4b  call  0xa0146b6c
a00a5e44:  92 10 20 00  clr  %o1
a00a5e48:  f6 17 bf ee  lduh  [ %fp + -18 ], %i3
a00a5e4c:  ad 2e e0 10  sll  %i3, 0x10, %l6
a00a5e50:  b3 35 a0 10  srl  %l6, 0x10, %i1
a00a5e54:  40 00 4e 3f  call  0xa00b9750
a00a5e58:  91 e8 00 1c  restore  %g0, %i4, %o0
a00a5e5c:  01 00 00 00  nop
a00a5e60:  81 c7 e0 08  ret
a00a5e64:  81 e8 00 00  restore
