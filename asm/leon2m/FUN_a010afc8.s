# leon2m FUN_a010afc8 0xa010afc8-0xa010afe4 (28 bytes)
a010afc8:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010afcc:  9a 13 62 c8  or  %o5, 0x2c8, %o5	! 0xcf00eac8
a010afd0:  c2 03 40 00  ld  [ %o5 ], %g1
a010afd4:  82 08 7f fe  and  %g1, -2, %g1
a010afd8:  c2 23 40 00  st  %g1, [ %o5 ]
a010afdc:  81 c3 e0 08  retl
a010afe0:  01 00 00 00  nop
