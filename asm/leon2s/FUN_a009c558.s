# leon2s FUN_a009c558 0xa009c558-0xa009c58c (52 bytes)
a009c558:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c55c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c560:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009c564:  90 5a 20 34  smul  %o0, 0x34, %o0
a009c568:  90 02 00 01  add  %o0, %g1, %o0
a009c56c:  da 02 20 04  ld  [ %o0 + 4 ], %o5
a009c570:  c2 03 60 08  ld  [ %o5 + 8 ], %g1
a009c574:  82 08 60 ff  and  %g1, 0xff, %g1
a009c578:  d0 03 60 04  ld  [ %o5 + 4 ], %o0
a009c57c:  83 28 60 10  sll  %g1, 0x10, %g1
a009c580:  91 32 20 10  srl  %o0, 0x10, %o0
a009c584:  81 c3 e0 08  retl
a009c588:  90 10 40 08  or  %g1, %o0, %o0
