# leon2s FUN_a00703d4 0xa00703d4-0xa0070404 (48 bytes)
a00703d4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00703d8:  d8 00 60 d8  ld  [ %g1 + 0xd8 ], %o4	! 0xa80788d8
a00703dc:  9a 10 20 01  mov  1, %o5
a00703e0:  9b 2b 40 08  sll  %o5, %o0, %o5
a00703e4:  83 33 20 08  srl  %o4, 8, %g1
a00703e8:  82 08 40 0d  and  %g1, %o5, %g1
a00703ec:  80 8b 00 0d  btst  %o4, %o5
a00703f0:  12 80 00 03  bne  0xa00703fc
a00703f4:  90 08 60 ff  and  %g1, 0xff, %o0
a00703f8:  90 10 20 00  clr  %o0
a00703fc:  81 c3 e0 08  retl
a0070400:  01 00 00 00  nop
