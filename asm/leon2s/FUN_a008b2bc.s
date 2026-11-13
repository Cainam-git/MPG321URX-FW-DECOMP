# leon2s FUN_a008b2bc 0xa008b2bc-0xa008b308 (76 bytes)
a008b2bc:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008b2c0:  98 10 62 54  or  %g1, 0x254, %o4	! 0xcf011254
a008b2c4:  82 10 62 58  or  %g1, 0x258, %g1
a008b2c8:  c2 00 40 00  ld  [ %g1 ], %g1
a008b2cc:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b2d0:  90 0a 20 0f  and  %o0, 0xf, %o0
a008b2d4:  83 30 60 04  srl  %g1, 4, %g1
a008b2d8:  80 a0 40 08  cmp  %g1, %o0
a008b2dc:  02 80 00 08  be  0xa008b2fc
a008b2e0:  9a 10 20 00  clr  %o5
a008b2e4:  c2 03 00 00  ld  [ %o4 ], %g1
a008b2e8:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b2ec:  83 30 60 04  srl  %g1, 4, %g1
a008b2f0:  80 a0 40 08  cmp  %g1, %o0
a008b2f4:  12 80 00 03  bne  0xa008b300
a008b2f8:  01 00 00 00  nop
a008b2fc:  9a 10 20 01  mov  1, %o5	! 0x1
a008b300:  81 c3 e0 08  retl
a008b304:  90 10 00 0d  mov  %o5, %o0
