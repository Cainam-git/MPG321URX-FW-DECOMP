# leon2s FUN_a006119c 0xa006119c-0xa0061200 (100 bytes)
a006119c:  15 27 c4 00  sethi  %hi(0x9f100000), %o2
a00611a0:  90 12 a0 90  or  %o2, 0x90, %o0	! 0x9f100090
a00611a4:  13 3f ff ef  sethi  %hi(0xffffbc00), %o1
a00611a8:  c2 02 00 00  ld  [ %o0 ], %g1
a00611ac:  92 12 63 ff  or  %o1, 0x3ff, %o1
a00611b0:  82 08 40 09  and  %g1, %o1, %g1
a00611b4:  1b 27 c4 80  sethi  %hi(0x9f120000), %o5
a00611b8:  c2 22 00 00  st  %g1, [ %o0 ]
a00611bc:  98 13 60 28  or  %o5, 0x28, %o4
a00611c0:  c2 03 00 00  ld  [ %o4 ], %g1
a00611c4:  17 00 00 10  sethi  %hi(0x4000), %o3
a00611c8:  82 10 40 0b  or  %g1, %o3, %g1
a00611cc:  c2 23 00 00  st  %g1, [ %o4 ]
a00611d0:  9a 13 60 34  or  %o5, 0x34, %o5
a00611d4:  d6 23 40 00  st  %o3, [ %o5 ]
a00611d8:  94 12 a0 9c  or  %o2, 0x9c, %o2
a00611dc:  d6 22 80 00  st  %o3, [ %o2 ]
a00611e0:  c2 03 00 00  ld  [ %o4 ], %g1
a00611e4:  82 08 40 09  and  %g1, %o1, %g1
a00611e8:  c2 23 00 00  st  %g1, [ %o4 ]
a00611ec:  c2 02 00 00  ld  [ %o0 ], %g1
a00611f0:  82 10 40 0b  or  %g1, %o3, %g1
a00611f4:  c2 22 00 00  st  %g1, [ %o0 ]
a00611f8:  81 c3 e0 08  retl
a00611fc:  01 00 00 00  nop
