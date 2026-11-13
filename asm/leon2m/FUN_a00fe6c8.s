# leon2m FUN_a00fe6c8 0xa00fe6c8-0xa00fe718 (80 bytes)
a00fe6c8:  11 33 c0 b7  sethi  %hi(0xcf02dc00), %o0
a00fe6cc:  82 12 20 04  or  %o0, 4, %g1	! 0xcf02dc04
a00fe6d0:  da 00 40 00  ld  [ %g1 ], %o5
a00fe6d4:  80 8b 60 12  btst  0x12, %o5
a00fe6d8:  32 80 00 09  bne,a   0xa00fe6fc
a00fe6dc:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a00fe6e0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00fe6e4:  9a 10 63 50  or  %g1, 0x350, %o5	! 0xcf011750
a00fe6e8:  d0 03 40 00  ld  [ %o5 ], %o0
a00fe6ec:  82 0a 20 01  and  %o0, 1, %g1
a00fe6f0:  9b 28 60 04  sll  %g1, 4, %o5
a00fe6f4:  10 80 00 07  b  0xa00fe710
a00fe6f8:  90 03 60 51  add  %o5, 0x51, %o0
a00fe6fc:  82 12 22 74  or  %o0, 0x274, %g1
a00fe700:  da 00 40 00  ld  [ %g1 ], %o5
a00fe704:  90 0b 60 01  and  %o5, 1, %o0
a00fe708:  9b 2a 20 04  sll  %o0, 4, %o5
a00fe70c:  90 03 60 71  add  %o5, 0x71, %o0
a00fe710:  81 c3 e0 08  retl
a00fe714:  90 0a 20 ff  and  %o0, 0xff, %o0
