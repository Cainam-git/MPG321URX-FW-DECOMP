# leon2s FUN_a009facc 0xa009facc-0xa009faf0 (36 bytes)
a009facc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009fad0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009fad4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009fad8:  90 5a 20 34  smul  %o0, 0x34, %o0
a009fadc:  90 02 00 01  add  %o0, %g1, %o0
a009fae0:  c2 02 20 04  ld  [ %o0 + 4 ], %g1
a009fae4:  d0 00 60 40  ld  [ %g1 + 0x40 ], %o0
a009fae8:  81 c3 e0 08  retl
a009faec:  90 0a 20 ff  and  %o0, 0xff, %o0
