# leon2m FUN_a00886a4 0xa00886a4-0xa00886c0 (28 bytes)
a00886a4:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00886a8:  d0 08 63 99  ldub  [ %g1 + 0x399 ], %o0	! 0xa802af99
a00886ac:  9a 0a 3f fb  and  %o0, -5, %o5
a00886b0:  91 32 20 02  srl  %o0, 2, %o0
a00886b4:  da 28 63 99  stb  %o5, [ %g1 + 0x399 ]
a00886b8:  81 c3 e0 08  retl
a00886bc:  90 0a 20 01  and  %o0, 1, %o0
