# leon2m FUN_a01302a4 0xa01302a4-0xa01302e0 (60 bytes)
a01302a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01302a8:  9b 2a 20 04  sll  %o0, 4, %o5
a01302ac:  98 23 40 08  sub  %o5, %o0, %o4
a01302b0:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a01302b4:  90 10 63 30  or  %g1, 0x330, %o0	! 0xa802df30
a01302b8:  9b 2b 20 03  sll  %o4, 3, %o5
a01302bc:  9a 03 40 08  add  %o5, %o0, %o5
a01302c0:  d8 03 60 70  ld  [ %o5 + 0x70 ], %o4
a01302c4:  03 00 00 80  sethi  %hi(0x20000), %g1
a01302c8:  92 0a 60 01  and  %o1, 1, %o1
a01302cc:  90 2b 00 01  andn  %o4, %g1, %o0
a01302d0:  93 2a 60 11  sll  %o1, 0x11, %o1
a01302d4:  82 12 00 09  or  %o0, %o1, %g1
a01302d8:  81 c3 e0 08  retl
a01302dc:  c2 23 60 70  st  %g1, [ %o5 + 0x70 ]
