# leon2m FUN_a00886f8 0xa00886f8-0xa0088714 (28 bytes)
a00886f8:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00886fc:  d0 08 63 99  ldub  [ %g1 + 0x399 ], %o0	! 0xa802af99
a0088700:  9a 0a 3f bf  and  %o0, -65, %o5
a0088704:  91 32 20 06  srl  %o0, 6, %o0
a0088708:  da 28 63 99  stb  %o5, [ %g1 + 0x399 ]
a008870c:  81 c3 e0 08  retl
a0088710:  90 0a 20 01  and  %o0, 1, %o0
