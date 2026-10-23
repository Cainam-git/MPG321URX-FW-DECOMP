# leon2m FUN_a011e65c 0xa011e65c-0xa011e690 (52 bytes)
a011e65c:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011e660:  96 13 20 04  or  %o4, 4, %o3	! 0xcf016404
a011e664:  da 02 c0 00  ld  [ %o3 ], %o5
a011e668:  83 32 20 04  srl  %o0, 4, %g1
a011e66c:  9a 0b 7f cf  and  %o5, -49, %o5
a011e670:  82 08 60 30  and  %g1, 0x30, %g1
a011e674:  9a 13 40 01  or  %o5, %g1, %o5
a011e678:  da 22 c0 00  st  %o5, [ %o3 ]
a011e67c:  98 13 20 08  or  %o4, 8, %o4
a011e680:  90 0a 20 ff  and  %o0, 0xff, %o0
a011e684:  d0 23 00 00  st  %o0, [ %o4 ]
a011e688:  81 c3 e0 08  retl
a011e68c:  01 00 00 00  nop
