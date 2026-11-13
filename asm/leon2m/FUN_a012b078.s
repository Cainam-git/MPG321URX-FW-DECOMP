# leon2m FUN_a012b078 0xa012b078-0xa012b164 (236 bytes)
a012b078:  9d e3 bf 80  save  %sp, -128, %sp
a012b07c:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a012b080:  90 0e 20 ff  and  %i0, 0xff, %o0
a012b084:  9e 13 e1 a0  or  %o7, 0x1a0, %o7
a012b088:  d2 0b e0 2c  ldub  [ %o7 + 0x2c ], %o1
a012b08c:  97 2a 20 02  sll  %o0, 2, %o3
a012b090:  a1 3a 40 0b  sra  %o1, %o3, %l0
a012b094:  a7 2a 20 03  sll  %o0, 3, %l3
a012b098:  a4 10 20 03  mov  3, %l2
a012b09c:  ad 2c 80 13  sll  %l2, %l3, %l6
a012b0a0:  a2 0c 20 0f  and  %l0, 0xf, %l1
a012b0a4:  e4 03 e0 2c  ld  [ %o7 + 0x2c ], %l2
a012b0a8:  94 04 40 11  add  %l1, %l1, %o2
a012b0ac:  b1 2d 80 0a  sll  %l6, %o2, %i0
a012b0b0:  a8 0e 60 ff  and  %i1, 0xff, %l4
a012b0b4:  9b 34 a0 08  srl  %l2, 8, %o5
a012b0b8:  ab 2d 00 13  sll  %l4, %l3, %l5
a012b0bc:  98 2b 40 18  andn  %o5, %i0, %o4
a012b0c0:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a012b0c4:  83 2d 40 0a  sll  %l5, %o2, %g1
a012b0c8:  ac 12 e0 ae  or  %o3, 0xae, %l6
a012b0cc:  b0 5a 20 16  smul  %o0, 0x16, %i0
a012b0d0:  9a 06 00 16  add  %i0, %l6, %o5
a012b0d4:  92 13 00 01  or  %o4, %g1, %o1
a012b0d8:  21 3f c0 00  sethi  %hi(0xff000000), %l0
a012b0dc:  f2 2b 60 01  stb  %i1, [ %o5 + 1 ]
a012b0e0:  a7 2a 60 10  sll  %o1, 0x10, %l3
a012b0e4:  a2 14 20 ff  or  %l0, 0xff, %l1
a012b0e8:  a8 0c 80 11  and  %l2, %l1, %l4
a012b0ec:  b3 34 e0 08  srl  %l3, 8, %i1
a012b0f0:  ea 15 80 18  lduh  [ %l6 + %i0 ], %l5
a012b0f4:  94 15 00 19  or  %l4, %i1, %o2
a012b0f8:  d2 13 60 08  lduh  [ %o5 + 8 ], %o1
a012b0fc:  ec 13 60 14  lduh  [ %o5 + 0x14 ], %l6
a012b100:  c2 13 60 02  lduh  [ %o5 + 2 ], %g1
a012b104:  d8 13 60 04  lduh  [ %o5 + 4 ], %o4
a012b108:  d6 13 60 06  lduh  [ %o5 + 6 ], %o3
a012b10c:  e0 13 60 0a  lduh  [ %o5 + 0xa ], %l0
a012b110:  e2 13 60 0c  lduh  [ %o5 + 0xc ], %l1
a012b114:  e4 13 60 0e  lduh  [ %o5 + 0xe ], %l2
a012b118:  e6 13 60 10  lduh  [ %o5 + 0x10 ], %l3
a012b11c:  e8 13 60 12  lduh  [ %o5 + 0x12 ], %l4
a012b120:  d4 23 e0 2c  st  %o2, [ %o7 + 0x2c ]
a012b124:  d2 37 bf e8  sth  %o1, [ %fp + -24 ]
a012b128:  ea 37 bf e0  sth  %l5, [ %fp + -32 ]
a012b12c:  c2 37 bf e2  sth  %g1, [ %fp + -30 ]
a012b130:  d8 37 bf e4  sth  %o4, [ %fp + -28 ]
a012b134:  d6 37 bf e6  sth  %o3, [ %fp + -26 ]
a012b138:  e0 37 bf ea  sth  %l0, [ %fp + -22 ]
a012b13c:  e2 37 bf ec  sth  %l1, [ %fp + -20 ]
a012b140:  e4 37 bf ee  sth  %l2, [ %fp + -18 ]
a012b144:  e6 37 bf f0  sth  %l3, [ %fp + -16 ]
a012b148:  e8 37 bf f2  sth  %l4, [ %fp + -14 ]
a012b14c:  ec 37 bf f4  sth  %l6, [ %fp + -12 ]
a012b150:  40 00 32 46  call  0xa0137a68
a012b154:  92 07 bf e0  add  %fp, -32, %o1
a012b158:  01 00 00 00  nop
a012b15c:  81 c7 e0 08  ret
a012b160:  81 e8 00 00  restore
