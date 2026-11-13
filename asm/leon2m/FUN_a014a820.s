# leon2m FUN_a014a820 0xa014a820-0xa014a860 (64 bytes)
a014a820:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a824:  80 a2 20 00  cmp  %o0, 0
a014a828:  02 80 00 08  be  0xa014a848
a014a82c:  03 2a 00 b9  sethi  %hi(0xa802e400), %g1
a014a830:  80 a2 20 01  cmp  %o0, 1
a014a834:  02 80 00 07  be  0xa014a850
a014a838:  82 10 20 01  mov  1, %g1
a014a83c:  11 2a 00 b9  sethi  %hi(0xa802e400), %o0
a014a840:  10 80 00 06  b  0xa014a858
a014a844:  c2 2a 20 03  stb  %g1, [ %o0 + 3 ]	! 0xa802e403
a014a848:  10 80 00 04  b  0xa014a858
a014a84c:  c0 28 60 03  clrb  [ %g1 + 3 ]
a014a850:  1b 2a 00 b9  sethi  %hi(0xa802e400), %o5
a014a854:  d0 2b 60 03  stb  %o0, [ %o5 + 3 ]	! 0xa802e403
a014a858:  81 c3 e0 08  retl
a014a85c:  01 00 00 00  nop
