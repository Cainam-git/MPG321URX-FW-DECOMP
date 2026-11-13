# leon2s FUN_a00a72c0 0xa00a72c0-0xa00a7314 (84 bytes)
a00a72c0:  1b 00 00 3d  sethi  %hi(0xf400), %o5
a00a72c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a72c8:  9a 13 60 01  or  %o5, 1, %o5
a00a72cc:  9a 02 00 0d  add  %o0, %o5, %o5
a00a72d0:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00a72d4:  9b 2b 60 02  sll  %o5, 2, %o5
a00a72d8:  9a 13 40 01  or  %o5, %g1, %o5
a00a72dc:  83 2a 60 10  sll  %o1, 0x10, %g1
a00a72e0:  d8 03 40 00  ld  [ %o5 ], %o4
a00a72e4:  83 30 60 18  srl  %g1, 0x18, %g1
a00a72e8:  c2 23 40 00  st  %g1, [ %o5 ]
a00a72ec:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a72f0:  91 2a 20 08  sll  %o0, 8, %o0
a00a72f4:  03 33 80 20  sethi  %hi(0xce008000), %g1
a00a72f8:  90 02 00 09  add  %o0, %o1, %o0
a00a72fc:  82 10 61 00  or  %g1, 0x100, %g1
a00a7300:  d4 22 00 01  st  %o2, [ %o0 + %g1 ]
a00a7304:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a7308:  d8 23 40 00  st  %o4, [ %o5 ]
a00a730c:  81 c3 e0 08  retl
a00a7310:  01 00 00 00  nop
