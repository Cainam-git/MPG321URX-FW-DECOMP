# leon2s FUN_a00c90b4 0xa00c90b4-0xa00c91f8 (324 bytes)
a00c90b4:  9d e3 bf 80  save  %sp, -128, %sp
a00c90b8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c90bc:  82 06 00 18  add  %i0, %i0, %g1
a00c90c0:  82 00 40 18  add  %g1, %i0, %g1
a00c90c4:  a1 28 60 03  sll  %g1, 3, %l0
a00c90c8:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00c90cc:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00c90d0:  a2 14 a3 b0  or  %l2, 0x3b0, %l1	! 0xa8078bb0
a00c90d4:  98 10 63 ff  or  %g1, 0x3ff, %o4
a00c90d8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00c90dc:  9a 08 40 0c  and  %g1, %o4, %o5
a00c90e0:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c90e4:  9a 13 40 01  or  %o5, %g1, %o5
a00c90e8:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00c90ec:  80 88 60 01  btst  1, %g1
a00c90f0:  12 80 00 08  bne  0xa00c9110
a00c90f4:  da 24 40 10  st  %o5, [ %l1 + %l0 ]
a00c90f8:  82 0b 40 0c  and  %o5, %o4, %g1
a00c90fc:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c9100:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00c9104:  40 3a e7 d0  call  0xa0f83044
a00c9108:  90 12 20 98  or  %o0, 0x98, %o0
a00c910c:  30 80 00 39  b,a   0xa00c91f0
a00c9110:  90 10 00 18  mov  %i0, %o0
a00c9114:  92 10 20 74  mov  0x74, %o1
a00c9118:  94 10 20 20  mov  0x20, %o2
a00c911c:  7f ff fb cb  call  0xa00c8048
a00c9120:  96 10 20 14  mov  0x14, %o3
a00c9124:  80 8a 20 ff  btst  0xff, %o0
a00c9128:  32 80 00 0a  bne,a   0xa00c9150
a00c912c:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00c9130:  90 10 00 18  mov  %i0, %o0
a00c9134:  92 07 bf e0  add  %fp, -32, %o1
a00c9138:  7f ff fc 30  call  0xa00c81f8
a00c913c:  94 10 20 14  mov  0x14, %o2
a00c9140:  80 8a 20 ff  btst  0xff, %o0
a00c9144:  02 80 00 13  be  0xa00c9190
a00c9148:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00c914c:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00c9150:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00c9154:  82 10 40 0d  or  %g1, %o5, %g1
a00c9158:  10 80 00 26  b  0xa00c91f0
a00c915c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00c9160:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00c9164:  40 3a e7 b8  call  0xa0f83044
a00c9168:  90 12 20 a8  or  %o0, 0xa8, %o0	! 0x9f1c20a8
a00c916c:  9a 06 00 18  add  %i0, %i0, %o5
a00c9170:  9a 03 40 18  add  %o5, %i0, %o5
a00c9174:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00c9178:  9b 2b 60 03  sll  %o5, 3, %o5
a00c917c:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00c9180:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c9184:  82 2b 00 01  andn  %o4, %g1, %g1
a00c9188:  10 80 00 1a  b  0xa00c91f0
a00c918c:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00c9190:  a0 10 62 38  or  %g1, 0x238, %l0
a00c9194:  94 10 20 00  clr  %o2
a00c9198:  9e 07 bf f8  add  %fp, -8, %o7
a00c919c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c91a0:  93 28 60 02  sll  %g1, 2, %o1
a00c91a4:  98 10 20 00  clr  %o4
a00c91a8:  90 02 40 10  add  %o1, %l0, %o0
a00c91ac:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c91b0:  82 22 40 0d  sub  %o1, %o5, %g1
a00c91b4:  82 03 c0 01  add  %o7, %g1, %g1
a00c91b8:  98 03 20 01  inc  %o4
a00c91bc:  da 0a 00 0d  ldub  [ %o0 + %o5 ], %o5
a00c91c0:  c2 08 7f eb  ldub  [ %g1 + -21 ], %g1
a00c91c4:  80 a3 40 01  cmp  %o5, %g1
a00c91c8:  12 bf ff e6  bne  0xa00c9160
a00c91cc:  96 0b 20 ff  and  %o4, 0xff, %o3
a00c91d0:  80 a2 e0 03  cmp  %o3, 3
a00c91d4:  28 bf ff f7  bleu,a   0xa00c91b0
a00c91d8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c91dc:  94 02 a0 01  inc  %o2
a00c91e0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c91e4:  80 a0 60 04  cmp  %g1, 4
a00c91e8:  08 bf ff ef  bleu  0xa00c91a4
a00c91ec:  93 28 60 02  sll  %g1, 2, %o1
a00c91f0:  81 c7 e0 08  ret
a00c91f4:  81 e8 00 00  restore
