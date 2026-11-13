# leon2m FUN_a01252e0 0xa01252e0-0xa01252fc (28 bytes)
a01252e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01252e4:  03 00 06 90  sethi  %hi(0x1a4000), %g1
a01252e8:  90 5a 20 16  smul  %o0, 0x16, %o0
a01252ec:  82 10 62 a8  or  %g1, 0x2a8, %g1
a01252f0:  90 02 00 01  add  %o0, %g1, %o0
a01252f4:  81 c3 e0 08  retl
a01252f8:  d0 0a 20 0b  ldub  [ %o0 + 0xb ], %o0
