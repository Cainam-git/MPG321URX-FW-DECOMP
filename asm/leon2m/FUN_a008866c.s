# leon2m FUN_a008866c 0xa008866c-0xa0088688 (28 bytes)
a008866c:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0088670:  d0 08 63 99  ldub  [ %g1 + 0x399 ], %o0	! 0xa802af99
a0088674:  9a 0a 3f fd  and  %o0, -3, %o5
a0088678:  91 32 20 01  srl  %o0, 1, %o0
a008867c:  da 28 63 99  stb  %o5, [ %g1 + 0x399 ]
a0088680:  81 c3 e0 08  retl
a0088684:  90 0a 20 01  and  %o0, 1, %o0
