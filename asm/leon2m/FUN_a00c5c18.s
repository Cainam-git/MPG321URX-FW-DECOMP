# leon2m FUN_a00c5c18 0xa00c5c18-0xa00c5e40 (552 bytes)
a00c5c18:  9d e3 bf 98  save  %sp, -104, %sp
a00c5c1c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c5c20:  80 a4 20 02  cmp  %l0, 2
a00c5c24:  02 80 00 68  be  0xa00c5dc4
a00c5c28:  80 a4 20 03  cmp  %l0, 3
a00c5c2c:  02 80 00 69  be  0xa00c5dd0
a00c5c30:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5c34:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c5c38:  96 08 60 ff  and  %g1, 0xff, %o3
a00c5c3c:  94 02 ff d0  add  %o3, -48, %o2
a00c5c40:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c5c44:  80 a3 60 01  cmp  %o5, 1
a00c5c48:  18 80 00 7c  bgu  0xa00c5e38
a00c5c4c:  b0 10 20 ff  mov  0xff, %i0
a00c5c50:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5c54:  98 12 62 90  or  %o1, 0x290, %o4	! 0xa802d290
a00c5c58:  c2 03 21 1c  ld  [ %o4 + 0x11c ], %g1
a00c5c5c:  90 0b 60 01  and  %o5, 1, %o0
a00c5c60:  9b 2a 20 04  sll  %o0, 4, %o5
a00c5c64:  b0 08 7f ef  and  %g1, -17, %i0
a00c5c68:  9e 16 00 0d  or  %i0, %o5, %o7
a00c5c6c:  80 8b e0 10  btst  0x10, %o7
a00c5c70:  12 80 00 31  bne  0xa00c5d34
a00c5c74:  de 23 21 1c  st  %o7, [ %o4 + 0x11c ]
a00c5c78:  40 00 4e bb  call  0xa00d9764
a00c5c7c:  01 00 00 00  nop
a00c5c80:  40 00 3b 46  call  0xa00d4998
a00c5c84:  01 00 00 00  nop
a00c5c88:  80 a4 20 02  cmp  %l0, 2
a00c5c8c:  02 80 00 32  be  0xa00c5d54
a00c5c90:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5c94:  80 a4 20 03  cmp  %l0, 3
a00c5c98:  02 80 00 51  be  0xa00c5ddc
a00c5c9c:  9e 10 20 30  mov  0x30, %o7
a00c5ca0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c5ca4:  94 12 60 78  or  %o1, 0x78, %o2	! 0xa802d078
a00c5ca8:  82 10 20 35  mov  0x35, %g1
a00c5cac:  90 10 20 36  mov  0x36, %o0
a00c5cb0:  9a 10 20 2b  mov  0x2b, %o5
a00c5cb4:  b0 10 20 0d  mov  0xd, %i0
a00c5cb8:  c2 2a 60 78  stb  %g1, [ %o1 + 0x78 ]
a00c5cbc:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c5cc0:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c5cc4:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c5cc8:  f0 2a a0 05  stb  %i0, [ %o2 + 5 ]
a00c5ccc:  80 a4 20 02  cmp  %l0, 2
a00c5cd0:  02 80 00 2d  be  0xa00c5d84
a00c5cd4:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c5cd8:  80 a4 20 03  cmp  %l0, 3
a00c5cdc:  02 80 00 4d  be  0xa00c5e10
a00c5ce0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c5ce4:  9a 12 20 d0  or  %o0, 0xd0, %o5	! 0xa802d0d0
a00c5ce8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c5cec:  c0 2a 60 9c  clrb  [ %o1 + 0x9c ]	! 0xa802b09c
a00c5cf0:  c0 2a 20 d0  clrb  [ %o0 + 0xd0 ]
a00c5cf4:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c5cf8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c5cfc:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c5d00:  80 a4 20 02  cmp  %l0, 2
a00c5d04:  02 80 00 29  be  0xa00c5da8
a00c5d08:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c5d0c:  80 a4 20 03  cmp  %l0, 3
a00c5d10:  12 80 00 29  bne  0xa00c5db4
a00c5d14:  90 10 00 10  mov  %l0, %o0
a00c5d18:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c5d1c:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00c5d20:  90 10 20 03  mov  3, %o0
a00c5d24:  40 02 0a b1  call  0xa01487e8
a00c5d28:  92 10 20 06  mov  6, %o1
a00c5d2c:  10 80 00 43  b  0xa00c5e38
a00c5d30:  b0 10 20 00  clr  %i0
a00c5d34:  40 00 4e 8c  call  0xa00d9764
a00c5d38:  c0 2b 21 78  clrb  [ %o4 + 0x178 ]
a00c5d3c:  40 00 3b 17  call  0xa00d4998
a00c5d40:  01 00 00 00  nop
a00c5d44:  80 a4 20 02  cmp  %l0, 2
a00c5d48:  12 bf ff d4  bne  0xa00c5c98
a00c5d4c:  80 a4 20 03  cmp  %l0, 3
a00c5d50:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c5d54:  98 16 21 28  or  %i0, 0x128, %o4	! 0xa802d128
a00c5d58:  a0 10 20 30  mov  0x30, %l0
a00c5d5c:  9a 10 20 35  mov  0x35, %o5
a00c5d60:  9e 10 20 0d  mov  0xd, %o7
a00c5d64:  96 10 20 36  mov  0x36, %o3
a00c5d68:  94 10 20 2b  mov  0x2b, %o2
a00c5d6c:  da 2e 21 28  stb  %o5, [ %i0 + 0x128 ]
a00c5d70:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c5d74:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00c5d78:  e0 2b 20 03  stb  %l0, [ %o4 + 3 ]
a00c5d7c:  d4 2b 20 04  stb  %o2, [ %o4 + 4 ]
a00c5d80:  e0 2b 20 02  stb  %l0, [ %o4 + 2 ]
a00c5d84:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c5d88:  a0 13 20 40  or  %o4, 0x40, %l0	! 0xa802d040
a00c5d8c:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00c5d90:  c0 2a a0 9a  clrb  [ %o2 + 0x9a ]	! 0xa802b09a
a00c5d94:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00c5d98:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c5d9c:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a00c5da0:  c0 2c 20 07  clrb  [ %l0 + 7 ]
a00c5da4:  c0 2c 20 0a  clrb  [ %l0 + 0xa ]
a00c5da8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5dac:  94 10 61 28  or  %g1, 0x128, %o2	! 0xa802d128
a00c5db0:  90 10 20 02  mov  2, %o0
a00c5db4:  40 02 0a 8d  call  0xa01487e8
a00c5db8:  92 10 20 06  mov  6, %o1
a00c5dbc:  10 80 00 1f  b  0xa00c5e38
a00c5dc0:  b0 10 20 00  clr  %i0
a00c5dc4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c5dc8:  10 bf ff 9c  b  0xa00c5c38
a00c5dcc:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c5dd0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c5dd4:  10 bf ff 99  b  0xa00c5c38
a00c5dd8:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c5ddc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c5de0:  90 12 a1 08  or  %o2, 0x108, %o0	! 0xa802d108
a00c5de4:  92 10 20 30  mov  0x30, %o1
a00c5de8:  96 10 20 35  mov  0x35, %o3
a00c5dec:  a0 10 20 0d  mov  0xd, %l0
a00c5df0:  98 10 20 36  mov  0x36, %o4
a00c5df4:  82 10 20 2b  mov  0x2b, %g1
a00c5df8:  d6 2a a1 08  stb  %o3, [ %o2 + 0x108 ]
a00c5dfc:  e0 2a 20 05  stb  %l0, [ %o0 + 5 ]
a00c5e00:  d8 2a 20 01  stb  %o4, [ %o0 + 1 ]
a00c5e04:  d2 2a 20 03  stb  %o1, [ %o0 + 3 ]
a00c5e08:  c2 2a 20 04  stb  %g1, [ %o0 + 4 ]
a00c5e0c:  d2 2a 20 02  stb  %o1, [ %o0 + 2 ]
a00c5e10:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c5e14:  96 13 e0 98  or  %o7, 0x98, %o3	! 0xa802d098
a00c5e18:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c5e1c:  c0 2e 20 98  clrb  [ %i0 + 0x98 ]	! 0xa802b098
a00c5e20:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00c5e24:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c5e28:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c5e2c:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c5e30:  10 bf ff ba  b  0xa00c5d18
a00c5e34:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c5e38:  81 c7 e0 08  ret
a00c5e3c:  81 e8 00 00  restore
