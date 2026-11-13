# leon2m FUN_a010ae38 0xa010ae38-0xa010ae54 (28 bytes)
a010ae38:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010ae3c:  82 13 62 c8  or  %o5, 0x2c8, %g1	! 0xcf00eac8
a010ae40:  d0 00 40 00  ld  [ %g1 ], %o0
a010ae44:  9a 0a 20 80  and  %o0, 0x80, %o5
a010ae48:  80 a0 00 0d  cmp  %g0, %o5
a010ae4c:  81 c3 e0 08  retl
a010ae50:  90 40 20 00  addx  %g0, 0, %o0
