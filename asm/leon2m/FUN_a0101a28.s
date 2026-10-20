# leon2m FUN_a0101a28 0xa0101a28-0xa0101a4c (36 bytes)
a0101a28:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a0101a2c:  82 13 60 dc  or  %o5, 0xdc, %g1	! 0xcf0160dc
a0101a30:  92 0a 60 ff  and  %o1, 0xff, %o1
a0101a34:  d2 20 40 00  st  %o1, [ %g1 ]
a0101a38:  9a 13 60 c8  or  %o5, 0xc8, %o5
a0101a3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101a40:  d0 23 40 00  st  %o0, [ %o5 ]
a0101a44:  81 c3 e0 08  retl
a0101a48:  01 00 00 00  nop
