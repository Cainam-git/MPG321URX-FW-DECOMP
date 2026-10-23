# leon2m FUN_a010b918 0xa010b918-0xa010b948 (48 bytes)
a010b918:  1b 34 00 c0  sethi  %hi(0xd0030000), %o5
a010b91c:  9a 13 60 04  or  %o5, 4, %o5	! 0xd0030004
a010b920:  d8 03 40 00  ld  [ %o5 ], %o4
a010b924:  82 0b 3f fe  and  %o4, -2, %g1
a010b928:  19 34 00 e0  sethi  %hi(0xd0038000), %o4
a010b92c:  c2 23 40 00  st  %g1, [ %o5 ]
a010b930:  98 13 20 04  or  %o4, 4, %o4
a010b934:  da 03 00 00  ld  [ %o4 ], %o5
a010b938:  82 0b 7f fe  and  %o5, -2, %g1
a010b93c:  c2 23 00 00  st  %g1, [ %o4 ]
a010b940:  81 c3 e0 08  retl
a010b944:  01 00 00 00  nop
