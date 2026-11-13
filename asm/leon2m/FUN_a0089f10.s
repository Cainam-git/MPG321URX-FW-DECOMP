# leon2m FUN_a0089f10 0xa0089f10-0xa0089f24 (20 bytes)
a0089f10:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089f14:  c2 0b 63 99  ldub  [ %o5 + 0x399 ], %g1	! 0xa802af99
a0089f18:  82 10 60 01  or  %g1, 1, %g1
a0089f1c:  81 c3 e0 08  retl
a0089f20:  c2 2b 63 99  stb  %g1, [ %o5 + 0x399 ]
