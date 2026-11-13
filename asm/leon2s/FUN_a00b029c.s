# leon2s FUN_a00b029c 0xa00b029c-0xa00b02b8 (28 bytes)
a00b029c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b02a0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b02a4:  90 5a 21 2c  smul  %o0, 0x12c, %o0
a00b02a8:  82 10 60 18  or  %g1, 0x18, %g1
a00b02ac:  90 02 00 01  add  %o0, %g1, %o0
a00b02b0:  81 c3 e0 08  retl
a00b02b4:  d0 0a 20 dd  ldub  [ %o0 + 0xdd ], %o0
