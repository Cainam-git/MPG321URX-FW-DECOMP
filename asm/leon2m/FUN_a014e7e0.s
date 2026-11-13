# leon2m FUN_a014e7e0 0xa014e7e0-0xa014e82c (76 bytes)
a014e7e0:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a014e7e4:  98 10 61 40  or  %g1, 0x140, %o4	! 0xcf03c940
a014e7e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e7ec:  80 a2 20 01  cmp  %o0, 1
a014e7f0:  02 80 00 08  be  0xa014e810
a014e7f4:  9a 10 00 0c  mov  %o4, %o5
a014e7f8:  c2 03 00 00  ld  [ %o4 ], %g1
a014e7fc:  98 08 7f fd  and  %g1, -3, %o4
a014e800:  d8 23 40 00  st  %o4, [ %o5 ]
a014e804:  82 13 c0 00  mov  %o7, %g1
a014e808:  7f fe 40 d7  call  0xa00deb64
a014e80c:  9e 10 40 00  mov  %g1, %o7
a014e810:  d0 03 00 00  ld  [ %o4 ], %o0
a014e814:  9a 12 20 02  or  %o0, 2, %o5
a014e818:  da 23 00 00  st  %o5, [ %o4 ]
a014e81c:  82 13 c0 00  mov  %o7, %g1
a014e820:  7f fe 40 d1  call  0xa00deb64
a014e824:  9e 10 40 00  mov  %g1, %o7
a014e828:  01 00 00 00  nop
