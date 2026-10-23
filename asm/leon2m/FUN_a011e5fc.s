# leon2m FUN_a011e5fc 0xa011e5fc-0xa011e630 (52 bytes)
a011e5fc:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011e600:  96 13 21 84  or  %o4, 0x184, %o3	! 0xcf016184
a011e604:  da 02 c0 00  ld  [ %o3 ], %o5
a011e608:  83 32 20 04  srl  %o0, 4, %g1
a011e60c:  9a 0b 7f cf  and  %o5, -49, %o5
a011e610:  82 08 60 30  and  %g1, 0x30, %g1
a011e614:  9a 13 40 01  or  %o5, %g1, %o5
a011e618:  da 22 c0 00  st  %o5, [ %o3 ]
a011e61c:  98 13 21 88  or  %o4, 0x188, %o4
a011e620:  90 0a 20 ff  and  %o0, 0xff, %o0
a011e624:  d0 23 00 00  st  %o0, [ %o4 ]
a011e628:  81 c3 e0 08  retl
a011e62c:  01 00 00 00  nop
