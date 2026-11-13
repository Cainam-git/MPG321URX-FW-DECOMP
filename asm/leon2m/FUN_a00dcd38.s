# leon2m FUN_a00dcd38 0xa00dcd38-0xa00dcec4 (396 bytes)
a00dcd38:  9d e3 bf 98  save  %sp, -104, %sp
a00dcd3c:  a0 96 20 00  orcc  %i0, 0, %l0
a00dcd40:  02 80 00 5f  be  0xa00dcebc
a00dcd44:  b0 10 20 00  clr  %i0
a00dcd48:  10 80 00 08  b  0xa00dcd68
a00dcd4c:  94 10 20 00  clr  %o2
a00dcd50:  02 80 00 11  be  0xa00dcd94
a00dcd54:  80 a2 a0 20  cmp  %o2, 0x20
a00dcd58:  94 02 a0 01  inc  %o2
a00dcd5c:  80 a2 a0 1f  cmp  %o2, 0x1f
a00dcd60:  14 80 00 0d  bg  0xa00dcd94
a00dcd64:  80 a2 a0 20  cmp  %o2, 0x20
a00dcd68:  d6 4c 00 0a  ldsb  [ %l0 + %o2 ], %o3
a00dcd6c:  90 1a e0 0a  xor  %o3, 0xa, %o0
a00dcd70:  80 a0 00 08  cmp  %g0, %o0
a00dcd74:  98 60 3f ff  subx  %g0, -1, %o4
a00dcd78:  82 1a e0 0d  xor  %o3, 0xd, %g1
a00dcd7c:  80 a0 00 01  cmp  %g0, %g1
a00dcd80:  9a 60 3f ff  subx  %g0, -1, %o5
a00dcd84:  80 93 00 0d  orcc  %o4, %o5, %g0
a00dcd88:  02 bf ff f2  be  0xa00dcd50
a00dcd8c:  80 a2 e0 00  cmp  %o3, 0
a00dcd90:  80 a2 a0 20  cmp  %o2, 0x20
a00dcd94:  22 80 00 02  be,a   0xa00dcd9c
a00dcd98:  94 10 20 1f  mov  0x1f, %o2
a00dcd9c:  c0 2c 00 0a  clrb  [ %l0 + %o2 ]
a00dcda0:  40 00 02 a7  call  0xa00dd83c
a00dcda4:  90 10 00 10  mov  %l0, %o0
a00dcda8:  d2 4c 00 00  ldsb  [ %l0 ], %o1
a00dcdac:  80 a2 60 30  cmp  %o1, 0x30
a00dcdb0:  02 80 00 12  be  0xa00dcdf8
a00dcdb4:  96 10 20 00  clr  %o3
a00dcdb8:  80 a2 20 09  cmp  %o0, 9
a00dcdbc:  14 80 00 40  bg  0xa00dcebc
a00dcdc0:  b0 10 3f ff  mov  -1, %i0
a00dcdc4:  10 80 00 08  b  0xa00dcde4
a00dcdc8:  98 10 20 00  clr  %o4
a00dcdcc:  b0 03 40 0b  add  %o5, %o3, %i0
a00dcdd0:  96 06 00 18  add  %i0, %i0, %o3
a00dcdd4:  d4 4c 00 0c  ldsb  [ %l0 + %o4 ], %o2
a00dcdd8:  92 02 c0 0a  add  %o3, %o2, %o1
a00dcddc:  98 03 20 01  inc  %o4
a00dcde0:  96 02 7f d0  add  %o1, -48, %o3
a00dcde4:  80 a3 00 08  cmp  %o4, %o0
a00dcde8:  06 bf ff f9  bl  0xa00dcdcc
a00dcdec:  9b 2a e0 02  sll  %o3, 2, %o5
a00dcdf0:  10 80 00 33  b  0xa00dcebc
a00dcdf4:  b0 10 00 0b  mov  %o3, %i0
a00dcdf8:  d8 4c 20 01  ldsb  [ %l0 + 1 ], %o4
a00dcdfc:  9a 1b 20 58  xor  %o4, 0x58, %o5
a00dce00:  80 a0 00 0d  cmp  %g0, %o5
a00dce04:  9e 60 3f ff  subx  %g0, -1, %o7
a00dce08:  b0 1b 20 78  xor  %o4, 0x78, %i0
a00dce0c:  80 a0 00 18  cmp  %g0, %i0
a00dce10:  94 60 3f ff  subx  %g0, -1, %o2
a00dce14:  80 93 c0 0a  orcc  %o7, %o2, %g0
a00dce18:  02 bf ff e9  be  0xa00dcdbc
a00dce1c:  80 a2 20 09  cmp  %o0, 9
a00dce20:  92 10 20 02  mov  2, %o1
a00dce24:  80 a2 40 08  cmp  %o1, %o0
a00dce28:  16 80 00 25  bge  0xa00dcebc
a00dce2c:  b0 10 00 0b  mov  %o3, %i0
a00dce30:  d4 4c 00 09  ldsb  [ %l0 + %o1 ], %o2
a00dce34:  9e 1a a0 20  xor  %o2, 0x20, %o7
a00dce38:  80 a0 00 0f  cmp  %g0, %o7
a00dce3c:  98 60 3f ff  subx  %g0, -1, %o4
a00dce40:  9a 1a a0 09  xor  %o2, 9, %o5
a00dce44:  80 a0 00 0d  cmp  %g0, %o5
a00dce48:  b0 60 3f ff  subx  %g0, -1, %i0
a00dce4c:  80 93 00 18  orcc  %o4, %i0, %g0
a00dce50:  d8 0c 00 09  ldub  [ %l0 + %o1 ], %o4
a00dce54:  82 03 3f d0  add  %o4, -48, %g1
a00dce58:  9e 03 3f 9f  add  %o4, -97, %o7
a00dce5c:  82 08 60 ff  and  %g1, 0xff, %g1
a00dce60:  12 bf ff e4  bne  0xa00dcdf0
a00dce64:  9a 0b e0 ff  and  %o7, 0xff, %o5
a00dce68:  80 a0 60 09  cmp  %g1, 9
a00dce6c:  97 2a e0 04  sll  %o3, 4, %o3
a00dce70:  18 80 00 05  bgu  0xa00dce84
a00dce74:  82 02 80 0b  add  %o2, %o3, %g1
a00dce78:  96 00 7f d0  add  %g1, -48, %o3
a00dce7c:  10 bf ff ea  b  0xa00dce24
a00dce80:  92 02 60 01  inc  %o1
a00dce84:  82 03 3f bf  add  %o4, -65, %g1
a00dce88:  98 02 80 0b  add  %o2, %o3, %o4
a00dce8c:  80 a3 60 05  cmp  %o5, 5
a00dce90:  18 80 00 05  bgu  0xa00dcea4
a00dce94:  82 08 60 ff  and  %g1, 0xff, %g1
a00dce98:  96 03 3f a9  add  %o4, -87, %o3
a00dce9c:  10 bf ff e2  b  0xa00dce24
a00dcea0:  92 02 60 01  inc  %o1
a00dcea4:  80 a0 60 05  cmp  %g1, 5
a00dcea8:  18 bf ff f5  bgu  0xa00dce7c
a00dceac:  9a 02 80 0b  add  %o2, %o3, %o5
a00dceb0:  96 03 7f c9  add  %o5, -55, %o3
a00dceb4:  10 bf ff dc  b  0xa00dce24
a00dceb8:  92 02 60 01  inc  %o1
a00dcebc:  81 c7 e0 08  ret
a00dcec0:  81 e8 00 00  restore
