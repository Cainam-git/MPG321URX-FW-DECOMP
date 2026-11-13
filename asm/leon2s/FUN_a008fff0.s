# leon2s FUN_a008fff0 0xa008fff0-0xa0090010 (32 bytes)
a008fff0:  90 0a 20 ff  and  %o0, 0xff, %o0
a008fff4:  80 a2 20 01  cmp  %o0, 1
a008fff8:  12 80 00 04  bne  0xa0090008
a008fffc:  90 10 20 00  clr  %o0
a0090000:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a0090004:  d0 08 60 08  ldub  [ %g1 + 8 ], %o0	! 0xa8078c08
a0090008:  81 c3 e0 08  retl
a009000c:  01 00 00 00  nop
