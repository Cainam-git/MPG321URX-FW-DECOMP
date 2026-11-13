# leon2m FUN_a010afac 0xa010afac-0xa010afc8 (28 bytes)
a010afac:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010afb0:  9a 13 62 c8  or  %o5, 0x2c8, %o5	! 0xcf00eac8
a010afb4:  c2 03 40 00  ld  [ %o5 ], %g1
a010afb8:  82 10 60 01  or  %g1, 1, %g1
a010afbc:  c2 23 40 00  st  %g1, [ %o5 ]
a010afc0:  81 c3 e0 08  retl
a010afc4:  01 00 00 00  nop
