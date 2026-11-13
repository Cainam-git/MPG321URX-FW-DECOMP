# leon2m FUN_a014aa7c 0xa014aa7c-0xa014aaa0 (36 bytes)
a014aa7c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014aa80:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5	! 0xa802e3d0
a014aa84:  90 0a 20 01  and  %o0, 1, %o0
a014aa88:  03 00 02 00  sethi  %hi(0x80000), %g1
a014aa8c:  82 2b 40 01  andn  %o5, %g1, %g1
a014aa90:  91 2a 20 13  sll  %o0, 0x13, %o0
a014aa94:  82 10 40 08  or  %g1, %o0, %g1
a014aa98:  81 c3 e0 08  retl
a014aa9c:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
