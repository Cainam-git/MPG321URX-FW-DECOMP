# leon2s FUN_a00a8184 0xa00a8184-0xa00a8210 (140 bytes)
a00a8184:  9d e3 bf 98  save  %sp, -104, %sp
a00a8188:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a818c:  82 06 00 18  add  %i0, %i0, %g1
a00a8190:  82 00 40 18  add  %g1, %i0, %g1
a00a8194:  82 00 40 01  add  %g1, %g1, %g1
a00a8198:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a819c:  82 00 40 19  add  %g1, %i1, %g1
a00a81a0:  9e 0f 00 1b  and  %i4, %i3, %o7
a00a81a4:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00a81a8:  b8 00 40 01  add  %g1, %g1, %i4
a00a81ac:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00a81b0:  80 a6 20 01  cmp  %i0, 1
a00a81b4:  ba 10 20 01  mov  1, %i5
a00a81b8:  18 80 00 03  bgu  0xa00a81c4
a00a81bc:  82 10 20 01  mov  1, %g1
a00a81c0:  ba 10 20 00  clr  %i5
a00a81c4:  80 a6 60 05  cmp  %i1, 5
a00a81c8:  28 80 00 02  bleu,a   0xa00a81d0
a00a81cc:  82 10 20 00  clr  %g1
a00a81d0:  80 97 40 01  orcc  %i5, %g1, %g0
a00a81d4:  12 80 00 0d  bne  0xa00a8208
a00a81d8:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a81dc:  82 10 61 44  or  %g1, 0x144, %g1	! 0xa00b4d44
a00a81e0:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a00a81e4:  ba 07 40 1a  add  %i5, %i2, %i5
a00a81e8:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a81ec:  bb 2f 60 02  sll  %i5, 2, %i5
a00a81f0:  ba 17 40 01  or  %i5, %g1, %i5
a00a81f4:  c2 07 40 00  ld  [ %i5 ], %g1
a00a81f8:  82 28 40 1b  andn  %g1, %i3, %g1
a00a81fc:  82 13 c0 01  or  %o7, %g1, %g1
a00a8200:  82 08 60 ff  and  %g1, 0xff, %g1
a00a8204:  c2 27 40 00  st  %g1, [ %i5 ]
a00a8208:  81 c7 e0 08  ret
a00a820c:  81 e8 00 00  restore
