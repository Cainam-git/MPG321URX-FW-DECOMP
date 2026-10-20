# leon2m FUN_a0126c58 0xa0126c58-0xa0126dcc (372 bytes)
a0126c58:  9d e3 bf 90  save  %sp, -112, %sp
a0126c5c:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0126c60:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0126c64:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a0126c68:  7f ff f7 18  call  0xa01248c8
a0126c6c:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a0126c70:  80 8a 20 ff  btst  0xff, %o0
a0126c74:  02 80 00 54  be  0xa0126dc4
a0126c78:  15 00 06 91  sethi  %hi(0x1a4400), %o2
a0126c7c:  92 0e 20 ff  and  %i0, 0xff, %o1
a0126c80:  7f fe e1 3c  call  0xa00df170
a0126c84:  90 12 a2 70  or  %o2, 0x270, %o0
a0126c88:  82 10 20 01  mov  1, %g1
a0126c8c:  a4 10 20 02  mov  2, %l2
a0126c90:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0126c94:  9a 10 00 11  mov  %l1, %o5
a0126c98:  92 10 20 02  mov  2, %o1
a0126c9c:  94 10 20 72  mov  0x72, %o2
a0126ca0:  96 10 20 05  mov  5, %o3
a0126ca4:  98 10 20 00  clr  %o4
a0126ca8:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126cac:  40 00 83 7d  call  0xa0147aa0
a0126cb0:  90 10 20 60  mov  0x60, %o0
a0126cb4:  67 fd 99 3b  call  0x4008d1a0
a0126cb8:  90 10 20 32  mov  0x32, %o0
a0126cbc:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a0126cc0:  96 10 20 05  mov  5, %o3
a0126cc4:  98 10 20 00  clr  %o4
a0126cc8:  9a 15 a0 88  or  %l6, 0x88, %o5
a0126ccc:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126cd0:  92 10 20 02  mov  2, %o1
a0126cd4:  94 10 20 72  mov  0x72, %o2
a0126cd8:  40 00 83 84  call  0xa0147ae8
a0126cdc:  90 10 20 60  mov  0x60, %o0
a0126ce0:  a0 15 a0 88  or  %l6, 0x88, %l0
a0126ce4:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126ce8:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0126cec:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0126cf0:  7f fe e1 20  call  0xa00df170
a0126cf4:  90 12 22 a0  or  %o0, 0x2a0, %o0
a0126cf8:  a4 10 00 11  mov  %l1, %l2
a0126cfc:  90 10 20 32  mov  0x32, %o0
a0126d00:  67 fd 99 28  call  0x4008d1a0
a0126d04:  a2 10 00 10  mov  %l0, %l1
a0126d08:  a8 10 00 15  mov  %l5, %l4
a0126d0c:  a6 10 00 16  mov  %l6, %l3
a0126d10:  10 80 00 1f  b  0xa0126d8c
a0126d14:  a0 10 20 02  mov  2, %l0
a0126d18:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126d1c:  80 a2 e0 09  cmp  %o3, 9
a0126d20:  18 80 00 29  bgu  0xa0126dc4
a0126d24:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a0126d28:  7f fe e1 12  call  0xa00df170
a0126d2c:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a0126d30:  98 10 20 01  mov  1, %o4
a0126d34:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a0126d38:  92 10 20 02  mov  2, %o1
a0126d3c:  94 10 20 72  mov  0x72, %o2
a0126d40:  96 10 20 05  mov  5, %o3
a0126d44:  98 10 20 00  clr  %o4
a0126d48:  9a 10 00 12  mov  %l2, %o5
a0126d4c:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126d50:  40 00 83 54  call  0xa0147aa0
a0126d54:  90 10 20 60  mov  0x60, %o0
a0126d58:  67 fd 99 12  call  0x4008d1a0
a0126d5c:  90 10 20 05  mov  5, %o0
a0126d60:  92 10 20 02  mov  2, %o1
a0126d64:  96 10 20 05  mov  5, %o3
a0126d68:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126d6c:  90 10 20 60  mov  0x60, %o0
a0126d70:  94 10 20 72  mov  0x72, %o2
a0126d74:  98 10 20 00  clr  %o4
a0126d78:  40 00 83 5c  call  0xa0147ae8
a0126d7c:  9a 10 00 11  mov  %l1, %o5
a0126d80:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126d84:  92 02 e0 01  add  %o3, 1, %o1
a0126d88:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0126d8c:  31 00 06 91  sethi  %hi(0x1a4400), %i0
a0126d90:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0126d94:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a0126d98:  90 16 22 d0  or  %i0, 0x2d0, %o0
a0126d9c:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0126da0:  94 10 00 0d  mov  %o5, %o2
a0126da4:  80 a3 40 0f  cmp  %o5, %o7
a0126da8:  12 bf ff dc  bne  0xa0126d18
a0126dac:  98 10 00 0f  mov  %o7, %o4
a0126db0:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0126db4:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a0126db8:  80 a2 40 01  cmp  %o1, %g1
a0126dbc:  12 bf ff d8  bne  0xa0126d1c
a0126dc0:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0126dc4:  81 c7 e0 08  ret
a0126dc8:  81 e8 00 00  restore
