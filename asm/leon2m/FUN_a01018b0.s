# leon2m FUN_a01018b0 0xa01018b0-0xa01018e8 (56 bytes)
a01018b0:  03 33 c0 58  sethi  %hi(0xcf016000), %g1
a01018b4:  98 10 60 cc  or  %g1, 0xcc, %o4	! 0xcf0160cc
a01018b8:  80 8a 20 ff  btst  0xff, %o0
a01018bc:  02 80 00 06  be  0xa01018d4
a01018c0:  9a 10 00 0c  mov  %o4, %o5
a01018c4:  da 03 00 00  ld  [ %o4 ], %o5
a01018c8:  90 13 60 20  or  %o5, 0x20, %o0
a01018cc:  d0 23 00 00  st  %o0, [ %o4 ]
a01018d0:  30 80 00 04  b,a   0xa01018e0
a01018d4:  c2 03 00 00  ld  [ %o4 ], %g1
a01018d8:  98 08 7f df  and  %g1, -33, %o4
a01018dc:  d8 23 40 00  st  %o4, [ %o5 ]
a01018e0:  81 c3 e0 08  retl
a01018e4:  01 00 00 00  nop
