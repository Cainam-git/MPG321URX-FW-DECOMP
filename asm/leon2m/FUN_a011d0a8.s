# leon2m FUN_a011d0a8 0xa011d0a8-0xa011d194 (236 bytes)
a011d0a8:  9c 03 bf 90  add  %sp, -112, %sp
a011d0ac:  98 10 20 00  clr  %o4
a011d0b0:  9a 10 20 00  clr  %o5
a011d0b4:  d8 3b a0 60  std  %o4, [ %sp + 0x60 ]
a011d0b8:  03 27 c6 c1  sethi  %hi(0x9f1b0400), %g1
a011d0bc:  94 10 62 00  or  %g1, 0x200, %o2	! 0x9f1b0600
a011d0c0:  96 03 a0 60  add  %sp, 0x60, %o3
a011d0c4:  98 10 20 00  clr  %o4
a011d0c8:  9a 10 20 00  clr  %o5
a011d0cc:  d0 0b 40 0a  ldub  [ %o5 + %o2 ], %o0
a011d0d0:  d0 2b 40 0b  stb  %o0, [ %o5 + %o3 ]
a011d0d4:  98 03 20 01  inc  %o4
a011d0d8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a011d0dc:  80 a3 60 08  cmp  %o5, 8
a011d0e0:  2a bf ff fc  bcs,a   0xa011d0d0
a011d0e4:  d0 0b 40 0a  ldub  [ %o5 + %o2 ], %o0
a011d0e8:  c2 0b a0 64  ldub  [ %sp + 0x64 ], %g1
a011d0ec:  99 28 60 08  sll  %g1, 8, %o4
a011d0f0:  da 0b a0 65  ldub  [ %sp + 0x65 ], %o5
a011d0f4:  96 03 00 0d  add  %o4, %o5, %o3
a011d0f8:  95 2a e0 10  sll  %o3, 0x10, %o2
a011d0fc:  83 32 a0 10  srl  %o2, 0x10, %g1
a011d100:  80 a0 65 04  cmp  %g1, 0x504
a011d104:  02 80 00 21  be  0xa011d188
a011d108:  90 10 20 04  mov  4, %o0
a011d10c:  80 a0 65 04  cmp  %g1, 0x504
a011d110:  14 80 00 0d  bg  0xa011d144
a011d114:  80 a0 65 51  cmp  %g1, 0x551
a011d118:  80 a0 65 01  cmp  %g1, 0x501
a011d11c:  02 80 00 1b  be  0xa011d188
a011d120:  90 10 20 02  mov  2, %o0
a011d124:  80 a0 65 01  cmp  %g1, 0x501
a011d128:  14 80 00 15  bg  0xa011d17c
a011d12c:  80 a0 65 02  cmp  %g1, 0x502
a011d130:  80 a0 65 00  cmp  %g1, 0x500
a011d134:  22 80 00 15  be,a   0xa011d188
a011d138:  90 10 20 01  mov  1, %o0
a011d13c:  10 80 00 13  b  0xa011d188
a011d140:  90 10 20 00  clr  %o0
a011d144:  02 80 00 11  be  0xa011d188
a011d148:  90 10 20 06  mov  6, %o0
a011d14c:  80 a0 65 51  cmp  %g1, 0x551
a011d150:  14 80 00 07  bg  0xa011d16c
a011d154:  80 a0 65 52  cmp  %g1, 0x552
a011d158:  80 a0 65 50  cmp  %g1, 0x550
a011d15c:  32 80 00 0b  bne,a   0xa011d188
a011d160:  90 10 20 00  clr  %o0
a011d164:  10 80 00 09  b  0xa011d188
a011d168:  90 10 20 05  mov  5, %o0
a011d16c:  32 80 00 07  bne,a   0xa011d188
a011d170:  90 10 20 00  clr  %o0
a011d174:  10 80 00 05  b  0xa011d188
a011d178:  90 10 20 07  mov  7, %o0
a011d17c:  32 80 00 03  bne,a   0xa011d188
a011d180:  90 10 20 00  clr  %o0
a011d184:  90 10 20 03  mov  3, %o0
a011d188:  90 0a 20 07  and  %o0, 7, %o0
a011d18c:  81 c3 e0 08  retl
a011d190:  9c 23 bf 90  sub  %sp, -112, %sp
