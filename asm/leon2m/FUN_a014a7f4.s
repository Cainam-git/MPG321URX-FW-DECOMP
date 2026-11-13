# leon2m FUN_a014a7f4 0xa014a7f4-0xa014a818 (36 bytes)
a014a7f4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014a7f8:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5	! 0xa802e3d0
a014a7fc:  90 0a 20 01  and  %o0, 1, %o0
a014a800:  03 00 08 00  sethi  %hi(0x200000), %g1
a014a804:  82 2b 40 01  andn  %o5, %g1, %g1
a014a808:  91 2a 20 15  sll  %o0, 0x15, %o0
a014a80c:  82 10 40 08  or  %g1, %o0, %g1
a014a810:  81 c3 e0 08  retl
a014a814:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
