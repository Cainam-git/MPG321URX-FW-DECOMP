# leon2s FUN_a008d0b8 0xa008d0b8-0xa008d1d8 (288 bytes)
a008d0b8:  9d e3 bf 98  save  %sp, -104, %sp
a008d0bc:  b1 2e 20 10  sll  %i0, 0x10, %i0
a008d0c0:  b1 36 20 10  srl  %i0, 0x10, %i0
a008d0c4:  80 a6 27 ff  cmp  %i0, 0x7ff
a008d0c8:  b2 10 20 00  clr  %i1
a008d0cc:  08 80 00 04  bleu  0xa008d0dc
a008d0d0:  98 10 20 00  clr  %o4
a008d0d4:  b2 10 28 00  mov  0x800, %i1
a008d0d8:  98 10 20 01  mov  1, %o4
a008d0dc:  39 33 c0 48  sethi  %hi(0xcf012000), %i4
a008d0e0:  bb 2e 60 10  sll  %i1, 0x10, %i5
a008d0e4:  9a 17 22 40  or  %i4, 0x240, %o5
a008d0e8:  82 0e 60 ff  and  %i1, 0xff, %g1
a008d0ec:  bb 37 60 18  srl  %i5, 0x18, %i5
a008d0f0:  c2 23 40 00  st  %g1, [ %o5 ]
a008d0f4:  ba 0f 60 ff  and  %i5, 0xff, %i5
a008d0f8:  9e 17 22 44  or  %i4, 0x244, %o7
a008d0fc:  fa 23 c0 00  st  %i5, [ %o7 ]
a008d100:  b8 17 22 00  or  %i4, 0x200, %i4
a008d104:  fa 07 00 00  ld  [ %i4 ], %i5
a008d108:  82 0f 60 a0  and  %i5, 0xa0, %g1
a008d10c:  80 a0 60 a0  cmp  %g1, 0xa0
a008d110:  12 80 00 30  bne  0xa008d1d0
a008d114:  b0 10 20 00  clr  %i0
a008d118:  ba 0f 60 0f  and  %i5, 0xf, %i5
a008d11c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a008d120:  b6 10 00 1d  mov  %i5, %i3
a008d124:  fa 28 60 02  stb  %i5, [ %g1 + 2 ]
a008d128:  80 a7 60 00  cmp  %i5, 0
a008d12c:  02 80 00 28  be  0xa008d1cc
a008d130:  b4 10 20 00  clr  %i2
a008d134:  82 0b 20 ff  and  %o4, 0xff, %g1
a008d138:  bb 28 60 02  sll  %g1, 2, %i5
a008d13c:  ba 07 40 01  add  %i5, %g1, %i5
a008d140:  96 10 00 0d  mov  %o5, %o3
a008d144:  98 10 00 0f  mov  %o7, %o4
a008d148:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a008d14c:  9a 10 00 1c  mov  %i4, %o5
a008d150:  94 10 62 52  or  %g1, 0x252, %o2
a008d154:  9e 07 40 1d  add  %i5, %i5, %o7
a008d158:  b0 10 00 1b  mov  %i3, %i0
a008d15c:  b6 0e a0 ff  and  %i2, 0xff, %i3
a008d160:  ba 06 c0 1b  add  %i3, %i3, %i5
a008d164:  ba 07 40 1b  add  %i5, %i3, %i5
a008d168:  ba 07 40 19  add  %i5, %i1, %i5
a008d16c:  82 07 60 02  add  %i5, 2, %g1
a008d170:  b9 28 60 10  sll  %g1, 0x10, %i4
a008d174:  82 08 60 ff  and  %g1, 0xff, %g1
a008d178:  c2 22 c0 00  st  %g1, [ %o3 ]
a008d17c:  b9 37 20 18  srl  %i4, 0x18, %i4
a008d180:  ba 07 60 03  add  %i5, 3, %i5
a008d184:  f8 23 00 00  st  %i4, [ %o4 ]
a008d188:  83 2f 60 10  sll  %i5, 0x10, %g1
a008d18c:  f8 03 40 00  ld  [ %o5 ], %i4
a008d190:  ba 0f 60 ff  and  %i5, 0xff, %i5
a008d194:  fa 22 c0 00  st  %i5, [ %o3 ]
a008d198:  83 30 60 18  srl  %g1, 0x18, %g1
a008d19c:  c2 23 00 00  st  %g1, [ %o4 ]
a008d1a0:  c2 03 40 00  ld  [ %o5 ], %g1
a008d1a4:  83 28 60 08  sll  %g1, 8, %g1
a008d1a8:  b8 17 00 01  or  %i4, %g1, %i4
a008d1ac:  b6 03 c0 1b  add  %o7, %i3, %i3
a008d1b0:  b4 06 a0 01  inc  %i2
a008d1b4:  b8 17 00 19  or  %i4, %i1, %i4
a008d1b8:  b6 06 c0 1b  add  %i3, %i3, %i3
a008d1bc:  82 0e a0 ff  and  %i2, 0xff, %g1
a008d1c0:  80 a0 40 18  cmp  %g1, %i0
a008d1c4:  0a bf ff e6  bcs  0xa008d15c
a008d1c8:  f8 32 80 1b  sth  %i4, [ %o2 + %i3 ]
a008d1cc:  b0 10 20 01  mov  1, %i0
a008d1d0:  81 c7 e0 08  ret
a008d1d4:  81 e8 00 00  restore
