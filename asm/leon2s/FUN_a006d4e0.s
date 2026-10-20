# leon2s FUN_a006d4e0 0xa006d4e0-0xa006d53c (92 bytes)
a006d4e0:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a006d4e4:  92 10 60 24  or  %g1, 0x24, %o1	! 0xa807a824
a006d4e8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006d4ec:  d4 08 60 d3  ldub  [ %g1 + 0xd3 ], %o2	! 0xa80788d3
a006d4f0:  96 10 20 00  clr  %o3
a006d4f4:  82 0a e0 ff  and  %o3, 0xff, %g1
a006d4f8:  9b 28 60 02  sll  %g1, 2, %o5
a006d4fc:  9a 03 40 01  add  %o5, %g1, %o5
a006d500:  9b 2b 60 02  sll  %o5, 2, %o5
a006d504:  9a 03 40 09  add  %o5, %o1, %o5
a006d508:  83 3a 80 01  sra  %o2, %g1, %g1
a006d50c:  d8 13 60 12  lduh  [ %o5 + 0x12 ], %o4
a006d510:  82 08 60 01  and  %g1, 1, %g1
a006d514:  83 28 60 07  sll  %g1, 7, %g1
a006d518:  98 0b 3f 7f  and  %o4, -129, %o4
a006d51c:  98 13 00 01  or  %o4, %g1, %o4
a006d520:  96 02 e0 01  inc  %o3
a006d524:  82 0a e0 ff  and  %o3, 0xff, %g1
a006d528:  80 a0 60 08  cmp  %g1, 8
a006d52c:  08 bf ff f3  bleu  0xa006d4f8
a006d530:  d8 33 60 12  sth  %o4, [ %o5 + 0x12 ]
a006d534:  81 c3 e0 08  retl
a006d538:  01 00 00 00  nop
