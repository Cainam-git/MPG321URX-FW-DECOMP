# leon2s FUN_a008f9e4 0xa008f9e4-0xa008fa00 (28 bytes)
a008f9e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a008f9e8:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a008f9ec:  90 5a 20 b0  smul  %o0, 0xb0, %o0
a008f9f0:  82 10 63 e4  or  %g1, 0x3e4, %g1
a008f9f4:  90 02 00 01  add  %o0, %g1, %o0
a008f9f8:  81 c3 e0 08  retl
a008f9fc:  d0 0a 20 a6  ldub  [ %o0 + 0xa6 ], %o0
