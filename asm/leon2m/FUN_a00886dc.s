# leon2m FUN_a00886dc 0xa00886dc-0xa00886f8 (28 bytes)
a00886dc:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a00886e0:  d0 08 63 99  ldub  [ %g1 + 0x399 ], %o0	! 0xa802af99
a00886e4:  9a 0a 3f df  and  %o0, -33, %o5
a00886e8:  91 32 20 05  srl  %o0, 5, %o0
a00886ec:  da 28 63 99  stb  %o5, [ %g1 + 0x399 ]
a00886f0:  81 c3 e0 08  retl
a00886f4:  90 0a 20 01  and  %o0, 1, %o0
