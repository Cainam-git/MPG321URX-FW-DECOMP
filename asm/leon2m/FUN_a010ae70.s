# leon2m FUN_a010ae70 0xa010ae70-0xa010ae8c (28 bytes)
a010ae70:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010ae74:  9a 13 62 c8  or  %o5, 0x2c8, %o5	! 0xcf00eac8
a010ae78:  c2 03 40 00  ld  [ %o5 ], %g1
a010ae7c:  82 08 7f 7f  and  %g1, -129, %g1
a010ae80:  c2 23 40 00  st  %g1, [ %o5 ]
a010ae84:  81 c3 e0 08  retl
a010ae88:  01 00 00 00  nop
