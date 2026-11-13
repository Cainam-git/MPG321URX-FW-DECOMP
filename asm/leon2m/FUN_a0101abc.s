# leon2m FUN_a0101abc 0xa0101abc-0xa0101af0 (52 bytes)
a0101abc:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a0101ac0:  9a 13 61 0c  or  %o5, 0x10c, %o5	! 0xcf01610c
a0101ac4:  c2 03 40 00  ld  [ %o5 ], %g1
a0101ac8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101acc:  82 08 60 01  and  %g1, 1, %g1
a0101ad0:  91 2a 20 03  sll  %o0, 3, %o0
a0101ad4:  92 0a 60 ff  and  %o1, 0xff, %o1
a0101ad8:  82 10 40 08  or  %g1, %o0, %g1
a0101adc:  92 02 40 09  add  %o1, %o1, %o1
a0101ae0:  82 10 40 09  or  %g1, %o1, %g1
a0101ae4:  c2 23 40 00  st  %g1, [ %o5 ]
a0101ae8:  81 c3 e0 08  retl
a0101aec:  01 00 00 00  nop
