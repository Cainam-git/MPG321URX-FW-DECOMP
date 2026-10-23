# leon2m FUN_a00fe7d8 0xa00fe7d8-0xa00fe820 (72 bytes)
a00fe7d8:  11 33 c0 b7  sethi  %hi(0xcf02dc00), %o0
a00fe7dc:  82 12 20 04  or  %o0, 4, %g1	! 0xcf02dc04
a00fe7e0:  da 00 40 00  ld  [ %g1 ], %o5
a00fe7e4:  80 8b 60 20  btst  0x20, %o5
a00fe7e8:  02 80 00 0c  be  0xa00fe818
a00fe7ec:  82 10 20 03  mov  3, %g1
a00fe7f0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fe7f4:  82 13 62 dc  or  %o5, 0x2dc, %g1	! 0xcf0116dc
a00fe7f8:  d0 00 40 00  ld  [ %g1 ], %o0
a00fe7fc:  9a 8a 20 c0  andcc  %o0, 0xc0, %o5
a00fe800:  9a 1b 60 80  xor  %o5, 0x80, %o5
a00fe804:  02 80 00 05  be  0xa00fe818
a00fe808:  82 10 20 00  clr  %g1
a00fe80c:  80 a0 00 0d  cmp  %g0, %o5
a00fe810:  90 40 20 00  addx  %g0, 0, %o0
a00fe814:  82 02 20 01  add  %o0, 1, %g1
a00fe818:  81 c3 e0 08  retl
a00fe81c:  90 08 60 03  and  %g1, 3, %o0
