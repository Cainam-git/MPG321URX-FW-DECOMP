# leon2m FUN_a0126dcc 0xa0126dcc-0xa0126f4c (384 bytes)
a0126dcc:  9d e3 bf 90  save  %sp, -112, %sp
a0126dd0:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a0126dd4:  a4 14 e0 90  or  %l3, 0x90, %l2	! 0xa802d890
a0126dd8:  f0 2c a0 01  stb  %i0, [ %l2 + 1 ]
a0126ddc:  7f ff f6 bb  call  0xa01248c8
a0126de0:  c0 2c e0 90  clrb  [ %l3 + 0x90 ]
a0126de4:  80 8a 20 ff  btst  0xff, %o0
a0126de8:  02 80 00 57  be  0xa0126f44
a0126dec:  a2 10 20 00  clr  %l1
a0126df0:  13 00 06 91  sethi  %hi(0x1a4400), %o1
a0126df4:  90 12 63 10  or  %o1, 0x310, %o0	! 0x1a4710
a0126df8:  d4 0c a0 01  ldub  [ %l2 + 1 ], %o2
a0126dfc:  7f fe e0 dd  call  0xa00df170
a0126e00:  d2 0c e0 90  ldub  [ %l3 + 0x90 ], %o1
a0126e04:  82 10 20 01  mov  1, %g1
a0126e08:  a0 10 20 02  mov  2, %l0
a0126e0c:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0126e10:  9a 10 00 12  mov  %l2, %o5
a0126e14:  92 10 20 02  mov  2, %o1
a0126e18:  94 10 20 a0  mov  0xa0, %o2
a0126e1c:  96 10 20 05  mov  5, %o3
a0126e20:  98 10 20 00  clr  %o4
a0126e24:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126e28:  40 00 83 1e  call  0xa0147aa0
a0126e2c:  90 10 20 60  mov  0x60, %o0
a0126e30:  67 fd 98 dc  call  0x4008d1a0
a0126e34:  90 10 20 32  mov  0x32, %o0
a0126e38:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a0126e3c:  96 10 20 05  mov  5, %o3
a0126e40:  98 10 20 00  clr  %o4
a0126e44:  9a 15 a0 88  or  %l6, 0x88, %o5
a0126e48:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0126e4c:  92 10 20 02  mov  2, %o1
a0126e50:  94 10 20 a0  mov  0xa0, %o2
a0126e54:  40 00 83 25  call  0xa0147ae8
a0126e58:  90 10 20 60  mov  0x60, %o0
a0126e5c:  a0 15 a0 88  or  %l6, 0x88, %l0
a0126e60:  11 00 06 91  sethi  %hi(0x1a4400), %o0
a0126e64:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a0126e68:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a0126e6c:  7f fe e0 c1  call  0xa00df170
a0126e70:  90 12 23 30  or  %o0, 0x330, %o0
a0126e74:  90 10 20 32  mov  0x32, %o0
a0126e78:  67 fd 98 ca  call  0x4008d1a0
a0126e7c:  b0 10 00 12  mov  %l2, %i0
a0126e80:  aa 10 00 13  mov  %l3, %l5
a0126e84:  a8 10 00 16  mov  %l6, %l4
a0126e88:  10 80 00 24  b  0xa0126f18
a0126e8c:  a4 10 20 02  mov  2, %l2
a0126e90:  80 a3 20 09  cmp  %o4, 9
a0126e94:  18 80 00 2c  bgu  0xa0126f44
a0126e98:  01 00 00 00  nop
a0126e9c:  7f ff f6 8b  call  0xa01248c8
a0126ea0:  01 00 00 00  nop
a0126ea4:  80 8a 20 ff  btst  0xff, %o0
a0126ea8:  19 00 06 91  sethi  %hi(0x1a4400), %o4
a0126eac:  02 80 00 26  be  0xa0126f44
a0126eb0:  90 13 23 50  or  %o4, 0x350, %o0	! 0x1a4750
a0126eb4:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0126eb8:  d4 0e 20 01  ldub  [ %i0 + 1 ], %o2
a0126ebc:  d6 0d 20 88  ldub  [ %l4 + 0x88 ], %o3
a0126ec0:  7f fe e0 ac  call  0xa00df170
a0126ec4:  d8 0c 20 01  ldub  [ %l0 + 1 ], %o4
a0126ec8:  94 10 20 01  mov  1, %o2
a0126ecc:  d4 23 a0 60  st  %o2, [ %sp + 0x60 ]
a0126ed0:  92 10 20 02  mov  2, %o1
a0126ed4:  94 10 20 a0  mov  0xa0, %o2
a0126ed8:  96 10 20 05  mov  5, %o3
a0126edc:  98 10 20 00  clr  %o4
a0126ee0:  9a 10 00 18  mov  %i0, %o5
a0126ee4:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126ee8:  40 00 82 ee  call  0xa0147aa0
a0126eec:  90 10 20 60  mov  0x60, %o0
a0126ef0:  67 fd 98 ac  call  0x4008d1a0
a0126ef4:  90 10 20 32  mov  0x32, %o0
a0126ef8:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0126efc:  90 10 20 60  mov  0x60, %o0
a0126f00:  92 10 20 02  mov  2, %o1
a0126f04:  94 10 20 a0  mov  0xa0, %o2
a0126f08:  96 10 20 05  mov  5, %o3
a0126f0c:  98 10 20 00  clr  %o4
a0126f10:  40 00 82 f6  call  0xa0147ae8
a0126f14:  9a 10 00 10  mov  %l0, %o5
a0126f18:  da 0e 20 01  ldub  [ %i0 + 1 ], %o5
a0126f1c:  d6 0c 20 01  ldub  [ %l0 + 1 ], %o3
a0126f20:  98 0c 60 ff  and  %l1, 0xff, %o4
a0126f24:  80 a3 40 0b  cmp  %o5, %o3
a0126f28:  12 bf ff da  bne  0xa0126e90
a0126f2c:  a2 04 60 01  inc  %l1
a0126f30:  d0 0c e0 90  ldub  [ %l3 + 0x90 ], %o0
a0126f34:  de 0d a0 88  ldub  [ %l6 + 0x88 ], %o7
a0126f38:  80 a2 00 0f  cmp  %o0, %o7
a0126f3c:  12 bf ff d6  bne  0xa0126e94
a0126f40:  80 a3 20 09  cmp  %o4, 9
a0126f44:  81 c7 e0 08  ret
a0126f48:  81 e8 00 00  restore
