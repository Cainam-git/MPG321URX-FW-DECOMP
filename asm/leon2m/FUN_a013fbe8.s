# leon2m FUN_a013fbe8 0xa013fbe8-0xa013fe2c (580 bytes)
a013fbe8:  9d e3 bf 98  save  %sp, -104, %sp
a013fbec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013fbf0:  7f ff f4 57  call  0xa013cd4c
a013fbf4:  90 10 00 18  mov  %i0, %o0
a013fbf8:  a6 10 00 08  mov  %o0, %l3
a013fbfc:  40 00 0c a4  call  0xa0142e8c
a013fc00:  90 10 00 18  mov  %i0, %o0
a013fc04:  90 0a 20 ff  and  %o0, 0xff, %o0
a013fc08:  80 a2 20 05  cmp  %o0, 5
a013fc0c:  02 80 00 86  be  0xa013fe24
a013fc10:  01 00 00 00  nop
a013fc14:  7f ff f4 4e  call  0xa013cd4c
a013fc18:  90 10 00 18  mov  %i0, %o0
a013fc1c:  23 00 06 96  sethi  %hi(0x1a5800), %l1
a013fc20:  98 14 62 16  or  %l1, 0x216, %o4	! 0x1a5a16
a013fc24:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a013fc28:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a013fc2c:  da 13 20 02  lduh  [ %o4 + 2 ], %o5
a013fc30:  80 a3 40 01  cmp  %o5, %g1
a013fc34:  a0 10 20 00  clr  %l0
a013fc38:  02 80 00 18  be  0xa013fc98
a013fc3c:  96 10 20 00  clr  %o3
a013fc40:  92 10 00 0c  mov  %o4, %o1
a013fc44:  9e 10 00 01  mov  %g1, %o7
a013fc48:  98 10 20 00  clr  %o4
a013fc4c:  d4 12 20 3c  lduh  [ %o0 + 0x3c ], %o2
a013fc50:  a5 2b 20 03  sll  %o4, 3, %l2
a013fc54:  82 04 80 0c  add  %l2, %o4, %g1
a013fc58:  9b 28 60 02  sll  %g1, 2, %o5
a013fc5c:  a4 03 40 09  add  %o5, %o1, %l2
a013fc60:  d8 14 a0 22  lduh  [ %l2 + 0x22 ], %o4
a013fc64:  80 a2 80 0c  cmp  %o2, %o4
a013fc68:  22 80 00 0c  be,a   0xa013fc98
a013fc6c:  a0 10 20 01  mov  1, %l0
a013fc70:  96 02 e0 01  inc  %o3
a013fc74:  98 0a e0 ff  and  %o3, 0xff, %o4
a013fc78:  83 2b 20 03  sll  %o4, 3, %g1
a013fc7c:  9a 00 40 0c  add  %g1, %o4, %o5
a013fc80:  a5 2b 60 02  sll  %o5, 2, %l2
a013fc84:  82 04 80 09  add  %l2, %o1, %g1
a013fc88:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a013fc8c:  80 a3 40 0f  cmp  %o5, %o7
a013fc90:  12 bf ff f1  bne  0xa013fc54
a013fc94:  a5 2b 20 03  sll  %o4, 3, %l2
a013fc98:  80 8c 20 ff  btst  0xff, %l0
a013fc9c:  12 80 00 3f  bne  0xa013fd98
a013fca0:  82 10 20 ff  mov  0xff, %g1
a013fca4:  a0 08 60 ff  and  %g1, 0xff, %l0
a013fca8:  80 a4 20 ff  cmp  %l0, 0xff
a013fcac:  02 80 00 5e  be  0xa013fe24
a013fcb0:  01 00 00 00  nop
a013fcb4:  7f ff f4 26  call  0xa013cd4c
a013fcb8:  90 10 00 18  mov  %i0, %o0
a013fcbc:  97 2c 20 03  sll  %l0, 3, %o3
a013fcc0:  98 02 c0 10  add  %o3, %l0, %o4
a013fcc4:  92 14 62 16  or  %l1, 0x216, %o1
a013fcc8:  97 2b 20 02  sll  %o4, 2, %o3
a013fccc:  98 02 c0 09  add  %o3, %o1, %o4
a013fcd0:  e4 13 20 0e  lduh  [ %o4 + 0xe ], %l2
a013fcd4:  e4 32 20 12  sth  %l2, [ %o0 + 0x12 ]
a013fcd8:  e2 13 20 10  lduh  [ %o4 + 0x10 ], %l1
a013fcdc:  e2 32 20 14  sth  %l1, [ %o0 + 0x14 ]
a013fce0:  e2 13 20 12  lduh  [ %o4 + 0x12 ], %l1
a013fce4:  e2 32 20 16  sth  %l1, [ %o0 + 0x16 ]
a013fce8:  e0 13 20 14  lduh  [ %o4 + 0x14 ], %l0
a013fcec:  e0 32 20 18  sth  %l0, [ %o0 + 0x18 ]
a013fcf0:  e0 13 20 0a  lduh  [ %o4 + 0xa ], %l0
a013fcf4:  e0 32 20 0e  sth  %l0, [ %o0 + 0xe ]
a013fcf8:  e4 13 20 1a  lduh  [ %o4 + 0x1a ], %l2
a013fcfc:  e4 32 20 1e  sth  %l2, [ %o0 + 0x1e ]
a013fd00:  f0 13 20 1c  lduh  [ %o4 + 0x1c ], %i0
a013fd04:  f0 32 20 20  sth  %i0, [ %o0 + 0x20 ]
a013fd08:  de 13 20 16  lduh  [ %o4 + 0x16 ], %o7
a013fd0c:  de 32 20 1a  sth  %o7, [ %o0 + 0x1a ]
a013fd10:  d4 13 20 18  lduh  [ %o4 + 0x18 ], %o2
a013fd14:  d4 32 20 1c  sth  %o2, [ %o0 + 0x1c ]
a013fd18:  d4 13 20 0a  lduh  [ %o4 + 0xa ], %o2
a013fd1c:  d4 32 20 28  sth  %o2, [ %o0 + 0x28 ]
a013fd20:  de 13 20 16  lduh  [ %o4 + 0x16 ], %o7
a013fd24:  de 32 20 2a  sth  %o7, [ %o0 + 0x2a ]
a013fd28:  da 13 20 18  lduh  [ %o4 + 0x18 ], %o5
a013fd2c:  82 10 20 20  mov  0x20, %g1
a013fd30:  da 32 20 2c  sth  %o5, [ %o0 + 0x2c ]
a013fd34:  c2 2a 20 26  stb  %g1, [ %o0 + 0x26 ]
a013fd38:  c0 2a 20 3a  clrb  [ %o0 + 0x3a ]
a013fd3c:  f0 13 20 22  lduh  [ %o4 + 0x22 ], %i0
a013fd40:  f0 32 20 3c  sth  %i0, [ %o0 + 0x3c ]
a013fd44:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a013fd48:  80 a0 60 00  cmp  %g1, 0
a013fd4c:  32 80 00 04  bne,a   0xa013fd5c
a013fd50:  b0 08 60 ff  and  %g1, 0xff, %i0
a013fd54:  40 00 51 5c  call  0xa01542c4
a013fd58:  91 ec e0 06  restore  %l3, 6, %o0
a013fd5c:  9a 5c 40 18  smul  %l1, %i0, %o5
a013fd60:  da 32 20 16  sth  %o5, [ %o0 + 0x16 ]
a013fd64:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a013fd68:  98 5c 00 01  smul  %l0, %g1, %o4
a013fd6c:  d8 32 20 0e  sth  %o4, [ %o0 + 0xe ]
a013fd70:  e2 0a 40 0b  ldub  [ %o1 + %o3 ], %l1
a013fd74:  a0 5c 80 11  smul  %l2, %l1, %l0
a013fd78:  e0 32 20 1e  sth  %l0, [ %o0 + 0x1e ]
a013fd7c:  f0 0a 40 0b  ldub  [ %o1 + %o3 ], %i0
a013fd80:  9a 5a 80 18  smul  %o2, %i0, %o5
a013fd84:  da 32 20 28  sth  %o5, [ %o0 + 0x28 ]
a013fd88:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a013fd8c:  92 5b c0 01  smul  %o7, %g1, %o1
a013fd90:  10 bf ff f1  b  0xa013fd54
a013fd94:  d2 32 20 2a  sth  %o1, [ %o0 + 0x2a ]
a013fd98:  94 02 e0 01  add  %o3, 1, %o2
a013fd9c:  d2 12 20 3c  lduh  [ %o0 + 0x3c ], %o1
a013fda0:  21 00 06 96  sethi  %hi(0x1a5800), %l0
a013fda4:  17 00 00 3f  sethi  %hi(0xfc00), %o3
a013fda8:  9e 14 22 16  or  %l0, 0x216, %o7
a013fdac:  98 12 e3 ff  or  %o3, 0x3ff, %o4
a013fdb0:  10 80 00 0f  b  0xa013fdec
a013fdb4:  91 2a 60 10  sll  %o1, 0x10, %o0
a013fdb8:  9b 2a e0 03  sll  %o3, 3, %o5
a013fdbc:  a4 03 40 0b  add  %o5, %o3, %l2
a013fdc0:  a1 2c a0 02  sll  %l2, 2, %l0
a013fdc4:  82 04 00 0f  add  %l0, %o7, %g1
a013fdc8:  da 10 60 22  lduh  [ %g1 + 0x22 ], %o5
a013fdcc:  a5 2b 60 10  sll  %o5, 0x10, %l2
a013fdd0:  83 34 a0 18  srl  %l2, 0x18, %g1
a013fdd4:  80 a4 80 08  cmp  %l2, %o0
a013fdd8:  02 80 00 11  be  0xa013fe1c
a013fddc:  94 02 a0 01  inc  %o2
a013fde0:  80 a2 40 01  cmp  %o1, %g1
a013fde4:  02 bf ff b0  be  0xa013fca4
a013fde8:  82 10 00 0b  mov  %o3, %g1
a013fdec:  96 0a a0 ff  and  %o2, 0xff, %o3
a013fdf0:  a1 2a e0 03  sll  %o3, 3, %l0
a013fdf4:  92 04 00 0b  add  %l0, %o3, %o1
a013fdf8:  83 2a 60 02  sll  %o1, 2, %g1
a013fdfc:  9a 00 40 0f  add  %g1, %o7, %o5
a013fe00:  e4 13 60 02  lduh  [ %o5 + 2 ], %l2
a013fe04:  80 a4 80 0c  cmp  %l2, %o4
a013fe08:  12 bf ff ec  bne  0xa013fdb8
a013fe0c:  93 32 20 18  srl  %o0, 0x18, %o1
a013fe10:  96 10 20 00  clr  %o3
a013fe14:  10 bf ff e9  b  0xa013fdb8
a013fe18:  94 10 20 00  clr  %o2
a013fe1c:  10 bf ff a2  b  0xa013fca4
a013fe20:  82 10 20 ff  mov  0xff, %g1
a013fe24:  81 c7 e0 08  ret
a013fe28:  81 e8 00 00  restore
