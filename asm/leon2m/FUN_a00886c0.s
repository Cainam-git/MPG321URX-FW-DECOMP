# leon2m FUN_a00886c0 0xa00886c0-0xa00886dc (28 bytes)
a00886c0:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00886c4:  d0 08 63 99  ldub  [ %g1 + 0x399 ], %o0	! 0xa802af99
a00886c8:  9a 0a 3f ef  and  %o0, -17, %o5
a00886cc:  91 32 20 04  srl  %o0, 4, %o0
a00886d0:  da 28 63 99  stb  %o5, [ %g1 + 0x399 ]
a00886d4:  81 c3 e0 08  retl
a00886d8:  90 0a 20 01  and  %o0, 1, %o0
