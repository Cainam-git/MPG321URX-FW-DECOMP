# leon2m FUN_a011a554 0xa011a554-0xa011a574 (32 bytes)
a011a554:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011a558:  9a 10 61 d8  or  %g1, 0x1d8, %o5	! 0xa802c9d8
a011a55c:  94 0a a0 ff  and  %o2, 0xff, %o2
a011a560:  d2 2b 40 0a  stb  %o1, [ %o5 + %o2 ]
a011a564:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011a568:  9a 10 61 d0  or  %g1, 0x1d0, %o5	! 0xa802c9d0
a011a56c:  81 c3 e0 08  retl
a011a570:  d0 2b 40 0a  stb  %o0, [ %o5 + %o2 ]
