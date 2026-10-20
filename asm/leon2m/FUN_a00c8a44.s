# leon2m FUN_a00c8a44 0xa00c8a44-0xa00c8c38 (500 bytes)
a00c8a44:  9d e3 bf 98  save  %sp, -104, %sp
a00c8a48:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c8a4c:  80 a4 20 02  cmp  %l0, 2
a00c8a50:  02 80 00 58  be  0xa00c8bb0
a00c8a54:  80 a4 20 03  cmp  %l0, 3
a00c8a58:  02 80 00 59  be  0xa00c8bbc
a00c8a5c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c8a60:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c8a64:  94 08 60 ff  and  %g1, 0xff, %o2
a00c8a68:  98 02 bf d0  add  %o2, -48, %o4
a00c8a6c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c8a70:  80 a3 60 02  cmp  %o5, 2
a00c8a74:  18 80 00 6f  bgu  0xa00c8c30
a00c8a78:  b0 10 20 ff  mov  0xff, %i0
a00c8a7c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c8a80:  96 10 62 90  or  %g1, 0x290, %o3	! 0xa802d290
a00c8a84:  de 0a e0 1f  ldub  [ %o3 + 0x1f ], %o7
a00c8a88:  80 a3 e0 00  cmp  %o7, 0
a00c8a8c:  02 80 00 69  be  0xa00c8c30
a00c8a90:  90 10 20 02  mov  2, %o0
a00c8a94:  b0 22 00 0c  sub  %o0, %o4, %i0
a00c8a98:  40 00 3c 22  call  0xa00d7b20
a00c8a9c:  f0 2a e0 31  stb  %i0, [ %o3 + 0x31 ]
a00c8aa0:  7f ff bf 8b  call  0xa00b88cc
a00c8aa4:  01 00 00 00  nop
a00c8aa8:  80 a4 20 02  cmp  %l0, 2
a00c8aac:  02 80 00 24  be  0xa00c8b3c
a00c8ab0:  80 a4 20 03  cmp  %l0, 3
a00c8ab4:  02 80 00 45  be  0xa00c8bc8
a00c8ab8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c8abc:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c8ac0:  9e 10 20 30  mov  0x30, %o7
a00c8ac4:  82 10 20 35  mov  0x35, %g1
a00c8ac8:  90 10 20 36  mov  0x36, %o0
a00c8acc:  b0 10 20 2b  mov  0x2b, %i0
a00c8ad0:  9a 10 20 0d  mov  0xd, %o5
a00c8ad4:  c2 2b 20 78  stb  %g1, [ %o4 + 0x78 ]
a00c8ad8:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c8adc:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c8ae0:  f0 2a a0 04  stb  %i0, [ %o2 + 4 ]
a00c8ae4:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c8ae8:  80 a4 20 02  cmp  %l0, 2
a00c8aec:  02 80 00 21  be  0xa00c8b70
a00c8af0:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c8af4:  80 a4 20 03  cmp  %l0, 3
a00c8af8:  02 80 00 41  be  0xa00c8bfc
a00c8afc:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c8b00:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8b04:  b0 12 20 d0  or  %o0, 0xd0, %i0	! 0xa802d0d0
a00c8b08:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]
a00c8b0c:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00c8b10:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c8b14:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c8b18:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c8b1c:  80 a4 20 02  cmp  %l0, 2
a00c8b20:  02 80 00 1d  be  0xa00c8b94
a00c8b24:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c8b28:  80 a4 20 03  cmp  %l0, 3
a00c8b2c:  12 80 00 1d  bne  0xa00c8ba0
a00c8b30:  90 10 00 10  mov  %l0, %o0
a00c8b34:  10 80 00 3c  b  0xa00c8c24
a00c8b38:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8b3c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8b40:  98 12 a1 28  or  %o2, 0x128, %o4	! 0xa802d128
a00c8b44:  a0 10 20 30  mov  0x30, %l0
a00c8b48:  9e 10 20 35  mov  0x35, %o7
a00c8b4c:  9a 10 20 0d  mov  0xd, %o5
a00c8b50:  92 10 20 36  mov  0x36, %o1
a00c8b54:  96 10 20 2b  mov  0x2b, %o3
a00c8b58:  de 2a a1 28  stb  %o7, [ %o2 + 0x128 ]
a00c8b5c:  da 2b 20 05  stb  %o5, [ %o4 + 5 ]
a00c8b60:  d2 2b 20 01  stb  %o1, [ %o4 + 1 ]
a00c8b64:  e0 2b 20 03  stb  %l0, [ %o4 + 3 ]
a00c8b68:  d6 2b 20 04  stb  %o3, [ %o4 + 4 ]
a00c8b6c:  e0 2b 20 02  stb  %l0, [ %o4 + 2 ]
a00c8b70:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c8b74:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c8b78:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c8b7c:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c8b80:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c8b84:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c8b88:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c8b8c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c8b90:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c8b94:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c8b98:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c8b9c:  90 10 20 02  mov  2, %o0
a00c8ba0:  40 01 ff 12  call  0xa01487e8
a00c8ba4:  92 10 20 06  mov  6, %o1
a00c8ba8:  10 80 00 22  b  0xa00c8c30
a00c8bac:  b0 10 20 00  clr  %i0
a00c8bb0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c8bb4:  10 bf ff ac  b  0xa00c8a64
a00c8bb8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c8bbc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c8bc0:  10 bf ff a9  b  0xa00c8a64
a00c8bc4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c8bc8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c8bcc:  b0 12 e1 08  or  %o3, 0x108, %i0	! 0xa802d108
a00c8bd0:  90 10 20 30  mov  0x30, %o0
a00c8bd4:  92 10 20 35  mov  0x35, %o1
a00c8bd8:  a0 10 20 0d  mov  0xd, %l0
a00c8bdc:  98 10 20 36  mov  0x36, %o4
a00c8be0:  82 10 20 2b  mov  0x2b, %g1
a00c8be4:  d2 2a e1 08  stb  %o1, [ %o3 + 0x108 ]
a00c8be8:  e0 2e 20 05  stb  %l0, [ %i0 + 5 ]
a00c8bec:  d8 2e 20 01  stb  %o4, [ %i0 + 1 ]
a00c8bf0:  d0 2e 20 03  stb  %o0, [ %i0 + 3 ]
a00c8bf4:  c2 2e 20 04  stb  %g1, [ %i0 + 4 ]
a00c8bf8:  d0 2e 20 02  stb  %o0, [ %i0 + 2 ]
a00c8bfc:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c8c00:  92 13 e0 98  or  %o7, 0x98, %o1	! 0xa802d098
a00c8c04:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c8c08:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]	! 0xa802b098
a00c8c0c:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00c8c10:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c8c14:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c8c18:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c8c1c:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c8c20:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c8c24:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c8c28:  10 bf ff de  b  0xa00c8ba0
a00c8c2c:  90 10 20 03  mov  3, %o0
a00c8c30:  81 c7 e0 08  ret
a00c8c34:  81 e8 00 00  restore
