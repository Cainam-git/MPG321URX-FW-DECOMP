# leon2m FUN_a00fc044 0xa00fc044-0xa00fc15c (280 bytes)
a00fc044:  9d e3 bf 90  save  %sp, -112, %sp
a00fc048:  21 33 c0 3b  sethi  %hi(0xcf00ec00), %l0
a00fc04c:  a2 10 20 c0  mov  0xc0, %l1
a00fc050:  92 14 23 c0  or  %l0, 0x3c0, %o1
a00fc054:  c0 27 bf f4  clr  [ %fp + -12 ]
a00fc058:  e2 22 40 00  st  %l1, [ %o1 ]
a00fc05c:  92 07 bf f4  add  %fp, -12, %o1
a00fc060:  94 10 2f 00  mov  0xf00, %o2
a00fc064:  96 10 28 70  mov  0x870, %o3
a00fc068:  7f ff fc f3  call  0xa00fb434
a00fc06c:  90 10 20 03  mov  3, %o0
a00fc070:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00fc074:  d0 00 62 a4  ld  [ %g1 + 0x2a4 ], %o0	! 0xa802d6a4
a00fc078:  d6 12 20 0a  lduh  [ %o0 + 0xa ], %o3
a00fc07c:  d4 12 20 08  lduh  [ %o0 + 8 ], %o2
a00fc080:  92 07 bf f4  add  %fp, -12, %o1
a00fc084:  7f ff fc ec  call  0xa00fb434
a00fc088:  90 10 20 06  mov  6, %o0
a00fc08c:  92 10 20 01  mov  1, %o1
a00fc090:  94 10 20 00  clr  %o2
a00fc094:  7f ff ff 4e  call  0xa00fbdcc
a00fc098:  90 10 20 00  clr  %o0
a00fc09c:  9a 10 20 01  mov  1, %o5
a00fc0a0:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00fc0a4:  da 32 e3 ea  sth  %o5, [ %o3 + 0x3ea ]	! 0xa802b7ea
a00fc0a8:  92 10 20 04  mov  4, %o1
a00fc0ac:  94 10 20 00  clr  %o2
a00fc0b0:  7f ff ff 47  call  0xa00fbdcc
a00fc0b4:  90 10 20 00  clr  %o0
a00fc0b8:  13 34 01 00  sethi  %hi(0xd0040000), %o1
a00fc0bc:  d8 02 40 00  ld  [ %o1 ], %o4
a00fc0c0:  15 20 00 00  sethi  %hi(0x80000000), %o2
a00fc0c4:  9e 13 00 0a  or  %o4, %o2, %o7
a00fc0c8:  11 00 02 6a  sethi  %hi(0x9a800), %o0
a00fc0cc:  de 22 40 00  st  %o7, [ %o1 ]
a00fc0d0:  94 12 20 14  or  %o0, 0x14, %o2
a00fc0d4:  90 10 20 0c  mov  0xc, %o0
a00fc0d8:  67 fe 39 ea  call  0x4008a880
a00fc0dc:  92 10 21 00  mov  0x100, %o1
a00fc0e0:  90 10 20 0c  mov  0xc, %o0
a00fc0e4:  67 fe 35 cf  call  0x40089820
a00fc0e8:  92 10 21 00  mov  0x100, %o1
a00fc0ec:  11 33 c0 40  sethi  %hi(0xcf010000), %o0
a00fc0f0:  a0 14 21 80  or  %l0, 0x180, %l0
a00fc0f4:  82 10 20 08  mov  8, %g1
a00fc0f8:  c2 24 00 00  st  %g1, [ %l0 ]
a00fc0fc:  96 12 23 00  or  %o0, 0x300, %o3
a00fc100:  e2 22 c0 00  st  %l1, [ %o3 ]
a00fc104:  94 12 23 04  or  %o0, 0x304, %o2
a00fc108:  9a 10 20 40  mov  0x40, %o5
a00fc10c:  da 22 80 00  st  %o5, [ %o2 ]
a00fc110:  98 12 23 08  or  %o0, 0x308, %o4
a00fc114:  c0 23 00 00  clr  [ %o4 ]
a00fc118:  a2 12 23 0c  or  %o0, 0x30c, %l1
a00fc11c:  c0 24 40 00  clr  [ %l1 ]
a00fc120:  94 10 20 80  mov  0x80, %o2
a00fc124:  9e 12 23 10  or  %o0, 0x310, %o7
a00fc128:  d4 23 c0 00  st  %o2, [ %o7 ]
a00fc12c:  92 12 23 14  or  %o0, 0x314, %o1
a00fc130:  d4 22 40 00  st  %o2, [ %o1 ]
a00fc134:  96 12 23 18  or  %o0, 0x318, %o3
a00fc138:  82 10 20 13  mov  0x13, %g1
a00fc13c:  c2 22 c0 00  st  %g1, [ %o3 ]
a00fc140:  9a 12 23 1c  or  %o0, 0x31c, %o5
a00fc144:  c0 23 40 00  clr  [ %o5 ]
a00fc148:  98 12 23 30  or  %o0, 0x330, %o4
a00fc14c:  d4 23 00 00  st  %o2, [ %o4 ]
a00fc150:  c0 24 00 00  clr  [ %l0 ]
a00fc154:  81 c7 e0 08  ret
a00fc158:  81 e8 00 00  restore
