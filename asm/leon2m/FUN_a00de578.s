# leon2m FUN_a00de578 0xa00de578-0xa00de5c0 (72 bytes)
a00de578:  98 10 20 00  clr  %o4	! 0x0
a00de57c:  80 a3 00 08  cmp  %o4, %o0
a00de580:  1a 80 00 0e  bcc  0xa00de5b8
a00de584:  03 00 00 3e  sethi  %hi(0xf800), %g1
a00de588:  82 10 61 ff  or  %g1, 0x1ff, %g1	! 0xf9ff
a00de58c:  9a 10 20 00  clr  %o5
a00de590:  01 00 00 00  nop
a00de594:  01 00 00 00  nop
a00de598:  9a 03 60 01  inc  %o5
a00de59c:  80 a3 40 01  cmp  %o5, %g1
a00de5a0:  08 bf ff fc  bleu  0xa00de590
a00de5a4:  01 00 00 00  nop
a00de5a8:  98 03 20 01  inc  %o4
a00de5ac:  80 a3 00 08  cmp  %o4, %o0
a00de5b0:  0a bf ff f8  bcs  0xa00de590
a00de5b4:  9a 10 20 00  clr  %o5
a00de5b8:  81 c3 e0 08  retl
a00de5bc:  01 00 00 00  nop
