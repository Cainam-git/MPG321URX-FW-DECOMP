# leon2m FUN_a00cf288 0xa00cf288-0xa00cf2d4 (76 bytes)
a00cf288:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cf28c:  80 a2 20 5f  cmp  %o0, 0x5f
a00cf290:  08 80 00 0e  bleu  0xa00cf2c8
a00cf294:  82 10 20 80  mov  0x80, %g1
a00cf298:  80 a2 20 60  cmp  %o0, 0x60
a00cf29c:  12 80 00 0c  bne  0xa00cf2cc
a00cf2a0:  92 0a 60 ff  and  %o1, 0xff, %o1
a00cf2a4:  80 a2 60 00  cmp  %o1, 0
a00cf2a8:  02 80 00 08  be  0xa00cf2c8
a00cf2ac:  80 a2 60 01  cmp  %o1, 1
a00cf2b0:  02 80 00 06  be  0xa00cf2c8
a00cf2b4:  82 10 21 00  mov  0x100, %g1
a00cf2b8:  80 a2 60 02  cmp  %o1, 2
a00cf2bc:  02 80 00 03  be  0xa00cf2c8
a00cf2c0:  82 10 21 80  mov  0x180, %g1
a00cf2c4:  82 10 22 00  mov  0x200, %g1
a00cf2c8:  c2 32 80 00  sth  %g1, [ %o2 ]
a00cf2cc:  81 c3 e0 08  retl
a00cf2d0:  01 00 00 00  nop
