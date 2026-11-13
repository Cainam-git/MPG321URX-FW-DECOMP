# leon2m FUN_a00d80d8 0xa00d80d8-0xa00d8100 (40 bytes)
a00d80d8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00d80dc:  1b 00 06 61  sethi  %hi(0x198400), %o5
a00d80e0:  82 13 60 c8  or  %o5, 0xc8, %g1	! 0x1984c8
a00d80e4:  91 2b 20 04  sll  %o4, 4, %o0
a00d80e8:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00d80ec:  98 02 00 01  add  %o0, %g1, %o4
a00d80f0:  da 32 40 00  sth  %o5, [ %o1 ]
a00d80f4:  c2 13 20 08  lduh  [ %o4 + 8 ], %g1
a00d80f8:  81 c3 e0 08  retl
a00d80fc:  c2 32 80 00  sth  %g1, [ %o2 ]
