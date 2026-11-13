# leon2m FUN_a010b198 0xa010b198-0xa010b1b4 (28 bytes)
a010b198:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010b19c:  9a 13 62 c8  or  %o5, 0x2c8, %o5	! 0xcf00eac8
a010b1a0:  c2 03 40 00  ld  [ %o5 ], %g1
a010b1a4:  82 08 7f fb  and  %g1, -5, %g1
a010b1a8:  c2 23 40 00  st  %g1, [ %o5 ]
a010b1ac:  81 c3 e0 08  retl
a010b1b0:  01 00 00 00  nop
