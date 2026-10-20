# leon2s FUN_a00a60d8 0xa00a60d8-0xa00a610c (52 bytes)
a00a60d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a60dc:  9a 02 00 08  add  %o0, %o0, %o5
a00a60e0:  9a 03 40 08  add  %o5, %o0, %o5
a00a60e4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a60e8:  82 10 60 04  or  %g1, 4, %g1	! 0xa807dc04
a00a60ec:  9b 2b 60 02  sll  %o5, 2, %o5
a00a60f0:  98 03 40 01  add  %o5, %g1, %o4
a00a60f4:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a00a60f8:  d2 03 20 04  ld  [ %o4 + 4 ], %o1
a00a60fc:  94 10 20 18  mov  0x18, %o2
a00a6100:  82 13 c0 00  mov  %o7, %g1
a00a6104:  40 00 2d 01  call  0xa00b1508
a00a6108:  9e 10 40 00  mov  %g1, %o7
