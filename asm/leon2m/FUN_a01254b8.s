# leon2m FUN_a01254b8 0xa01254b8-0xa01254f8 (64 bytes)
a01254b8:  82 10 20 01  mov  1, %g1	! 0x1
a01254bc:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a01254c0:  99 28 40 08  sll  %g1, %o0, %o4
a01254c4:  96 10 00 0a  mov  %o2, %o3
a01254c8:  80 8a 60 ff  btst  0xff, %o1
a01254cc:  02 80 00 06  be  0xa01254e4
a01254d0:  9a 10 00 0c  mov  %o4, %o5
a01254d4:  d2 0a a1 fa  ldub  [ %o2 + 0x1fa ], %o1
a01254d8:  90 13 00 09  or  %o4, %o1, %o0
a01254dc:  10 80 00 05  b  0xa01254f0
a01254e0:  d0 2a a1 fa  stb  %o0, [ %o2 + 0x1fa ]
a01254e4:  d8 0a a1 fa  ldub  [ %o2 + 0x1fa ], %o4
a01254e8:  94 2b 00 0d  andn  %o4, %o5, %o2
a01254ec:  d4 2a e1 fa  stb  %o2, [ %o3 + 0x1fa ]
a01254f0:  81 c3 e0 08  retl
a01254f4:  01 00 00 00  nop
