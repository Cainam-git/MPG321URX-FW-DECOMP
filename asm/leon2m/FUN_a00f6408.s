# leon2m FUN_a00f6408 0xa00f6408-0xa00f643c (52 bytes)
a00f6408:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f640c:  da 08 63 b4  ldub  [ %g1 + 0x3b4 ], %o5	! 0xa802b7b4
a00f6410:  17 33 c0 3b  sethi  %hi(0xcf00ec00), %o3
a00f6414:  98 03 60 04  add  %o5, 4, %o4
a00f6418:  96 12 e2 80  or  %o3, 0x280, %o3
a00f641c:  82 10 20 01  mov  1, %g1
a00f6420:  83 28 40 0c  sll  %g1, %o4, %g1
a00f6424:  da 02 c0 00  ld  [ %o3 ], %o5
a00f6428:  98 2b 40 01  andn  %o5, %g1, %o4
a00f642c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00f6430:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f6434:  81 c3 e0 08  retl
a00f6438:  01 00 00 00  nop
