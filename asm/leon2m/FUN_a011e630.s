# leon2m FUN_a011e630 0xa011e630-0xa011e65c (44 bytes)
a011e630:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e634:  90 13 21 84  or  %o4, 0x184, %o0	! 0xcf016184
a011e638:  c2 02 00 00  ld  [ %o0 ], %g1
a011e63c:  9a 08 60 30  and  %g1, 0x30, %o5
a011e640:  90 13 21 88  or  %o4, 0x188, %o0
a011e644:  83 2b 60 04  sll  %o5, 4, %g1
a011e648:  da 02 00 00  ld  [ %o0 ], %o5
a011e64c:  98 03 40 01  add  %o5, %g1, %o4
a011e650:  91 2b 20 10  sll  %o4, 0x10, %o0
a011e654:  81 c3 e0 08  retl
a011e658:  91 32 20 10  srl  %o0, 0x10, %o0
