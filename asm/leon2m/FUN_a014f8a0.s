# leon2m FUN_a014f8a0 0xa014f8a0-0xa014f92c (140 bytes)
a014f8a0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014f8a4:  80 8b 60 01  btst  1, %o5
a014f8a8:  02 80 00 04  be  0xa014f8b8
a014f8ac:  80 8b 60 02  btst  2, %o5
a014f8b0:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f8b4:  d2 28 60 a8  stb  %o1, [ %g1 + 0xa8 ]	! 0xa802a4a8
a014f8b8:  02 80 00 04  be  0xa014f8c8
a014f8bc:  80 8b 60 04  btst  4, %o5
a014f8c0:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f8c4:  d2 28 60 a9  stb  %o1, [ %g1 + 0xa9 ]	! 0xa802a4a9
a014f8c8:  02 80 00 04  be  0xa014f8d8
a014f8cc:  80 8b 60 08  btst  8, %o5
a014f8d0:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f8d4:  d2 28 60 aa  stb  %o1, [ %g1 + 0xaa ]	! 0xa802a4aa
a014f8d8:  02 80 00 04  be  0xa014f8e8
a014f8dc:  80 8b 60 10  btst  0x10, %o5
a014f8e0:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f8e4:  d2 28 60 ab  stb  %o1, [ %g1 + 0xab ]	! 0xa802a4ab
a014f8e8:  02 80 00 04  be  0xa014f8f8
a014f8ec:  80 8b 60 20  btst  0x20, %o5
a014f8f0:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f8f4:  d2 28 60 ac  stb  %o1, [ %g1 + 0xac ]	! 0xa802a4ac
a014f8f8:  02 80 00 04  be  0xa014f908
a014f8fc:  80 8b 60 40  btst  0x40, %o5
a014f900:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014f904:  d2 28 60 ad  stb  %o1, [ %g1 + 0xad ]	! 0xa802a4ad
a014f908:  02 80 00 04  be  0xa014f918
a014f90c:  80 8a 20 80  btst  0x80, %o0
a014f910:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a014f914:  d2 2b 60 ae  stb  %o1, [ %o5 + 0xae ]	! 0xa802a4ae
a014f918:  02 80 00 03  be  0xa014f924
a014f91c:  11 2a 00 a9  sethi  %hi(0xa802a400), %o0
a014f920:  d2 2a 20 af  stb  %o1, [ %o0 + 0xaf ]	! 0xa802a4af
a014f924:  81 c3 e0 08  retl
a014f928:  01 00 00 00  nop
