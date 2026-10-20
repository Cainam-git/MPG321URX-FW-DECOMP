# leon2s FUN_a00b14b0 0xa00b14b0-0xa00b14dc (44 bytes)
a00b14b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b14b4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b14b8:  9a 5a 21 2c  smul  %o0, 0x12c, %o5
a00b14bc:  82 10 60 18  or  %g1, 0x18, %g1
a00b14c0:  80 a2 20 01  cmp  %o0, 1
a00b14c4:  9a 03 40 01  add  %o5, %g1, %o5
a00b14c8:  18 80 00 03  bgu  0xa00b14d4
a00b14cc:  90 10 20 00  clr  %o0
a00b14d0:  d0 0b 61 29  ldub  [ %o5 + 0x129 ], %o0
a00b14d4:  81 c3 e0 08  retl
a00b14d8:  01 00 00 00  nop
