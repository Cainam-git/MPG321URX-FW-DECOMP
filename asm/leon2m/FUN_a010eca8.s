# leon2m FUN_a010eca8 0xa010eca8-0xa010ed50 (168 bytes)
a010eca8:  90 0a 20 ff  and  %o0, 0xff, %o0
a010ecac:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010ecb0:  93 2a 20 02  sll  %o0, 2, %o1
a010ecb4:  80 a2 20 01  cmp  %o0, 1
a010ecb8:  02 80 00 08  be  0xa010ecd8
a010ecbc:  96 10 63 c4  or  %g1, 0x3c4, %o3
a010ecc0:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a010ecc4:  80 a2 20 02  cmp  %o0, 2
a010ecc8:  12 80 00 04  bne  0xa010ecd8
a010eccc:  96 12 a3 44  or  %o2, 0x344, %o3
a010ecd0:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a010ecd4:  96 12 23 84  or  %o0, 0x384, %o3	! 0xa802d784
a010ecd8:  d4 12 e0 0e  lduh  [ %o3 + 0xe ], %o2
a010ecdc:  d8 0a e0 24  ldub  [ %o3 + 0x24 ], %o4
a010ece0:  c2 12 e0 0c  lduh  [ %o3 + 0xc ], %g1
a010ece4:  9a 02 bf ff  add  %o2, -1, %o5
a010ece8:  94 5b 40 01  smul  %o5, %g1, %o2
a010ecec:  91 33 20 03  srl  %o4, 3, %o0
a010ecf0:  9a 5a 80 08  smul  %o2, %o0, %o5
a010ecf4:  99 3b 60 1f  sra  %o5, 0x1f, %o4
a010ecf8:  83 33 20 1b  srl  %o4, 0x1b, %g1
a010ecfc:  d8 0a e0 3e  ldub  [ %o3 + 0x3e ], %o4
a010ed00:  90 03 40 01  add  %o5, %g1, %o0
a010ed04:  82 13 20 02  or  %o4, 2, %g1
a010ed08:  9b 3a 20 05  sra  %o0, 5, %o5
a010ed0c:  15 04 00 00  sethi  %hi(0x10000000), %o2
a010ed10:  90 13 40 0a  or  %o5, %o2, %o0
a010ed14:  c2 2a e0 3e  stb  %g1, [ %o3 + 0x3e ]
a010ed18:  19 00 06 6b  sethi  %hi(0x19ac00), %o4
a010ed1c:  d4 02 e0 04  ld  [ %o3 + 4 ], %o2
a010ed20:  82 13 22 d8  or  %o4, 0x2d8, %g1
a010ed24:  d8 00 40 09  ld  [ %g1 + %o1 ], %o4
a010ed28:  94 02 80 08  add  %o2, %o0, %o2
a010ed2c:  d4 23 20 24  st  %o2, [ %o4 + 0x24 ]
a010ed30:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010ed34:  d4 02 e0 08  ld  [ %o3 + 8 ], %o2
a010ed38:  98 10 62 cc  or  %g1, 0x2cc, %o4
a010ed3c:  96 02 80 08  add  %o2, %o0, %o3
a010ed40:  da 03 00 09  ld  [ %o4 + %o1 ], %o5
a010ed44:  d6 23 60 24  st  %o3, [ %o5 + 0x24 ]
a010ed48:  81 c3 e0 08  retl
a010ed4c:  01 00 00 00  nop
