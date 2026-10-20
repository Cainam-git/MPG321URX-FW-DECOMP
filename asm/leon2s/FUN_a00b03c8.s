# leon2s FUN_a00b03c8 0xa00b03c8-0xa00b03e4 (28 bytes)
a00b03c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b03cc:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b03d0:  90 5a 21 2c  smul  %o0, 0x12c, %o0
a00b03d4:  82 10 60 18  or  %g1, 0x18, %g1
a00b03d8:  90 02 00 01  add  %o0, %g1, %o0
a00b03dc:  81 c3 e0 08  retl
a00b03e0:  d0 0a 20 f5  ldub  [ %o0 + 0xf5 ], %o0
