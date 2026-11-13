# leon2m FUN_a01016e8 0xa01016e8-0xa0101704 (28 bytes)
a01016e8:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a01016ec:  9a 13 60 c0  or  %o5, 0xc0, %o5	! 0xcf0160c0
a01016f0:  c2 03 40 00  ld  [ %o5 ], %g1
a01016f4:  82 08 7f fe  and  %g1, -2, %g1
a01016f8:  c2 23 40 00  st  %g1, [ %o5 ]
a01016fc:  81 c3 e0 08  retl
a0101700:  01 00 00 00  nop
