# leon2m FUN_a00c5a00 0xa00c5a00-0xa00c5c18 (536 bytes)
a00c5a00:  9d e3 bf 98  save  %sp, -104, %sp
a00c5a04:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c5a08:  80 a4 20 02  cmp  %l0, 2
a00c5a0c:  02 80 00 44  be  0xa00c5b1c
a00c5a10:  80 a4 20 03  cmp  %l0, 3
a00c5a14:  02 80 00 45  be  0xa00c5b28
a00c5a18:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5a1c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c5a20:  96 08 60 ff  and  %g1, 0xff, %o3
a00c5a24:  94 02 ff d0  add  %o3, -48, %o2
a00c5a28:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c5a2c:  80 a3 60 03  cmp  %o5, 3
a00c5a30:  18 80 00 78  bgu  0xa00c5c10
a00c5a34:  b0 10 20 ff  mov  0xff, %i0
a00c5a38:  80 a3 60 01  cmp  %o5, 1
a00c5a3c:  02 80 00 09  be  0xa00c5a60
a00c5a40:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c5a44:  04 80 00 6d  ble  0xa00c5bf8
a00c5a48:  80 a3 60 02  cmp  %o5, 2
a00c5a4c:  02 80 00 05  be  0xa00c5a60
a00c5a50:  80 a3 60 03  cmp  %o5, 3
a00c5a54:  22 80 00 04  be,a   0xa00c5a64
a00c5a58:  da 2b e2 a1  stb  %o5, [ %o7 + 0x2a1 ]
a00c5a5c:  30 80 00 6d  b,a   0xa00c5c10
a00c5a60:  da 2b e2 a1  stb  %o5, [ %o7 + 0x2a1 ]
a00c5a64:  40 00 4f 40  call  0xa00d9764
a00c5a68:  01 00 00 00  nop
a00c5a6c:  7f ff cb 98  call  0xa00b88cc
a00c5a70:  01 00 00 00  nop
a00c5a74:  80 a4 20 02  cmp  %l0, 2
a00c5a78:  02 80 00 46  be  0xa00c5b90
a00c5a7c:  80 a4 20 03  cmp  %l0, 3
a00c5a80:  02 80 00 2d  be  0xa00c5b34
a00c5a84:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c5a88:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c5a8c:  90 10 20 30  mov  0x30, %o0
a00c5a90:  b0 10 20 35  mov  0x35, %i0
a00c5a94:  9e 10 20 36  mov  0x36, %o7
a00c5a98:  98 10 20 2b  mov  0x2b, %o4
a00c5a9c:  92 10 20 0d  mov  0xd, %o1
a00c5aa0:  f0 2a e0 78  stb  %i0, [ %o3 + 0x78 ]
a00c5aa4:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c5aa8:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c5aac:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c5ab0:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c5ab4:  80 a4 20 02  cmp  %l0, 2
a00c5ab8:  02 80 00 43  be  0xa00c5bc4
a00c5abc:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c5ac0:  80 a4 20 03  cmp  %l0, 3
a00c5ac4:  02 80 00 29  be  0xa00c5b68
a00c5ac8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5acc:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00c5ad0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c5ad4:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00c5ad8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c5adc:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c5ae0:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c5ae4:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c5ae8:  80 a4 20 02  cmp  %l0, 2
a00c5aec:  02 80 00 3f  be  0xa00c5be8
a00c5af0:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c5af4:  80 a4 20 03  cmp  %l0, 3
a00c5af8:  12 80 00 05  bne  0xa00c5b0c
a00c5afc:  90 10 00 10  mov  %l0, %o0
a00c5b00:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c5b04:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c5b08:  90 10 20 03  mov  3, %o0
a00c5b0c:  40 02 0b 37  call  0xa01487e8
a00c5b10:  92 10 20 06  mov  6, %o1
a00c5b14:  10 80 00 3f  b  0xa00c5c10
a00c5b18:  b0 10 20 00  clr  %i0
a00c5b1c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5b20:  10 bf ff c0  b  0xa00c5a20
a00c5b24:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c5b28:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c5b2c:  10 bf ff bd  b  0xa00c5a20
a00c5b30:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c5b34:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c5b38:  98 13 61 08  or  %o5, 0x108, %o4	! 0xa802d108
a00c5b3c:  9e 10 20 30  mov  0x30, %o7
a00c5b40:  82 10 20 35  mov  0x35, %g1
a00c5b44:  b0 10 20 0d  mov  0xd, %i0
a00c5b48:  a0 10 20 36  mov  0x36, %l0
a00c5b4c:  96 10 20 2b  mov  0x2b, %o3
a00c5b50:  c2 2b 61 08  stb  %g1, [ %o5 + 0x108 ]
a00c5b54:  f0 2b 20 05  stb  %i0, [ %o4 + 5 ]
a00c5b58:  e0 2b 20 01  stb  %l0, [ %o4 + 1 ]
a00c5b5c:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c5b60:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c5b64:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c5b68:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5b6c:  90 12 60 98  or  %o1, 0x98, %o0	! 0xa802d098
a00c5b70:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c5b74:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c5b78:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c5b7c:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c5b80:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c5b84:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c5b88:  10 bf ff de  b  0xa00c5b00
a00c5b8c:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c5b90:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5b94:  a0 12 61 28  or  %o1, 0x128, %l0	! 0xa802d128
a00c5b98:  b0 10 20 30  mov  0x30, %i0
a00c5b9c:  94 10 20 35  mov  0x35, %o2
a00c5ba0:  90 10 20 0d  mov  0xd, %o0
a00c5ba4:  82 10 20 36  mov  0x36, %g1
a00c5ba8:  9a 10 20 2b  mov  0x2b, %o5
a00c5bac:  d4 2a 61 28  stb  %o2, [ %o1 + 0x128 ]
a00c5bb0:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00c5bb4:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a00c5bb8:  f0 2c 20 03  stb  %i0, [ %l0 + 3 ]
a00c5bbc:  da 2c 20 04  stb  %o5, [ %l0 + 4 ]
a00c5bc0:  f0 2c 20 02  stb  %i0, [ %l0 + 2 ]
a00c5bc4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c5bc8:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c5bcc:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c5bd0:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00c5bd4:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c5bd8:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c5bdc:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c5be0:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c5be4:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c5be8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5bec:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00c5bf0:  10 bf ff c7  b  0xa00c5b0c
a00c5bf4:  90 10 20 02  mov  2, %o0
a00c5bf8:  80 a3 60 00  cmp  %o5, 0
a00c5bfc:  12 80 00 05  bne  0xa00c5c10
a00c5c00:  b0 10 20 ff  mov  0xff, %i0
a00c5c04:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5c08:  10 bf ff 97  b  0xa00c5a64
a00c5c0c:  c0 2b 22 a1  clrb  [ %o4 + 0x2a1 ]	! 0xa802d2a1
a00c5c10:  81 c7 e0 08  ret
a00c5c14:  81 e8 00 00  restore
