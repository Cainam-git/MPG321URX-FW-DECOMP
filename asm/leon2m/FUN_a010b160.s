# leon2m FUN_a010b160 0xa010b160-0xa010b17c (28 bytes)
a010b160:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a010b164:  82 13 62 c8  or  %o5, 0x2c8, %g1	! 0xcf00eac8
a010b168:  d0 00 40 00  ld  [ %g1 ], %o0
a010b16c:  9a 0a 20 04  and  %o0, 4, %o5
a010b170:  80 a0 00 0d  cmp  %g0, %o5
a010b174:  81 c3 e0 08  retl
a010b178:  90 40 20 00  addx  %g0, 0, %o0
