# leon2m FUN_a01328d4 0xa01328d4-0xa0132918 (68 bytes)
a01328d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01328d8:  9b 2a 20 04  sll  %o0, 4, %o5
a01328dc:  82 23 40 08  sub  %o5, %o0, %g1
a01328e0:  80 a2 20 03  cmp  %o0, 3
a01328e4:  9b 28 60 03  sll  %g1, 3, %o5
a01328e8:  92 0a 60 ff  and  %o1, 0xff, %o1
a01328ec:  18 80 00 07  bgu  0xa0132908
a01328f0:  90 10 3f ff  mov  -1, %o0
a01328f4:  11 2a 00 b7  sethi  %hi(0xa802dc00), %o0
a01328f8:  82 12 23 30  or  %o0, 0x330, %g1	! 0xa802df30
a01328fc:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a0132900:  83 32 20 0c  srl  %o0, 0xc, %g1
a0132904:  90 08 60 0f  and  %g1, 0xf, %o0
a0132908:  90 0a 20 ff  and  %o0, 0xff, %o0
a013290c:  82 13 c0 00  mov  %o7, %g1
a0132910:  40 00 41 af  call  0xa0142fcc
a0132914:  9e 10 40 00  mov  %g1, %o7
