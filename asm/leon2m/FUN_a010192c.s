# leon2m FUN_a010192c 0xa010192c-0xa0101950 (36 bytes)
a010192c:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a0101930:  82 10 60 d8  or  %g1, 0xd8, %g1	! 0xcf0160d8
a0101934:  da 00 40 00  ld  [ %g1 ], %o5
a0101938:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a010193c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0101940:  9a 13 40 08  or  %o5, %o0, %o5
a0101944:  da 20 40 00  st  %o5, [ %g1 ]
a0101948:  81 c3 e0 08  retl
a010194c:  01 00 00 00  nop
