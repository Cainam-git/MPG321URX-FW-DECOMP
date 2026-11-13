# leon2s FUN_a008d280 0xa008d280-0xa008d2e0 (96 bytes)
a008d280:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a008d284:  da 08 60 01  ldub  [ %g1 + 1 ], %o5	! 0xa8078c01
a008d288:  82 03 40 0d  add  %o5, %o5, %g1
a008d28c:  9a 00 40 0d  add  %g1, %o5, %o5
a008d290:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a008d294:  91 2a 20 10  sll  %o0, 0x10, %o0
a008d298:  96 10 62 40  or  %g1, 0x240, %o3
a008d29c:  94 10 62 44  or  %g1, 0x244, %o2
a008d2a0:  91 32 20 10  srl  %o0, 0x10, %o0
a008d2a4:  98 10 62 00  or  %g1, 0x200, %o4
a008d2a8:  80 a2 27 ff  cmp  %o0, 0x7ff
a008d2ac:  08 80 00 03  bleu  0xa008d2b8
a008d2b0:  82 10 20 00  clr  %g1
a008d2b4:  82 10 28 00  mov  0x800, %g1
a008d2b8:  82 03 40 01  add  %o5, %g1, %g1
a008d2bc:  82 00 60 04  add  %g1, 4, %g1
a008d2c0:  9b 28 60 10  sll  %g1, 0x10, %o5
a008d2c4:  82 08 60 ff  and  %g1, 0xff, %g1
a008d2c8:  c2 22 c0 00  st  %g1, [ %o3 ]
a008d2cc:  9b 33 60 18  srl  %o5, 0x18, %o5
a008d2d0:  da 22 80 00  st  %o5, [ %o2 ]
a008d2d4:  d0 03 00 00  ld  [ %o4 ], %o0
a008d2d8:  81 c3 e0 08  retl
a008d2dc:  90 0a 20 ff  and  %o0, 0xff, %o0
