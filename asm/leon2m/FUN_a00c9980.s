# leon2m FUN_a00c9980 0xa00c9980-0xa00c9be0 (608 bytes)
a00c9980:  9d e3 bf 98  save  %sp, -104, %sp
a00c9984:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9988:  80 a4 20 02  cmp  %l0, 2
a00c998c:  02 80 00 45  be  0xa00c9aa0
a00c9990:  80 a4 20 03  cmp  %l0, 3
a00c9994:  02 80 00 6a  be  0xa00c9b3c
a00c9998:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c999c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c99a0:  96 08 60 ff  and  %g1, 0xff, %o3
a00c99a4:  94 02 ff d0  add  %o3, -48, %o2
a00c99a8:  98 0a a0 ff  and  %o2, 0xff, %o4
a00c99ac:  80 a3 20 03  cmp  %o4, 3
a00c99b0:  18 80 00 8a  bgu  0xa00c9bd8
a00c99b4:  b0 10 20 ff  mov  0xff, %i0
a00c99b8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c99bc:  da 0b e2 af  ldub  [ %o7 + 0x2af ], %o5	! 0xa802d2af
a00c99c0:  80 a3 60 00  cmp  %o5, 0
a00c99c4:  02 80 00 85  be  0xa00c9bd8
a00c99c8:  80 a3 20 00  cmp  %o4, 0
a00c99cc:  02 80 00 38  be  0xa00c9aac
a00c99d0:  80 a3 20 01  cmp  %o4, 1
a00c99d4:  02 80 00 79  be  0xa00c9bb8
a00c99d8:  80 a3 20 02  cmp  %o4, 2
a00c99dc:  02 80 00 5b  be  0xa00c9b48
a00c99e0:  80 a3 20 03  cmp  %o4, 3
a00c99e4:  02 80 00 78  be  0xa00c9bc4
a00c99e8:  01 00 00 00  nop
a00c99ec:  7f ff bb b8  call  0xa00b88cc
a00c99f0:  01 00 00 00  nop
a00c99f4:  80 a4 20 02  cmp  %l0, 2
a00c99f8:  02 80 00 35  be  0xa00c9acc
a00c99fc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9a00:  80 a4 20 03  cmp  %l0, 3
a00c9a04:  02 80 00 56  be  0xa00c9b5c
a00c9a08:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c9a0c:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c9a10:  90 10 20 30  mov  0x30, %o0
a00c9a14:  9a 10 20 35  mov  0x35, %o5
a00c9a18:  98 10 20 36  mov  0x36, %o4
a00c9a1c:  9e 10 20 2b  mov  0x2b, %o7
a00c9a20:  92 10 20 0d  mov  0xd, %o1
a00c9a24:  da 2a e0 78  stb  %o5, [ %o3 + 0x78 ]
a00c9a28:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c9a2c:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c9a30:  de 2a a0 04  stb  %o7, [ %o2 + 4 ]
a00c9a34:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c9a38:  80 a4 20 02  cmp  %l0, 2
a00c9a3c:  02 80 00 30  be  0xa00c9afc
a00c9a40:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c9a44:  80 a4 20 03  cmp  %l0, 3
a00c9a48:  02 80 00 52  be  0xa00c9b90
a00c9a4c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c9a50:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00c9a54:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c9a58:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00c9a5c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c9a60:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c9a64:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c9a68:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c9a6c:  80 a4 20 02  cmp  %l0, 2
a00c9a70:  02 80 00 2c  be  0xa00c9b20
a00c9a74:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c9a78:  80 a4 20 03  cmp  %l0, 3
a00c9a7c:  12 80 00 2c  bne  0xa00c9b2c
a00c9a80:  90 10 00 10  mov  %l0, %o0
a00c9a84:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c9a88:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c9a8c:  90 10 20 03  mov  3, %o0
a00c9a90:  40 01 fb 56  call  0xa01487e8
a00c9a94:  92 10 20 06  mov  6, %o1
a00c9a98:  10 80 00 50  b  0xa00c9bd8
a00c9a9c:  b0 10 20 00  clr  %i0
a00c9aa0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9aa4:  10 bf ff bf  b  0xa00c99a0
a00c9aa8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c9aac:  7f ff 5d 87  call  0xa00a10c8
a00c9ab0:  01 00 00 00  nop
a00c9ab4:  7f ff bb 86  call  0xa00b88cc
a00c9ab8:  01 00 00 00  nop
a00c9abc:  80 a4 20 02  cmp  %l0, 2
a00c9ac0:  12 bf ff d1  bne  0xa00c9a04
a00c9ac4:  80 a4 20 03  cmp  %l0, 3
a00c9ac8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9acc:  98 12 61 28  or  %o1, 0x128, %o4	! 0xa802d128
a00c9ad0:  a0 10 20 30  mov  0x30, %l0
a00c9ad4:  94 10 20 35  mov  0x35, %o2
a00c9ad8:  90 10 20 0d  mov  0xd, %o0
a00c9adc:  82 10 20 36  mov  0x36, %g1
a00c9ae0:  b0 10 20 2b  mov  0x2b, %i0
a00c9ae4:  d4 2a 61 28  stb  %o2, [ %o1 + 0x128 ]
a00c9ae8:  d0 2b 20 05  stb  %o0, [ %o4 + 5 ]
a00c9aec:  c2 2b 20 01  stb  %g1, [ %o4 + 1 ]
a00c9af0:  e0 2b 20 03  stb  %l0, [ %o4 + 3 ]
a00c9af4:  f0 2b 20 04  stb  %i0, [ %o4 + 4 ]
a00c9af8:  e0 2b 20 02  stb  %l0, [ %o4 + 2 ]
a00c9afc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c9b00:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c9b04:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c9b08:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00c9b0c:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c9b10:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c9b14:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c9b18:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c9b1c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c9b20:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c9b24:  94 13 61 28  or  %o5, 0x128, %o2	! 0xa802d128
a00c9b28:  90 10 20 02  mov  2, %o0
a00c9b2c:  40 01 fb 2f  call  0xa01487e8
a00c9b30:  92 10 20 06  mov  6, %o1
a00c9b34:  10 80 00 29  b  0xa00c9bd8
a00c9b38:  b0 10 20 00  clr  %i0
a00c9b3c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9b40:  10 bf ff 98  b  0xa00c99a0
a00c9b44:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c9b48:  7f ff 5d 2a  call  0xa00a0ff0
a00c9b4c:  01 00 00 00  nop
a00c9b50:  40 00 2b 18  call  0xa00d47b0
a00c9b54:  01 00 00 00  nop
a00c9b58:  30 bf ff a5  b,a   0xa00c99ec
a00c9b5c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c9b60:  9e 16 21 08  or  %i0, 0x108, %o7	! 0xa802d108
a00c9b64:  98 10 20 30  mov  0x30, %o4
a00c9b68:  82 10 20 35  mov  0x35, %g1
a00c9b6c:  a0 10 20 0d  mov  0xd, %l0
a00c9b70:  9a 10 20 36  mov  0x36, %o5
a00c9b74:  96 10 20 2b  mov  0x2b, %o3
a00c9b78:  c2 2e 21 08  stb  %g1, [ %i0 + 0x108 ]
a00c9b7c:  e0 2b e0 05  stb  %l0, [ %o7 + 5 ]
a00c9b80:  da 2b e0 01  stb  %o5, [ %o7 + 1 ]
a00c9b84:  d8 2b e0 03  stb  %o4, [ %o7 + 3 ]
a00c9b88:  d6 2b e0 04  stb  %o3, [ %o7 + 4 ]
a00c9b8c:  d8 2b e0 02  stb  %o4, [ %o7 + 2 ]
a00c9b90:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9b94:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00c9b98:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c9b9c:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c9ba0:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c9ba4:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c9ba8:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c9bac:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c9bb0:  10 bf ff b5  b  0xa00c9a84
a00c9bb4:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c9bb8:  7f ff 39 59  call  0xa009811c
a00c9bbc:  01 00 00 00  nop
a00c9bc0:  30 bf ff 8b  b,a   0xa00c99ec
a00c9bc4:  7f ff 5d 26  call  0xa00a105c
a00c9bc8:  01 00 00 00  nop
a00c9bcc:  40 00 2a f9  call  0xa00d47b0
a00c9bd0:  01 00 00 00  nop
a00c9bd4:  30 bf ff 86  b,a   0xa00c99ec
a00c9bd8:  81 c7 e0 08  ret
a00c9bdc:  81 e8 00 00  restore
