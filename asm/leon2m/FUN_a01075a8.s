# leon2m FUN_a01075a8 0xa01075a8-0xa01075f8 (80 bytes)
a01075a8:  03 33 c0 3a  sethi  %hi(0xcf00e800), %g1
a01075ac:  96 10 62 00  or  %g1, 0x200, %o3	! 0xcf00ea00
a01075b0:  82 10 62 c8  or  %g1, 0x2c8, %g1
a01075b4:  da 00 40 00  ld  [ %g1 ], %o5
a01075b8:  9a 0b 7f ef  and  %o5, -17, %o5
a01075bc:  90 0a 20 ff  and  %o0, 0xff, %o0
a01075c0:  98 10 00 0b  mov  %o3, %o4
a01075c4:  da 20 40 00  st  %o5, [ %g1 ]
a01075c8:  80 a2 20 01  cmp  %o0, 1
a01075cc:  02 80 00 06  be  0xa01075e4
a01075d0:  01 00 00 00  nop
a01075d4:  da 02 c0 00  ld  [ %o3 ], %o5
a01075d8:  96 0b 7f fe  and  %o5, -2, %o3
a01075dc:  d6 23 00 00  st  %o3, [ %o4 ]
a01075e0:  30 80 00 04  b,a   0xa01075f0
a01075e4:  d0 02 c0 00  ld  [ %o3 ], %o0
a01075e8:  98 12 20 01  or  %o0, 1, %o4
a01075ec:  d8 22 c0 00  st  %o4, [ %o3 ]
a01075f0:  81 c3 e0 08  retl
a01075f4:  01 00 00 00  nop
