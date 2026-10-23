# leon2m FUN_a010b8e8 0xa010b8e8-0xa010b918 (48 bytes)
a010b8e8:  1b 34 00 c0  sethi  %hi(0xd0030000), %o5
a010b8ec:  9a 13 60 04  or  %o5, 4, %o5	! 0xd0030004
a010b8f0:  d8 03 40 00  ld  [ %o5 ], %o4
a010b8f4:  82 13 20 01  or  %o4, 1, %g1
a010b8f8:  19 34 00 e0  sethi  %hi(0xd0038000), %o4
a010b8fc:  c2 23 40 00  st  %g1, [ %o5 ]
a010b900:  98 13 20 04  or  %o4, 4, %o4
a010b904:  da 03 00 00  ld  [ %o4 ], %o5
a010b908:  82 13 60 01  or  %o5, 1, %g1
a010b90c:  c2 23 00 00  st  %g1, [ %o4 ]
a010b910:  81 c3 e0 08  retl
a010b914:  01 00 00 00  nop
