# leon2s FUN_a00a8370 0xa00a8370-0xa00a8400 (144 bytes)
a00a8370:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8374:  80 a2 20 07  cmp  %o0, 7
a00a8378:  08 80 00 15  bleu  0xa00a83cc
a00a837c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a8380:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a8384:  90 10 61 20  or  %g1, 0x120, %o0
a00a8388:  93 33 60 10  srl  %o5, 0x10, %o1
a00a838c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a8390:  98 10 20 00  clr  %o4
a00a8394:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a8398:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a839c:  82 00 40 01  add  %g1, %g1, %g1
a00a83a0:  c2 12 00 01  lduh  [ %o0 + %g1 ], %g1
a00a83a4:  82 00 40 09  add  %g1, %o1, %g1
a00a83a8:  83 28 60 02  sll  %g1, 2, %g1
a00a83ac:  98 03 20 01  inc  %o4
a00a83b0:  82 10 40 0b  or  %g1, %o3, %g1
a00a83b4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a83b8:  d4 20 40 00  st  %o2, [ %g1 ]
a00a83bc:  80 a3 60 07  cmp  %o5, 7
a00a83c0:  08 bf ff f7  bleu  0xa00a839c
a00a83c4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a83c8:  30 80 00 0c  b,a   0xa00a83f8
a00a83cc:  98 02 00 08  add  %o0, %o0, %o4
a00a83d0:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a83d4:  82 10 61 20  or  %g1, 0x120, %g1
a00a83d8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a83dc:  c2 10 40 0c  lduh  [ %g1 + %o4 ], %g1
a00a83e0:  82 00 40 0d  add  %g1, %o5, %g1
a00a83e4:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a83e8:  83 28 60 02  sll  %g1, 2, %g1
a00a83ec:  82 10 40 0d  or  %g1, %o5, %g1
a00a83f0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a83f4:  da 20 40 00  st  %o5, [ %g1 ]
a00a83f8:  81 c3 e0 08  retl
a00a83fc:  01 00 00 00  nop
