# leon2m FUN_a01250c4 0xa01250c4-0xa0125124 (96 bytes)
a01250c4:  03 00 06 90  sethi  %hi(0x1a4000), %g1
a01250c8:  96 10 62 a8  or  %g1, 0x2a8, %o3	! 0x1a42a8
a01250cc:  98 10 20 00  clr  %o4
a01250d0:  10 80 00 06  b  0xa01250e8
a01250d4:  90 10 20 00  clr  %o0
a01250d8:  90 0b 20 ff  and  %o4, 0xff, %o0
a01250dc:  80 a2 20 07  cmp  %o0, 7
a01250e0:  18 80 00 0d  bgu  0xa0125114
a01250e4:  80 a2 20 08  cmp  %o0, 8
a01250e8:  9a 5a 20 16  smul  %o0, 0x16, %o5
a01250ec:  9a 03 40 0b  add  %o5, %o3, %o5
a01250f0:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a01250f4:  80 a0 60 02  cmp  %g1, 2
a01250f8:  12 bf ff f8  bne  0xa01250d8
a01250fc:  98 03 20 01  inc  %o4
a0125100:  c2 13 60 14  lduh  [ %o5 + 0x14 ], %g1
a0125104:  80 88 64 00  btst  0x400, %g1
a0125108:  22 bf ff f5  be,a   0xa01250dc
a012510c:  90 0b 20 ff  and  %o4, 0xff, %o0
a0125110:  80 a2 20 08  cmp  %o0, 8
a0125114:  22 80 00 02  be,a   0xa012511c
a0125118:  90 10 20 ff  mov  0xff, %o0
a012511c:  81 c3 e0 08  retl
a0125120:  01 00 00 00  nop
