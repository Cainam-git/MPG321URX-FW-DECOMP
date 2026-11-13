# leon2m FUN_a00c9be0 0xa00c9be0-0xa00c9df4 (532 bytes)
a00c9be0:  9d e3 bf 98  save  %sp, -104, %sp
a00c9be4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9be8:  80 a4 20 02  cmp  %l0, 2
a00c9bec:  02 80 00 60  be  0xa00c9d6c
a00c9bf0:  80 a4 20 03  cmp  %l0, 3
a00c9bf4:  02 80 00 61  be  0xa00c9d78
a00c9bf8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c9bfc:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c9c00:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c9c04:  96 13 22 90  or  %o4, 0x290, %o3	! 0xa802d290
a00c9c08:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c9c0c:  d4 0a e0 1f  ldub  [ %o3 + 0x1f ], %o2
a00c9c10:  80 a2 a0 00  cmp  %o2, 0
a00c9c14:  9a 03 7f d0  add  %o5, -48, %o5
a00c9c18:  12 80 00 75  bne  0xa00c9dec
a00c9c1c:  b0 10 20 ff  mov  0xff, %i0
a00c9c20:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00c9c24:  80 a3 60 02  cmp  %o5, 2
a00c9c28:  18 80 00 71  bgu  0xa00c9dec
a00c9c2c:  9a 0b 60 03  and  %o5, 3, %o5
a00c9c30:  d8 02 e0 ac  ld  [ %o3 + 0xac ], %o4
a00c9c34:  15 00 03 00  sethi  %hi(0xc0000), %o2
a00c9c38:  90 2b 00 0a  andn  %o4, %o2, %o0
a00c9c3c:  93 2b 60 12  sll  %o5, 0x12, %o1
a00c9c40:  82 12 00 09  or  %o0, %o1, %g1
a00c9c44:  40 00 45 04  call  0xa00db054
a00c9c48:  c2 22 e0 ac  st  %g1, [ %o3 + 0xac ]
a00c9c4c:  7f ff bb 20  call  0xa00b88cc
a00c9c50:  01 00 00 00  nop
a00c9c54:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c9c58:  f0 0a e0 8e  ldub  [ %o3 + 0x8e ], %i0	! 0xa802b08e
a00c9c5c:  9e 16 20 04  or  %i0, 4, %o7
a00c9c60:  80 a4 20 02  cmp  %l0, 2
a00c9c64:  02 80 00 25  be  0xa00c9cf8
a00c9c68:  de 2a e0 8e  stb  %o7, [ %o3 + 0x8e ]
a00c9c6c:  80 a4 20 03  cmp  %l0, 3
a00c9c70:  02 80 00 45  be  0xa00c9d84
a00c9c74:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c9c78:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c9c7c:  90 10 20 30  mov  0x30, %o0
a00c9c80:  9e 10 20 35  mov  0x35, %o7
a00c9c84:  98 10 20 36  mov  0x36, %o4
a00c9c88:  92 10 20 2b  mov  0x2b, %o1
a00c9c8c:  82 10 20 0d  mov  0xd, %g1
a00c9c90:  de 2b 60 78  stb  %o7, [ %o5 + 0x78 ]
a00c9c94:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c9c98:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c9c9c:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c9ca0:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c9ca4:  80 a4 20 02  cmp  %l0, 2
a00c9ca8:  02 80 00 21  be  0xa00c9d2c
a00c9cac:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c9cb0:  80 a4 20 03  cmp  %l0, 3
a00c9cb4:  02 80 00 41  be  0xa00c9db8
a00c9cb8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c9cbc:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00c9cc0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c9cc4:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00c9cc8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c9ccc:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c9cd0:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c9cd4:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c9cd8:  80 a4 20 02  cmp  %l0, 2
a00c9cdc:  02 80 00 1d  be  0xa00c9d50
a00c9ce0:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c9ce4:  80 a4 20 03  cmp  %l0, 3
a00c9ce8:  12 80 00 1d  bne  0xa00c9d5c
a00c9cec:  90 10 00 10  mov  %l0, %o0
a00c9cf0:  10 80 00 3c  b  0xa00c9de0
a00c9cf4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c9cf8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9cfc:  a0 12 21 28  or  %o0, 0x128, %l0	! 0xa802d128
a00c9d00:  9e 10 20 30  mov  0x30, %o7
a00c9d04:  92 10 20 35  mov  0x35, %o1
a00c9d08:  82 10 20 0d  mov  0xd, %g1
a00c9d0c:  b0 10 20 36  mov  0x36, %i0
a00c9d10:  96 10 20 2b  mov  0x2b, %o3
a00c9d14:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c9d18:  c2 2c 20 05  stb  %g1, [ %l0 + 5 ]
a00c9d1c:  f0 2c 20 01  stb  %i0, [ %l0 + 1 ]
a00c9d20:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a00c9d24:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c9d28:  de 2c 20 02  stb  %o7, [ %l0 + 2 ]
a00c9d2c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c9d30:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c9d34:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c9d38:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c9d3c:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c9d40:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c9d44:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c9d48:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c9d4c:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c9d50:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c9d54:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c9d58:  90 10 20 02  mov  2, %o0
a00c9d5c:  40 01 fa a3  call  0xa01487e8
a00c9d60:  92 10 20 06  mov  6, %o1
a00c9d64:  10 80 00 22  b  0xa00c9dec
a00c9d68:  b0 10 20 00  clr  %i0
a00c9d6c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9d70:  10 bf ff a4  b  0xa00c9c00
a00c9d74:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c9d78:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9d7c:  10 bf ff a1  b  0xa00c9c00
a00c9d80:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c9d84:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c9d88:  98 12 e1 08  or  %o3, 0x108, %o4	! 0xa802d108
a00c9d8c:  94 10 20 30  mov  0x30, %o2
a00c9d90:  b0 10 20 35  mov  0x35, %i0
a00c9d94:  9e 10 20 0d  mov  0xd, %o7
a00c9d98:  a0 10 20 36  mov  0x36, %l0
a00c9d9c:  9a 10 20 2b  mov  0x2b, %o5
a00c9da0:  f0 2a e1 08  stb  %i0, [ %o3 + 0x108 ]
a00c9da4:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c9da8:  e0 2b 20 01  stb  %l0, [ %o4 + 1 ]
a00c9dac:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c9db0:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c9db4:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c9db8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9dbc:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00c9dc0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c9dc4:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c9dc8:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c9dcc:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c9dd0:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c9dd4:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c9dd8:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c9ddc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c9de0:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c9de4:  10 bf ff de  b  0xa00c9d5c
a00c9de8:  90 10 20 03  mov  3, %o0
a00c9dec:  81 c7 e0 08  ret
a00c9df0:  81 e8 00 00  restore
