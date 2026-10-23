# leon2m FUN_a00de5c0 0xa00de5c0-0xa00de604 (68 bytes)
a00de5c0:  98 10 20 00  clr  %o4	! 0x0
a00de5c4:  80 a3 00 08  cmp  %o4, %o0
a00de5c8:  1a 80 00 0d  bcc  0xa00de5fc
a00de5cc:  03 00 00 27  sethi  %hi(0x9c00), %g1
a00de5d0:  82 10 60 3f  or  %g1, 0x3f, %g1	! 0x9c3f
a00de5d4:  9a 10 20 00  clr  %o5
a00de5d8:  01 00 00 00  nop
a00de5dc:  9a 03 60 01  inc  %o5
a00de5e0:  80 a3 40 01  cmp  %o5, %g1
a00de5e4:  08 bf ff fd  bleu  0xa00de5d8
a00de5e8:  01 00 00 00  nop
a00de5ec:  98 03 20 01  inc  %o4
a00de5f0:  80 a3 00 08  cmp  %o4, %o0
a00de5f4:  0a bf ff f9  bcs  0xa00de5d8
a00de5f8:  9a 10 20 00  clr  %o5
a00de5fc:  81 c3 e0 08  retl
a00de600:  01 00 00 00  nop
