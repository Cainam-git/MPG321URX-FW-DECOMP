# leon2s FUN_a009c58c 0xa009c58c-0xa009c5b4 (40 bytes)
a009c58c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c590:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c594:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009c598:  90 5a 20 34  smul  %o0, 0x34, %o0
a009c59c:  90 02 00 01  add  %o0, %g1, %o0
a009c5a0:  c2 02 20 04  ld  [ %o0 + 4 ], %g1
a009c5a4:  c2 00 60 0c  ld  [ %g1 + 0xc ], %g1
a009c5a8:  11 3f c0 00  sethi  %hi(0xff000000), %o0
a009c5ac:  81 c3 e0 08  retl
a009c5b0:  90 28 40 08  andn  %g1, %o0, %o0
