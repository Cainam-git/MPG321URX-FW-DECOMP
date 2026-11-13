# leon2m FUN_a00c3a30 0xa00c3a30-0xa00c3c14 (484 bytes)
a00c3a30:  9d e3 bf 98  save  %sp, -104, %sp
a00c3a34:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c3a38:  80 a4 20 02  cmp  %l0, 2
a00c3a3c:  02 80 00 54  be  0xa00c3b8c
a00c3a40:  80 a4 20 03  cmp  %l0, 3
a00c3a44:  02 80 00 55  be  0xa00c3b98
a00c3a48:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c3a4c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c3a50:  94 08 60 ff  and  %g1, 0xff, %o2
a00c3a54:  98 02 bf d0  add  %o2, -48, %o4
a00c3a58:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c3a5c:  80 a3 60 0a  cmp  %o5, 0xa
a00c3a60:  18 80 00 6b  bgu  0xa00c3c0c
a00c3a64:  b0 10 20 ff  mov  0xff, %i0
a00c3a68:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3a6c:  40 00 54 31  call  0xa00d8b30
a00c3a70:  d8 2a e3 d0  stb  %o4, [ %o3 + 0x3d0 ]	! 0xa802d3d0
a00c3a74:  40 00 43 c9  call  0xa00d4998
a00c3a78:  01 00 00 00  nop
a00c3a7c:  7f ff d3 94  call  0xa00b88cc
a00c3a80:  01 00 00 00  nop
a00c3a84:  80 a4 20 02  cmp  %l0, 2
a00c3a88:  02 80 00 24  be  0xa00c3b18
a00c3a8c:  80 a4 20 03  cmp  %l0, 3
a00c3a90:  02 80 00 45  be  0xa00c3ba4
a00c3a94:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c3a98:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c3a9c:  90 10 20 30  mov  0x30, %o0
a00c3aa0:  96 10 20 35  mov  0x35, %o3
a00c3aa4:  98 10 20 36  mov  0x36, %o4
a00c3aa8:  92 10 20 2b  mov  0x2b, %o1
a00c3aac:  82 10 20 0d  mov  0xd, %g1
a00c3ab0:  d6 2b 60 78  stb  %o3, [ %o5 + 0x78 ]
a00c3ab4:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c3ab8:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c3abc:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c3ac0:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c3ac4:  80 a4 20 02  cmp  %l0, 2
a00c3ac8:  02 80 00 21  be  0xa00c3b4c
a00c3acc:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c3ad0:  80 a4 20 03  cmp  %l0, 3
a00c3ad4:  02 80 00 41  be  0xa00c3bd8
a00c3ad8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c3adc:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00c3ae0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c3ae4:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00c3ae8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c3aec:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c3af0:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c3af4:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c3af8:  80 a4 20 02  cmp  %l0, 2
a00c3afc:  02 80 00 1d  be  0xa00c3b70
a00c3b00:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c3b04:  80 a4 20 03  cmp  %l0, 3
a00c3b08:  12 80 00 1d  bne  0xa00c3b7c
a00c3b0c:  90 10 00 10  mov  %l0, %o0
a00c3b10:  10 80 00 3c  b  0xa00c3c00
a00c3b14:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3b18:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3b1c:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00c3b20:  9e 10 20 30  mov  0x30, %o7
a00c3b24:  92 10 20 35  mov  0x35, %o1
a00c3b28:  82 10 20 0d  mov  0xd, %g1
a00c3b2c:  b0 10 20 36  mov  0x36, %i0
a00c3b30:  a0 10 20 2b  mov  0x2b, %l0
a00c3b34:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c3b38:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00c3b3c:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00c3b40:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c3b44:  e0 2b 20 04  stb  %l0, [ %o4 + 4 ]
a00c3b48:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c3b4c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c3b50:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00c3b54:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c3b58:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c3b5c:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00c3b60:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c3b64:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c3b68:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c3b6c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c3b70:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3b74:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00c3b78:  90 10 20 02  mov  2, %o0
a00c3b7c:  40 02 13 1b  call  0xa01487e8
a00c3b80:  92 10 20 06  mov  6, %o1
a00c3b84:  10 80 00 22  b  0xa00c3c0c
a00c3b88:  b0 10 20 00  clr  %i0
a00c3b8c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c3b90:  10 bf ff b0  b  0xa00c3a50
a00c3b94:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c3b98:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3b9c:  10 bf ff ad  b  0xa00c3a50
a00c3ba0:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3ba4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c3ba8:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00c3bac:  94 10 20 30  mov  0x30, %o2
a00c3bb0:  b0 10 20 35  mov  0x35, %i0
a00c3bb4:  9e 10 20 0d  mov  0xd, %o7
a00c3bb8:  96 10 20 36  mov  0x36, %o3
a00c3bbc:  9a 10 20 2b  mov  0x2b, %o5
a00c3bc0:  f0 2c 21 08  stb  %i0, [ %l0 + 0x108 ]
a00c3bc4:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c3bc8:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00c3bcc:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c3bd0:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c3bd4:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c3bd8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3bdc:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00c3be0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c3be4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c3be8:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c3bec:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c3bf0:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c3bf4:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c3bf8:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c3bfc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c3c00:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c3c04:  10 bf ff de  b  0xa00c3b7c
a00c3c08:  90 10 20 03  mov  3, %o0
a00c3c0c:  81 c7 e0 08  ret
a00c3c10:  81 e8 00 00  restore
