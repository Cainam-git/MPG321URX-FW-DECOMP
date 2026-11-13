# leon2s FUN_a00b03ac 0xa00b03ac-0xa00b03c8 (28 bytes)
a00b03ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b03b0:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b03b4:  90 5a 21 2c  smul  %o0, 0x12c, %o0
a00b03b8:  82 10 60 18  or  %g1, 0x18, %g1
a00b03bc:  90 02 00 01  add  %o0, %g1, %o0
a00b03c0:  81 c3 e0 08  retl
a00b03c4:  d0 0a 20 f4  ldub  [ %o0 + 0xf4 ], %o0
