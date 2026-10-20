# leon2s FUN_a00a80cc 0xa00a80cc-0xa00a8184 (184 bytes)
a00a80cc:  9d e3 bf 98  save  %sp, -104, %sp
a00a80d0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a80d4:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a80d8:  9e 06 00 18  add  %i0, %i0, %o7
a00a80dc:  98 10 61 44  or  %g1, 0x144, %o4
a00a80e0:  9e 03 c0 18  add  %o7, %i0, %o7
a00a80e4:  83 2e a0 10  sll  %i2, 0x10, %g1
a00a80e8:  9e 03 c0 0f  add  %o7, %o7, %o7
a00a80ec:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a80f0:  9e 03 c0 19  add  %o7, %i1, %o7
a00a80f4:  9b 30 60 10  srl  %g1, 0x10, %o5
a00a80f8:  82 03 c0 0f  add  %o7, %o7, %g1
a00a80fc:  80 a6 20 01  cmp  %i0, 1
a00a8100:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00a8104:  96 10 00 0c  mov  %o4, %o3
a00a8108:  9e 10 00 01  mov  %g1, %o7
a00a810c:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a8110:  b0 10 20 01  mov  1, %i0
a00a8114:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00a8118:  18 80 00 03  bgu  0xa00a8124
a00a811c:  ba 10 20 01  mov  1, %i5
a00a8120:  b0 10 20 00  clr  %i0
a00a8124:  80 a6 60 05  cmp  %i1, 5
a00a8128:  28 80 00 02  bleu,a   0xa00a8130
a00a812c:  ba 10 20 00  clr  %i5
a00a8130:  80 96 00 1d  orcc  %i0, %i5, %g0
a00a8134:  12 80 00 12  bne  0xa00a817c
a00a8138:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a813c:  c2 13 00 01  lduh  [ %o4 + %g1 ], %g1
a00a8140:  82 00 40 0d  add  %g1, %o5, %g1
a00a8144:  83 28 60 02  sll  %g1, 2, %g1
a00a8148:  82 10 40 1d  or  %g1, %i5, %g1
a00a814c:  c2 00 40 00  ld  [ %g1 ], %g1
a00a8150:  80 a7 20 01  cmp  %i4, 1
a00a8154:  02 80 00 03  be  0xa00a8160
a00a8158:  b8 10 40 1b  or  %g1, %i3, %i4
a00a815c:  b8 28 40 1b  andn  %g1, %i3, %i4
a00a8160:  c2 12 c0 0f  lduh  [ %o3 + %o7 ], %g1
a00a8164:  82 00 40 1a  add  %g1, %i2, %g1
a00a8168:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a816c:  83 28 60 02  sll  %g1, 2, %g1
a00a8170:  82 10 40 1d  or  %g1, %i5, %g1
a00a8174:  ba 0f 20 ff  and  %i4, 0xff, %i5
a00a8178:  fa 20 40 00  st  %i5, [ %g1 ]
a00a817c:  81 c7 e0 08  ret
a00a8180:  81 e8 00 00  restore
