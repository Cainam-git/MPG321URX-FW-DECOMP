# leon2m FUN_a014e82c 0xa014e82c-0xa014e878 (76 bytes)
a014e82c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a014e830:  98 10 61 40  or  %g1, 0x140, %o4	! 0xcf03c940
a014e834:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e838:  80 a2 20 01  cmp  %o0, 1
a014e83c:  02 80 00 08  be  0xa014e85c
a014e840:  9a 10 00 0c  mov  %o4, %o5
a014e844:  c2 03 00 00  ld  [ %o4 ], %g1
a014e848:  98 08 7f fb  and  %g1, -5, %o4
a014e84c:  d8 23 40 00  st  %o4, [ %o5 ]
a014e850:  82 13 c0 00  mov  %o7, %g1
a014e854:  7f fe 40 cb  call  0xa00deb80
a014e858:  9e 10 40 00  mov  %g1, %o7
a014e85c:  d0 03 00 00  ld  [ %o4 ], %o0
a014e860:  9a 12 20 04  or  %o0, 4, %o5
a014e864:  da 23 00 00  st  %o5, [ %o4 ]
a014e868:  82 13 c0 00  mov  %o7, %g1
a014e86c:  7f fe 40 c5  call  0xa00deb80
a014e870:  9e 10 40 00  mov  %g1, %o7
a014e874:  01 00 00 00  nop
